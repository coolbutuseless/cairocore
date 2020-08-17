

cairo_font_face_header <- list(

  cairo_font_face_reference = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_font_face_reference:
    * @font_face: a #cairo_font_face_t, (may be %NULL in which case this
    * function does nothing).
    *
    * Increases the reference count on @font_face by one. This prevents
    * @font_face from being destroyed until a matching call to
    * cairo_font_face_destroy() is made.
    *
    * Use cairo_font_face_get_reference_count() to get the number of
    * references to a #cairo_font_face_t.
    *
    * Return value: the referenced #cairo_font_face_t.
    *
    * Since: 1.0
    **/}",
    proto_text = "cairo_font_face_t *
cairo_font_face_reference (cairo_font_face_t *font_face)"
  ),

  cairo_font_face_destroy = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_font_face_destroy:
    * @font_face: a #cairo_font_face_t
    *
    * Decreases the reference count on @font_face by one. If the result
    * is zero, then @font_face and all associated resources are freed.
    * See cairo_font_face_reference().
    *
    * Since: 1.0
    **/}",
    proto_text = "void
cairo_font_face_destroy (cairo_font_face_t *font_face)"
  ),

  cairo_font_face_get_type = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_font_face_get_type:
    * @font_face: a font face
    *
    * This function returns the type of the backend used to create
    * a font face. See #cairo_font_type_t for available types.
    *
    * Return value: The type of @font_face.
    *
    * Since: 1.2
    **/}",
    proto_text = "cairo_font_type_t
cairo_font_face_get_type (cairo_font_face_t *font_face)"
  ),

  cairo_font_face_get_reference_count = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_font_face_get_reference_count:
    * @font_face: a #cairo_font_face_t
    *
    * Returns the current reference count of @font_face.
    *
    * Return value: the current reference count of @font_face.  If the
    * object is a nil object, 0 will be returned.
    *
    * Since: 1.4
    **/}",
    proto_text = "unsigned int
cairo_font_face_get_reference_count (cairo_font_face_t *font_face)"
  ),

  cairo_font_face_status = list(
    include = TRUE,
    gtkdoc = r"{/**
    * cairo_font_face_status:
    * @font_face: a #cairo_font_face_t
    *
    * Checks whether an error has previously occurred for this
    * font face
    *
    * Return value: %CAIRO_STATUS_SUCCESS or another error such as
    *   %CAIRO_STATUS_NO_MEMORY.
    *
    * Since: 1.0
    **/}",
    proto_text = "cairo_status_t
cairo_font_face_status (cairo_font_face_t *font_face)"
  ),

  cairo_font_face_get_user_data = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_font_face_get_user_data:
    * @font_face: a #cairo_font_face_t
    * @key: the address of the #cairo_user_data_key_t the user data was
    * attached to
    *
    * Return user data previously attached to @font_face using the specified
    * key.  If no user data has been attached with the given key this
    * function returns %NULL.
    *
    * Return value: the user data previously attached or %NULL.
    *
    * Since: 1.0
    **/}",
    proto_text = "void *
cairo_font_face_get_user_data (cairo_font_face_t	   *font_face,
			       const cairo_user_data_key_t *key)"
  ),

  cairo_font_face_set_user_data = list(
    include = FALSE,
    gtkdoc = r"{/**
    * cairo_font_face_set_user_data:
    * @font_face: a #cairo_font_face_t
    * @key: the address of a #cairo_user_data_key_t to attach the user data to
    * @user_data: the user data to attach to the font face
    * @destroy: a #cairo_destroy_func_t which will be called when the
    * font face is destroyed or when new user data is attached using the
    * same key.
    *
    * Attach user data to @font_face.  To remove user data from a font face,
    * call this function with the key that was used to set it and %NULL
    * for @data.
    *
    * Return value: %CAIRO_STATUS_SUCCESS or %CAIRO_STATUS_NO_MEMORY if a
    * slot could not be allocated for the user data.
    *
    * Since: 1.0
    **/}",
    proto_text = "cairo_status_t
cairo_font_face_set_user_data (cairo_font_face_t	   *font_face,
			       const cairo_user_data_key_t *key,
			       void			   *user_data,
			       cairo_destroy_func_t	    destroy)"
  )
)

