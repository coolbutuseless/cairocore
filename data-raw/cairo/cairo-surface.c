{

}

/**
 * cairo_surface_get_type:
 * @surface: a #cairo_surface_t
 *
 * This function returns the type of the backend used to create
 * a surface. See #cairo_surface_type_t for available types.
 *
 * Return value: The type of @surface.
 *
 * Since: 1.2
 **/
cairo_surface_type_t
cairo_surface_get_type (cairo_surface_t *surface)
{
    /* We don't use surface->backend->type here so that some of the
     * special "wrapper" surfaces such as cairo_paginated_surface_t
     * can override surface->type with the type of the "child"
     * surface. */
    return surface->type;
}

/**
 * cairo_surface_get_content:
 * @surface: a #cairo_surface_t
 *
 * This function returns the content type of @surface which indicates
 * whether the surface contains color and/or alpha information. See
 * #cairo_content_t.
 *
 * Return value: The content type of @surface.
 *
 * Since: 1.2
 **/
cairo_content_t
cairo_surface_get_content (cairo_surface_t *surface)
{
    return surface->content;
}

/**
 * cairo_surface_status:
 * @surface: a #cairo_surface_t
 *
 * Checks whether an error has previously occurred for this
 * surface.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, %CAIRO_STATUS_NULL_POINTER,
 * %CAIRO_STATUS_NO_MEMORY, %CAIRO_STATUS_READ_ERROR,
 * %CAIRO_STATUS_INVALID_CONTENT, %CAIRO_STATUS_INVALID_FORMAT, or
 * %CAIRO_STATUS_INVALID_VISUAL.
 *
 * Since: 1.0
 **/
cairo_status_t
cairo_surface_status (cairo_surface_t *surface)
{
    return surface->status;
}
slim_hidden_def (cairo_surface_status);

static unsigned int
_cairo_surface_allocate_unique_id (void)
{
    static cairo_atomic_int_t unique_id;

#if CAIRO_NO_MUTEX
    if (++unique_id == 0)
	unique_id = 1;
    return unique_id;
#else
    cairo_atomic_int_t old, id;

    do {
	old = _cairo_atomic_uint_get (&unique_id);
	id = old + 1;
	if (id == 0)
	    id = 1;
    } while (! _cairo_atomic_uint_cmpxchg (&unique_id, old, id));

    return id;
#endif
}

/**
 * cairo_surface_get_device:
 * @surface: a #cairo_surface_t
 *
 * This function returns the device for a @surface.
 * See #cairo_device_t.
 *
 * Return value: The device for @surface or %NULL if the surface does
 *               not have an associated device.
 *
 * Since: 1.10
 **/
cairo_device_t *
cairo_surface_get_device (cairo_surface_t *surface)
{
    if (unlikely (surface->status))
	return _cairo_device_create_in_error (surface->status);

    return surface->device;
}


/**
 * cairo_surface_create_similar:
 * @other: an existing surface used to select the backend of the new surface
 * @content: the content for the new surface
 * @width: width of the new surface, (in device-space units)
 * @height: height of the new surface (in device-space units)
 *
 * Create a new surface that is as compatible as possible with an
 * existing surface. For example the new surface will have the same
 * device scale, fallback resolution and font options as
 * @other. Generally, the new surface will also use the same backend
 * as @other, unless that is not possible for some reason. The type of
 * the returned surface may be examined with
 * cairo_surface_get_type().
 *
 * Initially the surface contents are all 0 (transparent if contents
 * have transparency, black otherwise.)
 *
 * Use cairo_surface_create_similar_image() if you need an image surface
 * which can be painted quickly to the target surface.
 *
 * Return value: a pointer to the newly allocated surface. The caller
 * owns the surface and should call cairo_surface_destroy() when done
 * with it.
 *
 * This function always returns a valid pointer, but it will return a
 * pointer to a "nil" surface if @other is already in an error state
 * or any other error occurs.
 *
 * Since: 1.0
 **/
