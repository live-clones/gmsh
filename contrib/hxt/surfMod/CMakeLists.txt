cmake_minimum_required(VERSION 3.9)
project(hxt_surfMod C)

# include guard for CMake:
# if you plan to include multiple directory that depend on this one,
# you need to include this directory first
if(TARGET hxt_surfMod)
  return()
endif()


#################################################################################
# Options
#################################################################################
option(HXT_SURFMOD_OBJECT_ONLY "Do not create hxt_surfMod library" ON)


#################################################################################
# Library definition
#################################################################################
set(HXT_SURFMOD_SRC
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hxt_surfaceModifications.c"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hxt_surfaceModifications.h")

if(HXT_SURFMOD_OBJECT_ONLY)
	add_library(hxt_surfMod OBJECT ${HXT_SURFMOD_SRC})
else()
	add_library(hxt_surfMod ${HXT_SURFMOD_SRC})
endif()

add_subdirectory(../core "${CMAKE_CURRENT_BINARY_DIR}/core")

target_include_directories(hxt_surfMod
                           PUBLIC include
                           PRIVATE src)
target_link_libraries(hxt_surfMod
                      PUBLIC hxt_core
                      PRIVATE m)

if(HXT_ENABLE_OPENMP)
  find_package(OpenMP 4)
  if(OpenMP_CXX_FOUND)
      target_link_libraries(hxt_surfMod PUBLIC OpenMP::OpenMP_CXX)
  endif()
endif()
