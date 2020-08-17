
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
// Replicate a length 1 R vector (rvar) to match another (nvar)
// and store in (cvar).  If the vector (rvar) is the same length as (nvar)
// then just use as-is.
// New memory will only be allocated if the length of the variable is 1, otherwise
// we just a pointer to it in the C code
// If the length of the variable is not 1 or length of (nvar) then throw
// an error
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define replicate_dbl(cvar, rvar, n)                                                                         \
double *(cvar) = (double *)REAL((rvar));                                                                     \
if (length((rvar)) == 1) {                                                                                   \
  (cvar) = (double *)calloc((n), sizeof(double));                                                            \
  double tmp = REAL((rvar))[0];                                                                              \
  for (int i = 0; i < (n); i++) (cvar)[i] = tmp;                                                             \
} else if (length((rvar)) != (n)) {                                                                          \
  error("Variable '" #cvar "' must be length " #n " or 1");                                                  \
};                                                                                                           \



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Free memory if we allocated it
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#define replicate_free(cvar, rvar)   \
if (length((rvar)) == 1) free(cvar); \





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_arc (cairo_t *cr, double xc, double yc, double radius, double angle1, double angle2)
//
// Allow all arguments to be vectorised
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_arc_vec_(SEXP cr_, SEXP xc_, SEXP yc_, SEXP radius_,
                    SEXP angle1_, SEXP angle2_,
                    SEXP r_, SEXP g_, SEXP b_, SEXP a_,
                    SEXP sr_, SEXP sg_, SEXP sb_, SEXP sa_)  {
  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  double *xc = (double *)REAL(xc_);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // If a variable is length 1, allocate memory and replicate it to be the
  // same length as x_.   Otherwise just use a pointer to the SEXP array.
  // If the argument isn't length 1 or length x_, then throw an error
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  int nx = length(xc_);
  replicate_dbl(yc    , yc_    , nx);
  replicate_dbl(radius, radius_, nx);
  replicate_dbl(angle1, angle1_, nx);
  replicate_dbl(angle2, angle2_, nx);
  replicate_dbl(r     , r_     , nx);
  replicate_dbl(g     , g_     , nx);
  replicate_dbl(b     , b_     , nx);
  replicate_dbl(a     , a_     , nx);
  replicate_dbl(sr    , sr_    , nx);
  replicate_dbl(sg    , sg_    , nx);
  replicate_dbl(sb    , sb_    , nx);
  replicate_dbl(sa    , sa_    , nx);


  for (int i = 0; i < length(xc_); i++) {
    cairo_arc(cr, xc[i], yc[i], radius[i], angle1[i], angle2[i]);
    cairo_set_source_rgba(cr, r[i], g[i], b[i], a[i]);
    cairo_fill_preserve(cr);
    cairo_set_source_rgba(cr, sr[i], sg[i], sb[i], sa[i]);
    cairo_stroke(cr);
  }


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Free the memory if we allocated it
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  replicate_free(yc    , yc_    );
  replicate_free(radius, radius_);
  replicate_free(angle1, angle1_);
  replicate_free(angle2, angle2_);
  replicate_free(r     , r_     );
  replicate_free(g     , g_     );
  replicate_free(b     , b_     );
  replicate_free(a     , a_     );
  replicate_free(sr    , sr_    );
  replicate_free(sg    , sg_    );
  replicate_free(sb    , sb_    );
  replicate_free(sa    , sa_    );


  return R_NilValue;
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rectangle (cairo_t *cr, double x, double y, double width, double height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_rectangle_vec_(SEXP cr_, SEXP x_, SEXP y_, SEXP width_, SEXP height_,
                          SEXP r_, SEXP g_, SEXP b_, SEXP a_,
                          SEXP sr_, SEXP sg_, SEXP sb_, SEXP sa_)  {
  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  double *x = (double *)REAL(x_);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // If a variable is length 1, allocate memory and replicate it to be the
  // same length as x_.   Otherwise just use a pointer to the SEXP array.
  // If the argument isn't length 1 or length x_, then throw an error
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  int nx = length(x_);
  replicate_dbl(y     , y_     , nx);
  replicate_dbl(width , width_ , nx);
  replicate_dbl(height, height_, nx);
  replicate_dbl(r     , r_     , nx);
  replicate_dbl(g     , g_     , nx);
  replicate_dbl(b     , b_     , nx);
  replicate_dbl(a     , a_     , nx);
  replicate_dbl(sr    , sr_    , nx);
  replicate_dbl(sg    , sg_    , nx);
  replicate_dbl(sb    , sb_    , nx);
  replicate_dbl(sa    , sa_    , nx);


  for (int i = 0; i < length(x_); i++) {
    cairo_rectangle(cr, x[i], y[i], width[i], height[i]);
    cairo_set_source_rgba(cr, r[i], g[i], b[i], a[i]);
    cairo_fill_preserve(cr);
    cairo_set_source_rgba(cr, sr[i], sg[i], sb[i], sa[i]);
    cairo_stroke(cr);
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Free the memory if we allocated it
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  replicate_free(y     , y_     );
  replicate_free(width , width_ );
  replicate_free(height, height_);
  replicate_free(r     , r_     );
  replicate_free(g     , g_     );
  replicate_free(b     , b_     );
  replicate_free(a     , a_     );
  replicate_free(sr    , sr_    );
  replicate_free(sg    , sg_    );
  replicate_free(sb    , sb_    );
  replicate_free(sa    , sa_    );


  return R_NilValue;
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// void cairo_rectangle (cairo_t *cr, double x, double y, double width, double height)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_segment_vec_(SEXP cr_, SEXP x1_, SEXP y1_, SEXP x2_, SEXP y2_,
                        SEXP r_, SEXP g_, SEXP b_, SEXP a_)  {
  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  double *x1 = (double *)REAL(x1_);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // If a variable is length 1, allocate memory and replicate it to be the
  // same length as x_.   Otherwise just use a pointer to the SEXP array.
  // If the argument isn't length 1 or length x_, then throw an error
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  int nx = length(x1_);

  replicate_dbl(y1, y1_, nx);
  replicate_dbl(x2, x2_, nx);
  replicate_dbl(y2, y2_, nx);

  replicate_dbl(r, r_, nx);
  replicate_dbl(g, g_, nx);
  replicate_dbl(b, b_, nx);
  replicate_dbl(a, a_, nx);


  for (int i = 0; i < nx; i++) {
    cairo_set_source_rgba(cr, r[i], g[i], b[i], a[i]);
    cairo_move_to(cr, x1[i], y1[i]);
    cairo_line_to(cr, x2[i], y2[i]);
    cairo_stroke(cr);
  }

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Free the memory if we allocated it
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  replicate_free(y1    , y1_     );
  replicate_free(x2    , x2_     );
  replicate_free(y2    , y2_     );

  replicate_free(r     , r_     );
  replicate_free(g     , g_     );
  replicate_free(b     , b_     );
  replicate_free(a     , a_     );


  return R_NilValue;
}





//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
SEXP cairo_polygon_vec_(SEXP cr_, SEXP x_, SEXP y_, SEXP idx_,
                       SEXP r_, SEXP g_, SEXP b_, SEXP a_,
                       SEXP sr_, SEXP sg_, SEXP sb_, SEXP sa_)  {

  cairo_t *cr = isNull(cr_) ? NULL : (cairo_t *)R_ExternalPtrAddr(cr_);
  if (cr == NULL) error("'cairo_t * cr' pointer is invalid/NULL");

  double *x = (double *)REAL(x_);
  double *y = (double *)REAL(y_);
  int *idx = (int *)INTEGER(idx_);

  int nx = length(x_);
  int ny = length(y_);
  int ni = length(idx_);

  if (nx == 0 || ny != nx || ni != nx) {
    error("x, y, idx should all be the same length");
  }

  int npolys = 1;
  int last = idx[0];
  for (int i = 1; i < ni ; i++) {
    if (idx[i] != last) {
      last = idx[i];
      npolys++;
    }
  }

  //Rprintf("n polys: %i\n", npolys);

  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // If a variable is length 1, allocate memory and replicate it to be the
  // same length as x_.   Otherwise just use a pointer to the SEXP array.
  // If the argument isn't length 1 or length x_, then throw an error
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  replicate_dbl(r     , r_     , npolys);
  replicate_dbl(g     , g_     , npolys);
  replicate_dbl(b     , b_     , npolys);
  replicate_dbl(a     , a_     , npolys);
  replicate_dbl(sr    , sr_    , npolys);
  replicate_dbl(sg    , sg_    , npolys);
  replicate_dbl(sb    , sb_    , npolys);
  replicate_dbl(sa    , sa_    , npolys);


  int i = 0;

  for (int poly = 0; poly < npolys; poly++) {
    int current_idx = idx[i];
    cairo_move_to(cr, x[i], y[i]);
    i++;
    while (i < nx && current_idx == idx[i]) {
      cairo_line_to(cr, x[i], y[i]);
      i++;
    }
    cairo_close_path(cr);
    cairo_set_source_rgba(cr, r[poly], g[poly], b[poly], a[poly]);
    cairo_fill_preserve(cr);
    cairo_set_source_rgba(cr, sr[poly], sg[poly], sb[poly], sa[poly]);
    cairo_stroke(cr);
  }


  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // Free the memory if we allocated it
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  replicate_free(r     , r_     );
  replicate_free(g     , g_     );
  replicate_free(b     , b_     );
  replicate_free(a     , a_     );
  replicate_free(sr    , sr_    );
  replicate_free(sg    , sg_    );
  replicate_free(sb    , sb_    );
  replicate_free(sa    , sa_    );


  return R_NilValue;
}