cairo_surface_t *
cairo_surface_create_similar (cairo_surface_t  *other,
			      cairo_content_t	content,
			      int		width,
			      int		height)
{
    cairo_surface_t *surface;
    cairo_status_t status;
    cairo_solid_pattern_t pattern;

    if (unlikely (other->status))
	return _cairo_surface_create_in_error (other->status);
    if (unlikely (other->finished))
	return _cairo_surface_create_in_error (CAIRO_STATUS_SURFACE_FINISHED);
    if (unlikely (width < 0 || height < 0))
	return _cairo_surface_create_in_error (CAIRO_STATUS_INVALID_SIZE);
    if (unlikely (! CAIRO_CONTENT_VALID (content)))
	return _cairo_surface_create_in_error (CAIRO_STATUS_INVALID_CONTENT);

    /* We inherit the device scale, so create a larger surface */
    width = width * other->device_transform.xx;
    height = height * other->device_transform.yy;

    surface = NULL;
    if (other->backend->create_similar)
	surface = other->backend->create_similar (other, content, width, height);
    if (surface == NULL)
	surface = cairo_surface_create_similar_image (other,
						      _cairo_format_from_content (content),
						      width, height);

    if (unlikely (surface->status))
	return surface;

    _cairo_surface_copy_similar_properties (surface, other);
    cairo_surface_set_device_scale (surface,
				    other->device_transform.xx,
				    other->device_transform.yy);

    if (unlikely (surface->status))
	return surface;

    _cairo_pattern_init_solid (&pattern, CAIRO_COLOR_TRANSPARENT);
    status = _cairo_surface_paint (surface,
				   CAIRO_OPERATOR_CLEAR,
				   &pattern.base, NULL);
    if (unlikely (status)) {
	cairo_surface_destroy (surface);
	surface = _cairo_surface_create_in_error (status);
    }

    assert (surface->is_clear);

    return surface;
}

/**
 * cairo_surface_create_similar_image:
 * @other: an existing surface used to select the preference of the new surface
 * @format: the format for the new surface
 * @width: width of the new surface, (in pixels)
 * @height: height of the new surface (in pixels)
 *
 * Create a new image surface that is as compatible as possible for uploading
 * to and the use in conjunction with an existing surface. However, this surface
 * can still be used like any normal image surface. Unlike
 * cairo_surface_create_similar() the new image surface won't inherit
 * the device scale from @other.
 *
 * Initially the surface contents are all 0 (transparent if contents
 * have transparency, black otherwise.)
 *
 * Use cairo_surface_create_similar() if you don't need an image surface.
 *
 * Return value: a pointer to the newly allocated image surface. The caller
 * owns the surface and should call cairo_surface_destroy() when done
 * with it.
 *
 * This function always returns a valid pointer, but it will return a
 * pointer to a "nil" surface if @other is already in an error state
 * or any other error occurs.
 *
 * Since: 1.12
 **/
cairo_surface_t *
cairo_surface_create_similar_image (cairo_surface_t  *other,
				    cairo_format_t    format,
				    int		width,
				    int		height)
{
    cairo_surface_t *image;

    if (unlikely (other->status))
	return _cairo_surface_create_in_error (other->status);
    if (unlikely (other->finished))
	return _cairo_surface_create_in_error (CAIRO_STATUS_SURFACE_FINISHED);

    if (unlikely (width < 0 || height < 0))
	return _cairo_surface_create_in_error (CAIRO_STATUS_INVALID_SIZE);
    if (unlikely (! CAIRO_FORMAT_VALID (format)))
	return _cairo_surface_create_in_error (CAIRO_STATUS_INVALID_FORMAT);

    image = NULL;
    if (other->backend->create_similar_image)
	image = other->backend->create_similar_image (other,
						      format, width, height);
    if (image == NULL)
	image = cairo_image_surface_create (format, width, height);

    assert (image->is_clear);

    return image;
}
slim_hidden_def (cairo_surface_create_similar_image);


/**
 * cairo_surface_reference:
 * @surface: a #cairo_surface_t
 *
 * Increases the reference count on @surface by one. This prevents
 * @surface from being destroyed until a matching call to
 * cairo_surface_destroy() is made.
 *
 * Use cairo_surface_get_reference_count() to get the number of
 * references to a #cairo_surface_t.
 *
 * Return value: the referenced #cairo_surface_t.
 *
 * Since: 1.0
 **/
