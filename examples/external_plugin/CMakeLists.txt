# Builds Plugin(ElementAverage) as a shared library, against an installed Gmsh
# built as a shared library with the private API (ENABLE_BUILD_DYNAMIC and
# ENABLE_PRIVATE_API), which installs the headers of the private API in
# include/gmsh.

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

project(gmsh_plugin_example CXX)

set(CMAKE_CXX_STANDARD 17)

find_library(GMSH_LIB gmsh)
if(NOT GMSH_LIB)
  message(FATAL_ERROR "Could not find libgmsh")
endif()

find_path(GMSH_PRIVATE_INC Plugin.h PATH_SUFFIXES gmsh)
if(NOT GMSH_PRIVATE_INC)
  message(FATAL_ERROR "Could not find Plugin.h (the headers of the private API)")
endif()

add_library(ElementAverage MODULE ElementAverage.cpp)
target_include_directories(ElementAverage PRIVATE ${GMSH_PRIVATE_INC})
target_link_libraries(ElementAverage ${GMSH_LIB})
