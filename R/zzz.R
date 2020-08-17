
.env <- new.env(parent = emptyenv())

.onLoad <- function(...) {

  # Keep track of whether pkg has shown warning about memory-related functions
  .env$warned <- FALSE
}
