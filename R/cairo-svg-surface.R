# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_surface_create
#'
#' Creates a SVG surface of the specified size in points to be written
#' to filename.
#'
#' The SVG surface backend recognizes the following MIME types for the
#' data attached to a surface (see cairo_surface_set_mime_data()) when
#' it is used as a source pattern for drawing on this surface:
#' \%CAIRO_MIME_TYPE_JPEG, \%CAIRO_MIME_TYPE_PNG,
#' \%CAIRO_MIME_TYPE_URI. If any of them is specified, the SVG backend
#' emits a href with the content of MIME data instead of a surface
#' snapshot (PNG, Base64-encoded) in the corresponding image tag.
#'
#' The unofficial MIME type \%CAIRO_MIME_TYPE_URI is examined
#' first. If present, the URI is emitted as is: assuring the
#' correctness of URI is left to the client code.
#'
#' If \%CAIRO_MIME_TYPE_URI is not present, but \%CAIRO_MIME_TYPE_JPEG
#' or \%CAIRO_MIME_TYPE_PNG is specified, the corresponding data is
#' Base64-encoded and emitted.
#'
#' If \%CAIRO_MIME_TYPE_UNIQUE_ID is present, all surfaces with the same
#' unique identifier will only be embedded once.
#'
#' Return value: a pointer to the newly created surface. The caller
#' owns the surface and should call cairo_surface_destroy() when done
#' with it.
#'
#' This function always returns a valid pointer, but it will return a
#' pointer to a "nil" surface if an error such as out of memory
#' occurs. You can use cairo_surface_status() to check for this.
#'
#' Since: 1.2
#'
#' C function prototype: \code{cairo_surface_t * cairo_svg_surface_create (const char *filename, double width, double height)}
#'
#' @param filename [\code{char *}] a filename for the SVG output (must be writable), \%NULL may be used to specify no output. This will generate a SVG surface that may be queried and used as a source, without generating a temporary file.
#' @param width [\code{double}] width of the surface, in points (1 point == 1/72.0 inch)
#' @param height [\code{double}] height of the surface, in points (1 point == 1/72.0 inch)
#'
#' @return [\code{cairo_surface_t *}]
#'
#' @family cairo-svg-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_surface_create <- function(filename, width, height) {
  .Call("cairo_svg_surface_create_", filename, width, height)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_surface_restrict_to_version
#'
#' Restricts the generated SVG file to version. See cairo_svg_get_versions()
#' for a list of available version values that can be used here.
#'
#' This function should only be called before any drawing operations
#' have been performed on the given surface. The simplest way to do
#' this is to call this function immediately after creating the
#' surface.
#'
#' Since: 1.2
#'
#' C function prototype: \code{void cairo_svg_surface_restrict_to_version (cairo_surface_t *surface, cairo_svg_version_t version)}
#'
#' @param surface [\code{cairo_surface_t *}] a SVG #cairo_surface_t
#' @param version [\code{int}] SVG version
#'
#' @family cairo-svg-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_surface_restrict_to_version <- function(surface, version) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_svg_surface_restrict_to_version_", surface, version)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_version_to_string
#'
#' Get the string representation of the given version id. This function
#' will return \%NULL if version isn't valid. See cairo_svg_get_versions()
#' for a way to get the list of valid version ids.
#'
#' Return value: the string associated to given version.
#'
#' Since: 1.2
#'
#' C function prototype: \code{const char * cairo_svg_version_to_string (cairo_svg_version_t version)}
#'
#' @param version [\code{int}] a version id
#'
#' @return [\code{const char *}]
#'
#' @family cairo-svg-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_version_to_string <- function(version) {
  .Call("cairo_svg_version_to_string_", version)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_surface_set_document_unit
#'
#' Use the specified unit for the width and height of the generated SVG file.
#' See #cairo_svg_unit_t for a list of available unit values that can be used
#' here.
#'
#' This function can be called at any time before generating the SVG file.
#'
#' However to minimize the risk of ambiguities it's recommended to call it
#' before any drawing operations have been performed on the given surface, to
#' make it clearer what the unit used in the drawing operations is.
#'
#' The simplest way to do this is to call this function immediately after
#' creating the SVG surface.
#'
#' Note if this function is never called, the default unit for SVG documents
#' generated by cairo will be "pt". This is for historical reasons.
#'
#' Since: 1.16
#'
#' C function prototype: \code{void cairo_svg_surface_set_document_unit (cairo_surface_t *surface, cairo_svg_unit_t unit)}
#'
#' @param surface [\code{cairo_surface_t *}] a SVG #cairo_surface_t
#' @param unit [\code{int}] SVG unit
#'
#' @family cairo-svg-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_surface_set_document_unit <- function(surface, unit) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_svg_surface_set_document_unit_", surface, unit)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_surface_get_document_unit
#'
#' Get the unit of the SVG surface.
#'
#' If the surface passed as an argument is not a SVG surface, the function
#' sets the error status to CAIRO_STATUS_SURFACE_TYPE_MISMATCH and returns
#' CAIRO_SVG_UNIT_USER.
#'
#' Return value: the SVG unit of the SVG surface.
#'
#' Since: 1.16
#'
#' C function prototype: \code{cairo_svg_unit_t cairo_svg_surface_get_document_unit (cairo_surface_t *surface)}
#'
#' @param surface [\code{cairo_surface_t *}] a SVG #cairo_surface_t
#'
#' @return [\code{int}]
#'
#' @family cairo-svg-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_surface_get_document_unit <- function(surface) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_svg_surface_get_document_unit_", surface)
}
