cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 11)

if(APPLE)
  option(ENABLE_BUILD_IOS "Build XCode project for iOS (ARM)" OFF)
  option(ENABLE_BUILD_IOS_EMULATOR "Build XCode project for iOS emulator (x86)" ON)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARM)" OFF)
else(APPLE)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARM)" ON)
endif()

if(APPNAME)
  message(STATUS "Rebranding Onelab as " ${APPNAME})
else(APPNAME)
  set(APPNAME Onelab)
endif()

# find all benchmarks (in a two-level dir hierarchy) who provide infos.xml
file(GLOB BENCHMARKSDIR ${MODELS_DIR}/*)
foreach(SUBDIR ${BENCHMARKSDIR})
  if(IS_DIRECTORY ${SUBDIR})
    file(GLOB INFOSFILE ${SUBDIR}/infos.xml)
    if(INFOSFILE)
      message(STATUS "Found benchmark ${SUBDIR}")
      list(APPEND BENCHMARKS ${SUBDIR})
    else()
      file(GLOB BENCHMARKSDIR2 ${SUBDIR}/*)
      foreach(SUBDIR2 ${BENCHMARKSDIR2})
        if(IS_DIRECTORY ${SUBDIR2})
          file(GLOB INFOSFILE ${SUBDIR2}/infos.xml)
          if(INFOSFILE)
            message(STATUS "Found benchmark ${SUBDIR2}")
            list(APPEND BENCHMARKS ${SUBDIR2})
          endif()
        endif()
      endforeach()
    endif()
  endif()
endforeach()

macro(append_src FILES)
  foreach(FILE ${FILES})
    list(APPEND LIST ${FILE})
  endforeach(FILE)
  set(ONELAB_SRC ${ONELAB_SRC};${LIST})
endmacro(append_src)

if(ENABLE_BUILD_IOS_EMULATOR OR ENABLE_BUILD_IOS)
  # getdp framework
  find_path(GETDP_FRAMEWORK getdp.framework)
  if(GETDP_FRAMEWORK)
    set(GETDP_FRAMEWORK ${GETDP_FRAMEWORK}/getdp.framework)
    message(STATUS "Found framework " ${GETDP_FRAMEWORK})
  else(GETDP_FRAMEWORK)
    message(SEND_ERROR "Could not find getdp.framework")
  endif()
  # gmsh framework
  find_path(GMSH_FRAMEWORK gmsh.framework)
  if(GMSH_FRAMEWORK)
    set(GMSH_FRAMEWORK ${GMSH_FRAMEWORK}/gmsh.framework)
    message(STATUS "Found framework " ${GMSH_FRAMEWORK})
  else(GMSH_FRAMEWORK)
    message(SEND_ERROR "Could not find gmsh.framework")
  endif()
  # PETSc framework
  find_path(PETSC_FRAMEWORK petsc.framework)
  if(PETSC_FRAMEWORK)
    set(PETSC_FRAMEWORK ${PETSC_FRAMEWORK}/petsc.framework)
    message(STATUS "Found framework " ${PETSC_FRAMEWORK})
  else(PETSC_FRAMEWORK)
    message(SEND_ERROR "Could not find petsc.framework")
  endif()
  # SLEPc framework
  find_path(SLEPC_FRAMEWORK slepc.framework)
  if(SLEPC_FRAMEWORK)
    set(SLEPC_FRAMEWORK ${SLEPC_FRAMEWORK}/slepc.framework)
    message(STATUS "Found framework " ${SLEPC_FRAMEWORK})
  else(SLEPC_FRAMEWORK)
    message(SEND_ERROR "Could not find slepc.framework")
  endif()
  # OpenCASCADE framework
  find_path(OCCT_FRAMEWORK occt.framework)
  if(OCCT_FRAMEWORK)
    set(OCCT_FRAMEWORK ${OCCT_FRAMEWORK}/occt.framework)
    message(STATUS "Found framework " ${OCCT_FRAMEWORK})
  else(OCCT_FRAMEWORK)
    message(SEND_ERROR "Could not find occt.framework")
  endif()
  # add target
  add_custom_target(xcodeProject
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/models/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab/
                                               ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/iOS/Onelab.xcodeproj/
                                               ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}.xcodeproj/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawContext.h ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawGeom.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawMesh.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawString.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/drawString.h ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Trackball.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/Trackball.h ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iosUtils.h ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_SOURCE_DIR}/iosUtils.cpp ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GETDP_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/getdp.framework/
    COMMAND ${CMAKE_COMMAND} -E remove ${GMSH_FRAMEWORK}/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GMSH_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/gmsh.framework/
    COMMAND ${CMAKE_COMMAND} -E create_symlink . ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/gmsh.framework/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E create_symlink . ${GMSH_FRAMEWORK}/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PETSC_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/petsc.framework/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SLEPC_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/slepc.framework/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${OCCT_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/occt.framework/
  )
  add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove_directory
                    ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/files)
  foreach(DIR ${BENCHMARKS})
    get_filename_component(DIRNAME ${DIR} NAME)
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/files/${DIRNAME})
  endforeach(DIR)
  if("${APPNAME}" STREQUAL "BBEMG")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|Onelab|BBEMG|\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG.xcodeproj/project.pbxproj")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|Images.xcassets|Images_BBEMG.xcassets|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG.xcodeproj/project.pbxproj")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|ONELAB|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/iPhoneiPodStoryboard.storyboard")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|ONELAB|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/iPadStoryboard.storyboard")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|Onelab/Mobile|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/AboutViewController.mm")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND
      sed -e \"s|onelab.info|www.bbemg.be|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/AboutViewController.mm")
  endif()
  message(STATUS "")
  message(STATUS "${APPNAME} for iOS successfully configured:")
  message(STATUS " * Run 'make xcodeProject' to create the XCode project")
  message(STATUS " * Then run 'open ${APPNAME}/${APPNAME}.xcodeproj' to launch XCode")
  message(STATUS "")
endif()

if(ENABLE_BUILD_ANDROID)
  append_src(drawContext.cpp)
  append_src(Trackball.cpp)
  append_src(androidUtils.cpp)
  append_src(drawString.cpp)
  append_src(drawGeom.cpp)
  append_src(drawMesh.cpp)
  # getdp lib
  find_library(GETDP_LIB Getdp PATH_SUFFIXES lib)
  find_path(GETDP_INC "getdp.h" PATH_SUFFIXES include getdp include/getdp)
  if(GETDP_LIB AND GETDP_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GETDP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GETDP_INC})
  else(GETDP_LIB AND GETDP_INC)
    message(SEND_ERROR "Could not find getdp library")
  endif()
  # gmsh lib
  find_library(GMSH_LIB Gmsh PATH_SUFFIXES lib)
  find_path(GMSH_INC "GmshGlobal.h" PATH_SUFFIXES include gmsh include/gmsh)
  if(GMSH_LIB AND GMSH_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GMSH_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GMSH_INC})
  else(GMSH_LIB AND GMSH_INC)
    message(SEND_ERROR "Could not find gmsh library")
  endif()
  # Onelab android lib
  include_directories(${EXTERNAL_INCLUDES})
  set(CMAKE_BUILD_TYPE Release)
  add_definitions(-DBUILD_ANDROID)
  add_definitions(-DPICOJSON_USE_LOCALE=0)
  set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs/)
  add_library(androidOnelab SHARED ${ONELAB_SRC})
  set(LIBRARY_DEPS GLESv1_CM log)
  set_target_properties(androidOnelab PROPERTIES OUTPUT_NAME Onelab)
  target_link_libraries(androidOnelab ${LIBRARY_DEPS} ${EXTERNAL_LIBRARIES})
  find_library(PETSC_LIB petsc PATH_SUFFIXES lib)
  if(NOT PETSC_LIB)
    message(SEND_ERROR "Could not find PETSc library")
  endif()
  find_library(SLEPC_LIB slepc PATH_SUFFIXES lib)
  if(NOT SLEPC_LIB)
    message(SEND_ERROR "Could not find SLEPc library")
  endif()
  find_library(BLAS_LIB f2cblas PATH_SUFFIXES lib)
  if(NOT BLAS_LIB)
    message(SEND_ERROR "Could not find BLAS library")
  endif()
  find_library(LAPACK_LIB f2clapack PATH_SUFFIXES lib)
  if(NOT LAPACK_LIB)
    message(SEND_ERROR "Could not find LAPACK library")
  endif()
  find_library(CPP_LIB c++_shared PATH_SUFFIXES lib)
  if(NOT CPP_LIB)
    message(SEND_ERROR "Could not find c++_shared library")
  endif()
  set(ONELAB_LIB ${CMAKE_CURRENT_BINARY_DIR}/libs/libOnelab.so)
  add_custom_target(androidProject
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/models/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/Android/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E copy ${GMSH_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${GETDP_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${ONELAB_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${PETSC_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${SLEPC_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${LAPACK_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${BLAS_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
    COMMAND ${CMAKE_COMMAND} -E copy ${CPP_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/jniLibs/arm64-v8a/
  )
  add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove_directory
                    ${CMAKE_CURRENT_BINARY_DIR}/models)
  add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E make_directory
                    ${CMAKE_CURRENT_BINARY_DIR}/models)
  add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove
                    ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/res/raw/models.zip)
  foreach(DIR ${BENCHMARKS})
    get_filename_component(DIRNAME ${DIR} NAME)

    add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                      ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/models/${DIRNAME})
  endforeach(DIR)
  find_program(ZIP_COMMAND zip)
  add_custom_command(TARGET androidProject POST_BUILD COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/models/ && zip -r
                     ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/app/src/main/res/raw/models.zip * --exclude=*.svn*)
  message(STATUS "")
  message(STATUS "ONELAB for Android successfully configured:")
  message(STATUS " * Run 'make androidProject' to create the project")
  message(STATUS " * Finally build the app with gradle 'gradle assembleRelease'")
  message(STATUS "")
endif()
