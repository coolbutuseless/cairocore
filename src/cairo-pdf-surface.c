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
// cairo_surface_t * cairo_pdf_surface_create (const char *filename, double width_in_points, double height_in_points)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_create_(SEXP filename_, SEXP width_in_points_, SEXP height_in_points_)  {
  char * filename = (char *)CHAR(asChar(filename_));
  double width_in_points = isInteger(width_in_points_) ? (double)INTEGER(width_in_points_)[0] : (double)REAL(width_in_points_)[0];
  double height_in_points = isInteger(height_in_points_) ? (double)INTEGER(height_in_points_)[0] : (double)REAL(height_in_points_)[0];
  cairo_surface_t * result = cairo_pdf_surface_create(filename, width_in_points, height_in_points);
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_surface_t"));
  R_RegisterCFinalizer(result_, cairo_surface_t_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pdf_surface_restrict_to_version (cairo_surface_t *surface, cairo_pdf_version_t version)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_restrict_to_version_(SEXP surface_, SEXP version_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int version = isReal(version_) ? (int)REAL(version_)[0] : (int)INTEGER(version_)[0];
  cairo_pdf_surface_restrict_to_version(surface, version);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// const char * cairo_pdf_version_to_string (cairo_pdf_version_t version)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_version_to_string_(SEXP version_)  {
  int version = isReal(version_) ? (int)REAL(version_)[0] : (int)INTEGER(version_)[0];
  const char * result = cairo_pdf_version_to_string(version);
  SEXP result_ = PROTECT(mkString(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pdf_surface_set_size (cairo_surface_t *surface, double width_in_points, double height_in_points)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_set_size_(SEXP surface_, SEXP width_in_points_, SEXP height_in_points_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  double width_in_points = isInteger(width_in_points_) ? (double)INTEGER(width_in_points_)[0] : (double)REAL(width_in_points_)[0];
  double height_in_points = isInteger(height_in_points_) ? (double)INTEGER(height_in_points_)[0] : (double)REAL(height_in_points_)[0];
  cairo_pdf_surface_set_size(surface, width_in_points, height_in_points);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// int cairo_pdf_surface_add_outline (cairo_surface_t *surface, int parent_id, const char *utf8, const char *link_attribs, cairo_pdf_outline_flags_t flags)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_add_outline_(SEXP surface_, SEXP parent_id_, SEXP utf8_, SEXP link_attribs_, SEXP flags_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int parent_id = isReal(parent_id_) ? (int)REAL(parent_id_)[0] : (int)INTEGER(parent_id_)[0];
  char * utf8 = (char *)CHAR(asChar(utf8_));
  char * link_attribs = (char *)CHAR(asChar(link_attribs_));
  int flags = isReal(flags_) ? (int)REAL(flags_)[0] : (int)INTEGER(flags_)[0];
  int result = cairo_pdf_surface_add_outline(surface, parent_id, utf8, link_attribs, flags);
  SEXP result_ = PROTECT(ScalarInteger(result));
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pdf_surface_set_metadata (cairo_surface_t *surface, cairo_pdf_metadata_t metadata, const char *utf8)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_set_metadata_(SEXP surface_, SEXP metadata_, SEXP utf8_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int metadata = isReal(metadata_) ? (int)REAL(metadata_)[0] : (int)INTEGER(metadata_)[0];
  char * utf8 = (char *)CHAR(asChar(utf8_));
  cairo_pdf_surface_set_metadata(surface, metadata, utf8);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pdf_surface_set_page_label (cairo_surface_t *surface, const char *utf8)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_set_page_label_(SEXP surface_, SEXP utf8_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  char * utf8 = (char *)CHAR(asChar(utf8_));
  cairo_pdf_surface_set_page_label(surface, utf8);
  return R_NilValue;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_pdf_surface_set_thumbnail_size (cairo_surface_t *surface, int width, int height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_pdf_surface_set_thumbnail_size_(SEXP surface_, SEXP width_, SEXP height_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  int width = isReal(width_) ? (int)REAL(width_)[0] : (int)INTEGER(width_)[0];
  int height = isReal(height_) ? (int)REAL(height_)[0] : (int)INTEGER(height_)[0];
  cairo_pdf_surface_set_thumbnail_size(surface, width, height);
  return R_NilValue;
}
