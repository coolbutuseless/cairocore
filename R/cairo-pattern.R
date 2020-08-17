# This file was auto-generated from C headers

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_rgb
#'
#' Creates a new #cairo_pattern_t corresponding to an opaque color.  The
#' color components are floating point numbers in the range 0 to 1.
#' If the values passed in are outside that range, they will be
#' clamped.
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory.  The caller owns the
#' returned object and should call cairo_pattern_destroy() when
#' finished with it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error.  To inspect
#' the status of a pattern use cairo_pattern_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_rgb (double red, double green, double blue)}
#'
#' @param red [\code{double}] red component of the color
#' @param green [\code{double}] green component of the color
#' @param blue [\code{double}] blue component of the color
#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_rgb <- function(red, green, blue) {
  .Call("cairo_pattern_create_rgb_", red, green, blue)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_rgba
#'
#' Creates a new #cairo_pattern_t corresponding to a translucent color.
#' The color components are floating point numbers in the range 0 to
#' 1.  If the values passed in are outside that range, they will be
#' clamped.
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory.  The caller owns the
#' returned object and should call cairo_pattern_destroy() when
#' finished with it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error.  To inspect
#' the status of a pattern use cairo_pattern_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_rgba (double red, double green, double blue, double alpha)}
#'
#' @param red [\code{double}] red component of the color
#' @param green [\code{double}] green component of the color
#' @param blue [\code{double}] blue component of the color
#' @param alpha [\code{double}] alpha component of the color
#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_rgba <- function(red, green, blue, alpha) {
  .Call("cairo_pattern_create_rgba_", red, green, blue, alpha)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_for_surface
#'
#' Create a new #cairo_pattern_t for the given surface.
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory.  The caller owns the
#' returned object and should call cairo_pattern_destroy() when
#' finished with it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error.  To inspect
#' the status of a pattern use cairo_pattern_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_for_surface (cairo_surface_t *surface)}
#'
#' @param surface [\code{cairo_surface_t *}] the surface
#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_for_surface <- function(surface) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_pattern_create_for_surface_", surface)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_linear
#'
#' Create a new linear gradient #cairo_pattern_t along the line defined
#' by (x0, y0) and (x1, y1).  Before using the gradient pattern, a
#' number of color stops should be defined using
#' cairo_pattern_add_color_stop_rgb() or
#' cairo_pattern_add_color_stop_rgba().
#'
#' Note: The coordinates here are in pattern space. For a new pattern,
#' pattern space is identical to user space, but the relationship
#' between the spaces can be changed with cairo_pattern_set_matrix().
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory.  The caller owns the
#' returned object and should call cairo_pattern_destroy() when
#' finished with it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error.  To inspect
#' the status of a pattern use cairo_pattern_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_linear (double x0, double y0, double x1, double y1)}
#'
#' @param x0 [\code{double}] x coordinate of the start point
#' @param y0 [\code{double}] y coordinate of the start point
#' @param x1 [\code{double}] x coordinate of the end point
#' @param y1 [\code{double}] y coordinate of the end point
#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_linear <- function(x0, y0, x1, y1) {
  .Call("cairo_pattern_create_linear_", x0, y0, x1, y1)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_radial
#'
#' Creates a new radial gradient #cairo_pattern_t between the two
#' circles defined by (cx0, cy0, radius0) and (cx1, cy1, radius1).  Before using the
#' gradient pattern, a number of color stops should be defined using
#' cairo_pattern_add_color_stop_rgb() or
#' cairo_pattern_add_color_stop_rgba().
#'
#' Note: The coordinates here are in pattern space. For a new pattern,
#' pattern space is identical to user space, but the relationship
#' between the spaces can be changed with cairo_pattern_set_matrix().
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory.  The caller owns the
#' returned object and should call cairo_pattern_destroy() when
#' finished with it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error.  To inspect
#' the status of a pattern use cairo_pattern_status().
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_radial (double cx0, double cy0, double radius0, double cx1, double cy1, double radius1)}
#'
#' @param cx0 [\code{double}] x coordinate for the center of the start circle
#' @param cy0 [\code{double}] y coordinate for the center of the start circle
#' @param radius0 [\code{double}] radius of the start circle
#' @param cx1 [\code{double}] x coordinate for the center of the end circle
#' @param cy1 [\code{double}] y coordinate for the center of the end circle
#' @param radius1 [\code{double}] radius of the end circle
#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_radial <- function(cx0, cy0, radius0, cx1, cy1, radius1) {
  .Call("cairo_pattern_create_radial_", cx0, cy0, radius0, cx1, cy1, radius1)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_create_mesh
