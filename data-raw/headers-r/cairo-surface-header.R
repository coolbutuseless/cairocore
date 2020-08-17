
cairo_surface_header <- list(

  cairo_surface_get_type = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_get_type:
    * @surface: a #cairo_surface_t
    *
    * This function returns the type of the backend used to create
    * a surface. See #cairo_surface_type_t for available types.
    *
    * Return value: The type of @surface.
    *
    * Since: 1.2
    **/}",
    proto_text = "cairo_surface_type_t cairo_surface_get_type (cairo_surface_t *surface)"
  ),

  cairo_surface_get_content = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_content_t cairo_surface_get_content (cairo_surface_t *surface)"
  ),

  cairo_surface_status = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_status_t cairo_surface_status (cairo_surface_t *surface)"
  ),

  cairo_surface_get_device = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_device_t * cairo_surface_get_device (cairo_surface_t *surface)"
  ),

  cairo_surface_create_similar = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_surface_t * cairo_surface_create_similar (cairo_surface_t  *other,
			      cairo_content_t	content,
			      int		width,
			      int		height)"
  ),

  cairo_surface_create_similar_image = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_surface_t * cairo_surface_create_similar_image (cairo_surface_t  *other,
				    cairo_format_t    format,
				    int		width,
				    int		height)"
  ),

  cairo_surface_reference = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_surface_t * cairo_surface_reference (cairo_surface_t *surface)"
  ),

  cairo_surface_destroy = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_destroy:
    * @surface: a #cairo_surface_t
    *
    * Decreases the reference count on @surface by one. If the result is
    * zero, then @surface and all associated resources are freed.  See
    * cairo_surface_reference().
    *
    * Since: 1.0
    **/}",
    proto_text = "void cairo_surface_destroy (cairo_surface_t *surface)"
  ),

  cairo_surface_get_reference_count = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_get_reference_count:
    * @surface: a #cairo_surface_t
    *
    * Returns the current reference count of @surface.
    *
    * Return value: the current reference count of @surface.  If the
    * object is a nil object, 0 will be returned.
    *
    * Since: 1.4
    **/}",
    proto_text = "unsigned int cairo_surface_get_reference_count (cairo_surface_t *surface)"
  ),

  cairo_surface_finish = list(
    include = TRUE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_finish (cairo_surface_t *surface)"
  ),

  cairo_surface_get_user_data = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void * cairo_surface_get_user_data (cairo_surface_t		 *surface,
			     const cairo_user_data_key_t *key)"
  ),

  cairo_surface_set_user_data = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "cairo_status_t cairo_surface_set_user_data (cairo_surface_t		 *surface,
			     const cairo_user_data_key_t *key,
			     void			 *user_data,
			     cairo_destroy_func_t	 destroy)"
  ),

  cairo_surface_get_font_options = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_get_font_options (cairo_surface_t       *surface,
				cairo_font_options_t  *options)"
  ),

  cairo_surface_flush = list(
    include = TRUE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_flush (cairo_surface_t *surface)"
  ),

  cairo_surface_mark_dirty = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_mark_dirty:
    * @surface: a #cairo_surface_t
    *
    * Tells cairo that drawing has been done to surface using means other
    * than cairo, and that cairo should reread any cached areas. Note
    * that you must call cairo_surface_flush() before doing such drawing.
    *
    * Since: 1.0
    **/}",
    proto_text = "void cairo_surface_mark_dirty (cairo_surface_t *surface)"
  ),

  cairo_surface_mark_dirty_rectangle = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_mark_dirty_rectangle (cairo_surface_t *surface,
				    int              x,
				    int              y,
				    int              width,
				    int              height)"
  ),

  cairo_surface_set_device_scale = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_set_device_scale (cairo_surface_t *surface,
				double		 x_scale,
				double		 y_scale)"
  ),

  cairo_surface_get_device_scale = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_get_device_scale:
    * @surface: a #cairo_surface_t
    * @x_scale: the scale in the X direction, in device units
    * @y_scale: the scale in the Y direction, in device units
    *
    * This function returns the previous device offset set by
    * cairo_surface_set_device_scale().
    *
    * Since: 1.14
    **/}",
    proto_text = "void cairo_surface_get_device_scale (cairo_surface_t *surface,
				double          *x_scale,
				double          *y_scale)"
  ),

  cairo_surface_set_device_offset = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_set_device_offset (cairo_surface_t *surface,
				 double           x_offset,
				 double           y_offset)"
  ),

  cairo_surface_get_device_offset = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_surface_get_device_offset:
    * @surface: a #cairo_surface_t
    * @x_offset: the offset in the X direction, in device units
    * @y_offset: the offset in the Y direction, in device units
    *
    * This function returns the previous device offset set by
    * cairo_surface_set_device_offset().
    *
    * Since: 1.2
    **/}",
    proto_text = "void cairo_surface_get_device_offset (cairo_surface_t *surface,
				 double          *x_offset,
				 double          *y_offset)"
  ),

  cairo_surface_set_fallback_resolution = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_set_fallback_resolution (cairo_surface_t	*surface,
				       double		 x_pixels_per_inch,
				       double		 y_pixels_per_inch)"
  ),

  cairo_surface_get_fallback_resolution = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_get_fallback_resolution (cairo_surface_t	*surface,
				       double		*x_pixels_per_inch,
				       double		*y_pixels_per_inch)"
  ),

  cairo_surface_copy_page = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_copy_page (cairo_surface_t *surface)"
  ),

  cairo_surface_show_page = list(
    include = FALSE,
    gtkdoc = r"{/**
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
    **/}",
    proto_text = "void cairo_surface_show_page (cairo_surface_t *surface)"
  )
)
