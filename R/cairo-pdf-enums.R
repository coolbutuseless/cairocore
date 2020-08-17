

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_version_t
#'
#' #cairo_pdf_version_t is used to describe the version number of the PDF
#' specification that a generated PDF file will conform to.
#'
#' Since: 1.10
#'
#' \describe{
#' \item{CAIRO_PDF_VERSION_1_4}{The version 1.4 of the PDF specification. (Since 1.10)}
#' \item{CAIRO_PDF_VERSION_1_5}{The version 1.5 of the PDF specification. (Since 1.10)}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_version_t <- list(
  CAIRO_PDF_VERSION_1_4 =    0L,
  CAIRO_PDF_VERSION_1_5 =    1L
)


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_outline_flags_t
#'
#' #cairo_pdf_outline_flags_t is used by the
#' cairo_pdf_surface_add_outline() function specify the attributes of
#' an outline item. These flags may be bitwise-or'd to produce any
#' combination of flags.
#'
#' Since: 1.16
#'
#' \describe{
#' \item{CAIRO_PDF_OUTLINE_FLAG_OPEN}{The outline item defaults to open in the PDF viewer (Since 1.16)}
#' \item{CAIRO_PDF_OUTLINE_FLAG_BOLD}{The outline item is displayed by the viewer in bold text (Since 1.16)}
#' \item{CAIRO_PDF_OUTLINE_FLAG_ITALIC}{The outline item is displayed by the viewer in italic text (Since 1.16)}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_outline_flags_t <- list(
  CAIRO_PDF_OUTLINE_FLAG_OPEN   =    1L,
  CAIRO_PDF_OUTLINE_FLAG_BOLD   =    2L,
  CAIRO_PDF_OUTLINE_FLAG_ITALIC =    4L
)


#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' cairo_pdf_metadata_t
#'
#' #cairo_pdf_metadata_t is used by the
#' cairo_pdf_surface_set_metadata() function specify the metadata to set.
#'
#' Since: 1.16
#'
#' \describe{
#' \item{CAIRO_PDF_METADATA_TITLE}{The document title (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_AUTHOR}{The document author (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_SUBJECT}{The document subject (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_KEYWORDS}{The document keywords (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_CREATOR}{The document creator (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_CREATE_DATE}{The document creation date (Since 1.16)}
#' \item{CAIRO_PDF_METADATA_MOD_DATE}{The document modification date (Since 1.16)}
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
cairo_pdf_metadata_t <- list(
  CAIRO_PDF_METADATA_TITLE       =    0L,
  CAIRO_PDF_METADATA_AUTHOR      =    1L,
  CAIRO_PDF_METADATA_SUBJECT     =    2L,
  CAIRO_PDF_METADATA_KEYWORDS    =    3L,
  CAIRO_PDF_METADATA_CREATOR     =    4L,
  CAIRO_PDF_METADATA_CREATE_DATE =    5L,
  CAIRO_PDF_METADATA_MOD_DATE    =    6L
)



