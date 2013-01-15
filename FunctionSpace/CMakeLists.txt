# Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SRC
  Polynomial.cpp
  Legendre.cpp

  ReferenceSpace.cpp
  LineReferenceSpace.cpp
  TriReferenceSpace.cpp
  TetReferenceSpace.cpp

  Basis.cpp
  BasisGenerator.cpp

  BasisLocal.cpp
  BasisLocalScalar.cpp
  BasisLocalVector.cpp

  BasisLagrange.cpp
  BasisHierarchicalScalar.cpp
  BasisHierarchicalVector.cpp

  LineNodeBasis.cpp
  LineEdgeBasis.cpp
  LineNedelecBasis.cpp

#  QuadNodeBasis.cpp
#  QuadEdgeBasis.cpp

  TriNodeBasis.cpp
  TriEdgeBasis.cpp
  TriNedelecBasis.cpp
  TriLagrangeBasis.cpp

#  HexNodeBasis.cpp
#  HexEdgeBasis.cpp

  TetNodeBasis.cpp
  TetEdgeBasis.cpp
  
  FunctionSpace.cpp
  FunctionSpaceScalar.cpp
  FunctionSpaceVector.cpp
  FunctionSpaceNode.cpp
  FunctionSpaceEdge.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(FunctionSpace "${SRC};${HDR}")

## Compatibility with SmallFEM (TO BE REMOVED !!!)
add_sources_in_gmsh(FunctionSpace "${SRC}")
