
/**
 * cairo_pattern_create_rgb:
 * @red: red component of the color
 * @green: green component of the color
 * @blue: blue component of the color
 *
 * Creates a new #cairo_pattern_t corresponding to an opaque color.  The
 * color components are floating point numbers in the range 0 to 1.
 * If the values passed in are outside that range, they will be
 * clamped.
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory.  The caller owns the
 * returned object and should call cairo_pattern_destroy() when
 * finished with it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error.  To inspect
 * the status of a pattern use cairo_pattern_status().
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_create_rgb (double red, double green, double blue)
{
    return cairo_pattern_create_rgba (red, green, blue, 1.0);
}
slim_hidden_def (cairo_pattern_create_rgb);

/**
 * cairo_pattern_create_rgba:
 * @red: red component of the color
 * @green: green component of the color
 * @blue: blue component of the color
 * @alpha: alpha component of the color
 *
 * Creates a new #cairo_pattern_t corresponding to a translucent color.
 * The color components are floating point numbers in the range 0 to
 * 1.  If the values passed in are outside that range, they will be
 * clamped.
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory.  The caller owns the
 * returned object and should call cairo_pattern_destroy() when
 * finished with it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error.  To inspect
 * the status of a pattern use cairo_pattern_status().
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_create_rgba (double red, double green, double blue,
			   double alpha)
{
    cairo_color_t color;

    red   = _cairo_restrict_value (red,   0.0, 1.0);
    green = _cairo_restrict_value (green, 0.0, 1.0);
    blue  = _cairo_restrict_value (blue,  0.0, 1.0);
    alpha = _cairo_restrict_value (alpha, 0.0, 1.0);

    _cairo_color_init_rgba (&color, red, green, blue, alpha);

    CAIRO_MUTEX_INITIALIZE ();

    return _cairo_pattern_create_solid (&color);
}
slim_hidden_def (cairo_pattern_create_rgba);

/**
 * cairo_pattern_create_for_surface:
 * @surface: the surface
 *
 * Create a new #cairo_pattern_t for the given surface.
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory.  The caller owns the
 * returned object and should call cairo_pattern_destroy() when
 * finished with it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error.  To inspect
 * the status of a pattern use cairo_pattern_status().
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_create_for_surface (cairo_surface_t *surface)
{
    cairo_surface_pattern_t *pattern;

    if (surface == NULL) {
	_cairo_error_throw (CAIRO_STATUS_NULL_POINTER);
	return (cairo_pattern_t*) &_cairo_pattern_nil_null_pointer;
    }

    if (surface->status)
	return _cairo_pattern_create_in_error (surface->status);

    pattern =
	_freed_pool_get (&freed_pattern_pool[CAIRO_PATTERN_TYPE_SURFACE]);
    if (unlikely (pattern == NULL)) {
	pattern = _cairo_malloc (sizeof (cairo_surface_pattern_t));
	if (unlikely (pattern == NULL)) {
	    _cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	    return (cairo_pattern_t *)&_cairo_pattern_nil.base;
	}
    }

    CAIRO_MUTEX_INITIALIZE ();

    _cairo_pattern_init_for_surface (pattern, surface);
    CAIRO_REFERENCE_COUNT_INIT (&pattern->base.ref_count, 1);

    return &pattern->base;
}
slim_hidden_def (cairo_pattern_create_for_surface);

/**
 * cairo_pattern_create_linear:
 * @x0: x coordinate of the start point
 * @y0: y coordinate of the start point
 * @x1: x coordinate of the end point
 * @y1: y coordinate of the end point
 *
 * Create a new linear gradient #cairo_pattern_t along the line defined
 * by (x0, y0) and (x1, y1).  Before using the gradient pattern, a
 * number of color stops should be defined using
 * cairo_pattern_add_color_stop_rgb() or
 * cairo_pattern_add_color_stop_rgba().
 *
 * Note: The coordinates here are in pattern space. For a new pattern,
 * pattern space is identical to user space, but the relationship
 * between the spaces can be changed with cairo_pattern_set_matrix().
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory.  The caller owns the
 * returned object and should call cairo_pattern_destroy() when
 * finished with it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error.  To inspect
 * the status of a pattern use cairo_pattern_status().
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_create_linear (double x0, double y0, double x1, double y1)
{
    cairo_linear_pattern_t *pattern;

    pattern =
	_freed_pool_get (&freed_pattern_pool[CAIRO_PATTERN_TYPE_LINEAR]);
    if (unlikely (pattern == NULL)) {
	pattern = _cairo_malloc (sizeof (cairo_linear_pattern_t));
	if (unlikely (pattern == NULL)) {
	    _cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	    return (cairo_pattern_t *) &_cairo_pattern_nil.base;
	}
    }

    CAIRO_MUTEX_INITIALIZE ();

    _cairo_pattern_init_linear (pattern, x0, y0, x1, y1);
    CAIRO_REFERENCE_COUNT_INIT (&pattern->base.base.ref_count, 1);

    return &pattern->base.base;
}

/**
 * cairo_pattern_create_radial:
 * @cx0: x coordinate for the center of the start circle
 * @cy0: y coordinate for the center of the start circle
 * @radius0: radius of the start circle
 * @cx1: x coordinate for the center of the end circle
 * @cy1: y coordinate for the center of the end circle
 * @radius1: radius of the end circle
 *
 * Creates a new radial gradient #cairo_pattern_t between the two
 * circles defined by (cx0, cy0, radius0) and (cx1, cy1, radius1).  Before using the
 * gradient pattern, a number of color stops should be defined using
 * cairo_pattern_add_color_stop_rgb() or
 * cairo_pattern_add_color_stop_rgba().
 *
 * Note: The coordinates here are in pattern space. For a new pattern,
 * pattern space is identical to user space, but the relationship
 * between the spaces can be changed with cairo_pattern_set_matrix().
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory.  The caller owns the
 * returned object and should call cairo_pattern_destroy() when
 * finished with it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error.  To inspect
 * the status of a pattern use cairo_pattern_status().
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_create_radial (double cx0, double cy0, double radius0,
			     double cx1, double cy1, double radius1)
{
    cairo_radial_pattern_t *pattern;

    pattern =
	_freed_pool_get (&freed_pattern_pool[CAIRO_PATTERN_TYPE_RADIAL]);
    if (unlikely (pattern == NULL)) {
	pattern = _cairo_malloc (sizeof (cairo_radial_pattern_t));
	if (unlikely (pattern == NULL)) {
	    _cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	    return (cairo_pattern_t *) &_cairo_pattern_nil.base;
	}
    }

    CAIRO_MUTEX_INITIALIZE ();

    _cairo_pattern_init_radial (pattern, cx0, cy0, radius0, cx1, cy1, radius1);
    CAIRO_REFERENCE_COUNT_INIT (&pattern->base.base.ref_count, 1);

    return &pattern->base.base;
}

/**
 * cairo_pattern_create_mesh:
 *
 * Create a new mesh pattern.
 *
 * Mesh patterns are tensor-product patch meshes (type 7 shadings in
 * PDF). Mesh patterns may also be used to create other types of
 * shadings that are special cases of tensor-product patch meshes such
 * as Coons patch meshes (type 6 shading in PDF) and Gouraud-shaded
 * triangle meshes (type 4 and 5 shadings in PDF).
 *
 * Mesh patterns consist of one or more tensor-product patches, which
 * should be defined before using the mesh pattern. Using a mesh
 * pattern with a partially defined patch as source or mask will put
 * the context in an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * A tensor-product patch is defined by 4 Bézier curves (side 0, 1, 2,
 * 3) and by 4 additional control points (P0, P1, P2, P3) that provide
 * further control over the patch and complete the definition of the
 * tensor-product patch. The corner C0 is the first point of the
 * patch.
 *
 * Degenerate sides are permitted so straight lines may be used. A
 * zero length line on one side may be used to create 3 sided patches.
 *
 * <informalexample><screen>
 *       C1     Side 1       C2
 *        +---------------+
 *        |               |
 *        |  P1       P2  |
 *        |               |
 * Side 0 |               | Side 2
 *        |               |
 *        |               |
 *        |  P0       P3  |
 *        |               |
 *        +---------------+
 *      C0     Side 3        C3
 * </screen></informalexample>
 *
 * Each patch is constructed by first calling
 * cairo_mesh_pattern_begin_patch(), then cairo_mesh_pattern_move_to()
 * to specify the first point in the patch (C0). Then the sides are
 * specified with calls to cairo_mesh_pattern_curve_to() and
 * cairo_mesh_pattern_line_to().
 *
 * The four additional control points (P0, P1, P2, P3) in a patch can
 * be specified with cairo_mesh_pattern_set_control_point().
 *
 * At each corner of the patch (C0, C1, C2, C3) a color may be
 * specified with cairo_mesh_pattern_set_corner_color_rgb() or
 * cairo_mesh_pattern_set_corner_color_rgba(). Any corner whose color
 * is not explicitly specified defaults to transparent black.
 *
 * A Coons patch is a special case of the tensor-product patch where
 * the control points are implicitly defined by the sides of the
 * patch. The default value for any control point not specified is the
 * implicit value for a Coons patch, i.e. if no control points are
 * specified the patch is a Coons patch.
 *
 * A triangle is a special case of the tensor-product patch where the
 * control points are implicitly defined by the sides of the patch,
 * all the sides are lines and one of them has length 0, i.e. if the
 * patch is specified using just 3 lines, it is a triangle. If the
 * corners connected by the 0-length side have the same color, the
 * patch is a Gouraud-shaded triangle.
 *
 * Patches may be oriented differently to the above diagram. For
 * example the first point could be at the top left. The diagram only
 * shows the relationship between the sides, corners and control
 * points. Regardless of where the first point is located, when
 * specifying colors, corner 0 will always be the first point, corner
 * 1 the point between side 0 and side 1 etc.
 *
 * Calling cairo_mesh_pattern_end_patch() completes the current
 * patch. If less than 4 sides have been defined, the first missing
 * side is defined as a line from the current point to the first point
 * of the patch (C0) and the other sides are degenerate lines from C0
 * to C0. The corners between the added sides will all be coincident
 * with C0 of the patch and their color will be set to be the same as
 * the color of C0.
 *
 * Additional patches may be added with additional calls to
 * cairo_mesh_pattern_begin_patch()/cairo_mesh_pattern_end_patch().
 *
 * <informalexample><programlisting>
 * cairo_pattern_t *pattern = cairo_pattern_create_mesh ();
 *
 * /&ast; Add a Coons patch &ast;/
 * cairo_mesh_pattern_begin_patch (pattern);
 * cairo_mesh_pattern_move_to (pattern, 0, 0);
 * cairo_mesh_pattern_curve_to (pattern, 30, -30,  60,  30, 100, 0);
 * cairo_mesh_pattern_curve_to (pattern, 60,  30, 130,  60, 100, 100);
 * cairo_mesh_pattern_curve_to (pattern, 60,  70,  30, 130,   0, 100);
 * cairo_mesh_pattern_curve_to (pattern, 30,  70, -30,  30,   0, 0);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 0, 1, 0, 0);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 1, 0, 1, 0);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 2, 0, 0, 1);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 3, 1, 1, 0);
 * cairo_mesh_pattern_end_patch (pattern);
 *
 * /&ast; Add a Gouraud-shaded triangle &ast;/
 * cairo_mesh_pattern_begin_patch (pattern)
 * cairo_mesh_pattern_move_to (pattern, 100, 100);
 * cairo_mesh_pattern_line_to (pattern, 130, 130);
 * cairo_mesh_pattern_line_to (pattern, 130,  70);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 0, 1, 0, 0);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 1, 0, 1, 0);
 * cairo_mesh_pattern_set_corner_color_rgb (pattern, 2, 0, 0, 1);
 * cairo_mesh_pattern_end_patch (pattern)
 * </programlisting></informalexample>
 *
 * When two patches overlap, the last one that has been added is drawn
 * over the first one.
 *
 * When a patch folds over itself, points are sorted depending on
 * their parameter coordinates inside the patch. The v coordinate
 * ranges from 0 to 1 when moving from side 3 to side 1; the u
 * coordinate ranges from 0 to 1 when going from side 0 to side
 * 2. Points with higher v coordinate hide points with lower v
 * coordinate. When two points have the same v coordinate, the one
 * with higher u coordinate is above. This means that points nearer to
 * side 1 are above points nearer to side 3; when this is not
 * sufficient to decide which point is above (for example when both
 * points belong to side 1 or side 3) points nearer to side 2 are
 * above points nearer to side 0.
 *
 * For a complete definition of tensor-product patches, see the PDF
 * specification (ISO32000), which describes the parametrization in
 * detail.
 *
 * Note: The coordinates are always in pattern space. For a new
 * pattern, pattern space is identical to user space, but the
 * relationship between the spaces can be changed with
 * cairo_pattern_set_matrix().
 *
 * Return value: the newly created #cairo_pattern_t if successful, or
 * an error pattern in case of no memory. The caller owns the returned
 * object and should call cairo_pattern_destroy() when finished with
 * it.
 *
 * This function will always return a valid pointer, but if an error
 * occurred the pattern status will be set to an error. To inspect the
 * status of a pattern use cairo_pattern_status().
 *
 * Since: 1.12
 **/
