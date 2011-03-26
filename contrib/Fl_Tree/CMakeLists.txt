# Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Fl_Tree.cxx
  Fl_Tree_Item.cxx
  Fl_Tree_Item_Array.cxx
  Fl_Tree_Prefs.cxx
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.H)
append_gmsh_src(contrib/Fl_Tree "${SRC};${HDR}")
