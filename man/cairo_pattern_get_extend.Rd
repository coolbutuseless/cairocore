% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/cairo-pattern.R
\name{cairo_pattern_get_extend}
\alias{cairo_pattern_get_extend}
\title{cairo_pattern_get_extend}
\usage{
cairo_pattern_get_extend(pattern)
}
\arguments{
\item{pattern}{[\code{cairo_pattern_t *}] a #cairo_pattern_t}
}
\value{
[\code{int}]
}
\description{
Gets the current extend mode for a pattern.  See #cairo_extend_t
for details on the semantics of each extend strategy.
}
\details{
Return value: the current extend strategy used for drawing the
pattern.

Since: 1.0

C function prototype: \code{cairo_extend_t cairo_pattern_get_extend (cairo_pattern_t *pattern)}
}
\seealso{
Other cairo-pattern: 
\code{\link{cairo_mesh_pattern_begin_patch}()},
\code{\link{cairo_mesh_pattern_curve_to}()},
\code{\link{cairo_mesh_pattern_end_patch}()},
\code{\link{cairo_mesh_pattern_get_control_point}()},
\code{\link{cairo_mesh_pattern_get_corner_color_rgba}()},
\code{\link{cairo_mesh_pattern_get_patch_count}()},
\code{\link{cairo_mesh_pattern_get_path}()},
\code{\link{cairo_mesh_pattern_line_to}()},
\code{\link{cairo_mesh_pattern_move_to}()},
\code{\link{cairo_mesh_pattern_set_control_point}()},
\code{\link{cairo_mesh_pattern_set_corner_color_rgba}()},
\code{\link{cairo_mesh_pattern_set_corner_color_rgb}()},
\code{\link{cairo_pattern_add_color_stop_rgba}()},
\code{\link{cairo_pattern_add_color_stop_rgb}()},
\code{\link{cairo_pattern_create_for_surface}()},
\code{\link{cairo_pattern_create_linear}()},
\code{\link{cairo_pattern_create_mesh}()},
\code{\link{cairo_pattern_create_radial}()},
\code{\link{cairo_pattern_create_rgba}()},
\code{\link{cairo_pattern_create_rgb}()},
\code{\link{cairo_pattern_get_color_stop_count}()},
\code{\link{cairo_pattern_get_color_stop_rgba}()},
\code{\link{cairo_pattern_get_filter}()},
\code{\link{cairo_pattern_get_linear_points}()},
\code{\link{cairo_pattern_get_matrix}()},
\code{\link{cairo_pattern_get_radial_circles}()},
\code{\link{cairo_pattern_get_rgba}()},
\code{\link{cairo_pattern_get_type}()},
\code{\link{cairo_pattern_set_extend}()},
\code{\link{cairo_pattern_set_filter}()},
\code{\link{cairo_pattern_set_matrix}()},
\code{\link{cairo_pattern_status}()}
}
\concept{cairo-pattern}
