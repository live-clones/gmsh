cmake_minimum_required(VERSION 3.9)
project(hxt_core C)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_core)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_ENABLE_OPENMP "Enable OpenMP" ON)
option(HXT_ALIGN_ALLOCATIONS "Align allocation" OFF)
option(HXT_CORE_OBJECT_ONLY "Do not create hxt_core library" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_CORE_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_bbox.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_mesh.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_message.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_opt.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_sort.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_bbox.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_mesh.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_message.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_omp.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_opt.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_sort.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_tools.h"
   )

if(HXT_CORE_OBJECT_ONLY)
  # make an object library (no archive)
  add_library(hxt_core OBJECT ${HXT_CORE_SRC})
else()
  add_library(hxt_core ${HXT_CORE_SRC})
endif()
target_include_directories(hxt_core PUBLIC include)
target_compile_features(hxt_core PRIVATE c_std_99)

if(HXT_ENABLE_OPENMP)
  find_package(OpenMP 4)
  if(OpenMP_C_FOUND)
      target_link_libraries(hxt_core PUBLIC OpenMP::OpenMP_C)
  endif()
endif()


#################################################################################
# Compilation flags corresponding to options
#################################################################################
if(HXT_ALIGN_ALLOCATIONS)
	target_compile_definitions(hxt_core PUBLIC HXT_ALIGN_ALLOCATIONS)
endif()
