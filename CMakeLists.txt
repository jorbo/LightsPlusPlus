cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)
SET(CMAKE_CXX_FLAGS "-std=gnu++11")
project(lightsplusplus)


add_library(lightsplusplus src/bridge.cpp src/HTTPHandler.cpp src/lightspp.cpp)
include_directories(include)
include_directories(libs)
add_subdirectory(src)
add_subdirectory(libs)
target_link_libraries(lightsplusplus ${CURLPP_LDFLAGS} jsoncpp)

