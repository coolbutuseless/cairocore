% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/cairo-matrix.R
\name{cairo_matrix_rotate}
\alias{cairo_matrix_rotate}
\title{cairo_matrix_rotate}
\usage{
cairo_matrix_rotate(matrix, radians)
}
\arguments{
\item{matrix}{[\code{cairo_matrix_t *}] a #cairo_matrix_t}

\item{radians}{[\code{double}] angle of rotation, in radians. The direction of rotation is defined such that positive angles rotate in the direction from the positive X axis toward the positive Y axis. With the default axis orientation of cairo, positive angles rotate in a clockwise direction.}
}
\description{
Applies rotation by radians to the transformation in
matrix. The effect of the new transformation is to first rotate the
coordinates by radians, then apply the original transformation
to the coordinates.
}
\details{
Since: 1.0

C function prototype: \code{void cairo_matrix_rotate (cairo_matrix_t *matrix, double radians)}
}
\seealso{
Other cairo-matrix: 
\code{\link{cairo_matrix_init_rotate}()},
\code{\link{cairo_matrix_init_scale}()},
\code{\link{cairo_matrix_init_translate}()},
\code{\link{cairo_matrix_init}()},
\code{\link{cairo_matrix_invert}()},
\code{\link{cairo_matrix_multiply}()},
\code{\link{cairo_matrix_scale}()},
\code{\link{cairo_matrix_transform_distance}()},
\code{\link{cairo_matrix_transform_point}()},
\code{\link{cairo_matrix_translate}()}
}
\concept{cairo-matrix}
