cmake_minimum_required(VERSION 3.14)
project(lightsplusplus)
include_directories(${CMAKE_SOURCE_DIR}/libs)
include(FindPkgConfig)

pkg_check_modules(CURLPP REQUIRED curlpp)
include_directories(../libs/json)


file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "./*.cpp")

include_directories(../include)
add_library(lightsplusplus lightspp.cpp HTTPHandler.cpp jsoncpp.cpp)
target_link_libraries(lightsplusplus ${CURLPP_LDFLAGS})

