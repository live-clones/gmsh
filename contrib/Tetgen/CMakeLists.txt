# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  tetgen.cxx
  predicates.cxx
)

append_gmsh_src(contrib/Tetgen "${SRC}")
