

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Draw lots of arcs (circles)
#'
#' This is a custom function to draw lots of circles within C with a single
#' call from R.  Use this function when you want to draw lots of circles and
#' need to speed up the creation of the final image.
#'
#' Besides the \code{cr} context, all arguments should either be the same length
#' as the initial argument (\code{xc}) or have a length of 1.
#'
#' Vectors which have a length of 1 will be considered to have a constant value
#' for all objects
#'
#' @param cr \code{cairo_t *}
#' @param xc \code{double}
#' @param yc \code{double}
#' @param radius \code{double}
#' @param angle1 \code{double}
#' @param angle2 \code{double}
#' @param r,g,b,a fill colour values in range [0,1]. Set \code{a = 0} to
#'        disable filling
#' @param sr,sg,sb,sa stroke colour values in range [0,1]. Set \code{sa = 0} to
#'        disable drawing the stroke
#'
#' @examples
#' \dontrun{
#' # Draw 10 circles of the same radius, with red fill and no outline
#' N <- 10
#' xc <- runif(N)
#' yc <- runif(N)
#' radius <- 3
#' cairo_arc_vec(cr, xc, yc, radius, 0, 2*pi,   1, 0, 0, 1,   0, 0, 0, 0)
#' }
#'
#'
#' @export
#' @family bespoke
#' @family vectorised
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_arc_vec <- function(cr, xc, yc, radius, angle1, angle2, r, g, b, a, sr, sg, sb, sa) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_arc_vec_", cr, xc, yc, radius, angle1, angle2, r, g, b, a, sr, sg, sb, sa))
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Draw lots of rectangles
#'
#' This is a custom function to draw lots of rectangles within C with a single
#' call from R.  Use this function when you want to draw lots of rectangles and
#' need to speed up the creation of the final image.
#'
#' Besides the \code{cr} context, all arguments should either be the same length
#' as the initial argument (\code{xc}) or have a length of 1.
#'
#' Vectors which have a length of 1 will be considered to have a constant value
#' for all objects
#'
#' @param cr \code{cairo_t *}
#' @param x \code{double}
#' @param y \code{double}
#' @param width \code{double}
#' @param height \code{double}
#' @param r,g,b,a fill colour values in range [0,1]. Set \code{a = 0} to
#'        disable filling
#' @param sr,sg,sb,sa stroke colour values in range [0,1]. Set \code{sa = 0} to
#'        disable drawing the stroke
#'
#' @examples
#' \dontrun{
#' # Draw 10 rectangles of the same size, with red fill and no outline
#' N <- 10
#' x <- runif(N)
#' y <- runif(N)
#' width <- 20
#' height <- 10
#' cairo_rectangle_vec(cr, x, y, width, height,   1, 0, 0, 1,   0, 0, 0, 0)
#' }
#'
#'
#' @export
#' @family bespoke
#' @family vectorised
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_rectangle_vec <- function(cr, x, y, width, height, r, g, b, a, sr, sg, sb, sa) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_rectangle_vec_", cr, x, y, width, height, r, g, b, a, sr, sg, sb, sa))
}

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Draw lots of line segments
#'
#' This is a custom function to draw lots of line segments within C with a single
#' call from R.  Use this function when you want to draw lots of segments and
#' need to speed up the creation of the final image.
#'
#' Besides the \code{cr} context, all arguments should either be the same length
#' as the initial argument (\code{xc}) or have a length of 1.
#'
#' Vectors which have a length of 1 will be considered to have a constant value
#' for all objects
#'
#' @param cr \code{cairo_t *}
#' @param x1,y1,x2,y2 coordinates of endpoints
#' @param r,g,b,a colour values in range [0,1]
#'
#' @examples
#' \dontrun{
#' # Draw 10 lines - all black
#' N <- 10
#' x1 <- runif(N)
#' y1 <- runif(N)
#' x2 <- runif(N)
#' y2 <- runif(N)
#' cairo_segment_vec(cr, x1, y2, x2, y2,  0, 0, 0, 1)
#' }
#'
#'
#' @export
#' @family bespoke
#' @family vectorised
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_segment_vec <- function(cr, x1, y1, x2, y2, r, g, b, a) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_segment_vec_", cr, x1, y1, x2, y2, r, g, b, a))
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Draw lots of polygons
#'
#' This is a custom function to draw lots of polygons within C with a single
#' call from R.  Use this function when you want to draw lots of polygon and
#' need to speed up the creation of the final image.
#'
#' The x and y arguments must be the same length.
#'
#' The colour arguments (r, g, b, a, etc) must all be the same length as the
#' number of distinct runs of values in \code{idx}, or length of 1
#'
#'
#'
#' @param cr \code{cairo_t *}
#' @param x \code{double}
#' @param y \code{double}
#' @param idx \code{integer} runs of the same value define the locations in the
#'        x and y vectors which refer to the same polygon.
#' @param r,g,b,a fill colour values in range [0,1]. Set \code{a = 0} to
#'        disable filling.
#' @param sr,sg,sb,sa stroke colour values in range [0,1]. Set \code{sa = 0} to
#'        disable drawing the stroke
#'
#' @examples
#' \dontrun{
#' # define 2 polygons
#' df <- tibble::tribble(
#' ~x, ~y, ~idx,
#'  0,  0,    1,
#'  1,  0,    1,
#'  1,  1,    1,
#'  0,  1,    1,
#' 10,  0,   55,
#' 11,  0,   55,
#' 11,  1,   55,
#' 10,  1,   55
#' )
#'
#' # Draw 2 polygons with red fill and blue border
#' cairo_polygon_vec(cr, df$x, df$y, df$idx,  1, 0, 0, 1,   0, 0, 1, 1)
#'
#' }
#'
#'
#' @export
#' @family bespoke
#' @family vectorised
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_polygon_vec <- function(cr, x, y, idx, r, g, b, a, sr, sg, sb, sa) {
  stopifnot(inherits(cr, "cairo_t"))
  invisible(.Call("cairo_polygon_vec_", cr, x, y, idx, r, g, b, a, sr, sg, sb, sa))
}






