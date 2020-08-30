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
// cairo_surface_t * cairo_ps_surface_create (const char *filename, double width_in_points, double height_in_points)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_create_(SEXP filename_, SEXP width_in_points_, SEXP height_in_points_)  {
  char * filename = (char *)CHAR(asChar(filename_));
  double width_in_points = isInteger(width_in_points_) ? (double)INTEGER(width_in_points_)[0] : (double)REAL(width_in_points_)[0];
  double height_in_points = isInteger(height_in_points_) ? (double)INTEGER(height_in_points_)[0] : (double)REAL(height_in_points_)[0];
  cairo_surface_t * result = cairo_ps_surface_create(filename, width_in_points, height_in_points);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_restrict_to_level (cairo_surface_t *surface, cairo_ps_level_t level)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_restrict_to_level_(SEXP surface_, SEXP level_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int level = isReal(level_) ? (int)REAL(level_)[0] : (int)INTEGER(level_)[0];
  cairo_ps_surface_restrict_to_level(surface, level);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// const char * cairo_ps_level_to_string (cairo_ps_level_t level)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_level_to_string_(SEXP level_)  {
  int level = isReal(level_) ? (int)REAL(level_)[0] : (int)INTEGER(level_)[0];
  const char * result = cairo_ps_level_to_string(level);
  SEXP result_ = PROTECT(mkString(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_set_eps (cairo_surface_t *surface, cairo_bool_t eps)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_set_eps_(SEXP surface_, SEXP eps_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int eps = isReal(eps_) ? (int)REAL(eps_)[0] : (int)INTEGER(eps_)[0];
  cairo_ps_surface_set_eps(surface, eps);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_public cairo_bool_t cairo_ps_surface_get_eps (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_get_eps_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int result = cairo_ps_surface_get_eps(surface);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_set_size (cairo_surface_t *surface, double width_in_points, double height_in_points)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_set_size_(SEXP surface_, SEXP width_in_points_, SEXP height_in_points_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  double width_in_points = isInteger(width_in_points_) ? (double)INTEGER(width_in_points_)[0] : (double)REAL(width_in_points_)[0];
  double height_in_points = isInteger(height_in_points_) ? (double)INTEGER(height_in_points_)[0] : (double)REAL(height_in_points_)[0];
  cairo_ps_surface_set_size(surface, width_in_points, height_in_points);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_dsc_comment (cairo_surface_t *surface, const char *comment)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_dsc_comment_(SEXP surface_, SEXP comment_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  char * comment = (char *)CHAR(asChar(comment_));
  cairo_ps_surface_dsc_comment(surface, comment);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_dsc_begin_setup (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_dsc_begin_setup_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  cairo_ps_surface_dsc_begin_setup(surface);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_ps_surface_dsc_begin_page_setup (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_ps_surface_dsc_begin_page_setup_(SEXP surface_)  {
  cairo_surface_t *surface = TYPEOF(surface_) != EXTPTRSXP ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  cairo_ps_surface_dsc_begin_page_setup(surface);
  return R_NilValue;
}