cairo_pattern_t *
cairo_pattern_create_mesh (void)
{
    cairo_mesh_pattern_t *pattern;

    pattern =
	_freed_pool_get (&freed_pattern_pool[CAIRO_PATTERN_TYPE_MESH]);
    if (unlikely (pattern == NULL)) {
	pattern = _cairo_malloc (sizeof (cairo_mesh_pattern_t));
	if (unlikely (pattern == NULL)) {
	    _cairo_error_throw (CAIRO_STATUS_NO_MEMORY);
	    return (cairo_pattern_t *) &_cairo_pattern_nil.base;
	}
    }

    CAIRO_MUTEX_INITIALIZE ();

    _cairo_pattern_init (&pattern->base, CAIRO_PATTERN_TYPE_MESH);
    _cairo_array_init (&pattern->patches, sizeof (cairo_mesh_patch_t));
    pattern->current_patch = NULL;
    CAIRO_REFERENCE_COUNT_INIT (&pattern->base.ref_count, 1);

    return &pattern->base;
}

/**
 * cairo_pattern_reference:
 * @pattern: a #cairo_pattern_t
 *
 * Increases the reference count on @pattern by one. This prevents
 * @pattern from being destroyed until a matching call to
 * cairo_pattern_destroy() is made.
 *
 * Use cairo_pattern_get_reference_count() to get the number of
 * references to a #cairo_pattern_t.
 *
 * Return value: the referenced #cairo_pattern_t.
 *
 * Since: 1.0
 **/
