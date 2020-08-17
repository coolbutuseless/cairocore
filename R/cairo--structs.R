

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Create an cairo_text_extents_t pointer
#'
#' \code{cairo_text_extents_t * cairo_text_extents_t(void)}
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_text_extents_t <- function() {
  .Call("cairo_text_extents_t_")
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_text_extents_t_to_list - unpack cairo_text_extents_t struct
#'
#' @param x \code{cairo_text_extents_t *}
#' @param ... ignored
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
as.list.cairo_text_extents_t <- function(x, ...) {
  inherits(x, "cairo_text_extents_t")
  .Call("cairo_text_extents_t_to_list_", x)
}



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Create an empty cairo_text_extents_t pointer
#'
#' \code{cairo_text_extents_t * cairo_text_extents_t(void)}
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_extents_t <- function() {
  .Call("cairo_font_extents_t_")
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_extents_t_to_list - unpack cairo_font_extents_t struct
#'
#' @param x \code{cairo_font_extents_t *}
#' @param ... ignored
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
as.list.cairo_font_extents_t <- function(x, ...) {
  inherits(x, "cairo_font_extents_t")
  .Call("cairo_font_extents_t_to_list_", x)
}



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_matrix_t
#'
#' A #cairo_matrix_t holds an affine transformation, such as a scale,
#' rotation, shear, or a combination of those. The transformation of
#' a point (x, y) is given by:
#' <programlisting>
#' x_new = xx * x + xy * y + x0;
#' y_new = yx * x + yy * y + y0;
#' </programlisting>
#'
#' Since: 1.0
#'
#' @param xx xx component of the affine transformation
#' @param yx yx component of the affine transformation
#' @param xy xy component of the affine transformation
#' @param yy yy component of the affine transformation
#' @param x0 X translation component of the affine transformation
#' @param y0 Y translation component of the affine transformation
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_t <- function(xx, yx, xy, yy, x0, y0) {
  .Call("cairo_matrix_t_", xx, yx, xy, yy, x0, y0)
}




#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Update the values in a cairo_matrix_t
#'
#' @param mat cairo_matrix_t object to update
#' @inheritParams cairo_matrix_t
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_matrix_t_update <- function(mat, xx=NULL, yx=NULL, xy=NULL, yy=NULL, x0=NULL, y0=NULL) {
  .Call("cairo_matrix_t_update_", mat, xx, yx, xy, yy, x0, y0)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' unpack cairo_matrix_t struct
#'
#' @param x \code{cairo_matrix_t *}
#' @param ... ignored
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
as.list.cairo_matrix_t <- function(x, ...) {
  inherits(x, "cairo_matrix_t")
  .Call("cairo_matrix_t_to_list_", x)
}




#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_rectangle_int_t
#'
#' A data structure for holding a rectangle with integer coordinates.
#'
#' Since: 1.10
#'
#' @param x X coordinate of the left side of the rectangle
#' @param y Y coordinate of the the top side of the rectangle
#' @param width width of the rectangle
#' @param height height of the rectangle
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_rectangle_int_t <- function(x, y, width, height) {
  .Call("cairo_rectangle_int_t_", x, y, width, height)
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_rectangle_t
#'
#' A data structure for holding a rectangle.
#'
#' Since: 1.4
#'
#' @param x X coordinate of the left side of the rectangle
#' @param y Y coordinate of the the top side of the rectangle
#' @param width width of the rectangle
#' @param height height of the rectangle
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_rectangle_t <- function(x, y, width, height) {
  .Call("cairo_rectangle_t_", x, y, width, height)
}




#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' unpack cairo_rectangle_t struct
#'
#' @param x \code{cairo_rectangle_t *}
#' @param ... ignored
#'
#' @export
#' @family struct
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
as.list.cairo_rectangle_t <- function(x, ...) {
  inherits(x, "cairo_rectangle_t")
  .Call("cairo_rectangle_t_to_list_", x)
}

