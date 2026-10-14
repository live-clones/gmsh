# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(cor libsrc/core)
set(gen libsrc/general)
set(gpr libsrc/gprim)
set(lin libsrc/linalg)
set(mes libsrc/meshing)

set(SRC
  nglib_gmsh.cpp
  ${cor}/archive.cpp ${cor}/bitarray.cpp ${cor}/blockallocator.cpp
    ${cor}/exception.cpp ${cor}/flags.cpp ${cor}/localheap.cpp
    ${cor}/logging.cpp ${cor}/paje_trace.cpp ${cor}/profiler.cpp
    ${cor}/statushandler.cpp ${cor}/table.cpp ${cor}/taskmanager.cpp
    ${cor}/utils.cpp ${cor}/version.cpp
  ${gen}/gzstream.cpp ${gen}/table.cpp
  ${gpr}/geom3d.cpp ${gpr}/geomfuncs.cpp ${gpr}/geomtest3d.cpp
  ${lin}/bfgs.cpp ${lin}/densemat.cpp ${lin}/linsearch.cpp
  ${mes}/adfront2.cpp ${mes}/adfront3.cpp ${mes}/basegeom.cpp
    ${mes}/bisect.cpp ${mes}/clusters.cpp ${mes}/curvedelems.cpp
    ${mes}/debugging.cpp ${mes}/delaunay.cpp ${mes}/geomsearch.cpp
    ${mes}/global.cpp ${mes}/improve2.cpp ${mes}/improve2gen.cpp
    ${mes}/improve3.cpp ${mes}/localh.cpp ${mes}/meshclass.cpp
    ${mes}/meshfunc.cpp ${mes}/meshing2.cpp ${mes}/meshing3.cpp
    ${mes}/meshtool.cpp ${mes}/meshtype.cpp ${mes}/msghandler.cpp
    ${mes}/netrule2.cpp ${mes}/netrule3.cpp ${mes}/parser2.cpp
    ${mes}/parser3.cpp ${mes}/ruler2.cpp ${mes}/ruler3.cpp
    ${mes}/smoothing2.cpp ${mes}/smoothing3.cpp ${mes}/topology.cpp
    ${mes}/validate.cpp ${mes}/visual_interface.cpp
  rules/rule_hexrules.cpp rules/rule_prismrules2.cpp
    rules/rule_pyramidrules.cpp rules/rule_pyramidrules2.cpp
    rules/rule_quadrules.cpp rules/rule_tetrules.cpp rules/rule_triarules.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h *.hpp)

# Netgen does not use OpenMP, and Apple clang 11 crashes on its templates when
# OpenMP is enabled: compile it as an object library without the OpenMP flags
string(REPLACE "-Xpreprocessor -fopenmp" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
if(OpenMP_CXX_FLAGS)
  string(REPLACE "${OpenMP_CXX_FLAGS}" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

add_library(netgen OBJECT ${SRC} ${HDR})
set_target_properties(netgen PROPERTIES POSITION_INDEPENDENT_CODE ON
  CXX_VISIBILITY_PRESET hidden VISIBILITY_INLINES_HIDDEN ON)
target_include_directories(netgen PRIVATE . libsrc libsrc/include
  ${PROJECT_SOURCE_DIR}/src/common ${PROJECT_BINARY_DIR}/src/common
  ${ZLIB_INCLUDE_DIR})
if(WIN32)
  target_compile_definitions(netgen PRIVATE _USE_MATH_DEFINES)
endif()
if(MSVC)
  target_compile_definitions(netgen PRIVATE NOMINMAX _CRT_SECURE_NO_WARNINGS)
  target_compile_options(netgen PRIVATE /bigobj)
endif()

set(GMSH_SRC ${GMSH_SRC};$<TARGET_OBJECTS:netgen> PARENT_SCOPE)
