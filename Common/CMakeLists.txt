# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Gmsh.cpp
    GmshMessage.cpp
    GmshRemote.cpp
    GmshDaemon.cpp
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

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Common *.h) 
append_gmsh_src(Common "${SRC};${HDR}")
