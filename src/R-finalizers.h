

#include <R.h>
#include <Rinternals.h>
#include <Rdefines.h>
#include <cairo/cairo.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void generic_finalizer(SEXP ptr_);
void cairo_surface_t_finalizer(SEXP surface_ptr);
void cairo_t_finalizer(SEXP context_ptr);
void cairo_pattern_t_finalizer(SEXP ptr_);
void cairo_path_t_finalizer(SEXP ptr_);
void cairo_font_face_t_finalizer(SEXP ptr_);
void cairo_font_options_t_finalizer(SEXP ptr_);