cairo_pattern_t *
cairo_pattern_reference (cairo_pattern_t *pattern)
{
    if (pattern == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&pattern->ref_count))
	return pattern;

    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&pattern->ref_count));

    _cairo_reference_count_inc (&pattern->ref_count);

    return pattern;
}
slim_hidden_def (cairo_pattern_reference);

/**
 * cairo_pattern_get_type:
 * @pattern: a #cairo_pattern_t
 *
 * Get the pattern's type.  See #cairo_pattern_type_t for available
 * types.
 *
 * Return value: The type of @pattern.
 *
 * Since: 1.2
 **/
cairo_pattern_type_t
cairo_pattern_get_type (cairo_pattern_t *pattern)
{
    return pattern->type;
}

/**
 * cairo_pattern_status:
 * @pattern: a #cairo_pattern_t
 *
 * Checks whether an error has previously occurred for this
 * pattern.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, %CAIRO_STATUS_NO_MEMORY,
 * %CAIRO_STATUS_INVALID_MATRIX, %CAIRO_STATUS_PATTERN_TYPE_MISMATCH,
 * or %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.0
 **/
cairo_status_t
cairo_pattern_status (cairo_pattern_t *pattern)
{
    return pattern->status;
}

/**
 * cairo_pattern_destroy:
 * @pattern: a #cairo_pattern_t
 *
 * Decreases the reference count on @pattern by one. If the result is
 * zero, then @pattern and all associated resources are freed.  See
 * cairo_pattern_reference().
 *
 * Since: 1.0
 **/
void
cairo_pattern_destroy (cairo_pattern_t *pattern)
{
    cairo_pattern_type_t type;

    if (pattern == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&pattern->ref_count))
	return;

    assert (CAIRO_REFERENCE_COUNT_HAS_REFERENCE (&pattern->ref_count));

    if (! _cairo_reference_count_dec_and_test (&pattern->ref_count))
	return;

    type = pattern->type;
    _cairo_pattern_fini (pattern);

    /* maintain a small cache of freed patterns */
    if (type < ARRAY_LENGTH (freed_pattern_pool))
	_freed_pool_put (&freed_pattern_pool[type], pattern);
    else
	free (pattern);
}
slim_hidden_def (cairo_pattern_destroy);

/**
 * cairo_pattern_get_reference_count:
 * @pattern: a #cairo_pattern_t
 *
 * Returns the current reference count of @pattern.
 *
 * Return value: the current reference count of @pattern.  If the
 * object is a nil object, 0 will be returned.
 *
 * Since: 1.4
 **/
unsigned int
cairo_pattern_get_reference_count (cairo_pattern_t *pattern)
{
    if (pattern == NULL ||
	    CAIRO_REFERENCE_COUNT_IS_INVALID (&pattern->ref_count))
	return 0;

    return CAIRO_REFERENCE_COUNT_GET_VALUE (&pattern->ref_count);
}

/**
 * cairo_pattern_get_user_data:
 * @pattern: a #cairo_pattern_t
 * @key: the address of the #cairo_user_data_key_t the user data was
 * attached to
 *
 * Return user data previously attached to @pattern using the
 * specified key.  If no user data has been attached with the given
 * key this function returns %NULL.
 *
 * Return value: the user data previously attached or %NULL.
 *
 * Since: 1.4
 **/
void *
cairo_pattern_get_user_data (cairo_pattern_t		 *pattern,
			     const cairo_user_data_key_t *key)
{
    return _cairo_user_data_array_get_data (&pattern->user_data,
					    key);
}

/**
 * cairo_pattern_set_user_data:
 * @pattern: a #cairo_pattern_t
 * @key: the address of a #cairo_user_data_key_t to attach the user data to
 * @user_data: the user data to attach to the #cairo_pattern_t
 * @destroy: a #cairo_destroy_func_t which will be called when the
 * #cairo_t is destroyed or when new user data is attached using the
 * same key.
 *
 * Attach user data to @pattern.  To remove user data from a surface,
 * call this function with the key that was used to set it and %NULL
 * for @data.
 *
 * Return value: %CAIRO_STATUS_SUCCESS or %CAIRO_STATUS_NO_MEMORY if a
 * slot could not be allocated for the user data.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_set_user_data (cairo_pattern_t		 *pattern,
			     const cairo_user_data_key_t *key,
			     void			 *user_data,
			     cairo_destroy_func_t	  destroy)
{
    if (CAIRO_REFERENCE_COUNT_IS_INVALID (&pattern->ref_count))
	return pattern->status;

    return _cairo_user_data_array_set_data (&pattern->user_data,
					    key, user_data, destroy);
}

/**
 * cairo_mesh_pattern_begin_patch:
 * @pattern: a #cairo_pattern_t
 *
 * Begin a patch in a mesh pattern.
 *
 * After calling this function, the patch shape should be defined with
 * cairo_mesh_pattern_move_to(), cairo_mesh_pattern_line_to() and
 * cairo_mesh_pattern_curve_to().
 *
 * After defining the patch, cairo_mesh_pattern_end_patch() must be
 * called before using @pattern as a source or mask.
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @pattern already has a
 * current patch, it will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_begin_patch (cairo_pattern_t *pattern)
{
    cairo_mesh_pattern_t *mesh;
    cairo_status_t status;
    cairo_mesh_patch_t *current_patch;
    int i;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    status = _cairo_array_allocate (&mesh->patches, 1, (void **) &current_patch);
    if (unlikely (status)) {
	_cairo_pattern_set_error (pattern, status);
	return;
    }

    mesh->current_patch = current_patch;
    mesh->current_side = -2; /* no current point */

    for (i = 0; i < 4; i++)
	mesh->has_control_point[i] = FALSE;

    for (i = 0; i < 4; i++)
	mesh->has_color[i] = FALSE;
}



