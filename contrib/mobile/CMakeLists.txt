# Library to use Onelab (Gmsh/GetDP) on Android or iOS

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

set(DEFAULT ON CACHE INTERNAL "Default value for enabled-by-default options")

if(APPLE)
 option(ENABLE_BUILD_IOS "Build library for iOS (ARM)" OFF)
 option(ENABLE_BUILD_IOS_EMULATOR "Build library for iOS emulator (x86)" ON)
 option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" OFF)
else(APPLE)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" ON)
endif(APPLE)

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

macro(copy_headers SOURCE DEST)
  file(GLOB hfiles "${SOURCE}/*.h")
  foreach(file ${hfiles})
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${file} ${DEST})
  endforeach(file ${hfiles})
endmacro(copy_headers)

if(ENABLE_BUILD_IOS_EMULATOR OR ENABLE_BUILD_IOS)
  # we need getdp framework
  find_path(GETDP_FRAMEWORK "GetDP" GetDP.framework)
  if(NOT GETDP_FRAMEWORK)
    message(SEND_ERROR "Cannot compile onelab for iOS without GetDP")
  endif(NOT GETDP_FRAMEWORK)
  # we also need gmsh framework
  find_path(GMSH_FRAMEWORK "Gmsh" Gmsh.framework)
  if(NOT GMSH_FRAMEWORK)
    message(SEND_ERROR "Cannot compile onelab for iOS without Gmsh")
  endif(NOT GMSH_FRAMEWORK)
  # and we also need PETSc
  find_path(PETSC_FRAMEWORK "petsc" petsc.framework)
  if(NOT PETSC_FRAMEWORK)
    message(SEND_ERROR "Cannot compile onelab for iOS without PETSc")
  endif(NOT PETSC_FRAMEWORK)
  # add target
  add_custom_target(xcodeProject
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab.xcodeproj/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab.xcodeproj/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iOS/ic_launcher.png ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iOS/ic_launcher_retina.png ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawString.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawString.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Trackball.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Trackball.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/movePosition.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iosGModel.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iosGModel.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/GetDP.framework/Headers/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/Gmsh.framework/Headers/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/petsc.framework/Headers/
    COMMAND ${CMAKE_COMMAND} -E copy ${GETDP_FRAMEWORK}/GetDP ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/GetDP.framework/
    COMMAND ${CMAKE_COMMAND} -E copy ${GMSH_FRAMEWORK}/Gmsh ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/Gmsh.framework/
    COMMAND ${CMAKE_COMMAND} -E copy ${PETSC_FRAMEWORK}/petsc ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/petsc.framework/
  )
  copy_headers(${GETDP_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/GetDP.framework/Headers/)
  copy_headers(${GMSH_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/Gmsh.framework/Headers/)
  copy_headers(${PETSC_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/petsc.framework/Headers/)
endif(ENABLE_BUILD_IOS_EMULATOR OR ENABLE_BUILD_IOS)

if(ENABLE_BUILD_ANDROID)
  append_src(drawGModel.cpp)
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
