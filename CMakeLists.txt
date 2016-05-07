cmake_minimum_required(VERSION 3.5)
project(gjk_eap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


#
# Dependencies
#
add_subdirectory(deps/glm)

include_directories(
        src
        deps/glm)

file(GLOB SOURCE_FILES
        src/collision/*
        src/geometry/*
        src/math/*)

list(APPEND SOURCE_FILES Main.cpp)
add_executable(gjk_eap ${SOURCE_FILES})