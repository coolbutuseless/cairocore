

cairo_ps_header <- list(



  cairo_ps_surface_create = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_surface_create:
    * @filename: a filename for the PS output (must be writable), %NULL may be
    *            used to specify no output. This will generate a PS surface that
    *            may be queried and used as a source, without generating a
    *            temporary file.
    * @width_in_points: width of the surface, in points (1 point == 1/72.0 inch)
    * @height_in_points: height of the surface, in points (1 point == 1/72.0 inch)
    *
    * Creates a PostScript surface of the specified size in points to be
    * written to @filename. See cairo_ps_surface_create_for_stream() for
    * a more flexible mechanism for handling the PostScript output than
    * simply writing it to a named file.
    *
    * Note that the size of individual pages of the PostScript output can
    * vary. See cairo_ps_surface_set_size().
    *
    * Return value: a pointer to the newly created surface. The caller
    * owns the surface and should call cairo_surface_destroy() when done
    * with it.
    *
    * This function always returns a valid pointer, but it will return a
    * pointer to a "nil" surface if an error such as out of memory
    * occurs. You can use cairo_surface_status() to check for this.
    *
    * Since: 1.2
    **/}",
    proto_text = "cairo_surface_t * cairo_ps_surface_create (const char		*filename, double			 width_in_points,
			 double			 height_in_points)"
  ),


  cairo_ps_surface_create_for_stream = list(
    include = FALSE,
    gtkdoc = r"{/**
 * cairo_ps_surface_create_for_stream:
 * @write_func: a #cairo_write_func_t to accept the output data, may be %NULL
 *              to indicate a no-op @write_func. With a no-op @write_func,
 *              the surface may be queried or used as a source without
 *              generating any temporary files.
 * @closure: the closure argument for @write_func
 * @width_in_points: width of the surface, in points (1 point == 1/72.0 inch)
 * @height_in_points: height of the surface, in points (1 point == 1/72.0 inch)
 *
 * Creates a PostScript surface of the specified size in points to be
 * written incrementally to the stream represented by @write_func and
 * @closure. See cairo_ps_surface_create() for a more convenient way
 * to simply direct the PostScript output to a named file.
 *
 * Note that the size of individual pages of the PostScript
 * output can vary. See cairo_ps_surface_set_size().
 *
 * Return value: a pointer to the newly created surface. The caller
 * owns the surface and should call cairo_surface_destroy() when done
 * with it.
 *
 * This function always returns a valid pointer, but it will return a
 * pointer to a "nil" surface if an error such as out of memory
 * occurs. You can use cairo_surface_status() to check for this.
 *
 * Since: 1.2
 **/}",
    proto_text = "cairo_surface_t *
