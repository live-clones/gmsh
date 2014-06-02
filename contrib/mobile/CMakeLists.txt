# Library to use Onelab (Gmsh/GetDP) on Android or iOS

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(APPLE)
 option(ENABLE_BUILD_IOS "Build XCode project for iOS (ARM)" OFF)
 option(ENABLE_BUILD_IOS_EMULATOR "Build XCode project for iOS emulator (x86)" ON)
 option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" OFF)
else(APPLE)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" ON)
endif(APPLE)

# find all benchmarks who provide infos.xml
find_path(BENCHMARKSDIR benchmarks/)
file(GLOB BENCHMARKSDIR ${BENCHMARKSDIR}/benchmarks/*)
foreach(SUBDIR ${BENCHMARKSDIR})
  if(IS_DIRECTORY ${SUBDIR})
    file(GLOB INFOSFILE ${SUBDIR}/infos.xml)
    if(INFOSFILE)
      message(STATUS "Found benchmark ${SUBDIR}")
      list(APPEND BENCHMARKS ${SUBDIR})
    endif()
  endif()
endforeach()

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
  find_path(GETDP_FRAMEWORK GetDP.framework)
  if(GETDP_FRAMEWORK)
    set(GETDP_FRAMEWORK ${GETDP_FRAMEWORK}/GetDP.framework)
    message(STATUS "Found framework " ${GETDP_FRAMEWORK})
  else(GETDP_FRAMEWORK)
    message(SEND_ERROR "Could not find GetDP.framework")
  endif(GETDP_FRAMEWORK)
  # we also need gmsh framework
  find_path(GMSH_FRAMEWORK Gmsh.framework)
  if(GMSH_FRAMEWORK)
    set(GMSH_FRAMEWORK ${GMSH_FRAMEWORK}/Gmsh.framework)
    message(STATUS "Found framework " ${GMSH_FRAMEWORK})
  else(GMSH_FRAMEWORK)
    message(SEND_ERROR "Could not find Gmsh.framework")
  endif(GMSH_FRAMEWORK)
  # and we also need PETSc
  find_path(PETSC_FRAMEWORK petsc.framework)
  if(PETSC_FRAMEWORK)
    set(PETSC_FRAMEWORK ${PETSC_FRAMEWORK}/petsc.framework)
    message(STATUS "Found framework " ${PETSC_FRAMEWORK})
  else(PETSC_FRAMEWORK)
    message(SEND_ERROR "Could not find petsc.framework")
  endif(PETSC_FRAMEWORK)
  # add target
  add_custom_target(xcodeProject
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/models/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab.xcodeproj/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab.xcodeproj/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.h ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawGeom.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawMesh.cpp ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/
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
  foreach(DIR ${BENCHMARKS})
    get_filename_component(DIRNAME ${DIR} NAME)
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                    ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/files/${DIRNAME})
  endforeach(DIR)

  copy_headers(${GETDP_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/GetDP.framework/Headers/)
  copy_headers(${GMSH_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/Gmsh.framework/Headers/)
  copy_headers(${PETSC_FRAMEWORK}/Headers/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/Onelab/frameworks/petsc.framework/Headers/)

  message(STATUS "")
  message(STATUS "ONELAB for iOS successfully configured:")
  message(STATUS " * Run `make xcodeProject' to create the XCode project")
  message(STATUS " * Then run `open Onelab/Onelab.xcodeproj' to launch XCode")
  message(STATUS "")

endif(ENABLE_BUILD_IOS_EMULATOR OR ENABLE_BUILD_IOS)

if(ENABLE_BUILD_ANDROID)
  append_src(drawContext.cpp)
  append_src(movePosition.h)
  append_src(Trackball.cpp)
  append_src(androidGModel.cpp)
  append_src(drawString.cpp)
  append_src(drawGeom.cpp)
  append_src(drawMesh.cpp)
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
  find_library(PETSC_LIB petsc PATH_SUFFIXES lib)
  find_library(BLAS_LIB f2cblas PATH_SUFFIXES lib)
  find_library(LAPACK_LIB f2clapack PATH_SUFFIXES lib)
  set(ONELAB_LIB ${CMAKE_CURRENT_BINARY_DIR}/libs/libOnelab.so)
  if(PETSC_LIB AND BLAS_LIB AND LAPACK_LIB AND ONELAB_LIB)
    add_custom_target(androidProject
      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/models/
      COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/Android/ ${CMAKE_CURRENT_BINARY_DIR}/Onelab/
      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${GMSH_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${GETDP_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${ONELAB_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${PETSC_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${LAPACK_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
      COMMAND ${CMAKE_COMMAND} -E copy ${BLAS_LIB} ${CMAKE_CURRENT_BINARY_DIR}/Onelab/libs/armeabi-v7a/
    )
    foreach(DIR ${BENCHMARKS})
      get_filename_component(DIRNAME ${DIR} NAME)
      add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                      ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/models/${DIRNAME})
    endforeach(DIR)
    find_program(ZIP_COMMAND zip)
    add_custom_command(TARGET androidProject POST_BUILD COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/models/ && zip -r
                     ${CMAKE_CURRENT_BINARY_DIR}/Onelab/res/raw/models.zip * --exclude=*.svn*)

  message(STATUS "")
  message(STATUS "ONELAB for Android successfully configured:")
  message(STATUS " * Run `make androidProject' to create the project")
  message(STATUS " * Then update android project with 'android update project --name Onelab --path Onelab --target [id] --subprojects'")
  message(STATUS " * Finally you can build the app with ant 'ant debug'")
  message(STATUS "")
 
  else(PETSC_LIB AND BLAS_LIB AND LAPACK_LIB AND ONELAB_LIB)
    message(STATUS "Cannot make Android project without PETSc or without BLAS or without LAPACK or without \"Onelab library\"")
  endif(PETSC_LIB AND BLAS_LIB AND LAPACK_LIB AND ONELAB_LIB)
endif(ENABLE_BUILD_ANDROID)
