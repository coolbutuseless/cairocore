# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_surface_write_to_png
#'
#' Writes the contents of surface to a new file filename as a PNG
#' image.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS if the PNG file was written
#' successfully. Otherwise, \%CAIRO_STATUS_NO_MEMORY if memory could not
#' be allocated for the operation or
#' \%CAIRO_STATUS_SURFACE_TYPE_MISMATCH if the surface does not have
#' pixel contents, or \%CAIRO_STATUS_WRITE_ERROR if an I/O error occurs
#' while attempting to write the file, or \%CAIRO_STATUS_PNG_ERROR if libpng
#' returned an error.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_status_t cairo_surface_write_to_png (cairo_surface_t *surface, const char *filename)}
#'
#' @param surface [\code{cairo_surface_t *}] a #cairo_surface_t with pixel contents
#' @param filename [\code{char *}] the name of a file to write to; on Windows this filename is encoded in UTF-8.
#'
#' @return [\code{int}]
#'
#' @family cairo-png
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_surface_write_to_png <- function(surface, filename) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_surface_write_to_png_", surface, filename)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_image_surface_create_from_png
#'
#' Creates a new image surface and initializes the contents to the
#' given PNG file.
#'
#' Return value: a new #cairo_surface_t initialized with the contents
#' of the PNG file, or a "nil" surface if any error occurred. A nil
#' surface can be checked for with cairo_surface_status(surface) which
#' may return one of the following values:
#'
#' \%CAIRO_STATUS_NO_MEMORY
#' \%CAIRO_STATUS_FILE_NOT_FOUND
#' \%CAIRO_STATUS_READ_ERROR
#' \%CAIRO_STATUS_PNG_ERROR
#'
#' Alternatively, you can allow errors to propagate through the drawing
#' operations and check the status on the context upon completion
#' using cairo_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_surface_t * cairo_image_surface_create_from_png (const char *filename)}
#'
#' @param filename [\code{char *}] name of PNG file to load. On Windows this filename is encoded in UTF-8.
#'
#' @return [\code{cairo_surface_t *}]
#'
#' @family cairo-png
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_create_from_png <- function(filename) {
  .Call("cairo_image_surface_create_from_png_", filename)
}
