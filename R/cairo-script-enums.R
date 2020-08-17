#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_script_mode_t
#'
#' A set of script output variants.
#'
#' Since: 1.12
#'
#' \describe{
#' \item{CAIRO_SCRIPT_MODE_ASCII}{the output will be in readable text (default). (Since 1.12)}
#' \item{CAIRO_SCRIPT_MODE_BINARY}{the output will use byte codes. (Since 1.12)}
#' }
#'
#' @export
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_script_mode_t <- list(
  CAIRO_SCRIPT_MODE_ASCII  =    0L,
  CAIRO_SCRIPT_MODE_BINARY =    1L
)