cairo_ps_surface_create_for_stream (cairo_write_func_t	write_func,
				    void	       *closure,
				    double		width_in_points,
				    double		height_in_points)"
  ),



  cairo_ps_surface_restrict_to_level = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_surface_restrict_to_level:
    * @surface: a PostScript #cairo_surface_t
    * @level: PostScript level
    *
    * Restricts the generated PostSript file to @level. See
    * cairo_ps_get_levels() for a list of available level values that
    * can be used here.
    *
    * This function should only be called before any drawing operations
    * have been performed on the given surface. The simplest way to do
    * this is to call this function immediately after creating the
    * surface.
    *
    * Since: 1.6
    **/}",
    proto_text = "void cairo_ps_surface_restrict_to_level (cairo_surface_t  *surface, cairo_ps_level_t  level)"
  ),


  cairo_ps_get_levels = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_ps_get_levels:
    * @levels: supported level list
    * @num_levels: list length
    *
    * Used to retrieve the list of supported levels. See
    * cairo_ps_surface_restrict_to_level().
    *
    * Since: 1.6
    **/}",
    proto_text = "void cairo_ps_get_levels (cairo_ps_level_t const	**levels, int *num_levels)"
  ),


  cairo_ps_level_to_string = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_level_to_string:
    * @level: a level id
    *
    * Get the string representation of the given @level id. This function
    * will return %NULL if @level id isn't valid. See cairo_ps_get_levels()
    * for a way to get the list of valid level ids.
    *
    * Return value: the string associated to given level.
    *
    * Since: 1.6
    **/}",
    proto_text = "const char * cairo_ps_level_to_string (cairo_ps_level_t level)"
  ),


  cairo_ps_surface_set_eps = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_surface_set_eps:
    * @surface: a PostScript #cairo_surface_t
    * @eps: %TRUE to output EPS format PostScript
    *
    * If @eps is %TRUE, the PostScript surface will output Encapsulated
    * PostScript.
    *
    * This function should only be called before any drawing operations
    * have been performed on the current page. The simplest way to do
    * this is to call this function immediately after creating the
    * surface. An Encapsulated PostScript file should never contain more
    * than one page.
    *
    * Since: 1.6
    **/}",
    proto_text = "void cairo_ps_surface_set_eps (cairo_surface_t	*surface, cairo_bool_t           eps)"
  ),


  cairo_ps_surface_get_eps = list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_ps_surface_get_eps:
 * @surface: a PostScript #cairo_surface_t
 *
 * Check whether the PostScript surface will output Encapsulated PostScript.
 *
 * Return value: %TRUE if the surface will output Encapsulated PostScript.
 *
 * Since: 1.6
 **/}",
    proto_text = "cairo_public cairo_bool_t
