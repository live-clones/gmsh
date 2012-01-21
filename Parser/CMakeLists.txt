# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Gmsh.tab.cpp
  Gmsh.yy.cpp
  FunctionManager.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Parser "${SRC};${HDR}")
