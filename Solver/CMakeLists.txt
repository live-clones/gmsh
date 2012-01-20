# Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  linearSystem.cpp
  linearSystemCSR.cpp
  linearSystemPETSc.cpp
  dofManager.cpp
  groupOfElements.cpp
  elasticityTerm.cpp
elasticitySolver.cpp
  SElement.cpp
  eigenSolver.cpp
  multiscaleLaplace.cpp
functionSpace.cpp
  filters.cpp
  sparsityPattern.cpp
  STensor43.cpp
terms.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Solver "${SRC};${HDR}")
