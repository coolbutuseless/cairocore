

cairo_png_header <- list(

  cairo_surface_write_to_png <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_surface_write_to_png:
 * @surface: a #cairo_surface_t with pixel contents
 * @filename: the name of a file to write to; on Windows this filename
 *   is encoded in UTF-8.
 *
 * Writes the contents of @surface to a new file @filename as a PNG
 * image.
 *
 * Return value: %CAIRO_STATUS_SUCCESS if the PNG file was written
 * successfully. Otherwise, %CAIRO_STATUS_NO_MEMORY if memory could not
 * be allocated for the operation or
 * %CAIRO_STATUS_SURFACE_TYPE_MISMATCH if the surface does not have
 * pixel contents, or %CAIRO_STATUS_WRITE_ERROR if an I/O error occurs
 * while attempting to write the file, or %CAIRO_STATUS_PNG_ERROR if libpng
 * returned an error.
 *
 * Since: 1.0
 **/}",
    proto_text = "cairo_status_t cairo_surface_write_to_png (cairo_surface_t	*surface,
			    const char		*filename)"
  ),


  cairo_image_surface_create_from_png <- list(
    include = TRUE,
    gtkdoc = r"{/**
 * cairo_image_surface_create_from_png:
 * @filename: name of PNG file to load. On Windows this filename
 *   is encoded in UTF-8.
 *
 * Creates a new image surface and initializes the contents to the
 * given PNG file.
 *
 * Return value: a new #cairo_surface_t initialized with the contents
 * of the PNG file, or a "nil" surface if any error occurred. A nil
 * surface can be checked for with cairo_surface_status(surface) which
 * may return one of the following values:
 *
 *	%CAIRO_STATUS_NO_MEMORY
 *	%CAIRO_STATUS_FILE_NOT_FOUND
 *	%CAIRO_STATUS_READ_ERROR
 *	%CAIRO_STATUS_PNG_ERROR
 *
 * Alternatively, you can allow errors to propagate through the drawing
 * operations and check the status on the context upon completion
 * using cairo_status().
 *
 * Since: 1.0
 **/}",
    proto_text = "cairo_surface_t * cairo_image_surface_create_from_png (const char *filename)"
  )

)





xxx <- list(
  include = TRUE,
  gtkdoc = r"{}",
  proto_text = ""
)
