cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

find_library(GMSH_LIB gmsh)
if(NOT GMSH_LIB)
  message(FATAL_ERROR "Could not find libgmsh")
endif(NOT GMSH_LIB)

find_path(GMSH_INC gmsh.h)
if(NOT GMSH_INC)
  message(FATAL_ERROR "Could not find gmsh.h")
endif(NOT GMSH_INC)

if(GMSH_LIB MATCHES ".a")
  find_library(BLAS_LIB blas)
  find_library(LAPACK_LIB lapack)
endif(GMSH_LIB MATCHES ".a")

include_directories(${GMSH_INC})

add_executable(t0 t0.cpp)
target_link_libraries(t0 ${GMSH_LIB} ${LAPACK_LIB} ${BLAS_LIB})
