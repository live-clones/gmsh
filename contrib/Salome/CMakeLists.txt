# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Partition_Inter2d.cxx 
  Partition_Inter3d.cxx 
  Partition_Loop.cxx
  Partition_Loop2d.cxx
  Partition_Loop3d.cxx
  Partition_Spliter.cxx
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hxx)
append_gmsh_src(contrib/Salome "${SRC};${HDR}")
