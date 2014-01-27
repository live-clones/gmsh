# Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SRC
  Polynomial.cpp
  Legendre.cpp

  PermutationTree.cpp

  ReferenceSpace.cpp
  LineReferenceSpace.cpp
  TriReferenceSpace.cpp
  QuadReferenceSpace.cpp
  TetReferenceSpace.cpp
  HexReferenceSpace.cpp
  PyrReferenceSpace.cpp
  PriReferenceSpace.cpp

  ReferenceSpaceManager.cpp

  Basis.cpp
  BasisLocal.cpp
  BasisGenerator.cpp

  BasisLagrange.cpp
  BasisHierarchical0Form.cpp
  BasisHierarchical1Form.cpp

  LineNodeBasis.cpp
  LineEdgeBasis.cpp
  LineNedelecBasis.cpp
  LineLagrangeBasis.cpp

  TriNodeBasis.cpp
  TriEdgeBasis.cpp
  TriNedelecBasis.cpp
  TriLagrangeBasis.cpp

  QuadNodeBasis.cpp
  QuadEdgeBasis.cpp
  QuadNedelecBasis.cpp
  QuadLagrangeBasis.cpp

  TetNodeBasis.cpp
  TetEdgeBasis.cpp
  TetNedelecBasis.cpp
  TetLagrangeBasis.cpp

  HexNodeBasis.cpp
  HexEdgeBasis.cpp
  HexLagrangeBasis.cpp

  FunctionSpace.cpp
  FunctionSpaceScalar.cpp
  FunctionSpaceVector.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(FunctionSpace "${SRC};${HDR}")

## Compatibility with SmallFEM (TO BE REMOVED !!!)
add_sources_in_gmsh(FunctionSpace "${SRC}")
