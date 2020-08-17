
library(stringr)



xxx <- list(
  include = TRUE,
  gtkdoc = r"{}",
  proto_text = ""
)


code0 <- readLines(here::here("data-raw/cairo/cairo-font-options.c"))
code  <- paste(code0, collapse = "\n")


code1 <- gsub("\n\\{.*?/\\*\\*", '"\n\\),\n\nxxx = list(\ninclude = FALSE,\ngtkdoc = r\\"{/**', code)

code2 <- gsub("\\*\\*/\n", '**/}\\",\nproto_text = "', code1)

writeLines(code2, here::here("data-raw/headers-r/cairo-font-options-header.R"))
