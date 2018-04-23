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
  if(BLAS_LIB)
    list(APPEND EXTRA_LIBS ${BLAS_LIB})
  endif(BLAS_LIB)
  find_library(LAPACK_LIB lapack)
  if(LAPACK_LIB)
    list(APPEND EXTRA_LIBS ${LAPACK_LIB})
  endif(LAPACK_LIB)
endif(GMSH_LIB MATCHES ".a")

if(WIN32 OR CYGWIN)
  list(APPEND EXTRA_LIBS winmm wsock32 ws2_32 psapi)
endif(WIN32 OR CYGWIN)

include_directories(${GMSH_INC})

file(GLOB DEMOS *.cpp)
foreach(DEMO ${DEMOS})
  get_filename_component(DEMONAME ${DEMO} NAME_WE)
  if(${DEMONAME} MATCHES "(gui|adapt_mesh|spline)")
    add_executable(${DEMONAME} WIN32 MACOSX_BUNDLE ${DEMO})
  else()
    add_executable(${DEMONAME} ${DEMO})
  endif()
  target_link_libraries(${DEMONAME} ${GMSH_LIB} ${EXTRA_LIBS})
endforeach(DEMO)

file(GLOB DEMOS *.c)
foreach(DEMO ${DEMOS})
  get_filename_component(DEMONAME ${DEMO} NAME_WE)
  add_executable(${DEMONAME}c ${DEMO})
  target_link_libraries(${DEMONAME}c ${GMSH_LIB} ${EXTRA_LIBS})
endforeach(DEMO)
