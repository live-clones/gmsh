# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  IEdge.cpp
  IElement.cpp
  InterfaceBuilder.cpp
  MInterfaceElement.cpp
  MInterfaceLine.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(NonLinearSolver/Interface "${SRC};${HDR}")
