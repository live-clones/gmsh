# Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SRC
  Numeric.cpp
    fullMatrix.cpp
  BasisFactory.cpp
  discreteFrechetDistance.cpp
    nodalBasis.cpp
	polynomialBasis.cpp
	pyramidalBasis.cpp
	BergotBasis.cpp
	jacobiPolynomials.cpp
	legendrePolynomials.cpp
    bezierBasis.cpp
    JacobianBasis.cpp
    pointsGenerators.cpp
  ElementType.cpp
  GaussIntegration.cpp
    GaussQuadratureLin.cpp
    GaussQuadratureTri.cpp
    GaussQuadratureQuad.cpp
    GaussQuadratureTet.cpp
    GaussQuadratureHex.cpp
    GaussQuadraturePri.cpp
    GaussQuadraturePyr.cpp
    GaussLegendreSimplex.cpp
  GaussJacobi1D.cpp
  HilbertCurve.cpp
 robustPredicates.cpp
 decasteljau.cpp
  mathEvaluator.cpp
  Iso.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Numeric "${SRC};${HDR}")
