# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_init
#'
#' Sets matrix to be the affine transformation given by
#' xx, yx, xy, yy, x0, y0. The transformation is given
#' by:
#' <programlisting>
#' x_new = xx * x + xy * y + x0;
#' y_new = yx * x + yy * y + y0;
#' </programlisting>
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_init (cairo_matrix_t *matrix, double xx, double yx, double xy, double yy, double x0, double y0)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param xx [\code{double}] xx component of the affine transformation
#' @param yx [\code{double}] yx component of the affine transformation
#' @param xy [\code{double}] xy component of the affine transformation
#' @param yy [\code{double}] yy component of the affine transformation
#' @param x0 [\code{double}] X translation component of the affine transformation
#' @param y0 [\code{double}] Y translation component of the affine transformation
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_init <- function(matrix, xx, yx, xy, yy, x0, y0) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_init_", matrix, xx, yx, xy, yy, x0, y0)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_init_translate
#'
#' Initializes matrix to a transformation that translates by tx and
#' ty in the X and Y dimensions, respectively.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_init_translate (cairo_matrix_t *matrix, double tx, double ty)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param tx [\code{double}] amount to translate in the X direction
#' @param ty [\code{double}] amount to translate in the Y direction
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_init_translate <- function(matrix, tx, ty) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_init_translate_", matrix, tx, ty)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_translate
#'
#' Applies a translation by tx, ty to the transformation in
#' matrix. The effect of the new transformation is to first translate
#' the coordinates by tx and ty, then apply the original transformation
#' to the coordinates.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_translate (cairo_matrix_t *matrix, double tx, double ty)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param tx [\code{double}] amount to translate in the X direction
#' @param ty [\code{double}] amount to translate in the Y direction
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_translate <- function(matrix, tx, ty) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_translate_", matrix, tx, ty)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_init_scale
#'
#' Initializes matrix to a transformation that scales by sx and sy
#' in the X and Y dimensions, respectively.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_init_scale (cairo_matrix_t *matrix, double sx, double sy)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param sx [\code{double}] scale factor in the X direction
#' @param sy [\code{double}] scale factor in the Y direction
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_init_scale <- function(matrix, sx, sy) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_init_scale_", matrix, sx, sy)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_scale
#'
#' Applies scaling by sx, sy to the transformation in matrix. The
#' effect of the new transformation is to first scale the coordinates
#' by sx and sy, then apply the original transformation to the coordinates.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_scale (cairo_matrix_t *matrix, double sx, double sy)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param sx [\code{double}] scale factor in the X direction
#' @param sy [\code{double}] scale factor in the Y direction
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_scale <- function(matrix, sx, sy) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_scale_", matrix, sx, sy)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_init_rotate
#'
#' Initialized matrix to a transformation that rotates by radians.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_init_rotate (cairo_matrix_t *matrix, double radians)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param radians [\code{double}] angle of rotation, in radians. The direction of rotation is defined such that positive angles rotate in the direction from the positive X axis toward the positive Y axis. With the default axis orientation of cairo, positive angles rotate in a clockwise direction.
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_init_rotate <- function(matrix, radians) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_init_rotate_", matrix, radians)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_rotate
#'
#' Applies rotation by radians to the transformation in
#' matrix. The effect of the new transformation is to first rotate the
#' coordinates by radians, then apply the original transformation
#' to the coordinates.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_rotate (cairo_matrix_t *matrix, double radians)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param radians [\code{double}] angle of rotation, in radians. The direction of rotation is defined such that positive angles rotate in the direction from the positive X axis toward the positive Y axis. With the default axis orientation of cairo, positive angles rotate in a clockwise direction.
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_rotate <- function(matrix, radians) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_rotate_", matrix, radians)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_multiply
#'
#' Multiplies the affine transformations in a and b together
#' and stores the result in result. The effect of the resulting
#' transformation is to first apply the transformation in a to the
#' coordinates and then apply the transformation in b to the
#' coordinates.
#'
#' It is allowable for result to be identical to either a or b.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_multiply (cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b)}
#'
#' @param result [\code{cairo_matrix_t *}] a #cairo_matrix_t in which to store the result
#' @param a [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param b [\code{cairo_matrix_t *}] a #cairo_matrix_t
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_multiply <- function(result, a, b) {
  stopifnot(inherits(result, "cairo_matrix_t"))
  stopifnot(inherits(a, "cairo_matrix_t"))
  stopifnot(inherits(b, "cairo_matrix_t"))
  .Call("cairo_matrix_multiply_", result, a, b)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_transform_distance
#'
#' Transforms the distance vector (dx,dy) by matrix. This is
#' similar to cairo_matrix_transform_point() except that the translation
#' components of the transformation are ignored. The calculation of
#' the returned vector is as follows:
#'
#' <programlisting>
#' dx2 = dx1 * a + dy1 * c;
#' dy2 = dx1 * b + dy1 * d;
#' </programlisting>
#'
#' Affine transformations are position invariant, so the same vector
#' always transforms to the same vector. If (x1,y1) transforms
#' to (x2,y2) then (x1+dx1,y1+dy1) will transform to
#' (x1+dx2,y1+dy2) for all values of x1 and x2.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_transform_distance (const cairo_matrix_t *matrix, double *dx, double *dy)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param dx [\code{double *}] X component of a distance vector. An in/out parameter
#' @param dy [\code{double *}] Y component of a distance vector. An in/out parameter
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_transform_distance <- function(matrix, dx, dy) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_transform_distance_", matrix, dx, dy)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_transform_point
#'
#' Transforms the point (x, y) by matrix.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_matrix_transform_point (const cairo_matrix_t *matrix, double *x, double *y)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#' @param x [\code{double *}] X position. An in/out parameter
#' @param y [\code{double *}] Y position. An in/out parameter
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_transform_point <- function(matrix, x, y) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_transform_point_", matrix, x, y)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_invert
#'
#' Changes matrix to be the inverse of its original value. Not
#' all transformation matrices have inverses; if the matrix
#' collapses points together (it is <firstterm>degenerate</firstterm>),
#' then it has no inverse and this function will fail.
#'
#' Returns: If matrix has an inverse, modifies matrix to
#' be the inverse matrix and returns \%CAIRO_STATUS_SUCCESS. Otherwise,
#' returns \%CAIRO_STATUS_INVALID_MATRIX.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_status_t cairo_matrix_invert (cairo_matrix_t *matrix)}
#'
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#'
#' @return [\code{int}]
#'
#' @family cairo-matrix
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_invert <- function(matrix) {
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_matrix_invert_", matrix)
}
