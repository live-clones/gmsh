# Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
    OrthogonalPoly.cpp
    Utils.cpp
    CreateHierarchicalBasis.cpp
    HierarchicalBasisH1.cpp
    HierarchicalBasisHcurl.cpp
    HierarchicalBasisHdiv.cpp
    Point/HierarchicalBasisH1Point.cpp
    Line/HierarchicalBasisH1Line.cpp
    Line/HierarchicalBasisHcurlLine.cpp
    Triangle/HierarchicalBasisH1Tria.cpp
    Triangle/HierarchicalBasisHcurlTria.cpp
    Triangle/HierarchicalBasisHdivTria.cpp 
    Quadrilateral/HierarchicalBasisH1Quad.cpp
    Quadrilateral/HierarchicalBasisHcurlQuad.cpp
   # Quadrilateral/HierarchicalBasisHdivQuad.cpp   
    Tetrahedron/HierarchicalBasisH1Tetra.cpp
    Tetrahedron/HierarchicalBasisHcurlTetra.cpp
    Hexahedron/HierarchicalBasisH1Brick.cpp
    Hexahedron/HierarchicalBasisHcurlBrick.cpp
    Prism/HierarchicalBasisH1Pri.cpp
    Prism/HierarchicalBasisHcurlPri.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HierarchicalBasis "${SRC};${HDR}")
