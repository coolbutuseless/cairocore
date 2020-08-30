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
// cairo_surface_t * cairo_svg_surface_create (const char *filename, double width, double height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_svg_surface_create_(SEXP filename_, SEXP width_, SEXP height_)  {
  char * filename = (char *)CHAR(asChar(filename_));
  double width = isInteger(width_) ? (double)INTEGER(width_)[0] : (double)REAL(width_)[0];
  double height = isInteger(height_) ? (double)INTEGER(height_)[0] : (double)REAL(height_)[0];
  cairo_surface_t * result = cairo_svg_surface_create(filename, width, height);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_svg_surface_restrict_to_version (cairo_surface_t *surface, cairo_svg_version_t version)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_svg_surface_restrict_to_version_(SEXP surface_, SEXP version_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int version = isReal(version_) ? (int)REAL(version_)[0] : (int)INTEGER(version_)[0];
  cairo_svg_surface_restrict_to_version(surface, version);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// const char * cairo_svg_version_to_string (cairo_svg_version_t version)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_svg_version_to_string_(SEXP version_)  {
  int version = isReal(version_) ? (int)REAL(version_)[0] : (int)INTEGER(version_)[0];
  const char * result = cairo_svg_version_to_string(version);
  SEXP result_ = PROTECT(mkString(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_svg_surface_set_document_unit (cairo_surface_t *surface, cairo_svg_unit_t unit)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_svg_surface_set_document_unit_(SEXP surface_, SEXP unit_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int unit = isReal(unit_) ? (int)REAL(unit_)[0] : (int)INTEGER(unit_)[0];
  cairo_svg_surface_set_document_unit(surface, unit);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_svg_unit_t cairo_svg_surface_get_document_unit (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_svg_surface_get_document_unit_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int result = cairo_svg_surface_get_document_unit(surface);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}
