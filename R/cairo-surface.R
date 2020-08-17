# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_surface_finish
#'
#' This function finishes the surface and drops all references to
#' external resources.  For example, for the Xlib backend it means
#' that cairo will no longer access the drawable, which can be freed.
#' After calling cairo_surface_finish() the only valid operations on a
#' surface are checking status, getting and setting user, referencing
#' and destroying, and flushing and finishing it.
#' Further drawing to the surface will not affect the
#' surface but will instead trigger a \%CAIRO_STATUS_SURFACE_FINISHED
#' error.
#'
#' When the last call to cairo_surface_destroy() decreases the
#' reference count to zero, cairo will call cairo_surface_finish() if
#' it hasn't been called already, before freeing the resources
#' associated with the surface.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_surface_finish (cairo_surface_t *surface)}
#'
#' @param surface [\code{cairo_surface_t *}] the #cairo_surface_t to finish
#'
#' @family cairo-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_surface_finish <- function(surface) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_surface_finish_", surface)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_surface_flush
#'
#' Do any pending drawing for the surface and also restore any temporary
#' modifications cairo has made to the surface's state. This function
#' must be called before switching from drawing on the surface with
#' cairo to drawing on it directly with native APIs, or accessing its
#' memory outside of Cairo. If the surface doesn't support direct
#' access, then this function does nothing.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_surface_flush (cairo_surface_t *surface)}
#'
#' @param surface [\code{cairo_surface_t *}] a #cairo_surface_t
#'
#' @family cairo-surface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_surface_flush <- function(surface) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_surface_flush_", surface)
  invisible(NULL)
}