/**
 * cairo_mesh_pattern_end_patch:
 * @pattern: a #cairo_pattern_t
 *
 * Indicates the end of the current patch in a mesh pattern.
 *
 * If the current patch has less than 4 sides, it is closed with a
 * straight line from the current point to the first point of the
 * patch as if cairo_mesh_pattern_line_to() was used.
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @pattern has no current
 * patch or the current patch has no current point, @pattern will be
 * put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_end_patch (cairo_pattern_t *pattern)
{
    cairo_mesh_pattern_t *mesh;
    cairo_mesh_patch_t *current_patch;
    int i;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    current_patch = mesh->current_patch;
    if (unlikely (!current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (unlikely (mesh->current_side == -2)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    while (mesh->current_side < 3) {
	int corner_num;

	cairo_mesh_pattern_line_to (pattern,
				    current_patch->points[0][0].x,
				    current_patch->points[0][0].y);

	corner_num = mesh->current_side + 1;
	if (corner_num < 4 && ! mesh->has_color[corner_num]) {
	    current_patch->colors[corner_num] = current_patch->colors[0];
	    mesh->has_color[corner_num] = TRUE;
	}
    }

    for (i = 0; i < 4; i++) {
	if (! mesh->has_control_point[i])
	    _calc_control_point (current_patch, i);
    }

    for (i = 0; i < 4; i++) {
	if (! mesh->has_color[i])
	    current_patch->colors[i] = *CAIRO_COLOR_TRANSPARENT;
    }

    mesh->current_patch = NULL;
}

/**
 * cairo_mesh_pattern_curve_to:
 * @pattern: a #cairo_pattern_t
 * @x1: the X coordinate of the first control point
 * @y1: the Y coordinate of the first control point
 * @x2: the X coordinate of the second control point
 * @y2: the Y coordinate of the second control point
 * @x3: the X coordinate of the end of the curve
 * @y3: the Y coordinate of the end of the curve
 *
 * Adds a cubic Bézier spline to the current patch from the current
 * point to position (@x3, @y3) in pattern-space coordinates, using
 * (@x1, @y1) and (@x2, @y2) as the control points.
 *
 * If the current patch has no current point before the call to
 * cairo_mesh_pattern_curve_to(), this function will behave as if
 * preceded by a call to cairo_mesh_pattern_move_to(@pattern, @x1,
 * @y1).
 *
 * After this call the current point will be (@x3, @y3).
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @pattern has no current
 * patch or the current patch already has 4 sides, @pattern will be
 * put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_curve_to (cairo_pattern_t *pattern,
			     double x1, double y1,
			     double x2, double y2,
			     double x3, double y3)
{
    cairo_mesh_pattern_t *mesh;
    int current_point, i, j;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (!mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (unlikely (mesh->current_side == 3)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (mesh->current_side == -2)
	cairo_mesh_pattern_move_to (pattern, x1, y1);

    assert (mesh->current_side >= -1);
    assert (pattern->status == CAIRO_STATUS_SUCCESS);

    mesh->current_side++;

    current_point = 3 * mesh->current_side;

    current_point++;
    i = mesh_path_point_i[current_point];
    j = mesh_path_point_j[current_point];
    mesh->current_patch->points[i][j].x = x1;
    mesh->current_patch->points[i][j].y = y1;

    current_point++;
    i = mesh_path_point_i[current_point];
    j = mesh_path_point_j[current_point];
    mesh->current_patch->points[i][j].x = x2;
    mesh->current_patch->points[i][j].y = y2;

    current_point++;
    if (current_point < 12) {
	i = mesh_path_point_i[current_point];
	j = mesh_path_point_j[current_point];
	mesh->current_patch->points[i][j].x = x3;
	mesh->current_patch->points[i][j].y = y3;
    }
}
slim_hidden_def (cairo_mesh_pattern_curve_to);

/**
 * cairo_mesh_pattern_line_to:
 * @pattern: a #cairo_pattern_t
 * @x: the X coordinate of the end of the new line
 * @y: the Y coordinate of the end of the new line
 *
 * Adds a line to the current patch from the current point to position
 * (@x, @y) in pattern-space coordinates.
 *
 * If there is no current point before the call to
 * cairo_mesh_pattern_line_to() this function will behave as
 * cairo_mesh_pattern_move_to(@pattern, @x, @y).
 *
 * After this call the current point will be (@x, @y).
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @pattern has no current
 * patch or the current patch already has 4 sides, @pattern will be
 * put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_line_to (cairo_pattern_t *pattern,
			    double x, double y)
{
    cairo_mesh_pattern_t *mesh;
    cairo_point_double_t last_point;
    int last_point_idx, i, j;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (!mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (unlikely (mesh->current_side == 3)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (mesh->current_side == -2) {
	cairo_mesh_pattern_move_to (pattern, x, y);
	return;
    }

    last_point_idx = 3 * (mesh->current_side + 1);
    i = mesh_path_point_i[last_point_idx];
    j = mesh_path_point_j[last_point_idx];

    last_point = mesh->current_patch->points[i][j];

    cairo_mesh_pattern_curve_to (pattern,
				 (2 * last_point.x + x) * (1. / 3),
				 (2 * last_point.y + y) * (1. / 3),
				 (last_point.x + 2 * x) * (1. / 3),
				 (last_point.y + 2 * y) * (1. / 3),
				 x, y);
}
slim_hidden_def (cairo_mesh_pattern_line_to);

/**
 * cairo_mesh_pattern_move_to:
 * @pattern: a #cairo_pattern_t
 * @x: the X coordinate of the new position
 * @y: the Y coordinate of the new position
 *
 * Define the first point of the current patch in a mesh pattern.
 *
 * After this call the current point will be (@x, @y).
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @pattern has no current
 * patch or the current patch already has at least one side, @pattern
 * will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_move_to (cairo_pattern_t *pattern,
			    double x, double y)
{
    cairo_mesh_pattern_t *mesh;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (!mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    if (unlikely (mesh->current_side >= 0)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    mesh->current_side = -1;
    mesh->current_patch->points[0][0].x = x;
    mesh->current_patch->points[0][0].y = y;
}
slim_hidden_def (cairo_mesh_pattern_move_to);

/**
 * cairo_mesh_pattern_set_control_point:
 * @pattern: a #cairo_pattern_t
 * @point_num: the control point to set the position for
 * @x: the X coordinate of the control point
 * @y: the Y coordinate of the control point
 *
 * Set an internal control point of the current patch.
 *
 * Valid values for @point_num are from 0 to 3 and identify the
 * control points as explained in cairo_pattern_create_mesh().
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @point_num is not valid,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_INDEX.  If @pattern has no current patch,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_set_control_point (cairo_pattern_t *pattern,
				      unsigned int     point_num,
				      double           x,
				      double           y)
{
    cairo_mesh_pattern_t *mesh;
    int i, j;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    if (unlikely (point_num > 3)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_INDEX);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (!mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    i = mesh_control_point_i[point_num];
    j = mesh_control_point_j[point_num];

    mesh->current_patch->points[i][j].x = x;
    mesh->current_patch->points[i][j].y = y;
    mesh->has_control_point[point_num] = TRUE;
}


/**
 * cairo_mesh_pattern_set_corner_color_rgb:
 * @pattern: a #cairo_pattern_t
 * @corner_num: the corner to set the color for
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 *
 * Sets the color of a corner of the current patch in a mesh pattern.
 *
 * The color is specified in the same way as in cairo_set_source_rgb().
 *
 * Valid values for @corner_num are from 0 to 3 and identify the
 * corners as explained in cairo_pattern_create_mesh().
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @corner_num is not valid,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_INDEX.  If @pattern has no current patch,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_set_corner_color_rgb (cairo_pattern_t *pattern,
					 unsigned int     corner_num,
					 double red, double green, double blue)
{
    cairo_mesh_pattern_set_corner_color_rgba (pattern, corner_num, red, green, blue, 1.0);
}

/**
 * cairo_mesh_pattern_set_corner_color_rgba:
 * @pattern: a #cairo_pattern_t
 * @corner_num: the corner to set the color for
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 * @alpha: alpha component of color
 *
 * Sets the color of a corner of the current patch in a mesh pattern.
 *
 * The color is specified in the same way as in cairo_set_source_rgba().
 *
 * Valid values for @corner_num are from 0 to 3 and identify the
 * corners as explained in cairo_pattern_create_mesh().
 *
 * Note: If @pattern is not a mesh pattern then @pattern will be put
 * into an error status with a status of
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If @corner_num is not valid,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_INDEX.  If @pattern has no current patch,
 * @pattern will be put into an error status with a status of
 * %CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
 *
 * Since: 1.12
 **/
