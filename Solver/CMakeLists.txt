# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  linearSystem.cpp
  linearSystemCSR.cpp
  linearSystemPETSc.cpp
  linearSystemMUMPS.cpp
  dofManager.cpp
  groupOfElements.cpp
  elasticityTerm.cpp
elasticitySolver.cpp
  thermicSolver.cpp
  SElement.cpp
  eigenSolver.cpp
functionSpace.cpp
  filters.cpp
  frameSolver.cpp
  sparsityPattern.cpp
  STensor43.cpp
  STensor33.cpp
  STensor53.cpp
  STensor63.cpp
terms.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Solver "${SRC};${HDR}")
