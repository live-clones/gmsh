cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# TODO: Gmsh will should create a cmake file when installing the lib, so all the
# external dependencies can be obtained automatically

set(CMAKE_CXX_STANDARD 11)

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

file(GLOB FILES *.cpp)
foreach(FILE ${FILES})
  get_filename_component(DEMO ${FILE} NAME_WE)
  add_executable(${DEMO} ${FILE})
  target_link_libraries(${DEMO} ${GMSH_LIB} ${LAPACK_LIB} ${BLAS_LIB})
endforeach(FILE)