void
cairo_mesh_pattern_set_corner_color_rgba (cairo_pattern_t *pattern,
					  unsigned int     corner_num,
					  double red, double green, double blue,
					  double alpha)
{
    cairo_mesh_pattern_t *mesh;

    if (unlikely (pattern->status))
	return;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    if (unlikely (corner_num > 3)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_INDEX);
	return;
    }

    mesh = (cairo_mesh_pattern_t *) pattern;
    if (unlikely (!mesh->current_patch)) {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_INVALID_MESH_CONSTRUCTION);
	return;
    }

    red    = _cairo_restrict_value (red,    0.0, 1.0);
    green  = _cairo_restrict_value (green,  0.0, 1.0);
    blue   = _cairo_restrict_value (blue,   0.0, 1.0);
    alpha  = _cairo_restrict_value (alpha,  0.0, 1.0);

    _cairo_mesh_pattern_set_corner_color (mesh, corner_num, red, green, blue, alpha);
}
slim_hidden_def (cairo_mesh_pattern_set_corner_color_rgba);


/**
 * cairo_pattern_add_color_stop_rgb:
 * @pattern: a #cairo_pattern_t
 * @offset: an offset in the range [0.0 .. 1.0]
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 *
 * Adds an opaque color stop to a gradient pattern. The offset
 * specifies the location along the gradient's control vector. For
 * example, a linear gradient's control vector is from (x0,y0) to
 * (x1,y1) while a radial gradient's control vector is from any point
 * on the start circle to the corresponding point on the end circle.
 *
 * The color is specified in the same way as in cairo_set_source_rgb().
 *
 * If two (or more) stops are specified with identical offset values,
 * they will be sorted according to the order in which the stops are
 * added, (stops added earlier will compare less than stops added
 * later). This can be useful for reliably making sharp color
 * transitions instead of the typical blend.
 *
 *
 * Note: If the pattern is not a gradient pattern, (eg. a linear or
 * radial pattern), then the pattern will be put into an error status
 * with a status of %CAIRO_STATUS_PATTERN_TYPE_MISMATCH.
 *
 * Since: 1.0
 **/
void
cairo_pattern_add_color_stop_rgb (cairo_pattern_t *pattern,
				  double	   offset,
				  double	   red,
				  double	   green,
				  double	   blue)
{
    cairo_pattern_add_color_stop_rgba (pattern, offset, red, green, blue, 1.0);
}

/**
 * cairo_pattern_add_color_stop_rgba:
 * @pattern: a #cairo_pattern_t
 * @offset: an offset in the range [0.0 .. 1.0]
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 * @alpha: alpha component of color
 *
 * Adds a translucent color stop to a gradient pattern. The offset
 * specifies the location along the gradient's control vector. For
 * example, a linear gradient's control vector is from (x0,y0) to
 * (x1,y1) while a radial gradient's control vector is from any point
 * on the start circle to the corresponding point on the end circle.
 *
 * The color is specified in the same way as in cairo_set_source_rgba().
 *
 * If two (or more) stops are specified with identical offset values,
 * they will be sorted according to the order in which the stops are
 * added, (stops added earlier will compare less than stops added
 * later). This can be useful for reliably making sharp color
 * transitions instead of the typical blend.
 *
 * Note: If the pattern is not a gradient pattern, (eg. a linear or
 * radial pattern), then the pattern will be put into an error status
 * with a status of %CAIRO_STATUS_PATTERN_TYPE_MISMATCH.
 *
 * Since: 1.0
 **/
void
cairo_pattern_add_color_stop_rgba (cairo_pattern_t *pattern,
				   double	   offset,
				   double	   red,
				   double	   green,
				   double	   blue,
				   double	   alpha)
{
    if (pattern->status)
	return;

    if (pattern->type != CAIRO_PATTERN_TYPE_LINEAR &&
	pattern->type != CAIRO_PATTERN_TYPE_RADIAL)
    {
	_cairo_pattern_set_error (pattern, CAIRO_STATUS_PATTERN_TYPE_MISMATCH);
	return;
    }

    offset = _cairo_restrict_value (offset, 0.0, 1.0);
    red    = _cairo_restrict_value (red,    0.0, 1.0);
    green  = _cairo_restrict_value (green,  0.0, 1.0);
    blue   = _cairo_restrict_value (blue,   0.0, 1.0);
    alpha  = _cairo_restrict_value (alpha,  0.0, 1.0);

    _cairo_pattern_add_color_stop ((cairo_gradient_pattern_t *) pattern,
				   offset, red, green, blue, alpha);
}
slim_hidden_def (cairo_pattern_add_color_stop_rgba);