cairo_ps_surface_get_eps (cairo_surface_t	*surface)"
  ),


  cairo_ps_surface_set_size = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_surface_set_size:
    * @surface: a PostScript #cairo_surface_t
    * @width_in_points: new surface width, in points (1 point == 1/72.0 inch)
    * @height_in_points: new surface height, in points (1 point == 1/72.0 inch)
    *
    * Changes the size of a PostScript surface for the current (and
    * subsequent) pages.
    *
    * This function should only be called before any drawing operations
    * have been performed on the current page. The simplest way to do
    * this is to call this function immediately after creating the
    * surface or immediately after completing a page with either
    * cairo_show_page() or cairo_copy_page().
    *
    * Since: 1.2
    **/}",
    proto_text = "void cairo_ps_surface_set_size (cairo_surface_t	*surface, double width_in_points, double height_in_points)"
  ),

  cairo_ps_surface_dsc_comment = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_ps_surface_dsc_comment:
    * @surface: a PostScript #cairo_surface_t
    * @comment: a comment string to be emitted into the PostScript output
    *
    * Emit a comment into the PostScript output for the given surface.
    *
    * The comment is expected to conform to the PostScript Language
    * Document Structuring Conventions (DSC). Please see that manual for
    * details on the available comments and their meanings. In
    * particular, the \%\%IncludeFeature comment allows a
    * device-independent means of controlling printer device features. So
    * the PostScript Printer Description Files Specification will also be
    * a useful reference.
    *
    * The comment string must begin with a percent character (\%) and the
    * total length of the string (including any initial percent
    * characters) must not exceed 255 characters. Violating either of
    * these conditions will place @surface into an error state. But
    * beyond these two conditions, this function will not enforce
    * conformance of the comment with any particular specification.
    *
    * The comment string should not have a trailing newline.
    *
    * The DSC specifies different sections in which particular comments
    * can appear. This function provides for comments to be emitted
    * within three sections: the header, the Setup section, and the
    * PageSetup section.  Comments appearing in the first two sections
    * apply to the entire document while comments in the BeginPageSetup
    * section apply only to a single page.
    *
    * For comments to appear in the header section, this function should
    * be called after the surface is created, but before a call to
    * cairo_ps_surface_dsc_begin_setup().
    *
    * For comments to appear in the Setup section, this function should
    * be called after a call to cairo_ps_surface_dsc_begin_setup() but
    * before a call to cairo_ps_surface_dsc_begin_page_setup().
    *
    * For comments to appear in the PageSetup section, this function
    * should be called after a call to
    * cairo_ps_surface_dsc_begin_page_setup().
    *
    * Note that it is only necessary to call
    * cairo_ps_surface_dsc_begin_page_setup() for the first page of any
    * surface. After a call to cairo_show_page() or cairo_copy_page()
    * comments are unambiguously directed to the PageSetup section of the
    * current page. But it doesn't hurt to call this function at the
    * beginning of every page as that consistency may make the calling
    * code simpler.
    *
    * As a final note, cairo automatically generates several comments on
    * its own. As such, applications must not manually generate any of
    * the following comments:
    *
    * Header section: \%!PS-Adobe-3.0, \%\%Creator, \%\%CreationDate, \%\%Pages,
    * \%\%BoundingBox, \%\%DocumentData, \%\%LanguageLevel, \%\%EndComments.
    *
    * Setup section: \%\%BeginSetup, \%\%EndSetup
    *
    * PageSetup section: \%\%BeginPageSetup, \%\%PageBoundingBox, \%\%EndPageSetup.
    *
    * Other sections: \%\%BeginProlog, \%\%EndProlog, \%\%Page, \%\%Trailer, \%\%EOF
    *
    * Here is an example sequence showing how this function might be used:
    *
    * <informalexample><programlisting>
    * cairo_surface_t *surface = cairo_ps_surface_create (filename, width, height);
    * ...
    * cairo_ps_surface_dsc_comment (surface, "%%Title: My excellent document");
    * cairo_ps_surface_dsc_comment (surface, "%%Copyright: Copyright (C) 2006 Cairo Lover")
    * ...
    * cairo_ps_surface_dsc_begin_setup (surface);
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *MediaColor White");
    * ...
    * cairo_ps_surface_dsc_begin_page_setup (surface);
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *PageSize A3");
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *InputSlot LargeCapacity");
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *MediaType Glossy");
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *MediaColor Blue");
    * ... draw to first page here ..
    * cairo_show_page (cr);
    * ...
    * cairo_ps_surface_dsc_comment (surface, "%%IncludeFeature: *PageSize A5");
    * ...
    * </programlisting></informalexample>
    *
    * Since: 1.2
    **/}",
    proto_text = "void cairo_ps_surface_dsc_comment (cairo_surface_t	*surface, const char	*comment)"
  ),

  cairo_ps_surface_dsc_begin_setup = list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_ps_surface_dsc_begin_setup:
 * @surface: a PostScript #cairo_surface_t
 *
 * This function indicates that subsequent calls to
 * cairo_ps_surface_dsc_comment() should direct comments to the Setup
 * section of the PostScript output.
 *
 * This function should be called at most once per surface, and must
 * be called before any call to cairo_ps_surface_dsc_begin_page_setup()
 * and before any drawing is performed to the surface.
 *
 * See cairo_ps_surface_dsc_comment() for more details.
 *
 * Since: 1.2
 **/}",
    proto_text = "void
cairo_ps_surface_dsc_begin_setup (cairo_surface_t *surface)"
  ),

  cairo_ps_surface_dsc_begin_page_setup = list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_ps_surface_dsc_begin_page_setup:
 * @surface: a PostScript #cairo_surface_t
 *
 * This function indicates that subsequent calls to
 * cairo_ps_surface_dsc_comment() should direct comments to the
 * PageSetup section of the PostScript output.
 *
 * This function call is only needed for the first page of a
 * surface. It should be called after any call to
 * cairo_ps_surface_dsc_begin_setup() and before any drawing is
 * performed to the surface.
 *
 * See cairo_ps_surface_dsc_comment() for more details.
 *
 * Since: 1.2
 **/}",
    proto_text = "void
cairo_ps_surface_dsc_begin_page_setup (cairo_surface_t *surface)"
  )
)


xxx = list(
  include = TRUE,
  gtkdoc = r"{}",
  proto_text = ""
)

