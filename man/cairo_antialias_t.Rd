% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/cairo--enum.R
\docType{data}
\name{cairo_antialias_t}
\alias{cairo_antialias_t}
\title{cairo_antialias_t}
\format{
An object of class \code{list} of length 7.
}
\usage{
cairo_antialias_t
}
\description{
Specifies the type of antialiasing to do when rendering text or shapes.
}
\details{
As it is not necessarily clear from the above what advantages a particular
antialias method provides, since 1.12, there is also a set of hints:
CAIRO_ANTIALIAS_FAST: Allow the backend to degrade raster quality for speed
CAIRO_ANTIALIAS_GOOD: A balance between speed and quality
CAIRO_ANTIALIAS_BEST: A high-fidelity, but potentially slow, raster mode

These make no guarantee on how the backend will perform its rasterisation
(if it even rasterises!), nor that they have any differing effect other
than to enable some form of antialiasing. In the case of glyph rendering,
CAIRO_ANTIALIAS_FAST and CAIRO_ANTIALIAS_GOOD will be mapped to
CAIRO_ANTIALIAS_GRAY, with CAIRO_ANTALIAS_BEST being equivalent to
CAIRO_ANTIALIAS_SUBPIXEL.

The interpretation of CAIRO_ANTIALIAS_DEFAULT is left entirely up to
the backend, typically this will be similar to CAIRO_ANTIALIAS_GOOD.

Since: 1.0

\describe{
\item{CAIRO_ANTIALIAS_DEFAULT}{Use the default antialiasing for the subsystem and target device, since 1.0}
\item{CAIRO_ANTIALIAS_NONE}{Use a bilevel alpha mask, since 1.0}
\item{CAIRO_ANTIALIAS_GRAY}{Perform single-color antialiasing (using shades of gray for black text on a white background, for example), since 1.0}
\item{CAIRO_ANTIALIAS_SUBPIXEL}{Perform antialiasing by taking advantage of the order of subpixel elements on devices such as LCD panels, since 1.0}
\item{CAIRO_ANTIALIAS_FAST}{Hint that the backend should perform some antialiasing but prefer speed over quality, since 1.12}
\item{CAIRO_ANTIALIAS_GOOD}{The backend should balance quality against performance, since 1.12}
\item{CAIRO_ANTIALIAS_BEST}{Hint that the backend should render at the highest quality, sacrificing speed if necessary, since 1.12}
}
}
\seealso{
Other enum: 
\code{\link{cairo_content_t}},
\code{\link{cairo_device_type_t}},
\code{\link{cairo_extend_t}},
\code{\link{cairo_fill_rule_t}},
\code{\link{cairo_filter_t}},
\code{\link{cairo_font_slant_t}},
\code{\link{cairo_font_type_t}},
\code{\link{cairo_font_weight_t}},
\code{\link{cairo_format_t}},
\code{\link{cairo_ft_synthesize_t}},
\code{\link{cairo_hint_metrics_t}},
\code{\link{cairo_hint_style_t}},
\code{\link{cairo_int_status_t}},
\code{\link{cairo_line_cap_t}},
\code{\link{cairo_line_join_t}},
\code{\link{cairo_operator_t}},
\code{\link{cairo_path_data_type_t}},
\code{\link{cairo_pattern_type_t}},
\code{\link{cairo_pdf_metadata_t}},
\code{\link{cairo_pdf_outline_flags_t}},
\code{\link{cairo_pdf_version_t}},
\code{\link{cairo_ps_level_t}},
\code{\link{cairo_region_overlap_t}},
\code{\link{cairo_status_t}},
\code{\link{cairo_subpixel_order_t}},
\code{\link{cairo_surface_observer_mode_t}},
\code{\link{cairo_surface_type_t}},
\code{\link{cairo_svg_unit_t}},
\code{\link{cairo_svg_version_t}},
\code{\link{cairo_text_cluster_flags_t}},
\code{\link{enum_find}()},
\code{\link{enum_lookup}()}
}
\concept{enum}
\keyword{datasets}