#'
#' cairo_pattern_create_mesh:
#'
#' Create a new mesh pattern.
#'
#' Mesh patterns are tensor-product patch meshes (type 7 shadings in
#' PDF). Mesh patterns may also be used to create other types of
#' shadings that are special cases of tensor-product patch meshes such
#' as Coons patch meshes (type 6 shading in PDF) and Gouraud-shaded
#' triangle meshes (type 4 and 5 shadings in PDF).
#'
#' Mesh patterns consist of one or more tensor-product patches, which
#' should be defined before using the mesh pattern. Using a mesh
#' pattern with a partially defined patch as source or mask will put
#' the context in an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' A tensor-product patch is defined by 4 Bézier curves (side 0, 1, 2,
#' 3) and by 4 additional control points (P0, P1, P2, P3) that provide
#' further control over the patch and complete the definition of the
#' tensor-product patch. The corner C0 is the first point of the
#' patch.
#'
#' Degenerate sides are permitted so straight lines may be used. A
#' zero length line on one side may be used to create 3 sided patches.
#'
#' <informalexample><screen>
#' C1     Side 1       C2
#' +---------------+
#' |               |
#' |  P1       P2  |
#' |               |
#' Side 0 |               | Side 2
#' |               |
#' |               |
#' |  P0       P3  |
#' |               |
#' +---------------+
#' C0     Side 3        C3
#' </screen></informalexample>
#'
#' Each patch is constructed by first calling
#' cairo_mesh_pattern_begin_patch(), then cairo_mesh_pattern_move_to()
#' to specify the first point in the patch (C0). Then the sides are
#' specified with calls to cairo_mesh_pattern_curve_to() and
#' cairo_mesh_pattern_line_to().
#'
#' The four additional control points (P0, P1, P2, P3) in a patch can
#' be specified with cairo_mesh_pattern_set_control_point().
#'
#' At each corner of the patch (C0, C1, C2, C3) a color may be
#' specified with cairo_mesh_pattern_set_corner_color_rgb() or
#' cairo_mesh_pattern_set_corner_color_rgba(). Any corner whose color
#' is not explicitly specified defaults to transparent black.
#'
#' A Coons patch is a special case of the tensor-product patch where
#' the control points are implicitly defined by the sides of the
#' patch. The default value for any control point not specified is the
#' implicit value for a Coons patch, i.e. if no control points are
#' specified the patch is a Coons patch.
#'
#' A triangle is a special case of the tensor-product patch where the
#' control points are implicitly defined by the sides of the patch,
#' all the sides are lines and one of them has length 0, i.e. if the
#' patch is specified using just 3 lines, it is a triangle. If the
#' corners connected by the 0-length side have the same color, the
#' patch is a Gouraud-shaded triangle.
#'
#' Patches may be oriented differently to the above diagram. For
#' example the first point could be at the top left. The diagram only
#' shows the relationship between the sides, corners and control
#' points. Regardless of where the first point is located, when
#' specifying colors, corner 0 will always be the first point, corner
#' 1 the point between side 0 and side 1 etc.
#'
#' Calling cairo_mesh_pattern_end_patch() completes the current
#' patch. If less than 4 sides have been defined, the first missing
#' side is defined as a line from the current point to the first point
#' of the patch (C0) and the other sides are degenerate lines from C0
#' to C0. The corners between the added sides will all be coincident
#' with C0 of the patch and their color will be set to be the same as
#' the color of C0.
#'
#' Additional patches may be added with additional calls to
#' cairo_mesh_pattern_begin_patch()/cairo_mesh_pattern_end_patch().
#'
#' <informalexample><programlisting>
#' cairo_pattern_t *pattern = cairo_pattern_create_mesh ();
#'
#' /&ast; Add a Coons patch &ast;/
#' cairo_mesh_pattern_begin_patch (pattern);
#' cairo_mesh_pattern_move_to (pattern, 0, 0);
#' cairo_mesh_pattern_curve_to (pattern, 30, -30,  60,  30, 100, 0);
#' cairo_mesh_pattern_curve_to (pattern, 60,  30, 130,  60, 100, 100);
#' cairo_mesh_pattern_curve_to (pattern, 60,  70,  30, 130,   0, 100);
#' cairo_mesh_pattern_curve_to (pattern, 30,  70, -30,  30,   0, 0);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 0, 1, 0, 0);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 1, 0, 1, 0);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 2, 0, 0, 1);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 3, 1, 1, 0);
#' cairo_mesh_pattern_end_patch (pattern);
#'
#' /&ast; Add a Gouraud-shaded triangle &ast;/
#' cairo_mesh_pattern_begin_patch (pattern)
#' cairo_mesh_pattern_move_to (pattern, 100, 100);
#' cairo_mesh_pattern_line_to (pattern, 130, 130);
#' cairo_mesh_pattern_line_to (pattern, 130,  70);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 0, 1, 0, 0);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 1, 0, 1, 0);
#' cairo_mesh_pattern_set_corner_color_rgb (pattern, 2, 0, 0, 1);
#' cairo_mesh_pattern_end_patch (pattern)
#' </programlisting></informalexample>
#'
#' When two patches overlap, the last one that has been added is drawn
#' over the first one.
#'
#' When a patch folds over itself, points are sorted depending on
#' their parameter coordinates inside the patch. The v coordinate
#' ranges from 0 to 1 when moving from side 3 to side 1; the u
#' coordinate ranges from 0 to 1 when going from side 0 to side
#' 2. Points with higher v coordinate hide points with lower v
#' coordinate. When two points have the same v coordinate, the one
#' with higher u coordinate is above. This means that points nearer to
#' side 1 are above points nearer to side 3; when this is not
#' sufficient to decide which point is above (for example when both
#' points belong to side 1 or side 3) points nearer to side 2 are
#' above points nearer to side 0.
#'
#' For a complete definition of tensor-product patches, see the PDF
#' specification (ISO32000), which describes the parametrization in
#' detail.
#'
#' Note: The coordinates are always in pattern space. For a new
#' pattern, pattern space is identical to user space, but the
#' relationship between the spaces can be changed with
#' cairo_pattern_set_matrix().
#'
#' Return value: the newly created #cairo_pattern_t if successful, or
#' an error pattern in case of no memory. The caller owns the returned
#' object and should call cairo_pattern_destroy() when finished with
#' it.
#'
#' This function will always return a valid pointer, but if an error
#' occurred the pattern status will be set to an error. To inspect the
#' status of a pattern use cairo_pattern_status().
#'
#' Since: 1.12
#'
#' C function prototype: \code{cairo_pattern_t * cairo_pattern_create_mesh (void)}
#'