cairo_surface_t *
cairo_surface_reference (cairo_surface_t *surface)
{
    if (surface == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&surface->ref_count))
	return surface;

    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count));

    _cairo_reference_count_inc (&surface->ref_count);

    return surface;
}
slim_hidden_def (cairo_surface_reference);

/**
 * cairo_surface_destroy:
 * @surface: a #cairo_surface_t
 *
 * Decreases the reference count on @surface by one. If the result is
 * zero, then @surface and all associated resources are freed.  See
 * cairo_surface_reference().
 *
 * Since: 1.0
 **/
void
cairo_surface_destroy (cairo_surface_t *surface)
{
    if (surface == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&surface->ref_count))
	return;

    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count));

    if (! _cairo_reference_count_dec_and_test (&surface->ref_count))
	return;

    assert (surface->snapshot_of == NULL);

    if (! surface->finished) {
	_cairo_surface_finish_snapshots (surface);
	/* We may have been referenced by a snapshot prior to have
	 * detaching it with the copy-on-write.
	 */
	if (CAIRO_REFERENCE_COUNT_GET_VALUE (&surface->ref_count))
	    return;

	_cairo_surface_finish (surface);
    }

    if (surface->damage)
	_cairo_damage_destroy (surface->damage);

    _cairo_user_data_array_fini (&surface->user_data);
    _cairo_user_data_array_fini (&surface->mime_data);

    if (surface->owns_device)
        cairo_device_destroy (surface->device);

    assert (surface->snapshot_of == NULL);
    assert (! _cairo_surface_has_snapshots (surface));
    /* paranoid check that nobody took a reference whilst finishing */
    assert (! CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count));

    free (surface);
}
slim_hidden_def(cairo_surface_destroy);

/**
 * cairo_surface_get_reference_count:
 * @surface: a #cairo_surface_t
 *
 * Returns the current reference count of @surface.
 *
 * Return value: the current reference count of @surface.  If the
 * object is a nil object, 0 will be returned.
 *
 * Since: 1.4
 **/
unsigned int
cairo_surface_get_reference_count (cairo_surface_t *surface)
{
    if (surface == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&surface->ref_count))
	return 0;

    return CAIRO_REFERENCE_COUNT_GET_VALUE (&surface->ref_count);
}


/**
 * cairo_surface_finish:
 * @surface: the #cairo_surface_t to finish
 *
 * This function finishes the surface and drops all references to
 * external resources.  For example, for the Xlib backend it means
 * that cairo will no longer access the drawable, which can be freed.
 * After calling cairo_surface_finish() the only valid operations on a
 * surface are checking status, getting and setting user, referencing
 * and destroying, and flushing and finishing it.
 * Further drawing to the surface will not affect the
 * surface but will instead trigger a %CAIRO_STATUS_SURFACE_FINISHED
 * error.
 *
 * When the last call to cairo_surface_destroy() decreases the
 * reference count to zero, cairo will call cairo_surface_finish() if
 * it hasn't been called already, before freeing the resources
 * associated with the surface.
 *
 * Since: 1.0
 **/
void
cairo_surface_finish (cairo_surface_t *surface)
{
    if (surface == NULL)
	return;

    if (CAIRO_REFERENCE_COUNT_IS_INVALID (&surface->ref_count))
	return;

    if (surface->finished)
	return;

    /* We have to be careful when decoupling potential reference cycles */
    cairo_surface_reference (surface);

    _cairo_surface_finish_snapshots (surface);
    /* XXX need to block and wait for snapshot references */
    _cairo_surface_finish (surface);

    cairo_surface_destroy (surface);
}
slim_hidden_def (cairo_surface_finish);


/**
 * cairo_surface_get_user_data:
 * @surface: a #cairo_surface_t
 * @key: the address of the #cairo_user_data_key_t the user data was
 * attached to
 *
 * Return user data previously attached to @surface using the specified
 * key.  If no user data has been attached with the given key this
 * function returns %NULL.
 *
 * Return value: the user data previously attached or %NULL.
 *
 * Since: 1.0
 **/
void *
cairo_surface_get_user_data (cairo_surface_t		 *surface,
			     const cairo_user_data_key_t *key)
{
    /* Prevent reads of the array during teardown */
    if (! CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count))
	return NULL;

    return _cairo_user_data_array_get_data (&surface->user_data, key);
}

