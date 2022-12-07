#' @keywords internal
"_PACKAGE"

## usethis namespace: start
#' @importFrom Rcpp sourceCpp
#' @useDynLib hackspatialcpp, .registration = TRUE
## usethis namespace: end
NULL


#' bad sf, very bad
#'
#' A sf object with an old crs (no $wkt and a materialized $proj4string)
#'
#' @name badsf
#' @docType data
NULL
