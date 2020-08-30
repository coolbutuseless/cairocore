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
// void cairo_surface_finish (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_surface_finish_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  cairo_surface_finish(surface);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_surface_flush (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_surface_flush_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  cairo_surface_flush(surface);
  return R_NilValue;
}