/**
 * cairo_surface_set_user_data:
 * @surface: a #cairo_surface_t
 * @key: the address of a #cairo_user_data_key_t to attach the user data to
 * @user_data: the user data to attach to the surface
 * @destroy: a #cairo_destroy_func_t which will be called when the
 * surface is destroyed or when new user data is attached using the
 * same key.
 *
 * Attach user data to @surface.  To remove user data from a surface,
 * call this function with the key that was used to set it and %NULL
 * for @data.
 *
 * Return value: %CAIRO_STATUS_SUCCESS or %CAIRO_STATUS_NO_MEMORY if a
 * slot could not be allocated for the user data.
 *
 * Since: 1.0
 **/
cairo_status_t
cairo_surface_set_user_data (cairo_surface_t		 *surface,
			     const cairo_user_data_key_t *key,
			     void			 *user_data,
			     cairo_destroy_func_t	 destroy)
{
    if (CAIRO_REFERENCE_COUNT_IS_INVALID (&surface->ref_count))
	return surface->status;

    if (! CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count))
	return _cairo_error (CAIRO_STATUS_SURFACE_FINISHED);

    return _cairo_user_data_array_set_data (&surface->user_data,
					    key, user_data, destroy);
}



cairo_bool_t
_cairo_surface_has_mime_image (cairo_surface_t *surface)
{
    cairo_user_data_slot_t *slots;
    int i, j, num_slots;

    /* Prevent reads of the array during teardown */
    if (! CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&surface->ref_count))
	return FALSE;

    /* The number of mime-types attached to a surface is usually small,
     * typically zero. Therefore it is quicker to do a strcmp() against
     * each key than it is to intern the string (i.e. compute a hash,
     * search the hash table, and do a final strcmp).
     */
    num_slots = surface->mime_data.num_elements;
    slots = _cairo_array_index (&surface->mime_data, 0);
    for (i = 0; i < num_slots; i++) {
	if (slots[i].key != NULL) {
	    for (j = 0; j < ARRAY_LENGTH (_cairo_surface_image_mime_types); j++) {
		if (strcmp ((char *) slots[i].key, _cairo_surface_image_mime_types[j]) == 0)
		    return TRUE;
	    }
	}
    }

    return FALSE;
}


/**
 * cairo_surface_get_font_options:
 * @surface: a #cairo_surface_t
 * @options: a #cairo_font_options_t object into which to store
 *   the retrieved options. All existing values are overwritten
 *
 * Retrieves the default font rendering options for the surface.
 * This allows display surfaces to report the correct subpixel order
 * for rendering on them, print surfaces to disable hinting of
 * metrics and so forth. The result can then be used with
 * cairo_scaled_font_create().
 *
 * Since: 1.0
 **/
void
cairo_surface_get_font_options (cairo_surface_t       *surface,
				cairo_font_options_t  *options)
{
    if (cairo_font_options_status (options))
	return;

    if (surface->status) {
	_cairo_font_options_init_default (options);
	return;
    }

    if (! surface->has_font_options) {
	surface->has_font_options = TRUE;

	_cairo_font_options_init_default (&surface->font_options);

	if (!surface->finished && surface->backend->get_font_options) {
	    surface->backend->get_font_options (surface, &surface->font_options);
	}
    }

    _cairo_font_options_init_copy (options, &surface->font_options);
}
slim_hidden_def (cairo_surface_get_font_options);


/**
 * cairo_surface_flush:
 * @surface: a #cairo_surface_t
 *
 * Do any pending drawing for the surface and also restore any temporary
 * modifications cairo has made to the surface's state. This function
 * must be called before switching from drawing on the surface with
 * cairo to drawing on it directly with native APIs, or accessing its
 * memory outside of Cairo. If the surface doesn't support direct
 * access, then this function does nothing.
 *
 * Since: 1.0
 **/
void
cairo_surface_flush (cairo_surface_t *surface)
{
    cairo_status_t status;

    if (surface->status)
	return;

    if (surface->finished)
	return;

    status = _cairo_surface_flush (surface, 0);
    if (unlikely (status))
	_cairo_surface_set_error (surface, status);
}
slim_hidden_def (cairo_surface_flush);

