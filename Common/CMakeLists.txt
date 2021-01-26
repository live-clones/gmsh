# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  GmshGlobal.cpp
  GmshMessage.cpp
  gmshPopplerWrapper.cpp
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
  onelabUtils.cpp
  GamePad.cpp
  GmshRemote.cpp
  gmshLocalNetworkClient.cpp
  gmsh.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Common "${SRC};${HDR}")
