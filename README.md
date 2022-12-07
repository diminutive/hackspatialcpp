
<!-- README.md is generated from README.Rmd. Please edit that file -->

# hackspatialcpp

<!-- badges: start -->
<!-- badges: end -->

The goal of hackspatialcpp is to check spatial stuff and learn C++.

Not for general use.

## Example

This is a basic example, mostly I’ve stolen code from fasterize. Some of
the work here will end up in fasterize, and/or controlledburn.

``` r
library(hackspatialcpp)

hackspatialcpp:::get_wkt_sf(badsf)
#> [1] NA

hackspatialcpp:::get_wkt_sf(sf::st_set_crs(badsf, 4326))
#> old-style crs object detected; please recreate object with a recent sf::st_crs()
#> [1] "GEOGCRS[\"WGS 84\",\n    ENSEMBLE[\"World Geodetic System 1984 ensemble\",\n        MEMBER[\"World Geodetic System 1984 (Transit)\"],\n        MEMBER[\"World Geodetic System 1984 (G730)\"],\n        MEMBER[\"World Geodetic System 1984 (G873)\"],\n        MEMBER[\"World Geodetic System 1984 (G1150)\"],\n        MEMBER[\"World Geodetic System 1984 (G1674)\"],\n        MEMBER[\"World Geodetic System 1984 (G1762)\"],\n        MEMBER[\"World Geodetic System 1984 (G2139)\"],\n        ELLIPSOID[\"WGS 84\",6378137,298.257223563,\n            LENGTHUNIT[\"metre\",1]],\n        ENSEMBLEACCURACY[2.0]],\n    PRIMEM[\"Greenwich\",0,\n        ANGLEUNIT[\"degree\",0.0174532925199433]],\n    CS[ellipsoidal,2],\n        AXIS[\"geodetic latitude (Lat)\",north,\n            ORDER[1],\n            ANGLEUNIT[\"degree\",0.0174532925199433]],\n        AXIS[\"geodetic longitude (Lon)\",east,\n            ORDER[2],\n            ANGLEUNIT[\"degree\",0.0174532925199433]],\n    USAGE[\n        SCOPE[\"Horizontal component of 3D system.\"],\n        AREA[\"World.\"],\n        BBOX[-90,-180,90,180]],\n    ID[\"EPSG\",4326]]"

hackspatialcpp:::check_class_sf(badsf)
#> [1] TRUE

try(hackspatialcpp:::check_class_sf(mtcars))
#> Error in hackspatialcpp:::check_class_sf(mtcars) : 
#>   sf must be of class sf.
```

## Code of Conduct

Please note that the hackspatialcpp project is released with a
[Contributor Code of
Conduct](https://contributor-covenant.org/version/2/1/CODE_OF_CONDUCT.html).
By contributing to this project, you agree to abide by its terms.
