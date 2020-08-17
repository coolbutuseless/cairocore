
// #define R_NO_REMAP
#include <R.h>
#include <Rinternals.h>

// R wrappers for raw values
extern SEXP cairo_image_surface_get_array_();
extern SEXP cairo_image_surface_get_raw_();
extern SEXP cairo_image_surface_write_array_();

// Bespoke: cairo
extern SEXP cairo_arc_vec_();
extern SEXP cairo_rectangle_vec_();
extern SEXP cairo_segment_vec_();
extern SEXP cairo_polygon_vec_();

extern SEXP cairo_text_extents_t_();
extern SEXP cairo_text_extents_t_to_list_();
extern SEXP cairo_font_extents_t_();
extern SEXP cairo_font_extents_t_to_list_();

extern SEXP cairo_polygon_();
extern SEXP cairo_polyline_();

// Cairo - structs
extern SEXP cairo_matrix_t_();
extern SEXP cairo_matrix_t_to_list_();
extern SEXP cairo_matrix_t_update_();

extern SEXP cairo_rectangle_t_();
extern SEXP cairo_rectangle_t_to_list_();

extern SEXP cairo_rectangle_int_t_();


// ---- begin auto-generated externs ----
// cairo-font-face
extern SEXP cairo_font_face_get_type_();
extern SEXP cairo_font_face_status_();

// cairo-font-options
extern SEXP cairo_font_options_create_();
extern SEXP cairo_font_options_copy_();
extern SEXP cairo_font_options_status_();
extern SEXP cairo_font_options_merge_();
extern SEXP cairo_font_options_equal_();
extern SEXP cairo_font_options_hash_();
extern SEXP cairo_font_options_set_antialias_();
extern SEXP cairo_font_options_get_antialias_();
extern SEXP cairo_font_options_set_subpixel_order_();
extern SEXP cairo_font_options_get_subpixel_order_();
extern SEXP cairo_font_options_set_hint_style_();
extern SEXP cairo_font_options_get_hint_style_();
extern SEXP cairo_font_options_set_hint_metrics_();
extern SEXP cairo_font_options_get_hint_metrics_();
extern SEXP cairo_font_options_set_variations_();
extern SEXP cairo_font_options_get_variations_();

// cairo--
extern SEXP cairo_create_();
extern SEXP cairo_save_();
extern SEXP cairo_restore_();
extern SEXP cairo_push_group_();
extern SEXP cairo_push_group_with_content_();
extern SEXP cairo_pop_group_();
extern SEXP cairo_pop_group_to_source_();
extern SEXP cairo_set_operator_();
extern SEXP cairo_set_source_rgb_();
extern SEXP cairo_set_source_rgba_();
extern SEXP cairo_set_source_surface_();
extern SEXP cairo_set_source_();
extern SEXP cairo_get_source_();
extern SEXP cairo_set_tolerance_();
extern SEXP cairo_set_antialias_();
extern SEXP cairo_set_fill_rule_();
extern SEXP cairo_set_line_width_();
extern SEXP cairo_set_line_cap_();
extern SEXP cairo_set_line_join_();
extern SEXP cairo_set_dash_();
extern SEXP cairo_get_dash_count_();
extern SEXP cairo_get_dash_();
extern SEXP cairo_set_miter_limit_();
extern SEXP cairo_translate_();
extern SEXP cairo_scale_();
extern SEXP cairo_rotate_();
extern SEXP cairo_transform_();
extern SEXP cairo_set_matrix_();
extern SEXP cairo_identity_matrix_();
extern SEXP cairo_user_to_device_();
extern SEXP cairo_user_to_device_distance_();
extern SEXP cairo_device_to_user_();
extern SEXP cairo_device_to_user_distance_();
extern SEXP cairo_new_path_();
extern SEXP cairo_new_sub_path_();
extern SEXP cairo_move_to_();
extern SEXP cairo_line_to_();
extern SEXP cairo_curve_to_();
extern SEXP cairo_arc_();
extern SEXP cairo_arc_negative_();
extern SEXP cairo_rel_move_to_();
extern SEXP cairo_rel_line_to_();
extern SEXP cairo_rel_curve_to_();
extern SEXP cairo_rectangle_();
extern SEXP cairo_close_path_();
extern SEXP cairo_path_extents_();
extern SEXP cairo_paint_();
extern SEXP cairo_paint_with_alpha_();
extern SEXP cairo_mask_();
extern SEXP cairo_mask_surface_();
extern SEXP cairo_stroke_();
extern SEXP cairo_stroke_preserve_();
extern SEXP cairo_fill_();
extern SEXP cairo_fill_preserve_();
extern SEXP cairo_copy_page_();
extern SEXP cairo_show_page_();
extern SEXP cairo_in_stroke_();
extern SEXP cairo_in_fill_();
extern SEXP cairo_stroke_extents_();
extern SEXP cairo_fill_extents_();
extern SEXP cairo_clip_();
extern SEXP cairo_clip_preserve_();
extern SEXP cairo_reset_clip_();
extern SEXP cairo_clip_extents_();
extern SEXP cairo_in_clip_();
extern SEXP cairo_tag_begin_();
extern SEXP cairo_tag_end_();
extern SEXP cairo_select_font_face_();
extern SEXP cairo_font_extents_();
extern SEXP cairo_set_font_face_();
extern SEXP cairo_get_font_face_();
extern SEXP cairo_set_font_size_();
extern SEXP cairo_set_font_matrix_();
extern SEXP cairo_get_font_matrix_();
extern SEXP cairo_text_extents_();
extern SEXP cairo_show_text_();
extern SEXP cairo_text_path_();
extern SEXP cairo_get_operator_();
extern SEXP cairo_get_tolerance_();
extern SEXP cairo_get_antialias_();
extern SEXP cairo_has_current_point_();
extern SEXP cairo_get_current_point_();
extern SEXP cairo_get_fill_rule_();
extern SEXP cairo_get_line_width_();
extern SEXP cairo_get_line_cap_();
extern SEXP cairo_get_line_join_();
extern SEXP cairo_get_miter_limit_();
extern SEXP cairo_get_matrix_();
extern SEXP cairo_get_target_();
extern SEXP cairo_get_group_target_();
extern SEXP cairo_copy_path_();
extern SEXP cairo_copy_path_flat_();
extern SEXP cairo_append_path_();
extern SEXP cairo_status_();

