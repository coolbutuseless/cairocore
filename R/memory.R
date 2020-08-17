


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' C-style reference counting and \code{*_destroy()} functions are not implemented in R
#'
#' All memory and reference counting functions are currently empty.  The R
#' garbage collector is used to clean-up at the end of object lifetimes
#'
#' @param ... all arguments ignored
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_destroy <- function(...) {
  if (!isTRUE(.env$warned)) {
    message("C-style reference counting and '*_destroy()' functions are not implemented in R")
    .env$warned <- TRUE
  }
  invisible(NULL)
}

#' @rdname cairo_destroy
#' @export
cairo_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_get_reference_count <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_surface_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_surface_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_surface_get_reference_count <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_device_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_device_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_device_get_reference_count <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_pattern_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_pattern_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_pattern_get_reference_count <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_scaled_font_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_scaled_font_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_scaled_font_get_reference_count <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_font_face_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_font_face_reference <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_font_face_get_reference_count <- cairo_destroy



#' @rdname cairo_destroy
#' @export
cairo_rectangle_list_destroy <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_region_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_region_reference <- cairo_destroy


#' @rdname cairo_destroy
#' @export
cairo_font_options_destroy <- cairo_destroy

#' @rdname cairo_destroy
#' @export
cairo_path_destroy <- cairo_destroy
