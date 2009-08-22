# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  matheval.cpp
  node.cpp
  scanner.yy.cpp
  parser.tab.cpp
  symbol_table.cpp
  xmath.cpp
)

append_gmsh_src(contrib/MathEval "${SRC}")