/**
 * cairo_surface_mark_dirty:
 * @surface: a #cairo_surface_t
 *
 * Tells cairo that drawing has been done to surface using means other
 * than cairo, and that cairo should reread any cached areas. Note
 * that you must call cairo_surface_flush() before doing such drawing.
 *
 * Since: 1.0
 **/
void
cairo_surface_mark_dirty (cairo_surface_t *surface)
{
    cairo_rectangle_int_t extents;

    if (unlikely (surface->status))
	return;
    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, _cairo_error (CAIRO_STATUS_SURFACE_FINISHED));
	return;
    }

    _cairo_surface_get_extents (surface, &extents);
    cairo_surface_mark_dirty_rectangle (surface,
					extents.x, extents.y,
					extents.width, extents.height);
}
slim_hidden_def (cairo_surface_mark_dirty);

/**
 * cairo_surface_mark_dirty_rectangle:
 * @surface: a #cairo_surface_t
 * @x: X coordinate of dirty rectangle
 * @y: Y coordinate of dirty rectangle
 * @width: width of dirty rectangle
 * @height: height of dirty rectangle
 *
 * Like cairo_surface_mark_dirty(), but drawing has been done only to
 * the specified rectangle, so that cairo can retain cached contents
 * for other parts of the surface.
 *
 * Any cached clip set on the surface will be reset by this function,
 * to make sure that future cairo calls have the clip set that they
 * expect.
 *
 * Since: 1.0
 **/
void
cairo_surface_mark_dirty_rectangle (cairo_surface_t *surface,
				    int              x,
				    int              y,
				    int              width,
				    int              height)
{
    cairo_status_t status;

    if (unlikely (surface->status))
	return;

    assert (surface->snapshot_of == NULL);

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, _cairo_error (CAIRO_STATUS_SURFACE_FINISHED));
	return;
    }

    /* The application *should* have called cairo_surface_flush() before
     * modifying the surface independently of cairo (and thus having to
     * call mark_dirty()). */
    assert (! _cairo_surface_has_snapshots (surface));
    assert (! _cairo_surface_has_mime_data (surface));

    surface->is_clear = FALSE;
    surface->serial++;

    if (surface->damage) {
	cairo_box_t box;

	box.p1.x = x;
	box.p1.y = y;
	box.p2.x = x + width;
	box.p2.y = y + height;

	surface->damage = _cairo_damage_add_box (surface->damage, &box);
    }

    if (surface->backend->mark_dirty_rectangle != NULL) {
	/* XXX: FRAGILE: We're ignoring the scaling component of
	 * device_transform here. I don't know what the right thing to
	 * do would actually be if there were some scaling here, but
	 * we avoid this since device_transfom scaling is not exported
	 * publicly and mark_dirty is not used internally. */
	status = surface->backend->mark_dirty_rectangle (surface,
                                                         x + surface->device_transform.x0,
                                                         y + surface->device_transform.y0,
							 width, height);

	if (unlikely (status))
	    _cairo_surface_set_error (surface, status);
    }
}
slim_hidden_def (cairo_surface_mark_dirty_rectangle);

/**
 * cairo_surface_set_device_scale:
 * @surface: a #cairo_surface_t
 * @x_scale: a scale factor in the X direction
 * @y_scale: a scale factor in the Y direction
 *
 * Sets a scale that is multiplied to the device coordinates determined
 * by the CTM when drawing to @surface. One common use for this is to
 * render to very high resolution display devices at a scale factor, so
 * that code that assumes 1 pixel will be a certain size will still work.
 * Setting a transformation via cairo_translate() isn't
 * sufficient to do this, since functions like
 * cairo_device_to_user() will expose the hidden scale.
 *
 * Note that the scale affects drawing to the surface as well as
 * using the surface in a source pattern.
 *
 * Since: 1.14
 **/
void
cairo_surface_set_device_scale (cairo_surface_t *surface,
				double		 x_scale,
				double		 y_scale)
{
    cairo_status_t status;

    if (unlikely (surface->status))
	return;

    assert (surface->snapshot_of == NULL);

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, _cairo_error (CAIRO_STATUS_SURFACE_FINISHED));
	return;
    }

    status = _cairo_surface_begin_modification (surface);
    if (unlikely (status)) {
	_cairo_surface_set_error (surface, status);
	return;
    }

    surface->device_transform.xx = x_scale;
    surface->device_transform.yy = y_scale;
    surface->device_transform.xy = 0.0;
    surface->device_transform.yx = 0.0;

    surface->device_transform_inverse = surface->device_transform;
    status = cairo_matrix_invert (&surface->device_transform_inverse);
    /* should always be invertible unless given pathological input */
    assert (status == CAIRO_STATUS_SUCCESS);

    _cairo_observers_notify (&surface->device_transform_observers, surface);
}
slim_hidden_def (cairo_surface_set_device_scale);

