include_directories(${CMAKE_SOURCE_DIR}/libs)
include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)