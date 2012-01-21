# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Gmsh.cpp
    GmshRemote.cpp
    GmshMessage.cpp
  Context.cpp
  Options.cpp
  CommandLine.cpp
  OS.cpp
  OpenFile.cpp
  CreateFile.cpp
  VertexArray.cpp
  SmoothData.cpp
  Octree.cpp 
    OctreeInternals.cpp
  StringUtils.cpp
  ListUtils.cpp
  TreeUtils.cpp avl.cpp
  MallocUtils.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Common "${SRC};${HDR}")
