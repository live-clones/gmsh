# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
  MeshOpt.cpp
  MeshOptCommon.cpp
  MeshOptimizer.cpp
  MeshOptPatch.cpp
  MeshOptObjectiveFunction.cpp
  MeshOptObjContrib.cpp
  MeshOptObjContribFunc.cpp
  MeshOptVertexCoord.cpp
)


opt(NCURSES "Enable ncurses console tools" OFF)

if(ENABLE_NCURSES)
  find_library(NCURSES_LIB ncurses)
  find_path(NCURSES_INC "ncurses.h" PATH_SUFFIXES src include)
endif(ENABLE_NCURSES)
if(NCURSES_LIB AND NCURSES_INC)
    set_config_option(HAVE_NCURSES "NCURSES")
    list(APPEND EXTERNAL_LIBRARIES ${NCURSES_LIB})
    set(EXTERNAL_LIBRARIES ${EXTERNAL_LIBRARIES} PARENT_SCOPE)
    list(APPEND EXTERNAL_INCLUDES ${NCURSES_INC})
endif(NCURSES_LIB AND NCURSES_INC)

mark_as_advanced(NCURSES_INC NCURSES_LIB)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/MeshOptimizerConfig.h.in
               ${CMAKE_CURRENT_BINARY_DIR}/MeshOptimizerConfig.h)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hpp)
append_gmsh_src(contrib/MeshOptimizer "${SRC};${HDR}")

