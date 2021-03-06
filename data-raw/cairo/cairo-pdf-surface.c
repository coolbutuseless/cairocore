

/**
 * cairo_pdf_surface_create_for_stream:
 * @write_func: a #cairo_write_func_t to accept the output data, may be %NULL
 *              to indicate a no-op @write_func. With a no-op @write_func,
 *              the surface may be queried or used as a source without
 *              generating any temporary files.
 * @closure: the closure argument for @write_func
 * @width_in_points: width of the surface, in points (1 point == 1/72.0 inch)
 * @height_in_points: height of the surface, in points (1 point == 1/72.0 inch)
 *
 * Creates a PDF surface of the specified size in points to be written
 * incrementally to the stream represented by @write_func and @closure.
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
 **/
cairo_surface_t *
cairo_pdf_surface_create_for_stream (cairo_write_func_t		 write_func,
				     void			*closure,
				     double			 width_in_points,
				     double			 height_in_points)
{
    cairo_output_stream_t *output;

    output = _cairo_output_stream_create (write_func, NULL, closure);
    if (_cairo_output_stream_get_status (output))
	return _cairo_surface_create_in_error (_cairo_output_stream_destroy (output));

    return _cairo_pdf_surface_create_for_stream_internal (output,
							  width_in_points,
							  height_in_points);
}

/**
 * cairo_pdf_surface_create:
 * @filename: a filename for the PDF output (must be writable), %NULL may be
 *            used to specify no output. This will generate a PDF surface that
 *            may be queried and used as a source, without generating a
 *            temporary file.
 * @width_in_points: width of the surface, in points (1 point == 1/72.0 inch)
 * @height_in_points: height of the surface, in points (1 point == 1/72.0 inch)
 *
 * Creates a PDF surface of the specified size in points to be written
 * to @filename.
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
 **/
cairo_surface_t *
cairo_pdf_surface_create (const char		*filename,
			  double		 width_in_points,
			  double		 height_in_points)
{
    cairo_output_stream_t *output;

    output = _cairo_output_stream_create_for_filename (filename);
    if (_cairo_output_stream_get_status (output))
	return _cairo_surface_create_in_error (_cairo_output_stream_destroy (output));

    return _cairo_pdf_surface_create_for_stream_internal (output,
							  width_in_points,
							  height_in_points);
}

static cairo_bool_t
_cairo_surface_is_pdf (cairo_surface_t *surface)
{
    return surface->backend == &cairo_pdf_surface_backend;
}


/**
 * cairo_pdf_surface_restrict_to_version:
 * @surface: a PDF #cairo_surface_t
 * @version: PDF version
 *
 * Restricts the generated PDF file to @version. See cairo_pdf_get_versions()
 * for a list of available version values that can be used here.
 *
 * This function should only be called before any drawing operations
 * have been performed on the given surface. The simplest way to do
 * this is to call this function immediately after creating the
 * surface.
 *
 * Since: 1.10
 **/
void
cairo_pdf_surface_restrict_to_version (cairo_surface_t 		*abstract_surface,
				       cairo_pdf_version_t  	 version)
{
    cairo_pdf_surface_t *surface = NULL; /* hide compiler warning */

    if (! _extract_pdf_surface (abstract_surface, &surface))
	return;

    if (version < CAIRO_PDF_VERSION_LAST)
	surface->pdf_version = version;

    _cairo_pdf_operators_enable_actual_text(&surface->pdf_operators,
					    version >= CAIRO_PDF_VERSION_1_5);
}

/**
 * cairo_pdf_get_versions:
 * @versions: supported version list
 * @num_versions: list length
 *
 * Used to retrieve the list of supported versions. See
 * cairo_pdf_surface_restrict_to_version().
 *
 * Since: 1.10
 **/
void
cairo_pdf_get_versions (cairo_pdf_version_t const	**versions,
                        int                     	 *num_versions)
{
    if (versions != NULL)
	*versions = _cairo_pdf_versions;

    if (num_versions != NULL)
	*num_versions = CAIRO_PDF_VERSION_LAST;
}

/**
 * cairo_pdf_version_to_string:
 * @version: a version id
 *
 * Get the string representation of the given @version id. This function
 * will return %NULL if @version isn't valid. See cairo_pdf_get_versions()
 * for a way to get the list of valid version ids.
 *
 * Return value: the string associated to given version.
 *
 * Since: 1.10
 **/
const char *
cairo_pdf_version_to_string (cairo_pdf_version_t version)
{
    if (version >= CAIRO_PDF_VERSION_LAST)
	return NULL;

    return _cairo_pdf_version_strings[version];
}

/**
 * cairo_pdf_surface_set_size:
 * @surface: a PDF #cairo_surface_t
 * @width_in_points: new surface width, in points (1 point == 1/72.0 inch)
 * @height_in_points: new surface height, in points (1 point == 1/72.0 inch)
 *
 * Changes the size of a PDF surface for the current (and
 * subsequent) pages.
 *
 * This function should only be called before any drawing operations
 * have been performed on the current page. The simplest way to do
 * this is to call this function immediately after creating the
 * surface or immediately after completing a page with either
 * cairo_show_page() or cairo_copy_page().
 *
 * Since: 1.2
 **/
