# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  mathex.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_SOURCE_DIR}/contrib/MathEx *.h)
append_gmsh_src(contrib/MathEx "${SRC};${HDR}")
