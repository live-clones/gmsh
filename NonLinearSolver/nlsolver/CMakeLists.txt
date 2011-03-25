# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  nonLinearMechSolver.cpp
  unknownDynamicField.cpp
  unknownField.cpp
  unknownStaticField.cpp
  # inline
  explicitDofManager.h
  explicitHulbertChung.h
  nlsolAlgorithms.h
  staticDofManager.h
  timeFunction.h
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(NonLinearSolver/nlsolver "${SRC};${HDR}")
