#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
CharacterVector get_wkt_sf(Rcpp::DataFrame &sf) {

  std::stringstream err_msg;

  if(!Rf_inherits(sf, "sf")) {
    err_msg << "sf must be of class sf." << std::endl;
  }

  std::string err = err_msg.str();
  if(!err.empty()) {
    Rcpp::stop(err);
  }
  Rcpp::List polygons;
  polygons = sf[Rcpp::as<std::string>(sf.attr("sf_column"))];
  List crs;
  crs = polygons.attr("crs");
  CharacterVector crs_wkt;
  bool ok = false;
  // check first if we have the name
  Rcpp::CharacterVector nv = crs.names();
  for (int i=0; i<nv.size(); i++) {
    if (std::string(nv[i]) == "wkt") {
      ok = true;
    }
  }

  if (ok) {
    crs_wkt = as<CharacterVector>(crs["wkt"]);
  } else {
    crs_wkt = CharacterVector::create(NA_STRING);
  }




  return crs_wkt;

}

// [[Rcpp::export]]
LogicalVector check_class_sf(Rcpp::DataFrame &sf) {

  std::stringstream err_msg;

  if(!Rf_inherits(sf, "sf")) {
    err_msg << "sf must be of class sf." << std::endl;
  }

  std::string err1 = err_msg.str();
  if(!err1.empty()) {
    Rcpp::stop(err1);
  }
  Rcpp::List polygons;
  polygons = sf[Rcpp::as<std::string>(sf.attr("sf_column"))];

  if(!(Rf_inherits(polygons, "sfc_MULTIPOLYGON") |
     Rf_inherits(polygons, "sfc_POLYGON"))) {
    err_msg << "sf geometry must be POLYGON or MULTIPOLYGON" << std::endl;
  }

  std::string err = err_msg.str();
  if(!err.empty()) {
    Rcpp::stop(err);
  }
  return true;
}

// [[Rcpp::export]]
LogicalVector something_with_raster(Rcpp::S4 &raster) {
 return false;
}
