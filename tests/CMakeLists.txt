cmake_minimum_required(VERSION 3.14)
project(lights_tests)

SET(COVERAGE OFF CACHE BOOL "Coverage")

file(GLOB_RECURSE TEST_FILES RELATIVE ${CMAKE_SOURCE_DIR} "*.cpp")
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")

FIND_PACKAGE(Boost REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

add_executable(runAllTests main.cpp ${Boost_LIBRARIES} ${SOURCE_FILES})
target_link_libraries(runAllTests lightsplusplus boost_system boost_filesystem gtest gtest_main)
target_compile_options(runAllTests PRIVATE -O3 -std=c++14 -g -Wall -Werror -Wextra -Wpedantic -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow)
add_subdirectory(libs)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(libs)
include_directories(../include)