// cairo-image-surface
extern SEXP cairo_image_surface_create_();
extern SEXP cairo_format_stride_for_width_();
extern SEXP cairo_image_surface_create_for_data_();
extern SEXP cairo_image_surface_get_data_();
extern SEXP cairo_image_surface_get_format_();
extern SEXP cairo_image_surface_get_width_();
extern SEXP cairo_image_surface_get_height_();
extern SEXP cairo_image_surface_get_stride_();

// cairo-matrix
extern SEXP cairo_matrix_init_();
extern SEXP cairo_matrix_init_translate_();
extern SEXP cairo_matrix_translate_();
extern SEXP cairo_matrix_init_scale_();
extern SEXP cairo_matrix_scale_();
extern SEXP cairo_matrix_init_rotate_();
extern SEXP cairo_matrix_rotate_();
extern SEXP cairo_matrix_multiply_();
extern SEXP cairo_matrix_transform_distance_();
extern SEXP cairo_matrix_transform_point_();
extern SEXP cairo_matrix_invert_();

// cairo-pattern
extern SEXP cairo_pattern_create_rgb_();
extern SEXP cairo_pattern_create_rgba_();
extern SEXP cairo_pattern_create_for_surface_();
extern SEXP cairo_pattern_create_linear_();
extern SEXP cairo_pattern_create_radial_();
extern SEXP cairo_pattern_create_mesh_();
extern SEXP cairo_pattern_get_type_();
extern SEXP cairo_pattern_status_();
extern SEXP cairo_mesh_pattern_begin_patch_();
extern SEXP cairo_mesh_pattern_end_patch_();
extern SEXP cairo_mesh_pattern_curve_to_();
extern SEXP cairo_mesh_pattern_line_to_();
extern SEXP cairo_mesh_pattern_move_to_();
extern SEXP cairo_mesh_pattern_set_control_point_();
extern SEXP cairo_mesh_pattern_set_corner_color_rgb_();
extern SEXP cairo_mesh_pattern_set_corner_color_rgba_();
extern SEXP cairo_pattern_add_color_stop_rgb_();
extern SEXP cairo_pattern_add_color_stop_rgba_();
extern SEXP cairo_pattern_set_matrix_();
extern SEXP cairo_pattern_get_matrix_();
extern SEXP cairo_pattern_set_filter_();
extern SEXP cairo_pattern_get_filter_();
extern SEXP cairo_pattern_set_extend_();
extern SEXP cairo_pattern_get_extend_();
extern SEXP cairo_pattern_get_rgba_();
extern SEXP cairo_pattern_get_color_stop_rgba_();
extern SEXP cairo_pattern_get_color_stop_count_();
extern SEXP cairo_pattern_get_linear_points_();
extern SEXP cairo_pattern_get_radial_circles_();
extern SEXP cairo_mesh_pattern_get_patch_count_();
extern SEXP cairo_mesh_pattern_get_path_();
extern SEXP cairo_mesh_pattern_get_corner_color_rgba_();
extern SEXP cairo_mesh_pattern_get_control_point_();

