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
// void cairo_matrix_init (cairo_matrix_t *matrix, double xx, double yx, double xy, double yy, double x0, double y0)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_init_(SEXP matrix_, SEXP xx_, SEXP yx_, SEXP xy_, SEXP yy_, SEXP x0_, SEXP y0_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double xx = isInteger(xx_) ? (double)INTEGER(xx_)[0] : (double)REAL(xx_)[0];
  double yx = isInteger(yx_) ? (double)INTEGER(yx_)[0] : (double)REAL(yx_)[0];
  double xy = isInteger(xy_) ? (double)INTEGER(xy_)[0] : (double)REAL(xy_)[0];
  double yy = isInteger(yy_) ? (double)INTEGER(yy_)[0] : (double)REAL(yy_)[0];
  double x0 = isInteger(x0_) ? (double)INTEGER(x0_)[0] : (double)REAL(x0_)[0];
  double y0 = isInteger(y0_) ? (double)INTEGER(y0_)[0] : (double)REAL(y0_)[0];
  cairo_matrix_init(matrix, xx, yx, xy, yy, x0, y0);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_init_translate (cairo_matrix_t *matrix, double tx, double ty)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_init_translate_(SEXP matrix_, SEXP tx_, SEXP ty_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double tx = isInteger(tx_) ? (double)INTEGER(tx_)[0] : (double)REAL(tx_)[0];
  double ty = isInteger(ty_) ? (double)INTEGER(ty_)[0] : (double)REAL(ty_)[0];
  cairo_matrix_init_translate(matrix, tx, ty);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_translate (cairo_matrix_t *matrix, double tx, double ty)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_translate_(SEXP matrix_, SEXP tx_, SEXP ty_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double tx = isInteger(tx_) ? (double)INTEGER(tx_)[0] : (double)REAL(tx_)[0];
  double ty = isInteger(ty_) ? (double)INTEGER(ty_)[0] : (double)REAL(ty_)[0];
  cairo_matrix_translate(matrix, tx, ty);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_init_scale (cairo_matrix_t *matrix, double sx, double sy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_init_scale_(SEXP matrix_, SEXP sx_, SEXP sy_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double sx = isInteger(sx_) ? (double)INTEGER(sx_)[0] : (double)REAL(sx_)[0];
  double sy = isInteger(sy_) ? (double)INTEGER(sy_)[0] : (double)REAL(sy_)[0];
  cairo_matrix_init_scale(matrix, sx, sy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_scale (cairo_matrix_t *matrix, double sx, double sy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_scale_(SEXP matrix_, SEXP sx_, SEXP sy_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double sx = isInteger(sx_) ? (double)INTEGER(sx_)[0] : (double)REAL(sx_)[0];
  double sy = isInteger(sy_) ? (double)INTEGER(sy_)[0] : (double)REAL(sy_)[0];
  cairo_matrix_scale(matrix, sx, sy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_init_rotate (cairo_matrix_t *matrix, double radians)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_init_rotate_(SEXP matrix_, SEXP radians_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double radians = isInteger(radians_) ? (double)INTEGER(radians_)[0] : (double)REAL(radians_)[0];
  cairo_matrix_init_rotate(matrix, radians);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_rotate (cairo_matrix_t *matrix, double radians)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_rotate_(SEXP matrix_, SEXP radians_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double radians = isInteger(radians_) ? (double)INTEGER(radians_)[0] : (double)REAL(radians_)[0];
  cairo_matrix_rotate(matrix, radians);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_multiply (cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_multiply_(SEXP result_, SEXP a_, SEXP b_)  {
  cairo_matrix_t *result = TYPEOF(result_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(result_);
  if (result == NULL) error("'cairo_matrix_t * result' pointer is invalid/NULL");
  cairo_matrix_t *a = TYPEOF(a_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(a_);
  if (a == NULL) error("'cairo_matrix_t * a' pointer is invalid/NULL");
  cairo_matrix_t *b = TYPEOF(b_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(b_);
  if (b == NULL) error("'cairo_matrix_t * b' pointer is invalid/NULL");
  cairo_matrix_multiply(result, a, b);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_transform_distance (const cairo_matrix_t *matrix, double *dx, double *dy)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_transform_distance_(SEXP matrix_, SEXP dx_, SEXP dy_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double * dx = (double *)REAL(dx_);
  double * dy = (double *)REAL(dy_);
  cairo_matrix_transform_distance(matrix, dx, dy);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_matrix_transform_point (const cairo_matrix_t *matrix, double *x, double *y)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_transform_point_(SEXP matrix_, SEXP x_, SEXP y_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  double * x = (double *)REAL(x_);
  double * y = (double *)REAL(y_);
  cairo_matrix_transform_point(matrix, x, y);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_matrix_invert (cairo_matrix_t *matrix)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_invert_(SEXP matrix_)  {
  cairo_matrix_t *matrix = TYPEOF(matrix_) != EXTPTRSXP ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(matrix_);
  if (matrix == NULL) error("'cairo_matrix_t * matrix' pointer is invalid/NULL");
  int result = cairo_matrix_invert(matrix);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}
