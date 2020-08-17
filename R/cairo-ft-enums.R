
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_ft_synthesize_t
#'
#' A set of synthesis options to control how FreeType renders the glyphs
#' for a particular font face.
#'
#' Individual synthesis features of a #cairo_ft_font_face_t can be set
#' using cairo_ft_font_face_set_synthesize(), or disabled using
#' cairo_ft_font_face_unset_synthesize(). The currently enabled set of
#' synthesis options can be queried with cairo_ft_font_face_get_synthesize().
#'
#' Note: that when synthesizing glyphs, the font metrics returned will only
#' be estimates.
#'
#' Since: 1.12
#'
#' \describe{
#' \item{CAIRO_FT_SYNTHESIZE_BOLD}{Embolden the glyphs (redraw with a pixel offset)}
#' \item{CAIRO_FT_SYNTHESIZE_OBLIQUE}{Slant the glyph outline by 12 degrees to the right.}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_ft_synthesize_t <- list(
  CAIRO_FT_SYNTHESIZE_BOLD    = 1L,
  CAIRO_FT_SYNTHESIZE_OBLIQUE = 2L
)
