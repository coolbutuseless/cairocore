

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_version_t
#'
#' #cairo_svg_version_t is used to describe the version number of the SVG
#' specification that a generated SVG file will conform to.
#'
#' Since: 1.2
#'
#' \describe{
#' \item{CAIRO_SVG_VERSION_1_1}{The version 1.1 of the SVG specification. (Since 1.2)}
#' \item{CAIRO_SVG_VERSION_1_2}{The version 1.2 of the SVG specification. (Since 1.2)}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_version_t <- list(
  CAIRO_SVG_VERSION_1_1 =    0L,
  CAIRO_SVG_VERSION_1_2 =    1L
)


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_svg_unit_t
#'
#' #cairo_svg_unit_t is used to describe the units valid for coordinates and
#' lengths in the SVG specification.
#'
#' See also:
#' https://www.w3.org/TR/SVG/coords.html#Units
#' https://www.w3.org/TR/SVG/types.html#DataTypeLength
#' https://www.w3.org/TR/css-values-3/#lengths
#'
#' Since: 1.16
#'
#' \describe{
#' \item{CAIRO_SVG_UNIT_USER}{User unit, a value in the current coordinate system. If used in the root element for the initial coordinate systems it corresponds to pixels. (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_EM}{The size of the element's font. (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_EX}{The x-height of the element’s font. (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_PX}{Pixels (1px = 1/96th of 1in). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_IN}{Inches (1in = 2.54cm = 96px). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_CM}{Centimeters (1cm = 96px/2.54). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_MM}{Millimeters (1mm = 1/10th of 1cm). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_PT}{Points (1pt = 1/72th of 1in). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_PC}{Picas (1pc = 1/6th of 1in). (Since 1.16)}
#' \item{CAIRO_SVG_UNIT_PERCENT}{Percent, a value that is some fraction of another reference value. (Since 1.16)}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_svg_unit_t <- list(
  CAIRO_SVG_UNIT_USER    =    0L,
  CAIRO_SVG_UNIT_EM      =    1L,
  CAIRO_SVG_UNIT_EX      =    2L,
  CAIRO_SVG_UNIT_PX      =    3L,
  CAIRO_SVG_UNIT_IN      =    4L,
  CAIRO_SVG_UNIT_CM      =    5L,
  CAIRO_SVG_UNIT_MM      =    6L,
  CAIRO_SVG_UNIT_PT      =    7L,
  CAIRO_SVG_UNIT_PC      =    8L,
  CAIRO_SVG_UNIT_PERCENT =    9L
)
