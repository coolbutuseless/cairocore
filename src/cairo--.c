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
// cairo_t * cairo_create (cairo_surface_t *target)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_create_(SEXP target_)  {
  cairo_surface_t *target = TYPEOF(target_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(target_);
  if (target == NULL) error("'cairo_surface_t * target' pointer is invalid/NULL");
  cairo_t * result = cairo_create(target);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_t"));
  R_RegisterCFinalizer(result_, cairo_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_save (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_save_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_save(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_restore (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_restore_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_restore(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_push_group (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_push_group_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_push_group(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_push_group_with_content (cairo_t *cr, cairo_content_t content)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_push_group_with_content_(SEXP cr_, SEXP content_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int content = isReal(content_) ? (int)REAL(content_)[0] : (int)INTEGER(content_)[0];
  cairo_push_group_with_content(cr, content);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_pop_group (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pop_group_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_pattern_t * result = cairo_pop_group(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pop_group_to_source (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pop_group_to_source_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_pop_group_to_source(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_operator (cairo_t *cr, cairo_operator_t op)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_operator_(SEXP cr_, SEXP op_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int op = isReal(op_) ? (int)REAL(op_)[0] : (int)INTEGER(op_)[0];
  cairo_set_operator(cr, op);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_source_rgb (cairo_t *cr, double red, double green, double blue)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_source_rgb_(SEXP cr_, SEXP red_, SEXP green_, SEXP blue_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  cairo_set_source_rgb(cr, red, green, blue);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_source_rgba (cairo_t *cr, double red, double green, double blue, double alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_source_rgba_(SEXP cr_, SEXP red_, SEXP green_, SEXP blue_, SEXP alpha_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double red = isInteger(red_) ? (double)INTEGER(red_)[0] : (double)REAL(red_)[0];
  double green = isInteger(green_) ? (double)INTEGER(green_)[0] : (double)REAL(green_)[0];
  double blue = isInteger(blue_) ? (double)INTEGER(blue_)[0] : (double)REAL(blue_)[0];
  double alpha = isInteger(alpha_) ? (double)INTEGER(alpha_)[0] : (double)REAL(alpha_)[0];
  cairo_set_source_rgba(cr, red, green, blue, alpha);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_source_surface (cairo_t *cr, cairo_surface_t *surface, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_source_surface_(SEXP cr_, SEXP surface_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_set_source_surface(cr, surface, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_source (cairo_t *cr, cairo_pattern_t *source)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_source_(SEXP cr_, SEXP source_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_pattern_t *source = TYPEOF(source_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(source_);
  if (source == NULL) error("'cairo_pattern_t * source' pointer is invalid/NULL");
  cairo_set_source(cr, source);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_pattern_t * cairo_get_source (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_source_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_pattern_t * result = cairo_get_source(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_pattern_t"));
  R_RegisterCFinalizer(result_, cairo_pattern_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_tolerance (cairo_t *cr, double tolerance)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_tolerance_(SEXP cr_, SEXP tolerance_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double tolerance = isInteger(tolerance_) ? (double)INTEGER(tolerance_)[0] : (double)REAL(tolerance_)[0];
  cairo_set_tolerance(cr, tolerance);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_antialias (cairo_t *cr, cairo_antialias_t antialias)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_antialias_(SEXP cr_, SEXP antialias_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int antialias = isReal(antialias_) ? (int)REAL(antialias_)[0] : (int)INTEGER(antialias_)[0];
  cairo_set_antialias(cr, antialias);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_fill_rule (cairo_t *cr, cairo_fill_rule_t fill_rule)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_fill_rule_(SEXP cr_, SEXP fill_rule_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int fill_rule = isReal(fill_rule_) ? (int)REAL(fill_rule_)[0] : (int)INTEGER(fill_rule_)[0];
  cairo_set_fill_rule(cr, fill_rule);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_line_width (cairo_t *cr, double width)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_line_width_(SEXP cr_, SEXP width_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double width = isInteger(width_) ? (double)INTEGER(width_)[0] : (double)REAL(width_)[0];
  cairo_set_line_width(cr, width);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_line_cap (cairo_t *cr, cairo_line_cap_t line_cap)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_line_cap_(SEXP cr_, SEXP line_cap_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int line_cap = isReal(line_cap_) ? (int)REAL(line_cap_)[0] : (int)INTEGER(line_cap_)[0];
  cairo_set_line_cap(cr, line_cap);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_line_join (cairo_t *cr, cairo_line_join_t line_join)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_line_join_(SEXP cr_, SEXP line_join_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int line_join = isReal(line_join_) ? (int)REAL(line_join_)[0] : (int)INTEGER(line_join_)[0];
  cairo_set_line_join(cr, line_join);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_dash (cairo_t *cr, const double *dashes, int num_dashes, double offset)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_dash_(SEXP cr_, SEXP dashes_, SEXP num_dashes_, SEXP offset_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * dashes = (double *)REAL(dashes_);
  int num_dashes = isReal(num_dashes_) ? (int)REAL(num_dashes_)[0] : (int)INTEGER(num_dashes_)[0];
  double offset = isInteger(offset_) ? (double)INTEGER(offset_)[0] : (double)REAL(offset_)[0];
  cairo_set_dash(cr, dashes, num_dashes, offset);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// int cairo_get_dash_count (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_dash_count_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_dash_count(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_get_dash (cairo_t *cr, double *dashes, double *offset)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_dash_(SEXP cr_, SEXP dashes_, SEXP offset_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * dashes = (double *)REAL(dashes_);
  double * offset = (double *)REAL(offset_);
  cairo_get_dash(cr, dashes, offset);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_miter_limit (cairo_t *cr, double limit)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_miter_limit_(SEXP cr_, SEXP limit_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double limit = isInteger(limit_) ? (double)INTEGER(limit_)[0] : (double)REAL(limit_)[0];
  cairo_set_miter_limit(cr, limit);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_translate (cairo_t *cr, double tx, double ty)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_translate_(SEXP cr_, SEXP tx_, SEXP ty_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double tx = isInteger(tx_) ? (double)INTEGER(tx_)[0] : (double)REAL(tx_)[0];
  double ty = isInteger(ty_) ? (double)INTEGER(ty_)[0] : (double)REAL(ty_)[0];
  cairo_translate(cr, tx, ty);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_scale (cairo_t *cr, double sx, double sy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_scale_(SEXP cr_, SEXP sx_, SEXP sy_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double sx = isInteger(sx_) ? (double)INTEGER(sx_)[0] : (double)REAL(sx_)[0];
  double sy = isInteger(sy_) ? (double)INTEGER(sy_)[0] : (double)REAL(sy_)[0];
  cairo_scale(cr, sx, sy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rotate (cairo_t *cr, double angle)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rotate_(SEXP cr_, SEXP angle_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double angle = isInteger(angle_) ? (double)INTEGER(angle_)[0] : (double)REAL(angle_)[0];
  cairo_rotate(cr, angle);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_transform (cairo_t *cr, const cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_transform_(SEXP cr_, SEXP matrix_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_transform(cr, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_matrix (cairo_t *cr, const cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_matrix_(SEXP cr_, SEXP matrix_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_set_matrix(cr, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_identity_matrix (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_identity_matrix_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_identity_matrix(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_user_to_device (cairo_t *cr, double *x, double *y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_user_to_device_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x = (double *)REAL(x_);
  double * y = (double *)REAL(y_);
  cairo_user_to_device(cr, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_user_to_device_distance (cairo_t *cr, double *dx, double *dy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_user_to_device_distance_(SEXP cr_, SEXP dx_, SEXP dy_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * dx = (double *)REAL(dx_);
  double * dy = (double *)REAL(dy_);
  cairo_user_to_device_distance(cr, dx, dy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_device_to_user (cairo_t *cr, double *x, double *y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_device_to_user_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x = (double *)REAL(x_);
  double * y = (double *)REAL(y_);
  cairo_device_to_user(cr, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_device_to_user_distance (cairo_t *cr, double *dx, double *dy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_device_to_user_distance_(SEXP cr_, SEXP dx_, SEXP dy_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * dx = (double *)REAL(dx_);
  double * dy = (double *)REAL(dy_);
  cairo_device_to_user_distance(cr, dx, dy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_new_path (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_new_path_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_new_path(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_new_sub_path (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_new_sub_path_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_new_sub_path(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_move_to (cairo_t *cr, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_move_to_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_move_to(cr, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_line_to (cairo_t *cr, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_line_to_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  cairo_line_to(cr, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_curve_to (cairo_t *cr, double x1, double y1, double x2, double y2, double x3, double y3)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_curve_to_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_, SEXP x3_, SEXP y3_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x1 = isInteger(x1_) ? (double)INTEGER(x1_)[0] : (double)REAL(x1_)[0];
  double y1 = isInteger(y1_) ? (double)INTEGER(y1_)[0] : (double)REAL(y1_)[0];
  double x2 = isInteger(x2_) ? (double)INTEGER(x2_)[0] : (double)REAL(x2_)[0];
  double y2 = isInteger(y2_) ? (double)INTEGER(y2_)[0] : (double)REAL(y2_)[0];
  double x3 = isInteger(x3_) ? (double)INTEGER(x3_)[0] : (double)REAL(x3_)[0];
  double y3 = isInteger(y3_) ? (double)INTEGER(y3_)[0] : (double)REAL(y3_)[0];
  cairo_curve_to(cr, x1, y1, x2, y2, x3, y3);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_arc (cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_arc_(SEXP cr_, SEXP xc_, SEXP yc_, SEXP radius_, SEXP angle1_, SEXP angle2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double xc = isInteger(xc_) ? (double)INTEGER(xc_)[0] : (double)REAL(xc_)[0];
  double yc = isInteger(yc_) ? (double)INTEGER(yc_)[0] : (double)REAL(yc_)[0];
  double radius = isInteger(radius_) ? (double)INTEGER(radius_)[0] : (double)REAL(radius_)[0];
  double angle1 = isInteger(angle1_) ? (double)INTEGER(angle1_)[0] : (double)REAL(angle1_)[0];
  double angle2 = isInteger(angle2_) ? (double)INTEGER(angle2_)[0] : (double)REAL(angle2_)[0];
  cairo_arc(cr, xc, yc, radius, angle1, angle2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_arc_negative (cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_arc_negative_(SEXP cr_, SEXP xc_, SEXP yc_, SEXP radius_, SEXP angle1_, SEXP angle2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double xc = isInteger(xc_) ? (double)INTEGER(xc_)[0] : (double)REAL(xc_)[0];
  double yc = isInteger(yc_) ? (double)INTEGER(yc_)[0] : (double)REAL(yc_)[0];
  double radius = isInteger(radius_) ? (double)INTEGER(radius_)[0] : (double)REAL(radius_)[0];
  double angle1 = isInteger(angle1_) ? (double)INTEGER(angle1_)[0] : (double)REAL(angle1_)[0];
  double angle2 = isInteger(angle2_) ? (double)INTEGER(angle2_)[0] : (double)REAL(angle2_)[0];
  cairo_arc_negative(cr, xc, yc, radius, angle1, angle2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rel_move_to (cairo_t *cr, double dx, double dy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rel_move_to_(SEXP cr_, SEXP dx_, SEXP dy_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double dx = isInteger(dx_) ? (double)INTEGER(dx_)[0] : (double)REAL(dx_)[0];
  double dy = isInteger(dy_) ? (double)INTEGER(dy_)[0] : (double)REAL(dy_)[0];
  cairo_rel_move_to(cr, dx, dy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rel_line_to (cairo_t *cr, double dx, double dy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rel_line_to_(SEXP cr_, SEXP dx_, SEXP dy_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double dx = isInteger(dx_) ? (double)INTEGER(dx_)[0] : (double)REAL(dx_)[0];
  double dy = isInteger(dy_) ? (double)INTEGER(dy_)[0] : (double)REAL(dy_)[0];
  cairo_rel_line_to(cr, dx, dy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rel_curve_to (cairo_t *cr, double dx1, double dy1, double dx2, double dy2, double dx3, double dy3)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rel_curve_to_(SEXP cr_, SEXP dx1_, SEXP dy1_, SEXP dx2_, SEXP dy2_, SEXP dx3_, SEXP dy3_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double dx1 = isInteger(dx1_) ? (double)INTEGER(dx1_)[0] : (double)REAL(dx1_)[0];
  double dy1 = isInteger(dy1_) ? (double)INTEGER(dy1_)[0] : (double)REAL(dy1_)[0];
  double dx2 = isInteger(dx2_) ? (double)INTEGER(dx2_)[0] : (double)REAL(dx2_)[0];
  double dy2 = isInteger(dy2_) ? (double)INTEGER(dy2_)[0] : (double)REAL(dy2_)[0];
  double dx3 = isInteger(dx3_) ? (double)INTEGER(dx3_)[0] : (double)REAL(dx3_)[0];
  double dy3 = isInteger(dy3_) ? (double)INTEGER(dy3_)[0] : (double)REAL(dy3_)[0];
  cairo_rel_curve_to(cr, dx1, dy1, dx2, dy2, dx3, dy3);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rectangle (cairo_t *cr, double x, double y, double width, double height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rectangle_(SEXP cr_, SEXP x_, SEXP y_, SEXP width_, SEXP height_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  double width = isInteger(width_) ? (double)INTEGER(width_)[0] : (double)REAL(width_)[0];
  double height = isInteger(height_) ? (double)INTEGER(height_)[0] : (double)REAL(height_)[0];
  cairo_rectangle(cr, x, y, width, height);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_close_path (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_close_path_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_close_path(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_path_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_path_extents_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  double * x2 = (double *)REAL(x2_);
  double * y2 = (double *)REAL(y2_);
  cairo_path_extents(cr, x1, y1, x2, y2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_paint (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_paint_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_paint(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_paint_with_alpha (cairo_t *cr, double alpha)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_paint_with_alpha_(SEXP cr_, SEXP alpha_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double alpha = isInteger(alpha_) ? (double)INTEGER(alpha_)[0] : (double)REAL(alpha_)[0];
  cairo_paint_with_alpha(cr, alpha);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mask (cairo_t *cr, cairo_pattern_t *pattern)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mask_(SEXP cr_, SEXP pattern_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_pattern_t *pattern = TYPEOF(pattern_) != EXTPTRSXP ? NULL : (cairo_pattern_t *)R_ExternalPtrAddr(pattern_);
  if (pattern == NULL) error("'cairo_pattern_t * pattern' pointer is invalid/NULL");
  cairo_mask(cr, pattern);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_mask_surface (cairo_t *cr, cairo_surface_t *surface, double surface_x, double surface_y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_mask_surface_(SEXP cr_, SEXP surface_, SEXP surface_x_, SEXP surface_y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  double surface_x = isInteger(surface_x_) ? (double)INTEGER(surface_x_)[0] : (double)REAL(surface_x_)[0];
  double surface_y = isInteger(surface_y_) ? (double)INTEGER(surface_y_)[0] : (double)REAL(surface_y_)[0];
  cairo_mask_surface(cr, surface, surface_x, surface_y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_stroke (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_stroke_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_stroke(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_stroke_preserve (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_stroke_preserve_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_stroke_preserve(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_fill (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_fill_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_fill(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_fill_preserve (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_fill_preserve_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_fill_preserve(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_copy_page (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_copy_page_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_copy_page(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_show_page (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_show_page_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_show_page(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_bool_t cairo_in_stroke (cairo_t *cr, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_in_stroke_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  int result = cairo_in_stroke(cr, x, y);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_bool_t cairo_in_fill (cairo_t *cr, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_in_fill_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  int result = cairo_in_fill(cr, x, y);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_stroke_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_stroke_extents_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  double * x2 = (double *)REAL(x2_);
  double * y2 = (double *)REAL(y2_);
  cairo_stroke_extents(cr, x1, y1, x2, y2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_fill_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_fill_extents_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  double * x2 = (double *)REAL(x2_);
  double * y2 = (double *)REAL(y2_);
  cairo_fill_extents(cr, x1, y1, x2, y2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_clip (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_clip_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_clip(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_clip_preserve (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_clip_preserve_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_clip_preserve(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_reset_clip (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_reset_clip_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_reset_clip(cr);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_clip_extents (cairo_t *cr, double *x1, double *y1, double *x2, double *y2)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_clip_extents_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x1 = (double *)REAL(x1_);
  double * y1 = (double *)REAL(y1_);
  double * x2 = (double *)REAL(x2_);
  double * y2 = (double *)REAL(y2_);
  cairo_clip_extents(cr, x1, y1, x2, y2);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_bool_t cairo_in_clip (cairo_t *cr, double x, double y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_in_clip_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  int result = cairo_in_clip(cr, x, y);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_tag_begin (cairo_t *cr, const char *tag_name, const char *attributes)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_tag_begin_(SEXP cr_, SEXP tag_name_, SEXP attributes_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * tag_name = (char *)CHAR(asChar(tag_name_));
  char * attributes = (char *)CHAR(asChar(attributes_));
  cairo_tag_begin(cr, tag_name, attributes);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_public void cairo_tag_end (cairo_t *cr, const char *tag_name)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_tag_end_(SEXP cr_, SEXP tag_name_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * tag_name = (char *)CHAR(asChar(tag_name_));
  cairo_tag_end(cr, tag_name);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_select_font_face (cairo_t *cr, const char *family, cairo_font_slant_t slant, cairo_font_weight_t weight)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_select_font_face_(SEXP cr_, SEXP family_, SEXP slant_, SEXP weight_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * family = (char *)CHAR(asChar(family_));
  int slant = isReal(slant_) ? (int)REAL(slant_)[0] : (int)INTEGER(slant_)[0];
  int weight = isReal(weight_) ? (int)REAL(weight_)[0] : (int)INTEGER(weight_)[0];
  cairo_select_font_face(cr, family, slant, weight);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_extents (cairo_t *cr, cairo_font_extents_t *extents)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_extents_(SEXP cr_, SEXP extents_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_font_extents_t *extents = TYPEOF(extents_) != EXTPTRSXP ? NULL : (cairo_font_extents_t *)R_ExternalPtrAddr(extents_);
  if (extents == NULL) error("'cairo_font_extents_t * extents' pointer is invalid/NULL");
  cairo_font_extents(cr, extents);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_font_face (cairo_t *cr, cairo_font_face_t *font_face)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_font_face_(SEXP cr_, SEXP font_face_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_font_face_t *font_face = TYPEOF(font_face_) != EXTPTRSXP ? NULL : (cairo_font_face_t *)R_ExternalPtrAddr(font_face_);
  if (font_face == NULL) error("'cairo_font_face_t * font_face' pointer is invalid/NULL");
  cairo_set_font_face(cr, font_face);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_font_face_t * cairo_get_font_face (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_font_face_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_font_face_t * result = cairo_get_font_face(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_font_face_t"));
  R_RegisterCFinalizer(result_, cairo_font_face_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_font_size (cairo_t *cr, double size)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_font_size_(SEXP cr_, SEXP size_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double size = isInteger(size_) ? (double)INTEGER(size_)[0] : (double)REAL(size_)[0];
  cairo_set_font_size(cr, size);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_set_font_matrix (cairo_t *cr, const cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_set_font_matrix_(SEXP cr_, SEXP matrix_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_set_font_matrix(cr, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_get_font_matrix (cairo_t *cr, cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_font_matrix_(SEXP cr_, SEXP matrix_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_get_font_matrix(cr, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_text_extents (cairo_t *cr, const char *utf8, cairo_text_extents_t *extents)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_text_extents_(SEXP cr_, SEXP utf8_, SEXP extents_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * utf8 = (char *)CHAR(asChar(utf8_));
  cairo_text_extents_t *extents = TYPEOF(extents_) != EXTPTRSXP ? NULL : (cairo_text_extents_t *)R_ExternalPtrAddr(extents_);
  if (extents == NULL) error("'cairo_text_extents_t * extents' pointer is invalid/NULL");
  cairo_text_extents(cr, utf8, extents);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_show_text (cairo_t *cr, const char *utf8)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_show_text_(SEXP cr_, SEXP utf8_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * utf8 = (char *)CHAR(asChar(utf8_));
  cairo_show_text(cr, utf8);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_text_path (cairo_t *cr, const char *utf8)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_text_path_(SEXP cr_, SEXP utf8_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  char * utf8 = (char *)CHAR(asChar(utf8_));
  cairo_text_path(cr, utf8);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_operator_t cairo_get_operator (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_operator_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_operator(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// double cairo_get_tolerance (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_tolerance_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double result = cairo_get_tolerance(cr);
  SEXP result_ = PROTECT(ScalarReal(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_antialias_t cairo_get_antialias (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_antialias_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_antialias(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_bool_t cairo_has_current_point (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_has_current_point_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_has_current_point(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_get_current_point (cairo_t *cr, double *x, double *y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_current_point_(SEXP cr_, SEXP x_, SEXP y_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double * x = (double *)REAL(x_);
  double * y = (double *)REAL(y_);
  cairo_get_current_point(cr, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_fill_rule_t cairo_get_fill_rule (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_fill_rule_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_fill_rule(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// double cairo_get_line_width (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_line_width_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double result = cairo_get_line_width(cr);
  SEXP result_ = PROTECT(ScalarReal(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_line_cap_t cairo_get_line_cap (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_line_cap_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_line_cap(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_line_join_t cairo_get_line_join (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_line_join_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_get_line_join(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// double cairo_get_miter_limit (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_miter_limit_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  double result = cairo_get_miter_limit(cr);
  SEXP result_ = PROTECT(ScalarReal(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_get_matrix (cairo_t *cr, cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_matrix_(SEXP cr_, SEXP matrix_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  cairo_get_matrix(cr, matrix);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_surface_t * cairo_get_target (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_target_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_surface_t * result = cairo_get_target(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_surface_t * cairo_get_group_target (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_get_group_target_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_surface_t * result = cairo_get_group_target(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_path_t * cairo_copy_path (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_copy_path_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_path_t * result = cairo_copy_path(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_path_t"));
  R_RegisterCFinalizer(result_, cairo_path_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_path_t * cairo_copy_path_flat (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_copy_path_flat_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_path_t * result = cairo_copy_path_flat(cr);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_path_t"));
  R_RegisterCFinalizer(result_, cairo_path_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_append_path (cairo_t *cr, const cairo_path_t *path)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_append_path_(SEXP cr_, SEXP path_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  cairo_path_t *path = TYPEOF(path_) != EXTPTRSXP ? NULL : (cairo_path_t *)R_ExternalPtrAddr(path_);
  if (path == NULL) error("'cairo_path_t * path' pointer is invalid/NULL");
  cairo_append_path(cr, path);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_status (cairo_t *cr)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_status_(SEXP cr_)  {
  cairo_t *cr = TYPEOF(cr_) != EXTPTRSXP ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");
  int result = cairo_status(cr);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}
