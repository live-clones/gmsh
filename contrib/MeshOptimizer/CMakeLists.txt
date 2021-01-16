# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  MeshOptimizer.cpp
  MeshOpt.cpp
  MeshOptCommon.cpp
  Patch.cpp
  ObjectiveFunction.cpp
  ObjContrib.cpp
  ObjContribFunc.cpp
  VertexCoord.cpp
  CADDistances.cpp
  IntegralBoundaryDist.cpp
)


opt(NCURSES "Enable ncurses console tools" OFF)

if(ENABLE_NCURSES)
  find_library(NCURSES_LIB ncurses)
  find_path(NCURSES_INC "ncurses.h" PATH_SUFFIXES src include)
endif()
if(NCURSES_LIB AND NCURSES_INC)
    set_config_option(HAVE_NCURSES "NCURSES")
    list(APPEND EXTERNAL_LIBRARIES ${NCURSES_LIB})
    set(EXTERNAL_LIBRARIES ${EXTERNAL_LIBRARIES} PARENT_SCOPE)
    list(APPEND EXTERNAL_INCLUDES ${NCURSES_INC})
endif()

mark_as_advanced(NCURSES_INC NCURSES_LIB)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/MeshOptimizerConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/MeshOptimizerConfig.h)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/MeshOptimizer "${SRC};${HDR}")
