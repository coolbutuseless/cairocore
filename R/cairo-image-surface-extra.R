


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Get a \emph{copy} of the given surface as packed color in a vector of raw values
#'
#' @param surface \code{cairo_surface_t *}
#'
#' @return matrix or array of real numbers in range [0, 1]
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_get_raw <- function(surface) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  .Call("cairo_image_surface_get_raw_", surface)
}




#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Get a copy of the given surface as an array
#'
#' \code{ unsigned char * cairo_image_surface_get_data (cairo_surface_t *surface) }
#'
#' @param surface \code{cairo_surface_t *}
#' @param nchannel 1 = grey, 3 = rgb, 4 = rgba
#'
#' @return matrix or array of real numbers in range [0, 1]
#' @import pixelweaver
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_get_array <- function(surface, nchannel = 4) {
  stopifnot(inherits(surface, "cairo_surface_t"))
  argb32_ptr <- .Call("cairo_image_surface_get_array_", surface)
  # pixelweaver::packed_fmt$ARGB32 = 0
  pixelweaver::packed_to_planar(argb32_ptr, format = 0L, nchannel = nchannel)
}




#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Get a copy of the given surface as raster
#'
#' \code{ unsigned char * cairo_image_surface_get_data (cairo_surface_t *surface) }
#'
#' @param surface \code{cairo_surface_t *}
#' @param nchannel 1 = grey, 3 = rgb, 4 = rgba
#'
#' @return raster object
#'
#' @import grDevices
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_get_raster <- function(surface, nchannel = 4) {
  arr <- cairo_image_surface_get_array(surface, nchannel = nchannel)
  as.raster(arr)
}


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Write an array onto an existing surface
#'
#' \code{ int cairo_image_surface_write_robj(cairo_surface_t * surface, unsigned char *data, int width, int height) }
#' @param surface cairo surface
#' @param arr matrix, RGB array or RGBA array. numeric/double/real values only
#' @param maxval maximum value of colour representation. Usually 1.
#'
#' @import pixelweaver
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_write_array <- function(surface, arr, maxval = 1) {
  argb32_ptr <- pixelweaver::planar_to_packed(arr, format = 0L, maxval = maxval, as_ptr = TRUE)
  .Call("cairo_image_surface_write_array_", surface, argb32_ptr, ncol(arr), nrow(arr))
}



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Createa an image surface from an array
#'
#' @param arr matrix, RGB array or RGBA array
#' @param maxval maximum value of colour representation. Usually 1.
#'
#' @import pixelweaver
#' @export
#' @family bespoke
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_image_surface_create_from_array <- function(arr, maxval = 1) {

  packed_raw <- pixelweaver::planar_to_packed(
    planar_data = arr,
    format      = packed_fmt$ARGB32,
    maxval      = maxval,
    as_ptr      = FALSE
  )

  cairo_image_surface_create_for_data(
    data   = packed_raw,
    format = cairo_format_t$CAIRO_FORMAT_ARGB32,
    width  = ncol(arr),
    height = nrow(arr),
    stride = ncol(arr) * 4L
  )
}