/**
 * cairo_pattern_set_matrix:
 * @pattern: a #cairo_pattern_t
 * @matrix: a #cairo_matrix_t
 *
 * Sets the pattern's transformation matrix to @matrix. This matrix is
 * a transformation from user space to pattern space.
 *
 * When a pattern is first created it always has the identity matrix
 * for its transformation matrix, which means that pattern space is
 * initially identical to user space.
 *
 * Important: Please note that the direction of this transformation
 * matrix is from user space to pattern space. This means that if you
 * imagine the flow from a pattern to user space (and on to device
 * space), then coordinates in that flow will be transformed by the
 * inverse of the pattern matrix.
 *
 * For example, if you want to make a pattern appear twice as large as
 * it does by default the correct code to use is:
 *
 * <informalexample><programlisting>
 * cairo_matrix_init_scale (&amp;matrix, 0.5, 0.5);
 * cairo_pattern_set_matrix (pattern, &amp;matrix);
 * </programlisting></informalexample>
 *
 * Meanwhile, using values of 2.0 rather than 0.5 in the code above
 * would cause the pattern to appear at half of its default size.
 *
 * Also, please note the discussion of the user-space locking
 * semantics of cairo_set_source().
 *
 * Since: 1.0
 **/
void
cairo_pattern_set_matrix (cairo_pattern_t      *pattern,
			  const cairo_matrix_t *matrix)
{
    cairo_matrix_t inverse;
    cairo_status_t status;

    if (pattern->status)
	return;

    if (memcmp (&pattern->matrix, matrix, sizeof (cairo_matrix_t)) == 0)
	return;

    pattern->matrix = *matrix;
    _cairo_pattern_notify_observers (pattern, CAIRO_PATTERN_NOTIFY_MATRIX);

    inverse = *matrix;
    status = cairo_matrix_invert (&inverse);
    if (unlikely (status))
	status = _cairo_pattern_set_error (pattern, status);
}
slim_hidden_def (cairo_pattern_set_matrix);

/**
 * cairo_pattern_get_matrix:
 * @pattern: a #cairo_pattern_t
 * @matrix: return value for the matrix
 *
 * Stores the pattern's transformation matrix into @matrix.
 *
 * Since: 1.0
 **/
void
cairo_pattern_get_matrix (cairo_pattern_t *pattern, cairo_matrix_t *matrix)
{
    *matrix = pattern->matrix;
}

/**
 * cairo_pattern_set_filter:
 * @pattern: a #cairo_pattern_t
 * @filter: a #cairo_filter_t describing the filter to use for resizing
 * the pattern
 *
 * Sets the filter to be used for resizing when using this pattern.
 * See #cairo_filter_t for details on each filter.
 *
 * * Note that you might want to control filtering even when you do not
 * have an explicit #cairo_pattern_t object, (for example when using
 * cairo_set_source_surface()). In these cases, it is convenient to
 * use cairo_get_source() to get access to the pattern that cairo
 * creates implicitly. For example:
 *
 * <informalexample><programlisting>
 * cairo_set_source_surface (cr, image, x, y);
 * cairo_pattern_set_filter (cairo_get_source (cr), CAIRO_FILTER_NEAREST);
 * </programlisting></informalexample>
 *
 * Since: 1.0
 **/
void
cairo_pattern_set_filter (cairo_pattern_t *pattern, cairo_filter_t filter)
{
    if (pattern->status)
	return;

    pattern->filter = filter;
    _cairo_pattern_notify_observers (pattern, CAIRO_PATTERN_NOTIFY_FILTER);
}

/**
 * cairo_pattern_get_filter:
 * @pattern: a #cairo_pattern_t
 *
 * Gets the current filter for a pattern.  See #cairo_filter_t
 * for details on each filter.
 *
 * Return value: the current filter used for resizing the pattern.
 *
 * Since: 1.0
 **/
cairo_filter_t
cairo_pattern_get_filter (cairo_pattern_t *pattern)
{
    return pattern->filter;
}

/**
 * cairo_pattern_set_extend:
 * @pattern: a #cairo_pattern_t
 * @extend: a #cairo_extend_t describing how the area outside of the
 * pattern will be drawn
 *
 * Sets the mode to be used for drawing outside the area of a pattern.
 * See #cairo_extend_t for details on the semantics of each extend
 * strategy.
 *
 * The default extend mode is %CAIRO_EXTEND_NONE for surface patterns
 * and %CAIRO_EXTEND_PAD for gradient patterns.
 *
 * Since: 1.0
 **/
void
cairo_pattern_set_extend (cairo_pattern_t *pattern, cairo_extend_t extend)
{
    if (pattern->status)
	return;

    pattern->extend = extend;
    _cairo_pattern_notify_observers (pattern, CAIRO_PATTERN_NOTIFY_EXTEND);
}

/**
 * cairo_pattern_get_extend:
 * @pattern: a #cairo_pattern_t
 *
 * Gets the current extend mode for a pattern.  See #cairo_extend_t
 * for details on the semantics of each extend strategy.
 *
 * Return value: the current extend strategy used for drawing the
 * pattern.
 *
 * Since: 1.0
 **/
cairo_extend_t
cairo_pattern_get_extend (cairo_pattern_t *pattern)
{
    return pattern->extend;
}
slim_hidden_def (cairo_pattern_get_extend);


