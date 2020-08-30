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
// cairo_font_type_t cairo_font_face_get_type (cairo_font_face_t *font_face)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_face_get_type_(SEXP font_face_)  {
  cairo_font_face_t *font_face = TYPEOF(font_face_) != EXTPTRSXP ? NULL : (cairo_font_face_t *)R_ExternalPtrAddr(font_face_);
  if (font_face == NULL) error("'cairo_font_face_t * font_face' pointer is invalid/NULL");
  int result = cairo_font_face_get_type(font_face);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_font_face_status (cairo_font_face_t *font_face)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_face_status_(SEXP font_face_)  {
  cairo_font_face_t *font_face = TYPEOF(font_face_) != EXTPTRSXP ? NULL : (cairo_font_face_t *)R_ExternalPtrAddr(font_face_);
  if (font_face == NULL) error("'cairo_font_face_t * font_face' pointer is invalid/NULL");
  int result = cairo_font_face_status(font_face);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}