// cairo-pdf-surface
extern SEXP cairo_pdf_surface_create_();
extern SEXP cairo_pdf_surface_restrict_to_version_();
extern SEXP cairo_pdf_version_to_string_();
extern SEXP cairo_pdf_surface_set_size_();
extern SEXP cairo_pdf_surface_add_outline_();
extern SEXP cairo_pdf_surface_set_metadata_();
extern SEXP cairo_pdf_surface_set_page_label_();
extern SEXP cairo_pdf_surface_set_thumbnail_size_();

// cairo-png
extern SEXP cairo_surface_write_to_png_();
extern SEXP cairo_image_surface_create_from_png_();

// cairo-ps
extern SEXP cairo_ps_surface_create_();
extern SEXP cairo_ps_surface_restrict_to_level_();
extern SEXP cairo_ps_level_to_string_();
extern SEXP cairo_ps_surface_set_eps_();
extern SEXP cairo_ps_surface_get_eps_();
extern SEXP cairo_ps_surface_set_size_();
extern SEXP cairo_ps_surface_dsc_comment_();
extern SEXP cairo_ps_surface_dsc_begin_setup_();
extern SEXP cairo_ps_surface_dsc_begin_page_setup_();

// cairo-surface
extern SEXP cairo_surface_finish_();
extern SEXP cairo_surface_flush_();

// cairo-surface-subsurface
extern SEXP cairo_surface_create_for_rectangle_();

// cairo-svg-surface
extern SEXP cairo_svg_surface_create_();
extern SEXP cairo_svg_surface_restrict_to_version_();
extern SEXP cairo_svg_version_to_string_();
extern SEXP cairo_svg_surface_set_document_unit_();
extern SEXP cairo_svg_surface_get_document_unit_();

// ---- end auto-generated externs ----



