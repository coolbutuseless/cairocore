

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Polygon, Polyline
#'
#' Bespoke
#'
#' @param cr \code{cairo_t *}
#' @param x \code{double}
#' @param y \code{double}
#'
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_polygon <- function(cr, x, y) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_polygon_", cr, x, y))
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' @rdname cairo_polygon
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_polyline <- function(cr, x, y) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_polyline_", cr, x, y))
}
