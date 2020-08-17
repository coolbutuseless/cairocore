

#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Given a list representing an enum and a value, return the name corresponding to that value
#'
#' Helper function for dealing with C-style enums which are coded as lists
#' in R
#'
#' @param enum named list of integers representing an enum
#' @param value the enum integer value
#'
#' @return return character string name or NULL
#'
#' @examples
#' \dontrun{
#' cairo_antialias_t
#' enum_lookup(cairo_antialias_t, 3)
#' }
#'
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum_lookup <- function(enum, value) {
  if (value %in% enum) {
    names(which(enum == value))
  } else {
    NULL
  }
}



#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#' Find the name of the enum which contains the given member
#'
#' @param name name of an enum member, taken from C e.g. 'CAIRO_FORMAT_ARGB32'
#'
#' @return character string wih name enum which contains this member, or NULL
#'         if member not found in any enum
#'
#' @examples
#' \dontrun{
#' enum_find('CAIRO_FORMAT_ARGB32')
#' }
#'
#' @export
#' @family enum
#~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
enum_find <- function(name) {

  all_names <- ls(asNamespace('cairocore'))
  t_names <- grep("_t$", all_names, value = TRUE)

  for (t_name in t_names) {
    v <- get(t_name, envir = asNamespace('cairocore'))
    if (is.list(v)) {
      if (name %in% names(v)) {
        return(t_name)
      }
    }
  }

  return(NULL)
}




if (FALSE) {
  enum_lookup(cairo_antialias_t, 3)
}