static const R_CallMethodDef CEntries[] = {

  // ---- begin auto-generated callmethoddefs ----
  // cairo-font-face
  {"cairo_font_face_get_type_", (DL_FUNC) &cairo_font_face_get_type_, 1},
  {"cairo_font_face_status_", (DL_FUNC) &cairo_font_face_status_, 1},

  // cairo-font-options
  {"cairo_font_options_create_", (DL_FUNC) &cairo_font_options_create_, 0},
  {"cairo_font_options_copy_", (DL_FUNC) &cairo_font_options_copy_, 1},
  {"cairo_font_options_status_", (DL_FUNC) &cairo_font_options_status_, 1},
  {"cairo_font_options_merge_", (DL_FUNC) &cairo_font_options_merge_, 2},
  {"cairo_font_options_equal_", (DL_FUNC) &cairo_font_options_equal_, 2},
  {"cairo_font_options_hash_", (DL_FUNC) &cairo_font_options_hash_, 1},
  {"cairo_font_options_set_antialias_", (DL_FUNC) &cairo_font_options_set_antialias_, 2},
  {"cairo_font_options_get_antialias_", (DL_FUNC) &cairo_font_options_get_antialias_, 1},
  {"cairo_font_options_set_subpixel_order_", (DL_FUNC) &cairo_font_options_set_subpixel_order_, 2},
  {"cairo_font_options_get_subpixel_order_", (DL_FUNC) &cairo_font_options_get_subpixel_order_, 1},
  {"cairo_font_options_set_hint_style_", (DL_FUNC) &cairo_font_options_set_hint_style_, 2},
  {"cairo_font_options_get_hint_style_", (DL_FUNC) &cairo_font_options_get_hint_style_, 1},
  {"cairo_font_options_set_hint_metrics_", (DL_FUNC) &cairo_font_options_set_hint_metrics_, 2},
  {"cairo_font_options_get_hint_metrics_", (DL_FUNC) &cairo_font_options_get_hint_metrics_, 1},
  {"cairo_font_options_set_variations_", (DL_FUNC) &cairo_font_options_set_variations_, 2},
  {"cairo_font_options_get_variations_", (DL_FUNC) &cairo_font_options_get_variations_, 1},

  // cairo--
  {"cairo_create_", (DL_FUNC) &cairo_create_, 1},
  {"cairo_save_", (DL_FUNC) &cairo_save_, 1},
  {"cairo_restore_", (DL_FUNC) &cairo_restore_, 1},
  {"cairo_push_group_", (DL_FUNC) &cairo_push_group_, 1},
  {"cairo_push_group_with_content_", (DL_FUNC) &cairo_push_group_with_content_, 2},
  {"cairo_pop_group_", (DL_FUNC) &cairo_pop_group_, 1},
  {"cairo_pop_group_to_source_", (DL_FUNC) &cairo_pop_group_to_source_, 1},
  {"cairo_set_operator_", (DL_FUNC) &cairo_set_operator_, 2},
  {"cairo_set_source_rgb_", (DL_FUNC) &cairo_set_source_rgb_, 4},
  {"cairo_set_source_rgba_", (DL_FUNC) &cairo_set_source_rgba_, 5},
  {"cairo_set_source_surface_", (DL_FUNC) &cairo_set_source_surface_, 4},
  {"cairo_set_source_", (DL_FUNC) &cairo_set_source_, 2},
  {"cairo_get_source_", (DL_FUNC) &cairo_get_source_, 1},
  {"cairo_set_tolerance_", (DL_FUNC) &cairo_set_tolerance_, 2},
  {"cairo_set_antialias_", (DL_FUNC) &cairo_set_antialias_, 2},
  {"cairo_set_fill_rule_", (DL_FUNC) &cairo_set_fill_rule_, 2},
  {"cairo_set_line_width_", (DL_FUNC) &cairo_set_line_width_, 2},
  {"cairo_set_line_cap_", (DL_FUNC) &cairo_set_line_cap_, 2},
  {"cairo_set_line_join_", (DL_FUNC) &cairo_set_line_join_, 2},
  {"cairo_set_dash_", (DL_FUNC) &cairo_set_dash_, 4},
  {"cairo_get_dash_count_", (DL_FUNC) &cairo_get_dash_count_, 1},
  {"cairo_get_dash_", (DL_FUNC) &cairo_get_dash_, 3},
  {"cairo_set_miter_limit_", (DL_FUNC) &cairo_set_miter_limit_, 2},
  {"cairo_translate_", (DL_FUNC) &cairo_translate_, 3},
  {"cairo_scale_", (DL_FUNC) &cairo_scale_, 3},
  {"cairo_rotate_", (DL_FUNC) &cairo_rotate_, 2},
  {"cairo_transform_", (DL_FUNC) &cairo_transform_, 2},
  {"cairo_set_matrix_", (DL_FUNC) &cairo_set_matrix_, 2},
  {"cairo_identity_matrix_", (DL_FUNC) &cairo_identity_matrix_, 1},
  {"cairo_user_to_device_", (DL_FUNC) &cairo_user_to_device_, 3},
  {"cairo_user_to_device_distance_", (DL_FUNC) &cairo_user_to_device_distance_, 3},
  {"cairo_device_to_user_", (DL_FUNC) &cairo_device_to_user_, 3},
  {"cairo_device_to_user_distance_", (DL_FUNC) &cairo_device_to_user_distance_, 3},
  {"cairo_new_path_", (DL_FUNC) &cairo_new_path_, 1},
  {"cairo_new_sub_path_", (DL_FUNC) &cairo_new_sub_path_, 1},
  {"cairo_move_to_", (DL_FUNC) &cairo_move_to_, 3},
  {"cairo_line_to_", (DL_FUNC) &cairo_line_to_, 3},
  {"cairo_curve_to_", (DL_FUNC) &cairo_curve_to_, 7},
  {"cairo_arc_", (DL_FUNC) &cairo_arc_, 6},
  {"cairo_arc_negative_", (DL_FUNC) &cairo_arc_negative_, 6},
  {"cairo_rel_move_to_", (DL_FUNC) &cairo_rel_move_to_, 3},
  {"cairo_rel_line_to_", (DL_FUNC) &cairo_rel_line_to_, 3},
  {"cairo_rel_curve_to_", (DL_FUNC) &cairo_rel_curve_to_, 7},
  {"cairo_rectangle_", (DL_FUNC) &cairo_rectangle_, 5},
  {"cairo_close_path_", (DL_FUNC) &cairo_close_path_, 1},
  {"cairo_path_extents_", (DL_FUNC) &cairo_path_extents_, 5},
  {"cairo_paint_", (DL_FUNC) &cairo_paint_, 1},
  {"cairo_paint_with_alpha_", (DL_FUNC) &cairo_paint_with_alpha_, 2},
  {"cairo_mask_", (DL_FUNC) &cairo_mask_, 2},
  {"cairo_mask_surface_", (DL_FUNC) &cairo_mask_surface_, 4},
  {"cairo_stroke_", (DL_FUNC) &cairo_stroke_, 1},
  {"cairo_stroke_preserve_", (DL_FUNC) &cairo_stroke_preserve_, 1},
  {"cairo_fill_", (DL_FUNC) &cairo_fill_, 1},
  {"cairo_fill_preserve_", (DL_FUNC) &cairo_fill_preserve_, 1},
  {"cairo_copy_page_", (DL_FUNC) &cairo_copy_page_, 1},
  {"cairo_show_page_", (DL_FUNC) &cairo_show_page_, 1},
  {"cairo_in_stroke_", (DL_FUNC) &cairo_in_stroke_, 3},
  {"cairo_in_fill_", (DL_FUNC) &cairo_in_fill_, 3},
  {"cairo_stroke_extents_", (DL_FUNC) &cairo_stroke_extents_, 5},
  {"cairo_fill_extents_", (DL_FUNC) &cairo_fill_extents_, 5},
  {"cairo_clip_", (DL_FUNC) &cairo_clip_, 1},
  {"cairo_clip_preserve_", (DL_FUNC) &cairo_clip_preserve_, 1},
  {"cairo_reset_clip_", (DL_FUNC) &cairo_reset_clip_, 1},
  {"cairo_clip_extents_", (DL_FUNC) &cairo_clip_extents_, 5},
  {"cairo_in_clip_", (DL_FUNC) &cairo_in_clip_, 3},
  {"cairo_tag_begin_", (DL_FUNC) &cairo_tag_begin_, 3},
  {"cairo_tag_end_", (DL_FUNC) &cairo_tag_end_, 2},
  {"cairo_select_font_face_", (DL_FUNC) &cairo_select_font_face_, 4},
  {"cairo_font_extents_", (DL_FUNC) &cairo_font_extents_, 2},
  {"cairo_set_font_face_", (DL_FUNC) &cairo_set_font_face_, 2},
  {"cairo_get_font_face_", (DL_FUNC) &cairo_get_font_face_, 1},
  {"cairo_set_font_size_", (DL_FUNC) &cairo_set_font_size_, 2},
  {"cairo_set_font_matrix_", (DL_FUNC) &cairo_set_font_matrix_, 2},
  {"cairo_get_font_matrix_", (DL_FUNC) &cairo_get_font_matrix_, 2},
  {"cairo_text_extents_", (DL_FUNC) &cairo_text_extents_, 3},
  {"cairo_show_text_", (DL_FUNC) &cairo_show_text_, 2},
  {"cairo_text_path_", (DL_FUNC) &cairo_text_path_, 2},
  {"cairo_get_operator_", (DL_FUNC) &cairo_get_operator_, 1},
  {"cairo_get_tolerance_", (DL_FUNC) &cairo_get_tolerance_, 1},
  {"cairo_get_antialias_", (DL_FUNC) &cairo_get_antialias_, 1},
  {"cairo_has_current_point_", (DL_FUNC) &cairo_has_current_point_, 1},
  {"cairo_get_current_point_", (DL_FUNC) &cairo_get_current_point_, 3},
  {"cairo_get_fill_rule_", (DL_FUNC) &cairo_get_fill_rule_, 1},
  {"cairo_get_line_width_", (DL_FUNC) &cairo_get_line_width_, 1},
  {"cairo_get_line_cap_", (DL_FUNC) &cairo_get_line_cap_, 1},
  {"cairo_get_line_join_", (DL_FUNC) &cairo_get_line_join_, 1},
  {"cairo_get_miter_limit_", (DL_FUNC) &cairo_get_miter_limit_, 1},
  {"cairo_get_matrix_", (DL_FUNC) &cairo_get_matrix_, 2},
  {"cairo_get_target_", (DL_FUNC) &cairo_get_target_, 1},
  {"cairo_get_group_target_", (DL_FUNC) &cairo_get_group_target_, 1},
  {"cairo_copy_path_", (DL_FUNC) &cairo_copy_path_, 1},
  {"cairo_copy_path_flat_", (DL_FUNC) &cairo_copy_path_flat_, 1},
  {"cairo_append_path_", (DL_FUNC) &cairo_append_path_, 2},
  {"cairo_status_", (DL_FUNC) &cairo_status_, 1},

  // cairo-image-surface
  {"cairo_image_surface_create_", (DL_FUNC) &cairo_image_surface_create_, 3},
  {"cairo_format_stride_for_width_", (DL_FUNC) &cairo_format_stride_for_width_, 2},
  {"cairo_image_surface_create_for_data_", (DL_FUNC) &cairo_image_surface_create_for_data_, 5},
  {"cairo_image_surface_get_data_", (DL_FUNC) &cairo_image_surface_get_data_, 1},
  {"cairo_image_surface_get_format_", (DL_FUNC) &cairo_image_surface_get_format_, 1},
  {"cairo_image_surface_get_width_", (DL_FUNC) &cairo_image_surface_get_width_, 1},
  {"cairo_image_surface_get_height_", (DL_FUNC) &cairo_image_surface_get_height_, 1},
  {"cairo_image_surface_get_stride_", (DL_FUNC) &cairo_image_surface_get_stride_, 1},

  // cairo-matrix
  {"cairo_matrix_init_", (DL_FUNC) &cairo_matrix_init_, 7},
  {"cairo_matrix_init_translate_", (DL_FUNC) &cairo_matrix_init_translate_, 3},
  {"cairo_matrix_translate_", (DL_FUNC) &cairo_matrix_translate_, 3},
  {"cairo_matrix_init_scale_", (DL_FUNC) &cairo_matrix_init_scale_, 3},
  {"cairo_matrix_scale_", (DL_FUNC) &cairo_matrix_scale_, 3},
  {"cairo_matrix_init_rotate_", (DL_FUNC) &cairo_matrix_init_rotate_, 2},
  {"cairo_matrix_rotate_", (DL_FUNC) &cairo_matrix_rotate_, 2},
  {"cairo_matrix_multiply_", (DL_FUNC) &cairo_matrix_multiply_, 3},
  {"cairo_matrix_transform_distance_", (DL_FUNC) &cairo_matrix_transform_distance_, 3},
  {"cairo_matrix_transform_point_", (DL_FUNC) &cairo_matrix_transform_point_, 3},
  {"cairo_matrix_invert_", (DL_FUNC) &cairo_matrix_invert_, 1},

  // cairo-pattern
  {"cairo_pattern_create_rgb_", (DL_FUNC) &cairo_pattern_create_rgb_, 3},
  {"cairo_pattern_create_rgba_", (DL_FUNC) &cairo_pattern_create_rgba_, 4},
  {"cairo_pattern_create_for_surface_", (DL_FUNC) &cairo_pattern_create_for_surface_, 1},
  {"cairo_pattern_create_linear_", (DL_FUNC) &cairo_pattern_create_linear_, 4},
  {"cairo_pattern_create_radial_", (DL_FUNC) &cairo_pattern_create_radial_, 6},
  {"cairo_pattern_create_mesh_", (DL_FUNC) &cairo_pattern_create_mesh_, 0},
  {"cairo_pattern_get_type_", (DL_FUNC) &cairo_pattern_get_type_, 1},
  {"cairo_pattern_status_", (DL_FUNC) &cairo_pattern_status_, 1},
  {"cairo_mesh_pattern_begin_patch_", (DL_FUNC) &cairo_mesh_pattern_begin_patch_, 1},
  {"cairo_mesh_pattern_end_patch_", (DL_FUNC) &cairo_mesh_pattern_end_patch_, 1},
  {"cairo_mesh_pattern_curve_to_", (DL_FUNC) &cairo_mesh_pattern_curve_to_, 7},
  {"cairo_mesh_pattern_line_to_", (DL_FUNC) &cairo_mesh_pattern_line_to_, 3},
  {"cairo_mesh_pattern_move_to_", (DL_FUNC) &cairo_mesh_pattern_move_to_, 3},
  {"cairo_mesh_pattern_set_control_point_", (DL_FUNC) &cairo_mesh_pattern_set_control_point_, 4},
  {"cairo_mesh_pattern_set_corner_color_rgb_", (DL_FUNC) &cairo_mesh_pattern_set_corner_color_rgb_, 5},
  {"cairo_mesh_pattern_set_corner_color_rgba_", (DL_FUNC) &cairo_mesh_pattern_set_corner_color_rgba_, 6},
  {"cairo_pattern_add_color_stop_rgb_", (DL_FUNC) &cairo_pattern_add_color_stop_rgb_, 5},
  {"cairo_pattern_add_color_stop_rgba_", (DL_FUNC) &cairo_pattern_add_color_stop_rgba_, 6},
  {"cairo_pattern_set_matrix_", (DL_FUNC) &cairo_pattern_set_matrix_, 2},
  {"cairo_pattern_get_matrix_", (DL_FUNC) &cairo_pattern_get_matrix_, 2},
  {"cairo_pattern_set_filter_", (DL_FUNC) &cairo_pattern_set_filter_, 2},
  {"cairo_pattern_get_filter_", (DL_FUNC) &cairo_pattern_get_filter_, 1},
  {"cairo_pattern_set_extend_", (DL_FUNC) &cairo_pattern_set_extend_, 2},
  {"cairo_pattern_get_extend_", (DL_FUNC) &cairo_pattern_get_extend_, 1},
  {"cairo_pattern_get_rgba_", (DL_FUNC) &cairo_pattern_get_rgba_, 5},
  {"cairo_pattern_get_color_stop_rgba_", (DL_FUNC) &cairo_pattern_get_color_stop_rgba_, 7},
  {"cairo_pattern_get_color_stop_count_", (DL_FUNC) &cairo_pattern_get_color_stop_count_, 2},
  {"cairo_pattern_get_linear_points_", (DL_FUNC) &cairo_pattern_get_linear_points_, 5},
  {"cairo_pattern_get_radial_circles_", (DL_FUNC) &cairo_pattern_get_radial_circles_, 7},
  {"cairo_mesh_pattern_get_patch_count_", (DL_FUNC) &cairo_mesh_pattern_get_patch_count_, 2},
  {"cairo_mesh_pattern_get_path_", (DL_FUNC) &cairo_mesh_pattern_get_path_, 2},
  {"cairo_mesh_pattern_get_corner_color_rgba_", (DL_FUNC) &cairo_mesh_pattern_get_corner_color_rgba_, 7},
  {"cairo_mesh_pattern_get_control_point_", (DL_FUNC) &cairo_mesh_pattern_get_control_point_, 5},

  // cairo-pdf-surface
  {"cairo_pdf_surface_create_", (DL_FUNC) &cairo_pdf_surface_create_, 3},
  {"cairo_pdf_surface_restrict_to_version_", (DL_FUNC) &cairo_pdf_surface_restrict_to_version_, 2},
  {"cairo_pdf_version_to_string_", (DL_FUNC) &cairo_pdf_version_to_string_, 1},
  {"cairo_pdf_surface_set_size_", (DL_FUNC) &cairo_pdf_surface_set_size_, 3},
  {"cairo_pdf_surface_add_outline_", (DL_FUNC) &cairo_pdf_surface_add_outline_, 5},
  {"cairo_pdf_surface_set_metadata_", (DL_FUNC) &cairo_pdf_surface_set_metadata_, 3},
  {"cairo_pdf_surface_set_page_label_", (DL_FUNC) &cairo_pdf_surface_set_page_label_, 2},
  {"cairo_pdf_surface_set_thumbnail_size_", (DL_FUNC) &cairo_pdf_surface_set_thumbnail_size_, 3},

  // cairo-png
  {"cairo_surface_write_to_png_", (DL_FUNC) &cairo_surface_write_to_png_, 2},
  {"cairo_image_surface_create_from_png_", (DL_FUNC) &cairo_image_surface_create_from_png_, 1},

  // cairo-ps
  {"cairo_ps_surface_create_", (DL_FUNC) &cairo_ps_surface_create_, 3},
  {"cairo_ps_surface_restrict_to_level_", (DL_FUNC) &cairo_ps_surface_restrict_to_level_, 2},
  {"cairo_ps_level_to_string_", (DL_FUNC) &cairo_ps_level_to_string_, 1},
  {"cairo_ps_surface_set_eps_", (DL_FUNC) &cairo_ps_surface_set_eps_, 2},
  {"cairo_ps_surface_get_eps_", (DL_FUNC) &cairo_ps_surface_get_eps_, 1},
  {"cairo_ps_surface_set_size_", (DL_FUNC) &cairo_ps_surface_set_size_, 3},
  {"cairo_ps_surface_dsc_comment_", (DL_FUNC) &cairo_ps_surface_dsc_comment_, 2},
  {"cairo_ps_surface_dsc_begin_setup_", (DL_FUNC) &cairo_ps_surface_dsc_begin_setup_, 1},
  {"cairo_ps_surface_dsc_begin_page_setup_", (DL_FUNC) &cairo_ps_surface_dsc_begin_page_setup_, 1},

  // cairo-surface
  {"cairo_surface_finish_", (DL_FUNC) &cairo_surface_finish_, 1},
  {"cairo_surface_flush_", (DL_FUNC) &cairo_surface_flush_, 1},

  // cairo-surface-subsurface
  {"cairo_surface_create_for_rectangle_", (DL_FUNC) &cairo_surface_create_for_rectangle_, 5},

  // cairo-svg-surface
  {"cairo_svg_surface_create_", (DL_FUNC) &cairo_svg_surface_create_, 3},
  {"cairo_svg_surface_restrict_to_version_", (DL_FUNC) &cairo_svg_surface_restrict_to_version_, 2},
  {"cairo_svg_version_to_string_", (DL_FUNC) &cairo_svg_version_to_string_, 1},
  {"cairo_svg_surface_set_document_unit_", (DL_FUNC) &cairo_svg_surface_set_document_unit_, 2},
  {"cairo_svg_surface_get_document_unit_", (DL_FUNC) &cairo_svg_surface_get_document_unit_, 1},

  // ---- end auto-generated callmethoddefs ----


  // name                       pointer                           Num args

  {"cairo_image_surface_get_raw_", (DL_FUNC) &cairo_image_surface_get_raw_, 1},
  {"cairo_image_surface_get_array_", (DL_FUNC) &cairo_image_surface_get_array_, 1},
  {"cairo_image_surface_write_array_", (DL_FUNC) &cairo_image_surface_write_array_, 4},

  // Bespoke: cairo
  {"cairo_arc_vec_", (DL_FUNC) &cairo_arc_vec_, 14},
  {"cairo_rectangle_vec_", (DL_FUNC) &cairo_rectangle_vec_, 13},
  {"cairo_segment_vec_", (DL_FUNC) &cairo_segment_vec_, 9},
  {"cairo_polygon_vec_", (DL_FUNC) &cairo_polygon_vec_, 12},

  {"cairo_text_extents_t_", (DL_FUNC) &cairo_text_extents_t_, 0},
  {"cairo_text_extents_t_to_list_", (DL_FUNC) &cairo_text_extents_t_to_list_, 1},
  {"cairo_font_extents_t_", (DL_FUNC) &cairo_font_extents_t_, 0},
  {"cairo_font_extents_t_to_list_", (DL_FUNC) &cairo_font_extents_t_to_list_, 1},
  {"cairo_polyline_", (DL_FUNC) &cairo_polyline_, 3},
  {"cairo_polygon_", (DL_FUNC) &cairo_polygon_, 3},

  // Cairo = structs
  {"cairo_matrix_t_", (DL_FUNC) &cairo_matrix_t_, 6},
  {"cairo_matrix_t_to_list_", (DL_FUNC) &cairo_matrix_t_to_list_, 1},
  {"cairo_matrix_t_update_", (DL_FUNC) &cairo_matrix_t_update_, 7},

  {"cairo_rectangle_t_", (DL_FUNC) &cairo_rectangle_t_, 4},
  {"cairo_rectangle_t_to_list_", (DL_FUNC) &cairo_rectangle_t_to_list_, 1},

  {"cairo_rectangle_int_t_", (DL_FUNC) &cairo_rectangle_int_t_, 4},




  {NULL , NULL, 0}
};


void R_init_cairocore(DllInfo *info) {
  R_registerRoutines(
    info,      // DllInfo
    NULL,      // .C
    CEntries,  // .Call
    NULL,      // Fortran
    NULL       // External
  );
  R_useDynamicSymbols(info, FALSE);
}



