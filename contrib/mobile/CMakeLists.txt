# Library to use Onelab (Gmsh/GetDP) on Android or iOS

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(DEFAULT ON CACHE INTERNAL "Default value for enabled-by-default options")

option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" ON)
option(ENABLE_BUILD_IOS "Build library for iOS (ARM)" OFF)
option(ENABLE_BUILD_IOS_EMULATOR "Build library for iOS emulator (x86)" OFF)

macro(set_config_option VARNAME STRING)
  set(${VARNAME} TRUE)
  list(APPEND CONFIG_OPTIONS ${STRING})
  message(STATUS "Found " ${STRING})
endmacro(set_config_option)

macro(append_src FILES)
  foreach(FILE ${FILES})
    list(APPEND LIST ${FILE})
  endforeach(FILE)
  set(ONELAB_SRC ${ONELAB_SRC};${LIST})
endmacro(append_src)

append_src(drawGModel.cpp)

if(ENABLE_BUILD_ANDROID)
  append_src(androidGModel.cpp)
  # user must specify the android-cmake toolchain
  find_file(CMAKE_TOOLCHAIN_FILE "android.toolchain.cmake")
  if(NOT CMAKE_TOOLCHAIN_FILE)
    message(SEND_ERROR "Cannot compile onelab for android without android-cmake")
  endif(NOT CMAKE_TOOLCHAIN_FILE)
  # we need getdp lib
  find_library(GETDP_LIB Getdp PATH_SUFFIXES lib)
  find_path(GETDP_INC "GetDP.h" PATH_SUFFIXES include getdp include/getdp)
  if(GETDP_LIB AND GETDP_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GETDP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GETDP_INC})
    set_config_option(HAVE_GMSH "GetDP")
  else(GETDP_LIB AND GETDP_INC)
    message(SEND_ERROR "Cannot compile onelab for Android without GetDP")
  endif(GETDP_LIB AND GETDP_INC)
  # we also need gmsh lib
  find_library(GMSH_LIB Gmsh PATH_SUFFIXES lib)
  find_path(GMSH_INC "Gmsh.h" PATH_SUFFIXES include gmsh include/gmsh)
  if(GMSH_LIB AND GMSH_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GMSH_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GMSH_INC})
    set_config_option(HAVE_GMSH "Gmsh")
  else(GMSH_LIB AND GMSH_INC)
    message(SEND_ERROR "Cannot compile onelab for Android without Gmsh")
  endif(GMSH_LIB AND GMSH_INC)
  # then we can make our library for Android
  include_directories(${EXTERNAL_INCLUDES})
  set(CMAKE_BUILD_TYPE Release)
  add_definitions(-DBUILD_ANDROID)
  set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs/)
  add_library(androidOnelab SHARED ${ONELAB_SRC})
  set( LIBRARY_DEPS GLESv1_CM log)
  set_target_properties(androidOnelab PROPERTIES OUTPUT_NAME Onelab)
  target_link_libraries(androidOnelab ${LIBRARY_DEPS}  ${EXTERNAL_LIBRARIES})
endif(ENABLE_BUILD_ANDROID)
