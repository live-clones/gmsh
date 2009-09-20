# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Numeric.cpp
    fullMatrix.cpp
    EigSolve.cpp
    functionSpace.cpp
  GaussQuadratureLin.cpp
    GaussQuadratureTri.cpp
    GaussQuadratureQuad.cpp
    GaussQuadratureTet.cpp
    GaussQuadratureHex.cpp
    GaussLegendreSimplex.cpp
  robustPredicates.cpp
  mathEvaluator.cpp
  Iso.cpp
  gmshLaplace.cpp
    gmshCrossConf.cpp
    gmshDistance.cpp
    gmshConvexCombination.cpp
    gmshElasticity.cpp
    gmshLinearSystemCSR.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Numeric *.h) 
append_gmsh_src(Numeric "${SRC};${HDR}")
