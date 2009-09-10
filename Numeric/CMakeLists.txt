# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Numeric.cpp
    GmshMatrix.cpp
    gmshLaplace.cpp
  gmshCrossConf.cpp
    gmshConvexCombination.cpp
      gmshHelmholtz.cpp
      gmshElasticity.cpp
      gmshProjection.cpp
      gmshLinearSystemCSR.cpp
    EigSolve.cpp
    FunctionSpace.cpp
    GaussQuadratureLin.cpp
      GaussQuadratureTri.cpp
      GaussQuadratureQuad.cpp
      GaussQuadratureTet.cpp
      GaussQuadratureHex.cpp
      GaussLegendreSimplex.cpp
    GmshPredicates.cpp
  mathEvaluator.cpp
)

append_gmsh_src(Numeric "${SRC}")
