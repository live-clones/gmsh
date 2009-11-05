# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
  dgGroupOfElements.cpp
  dgAlgorithm.cpp
  dgConservationLawAdvection.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Solver *.h) 
append_gmsh_src(Solver "${SRC};${HDR}")
