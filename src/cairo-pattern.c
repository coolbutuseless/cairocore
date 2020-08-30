// This file was auto-generated from C headers

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <cairo/cairo.h>
#include <cairo/cairo-pdf.h>
#include <cairo/cairo-svg.h>
#include <cairo/cairo-ps.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aaa.h"
#include "R-finalizers.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_rgb (double red, double green, double blue)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_rgb_(SEXP red_, SEXP green_, SEXP blue_)  {
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  cairo_pattern_t * result = cairo_pattern_create_rgb(red, green, blue);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_rgba (double red, double green, double blue, double alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_rgba_(SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  double alpha = isInteger(alpha_) ? (double)INTEGER(alpha_)[0] : (double)REAL(alpha_)[0];
  cairo_pattern_t * result = cairo_pattern_create_rgba(red, green, blue, alpha);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_for_surface (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_for_surface_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  cairo_pattern_t * result = cairo_pattern_create_for_surface(surface);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_linear (double x0, double y0, double x1, double y1)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_linear_(SEXP x0_, SEXP y0_, SEXP x1_, SEXP y1_)  {
  double x0 = isInteger(x0_) ? (double)INTEGER(x0_)[0] : (double)REAL(x0_)[0];
  double y0 = isInteger(y0_) ? (double)INTEGER(y0_)[0] : (double)REAL(y0_)[0];
  double x1 = isInteger(x1_) ? (double)INTEGER(x1_)[0] : (double)REAL(x1_)[0];
  double y1 = isInteger(y1_) ? (double)INTEGER(y1_)[0] : (double)REAL(y1_)[0];
  cairo_pattern_t * result = cairo_pattern_create_linear(x0, y0, x1, y1);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_radial (double cx0, double cy0, double radius0, double cx1, double cy1, double radius1)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_radial_(SEXP cx0_, SEXP cy0_, SEXP radius0_, SEXP cx1_, SEXP cy1_, SEXP radius1_)  {
  double cx0 = isInteger(cx0_) ? (double)INTEGER(cx0_)[0] : (double)REAL(cx0_)[0];
  double cy0 = isInteger(cy0_) ? (double)INTEGER(cy0_)[0] : (double)REAL(cy0_)[0];
  double radius0 = isInteger(radius0_) ? (double)INTEGER(radius0_)[0] : (double)REAL(radius0_)[0];
  double cx1 = isInteger(cx1_) ? (double)INTEGER(cx1_)[0] : (double)REAL(cx1_)[0];
  double cy1 = isInteger(cy1_) ? (double)INTEGER(cy1_)[0] : (double)REAL(cy1_)[0];
  double radius1 = isInteger(radius1_) ? (double)INTEGER(radius1_)[0] : (double)REAL(radius1_)[0];
  cairo_pattern_t * result = cairo_pattern_create_radial(cx0, cy0, radius0, cx1, cy1, radius1);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pattern_create_mesh (void)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_create_mesh_(void)  {
  cairo_pattern_t * result = cairo_pattern_create_mesh();
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_type_t cairo_pattern_get_type (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_type_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int result = cairo_pattern_get_type(pattern);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_status (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_status_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int result = cairo_pattern_status(pattern);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_begin_patch (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_begin_patch_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  cairo_mesh_pattern_begin_patch(pattern);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_end_patch (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_end_patch_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  cairo_mesh_pattern_end_patch(pattern);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_curve_to (cairo_pattern_t *pattern, double x1, double y1, double x2, double y2, double x3, double y3)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_curve_to_(SEXP pattern_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_, SEXP x3_, SEXP y3_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double x1 = isInteger(x1_) ? (double)INTEGER(x1_)[0] : (double)REAL(x1_)[0];
  double y1 = isInteger(y1_) ? (double)INTEGER(y1_)[0] : (double)REAL(y1_)[0];
  double x2 = isInteger(x2_) ? (double)INTEGER(x2_)[0] : (double)REAL(x2_)[0];
  double y2 = isInteger(y2_) ? (double)INTEGER(y2_)[0] : (double)REAL(y2_)[0];
  double x3 = isInteger(x3_) ? (double)INTEGER(x3_)[0] : (double)REAL(x3_)[0];
  double y3 = isInteger(y3_) ? (double)INTEGER(y3_)[0] : (double)REAL(y3_)[0];
  cairo_mesh_pattern_curve_to(pattern, x1, y1, x2, y2, x3, y3);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_line_to (cairo_pattern_t *pattern, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_line_to_(SEXP pattern_, SEXP x_, SEXP y_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_mesh_pattern_line_to(pattern, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_move_to (cairo_pattern_t *pattern, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_move_to_(SEXP pattern_, SEXP x_, SEXP y_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_mesh_pattern_move_to(pattern, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_set_control_point (cairo_pattern_t *pattern, unsigned int point_num, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_set_control_point_(SEXP pattern_, SEXP point_num_, SEXP x_, SEXP y_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int point_num = isReal(point_num_) ? (unsigned int)REAL(point_num_)[0] : (unsigned int)INTEGER(point_num_)[0];
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_mesh_pattern_set_control_point(pattern, point_num, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_set_corner_color_rgb (cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_set_corner_color_rgb_(SEXP pattern_, SEXP corner_num_, SEXP red_, SEXP green_, SEXP blue_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int corner_num = isReal(corner_num_) ? (unsigned int)REAL(corner_num_)[0] : (unsigned int)INTEGER(corner_num_)[0];
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  cairo_mesh_pattern_set_corner_color_rgb(pattern, corner_num, red, green, blue);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mesh_pattern_set_corner_color_rgba (cairo_pattern_t *pattern, unsigned int corner_num, double red, double green, double blue, double alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_set_corner_color_rgba_(SEXP pattern_, SEXP corner_num_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int corner_num = isReal(corner_num_) ? (unsigned int)REAL(corner_num_)[0] : (unsigned int)INTEGER(corner_num_)[0];
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  double alpha = isInteger(alpha_) ? (double)INTEGER(alpha_)[0] : (double)REAL(alpha_)[0];
  cairo_mesh_pattern_set_corner_color_rgba(pattern, corner_num, red, green, blue, alpha);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_add_color_stop_rgb (cairo_pattern_t *pattern, double offset, double red, double green, double blue)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_add_color_stop_rgb_(SEXP pattern_, SEXP offset_, SEXP red_, SEXP green_, SEXP blue_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double offset = isInteger(offset_) ? (double)INTEGER(offset_)[0] : (double)REAL(offset_)[0];
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  cairo_pattern_add_color_stop_rgb(pattern, offset, red, green, blue);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_add_color_stop_rgba (cairo_pattern_t *pattern, double offset, double red, double green, double blue, double alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_add_color_stop_rgba_(SEXP pattern_, SEXP offset_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double offset = isInteger(offset_) ? (double)INTEGER(offset_)[0] : (double)REAL(offset_)[0];
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  double alpha = isInteger(alpha_) ? (double)INTEGER(alpha_)[0] : (double)REAL(alpha_)[0];
  cairo_pattern_add_color_stop_rgba(pattern, offset, red, green, blue, alpha);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_set_matrix (cairo_pattern_t *pattern, const cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_set_matrix_(SEXP pattern_, SEXP matrix_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_pattern_set_matrix(pattern, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_get_matrix (cairo_pattern_t *pattern, cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_matrix_(SEXP pattern_, SEXP matrix_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_pattern_get_matrix(pattern, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_set_filter (cairo_pattern_t *pattern, cairo_filter_t filter)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_set_filter_(SEXP pattern_, SEXP filter_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int filter = isReal(filter_) ? (int)REAL(filter_)[0] : (int)INTEGER(filter_)[0];
  cairo_pattern_set_filter(pattern, filter);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_filter_t cairo_pattern_get_filter (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_filter_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int result = cairo_pattern_get_filter(pattern);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pattern_set_extend (cairo_pattern_t *pattern, cairo_extend_t extend)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_set_extend_(SEXP pattern_, SEXP extend_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int extend = isReal(extend_) ? (int)REAL(extend_)[0] : (int)INTEGER(extend_)[0];
  cairo_pattern_set_extend(pattern, extend);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_extend_t cairo_pattern_get_extend (cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_extend_(SEXP pattern_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int result = cairo_pattern_get_extend(pattern);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_get_rgba (cairo_pattern_t *pattern, double *red, double *green, double *blue, double *alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_rgba_(SEXP pattern_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double * red = (double *)REAL(red_);
  double * green = (double *)REAL(green_);
  double * blue = (double *)REAL(blue_);
  double * alpha = (double *)REAL(alpha_);
  int result = cairo_pattern_get_rgba(pattern, red, green, blue, alpha);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_get_color_stop_rgba (cairo_pattern_t *pattern, int index, double *offset, double *red, double *green, double *blue, double *alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_color_stop_rgba_(SEXP pattern_, SEXP index_, SEXP offset_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int index = isReal(index_) ? (int)REAL(index_)[0] : (int)INTEGER(index_)[0];
  double * offset = (double *)REAL(offset_);
  double * red = (double *)REAL(red_);
  double * green = (double *)REAL(green_);
  double * blue = (double *)REAL(blue_);
  double * alpha = (double *)REAL(alpha_);
  int result = cairo_pattern_get_color_stop_rgba(pattern, index, offset, red, green, blue, alpha);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_get_color_stop_count (cairo_pattern_t *pattern, int *count)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_color_stop_count_(SEXP pattern_, SEXP count_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  int * count = (int *)INTEGER(count_);
  int result = cairo_pattern_get_color_stop_count(pattern, count);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_get_linear_points (cairo_pattern_t *pattern, double *x0, double *y0, double *x1, double *y1)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_linear_points_(SEXP pattern_, SEXP x0_, SEXP y0_, SEXP x1_, SEXP y1_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double * x0 = (double *)REAL(x0_);
  double * y0 = (double *)REAL(y0_);
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  int result = cairo_pattern_get_linear_points(pattern, x0, y0, x1, y1);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_pattern_get_radial_circles (cairo_pattern_t *pattern, double *x0, double *y0, double *r0, double *x1, double *y1, double *r1)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pattern_get_radial_circles_(SEXP pattern_, SEXP x0_, SEXP y0_, SEXP r0_, SEXP x1_, SEXP y1_, SEXP r1_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  double * x0 = (double *)REAL(x0_);
  double * y0 = (double *)REAL(y0_);
  double * r0 = (double *)REAL(r0_);
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  double * r1 = (double *)REAL(r1_);
  int result = cairo_pattern_get_radial_circles(pattern, x0, y0, r0, x1, y1, r1);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_mesh_pattern_get_patch_count (cairo_pattern_t *pattern, unsigned int *count)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_get_patch_count_(SEXP pattern_, SEXP count_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int *count = TYPEOF(count_) != EXTPTRSXP ? NULL : (unsigned int *)R_ExternalPtrAddr(count_);
  if (count == NULL) error("'unsigned int * count' pointer is invalid/NULL");
  int result = cairo_mesh_pattern_get_patch_count(pattern, count);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_path_t * cairo_mesh_pattern_get_path (cairo_pattern_t *pattern, unsigned int patch_num)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_get_path_(SEXP pattern_, SEXP patch_num_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int patch_num = isReal(patch_num_) ? (unsigned int)REAL(patch_num_)[0] : (unsigned int)INTEGER(patch_num_)[0];
  cairo_path_t * result = cairo_mesh_pattern_get_path(pattern, patch_num);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_path_t"));
  R_RegisterCFinalizer(result_, cairo_path_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_mesh_pattern_get_corner_color_rgba (cairo_pattern_t *pattern, unsigned int patch_num, unsigned int corner_num, double *red, double *green, double *blue, double *alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_get_corner_color_rgba_(SEXP pattern_, SEXP patch_num_, SEXP corner_num_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int patch_num = isReal(patch_num_) ? (unsigned int)REAL(patch_num_)[0] : (unsigned int)INTEGER(patch_num_)[0];
  unsigned int corner_num = isReal(corner_num_) ? (unsigned int)REAL(corner_num_)[0] : (unsigned int)INTEGER(corner_num_)[0];
  double * red = (double *)REAL(red_);
  double * green = (double *)REAL(green_);
  double * blue = (double *)REAL(blue_);
  double * alpha = (double *)REAL(alpha_);
  int result = cairo_mesh_pattern_get_corner_color_rgba(pattern, patch_num, corner_num, red, green, blue, alpha);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_mesh_pattern_get_control_point (cairo_pattern_t *pattern, unsigned int patch_num, unsigned int point_num, double *x, double *y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mesh_pattern_get_control_point_(SEXP pattern_, SEXP patch_num_, SEXP point_num_, SEXP x_, SEXP y_)  {
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  unsigned int patch_num = isReal(patch_num_) ? (unsigned int)REAL(patch_num_)[0] : (unsigned int)INTEGER(patch_num_)[0];
  unsigned int point_num = isReal(point_num_) ? (unsigned int)REAL(point_num_)[0] : (unsigned int)INTEGER(point_num_)[0];
  double * x = (double *)REAL(x_);
  double * y = (double *)REAL(y_);
  int result = cairo_mesh_pattern_get_control_point(pattern, patch_num, point_num, x, y);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}
