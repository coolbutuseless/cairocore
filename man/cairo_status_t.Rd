% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/cairo--enum.R
\docType{data}
\name{cairo_status_t}
\alias{cairo_status_t}
\title{cairo_status_t}
\format{
An object of class \code{list} of length 44.
}
\usage{
cairo_status_t
}
\description{
#cairo_status_t is used to indicate errors that can occur when
using Cairo. In some cases it is returned directly by functions.
but when using #cairo_t, the last error, if any, is stored in
the context and can be retrieved with cairo_status().
}
\details{
New entries may be added in future versions.  Use cairo_status_to_string()
to get a human-readable representation of an error message.

Since: 1.0

\describe{
\item{CAIRO_STATUS_SUCCESS}{no error has occurred (Since 1.0)}
\item{CAIRO_STATUS_NO_MEMORY}{out of memory (Since 1.0)}
\item{CAIRO_STATUS_INVALID_RESTORE}{cairo_restore() called without matching cairo_save() (Since 1.0)}
\item{CAIRO_STATUS_INVALID_POP_GROUP}{no saved group to pop, i.e. cairo_pop_group() without matching cairo_push_group() (Since 1.0)}
\item{CAIRO_STATUS_NO_CURRENT_POINT}{no current point defined (Since 1.0)}
\item{CAIRO_STATUS_INVALID_MATRIX}{invalid matrix (not invertible) (Since 1.0)}
\item{CAIRO_STATUS_INVALID_STATUS}{invalid value for an input #cairo_status_t (Since 1.0)}
\item{CAIRO_STATUS_NULL_POINTER}{\%NULL pointer (Since 1.0)}
\item{CAIRO_STATUS_INVALID_STRING}{input string not valid UTF-8 (Since 1.0)}
\item{CAIRO_STATUS_INVALID_PATH_DATA}{input path data not valid (Since 1.0)}
\item{CAIRO_STATUS_READ_ERROR}{error while reading from input stream (Since 1.0)}
\item{CAIRO_STATUS_WRITE_ERROR}{error while writing to output stream (Since 1.0)}
\item{CAIRO_STATUS_SURFACE_FINISHED}{target surface has been finished (Since 1.0)}
\item{CAIRO_STATUS_SURFACE_TYPE_MISMATCH}{the surface type is not appropriate for the operation (Since 1.0)}
\item{CAIRO_STATUS_PATTERN_TYPE_MISMATCH}{the pattern type is not appropriate for the operation (Since 1.0)}
\item{CAIRO_STATUS_INVALID_CONTENT}{invalid value for an input #cairo_content_t (Since 1.0)}
\item{CAIRO_STATUS_INVALID_FORMAT}{invalid value for an input #cairo_format_t (Since 1.0)}
\item{CAIRO_STATUS_INVALID_VISUAL}{invalid value for an input Visual* (Since 1.0)}
\item{CAIRO_STATUS_FILE_NOT_FOUND}{file not found (Since 1.0)}
\item{CAIRO_STATUS_INVALID_DASH}{invalid value for a dash setting (Since 1.0)}
\item{CAIRO_STATUS_INVALID_DSC_COMMENT}{invalid value for a DSC comment (Since 1.2)}
\item{CAIRO_STATUS_INVALID_INDEX}{invalid index passed to getter (Since 1.4)}
\item{CAIRO_STATUS_CLIP_NOT_REPRESENTABLE}{clip region not representable in desired format (Since 1.4)}
\item{CAIRO_STATUS_TEMP_FILE_ERROR}{error creating or writing to a temporary file (Since 1.6)}
\item{CAIRO_STATUS_INVALID_STRIDE}{invalid value for stride (Since 1.6)}
\item{CAIRO_STATUS_FONT_TYPE_MISMATCH}{the font type is not appropriate for the operation (Since 1.8)}
\item{CAIRO_STATUS_USER_FONT_IMMUTABLE}{the user-font is immutable (Since 1.8)}
\item{CAIRO_STATUS_USER_FONT_ERROR}{error occurred in a user-font callback function (Since 1.8)}
\item{CAIRO_STATUS_NEGATIVE_COUNT}{negative number used where it is not allowed (Since 1.8)}
\item{CAIRO_STATUS_INVALID_CLUSTERS}{input clusters do not represent the accompanying text and glyph array (Since 1.8)}
\item{CAIRO_STATUS_INVALID_SLANT}{invalid value for an input #cairo_font_slant_t (Since 1.8)}
\item{CAIRO_STATUS_INVALID_WEIGHT}{invalid value for an input #cairo_font_weight_t (Since 1.8)}
\item{CAIRO_STATUS_INVALID_SIZE}{invalid value (typically too big) for the size of the input (surface, pattern, etc.) (Since 1.10)}
\item{CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED}{user-font method not implemented (Since 1.10)}
\item{CAIRO_STATUS_DEVICE_TYPE_MISMATCH}{the device type is not appropriate for the operation (Since 1.10)}
\item{CAIRO_STATUS_DEVICE_ERROR}{an operation to the device caused an unspecified error (Since 1.10)}
\item{CAIRO_STATUS_INVALID_MESH_CONSTRUCTION}{a mesh pattern construction operation was used outside of a cairo_mesh_pattern_begin_patch()/cairo_mesh_pattern_end_patch() pair (Since 1.12)}
\item{CAIRO_STATUS_DEVICE_FINISHED}{target device has been finished (Since 1.12)}
\item{CAIRO_STATUS_JBIG2_GLOBAL_MISSING}{\%CAIRO_MIME_TYPE_JBIG2_GLOBAL_ID has been used on at least one image but no image provided \%CAIRO_MIME_TYPE_JBIG2_GLOBAL (Since 1.14)}
\item{CAIRO_STATUS_PNG_ERROR}{error occurred in libpng while reading from or writing to a PNG file (Since 1.16)}
\item{CAIRO_STATUS_FREETYPE_ERROR}{error occurred in libfreetype (Since 1.16)}
\item{CAIRO_STATUS_WIN32_GDI_ERROR}{error occurred in the Windows Graphics Device Interface (Since 1.16)}
\item{CAIRO_STATUS_TAG_ERROR}{invalid tag name, attributes, or nesting (Since 1.16)}
\item{CAIRO_STATUS_LAST_STATUS}{this is a special value indicating the number of status values defined in this enumeration. When using this value, note that the version of cairo at run-time may have additional status values defined than the value of this symbol at compile-time. (Since 1.10)}
}
}
\seealso{
Other enum: 
\code{\link{cairo_antialias_t}},
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
