# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_create
#'
#' Creates a PDF surface of the specified size in points to be written
#' to filename.
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
#' C function prototype: \code{cairo_surface_t * cairo_pdf_surface_create (const char *filename, double width_in_points, double height_in_points)}
#'
#' @param filename [\code{char *}] a filename for the PDF output (must be writable), \%NULL may be used to specify no output. This will generate a PDF surface that may be queried and used as a source, without generating a temporary file.
#' @param width_in_points [\code{double}] width of the surface, in points (1 point == 1/72.0 inch)
#' @param height_in_points [\code{double}] height of the surface, in points (1 point == 1/72.0 inch)
#'
#' @return [\code{cairo_surface_t *}]
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_create <- function(filename, width_in_points, height_in_points) {
  .Call("cairo_pdf_surface_create_", filename, width_in_points, height_in_points)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_restrict_to_version
#'
#' Restricts the generated PDF file to version. See cairo_pdf_get_versions()
#' for a list of available version values that can be used here.
#'
#' This function should only be called before any drawing operations
#' have been performed on the given surface. The simplest way to do
#' this is to call this function immediately after creating the
#' surface.
#'
#' Since: 1.10
#'
#' C function prototype: \code{void cairo_pdf_surface_restrict_to_version (cairo_surface_t *surface, cairo_pdf_version_t version)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param version [\code{int}] PDF version
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_restrict_to_version <- function(surface, version) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_restrict_to_version_", surface, version)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_version_to_string
#'
#' Get the string representation of the given version id. This function
#' will return \%NULL if version isn't valid. See cairo_pdf_get_versions()
#' for a way to get the list of valid version ids.
#'
#' Return value: the string associated to given version.
#'
#' Since: 1.10
#'
#' C function prototype: \code{const char * cairo_pdf_version_to_string (cairo_pdf_version_t version)}
#'
#' @param version [\code{int}] a version id
#'
#' @return [\code{const char *}]
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_version_to_string <- function(version) {
  .Call("cairo_pdf_version_to_string_", version)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_set_size
#'
#' Changes the size of a PDF surface for the current (and
#' subsequent) pages.
#'
#' This function should only be called before any drawing operations
#' have been performed on the current page. The simplest way to do
#' this is to call this function immediately after creating the
#' surface or immediately after completing a page with either
#' cairo_show_page() or cairo_copy_page().
#'
#' Since: 1.2
#'
#' C function prototype: \code{void cairo_pdf_surface_set_size (cairo_surface_t *surface, double width_in_points, double height_in_points)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param width_in_points [\code{double}] new surface width, in points (1 point == 1/72.0 inch)
#' @param height_in_points [\code{double}] new surface height, in points (1 point == 1/72.0 inch)
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_set_size <- function(surface, width_in_points, height_in_points) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_set_size_", surface, width_in_points, height_in_points)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_add_outline
#'
#' Add an item to the document outline hierarchy with the name utf8
#' that links to the location specified by link_attribs. Link
#' attributes have the same keys and values as the [Link Tag][link],
#' excluding the "rect" attribute. The item will be a child of the
#' item with id parent_id. Use \%CAIRO_PDF_OUTLINE_ROOT as the parent
#' id of top level items.
#'
#' Return value: the id for the added item.
#'
#' Since: 1.16
#'
#' C function prototype: \code{int cairo_pdf_surface_add_outline (cairo_surface_t *surface, int parent_id, const char *utf8, const char *link_attribs, cairo_pdf_outline_flags_t flags)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param parent_id [\code{int}] the id of the parent item or \%CAIRO_PDF_OUTLINE_ROOT if this is a top level item.
#' @param utf8 [\code{char *}] the name of the outline
#' @param link_attribs [\code{char *}] the link attributes specifying where this outline links to
#' @param flags [\code{int}] outline item flags
#'
#' @return [\code{int}]
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_add_outline <- function(surface, parent_id, utf8, link_attribs, flags) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_add_outline_", surface, parent_id, utf8, link_attribs, flags)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_set_metadata
#'
#' Set document metadata. The \%CAIRO_PDF_METADATA_CREATE_DATE and
#' \%CAIRO_PDF_METADATA_MOD_DATE values must be in ISO-8601 format:
#' YYYY-MM-DDThh:mm:ss. An optional timezone of the form "[+/-]hh:mm"
#' or "Z" for UTC time can be appended. All other metadata values can be any UTF-8
#' string.
#'
#' For example:
#' <informalexample><programlisting>
#' cairo_pdf_surface_set_metadata (surface, CAIRO_PDF_METADATA_TITLE, "My Document");
#' cairo_pdf_surface_set_metadata (surface, CAIRO_PDF_METADATA_CREATE_DATE, "2015-12-31T23:59+02:00");
#' </programlisting></informalexample>
#'
#' Since: 1.16
#'
#' C function prototype: \code{void cairo_pdf_surface_set_metadata (cairo_surface_t *surface, cairo_pdf_metadata_t metadata, const char *utf8)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param metadata [\code{int}] The metadata item to set.
#' @param utf8 [\code{char *}] metadata value
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_set_metadata <- function(surface, metadata, utf8) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_set_metadata_", surface, metadata, utf8)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_set_page_label
#'
#' Set page label for the current page.
#'
#' Since: 1.16
#'
#' C function prototype: \code{void cairo_pdf_surface_set_page_label (cairo_surface_t *surface, const char *utf8)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param utf8 [\code{char *}] The page label.
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_set_page_label <- function(surface, utf8) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_set_page_label_", surface, utf8)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_surface_set_thumbnail_size
#'
#' Set the thumbnail image size for the current and all subsequent
#' pages. Setting a width or height of 0 disables thumbnails for the
#' current and subsequent pages.
#'
#' Since: 1.16
#'
#' C function prototype: \code{void cairo_pdf_surface_set_thumbnail_size (cairo_surface_t *surface, int width, int height)}
#'
#' @param surface [\code{cairo_surface_t *}] a PDF #cairo_surface_t
#' @param width [\code{int}] Thumbnail width.
#' @param height [\code{int}] Thumbnail height
#'
#' @family cairo-pdf-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_surface_set_thumbnail_size <- function(surface, width, height) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pdf_surface_set_thumbnail_size_", surface, width, height)
  invisible(NULL)
}
