cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# if CMAKE_BUILD_TYPE is specified use it; otherwise set the default
# build type to "RelWithDebInfo" ("-O2 -g" with gcc) prior to calling
# project()
if(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose build type")
else(DEFINED CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose build type")
endif(DEFINED CMAKE_BUILD_TYPE)

project(api_demos CXX)

add_subdirectory(../.. "${CMAKE_CURRENT_BINARY_DIR}/gmsh")

include_directories(../../Common ../../Numeric ../../Geo ../../Mesh 
   ../../Solver ../../Post ../../Plugin ../../Graphics 
   ../../contrib/DiscreteIntegration ${GMSH_EXTERNAL_INCLUDE_DIRS}
   ${CMAKE_CURRENT_BINARY_DIR}/gmsh/Common)

if(APPLE)
  set(glut "-framework GLUT")
else(APPLE)
  set(glut "glut")
endif(APPLE)

add_executable(mainAntTweakBar mainAntTweakBar.cpp)
target_link_libraries(mainAntTweakBar shared AntTweakBar ${glut})

add_executable(mainCartesian mainCartesian.cpp)
target_link_libraries(mainCartesian shared)

add_executable(mainElasticity mainElasticity.cpp)
target_link_libraries(mainElasticity shared)

add_executable(mainGlut mainGlut.cpp)
target_link_libraries(mainGlut shared ${glut})

add_executable(mainHomology mainHomology.cpp)
target_link_libraries(mainHomology shared)

add_executable(mainLevelset mainLevelset.cpp)
target_link_libraries(mainLevelset shared)

add_executable(mainOcc mainOcc.cpp)
target_link_libraries(mainOcc shared)

add_executable(mainPost mainPost.cpp)
target_link_libraries(mainPost shared)

add_executable(mainSimple mainSimple.cpp)
target_link_libraries(mainSimple shared)
