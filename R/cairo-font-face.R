# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_face_get_type
#'
#' This function returns the type of the backend used to create
#' a font face. See #cairo_font_type_t for available types.
#'
#' Return value: The type of font_face.
#'
#' Since: 1.2
#'
#' C function prototype: \code{cairo_font_type_t cairo_font_face_get_type (cairo_font_face_t *font_face)}
#'
#' @param font_face [\code{cairo_font_face_t *}] a font face
#'
#' @return [\code{int}]
#'
#' @family cairo-font-face
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_face_get_type <- function(font_face) {
  stopifnot(inherits(font_face, "cairo_font_face_t"))
  .Call("cairo_font_face_get_type_", font_face)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_face_status
#'
#' Checks whether an error has previously occurred for this
#' font face
#'
#' Return value: \%CAIRO_STATUS_SUCCESS or another error such as
#' \%CAIRO_STATUS_NO_MEMORY.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_status_t cairo_font_face_status (cairo_font_face_t *font_face)}
#'
#' @param font_face [\code{cairo_font_face_t *}] a #cairo_font_face_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-face
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_face_status <- function(font_face) {
  stopifnot(inherits(font_face, "cairo_font_face_t"))
  .Call("cairo_font_face_status_", font_face)
}
