

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
// Create a point to a cairo_text_extents_t struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_text_extents_t_(void) {
  cairo_text_extents_t * result = (cairo_text_extents_t *)calloc(1, sizeof(cairo_text_extents_t));
  SEXP result_;
  PROTECT(result_ = R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_text_extents_t"));
  R_RegisterCFinalizer(result_, generic_finalizer);
  UNPROTECT(1);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Unpack a cairo_text_extents_t into a list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_text_extents_t_to_list_(SEXP ptr_) {
  cairo_text_extents_t *ptr = isNull(ptr_) ? NULL : (cairo_text_extents_t *)R_ExternalPtrAddr(ptr_);
  if (ptr == NULL) error("'cairo_text_extents_t *' pointer is invalid/NULL");

  // Final list
  SEXP result_;
  PROTECT(result_ = NEW_LIST(6));
  SET_VECTOR_ELT(result_, 0, ScalarReal(ptr->x_bearing));
  SET_VECTOR_ELT(result_, 1, ScalarReal(ptr->y_bearing));
  SET_VECTOR_ELT(result_, 2, ScalarReal(ptr->width));
  SET_VECTOR_ELT(result_, 3, ScalarReal(ptr->height));
  SET_VECTOR_ELT(result_, 4, ScalarReal(ptr->x_advance));
  SET_VECTOR_ELT(result_, 5, ScalarReal(ptr->y_advance));

  // Set the names on the list. There's probably a macro that does this.
  SEXP names;
  PROTECT(names = allocVector(STRSXP, 6));
  SET_STRING_ELT(names, 0, mkChar("x_bearing"));
  SET_STRING_ELT(names, 1, mkChar("y_bearing"));
  SET_STRING_ELT(names, 2, mkChar("width"));
  SET_STRING_ELT(names, 3, mkChar("height"));
  SET_STRING_ELT(names, 4, mkChar("x_advance"));
  SET_STRING_ELT(names, 5, mkChar("y_advance"));
  setAttrib(result_, R_NamesSymbol, names);

  UNPROTECT(2);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Create a pointer to a "cairo_font_extents_t" struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_extents_t_(void) {
  cairo_font_extents_t * result = (cairo_font_extents_t *)calloc(1, sizeof(cairo_font_extents_t));
  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_font_extents_t"));
  R_RegisterCFinalizer(result_, generic_finalizer);
  UNPROTECT(1);
  return result_;
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Unpack a cairo_font_extents_t into a list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_font_extents_t_to_list_(SEXP ptr_) {
  cairo_font_extents_t *ptr = isNull(ptr_) ? NULL : (cairo_font_extents_t *)R_ExternalPtrAddr(ptr_);
  if (ptr == NULL) error("cairo_font_extents_t pointer is invalid/NULL");
  // Final list
  SEXP result_ = PROTECT(NEW_LIST(5));
  SET_VECTOR_ELT(result_, 0, ScalarReal(ptr->ascent));
  SET_VECTOR_ELT(result_, 1, ScalarReal(ptr->descent));
  SET_VECTOR_ELT(result_, 2, ScalarReal(ptr->height));
  SET_VECTOR_ELT(result_, 3, ScalarReal(ptr->max_x_advance));
  SET_VECTOR_ELT(result_, 4, ScalarReal(ptr->max_y_advance));

  // Set the names on the list.
  SEXP names = PROTECT(allocVector(STRSXP, 5));
  SET_STRING_ELT(names, 0, mkChar("ascent"));
  SET_STRING_ELT(names, 1, mkChar("descent"));
  SET_STRING_ELT(names, 2, mkChar("height"));
  SET_STRING_ELT(names, 3, mkChar("max_x_advance"));
  SET_STRING_ELT(names, 4, mkChar("max_y_advance"));
  setAttrib(result_, R_NamesSymbol, names);

  UNPROTECT(2);
  return result_;
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Create a pointer to a "cairo_matrix_t" struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_t_(SEXP xx_, SEXP yx_, SEXP xy_, SEXP yy_, SEXP x0_, SEXP y0_) {
  cairo_matrix_t * result = (cairo_matrix_t *)calloc(1, sizeof(cairo_matrix_t));

  result->xx = REAL(xx_)[0];
  result->yx = REAL(yx_)[0];
  result->xy = REAL(xy_)[0];
  result->yy = REAL(yy_)[0];
  result->x0 = REAL(x0_)[0];
  result->y0 = REAL(y0_)[0];

  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_matrix_t"));
  R_RegisterCFinalizer(result_, generic_finalizer);
  UNPROTECT(1);
  return result_;
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Update a pointer to a "cairo_matrix_t" struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_t_update_(SEXP ptr_, SEXP xx_, SEXP yx_, SEXP xy_, SEXP yy_, SEXP x0_, SEXP y0_) {

  cairo_matrix_t *ptr = isNull(ptr_) ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(ptr_);
  if (ptr == NULL) error("'cairo_matrix_t *' pointer is invalid/NULL");

  ptr->xx = isNull(xx_) ? ptr->xx : REAL(xx_)[0];
  ptr->yx = isNull(yx_) ? ptr->yx : REAL(yx_)[0];
  ptr->xy = isNull(xy_) ? ptr->xy : REAL(xy_)[0];
  ptr->yy = isNull(yy_) ? ptr->yy : REAL(yy_)[0];
  ptr->x0 = isNull(x0_) ? ptr->x0 : REAL(x0_)[0];
  ptr->y0 = isNull(y0_) ? ptr->y0 : REAL(y0_)[0];

  return ptr_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Unpack a cairo_text_extents_t into a list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_matrix_t_to_list_(SEXP ptr_) {
  cairo_matrix_t *ptr = isNull(ptr_) ? NULL : (cairo_matrix_t *)R_ExternalPtrAddr(ptr_);
  if (ptr == NULL) error("'cairo_matrix_t *' pointer is invalid/NULL");

  // Final list
  SEXP result_;
  PROTECT(result_ = NEW_LIST(6));
  SET_VECTOR_ELT(result_, 0, ScalarReal(ptr->xx));
  SET_VECTOR_ELT(result_, 1, ScalarReal(ptr->yx));
  SET_VECTOR_ELT(result_, 2, ScalarReal(ptr->xy));
  SET_VECTOR_ELT(result_, 3, ScalarReal(ptr->yy));
  SET_VECTOR_ELT(result_, 4, ScalarReal(ptr->x0));
  SET_VECTOR_ELT(result_, 5, ScalarReal(ptr->y0));

  // Set the names on the list. There's probably a macro that does this.
  SEXP names;
  PROTECT(names = allocVector(STRSXP, 6));
  SET_STRING_ELT(names, 0, mkChar("xx"));
  SET_STRING_ELT(names, 1, mkChar("yx"));
  SET_STRING_ELT(names, 2, mkChar("xy"));
  SET_STRING_ELT(names, 3, mkChar("yy"));
  SET_STRING_ELT(names, 4, mkChar("x0"));
  SET_STRING_ELT(names, 5, mkChar("y0"));
  setAttrib(result_, R_NamesSymbol, names);

  UNPROTECT(2);
  return result_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Create a pointer to a "cairo_rectangle_t" struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rectangle_t_(SEXP x_, SEXP y_, SEXP width_, SEXP height_) {
  cairo_rectangle_t * result = (cairo_rectangle_t *)calloc(1, sizeof(cairo_rectangle_t));

  result->x      = REAL(x_)[0];
  result->y      = REAL(y_)[0];
  result->width  = REAL(width_)[0];
  result->height = REAL(height_)[0];

  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_rectangle_t"));
  R_RegisterCFinalizer(result_, generic_finalizer);
  UNPROTECT(1);
  return result_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Unpack a cairo_text_extents_t into a list
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rectangle_t_to_list_(SEXP ptr_) {
  cairo_rectangle_t *ptr = isNull(ptr_) ? NULL : (cairo_rectangle_t *)R_ExternalPtrAddr(ptr_);
  if (ptr == NULL) error("'cairo_rectangle_t *' pointer is invalid/NULL");

  // Final list
  SEXP result_;
  PROTECT(result_ = NEW_LIST(4));
  SET_VECTOR_ELT(result_, 0, ScalarReal(ptr->x));
  SET_VECTOR_ELT(result_, 1, ScalarReal(ptr->y));
  SET_VECTOR_ELT(result_, 2, ScalarReal(ptr->width));
  SET_VECTOR_ELT(result_, 3, ScalarReal(ptr->height));

  // Set the names on the list. There's probably a macro that does this.
  SEXP names;
  PROTECT(names = allocVector(STRSXP, 4));
  SET_STRING_ELT(names, 0, mkChar("x"));
  SET_STRING_ELT(names, 1, mkChar("y"));
  SET_STRING_ELT(names, 2, mkChar("width"));
  SET_STRING_ELT(names, 3, mkChar("height"));
  setAttrib(result_, R_NamesSymbol, names);

  UNPROTECT(2);
  return result_;
}




//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Create a pointer to a "cairo_rectangle_int_t" struct
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rectangle_int_t_(SEXP x_, SEXP y_, SEXP width_, SEXP height_) {
  cairo_rectangle_int_t * result = (cairo_rectangle_int_t *)calloc(1, sizeof(cairo_rectangle_int_t));

  result->x      = INTEGER(x_)[0];
  result->y      = INTEGER(y_)[0];
  result->width  = INTEGER(width_)[0];
  result->height = INTEGER(height_)[0];

  SEXP result_ = PROTECT(R_MakeExternalPtr(result, R_NilValue, R_NilValue));
  SET_CLASS(result_, mkString("cairo_rectangle_int_t"));
  R_RegisterCFinalizer(result_, generic_finalizer);
  UNPROTECT(1);
  return result_;
}

