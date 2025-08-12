# Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  OrthogonalPoly.cpp
  HierarchicalBasisH1.cpp
  HierarchicalBasisH1Quad.cpp
  HierarchicalBasisH1Tria.cpp
  HierarchicalBasisH1Line.cpp
  HierarchicalBasisH1Brick.cpp
  HierarchicalBasisH1Tetra.cpp
  HierarchicalBasisH1Pri.cpp
  HierarchicalBasisH1Point.cpp
  HierarchicalBasis.cpp
  HierarchicalBasisHcurl.cpp
  HierarchicalBasisHcurlQuad.cpp
  HierarchicalBasisHcurlBrick.cpp
  HierarchicalBasisHcurlTria.cpp
  HierarchicalBasisHcurlTetra.cpp
  HierarchicalBasisHcurlPri.cpp
  HierarchicalBasisHcurlLine.cpp
  Utils.cpp
  CreateHierarchicalBasis.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HierarchicalBasis_old "${SRC};${HDR}")