void
cairo_pdf_surface_set_size (cairo_surface_t	*surface,
			    double		 width_in_points,
			    double		 height_in_points)
{
    cairo_pdf_surface_t *pdf_surface = NULL; /* hide compiler warning */
    cairo_status_t status;

    if (! _extract_pdf_surface (surface, &pdf_surface))
	return;

    _cairo_pdf_surface_set_size_internal (pdf_surface,
					  width_in_points,
					  height_in_points);
    status = _cairo_paginated_surface_set_size (pdf_surface->paginated_surface,
						width_in_points,
						height_in_points);
    if (status)
	status = _cairo_surface_set_error (surface, status);
}

/**
 * CAIRO_PDF_OUTLINE_ROOT:
 *
 * The root outline item in cairo_pdf_surface_add_outline().
 *
 * Since: 1.16
 **/

/**
 * cairo_pdf_surface_add_outline:
 * @surface: a PDF #cairo_surface_t
 * @parent_id: the id of the parent item or %CAIRO_PDF_OUTLINE_ROOT if this is a top level item.
 * @utf8: the name of the outline
 * @link_attribs: the link attributes specifying where this outline links to
 * @flags: outline item flags
 *
 * Add an item to the document outline hierarchy with the name @utf8
 * that links to the location specified by @link_attribs. Link
 * attributes have the same keys and values as the [Link Tag][link],
 * excluding the "rect" attribute. The item will be a child of the
 * item with id @parent_id. Use %CAIRO_PDF_OUTLINE_ROOT as the parent
 * id of top level items.
 *
 * Return value: the id for the added item.
 *
 * Since: 1.16
 **/
int
cairo_pdf_surface_add_outline (cairo_surface_t	         *surface,
			       int                        parent_id,
			       const char                *utf8,
			       const char                *link_attribs,
			       cairo_pdf_outline_flags_t  flags)
{
    cairo_pdf_surface_t *pdf_surface = NULL; /* hide compiler warning */
    cairo_status_t status;
    int id = 0;

    if (! _extract_pdf_surface (surface, &pdf_surface))
	return 0;

    status = _cairo_pdf_interchange_add_outline (pdf_surface,
						 parent_id,
						 utf8,
						 link_attribs,
						 flags,
						 &id);
    if (status)
	status = _cairo_surface_set_error (surface, status);

    return id;
}

/**
 * cairo_pdf_surface_set_metadata:
 * @surface: a PDF #cairo_surface_t
 * @metadata: The metadata item to set.
 * @utf8: metadata value
 *
 * Set document metadata. The %CAIRO_PDF_METADATA_CREATE_DATE and
 * %CAIRO_PDF_METADATA_MOD_DATE values must be in ISO-8601 format:
 * YYYY-MM-DDThh:mm:ss. An optional timezone of the form "[+/-]hh:mm"
 * or "Z" for UTC time can be appended. All other metadata values can be any UTF-8
 * string.
 *
 * For example:
 * <informalexample><programlisting>
 * cairo_pdf_surface_set_metadata (surface, CAIRO_PDF_METADATA_TITLE, "My Document");
 * cairo_pdf_surface_set_metadata (surface, CAIRO_PDF_METADATA_CREATE_DATE, "2015-12-31T23:59+02:00");
 * </programlisting></informalexample>
 *
 * Since: 1.16
 **/
void
cairo_pdf_surface_set_metadata (cairo_surface_t      *surface,
				cairo_pdf_metadata_t  metadata,
                                const char           *utf8)
{
    cairo_pdf_surface_t *pdf_surface = NULL; /* hide compiler warning */
    cairo_status_t status;

    if (! _extract_pdf_surface (surface, &pdf_surface))
	return;

    status = _cairo_pdf_interchange_set_metadata (pdf_surface, metadata, utf8);
    if (status)
	status = _cairo_surface_set_error (surface, status);
}

/**
 * cairo_pdf_surface_set_page_label:
 * @surface: a PDF #cairo_surface_t
 * @utf8: The page label.
 *
 * Set page label for the current page.
 *
 * Since: 1.16
 **/
void
cairo_pdf_surface_set_page_label (cairo_surface_t *surface,
                                  const char      *utf8)
{
    cairo_pdf_surface_t *pdf_surface = NULL; /* hide compiler warning */

    if (! _extract_pdf_surface (surface, &pdf_surface))
	return;

    free (pdf_surface->current_page_label);
    pdf_surface->current_page_label = utf8 ? strdup (utf8) : NULL;
}

/**
 * cairo_pdf_surface_set_thumbnail_size:
 * @surface: a PDF #cairo_surface_t
 * @width: Thumbnail width.
 * @height: Thumbnail height
 *
 * Set the thumbnail image size for the current and all subsequent
 * pages. Setting a width or height of 0 disables thumbnails for the
 * current and subsequent pages.
 *
 * Since: 1.16
 **/
void
cairo_pdf_surface_set_thumbnail_size (cairo_surface_t *surface,
				      int              width,
				      int              height)
{
    cairo_pdf_surface_t *pdf_surface = NULL; /* hide compiler warning */

    if (! _extract_pdf_surface (surface, &pdf_surface))
	return;

    pdf_surface->thumbnail_width = width;
    pdf_surface->thumbnail_height = height;
}


