cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

if(APPLE)
  option(ENABLE_BUILD_IOS "Build XCode project for iOS (ARM)" OFF)
  option(ENABLE_BUILD_IOS_EMULATOR "Build XCode project for iOS emulator (x86)" ON)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" OFF)
else(APPLE)
  option(ENABLE_BUILD_ANDROID "Build library for Android NDK (ARMv7)" ON)
endif(APPLE)

if(APPNAME)
  message(STATUS "Rebranding Onelab as " ${APPNAME})
else(APPNAME)
  set(APPNAME Onelab)
endif(APPNAME)

# find all benchmarks who provide infos.xml
if("${APPNAME}" STREQUAL "BBEMG")
  find_path(BENCHMARKSDIR benchmarks_private/)
  file(GLOB BENCHMARKSDIR ${BENCHMARKSDIR}/benchmarks_private/bbemg*)
else("${APPNAME}" STREQUAL "BBEMG")
  find_path(BENCHMARKSDIR benchmarks/)
  file(GLOB BENCHMARKSDIR ${BENCHMARKSDIR}/benchmarks/*)
endif("${APPNAME}" STREQUAL "BBEMG")

foreach(SUBDIR ${BENCHMARKSDIR})
  if(IS_DIRECTORY ${SUBDIR})
    file(GLOB INFOSFILE ${SUBDIR}/infos.xml)
    if(INFOSFILE)
      message(STATUS "Found benchmark ${SUBDIR}")
      list(APPEND BENCHMARKS ${SUBDIR})
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
  # GetDP framework
  find_path(GETDP_FRAMEWORK GetDP.framework)
  if(GETDP_FRAMEWORK)
    set(GETDP_FRAMEWORK ${GETDP_FRAMEWORK}/GetDP.framework)
    message(STATUS "Found framework " ${GETDP_FRAMEWORK})
  else(GETDP_FRAMEWORK)
    message(SEND_ERROR "Could not find GetDP.framework")
  endif(GETDP_FRAMEWORK)
  # Gmsh framework
  find_path(GMSH_FRAMEWORK Gmsh.framework)
  if(GMSH_FRAMEWORK)
    set(GMSH_FRAMEWORK ${GMSH_FRAMEWORK}/Gmsh.framework)
    message(STATUS "Found framework " ${GMSH_FRAMEWORK})
  else(GMSH_FRAMEWORK)
    message(SEND_ERROR "Could not find Gmsh.framework")
  endif(GMSH_FRAMEWORK)
  # PETSc framework
  find_path(PETSC_FRAMEWORK petsc.framework)
  if(PETSC_FRAMEWORK)
    set(PETSC_FRAMEWORK ${PETSC_FRAMEWORK}/petsc.framework)
    message(STATUS "Found framework " ${PETSC_FRAMEWORK})
  else(PETSC_FRAMEWORK)
    message(SEND_ERROR "Could not find petsc.framework")
  endif(PETSC_FRAMEWORK)
  # SLEPc framework
  find_path(SLEPC_FRAMEWORK slepc.framework)
  if(SLEPC_FRAMEWORK)
    set(SLEPC_FRAMEWORK ${SLEPC_FRAMEWORK}/slepc.framework)
    message(STATUS "Found framework " ${SLEPC_FRAMEWORK})
  else(SLEPC_FRAMEWORK)
    message(SEND_ERROR "Could not find slepc.framework")
  endif(SLEPC_FRAMEWORK)
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
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GETDP_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/GetDP.framework/
    COMMAND ${CMAKE_COMMAND} -E remove ${GMSH_FRAMEWORK}/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${GMSH_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/Gmsh.framework/
    COMMAND ${CMAKE_COMMAND} -E create_symlink . ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/Gmsh.framework/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E create_symlink . ${GMSH_FRAMEWORK}/Headers/gmsh
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${PETSC_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/petsc.framework/
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${SLEPC_FRAMEWORK}/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/frameworks/slepc.framework/
  )
  add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove_directory
                    ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/files)
  foreach(DIR ${BENCHMARKS})
    get_filename_component(DIRNAME ${DIR} NAME)
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/files/${DIRNAME})
    file(GLOB PNG ${DIR}/*.png)
    foreach(IMG ${PNG})
      get_filename_component(IMGNAME ${IMG} NAME)
      if(NOT (IMGNAME MATCHES ".*_128.png"))
        add_custom_command(TARGET xcodeProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove
                          "${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/${APPNAME}/files/${DIRNAME}/${IMGNAME}")
      endif()
    endforeach(IMG)
  endforeach(DIR)
  if("${APPNAME}" STREQUAL "BBEMG")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|Onelab|BBEMG|\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG.xcodeproj/project.pbxproj")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|Images.xcassets|Images_BBEMG.xcassets|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG.xcodeproj/project.pbxproj")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|ONELAB|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/en.lproj/iPhoneiPodStoryboard.storyboard")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|ONELAB|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/en.lproj/iPadStoryboard.storyboard")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|Onelab/Mobile|BBEMG|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/AboutViewController.mm")
    add_custom_command(TARGET xcodeProject POST_BUILD COMMAND 
      sed -e \"s|onelab.info|www.bbemg.be|g\" -i \"\" "${CMAKE_CURRENT_BINARY_DIR}/BBEMG/BBEMG/AboutViewController.mm")
  endif("${APPNAME}" STREQUAL "BBEMG")
  message(STATUS "")
  message(STATUS "${APPNAME} for iOS successfully configured:")
  message(STATUS " * Run 'make xcodeProject' to create the XCode project")
  message(STATUS " * Then run 'open ${APPNAME}/${APPNAME}.xcodeproj' to launch XCode")
  message(STATUS "")
endif(ENABLE_BUILD_IOS_EMULATOR OR ENABLE_BUILD_IOS)

if(ENABLE_BUILD_ANDROID)
  append_src(drawContext.cpp)
  append_src(Trackball.cpp)
  append_src(androidUtils.cpp)
  append_src(drawString.cpp)
  append_src(drawGeom.cpp)
  append_src(drawMesh.cpp)
  # GetDP lib
  find_library(GETDP_LIB Getdp PATH_SUFFIXES lib)
  find_path(GETDP_INC "GetDP.h" PATH_SUFFIXES include getdp include/getdp)
  if(GETDP_LIB AND GETDP_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GETDP_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GETDP_INC})
  else(GETDP_LIB AND GETDP_INC)
    message(SEND_ERROR "Could not find GetDP library")
  endif(GETDP_LIB AND GETDP_INC)
  # Gmsh lib
  find_library(GMSH_LIB Gmsh PATH_SUFFIXES lib)
  find_path(GMSH_INC "Gmsh.h" PATH_SUFFIXES include gmsh include/gmsh)
  if(GMSH_LIB AND GMSH_INC)
    list(APPEND EXTERNAL_LIBRARIES ${GMSH_LIB})
    list(APPEND EXTERNAL_INCLUDES ${GMSH_INC})
  else(GMSH_LIB AND GMSH_INC)
    message(SEND_ERROR "Could not find Gmsh library")
  endif(GMSH_LIB AND GMSH_INC)
  # Onelab android lib
  include_directories(${EXTERNAL_INCLUDES})
  set(CMAKE_BUILD_TYPE Release)
  add_definitions(-DBUILD_ANDROID)
  set(LIBRARY_OUTPUT_PATH_ROOT ${CMAKE_CURRENT_BINARY_DIR})
  set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/libs/)
  add_library(androidOnelab SHARED ${ONELAB_SRC})
  set(LIBRARY_DEPS GLESv1_CM log)
  set_target_properties(androidOnelab PROPERTIES OUTPUT_NAME Onelab)
  target_link_libraries(androidOnelab ${LIBRARY_DEPS} ${EXTERNAL_LIBRARIES})
  find_library(PETSC_LIB petsc PATH_SUFFIXES lib)
  if(NOT PETSC_LIB)
    message(SEND_ERROR "Could not find PETSc library")
  endif(NOT PETSC_LIB)
  find_library(SLEPC_LIB slepc PATH_SUFFIXES lib)
  if(NOT SLEPC_LIB)
    message(SEND_ERROR "Could not find SLEPc library")
  endif(NOT SLEPC_LIB)
  find_library(BLAS_LIB f2cblas PATH_SUFFIXES lib)
  if(NOT BLAS_LIB)
    message(SEND_ERROR "Could not find BLAS library")
  endif(NOT BLAS_LIB)
  find_library(LAPACK_LIB f2clapack PATH_SUFFIXES lib)
  if(NOT LAPACK_LIB)
    message(SEND_ERROR "Could not find LAPACK library")
  endif(NOT LAPACK_LIB)
  set(ONELAB_LIB ${CMAKE_CURRENT_BINARY_DIR}/libs/libOnelab.so)
  add_custom_target(androidProject
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/models/
    COMMAND ${CMAKE_COMMAND} -E copy_directory  ${CMAKE_CURRENT_SOURCE_DIR}/Android/ ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${GMSH_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${GETDP_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${ONELAB_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${PETSC_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${SLEPC_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${LAPACK_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
    COMMAND ${CMAKE_COMMAND} -E copy ${BLAS_LIB} ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/libs/armeabi-v7a/
  )
  add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove_directory
                    ${CMAKE_CURRENT_BINARY_DIR}/models)
  add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove
                    ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/res/raw/models.zip)
  foreach(DIR ${BENCHMARKS})
    get_filename_component(DIRNAME ${DIR} NAME)
    add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
                      ${DIR} ${CMAKE_CURRENT_BINARY_DIR}/models/${DIRNAME})
    file(GLOB PNG ${DIR}/*.png)
    foreach(IMG ${PNG})
      get_filename_component(IMGNAME ${IMG} NAME)
      if(NOT (IMGNAME MATCHES ".*_128.png"))
        add_custom_command(TARGET androidProject POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove
                           "${CMAKE_CURRENT_BINARY_DIR}/models/${DIRNAME}/${IMGNAME}")
      endif()
    endforeach(IMG)
  endforeach(DIR)
  find_program(ZIP_COMMAND zip)
  add_custom_command(TARGET androidProject POST_BUILD COMMAND cd ${CMAKE_CURRENT_BINARY_DIR}/models/ && zip -r
                     ${CMAKE_CURRENT_BINARY_DIR}/${APPNAME}/res/raw/models.zip * --exclude=*.svn*)
  message(STATUS "")
  message(STATUS "ONELAB for Android successfully configured:")
  message(STATUS " * Run 'make androidProject' to create the project")
  message(STATUS " * Then update android project with 'android update project --name ${APPNAME} --path ${APPNAME} --target [id] --subprojects'")
  message(STATUS " * Finally build the app with ant 'ant debug'")
  message(STATUS "")
endif(ENABLE_BUILD_ANDROID)