/**
 * cairo_surface_get_device_scale:
 * @surface: a #cairo_surface_t
 * @x_scale: the scale in the X direction, in device units
 * @y_scale: the scale in the Y direction, in device units
 *
 * This function returns the previous device offset set by
 * cairo_surface_set_device_scale().
 *
 * Since: 1.14
 **/
void
cairo_surface_get_device_scale (cairo_surface_t *surface,
				double          *x_scale,
				double          *y_scale)
{
    if (x_scale)
	*x_scale = surface->device_transform.xx;
    if (y_scale)
	*y_scale = surface->device_transform.yy;
}
slim_hidden_def (cairo_surface_get_device_scale);

/**
 * cairo_surface_set_device_offset:
 * @surface: a #cairo_surface_t
 * @x_offset: the offset in the X direction, in device units
 * @y_offset: the offset in the Y direction, in device units
 *
 * Sets an offset that is added to the device coordinates determined
 * by the CTM when drawing to @surface. One use case for this function
 * is when we want to create a #cairo_surface_t that redirects drawing
 * for a portion of an onscreen surface to an offscreen surface in a
 * way that is completely invisible to the user of the cairo
 * API. Setting a transformation via cairo_translate() isn't
 * sufficient to do this, since functions like
 * cairo_device_to_user() will expose the hidden offset.
 *
 * Note that the offset affects drawing to the surface as well as
 * using the surface in a source pattern.
 *
 * Since: 1.0
 **/
void
cairo_surface_set_device_offset (cairo_surface_t *surface,
				 double           x_offset,
				 double           y_offset)
{
    cairo_status_t status;

    if (unlikely (surface->status))
	return;

    assert (surface->snapshot_of == NULL);

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, _cairo_error (CAIRO_STATUS_SURFACE_FINISHED));
	return;
    }

    status = _cairo_surface_begin_modification (surface);
    if (unlikely (status)) {
	_cairo_surface_set_error (surface, status);
	return;
    }

    surface->device_transform.x0 = x_offset;
    surface->device_transform.y0 = y_offset;

    surface->device_transform_inverse = surface->device_transform;
    status = cairo_matrix_invert (&surface->device_transform_inverse);
    /* should always be invertible unless given pathological input */
    assert (status == CAIRO_STATUS_SUCCESS);

    _cairo_observers_notify (&surface->device_transform_observers, surface);
}

/**
 * cairo_surface_get_device_offset:
 * @surface: a #cairo_surface_t
 * @x_offset: the offset in the X direction, in device units
 * @y_offset: the offset in the Y direction, in device units
 *
 * This function returns the previous device offset set by
 * cairo_surface_set_device_offset().
 *
 * Since: 1.2
 **/
void
cairo_surface_get_device_offset (cairo_surface_t *surface,
				 double          *x_offset,
				 double          *y_offset)
{
    if (x_offset)
	*x_offset = surface->device_transform.x0;
    if (y_offset)
	*y_offset = surface->device_transform.y0;
}

/**
 * cairo_surface_set_fallback_resolution:
 * @surface: a #cairo_surface_t
 * @x_pixels_per_inch: horizontal setting for pixels per inch
 * @y_pixels_per_inch: vertical setting for pixels per inch
 *
 * Set the horizontal and vertical resolution for image fallbacks.
 *
 * When certain operations aren't supported natively by a backend,
 * cairo will fallback by rendering operations to an image and then
 * overlaying that image onto the output. For backends that are
 * natively vector-oriented, this function can be used to set the
 * resolution used for these image fallbacks, (larger values will
 * result in more detailed images, but also larger file sizes).
 *
 * Some examples of natively vector-oriented backends are the ps, pdf,
 * and svg backends.
 *
 * For backends that are natively raster-oriented, image fallbacks are
 * still possible, but they are always performed at the native
 * device resolution. So this function has no effect on those
 * backends.
 *
 * Note: The fallback resolution only takes effect at the time of
 * completing a page (with cairo_show_page() or cairo_copy_page()) so
 * there is currently no way to have more than one fallback resolution
 * in effect on a single page.
 *
 * The default fallback resolution is 300 pixels per inch in both
 * dimensions.
 *
 * Since: 1.2
 **/
