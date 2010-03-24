# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  linearSystemCSR.cpp
  groupOfElements.cpp
  elasticityTerm.cpp
  elasticitySolver.cpp
  SElement.cpp
  eigenSolver.cpp
  multiscaleLaplace.cpp
  dgGroupOfElements.cpp
  dgAlgorithm.cpp
  dgRungeKutta.cpp
  dgRungeKuttaMultirate.cpp
  dgConservationLaw.cpp
  dgConservationLawAdvection.cpp
  dgSystemOfEquations.cpp
  dgConservationLawShallowWater1d.cpp	
  dgConservationLawShallowWater2d.cpp
  dgConservationLawWaveEquation.cpp
  dgConservationLawMaxwell.cpp
  dgConservationLawPerfectGas.cpp
  dgLimiter.cpp
  dgTransformNodalValue.cpp
  dgResidual.cpp
  dgDofContainer.cpp
  function.cpp
  functionDerivator.cpp
  luaFunction.cpp
  functionSpace.cpp
  dgFunctionIntegrator.cpp
  dgMesh2MeshProjection.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Solver "${SRC};${HDR}")
