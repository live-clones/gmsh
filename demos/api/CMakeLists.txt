cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# TODO: Gmsh should create a cmake file when installing the lib, so all the
# external dependencies can be obtained automatically

set(CMAKE_CXX_STANDARD 11)

find_library(GMSH_LIB gmsh)
if(NOT GMSH_LIB)
  message(FATAL_ERROR "Could not find libgmsh")
endif()

find_path(GMSH_INC gmsh.h)
if(NOT GMSH_INC)
  message(FATAL_ERROR "Could not find gmsh.h")
endif()

if(GMSH_LIB MATCHES ".a") # FIXME - generalize this
  find_library(BLAS_LIB blas)
  if(BLAS_LIB)
    list(APPEND EXTRA_LIBS ${BLAS_LIB})
  endif()
  find_library(LAPACK_LIB lapack)
  if(LAPACK_LIB)
    list(APPEND EXTRA_LIBS ${LAPACK_LIB})
  endif()
endif()

if(WIN32 OR CYGWIN)
  list(APPEND EXTRA_LIBS winmm wsock32 ws2_32 psapi)
endif()

include_directories(${GMSH_INC})

include(CTest)

file(GLOB DEMOS *.cpp)
foreach(DEMO ${DEMOS})
  get_filename_component(DEMONAME ${DEMO} NAME_WE)
  if(${DEMONAME} MATCHES "(gui|adapt_mesh|spline|spherical_surf)")
    add_executable(${DEMONAME} WIN32 MACOSX_BUNDLE ${DEMO})
    if(APPLE)
      add_test(${DEMONAME} ${DEMONAME}.app/Contents/MacOS/${DEMONAME})
    else()
      add_test(${DEMONAME} ${DEMONAME})
    endif()
  else()
    add_executable(${DEMONAME} ${DEMO})
    add_test(${DEMONAME}_cpp ${DEMONAME})
  endif()
  target_link_libraries(${DEMONAME} ${GMSH_LIB} ${EXTRA_LIBS})
endforeach()

file(GLOB DEMOS *.c)
foreach(DEMO ${DEMOS})
  get_filename_component(DEMONAME ${DEMO} NAME_WE)
  add_executable(${DEMONAME}c ${DEMO})
  target_link_libraries(${DEMONAME}c ${GMSH_LIB} ${EXTRA_LIBS})
  add_test(${DEMONAME}_c ${DEMONAME}c)
endforeach()

find_program(PYTHON python)
if(PYTHON)
  file(GLOB DEMOS *.py)
  foreach(DEMO ${DEMOS})
    get_filename_component(DEMONAME ${DEMO} NAME_WE)
    add_test(${DEMONAME}_py ${PYTHON} ${DEMO})
  endforeach()
endif()

find_program(JULIA julia)
if(JULIA)
  file(GLOB DEMOS *.jl)
  foreach(DEMO ${DEMOS})
    get_filename_component(DEMONAME ${DEMO} NAME_WE)
    add_test(${DEMONAME}_jl ${JULIA} ${DEMO})
  endforeach()
endif()
