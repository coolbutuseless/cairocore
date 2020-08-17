
#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <cairo/cairo.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aaa.h"
#include "R-finalizers.h"



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_polyline_(SEXP cr_, SEXP x_, SEXP y_)  {

  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  int nx   = length(x_);
  int ny   = length(y_);

  if (nx != ny) {
    error("cairo_polyline_(): All lengths must be either the same");
  }


  double *x      = (double *)REAL(x_);
  double *y      = (double *)REAL(y_);

  cairo_move_to(cr, x[0], y[0]);

  for (int i = 1; i < nx; i++) {
    cairo_line_to(cr, x[i], y[i]);
  }

  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_polygon_(SEXP cr_, SEXP x_, SEXP y_)  {

  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  cairo_polyline_(cr_, x_, y_);
  cairo_close_path(cr);

  return R_NilValue;
}