/**
 * cairo_pattern_get_rgba:
 * @pattern: a #cairo_pattern_t
 * @red: return value for red component of color, or %NULL
 * @green: return value for green component of color, or %NULL
 * @blue: return value for blue component of color, or %NULL
 * @alpha: return value for alpha component of color, or %NULL
 *
 * Gets the solid color for a solid color pattern.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if the pattern is not a solid
 * color pattern.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_rgba (cairo_pattern_t *pattern,
			double *red, double *green,
			double *blue, double *alpha)
{
    cairo_solid_pattern_t *solid = (cairo_solid_pattern_t*) pattern;
    double r0, g0, b0, a0;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_SOLID)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    _cairo_color_get_rgba (&solid->color, &r0, &g0, &b0, &a0);

    if (red)
	*red = r0;
    if (green)
	*green = g0;
    if (blue)
	*blue = b0;
    if (alpha)
	*alpha = a0;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_pattern_get_surface:
 * @pattern: a #cairo_pattern_t
 * @surface: return value for surface of pattern, or %NULL
 *
 * Gets the surface of a surface pattern.  The reference returned in
 * @surface is owned by the pattern; the caller should call
 * cairo_surface_reference() if the surface is to be retained.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if the pattern is not a surface
 * pattern.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_surface (cairo_pattern_t *pattern,
			   cairo_surface_t **surface)
{
    cairo_surface_pattern_t *spat = (cairo_surface_pattern_t*) pattern;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_SURFACE)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (surface)
	*surface = spat->surface;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_pattern_get_color_stop_rgba:
 * @pattern: a #cairo_pattern_t
 * @index: index of the stop to return data for
 * @offset: return value for the offset of the stop, or %NULL
 * @red: return value for red component of color, or %NULL
 * @green: return value for green component of color, or %NULL
 * @blue: return value for blue component of color, or %NULL
 * @alpha: return value for alpha component of color, or %NULL
 *
 * Gets the color and offset information at the given @index for a
 * gradient pattern.  Values of @index range from 0 to n-1
 * where n is the number returned
 * by cairo_pattern_get_color_stop_count().
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or %CAIRO_STATUS_INVALID_INDEX
 * if @index is not valid for the given pattern.  If the pattern is
 * not a gradient pattern, %CAIRO_STATUS_PATTERN_TYPE_MISMATCH is
 * returned.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_color_stop_rgba (cairo_pattern_t *pattern,
				   int index, double *offset,
				   double *red, double *green,
				   double *blue, double *alpha)
{
    cairo_gradient_pattern_t *gradient = (cairo_gradient_pattern_t*) pattern;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_LINEAR &&
	pattern->type != CAIRO_PATTERN_TYPE_RADIAL)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (index < 0 || (unsigned int) index >= gradient->n_stops)
	return _cairo_error (CAIRO_STATUS_INVALID_INDEX);

    if (offset)
	*offset = gradient->stops[index].offset;
    if (red)
	*red = gradient->stops[index].color.red;
    if (green)
	*green = gradient->stops[index].color.green;
    if (blue)
	*blue = gradient->stops[index].color.blue;
    if (alpha)
	*alpha = gradient->stops[index].color.alpha;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_pattern_get_color_stop_count:
 * @pattern: a #cairo_pattern_t
 * @count: return value for the number of color stops, or %NULL
 *
 * Gets the number of color stops specified in the given gradient
 * pattern.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if @pattern is not a gradient
 * pattern.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_color_stop_count (cairo_pattern_t *pattern,
				    int *count)
{
    cairo_gradient_pattern_t *gradient = (cairo_gradient_pattern_t*) pattern;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_LINEAR &&
	pattern->type != CAIRO_PATTERN_TYPE_RADIAL)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (count)
	*count = gradient->n_stops;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_pattern_get_linear_points:
 * @pattern: a #cairo_pattern_t
 * @x0: return value for the x coordinate of the first point, or %NULL
 * @y0: return value for the y coordinate of the first point, or %NULL
 * @x1: return value for the x coordinate of the second point, or %NULL
 * @y1: return value for the y coordinate of the second point, or %NULL
 *
 * Gets the gradient endpoints for a linear gradient.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if @pattern is not a linear
 * gradient pattern.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_linear_points (cairo_pattern_t *pattern,
				 double *x0, double *y0,
				 double *x1, double *y1)
{
    cairo_linear_pattern_t *linear = (cairo_linear_pattern_t*) pattern;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_LINEAR)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (x0)
	*x0 = linear->pd1.x;
    if (y0)
	*y0 = linear->pd1.y;
    if (x1)
	*x1 = linear->pd2.x;
    if (y1)
	*y1 = linear->pd2.y;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_pattern_get_radial_circles:
 * @pattern: a #cairo_pattern_t
 * @x0: return value for the x coordinate of the center of the first circle, or %NULL
 * @y0: return value for the y coordinate of the center of the first circle, or %NULL
 * @r0: return value for the radius of the first circle, or %NULL
 * @x1: return value for the x coordinate of the center of the second circle, or %NULL
 * @y1: return value for the y coordinate of the center of the second circle, or %NULL
 * @r1: return value for the radius of the second circle, or %NULL
 *
 * Gets the gradient endpoint circles for a radial gradient, each
 * specified as a center coordinate and a radius.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if @pattern is not a radial
 * gradient pattern.
 *
 * Since: 1.4
 **/
cairo_status_t
cairo_pattern_get_radial_circles (cairo_pattern_t *pattern,
				  double *x0, double *y0, double *r0,
				  double *x1, double *y1, double *r1)
{
    cairo_radial_pattern_t *radial = (cairo_radial_pattern_t*) pattern;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_RADIAL)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (x0)
	*x0 = radial->cd1.center.x;
    if (y0)
	*y0 = radial->cd1.center.y;
    if (r0)
	*r0 = radial->cd1.radius;
    if (x1)
	*x1 = radial->cd2.center.x;
    if (y1)
	*y1 = radial->cd2.center.y;
    if (r1)
	*r1 = radial->cd2.radius;

    return CAIRO_STATUS_SUCCESS;
}

/**
 * cairo_mesh_pattern_get_patch_count:
 * @pattern: a #cairo_pattern_t
 * @count: return value for the number patches, or %NULL
 *
 * Gets the number of patches specified in the given mesh pattern.
 *
 * The number only includes patches which have been finished by
 * calling cairo_mesh_pattern_end_patch(). For example it will be 0
 * during the definition of the first patch.
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or
 * %CAIRO_STATUS_PATTERN_TYPE_MISMATCH if @pattern is not a mesh
 * pattern.
 *
 * Since: 1.12
 **/
cairo_status_t
cairo_mesh_pattern_get_patch_count (cairo_pattern_t *pattern,
				    unsigned int *count)
{
    cairo_mesh_pattern_t *mesh = (cairo_mesh_pattern_t *) pattern;

    if (unlikely (pattern->status))
	return pattern->status;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH))
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (count) {
	*count = _cairo_array_num_elements (&mesh->patches);
	if (mesh->current_patch)
	    *count -= 1;
    }

    return CAIRO_STATUS_SUCCESS;
}
slim_hidden_def (cairo_mesh_pattern_get_patch_count);

/**
 * cairo_mesh_pattern_get_path:
 * @pattern: a #cairo_pattern_t
 * @patch_num: the patch number to return data for
 *
 * Gets path defining the patch @patch_num for a mesh
 * pattern.
 *
 * @patch_num can range from 0 to n-1 where n is the number returned by
 * cairo_mesh_pattern_get_patch_count().
 *
 * Return value: the path defining the patch, or a path with status
 * %CAIRO_STATUS_INVALID_INDEX if @patch_num or @point_num is not
 * valid for @pattern. If @pattern is not a mesh pattern, a path with
 * status %CAIRO_STATUS_PATTERN_TYPE_MISMATCH is returned.
 *
 * Since: 1.12
 **/
