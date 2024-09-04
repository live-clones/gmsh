# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Numeric.cpp
    fullMatrix.cpp
  BasisFactory.cpp
    FuncSpaceData.cpp
  discreteFrechetDistance.cpp
  miniBasis.cpp
    nodalBasis.cpp
	polynomialBasis.cpp
	incompleteBasis.cpp
	pyramidalBasis.cpp
	BergotBasis.cpp
	orthogonalBasis.cpp
    bezierBasis.cpp
    JacobianBasis.cpp
    CondNumBasis.cpp
    pointsGenerators.cpp
    InnerVertexPlacement.cpp
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
  approximationError.cpp
  ConjugateGradients.cpp
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
  curvature.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/numeric "${SRC};${HDR}")
