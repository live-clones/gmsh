# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

add_subdirectory(InternalPoints)
include_directories(InternalPoints)
append_gmsh_src(NonLinearSolver "${SRC};${HDR}")
set(GMSH_DIRS ${GMSH_DIRS};NonLinearSolver PARENT_SCOPE)