#'
#' @return [\code{cairo_pattern_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_create_mesh <- function() {
  .Call("cairo_pattern_create_mesh_")
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_type
#'
#' Get the pattern's type.  See #cairo_pattern_type_t for available
#' types.
#'
#' Return value: The type of pattern.
#'
#' Since: 1.2
#'
#' C function prototype: \code{cairo_pattern_type_t cairo_pattern_get_type (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_type <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_type_", pattern)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_status
#'
#' Checks whether an error has previously occurred for this
#' pattern.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, \%CAIRO_STATUS_NO_MEMORY,
#' \%CAIRO_STATUS_INVALID_MATRIX, \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH,
#' or \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_status (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_status <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_status_", pattern)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_begin_patch
#'
#' Begin a patch in a mesh pattern.
#'
#' After calling this function, the patch shape should be defined with
#' cairo_mesh_pattern_move_to(), cairo_mesh_pattern_line_to() and
#' cairo_mesh_pattern_curve_to().
#'
#' After defining the patch, cairo_mesh_pattern_end_patch() must be
#' called before using pattern as a source or mask.
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If pattern already has a
#' current patch, it will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_begin_patch (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_begin_patch <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_begin_patch_", pattern)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_end_patch
#'
#' Indicates the end of the current patch in a mesh pattern.
#'
#' If the current patch has less than 4 sides, it is closed with a
#' straight line from the current point to the first point of the
#' patch as if cairo_mesh_pattern_line_to() was used.
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If pattern has no current
#' patch or the current patch has no current point, pattern will be
#' put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_end_patch (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_end_patch <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_end_patch_", pattern)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_curve_to
#'
#' Adds a cubic Bézier spline to the current patch from the current
#' point to position (x3, y3) in pattern-space coordinates, using
#' (x1, y1) and (x2, y2) as the control points.
#'
#' If the current patch has no current point before the call to
#' cairo_mesh_pattern_curve_to(), this function will behave as if
#' preceded by a call to cairo_mesh_pattern_move_to(pattern, x1,
#' y1).
#'
#' After this call the current point will be (x3, y3).
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If pattern has no current
#' patch or the current patch already has 4 sides, pattern will be
#' put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_curve_to (cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param x1 [\code{double}] the X coordinate of the first control point
#' @param y1 [\code{double}] the Y coordinate of the first control point
#' @param x2 [\code{double}] the X coordinate of the second control point
#' @param y2 [\code{double}] the Y coordinate of the second control point
#' @param x3 [\code{double}] the X coordinate of the end of the curve
#' @param y3 [\code{double}] the Y coordinate of the end of the curve
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_curve_to <- function(pattern, x1, y1, x2, y2, x3, y3) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_curve_to_", pattern, x1, y1, x2, y2, x3, y3)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_line_to
#'
#' Adds a line to the current patch from the current point to position
#' (x, y) in pattern-space coordinates.
#'
#' If there is no current point before the call to
#' cairo_mesh_pattern_line_to() this function will behave as
#' cairo_mesh_pattern_move_to(pattern, x, y).
#'
#' After this call the current point will be (x, y).
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If pattern has no current
#' patch or the current patch already has 4 sides, pattern will be
#' put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_line_to (cairo_pattern_t *pattern, double x, double y)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param x [\code{double}] the X coordinate of the end of the new line
#' @param y [\code{double}] the Y coordinate of the end of the new line
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_line_to <- function(pattern, x, y) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_line_to_", pattern, x, y)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_move_to
#'
#' Define the first point of the current patch in a mesh pattern.
#'
#' After this call the current point will be (x, y).
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If pattern has no current
#' patch or the current patch already has at least one side, pattern
#' will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_move_to (cairo_pattern_t *pattern, double x, double y)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param x [\code{double}] the X coordinate of the new position
#' @param y [\code{double}] the Y coordinate of the new position
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_move_to <- function(pattern, x, y) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_move_to_", pattern, x, y)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_set_control_point
#'
#' Set an internal control point of the current patch.
#'
#' Valid values for point_num are from 0 to 3 and identify the
#' control points as explained in cairo_pattern_create_mesh().
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If point_num is not valid,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_INDEX.  If pattern has no current patch,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_set_control_point (cairo_pattern_t *pattern, unsigned int point_num, double x, double y)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param point_num [\code{unsigned int}] the control point to set the position for
#' @param x [\code{double}] the X coordinate of the control point
#' @param y [\code{double}] the Y coordinate of the control point
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_set_control_point <- function(pattern, point_num, x, y) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_set_control_point_", pattern, point_num, x, y)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_set_corner_color_rgb
#'
#' Sets the color of a corner of the current patch in a mesh pattern.
#'
#' The color is specified in the same way as in cairo_set_source_rgb().
#'
#' Valid values for corner_num are from 0 to 3 and identify the
#' corners as explained in cairo_pattern_create_mesh().
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If corner_num is not valid,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_INDEX.  If pattern has no current patch,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_set_corner_color_rgb (cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param corner_num [\code{unsigned int}] the corner to set the color for
#' @param red [\code{double}] red component of color
#' @param green [\code{double}] green component of color
#' @param blue [\code{double}] blue component of color
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_set_corner_color_rgb <- function(pattern, corner_num, red, green, blue) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_set_corner_color_rgb_", pattern, corner_num, red, green, blue)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_set_corner_color_rgba
#'
#' Sets the color of a corner of the current patch in a mesh pattern.
#'
#' The color is specified in the same way as in cairo_set_source_rgba().
#'
#' Valid values for corner_num are from 0 to 3 and identify the
#' corners as explained in cairo_pattern_create_mesh().
#'
#' Note: If pattern is not a mesh pattern then pattern will be put
#' into an error status with a status of
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH. If corner_num is not valid,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_INDEX.  If pattern has no current patch,
#' pattern will be put into an error status with a status of
#' \%CAIRO_STATUS_INVALID_MESH_CONSTRUCTION.
#'
#' Since: 1.12
#'
#' C function prototype: \code{void cairo_mesh_pattern_set_corner_color_rgba (cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param corner_num [\code{unsigned int}] the corner to set the color for
#' @param red [\code{double}] red component of color
#' @param green [\code{double}] green component of color
#' @param blue [\code{double}] blue component of color
#' @param alpha [\code{double}] alpha component of color
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_set_corner_color_rgba <- function(pattern, corner_num, red, green, blue, alpha) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_set_corner_color_rgba_", pattern, corner_num, red, green, blue, alpha)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_add_color_stop_rgb
#'
#' Adds an opaque color stop to a gradient pattern. The offset
#' specifies the location along the gradient's control vector. For
#' example, a linear gradient's control vector is from (x0,y0) to
#' (x1,y1) while a radial gradient's control vector is from any point
#' on the start circle to the corresponding point on the end circle.
#'
#' The color is specified in the same way as in cairo_set_source_rgb().
#'
#' If two (or more) stops are specified with identical offset values,
#' they will be sorted according to the order in which the stops are
#' added, (stops added earlier will compare less than stops added
#' later). This can be useful for reliably making sharp color
#' transitions instead of the typical blend.
#'
#'
#' Note: If the pattern is not a gradient pattern, (eg. a linear or
#' radial pattern), then the pattern will be put into an error status
#' with a status of \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_add_color_stop_rgb (cairo_pattern_t *pattern, double offset, double red, double green, double blue)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param offset [\code{double}] an offset in the range [0.0 .. 1.0]
#' @param red [\code{double}] red component of color
#' @param green [\code{double}] green component of color
#' @param blue [\code{double}] blue component of color
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_add_color_stop_rgb <- function(pattern, offset, red, green, blue) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_add_color_stop_rgb_", pattern, offset, red, green, blue)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_add_color_stop_rgba
#'
#' Adds a translucent color stop to a gradient pattern. The offset
#' specifies the location along the gradient's control vector. For
#' example, a linear gradient's control vector is from (x0,y0) to
#' (x1,y1) while a radial gradient's control vector is from any point
#' on the start circle to the corresponding point on the end circle.
#'
#' The color is specified in the same way as in cairo_set_source_rgba().
#'
#' If two (or more) stops are specified with identical offset values,
#' they will be sorted according to the order in which the stops are
#' added, (stops added earlier will compare less than stops added
#' later). This can be useful for reliably making sharp color
#' transitions instead of the typical blend.
#'
#' Note: If the pattern is not a gradient pattern, (eg. a linear or
#' radial pattern), then the pattern will be put into an error status
#' with a status of \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_add_color_stop_rgba (cairo_pattern_t *pattern, double offset, double red, double green, double blue, double alpha)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param offset [\code{double}] an offset in the range [0.0 .. 1.0]
#' @param red [\code{double}] red component of color
#' @param green [\code{double}] green component of color
#' @param blue [\code{double}] blue component of color
#' @param alpha [\code{double}] alpha component of color
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_add_color_stop_rgba <- function(pattern, offset, red, green, blue, alpha) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_add_color_stop_rgba_", pattern, offset, red, green, blue, alpha)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_set_matrix
#'
#' Sets the pattern's transformation matrix to matrix. This matrix is
#' a transformation from user space to pattern space.
#'
#' When a pattern is first created it always has the identity matrix
#' for its transformation matrix, which means that pattern space is
#' initially identical to user space.
#'
#' Important: Please note that the direction of this transformation
#' matrix is from user space to pattern space. This means that if you
#' imagine the flow from a pattern to user space (and on to device
#' space), then coordinates in that flow will be transformed by the
#' inverse of the pattern matrix.
#'
#' For example, if you want to make a pattern appear twice as large as
#' it does by default the correct code to use is:
#'
#' <informalexample><programlisting>
#' cairo_matrix_init_scale (&amp;matrix, 0.5, 0.5);
#' cairo_pattern_set_matrix (pattern, &amp;matrix);
#' </programlisting></informalexample>
#'
#' Meanwhile, using values of 2.0 rather than 0.5 in the code above
#' would cause the pattern to appear at half of its default size.
#'
#' Also, please note the discussion of the user-space locking
#' semantics of cairo_set_source().
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_set_matrix (cairo_pattern_t *pattern, const cairo_matrix_t *matrix)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param matrix [\code{cairo_matrix_t *}] a #cairo_matrix_t
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_set_matrix <- function(pattern, matrix) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_pattern_set_matrix_", pattern, matrix)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_matrix
#'
#' Stores the pattern's transformation matrix into matrix.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_get_matrix (cairo_pattern_t *pattern, cairo_matrix_t *matrix)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param matrix [\code{cairo_matrix_t *}] return value for the matrix
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_matrix <- function(pattern, matrix) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  stopifnot(inherits(matrix, "cairo_matrix_t"))
  .Call("cairo_pattern_get_matrix_", pattern, matrix)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_set_filter
#'
#' Sets the filter to be used for resizing when using this pattern.
#' See #cairo_filter_t for details on each filter.
#'
#' * Note that you might want to control filtering even when you do not
#' have an explicit #cairo_pattern_t object, (for example when using
#' cairo_set_source_surface()). In these cases, it is convenient to
#' use cairo_get_source() to get access to the pattern that cairo
#' creates implicitly. For example:
#'
#' <informalexample><programlisting>
#' cairo_set_source_surface (cr, image, x, y);
#' cairo_pattern_set_filter (cairo_get_source (cr), CAIRO_FILTER_NEAREST);
#' </programlisting></informalexample>
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_set_filter (cairo_pattern_t *pattern, cairo_filter_t filter)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param filter [\code{int}] a #cairo_filter_t describing the filter to use for resizing the pattern
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_set_filter <- function(pattern, filter) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_set_filter_", pattern, filter)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_filter
#'
#' Gets the current filter for a pattern.  See #cairo_filter_t
#' for details on each filter.
#'
#' Return value: the current filter used for resizing the pattern.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_filter_t cairo_pattern_get_filter (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_filter <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_filter_", pattern)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_set_extend
#'
#' Sets the mode to be used for drawing outside the area of a pattern.
#' See #cairo_extend_t for details on the semantics of each extend
#' strategy.
#'
#' The default extend mode is \%CAIRO_EXTEND_NONE for surface patterns
#' and \%CAIRO_EXTEND_PAD for gradient patterns.
#'
#' Since: 1.0
#'
#' C function prototype: \code{void cairo_pattern_set_extend (cairo_pattern_t *pattern, cairo_extend_t extend)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param extend [\code{int}] a #cairo_extend_t describing how the area outside of the pattern will be drawn
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_set_extend <- function(pattern, extend) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_set_extend_", pattern, extend)
  invisible(NULL)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_extend
#'
#' Gets the current extend mode for a pattern.  See #cairo_extend_t
#' for details on the semantics of each extend strategy.
#'
#' Return value: the current extend strategy used for drawing the
#' pattern.
#'
#' Since: 1.0
#'
#' C function prototype: \code{cairo_extend_t cairo_pattern_get_extend (cairo_pattern_t *pattern)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_extend <- function(pattern) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_extend_", pattern)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_rgba
#'
#' Gets the solid color for a solid color pattern.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH if the pattern is not a solid
#' color pattern.
#'
#' Since: 1.4
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_get_rgba (cairo_pattern_t *pattern, double *red, double *green, double *blue, double *alpha)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param red [\code{double *}] return value for red component of color, or \%NULL
#' @param green [\code{double *}] return value for green component of color, or \%NULL
#' @param blue [\code{double *}] return value for blue component of color, or \%NULL
#' @param alpha [\code{double *}] return value for alpha component of color, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_rgba <- function(pattern, red, green, blue, alpha) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_rgba_", pattern, red, green, blue, alpha)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_color_stop_rgba
#'
#' Gets the color and offset information at the given index for a
#' gradient pattern.  Values of index range from 0 to n-1
#' where n is the number returned
#' by cairo_pattern_get_color_stop_count().
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or \%CAIRO_STATUS_INVALID_INDEX
#' if index is not valid for the given pattern.  If the pattern is
#' not a gradient pattern, \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH is
#' returned.
#'
#' Since: 1.4
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_get_color_stop_rgba (cairo_pattern_t *pattern, int index, double *offset, double *red, double *green, double *blue, double *alpha)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param index [\code{int}] index of the stop to return data for
#' @param offset [\code{double *}] return value for the offset of the stop, or \%NULL
#' @param red [\code{double *}] return value for red component of color, or \%NULL
#' @param green [\code{double *}] return value for green component of color, or \%NULL
#' @param blue [\code{double *}] return value for blue component of color, or \%NULL
#' @param alpha [\code{double *}] return value for alpha component of color, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_color_stop_rgba <- function(pattern, index, offset, red, green, blue, alpha) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_color_stop_rgba_", pattern, index, offset, red, green, blue, alpha)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_color_stop_count
#'
#' Gets the number of color stops specified in the given gradient
#' pattern.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH if pattern is not a gradient
#' pattern.
#'
#' Since: 1.4
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_get_color_stop_count (cairo_pattern_t *pattern, int *count)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param count [\code{int *}] return value for the number of color stops, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_color_stop_count <- function(pattern, count) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_color_stop_count_", pattern, count)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_linear_points
#'
#' Gets the gradient endpoints for a linear gradient.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH if pattern is not a linear
#' gradient pattern.
#'
#' Since: 1.4
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_get_linear_points (cairo_pattern_t *pattern, double *x0, double *y0, double *x1, double *y1)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param x0 [\code{double *}] return value for the x coordinate of the first point, or \%NULL
#' @param y0 [\code{double *}] return value for the y coordinate of the first point, or \%NULL
#' @param x1 [\code{double *}] return value for the x coordinate of the second point, or \%NULL
#' @param y1 [\code{double *}] return value for the y coordinate of the second point, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_linear_points <- function(pattern, x0, y0, x1, y1) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_linear_points_", pattern, x0, y0, x1, y1)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pattern_get_radial_circles
#'
#' Gets the gradient endpoint circles for a radial gradient, each
#' specified as a center coordinate and a radius.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH if pattern is not a radial
#' gradient pattern.
#'
#' Since: 1.4
#'
#' C function prototype: \code{cairo_status_t cairo_pattern_get_radial_circles (cairo_pattern_t *pattern, double *x0, double *y0, double *r0, double *x1, double *y1, double *r1)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param x0 [\code{double *}] return value for the x coordinate of the center of the first circle, or \%NULL
#' @param y0 [\code{double *}] return value for the y coordinate of the center of the first circle, or \%NULL
#' @param r0 [\code{double *}] return value for the radius of the first circle, or \%NULL
#' @param x1 [\code{double *}] return value for the x coordinate of the center of the second circle, or \%NULL
#' @param y1 [\code{double *}] return value for the y coordinate of the center of the second circle, or \%NULL
#' @param r1 [\code{double *}] return value for the radius of the second circle, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pattern_get_radial_circles <- function(pattern, x0, y0, r0, x1, y1, r1) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_pattern_get_radial_circles_", pattern, x0, y0, r0, x1, y1, r1)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_get_patch_count
#'
#' Gets the number of patches specified in the given mesh pattern.
#'
#' The number only includes patches which have been finished by
#' calling cairo_mesh_pattern_end_patch(). For example it will be 0
#' during the definition of the first patch.
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or
#' \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH if pattern is not a mesh
#' pattern.
#'
#' Since: 1.12
#'
#' C function prototype: \code{cairo_status_t cairo_mesh_pattern_get_patch_count (cairo_pattern_t *pattern, unsigned int *count)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param count [\code{unsigned int *}] return value for the number patches, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_get_patch_count <- function(pattern, count) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  stopifnot(inherits(count, "unsigned int"))
  .Call("cairo_mesh_pattern_get_patch_count_", pattern, count)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_get_path
#'
#' Gets path defining the patch patch_num for a mesh
#' pattern.
#'
#' patch_num can range from 0 to n-1 where n is the number returned by
#' cairo_mesh_pattern_get_patch_count().
#'
#' Return value: the path defining the patch, or a path with status
#' \%CAIRO_STATUS_INVALID_INDEX if patch_num or point_num is not
#' valid for pattern. If pattern is not a mesh pattern, a path with
#' status \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH is returned.
#'
#' Since: 1.12
#'
#' C function prototype: \code{cairo_path_t * cairo_mesh_pattern_get_path (cairo_pattern_t *pattern, unsigned int patch_num)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param patch_num [\code{unsigned int}] the patch number to return data for
#'
#' @return [\code{cairo_path_t *}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_get_path <- function(pattern, patch_num) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_get_path_", pattern, patch_num)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_get_corner_color_rgba
#'
#' Gets the color information in corner corner_num of patch
#' patch_num for a mesh pattern.
#'
#' patch_num can range from 0 to n-1 where n is the number returned by
#' cairo_mesh_pattern_get_patch_count().
#'
#' Valid values for corner_num are from 0 to 3 and identify the
#' corners as explained in cairo_pattern_create_mesh().
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or \%CAIRO_STATUS_INVALID_INDEX
#' if patch_num or corner_num is not valid for pattern. If
#' pattern is not a mesh pattern, \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH
#' is returned.
#'
#' Since: 1.12
#'
#' C function prototype: \code{cairo_status_t cairo_mesh_pattern_get_corner_color_rgba (cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param patch_num [\code{unsigned int}] the patch number to return data for
#' @param corner_num [\code{unsigned int}] the corner number to return data for
#' @param red [\code{double *}] return value for red component of color, or \%NULL
#' @param green [\code{double *}] return value for green component of color, or \%NULL
#' @param blue [\code{double *}] return value for blue component of color, or \%NULL
#' @param alpha [\code{double *}] return value for alpha component of color, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_get_corner_color_rgba <- function(pattern, patch_num, corner_num, red, green, blue, alpha) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_get_corner_color_rgba_", pattern, patch_num, corner_num, red, green, blue, alpha)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_mesh_pattern_get_control_point
#'
#' Gets the control point point_num of patch patch_num for a mesh
#' pattern.
#'
#' patch_num can range from 0 to n-1 where n is the number returned by
#' cairo_mesh_pattern_get_patch_count().
#'
#' Valid values for point_num are from 0 to 3 and identify the
#' control points as explained in cairo_pattern_create_mesh().
#'
#' Return value: \%CAIRO_STATUS_SUCCESS, or \%CAIRO_STATUS_INVALID_INDEX
#' if patch_num or point_num is not valid for pattern. If pattern
#' is not a mesh pattern, \%CAIRO_STATUS_PATTERN_TYPE_MISMATCH is
#' returned.
#'
#' Since: 1.12
#'
#' C function prototype: \code{cairo_status_t cairo_mesh_pattern_get_control_point (cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y)}
#'
#' @param pattern [\code{cairo_pattern_t *}] a #cairo_pattern_t
#' @param patch_num [\code{unsigned int}] the patch number to return data for
#' @param point_num [\code{unsigned int}] the control point number to return data for
#' @param x [\code{double *}] return value for the x coordinate of the control point, or \%NULL
#' @param y [\code{double *}] return value for the y coordinate of the control point, or \%NULL
#'
#' @return [\code{int}]
#'
#' @family cairo-pattern
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_mesh_pattern_get_control_point <- function(pattern, patch_num, point_num, x, y) {
  stopifnot(inherits(pattern, "cairo_pattern_t"))
  .Call("cairo_mesh_pattern_get_control_point_", pattern, patch_num, point_num, x, y)
}