cairo_path_t *
cairo_mesh_pattern_get_path (cairo_pattern_t *pattern,
			     unsigned int patch_num)
{
    cairo_mesh_pattern_t *mesh = (cairo_mesh_pattern_t *) pattern;
    const cairo_mesh_patch_t *patch;
    cairo_path_t *path;
    cairo_path_data_t *data;
    unsigned int patch_count;
    int l, current_point;

    if (unlikely (pattern->status))
	return _cairo_path_create_in_error (pattern->status);

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH))
	return _cairo_path_create_in_error (_cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH));

    patch_count = _cairo_array_num_elements (&mesh->patches);
    if (mesh->current_patch)
	patch_count--;

    if (unlikely (patch_num >= patch_count))
	return _cairo_path_create_in_error (_cairo_error (CAIRO_STATUS_INVALID_INDEX));

    patch = _cairo_array_index_const (&mesh->patches, patch_num);

    path = _cairo_malloc (sizeof (cairo_path_t));
    if (path == NULL)
	return _cairo_path_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));

    path->num_data = 18;
    path->data = _cairo_malloc_ab (path->num_data,
				   sizeof (cairo_path_data_t));
    if (path->data == NULL) {
	free (path);
	return _cairo_path_create_in_error (_cairo_error (CAIRO_STATUS_NO_MEMORY));
    }

    data = path->data;
    data[0].header.type = CAIRO_PATH_MOVE_TO;
    data[0].header.length = 2;
    data[1].point.x = patch->points[0][0].x;
    data[1].point.y = patch->points[0][0].y;
    data += data[0].header.length;

    current_point = 0;

    for (l = 0; l < 4; l++) {
	int i, j, k;

	data[0].header.type = CAIRO_PATH_CURVE_TO;
	data[0].header.length = 4;

	for (k = 1; k < 4; k++) {
	    current_point = (current_point + 1) % 12;
	    i = mesh_path_point_i[current_point];
	    j = mesh_path_point_j[current_point];
	    data[k].point.x = patch->points[i][j].x;
	    data[k].point.y = patch->points[i][j].y;
	}

	data += data[0].header.length;
    }

    path->status = CAIRO_STATUS_SUCCESS;

    return path;
}
slim_hidden_def (cairo_mesh_pattern_get_path);

/**
 * cairo_mesh_pattern_get_corner_color_rgba:
 * @pattern: a #cairo_pattern_t
 * @patch_num: the patch number to return data for
 * @corner_num: the corner number to return data for
 * @red: return value for red component of color, or %NULL
 * @green: return value for green component of color, or %NULL
 * @blue: return value for blue component of color, or %NULL
 * @alpha: return value for alpha component of color, or %NULL
 *
 * Gets the color information in corner @corner_num of patch
 * @patch_num for a mesh pattern.
 *
 * @patch_num can range from 0 to n-1 where n is the number returned by
 * cairo_mesh_pattern_get_patch_count().
 *
 * Valid values for @corner_num are from 0 to 3 and identify the
 * corners as explained in cairo_pattern_create_mesh().
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or %CAIRO_STATUS_INVALID_INDEX
 * if @patch_num or @corner_num is not valid for @pattern. If
 * @pattern is not a mesh pattern, %CAIRO_STATUS_PATTERN_TYPE_MISMATCH
 * is returned.
 *
 * Since: 1.12
 **/
cairo_status_t
cairo_mesh_pattern_get_corner_color_rgba (cairo_pattern_t *pattern,
					  unsigned int patch_num,
					  unsigned int corner_num,
					  double *red, double *green,
					  double *blue, double *alpha)
{
    cairo_mesh_pattern_t *mesh = (cairo_mesh_pattern_t *) pattern;
    unsigned int patch_count;
    const cairo_mesh_patch_t *patch;

    if (unlikely (pattern->status))
	return pattern->status;

    if (unlikely (pattern->type != CAIRO_PATTERN_TYPE_MESH))
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (unlikely (corner_num > 3))
	return _cairo_error (CAIRO_STATUS_INVALID_INDEX);

    patch_count = _cairo_array_num_elements (&mesh->patches);
    if (mesh->current_patch)
	patch_count--;

    if (unlikely (patch_num >= patch_count))
	return _cairo_error (CAIRO_STATUS_INVALID_INDEX);

    patch = _cairo_array_index_const (&mesh->patches, patch_num);

    if (red)
	*red = patch->colors[corner_num].red;
    if (green)
	*green = patch->colors[corner_num].green;
    if (blue)
	*blue = patch->colors[corner_num].blue;
    if (alpha)
	*alpha = patch->colors[corner_num].alpha;

    return CAIRO_STATUS_SUCCESS;
}
slim_hidden_def (cairo_mesh_pattern_get_corner_color_rgba);

/**
 * cairo_mesh_pattern_get_control_point:
 * @pattern: a #cairo_pattern_t
 * @patch_num: the patch number to return data for
 * @point_num: the control point number to return data for
 * @x: return value for the x coordinate of the control point, or %NULL
 * @y: return value for the y coordinate of the control point, or %NULL
 *
 * Gets the control point @point_num of patch @patch_num for a mesh
 * pattern.
 *
 * @patch_num can range from 0 to n-1 where n is the number returned by
 * cairo_mesh_pattern_get_patch_count().
 *
 * Valid values for @point_num are from 0 to 3 and identify the
 * control points as explained in cairo_pattern_create_mesh().
 *
 * Return value: %CAIRO_STATUS_SUCCESS, or %CAIRO_STATUS_INVALID_INDEX
 * if @patch_num or @point_num is not valid for @pattern. If @pattern
 * is not a mesh pattern, %CAIRO_STATUS_PATTERN_TYPE_MISMATCH is
 * returned.
 *
 * Since: 1.12
 **/
cairo_status_t
cairo_mesh_pattern_get_control_point (cairo_pattern_t *pattern,
				      unsigned int patch_num,
				      unsigned int point_num,
				      double *x, double *y)
{
    cairo_mesh_pattern_t *mesh = (cairo_mesh_pattern_t *) pattern;
    const cairo_mesh_patch_t *patch;
    unsigned int patch_count;
    int i, j;

    if (pattern->status)
	return pattern->status;

    if (pattern->type != CAIRO_PATTERN_TYPE_MESH)
	return _cairo_error (CAIRO_STATUS_PATTERN_TYPE_MISMATCH);

    if (point_num > 3)
	return _cairo_error (CAIRO_STATUS_INVALID_INDEX);

    patch_count = _cairo_array_num_elements (&mesh->patches);
    if (mesh->current_patch)
	patch_count--;

    if (unlikely (patch_num >= patch_count))
	return _cairo_error (CAIRO_STATUS_INVALID_INDEX);

    patch = _cairo_array_index_const (&mesh->patches, patch_num);

    i = mesh_control_point_i[point_num];
    j = mesh_control_point_j[point_num];

    if (x)
	*x = patch->points[i][j].x;
    if (y)
	*y = patch->points[i][j].y;

    return CAIRO_STATUS_SUCCESS;
}