void
cairo_surface_set_fallback_resolution (cairo_surface_t	*surface,
				       double		 x_pixels_per_inch,
				       double		 y_pixels_per_inch)
{
    cairo_status_t status;

    if (unlikely (surface->status))
	return;

    assert (surface->snapshot_of == NULL);

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, _cairo_error (CAIRO_STATUS_SURFACE_FINISHED));
	return;
    }

    if (x_pixels_per_inch <= 0 || y_pixels_per_inch <= 0) {
	/* XXX Could delay raising the error until we fallback, but throwing
	 * the error here means that we can catch the real culprit.
	 */
	_cairo_surface_set_error (surface, CAIRO_STATUS_INVALID_MATRIX);
	return;
    }

    status = _cairo_surface_begin_modification (surface);
    if (unlikely (status)) {
	_cairo_surface_set_error (surface, status);
	return;
    }

    surface->x_fallback_resolution = x_pixels_per_inch;
    surface->y_fallback_resolution = y_pixels_per_inch;
}


/**
 * cairo_surface_get_fallback_resolution:
 * @surface: a #cairo_surface_t
 * @x_pixels_per_inch: horizontal pixels per inch
 * @y_pixels_per_inch: vertical pixels per inch
 *
 * This function returns the previous fallback resolution set by
 * cairo_surface_set_fallback_resolution(), or default fallback
 * resolution if never set.
 *
 * Since: 1.8
 **/
void
cairo_surface_get_fallback_resolution (cairo_surface_t	*surface,
				       double		*x_pixels_per_inch,
				       double		*y_pixels_per_inch)
{
    if (x_pixels_per_inch)
	*x_pixels_per_inch = surface->x_fallback_resolution;
    if (y_pixels_per_inch)
	*y_pixels_per_inch = surface->y_fallback_resolution;
}



/**
 * cairo_surface_copy_page:
 * @surface: a #cairo_surface_t
 *
 * Emits the current page for backends that support multiple pages,
 * but doesn't clear it, so that the contents of the current page will
 * be retained for the next page.  Use cairo_surface_show_page() if you
 * want to get an empty page after the emission.
 *
 * There is a convenience function for this that takes a #cairo_t,
 * namely cairo_copy_page().
 *
 * Since: 1.6
 **/
void
cairo_surface_copy_page (cairo_surface_t *surface)
{
    if (unlikely (surface->status))
	return;

    assert (surface->snapshot_of == NULL);

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, CAIRO_STATUS_SURFACE_FINISHED);
	return;
    }

    /* It's fine if some backends don't implement copy_page */
    if (surface->backend->copy_page == NULL)
	return;

    _cairo_surface_set_error (surface, surface->backend->copy_page (surface));
}
slim_hidden_def (cairo_surface_copy_page);

/**
 * cairo_surface_show_page:
 * @surface: a #cairo_Surface_t
 *
 * Emits and clears the current page for backends that support multiple
 * pages.  Use cairo_surface_copy_page() if you don't want to clear the page.
 *
 * There is a convenience function for this that takes a #cairo_t,
 * namely cairo_show_page().
 *
 * Since: 1.6
 **/
void
cairo_surface_show_page (cairo_surface_t *surface)
{
    cairo_status_t status;

    if (unlikely (surface->status))
	return;

    if (unlikely (surface->finished)) {
	_cairo_surface_set_error (surface, CAIRO_STATUS_SURFACE_FINISHED);
	return;
    }

    status = _cairo_surface_begin_modification (surface);
    if (unlikely (status)) {
	_cairo_surface_set_error (surface, status);
	return;
    }

    /* It's fine if some backends don't implement show_page */
    if (surface->backend->show_page == NULL)
	return;

    _cairo_surface_set_error (surface, surface->backend->show_page (surface));
}
