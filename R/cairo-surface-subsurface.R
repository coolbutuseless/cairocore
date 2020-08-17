# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_surface_create_for_rectangle
#'
#' Create a new surface that is a rectangle within the target surface.
#' All operations drawn to this surface are then clipped and translated
#' onto the target surface. Nothing drawn via this sub-surface outside of
#' its bounds is drawn onto the target surface, making this a useful method
#' for passing constrained child surfaces to library routines that draw
#' directly onto the parent surface, i.e. with no further backend allocations,
#' double buffering or copies.
#'
#' <note><para>The semantics of subsurfaces have not been finalized yet
#' unless the rectangle is in full device units, is contained within
#' the extents of the target surface, and the target or subsurface's
#' device transforms are not changed.</para></note>
#'
#' Return value: a pointer to the newly allocated surface. The caller
#' owns the surface and should call cairo_surface_destroy() when done
#' with it.
#'
#' This function always returns a valid pointer, but it will return a
#' pointer to a "nil" surface if other is already in an error state
#' or any other error occurs.
#'
#' Since: 1.10
#'
#' C function prototype: \code{cairo_surface_t * cairo_surface_create_for_rectangle (cairo_surface_t *target, double x, double y, double width, double height)}
#'
#' @param target [\code{cairo_surface_t *}] an existing surface for which the sub-surface will point to
#' @param x [\code{double}] the x-origin of the sub-surface from the top-left of the target surface (in device-space units)
#' @param y [\code{double}] the y-origin of the sub-surface from the top-left of the target surface (in device-space units)
#' @param width [\code{double}] width of the sub-surface (in device-space units)
#' @param height [\code{double}] height of the sub-surface (in device-space units)
#'
#' @return [\code{cairo_surface_t *}]
#'
#' @family cairo-surface-subsurface
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_surface_create_for_rectangle <- function(target, x, y, width, height) {
  stopifnot(inherits(target, "cairo_surface_t"))
  .Call("cairo_surface_create_for_rectangle_", target, x, y, width, height)
}
