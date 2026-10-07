# Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
    HierarchicalBasis.cpp
    H1Point.cpp
    H1Line.cpp
    HcurlLine.cpp
    H1Triangle.cpp
    HcurlTriangle.cpp
    HdivTriangle.cpp
    H1Quadrangle.cpp
    HcurlQuadrangle.cpp
    # HdivQuadrangle.cpp (not finished)
    H1Tetrahedron.cpp
    HcurlTetrahedron.cpp
    H1Hexahedron.cpp
    HcurlHexahedron.cpp
    H1Prism.cpp
    HcurlPrism.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HierarchicalBasis "${SRC};${HDR}")
