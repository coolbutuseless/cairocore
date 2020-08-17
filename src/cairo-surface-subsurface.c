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
// cairo_surface_t * cairo_surface_create_for_rectangle (cairo_surface_t *target, double x, double y, double width, double height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_surface_create_for_rectangle_(SEXP target_, SEXP x_, SEXP y_, SEXP width_, SEXP height_)  {
  cairo_surface_t *target = isNull(target_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(target_);
  if (target == NULL) error("'cairo_surface_t * target' pointer is invalid/NULL");
  double x = isInteger(x_) ? (double)INTEGER(x_)[0] : (double)REAL(x_)[0];
  double y = isInteger(y_) ? (double)INTEGER(y_)[0] : (double)REAL(y_)[0];
  double width = isInteger(width_) ? (double)INTEGER(width_)[0] : (double)REAL(width_)[0];
  double height = isInteger(height_) ? (double)INTEGER(height_)[0] : (double)REAL(height_)[0];
  cairo_surface_t * result = cairo_surface_create_for_rectangle(target, x, y, width, height);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}
