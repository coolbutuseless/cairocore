



cairo_header <- list(

  cairo_create <- list(
    include = TRUE,
    gtkdoc = r"{/**
  * cairo_create:
  * @target: target surface for the context
*
  * Creates a new #cairo_t with all graphics state parameters set to
* default values and with @target as a target surface. The target
* surface should be constructed with a backend-specific function such
* as cairo_image_surface_create() (or any other
                                   * <function>cairo_<emphasis>backend</emphasis>_surface_create(<!-- -->)</function>
                                     * variant).
*
  * This function references @target, so you can immediately
* call cairo_surface_destroy() on it if you don't need to
 * maintain a separate reference to it.
 *
 * Return value: a newly allocated #cairo_t with a reference
 *  count of 1. The initial reference count should be released
 *  with cairo_destroy() when you are done using the #cairo_t.
 *  This function never returns %NULL. If memory cannot be
 *  allocated, a special #cairo_t object will be returned on
 *  which cairo_status() returns %CAIRO_STATUS_NO_MEMORY. If
 *  you attempt to target a surface which does not support
 *  writing (such as #cairo_mime_surface_t) then a
 *  %CAIRO_STATUS_WRITE_ERROR will be raised.  You can use this
 *  object normally, but no drawing will be done.
 *
 * Since: 1.0
 **/}",
    proto_text = "cairo_t * cairo_create (cairo_surface_t *target)"
  ),

  cairo_move_to <- list(
    include = TRUE,
    gtkdoc = r"{/**
  * cairo_move_to:
  * @cr: a cairo context
* @x: the X coordinate of the new position
* @y: the Y coordinate of the new position
*
  * Begin a new sub-path. After this call the current point will be (@x,
                                                                     * @y).
*
  * Since: 1.0
**/}",
    proto_text = "void cairo_move_to (cairo_t *cr, double x, double y)"
  ),


  cairo_line_to <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_line_to:
 * @cr: a cairo context
 * @x: the X coordinate of the end of the new line
 * @y: the Y coordinate of the end of the new line
 *
 * Adds a line to the path from the current point to position (@x, @y)
 * in user-space coordinates. After this call the current point
 * will be (@x, @y).
 *
 * If there is no current point before the call to cairo_line_to()
 * this function will behave as cairo_move_to(@cr, @x, @y).
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_line_to (cairo_t *cr, double x, double y)"
  ),


  cairo_rectangle <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_rectangle:
 * @cr: a cairo context
 * @x: the X coordinate of the top left corner of the rectangle
 * @y: the Y coordinate to the top left corner of the rectangle
 * @width: the width of the rectangle
 * @height: the height of the rectangle
 *
 * Adds a closed sub-path rectangle of the given size to the current
 * path at position (@x, @y) in user-space coordinates.
 *
 * This function is logically equivalent to:
 * <informalexample><programlisting>
 * cairo_move_to (cr, x, y);
 * cairo_rel_line_to (cr, width, 0);
 * cairo_rel_line_to (cr, 0, height);
 * cairo_rel_line_to (cr, -width, 0);
 * cairo_close_path (cr);
 * </programlisting></informalexample>
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_rectangle (cairo_t *cr,
		 double x, double y,
		 double width, double height)"
  ),


  cairo_paint <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_paint:
 * @cr: a cairo context
 *
 * A drawing operator that paints the current source everywhere within
 * the current clip region.
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_paint (cairo_t *cr)"
  ),



  cairo_select_font_face <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_select_font_face:
 * @cr: a #cairo_t
 * @family: a font family name, encoded in UTF-8
 * @slant: the slant for the font
 * @weight: the weight for the font
 *
 * Note: The cairo_select_font_face() function call is part of what
 * the cairo designers call the "toy" text API. It is convenient for
 * short demos and simple programs, but it is not expected to be
 * adequate for serious text-using applications.
 *
 * Selects a family and style of font from a simplified description as
 * a family name, slant and weight. Cairo provides no operation to
 * list available family names on the system (this is a "toy",
 * remember), but the standard CSS2 generic family names, ("serif",
 * "sans-serif", "cursive", "fantasy", "monospace"), are likely to
 * work as expected.
 *
 * If @family starts with the string "@cairo:", or if no native font
 * backends are compiled in, cairo will use an internal font family.
 * The internal font family recognizes many modifiers in the @family
 * string, most notably, it recognizes the string "monospace".  That is,
 * the family name "@cairo:monospace" will use the monospace version of
 * the internal font family.
 *
 * For "real" font selection, see the font-backend-specific
 * font_face_create functions for the font backend you are using. (For
 * example, if you are using the freetype-based cairo-ft font backend,
 * see cairo_ft_font_face_create_for_ft_face() or
 * cairo_ft_font_face_create_for_pattern().) The resulting font face
 * could then be used with cairo_scaled_font_create() and
 * cairo_set_scaled_font().
 *
 * Similarly, when using the "real" font support, you can call
 * directly into the underlying font system, (such as fontconfig or
 * freetype), for operations such as listing available fonts, etc.
 *
 * It is expected that most applications will need to use a more
 * comprehensive font handling and text layout library, (for example,
 * pango), in conjunction with cairo.
 *
 * If text is drawn without a call to cairo_select_font_face(), (nor
 * cairo_set_font_face() nor cairo_set_scaled_font()), the default
 * family is platform-specific, but is essentially "sans-serif".
 * Default slant is %CAIRO_FONT_SLANT_NORMAL, and default weight is
 * %CAIRO_FONT_WEIGHT_NORMAL.
 *
 * This function is equivalent to a call to cairo_toy_font_face_create()
 * followed by cairo_set_font_face().
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_select_font_face (cairo_t              *cr,
			const char           *family,
			cairo_font_slant_t    slant,
			cairo_font_weight_t   weight)"
  ),



  cairo_set_font_size <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_set_font_size:
 * @cr: a #cairo_t
 * @size: the new font size, in user space units
 *
 * Sets the current font matrix to a scale by a factor of @size, replacing
 * any font matrix previously set with cairo_set_font_size() or
 * cairo_set_font_matrix(). This results in a font size of @size user space
 * units. (More precisely, this matrix will result in the font's
 * em-square being a @size by @size square in user space.)
 *
 * If text is drawn without a call to cairo_set_font_size(), (nor
 * cairo_set_font_matrix() nor cairo_set_scaled_font()), the default
 * font size is 10.0.
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_set_font_size (cairo_t *cr, double size)"
  ),



  cairo_show_text <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_show_text:
 * @cr: a cairo context
 * @utf8: a NUL-terminated string of text encoded in UTF-8, or %NULL
 *
 * A drawing operator that generates the shape from a string of UTF-8
 * characters, rendered according to the current font_face, font_size
 * (font_matrix), and font_options.
 *
 * This function first computes a set of glyphs for the string of
 * text. The first glyph is placed so that its origin is at the
 * current point. The origin of each subsequent glyph is offset from
 * that of the previous glyph by the advance values of the previous
 * glyph.
 *
 * After this call the current point is moved to the origin of where
 * the next glyph would be placed in this same progression. That is,
 * the current point will be at the origin of the final glyph offset
 * by its advance values. This allows for easy display of a single
 * logical string with multiple calls to cairo_show_text().
 *
 * Note: The cairo_show_text() function call is part of what the cairo
 * designers call the "toy" text API. It is convenient for short demos
 * and simple programs, but it is not expected to be adequate for
 * serious text-using applications. See cairo_show_glyphs() for the
 * "real" text display API in cairo.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_show_text (cairo_t *cr, const char *utf8)"
  ),



  cairo_set_source_rgb <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_set_source_rgb:
 * @cr: a cairo context
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 *
 * Sets the source pattern within @cr to an opaque color. This opaque
 * color will then be used for any subsequent drawing operation until
 * a new source pattern is set.
 *
 * The color components are floating point numbers in the range 0 to
 * 1. If the values passed in are outside that range, they will be
 * clamped.
 *
 * The default source pattern is opaque black, (that is, it is
 * equivalent to cairo_set_source_rgb(cr, 0.0, 0.0, 0.0)).
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_set_source_rgb (cairo_t *cr, double red, double green, double blue)"
  ),

  cairo_set_antialias <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_set_antialias:
 * @cr: a #cairo_t
 * @antialias: the new antialiasing mode
 *
 * Set the antialiasing mode of the rasterizer used for drawing shapes.
 * This value is a hint, and a particular backend may or may not support
 * a particular value.  At the current time, no backend supports
 * %CAIRO_ANTIALIAS_SUBPIXEL when drawing shapes.
 *
 * Note that this option does not affect text rendering, instead see
 * cairo_font_options_set_antialias().
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_set_antialias (cairo_t *cr, cairo_antialias_t antialias)"
  ),

  cairo_set_fill_rule <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_fill_rule_t:
 * @CAIRO_FILL_RULE_WINDING: If the path crosses the ray from
 * left-to-right, counts +1. If the path crosses the ray
 * from right to left, counts -1. (Left and right are determined
 * from the perspective of looking along the ray from the starting
 * point.) If the total count is non-zero, the point will be filled. (Since 1.0)
 * @CAIRO_FILL_RULE_EVEN_ODD: Counts the total number of
 * intersections, without regard to the orientation of the contour. If
 * the total number of intersections is odd, the point will be
 * filled. (Since 1.0)
 *
 * #cairo_fill_rule_t is used to select how paths are filled. For both
 * fill rules, whether or not a point is included in the fill is
 * determined by taking a ray from that point to infinity and looking
 * at intersections with the path. The ray can be in any direction,
 * as long as it doesn't pass through the end point of a segment
 * or have a tricky intersection such as intersecting tangent to the path.
 * (Note that filling is not actually implemented in this way. This
 * is just a description of the rule that is applied.)
 *
 * The default fill rule is %CAIRO_FILL_RULE_WINDING.
 *
 * New entries may be added in future versions.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_set_fill_rule (cairo_t *cr, cairo_fill_rule_t fill_rule);"
  ),

  cairo_set_line_width <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_fill_rule_t:
 * @CAIRO_FILL_RULE_WINDING: If the path crosses the ray from
 * left-to-right, counts +1. If the path crosses the ray
 * from right to left, counts -1. (Left and right are determined
 * from the perspective of looking along the ray from the starting
 * point.) If the total count is non-zero, the point will be filled. (Since 1.0)
 * @CAIRO_FILL_RULE_EVEN_ODD: Counts the total number of
 * intersections, without regard to the orientation of the contour. If
 * the total number of intersections is odd, the point will be
 * filled. (Since 1.0)
 *
 * #cairo_fill_rule_t is used to select how paths are filled. For both
 * fill rules, whether or not a point is included in the fill is
 * determined by taking a ray from that point to infinity and looking
 * at intersections with the path. The ray can be in any direction,
 * as long as it doesn't pass through the end point of a segment
 * or have a tricky intersection such as intersecting tangent to the path.
 * (Note that filling is not actually implemented in this way. This
 * is just a description of the rule that is applied.)
 *
 * The default fill rule is %CAIRO_FILL_RULE_WINDING.
 *
 * New entries may be added in future versions.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_set_line_width (cairo_t *cr, double width)"
  ),


  cairo_stroke_preserve <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_stroke_preserve:
 * @cr: a cairo context
 *
 * A drawing operator that strokes the current path according to the
 * current line width, line join, line cap, and dash settings. Unlike
 * cairo_stroke(), cairo_stroke_preserve() preserves the path within the
 * cairo context.
 *
 * See cairo_set_line_width(), cairo_set_line_join(),
 * cairo_set_line_cap(), cairo_set_dash(), and
 * cairo_stroke_preserve().
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_stroke_preserve (cairo_t *cr)"
  ),


  cairo_fill <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_fill:
 * @cr: a cairo context
 *
 * A drawing operator that fills the current path according to the
 * current fill rule, (each sub-path is implicitly closed before being
 * filled). After cairo_fill(), the current path will be cleared from
 * the cairo context. See cairo_set_fill_rule() and
 * cairo_fill_preserve().
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_fill (cairo_t *cr)"
  ),


  cairo_arc <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_arc:
 * @cr: a cairo context
 * @xc: X position of the center of the arc
 * @yc: Y position of the center of the arc
 * @radius: the radius of the arc
 * @angle1: the start angle, in radians
 * @angle2: the end angle, in radians
 *
 * Adds a circular arc of the given @radius to the current path.  The
 * arc is centered at (@xc, @yc), begins at @angle1 and proceeds in
 * the direction of increasing angles to end at @angle2. If @angle2 is
 * less than @angle1 it will be progressively increased by
 * <literal>2*M_PI</literal> until it is greater than @angle1.
 *
 * If there is a current point, an initial line segment will be added
 * to the path to connect the current point to the beginning of the
 * arc. If this initial line is undesired, it can be avoided by
 * calling cairo_new_sub_path() before calling cairo_arc().
 *
 * Angles are measured in radians. An angle of 0.0 is in the direction
 * of the positive X axis (in user space). An angle of
 * <literal>M_PI/2.0</literal> radians (90 degrees) is in the
 * direction of the positive Y axis (in user space). Angles increase
 * in the direction from the positive X axis toward the positive Y
 * axis. So with the default transformation matrix, angles increase in
 * a clockwise direction.
 *
 * (To convert from degrees to radians, use <literal>degrees * (M_PI /
 * 180.)</literal>.)
 *
 * This function gives the arc in the direction of increasing angles;
 * see cairo_arc_negative() to get the arc in the direction of
 * decreasing angles.
 *
 * The arc is circular in user space. To achieve an elliptical arc,
 * you can scale the current transformation matrix by different
 * amounts in the X and Y directions. For example, to draw an ellipse
 * in the box given by @x, @y, @width, @height:
 *
 * <informalexample><programlisting>
 * cairo_save (cr);
 * cairo_translate (cr, x + width / 2., y + height / 2.);
 * cairo_scale (cr, width / 2., height / 2.);
 * cairo_arc (cr, 0., 0., 1., 0., 2 * M_PI);
 * cairo_restore (cr);
 * </programlisting></informalexample>
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_arc (cairo_t *cr,
	   double xc, double yc,
	   double radius,
	   double angle1, double angle2)"
  ),


  cairo_close_path <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_close_path:
 * @cr: a cairo context
 *
 * Adds a line segment to the path from the current point to the
 * beginning of the current sub-path, (the most recent point passed to
 * cairo_move_to()), and closes this sub-path. After this call the
 * current point will be at the joined endpoint of the sub-path.
 *
 * The behavior of cairo_close_path() is distinct from simply calling
 * cairo_line_to() with the equivalent coordinate in the case of
 * stroking. When a closed sub-path is stroked, there are no caps on
 * the ends of the sub-path. Instead, there is a line join connecting
 * the final and initial segments of the sub-path.
 *
 * If there is no current point before the call to cairo_close_path(),
 * this function will have no effect.
 *
 * Note: As of cairo version 1.2.4 any call to cairo_close_path() will
 * place an explicit MOVE_TO element into the path immediately after
 * the CLOSE_PATH element, (which can be seen in cairo_copy_path() for
 * example). This can simplify path processing in some cases as it may
 * not be necessary to save the "last move_to point" during processing
 * as the MOVE_TO immediately after the CLOSE_PATH will provide that
 * point.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_close_path (cairo_t *cr)"
  ),


  cairo_translate <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_translate:
 * @cr: a cairo context
 * @tx: amount to translate in the X direction
 * @ty: amount to translate in the Y direction
 *
 * Modifies the current transformation matrix (CTM) by translating the
 * user-space origin by (@tx, @ty). This offset is interpreted as a
 * user-space coordinate according to the CTM in place before the new
 * call to cairo_translate(). In other words, the translation of the
 * user-space origin takes place after any existing transformation.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_translate (cairo_t *cr, double tx, double ty)"
  ),


  cairo_scale <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_scale:
 * @cr: a cairo context
 * @sx: scale factor for the X dimension
 * @sy: scale factor for the Y dimension
 *
 * Modifies the current transformation matrix (CTM) by scaling the X
 * and Y user-space axes by @sx and @sy respectively. The scaling of
 * the axes takes place after any existing transformation of user
 * space.
 *
 * Since: 1.0
 **/}",
    proto_text = "void cairo_scale (cairo_t *cr, double sx, double sy)"
  ),

  cairo_set_source_rgba <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_set_source_rgba:
 * @cr: a cairo context
 * @red: red component of color
 * @green: green component of color
 * @blue: blue component of color
 * @alpha: alpha component of color
 *
 * Sets the source pattern within @cr to a translucent color. This
 * color will then be used for any subsequent drawing operation until
 * a new source pattern is set.
 *
 * The color and alpha components are floating point numbers in the
 * range 0 to 1. If the values passed in are outside that range, they
 * will be clamped.
 *
 * The default source pattern is opaque black, (that is, it is
 * equivalent to cairo_set_source_rgba(cr, 0.0, 0.0, 0.0, 1.0)).
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_set_source_rgba (cairo_t *cr,
		       double red, double green, double blue,
		       double alpha)"
  ),


  cairo_text_extents <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_text_extents:
 * @cr: a #cairo_t
 * @utf8: a NUL-terminated string of text encoded in UTF-8, or %NULL
 * @extents: a #cairo_text_extents_t object into which the results
 * will be stored
 *
 * Gets the extents for a string of text. The extents describe a
 * user-space rectangle that encloses the "inked" portion of the text,
 * (as it would be drawn by cairo_show_text()). Additionally, the
 * x_advance and y_advance values indicate the amount by which the
 * current point would be advanced by cairo_show_text().
 *
 * Note that whitespace characters do not directly contribute to the
 * size of the rectangle (extents.width and extents.height). They do
 * contribute indirectly by changing the position of non-whitespace
 * characters. In particular, trailing whitespace characters are
 * likely to not affect the size of the rectangle, though they will
 * affect the x_advance and y_advance values.
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_text_extents (cairo_t              *cr,
		    const char		 *utf8,
		    cairo_text_extents_t *extents)"
  ),



  cairo_paint_with_alpha <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_paint_with_alpha:
 * @cr: a cairo context
 * @alpha: alpha value, between 0 (transparent) and 1 (opaque)
 *
 * A drawing operator that paints the current source everywhere within
 * the current clip region using a mask of constant alpha value
 * @alpha. The effect is similar to cairo_paint(), but the drawing
 * is faded out using the alpha value.
 *
 * Since: 1.0
 **/}",
    proto_text = "void
cairo_paint_with_alpha (cairo_t *cr,
			double   alpha)"
  )


)





xxx <- list(
  include = TRUE,
  gtkdoc = r"{}",
  proto_text = ""
)





