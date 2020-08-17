# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_create
#'
#' cairo_font_options_create:
#'
#' Allocates a new font options object with all options initialized
#' to default values.
#'
#' Return value: a newly allocated #cairo_font_options_t. Free with
#' cairo_font_options_destroy(). This function always returns a
#' valid pointer; if memory cannot be allocated, then a special
#' error object is returned where all operations on the object do nothing.
#' You can check for this with cairo_font_options_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_font_options_t * cairo_font_options_create (void)}
#'

#'
#' @return [\code{cairo_font_options_t *}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_create <- function() {
  .Call("cairo_font_options_create_")
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_copy
#'
#' Allocates a new font options object copying the option values from
#' original.
#'
#' Return value: a newly allocated #cairo_font_options_t. Free with
#' cairo_font_options_destroy(). This function always returns a
#' valid pointer; if memory cannot be allocated, then a special
#' error object is returned where all operations on the object do nothing.
#' You can check for this with cairo_font_options_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_font_options_t * cairo_font_options_copy (const cairo_font_options_t *original)}
#'
#' @param original [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{cairo_font_options_t *}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_copy <- function(original) {
  stopifnot(inherits(original, "cairo_font_options_t"))
  .Call("cairo_font_options_copy_", original)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_status
#'
#' Checks whether an error has previously occurred for this
#' font options object
#'
#' Return value: \%CAIRO_STATUS_SUCCESS or \%CAIRO_STATUS_NO_MEMORY
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_status_t cairo_font_options_status (cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_status <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_status_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_merge
#'
#' Merges non-default options from other into options, replacing
#' existing values. This operation can be thought of as somewhat
#' similar to compositing other onto options with the operation
#' of \%CAIRO_OPERATOR_OVER.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_font_options_merge (cairo_font_options_t *options, const cairo_font_options_t *other)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param other [\code{cairo_font_options_t *}] another #cairo_font_options_t
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_merge <- function(options, other) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  stopifnot(inherits(other, "cairo_font_options_t"))
  .Call("cairo_font_options_merge_", options, other)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_equal
#'
#' Compares two font options objects for equality.
#'
#' Return value: \%TRUE if all fields of the two font options objects match.
#' Note that this function will return \%FALSE if either object is in
#' error.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_bool_t cairo_font_options_equal (const cairo_font_options_t *options, const cairo_font_options_t *other)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param other [\code{cairo_font_options_t *}] another #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_equal <- function(options, other) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  stopifnot(inherits(other, "cairo_font_options_t"))
  .Call("cairo_font_options_equal_", options, other)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_hash
#'
#' Compute a hash for the font options object; this value will
#' be useful when storing an object containing a #cairo_font_options_t
#' in a hash table.
#'
#' Return value: the hash value for the font options object.
#' The return value can be cast to a 32-bit type if a
#' 32-bit hash value is needed.
#'
#' Since: 1.0
#'
#' C function prototype: \code{unsigned long cairo_font_options_hash (const cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{unsigned long}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_hash <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_hash_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_set_antialias
#'
#' Sets the antialiasing mode for the font options object. This
#' specifies the type of antialiasing to do when rendering text.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_font_options_set_antialias (cairo_font_options_t *options, cairo_antialias_t antialias)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param antialias [\code{int}] the new antialiasing mode
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_set_antialias <- function(options, antialias) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_set_antialias_", options, antialias)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_get_antialias
#'
#' Gets the antialiasing mode for the font options object.
#'
#' Return value: the antialiasing mode
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_antialias_t cairo_font_options_get_antialias (const cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_get_antialias <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_get_antialias_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_set_subpixel_order
#'
#' Sets the subpixel order for the font options object. The subpixel
#' order specifies the order of color elements within each pixel on
#' the display device when rendering with an antialiasing mode of
#' \%CAIRO_ANTIALIAS_SUBPIXEL. See the documentation for
#' #cairo_subpixel_order_t for full details.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_font_options_set_subpixel_order (cairo_font_options_t *options, cairo_subpixel_order_t subpixel_order)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param subpixel_order [\code{int}] the new subpixel order
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_set_subpixel_order <- function(options, subpixel_order) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_set_subpixel_order_", options, subpixel_order)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_get_subpixel_order
#'
#' Gets the subpixel order for the font options object.
#' See the documentation for #cairo_subpixel_order_t for full details.
#'
#' Return value: the subpixel order for the font options object
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_subpixel_order_t cairo_font_options_get_subpixel_order (const cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_get_subpixel_order <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_get_subpixel_order_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_set_hint_style
#'
#' Sets the hint style for font outlines for the font options object.
#' This controls whether to fit font outlines to the pixel grid,
#' and if so, whether to optimize for fidelity or contrast.
#' See the documentation for #cairo_hint_style_t for full details.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_font_options_set_hint_style (cairo_font_options_t *options, cairo_hint_style_t hint_style)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param hint_style [\code{int}] the new hint style
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_set_hint_style <- function(options, hint_style) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_set_hint_style_", options, hint_style)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_get_hint_style
#'
#' Gets the hint style for font outlines for the font options object.
#' See the documentation for #cairo_hint_style_t for full details.
#'
#' Return value: the hint style for the font options object
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_hint_style_t cairo_font_options_get_hint_style (const cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_get_hint_style <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_get_hint_style_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_set_hint_metrics
#'
#' Sets the metrics hinting mode for the font options object. This
#' controls whether metrics are quantized to integer values in
#' device units.
#' See the documentation for #cairo_hint_metrics_t for full details.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_font_options_set_hint_metrics (cairo_font_options_t *options, cairo_hint_metrics_t hint_metrics)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param hint_metrics [\code{int}] the new metrics hinting mode
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_set_hint_metrics <- function(options, hint_metrics) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_set_hint_metrics_", options, hint_metrics)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_get_hint_metrics
#'
#' Gets the metrics hinting mode for the font options object.
#' See the documentation for #cairo_hint_metrics_t for full details.
#'
#' Return value: the metrics hinting mode for the font options object
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_hint_metrics_t cairo_font_options_get_hint_metrics (const cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{int}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_get_hint_metrics <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_get_hint_metrics_", options)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_set_variations
#'
#' Sets the OpenType font variations for the font options object.
#' Font variations are specified as a string with a format that
#' is similar to the CSS font-variation-settings. The string contains
#' a comma-separated list of axis assignments, which each assignment
#' consists of a 4-character axis name and a value, separated by
#' whitespace and optional equals sign.
#'
#' Examples:
#'
#' wght=200,wdth=140.5
#'
#' wght 200 , wdth 140.5
#'
#' Since: 1.16
#'
#' C function prototype: \code{void cairo_font_options_set_variations (cairo_font_options_t *options, const char *variations)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#' @param variations [\code{char *}] the new font variations, or \%NULL
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_set_variations <- function(options, variations) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_set_variations_", options, variations)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_font_options_get_variations
#'
#' Gets the OpenType font variations for the font options object.
#' See cairo_font_options_set_variations() for details about the
#' string format.
#'
#' Return value: the font variations for the font options object. The
#' returned string belongs to the options and must not be modified.
#' It is valid until either the font options object is destroyed or
#' the font variations in this object is modified with
#' cairo_font_options_set_variations().
#'
#' Since: 1.16
#'
#' C function prototype: \code{const char * cairo_font_options_get_variations (cairo_font_options_t *options)}
#'
#' @param options [\code{cairo_font_options_t *}] a #cairo_font_options_t
#'
#' @return [\code{const char *}]
#'
#' @family cairo-font-options
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_font_options_get_variations <- function(options) {
  stopifnot(inherits(options, "cairo_font_options_t"))
  .Call("cairo_font_options_get_variations_", options)
}
