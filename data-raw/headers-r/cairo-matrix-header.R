


cairo_matrix_header <- list(

  cairo_matrix_init = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_init:
    * @matrix: a #cairo_matrix_t
    * @xx: xx component of the affine transformation
    * @yx: yx component of the affine transformation
    * @xy: xy component of the affine transformation
    * @yy: yy component of the affine transformation
    * @x0: X translation component of the affine transformation
    * @y0: Y translation component of the affine transformation
    *
    * Sets @matrix to be the affine transformation given by
    * @xx, @yx, @xy, @yy, @x0, @y0. The transformation is given
    * by:
    * <programlisting>
    *  x_new = xx * x + xy * y + x0;
    *  y_new = yx * x + yy * y + y0;
    * </programlisting>
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_init (cairo_matrix_t *matrix,
		   double xx, double yx,

		   double xy, double yy,
		   double x0, double y0)"
  ),

  cairo_matrix_init_translate = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_init_translate:
    * @matrix: a #cairo_matrix_t
    * @tx: amount to translate in the X direction
    * @ty: amount to translate in the Y direction
    *
    * Initializes @matrix to a transformation that translates by @tx and
    * @ty in the X and Y dimensions, respectively.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_init_translate (cairo_matrix_t *matrix,
			     double tx, double ty)"
  ),

  cairo_matrix_translate = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_translate:
    * @matrix: a #cairo_matrix_t
    * @tx: amount to translate in the X direction
    * @ty: amount to translate in the Y direction
    *
    * Applies a translation by @tx, @ty to the transformation in
    * @matrix. The effect of the new transformation is to first translate
    * the coordinates by @tx and @ty, then apply the original transformation
    * to the coordinates.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_translate (cairo_matrix_t *matrix, double tx, double ty)"
  ),

  cairo_matrix_init_scale = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_init_scale:
    * @matrix: a #cairo_matrix_t
    * @sx: scale factor in the X direction
    * @sy: scale factor in the Y direction
    *
    * Initializes @matrix to a transformation that scales by @sx and @sy
    * in the X and Y dimensions, respectively.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_init_scale (cairo_matrix_t *matrix,
			 double sx, double sy)"
  ),

  cairo_matrix_scale = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_scale:
    * @matrix: a #cairo_matrix_t
    * @sx: scale factor in the X direction
    * @sy: scale factor in the Y direction
    *
    * Applies scaling by @sx, @sy to the transformation in @matrix. The
    * effect of the new transformation is to first scale the coordinates
    * by @sx and @sy, then apply the original transformation to the coordinates.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_scale (cairo_matrix_t *matrix, double sx, double sy)"
  ),

  cairo_matrix_init_rotate = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_init_rotate:
    * @matrix: a #cairo_matrix_t
    * @radians: angle of rotation, in radians. The direction of rotation
    * is defined such that positive angles rotate in the direction from
    * the positive X axis toward the positive Y axis. With the default
    * axis orientation of cairo, positive angles rotate in a clockwise
    * direction.
    *
    * Initialized @matrix to a transformation that rotates by @radians.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_init_rotate (cairo_matrix_t *matrix,
			  double radians)"
  ),

  cairo_matrix_rotate = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_rotate:
    * @matrix: a #cairo_matrix_t
    * @radians: angle of rotation, in radians. The direction of rotation
    * is defined such that positive angles rotate in the direction from
    * the positive X axis toward the positive Y axis. With the default
    * axis orientation of cairo, positive angles rotate in a clockwise
    * direction.
    *
    * Applies rotation by @radians to the transformation in
    * @matrix. The effect of the new transformation is to first rotate the
    * coordinates by @radians, then apply the original transformation
    * to the coordinates.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_rotate (cairo_matrix_t *matrix, double radians)"
  ),

  cairo_matrix_multiply = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_multiply:
    * @result: a #cairo_matrix_t in which to store the result
    * @a: a #cairo_matrix_t
    * @b: a #cairo_matrix_t
    *
    * Multiplies the affine transformations in @a and @b together
    * and stores the result in @result. The effect of the resulting
    * transformation is to first apply the transformation in @a to the
    * coordinates and then apply the transformation in @b to the
    * coordinates.
    *
    * It is allowable for @result to be identical to either @a or @b.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_multiply (cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b)"
  ),

  cairo_matrix_transform_distance = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_transform_distance:
    * @matrix: a #cairo_matrix_t
    * @dx: X component of a distance vector. An in/out parameter
    * @dy: Y component of a distance vector. An in/out parameter
    *
    * Transforms the distance vector (@dx,@dy) by @matrix. This is
    * similar to cairo_matrix_transform_point() except that the translation
    * components of the transformation are ignored. The calculation of
    * the returned vector is as follows:
    *
    * <programlisting>
    * dx2 = dx1 * a + dy1 * c;
    * dy2 = dx1 * b + dy1 * d;
    * </programlisting>
    *
    * Affine transformations are position invariant, so the same vector
    * always transforms to the same vector. If (@x1,@y1) transforms
    * to (@x2,@y2) then (@x1+@dx1,@y1+@dy1) will transform to
    * (@x1+@dx2,@y1+@dy2) for all values of @x1 and @x2.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_transform_distance (const cairo_matrix_t *matrix, double *dx, double *dy)"
  ),

  cairo_matrix_transform_point = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_transform_point:
    * @matrix: a #cairo_matrix_t
    * @x: X position. An in/out parameter
    * @y: Y position. An in/out parameter
    *
    * Transforms the point (@x, @y) by @matrix.
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_matrix_transform_point (const cairo_matrix_t *matrix, double *x, double *y)"
  ),

  cairo_matrix_invert = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_matrix_invert:
    * @matrix: a #cairo_matrix_t
    *
    * Changes @matrix to be the inverse of its original value. Not
    * all transformation matrices have inverses; if the matrix
    * collapses points together (it is <firstterm>degenerate</firstterm>),
    * then it has no inverse and this function will fail.
    *
    * Returns: If @matrix has an inverse, modifies @matrix to
    *  be the inverse matrix and returns %CAIRO_STATUS_SUCCESS. Otherwise,
    *  returns %CAIRO_STATUS_INVALID_MATRIX.
    *
    * Since: 1.0
    **/}",
    proto_text = "cairo_status_t
cairo_matrix_invert (cairo_matrix_t *matrix)"
  )
)


