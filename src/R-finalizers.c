


#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <cairo/cairo.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "aaa.h"



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// generic finalizer for objects which are malloced.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void generic_finalizer(SEXP ptr_) {
  void *ptr = (void *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    free(ptr);
    R_ClearExternalPtr(ptr_);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Used internally when within R the 'externalpointer' object gets
// garbage collected
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_surface_t_finalizer(SEXP surface_ptr) {
  cairo_surface_t *surface = (cairo_surface_t *)R_ExternalPtrAddr(surface_ptr);
  if (surface != NULL) {
    cairo_surface_destroy(surface);
    R_ClearExternalPtr(surface_ptr);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Used internally when within R the 'externalpointer' object gets
// garbage collected
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_t_finalizer(SEXP ptr_) {
  cairo_t *ptr = (cairo_t *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    cairo_destroy(ptr);
    R_ClearExternalPtr(ptr_);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Used internally when within R the 'externalpointer' object gets
// garbage collected
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_pattern_t_finalizer(SEXP ptr_) {
  cairo_pattern_t *ptr = (cairo_pattern_t *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    cairo_pattern_destroy(ptr);
    R_ClearExternalPtr(ptr_);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_path_t_finalizer(SEXP ptr_) {
  cairo_path_t *ptr = (cairo_path_t *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    cairo_path_destroy(ptr);
    R_ClearExternalPtr(ptr_);
  }
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_font_face_t_finalizer(SEXP ptr_) {
  cairo_font_face_t *ptr = (cairo_font_face_t *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    cairo_font_face_destroy(ptr);
    R_ClearExternalPtr(ptr_);
  }
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void cairo_font_options_t_finalizer(SEXP ptr_) {
  cairo_font_options_t *ptr = (cairo_font_options_t *)R_ExternalPtrAddr(ptr_);
  if (ptr != NULL) {
    free(ptr);
    R_ClearExternalPtr(ptr_);
  }
}

