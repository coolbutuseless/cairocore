
/**
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
 **/
void
cairo_matrix_init (cairo_matrix_t *matrix,
		   double xx, double yx,

		   double xy, double yy,
		   double x0, double y0)
{
    matrix->xx = xx; matrix->yx = yx;
    matrix->xy = xy; matrix->yy = yy;
    matrix->x0 = x0; matrix->y0 = y0;
}



/**
 * cairo_matrix_init_translate:
 * @matrix: a #cairo_matrix_t
 * @tx: amount to translate in the X direction
 * @ty: amount to translate in the Y direction
 *
 * Initializes @matrix to a transformation that translates by @tx and
 * @ty in the X and Y dimensions, respectively.
 *
 * Since: 1.0
 **/
void
cairo_matrix_init_translate (cairo_matrix_t *matrix,
			     double tx, double ty)
{
    cairo_matrix_init (matrix,
		       1, 0,
		       0, 1,
		       tx, ty);
}


/**
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
 **/
void
cairo_matrix_translate (cairo_matrix_t *matrix, double tx, double ty)
{
    cairo_matrix_t tmp;

    cairo_matrix_init_translate (&tmp, tx, ty);

    cairo_matrix_multiply (matrix, &tmp, matrix);
}


/**
 * cairo_matrix_init_scale:
 * @matrix: a #cairo_matrix_t
 * @sx: scale factor in the X direction
 * @sy: scale factor in the Y direction
 *
 * Initializes @matrix to a transformation that scales by @sx and @sy
 * in the X and Y dimensions, respectively.
 *
 * Since: 1.0
 **/
void
cairo_matrix_init_scale (cairo_matrix_t *matrix,
			 double sx, double sy)
{
    cairo_matrix_init (matrix,
		       sx,  0,
		       0, sy,
		       0, 0);
}


/**
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
 **/
void
cairo_matrix_scale (cairo_matrix_t *matrix, double sx, double sy)
{
    cairo_matrix_t tmp;

    cairo_matrix_init_scale (&tmp, sx, sy);

    cairo_matrix_multiply (matrix, &tmp, matrix);
}


/**
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
 **/
void
cairo_matrix_init_rotate (cairo_matrix_t *matrix,
			  double radians)
{
    double  s;
    double  c;

    s = sin (radians);
    c = cos (radians);

    cairo_matrix_init (matrix,
		       c, s,
		       -s, c,
		       0, 0);
}


/**
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
 **/
void
cairo_matrix_rotate (cairo_matrix_t *matrix, double radians)
{
    cairo_matrix_t tmp;

    cairo_matrix_init_rotate (&tmp, radians);

    cairo_matrix_multiply (matrix, &tmp, matrix);
}

/**
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
 **/
/*
 * XXX: The ordering of the arguments to this function corresponds
 *      to [row_vector]*A*B. If we want to use column vectors instead,
 *      then we need to switch the two arguments and fix up all
 *      uses.
 */
void
cairo_matrix_multiply (cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b)
{
    cairo_matrix_t r;

    r.xx = a->xx * b->xx + a->yx * b->xy;
    r.yx = a->xx * b->yx + a->yx * b->yy;

    r.xy = a->xy * b->xx + a->yy * b->xy;
    r.yy = a->xy * b->yx + a->yy * b->yy;

    r.x0 = a->x0 * b->xx + a->y0 * b->xy + b->x0;
    r.y0 = a->x0 * b->yx + a->y0 * b->yy + b->y0;

    *result = r;
}


void
_cairo_matrix_multiply (cairo_matrix_t *r,
			const cairo_matrix_t *a,
			const cairo_matrix_t *b)
{
    r->xx = a->xx * b->xx + a->yx * b->xy;
    r->yx = a->xx * b->yx + a->yx * b->yy;

    r->xy = a->xy * b->xx + a->yy * b->xy;
    r->yy = a->xy * b->yx + a->yy * b->yy;

    r->x0 = a->x0 * b->xx + a->y0 * b->xy + b->x0;
    r->y0 = a->x0 * b->yx + a->y0 * b->yy + b->y0;
}

/**
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
 **/
void
cairo_matrix_transform_distance (const cairo_matrix_t *matrix, double *dx, double *dy)
{
    double new_x, new_y;

    new_x = (matrix->xx * *dx + matrix->xy * *dy);
    new_y = (matrix->yx * *dx + matrix->yy * *dy);

    *dx = new_x;
    *dy = new_y;
}


/**
 * cairo_matrix_transform_point:
 * @matrix: a #cairo_matrix_t
 * @x: X position. An in/out parameter
 * @y: Y position. An in/out parameter
 *
 * Transforms the point (@x, @y) by @matrix.
 *
 * Since: 1.0
 **/
void
cairo_matrix_transform_point (const cairo_matrix_t *matrix, double *x, double *y)
{
    cairo_matrix_transform_distance (matrix, x, y);

    *x += matrix->x0;
    *y += matrix->y0;
}



/**
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
 **/
cairo_status_t
cairo_matrix_invert (cairo_matrix_t *matrix)
{
    double det;

    /* Simple scaling|translation matrices are quite common... */
    if (matrix->xy == 0. && matrix->yx == 0.) {
	matrix->x0 = -matrix->x0;
	matrix->y0 = -matrix->y0;

	if (matrix->xx != 1.) {
	    if (matrix->xx == 0.)
		return _cairo_error (CAIRO_STATUS_INVALID_MATRIX);

	    matrix->xx = 1. / matrix->xx;
	    matrix->x0 *= matrix->xx;
	}

	if (matrix->yy != 1.) {
	    if (matrix->yy == 0.)
		return _cairo_error (CAIRO_STATUS_INVALID_MATRIX);

	    matrix->yy = 1. / matrix->yy;
	    matrix->y0 *= matrix->yy;
	}

	return CAIRO_STATUS_SUCCESS;
    }

    /* inv (A) = 1/det (A) * adj (A) */
    det = _cairo_matrix_compute_determinant (matrix);

    if (! ISFINITE (det))
	return _cairo_error (CAIRO_STATUS_INVALID_MATRIX);

    if (det == 0)
	return _cairo_error (CAIRO_STATUS_INVALID_MATRIX);

    _cairo_matrix_compute_adjoint (matrix);
    _cairo_matrix_scalar_multiply (matrix, 1 / det);

    return CAIRO_STATUS_SUCCESS;
}


