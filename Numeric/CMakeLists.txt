# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Numeric.cpp
    fullMatrix.cpp
  BasisFactory.cpp
    polynomialBasis.cpp
    JacobianBasis.cpp
    BergotBasis.cpp
    pyramidalBasis.cpp
    jacobiPolynomials.cpp
    legendrePolynomials.cpp
  pointsGenerators.cpp
  GaussIntegration.cpp
    GaussQuadratureLin.cpp
    GaussQuadratureTri.cpp
    GaussQuadratureQuad.cpp
    GaussQuadratureTet.cpp
    GaussQuadratureHex.cpp
    GaussQuadraturePri.cpp
    GaussLegendreSimplex.cpp
  GaussJacobi1D.cpp
  robustPredicates.cpp
  mathEvaluator.cpp
  Iso.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Numeric "${SRC};${HDR}")
