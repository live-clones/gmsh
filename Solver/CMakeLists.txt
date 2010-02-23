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
  dgConservationLaw.cpp
  dgConservationLawAdvection.cpp
  dgSystemOfEquations.cpp
  dgConservationLawShallowWater2d.cpp
  dgConservationLawWaveEquation.cpp
  dgConservationLawMaxwell.cpp
  dgConservationLawPerfectGas.cpp
  dgLimiter.cpp
  dgDofContainer.cpp
  function.cpp
  functionDerivator.cpp
  luaFunction.cpp
  functionSpace.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Solver *.h) 
append_gmsh_src(Solver "${SRC};${HDR}")
