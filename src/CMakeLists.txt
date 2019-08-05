cmake_minimum_required(VERSION 3.14)
project(lightsplusplus)
include_directories(${CMAKE_SOURCE_DIR}/libs)
include(FindPkgConfig)

pkg_check_modules(CURLPP REQUIRED curlpp)
include_directories(../libs/json)

file(GLOB_RECURSE SOURCE_FILES "*.cpp")
include_directories(../include)
include_directories(../include/exceptions)
add_library(lightsplusplus ${SOURCE_FILES})
target_link_libraries(lightsplusplus ${CURLPP_LDFLAGS})

