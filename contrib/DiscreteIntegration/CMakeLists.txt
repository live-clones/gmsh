# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  DILevelset.cpp
  Integration3D.cpp
  recurCut.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_SOURCE_DIR}/contrib/DiscreteIntegration *.h)
append_gmsh_src(contrib/DiscreteIntegration "${SRC};${HDR}")
