
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
//
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_image_surface_get_raw_(SEXP surface_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  unsigned char * result = cairo_image_surface_get_data(surface);

  cairo_format_t format = cairo_image_surface_get_format(surface);

  if (format != CAIRO_FORMAT_ARGB32) {
    error("cairo_image_surface_get_raw_ only understands 4bytes/pixel CAIRO_FORMAT_ARGB32. not format=%i", format);
  }

  int bytes_per_pixel = 4;
  int w = cairo_image_surface_get_width(surface);
  int h = cairo_image_surface_get_height(surface);
  int stride = cairo_image_surface_get_stride(surface);

  if (stride != 4 * w) {
    error("cairo_image_surface_get_raw_(): Currently only supports stride (%i) = 4 * width (%i)", stride, w);
  }

  int nbytes = 4 * w * h;


  SEXP result_ = PROTECT(allocVector(RAWSXP, w*h*4));
  unsigned char *dst = RAW(result_);

  memcpy(dst, result, nbytes);

  UNPROTECT(1);
  return result_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// unsigned char * cairo_image_surface_get_data (cairo_surface_t *surface)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_image_surface_get_array_(SEXP surface_)  {
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  unsigned char * result = cairo_image_surface_get_data(surface);

  cairo_format_t format = cairo_image_surface_get_format(surface);

  if (format != CAIRO_FORMAT_ARGB32) {
    error("cairo_image_surface_get_array_ only understands 4bytes/pixel CAIRO_FORMAT_ARGB32. not format=%i", format);
  }

  int bytes_per_pixel = 4;
  int w = cairo_image_surface_get_width(surface);
  int h = cairo_image_surface_get_height(surface);
  int stride = cairo_image_surface_get_stride(surface);

  if (stride != 4 * w) {
    error("cairo_image_surface_get_array_(): Currently only supports stride (%i) = 4 * width (%i)", stride, w);
  }

  int nbytes = 4 * w * h;

  //Rprintf("width: %i,  height: %i,  bytes/pixel: %i,  stride: %i = %i bytes\n", w, h, bytes_per_pixel, stride, nbytes);

  unsigned char *dst = (unsigned char *)calloc(w*h*4, sizeof(unsigned char));

  memcpy(dst, result, nbytes);

  SEXP outdim = PROTECT(allocVector(INTSXP, 2));
  INTEGER(outdim)[0] = h;
  INTEGER(outdim)[1] = w;


  SEXP result_ = PROTECT(R_MakeExternalPtr(dst, outdim, R_NilValue));
  SET_CLASS(result_, mkString("unsigned char"));
  R_RegisterCFinalizer(result_, generic_finalizer);

  UNPROTECT(2);
  return result_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// cairo_surface_t * cairo_image_surface_create_for_data (unsigned char *data, cairo_format_t format, int width, int height, int stride)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_image_surface_write_array_(SEXP surface_, SEXP src_, SEXP width_, SEXP height_)  {

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Unpack source pointer
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  unsigned char *src;
  src = isNull(src_) ? NULL : (unsigned char *)R_ExternalPtrAddr(src_);
  if (src == NULL) error("cairo_image_surface_write_array_: 'unsigned char * src' pointer is invalid/NULL");


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Unpack surface ptr
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  cairo_surface_t *surface = isNull(surface_) ? NULL : (cairo_surface_t *)R_ExternalPtrAddr(surface_);
  if (surface == NULL) error("'cairo_surface_t * surface' pointer is invalid/NULL");
  unsigned char * dst = cairo_image_surface_get_data(surface);

  cairo_format_t format = cairo_image_surface_get_format(surface);


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Sanity check surface is one we know how to write to
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  if (format != CAIRO_FORMAT_ARGB32) {
    error("cairo_image_surface_get_data_raw_ only understands 4bytes/pixel CAIRO_FORMAT_ARGB32. not format=%i", format);
  }

  int w = cairo_image_surface_get_width(surface);
  int h = cairo_image_surface_get_height(surface);
  int stride = cairo_image_surface_get_stride(surface);

  if (stride != 4 * w) {
    error("cairo_image_surface_write_array_(): Currently only supports stride (%i) = 4 * width (%i)", stride, w);
  }

  int width  = INTEGER(width_)[0];
  int height = INTEGER(height_)[0];

  if (w*h != width*height) {
    error("cairo_image_surface_write_array_(): Dim mismatch between robj (%i, %i) and surface (%i, %i)", width, height, w, h);
  }

  memcpy(dst, src, w*h*4);
  cairo_surface_mark_dirty(surface);


  return R_NilValue;
}




