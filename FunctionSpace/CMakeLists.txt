# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Polynomial.cpp
  Legendre.cpp

  Basis.cpp
  BasisScalar.cpp
  BasisVector.cpp
  QuadNodeBasis.cpp
  QuadEdgeBasis.cpp
  TriNodeBasis.cpp
  TriEdgeBasis.cpp
  TriNedelecBasis.cpp

  LocalFunctionSpace.cpp
  LocalFunctionSpaceScalar.cpp
  LocalFunctionSpaceVector.cpp
  LocalFunctionSpace0Form.cpp
  LocalFunctionSpace1Form.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(FunctionSpace "${SRC};${HDR}")

## Compatibility with SmallFEM (TO BE REMOVED !!!)
add_sources_in_gmsh(FunctionSpace "${SRC}")
