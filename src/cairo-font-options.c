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
// cairo_font_options_t * cairo_font_options_create (void)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_create_(void)  {
  cairo_font_options_t * result = cairo_font_options_create();
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_font_options_t"));
  R_RegisterCFinalizer(result_, cairo_font_options_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_font_options_t * cairo_font_options_copy (const cairo_font_options_t *original)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_copy_(SEXP original_)  {
  cairo_font_options_t *original = TYPEOF(original_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(original_);
  if (original == NULL) error("'cairo_font_options_t * original' pointer is invalid/NULL");
  cairo_font_options_t * result = cairo_font_options_copy(original);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_font_options_t"));
  R_RegisterCFinalizer(result_, cairo_font_options_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_status_t cairo_font_options_status (cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_status_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int result = cairo_font_options_status(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_merge (cairo_font_options_t *options, const cairo_font_options_t *other)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_merge_(SEXP options_, SEXP other_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  cairo_font_options_t *other = TYPEOF(other_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(other_);
  if (other == NULL) error("'cairo_font_options_t * other' pointer is invalid/NULL");
  cairo_font_options_merge(options, other);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_bool_t cairo_font_options_equal (const cairo_font_options_t *options, const cairo_font_options_t *other)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_equal_(SEXP options_, SEXP other_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  cairo_font_options_t *other = TYPEOF(other_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(other_);
  if (other == NULL) error("'cairo_font_options_t * other' pointer is invalid/NULL");
  int result = cairo_font_options_equal(options, other);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned long cairo_font_options_hash (const cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_hash_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  unsigned long result = cairo_font_options_hash(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_set_antialias (cairo_font_options_t *options, cairo_antialias_t antialias)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_set_antialias_(SEXP options_, SEXP antialias_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int antialias = isReal(antialias_) ? (int)REAL(antialias_)[0] : (int)INTEGER(antialias_)[0];
  cairo_font_options_set_antialias(options, antialias);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_antialias_t cairo_font_options_get_antialias (const cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_get_antialias_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int result = cairo_font_options_get_antialias(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_set_subpixel_order (cairo_font_options_t *options, cairo_subpixel_order_t subpixel_order)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_set_subpixel_order_(SEXP options_, SEXP subpixel_order_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int subpixel_order = isReal(subpixel_order_) ? (int)REAL(subpixel_order_)[0] : (int)INTEGER(subpixel_order_)[0];
  cairo_font_options_set_subpixel_order(options, subpixel_order);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_subpixel_order_t cairo_font_options_get_subpixel_order (const cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_get_subpixel_order_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int result = cairo_font_options_get_subpixel_order(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_set_hint_style (cairo_font_options_t *options, cairo_hint_style_t hint_style)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_set_hint_style_(SEXP options_, SEXP hint_style_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int hint_style = isReal(hint_style_) ? (int)REAL(hint_style_)[0] : (int)INTEGER(hint_style_)[0];
  cairo_font_options_set_hint_style(options, hint_style);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_hint_style_t cairo_font_options_get_hint_style (const cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_get_hint_style_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int result = cairo_font_options_get_hint_style(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_set_hint_metrics (cairo_font_options_t *options, cairo_hint_metrics_t hint_metrics)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_set_hint_metrics_(SEXP options_, SEXP hint_metrics_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int hint_metrics = isReal(hint_metrics_) ? (int)REAL(hint_metrics_)[0] : (int)INTEGER(hint_metrics_)[0];
  cairo_font_options_set_hint_metrics(options, hint_metrics);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_hint_metrics_t cairo_font_options_get_hint_metrics (const cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_get_hint_metrics_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  int result = cairo_font_options_get_hint_metrics(options);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_font_options_set_variations (cairo_font_options_t *options, const char *variations)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_set_variations_(SEXP options_, SEXP variations_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  char * variations = (char *)CHAR(asChar(variations_));
  cairo_font_options_set_variations(options, variations);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// const char * cairo_font_options_get_variations (cairo_font_options_t *options)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_options_get_variations_(SEXP options_)  {
  cairo_font_options_t *options = TYPEOF(options_) != EXTPTRSXP ? NULL : (cairo_font_options_t *)R_ExternalPtrAddr(options_);
  if (options == NULL) error("'cairo_font_options_t * options' pointer is invalid/NULL");
  const char * result = cairo_font_options_get_variations(options);
  SEXP result_ = PROTECT(mkString(result));
  UNPROTECT(1);
  return result_;
}
