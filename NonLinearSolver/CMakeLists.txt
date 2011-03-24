# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.


add_subdirectory(BoundaryConditions)
add_subdirectory(contact)
add_subdirectory(Domain)
add_subdirectory(field)
add_subdirectory(Interface)
add_subdirectory(internalPoints)
add_subdirectory(materialLaw)
add_subdirectory(nlTerms)
add_subdirectory(nlsolver)
add_subdirectory(space)

append_gmsh_src(NonLinearSolver "${SRC};${HDR}")
set(GMSH_DIRS ${GMSH_DIRS};NonLinearSolver PARENT_SCOPE)

#   add pragma to compile nlmechsolpy.i in gmshpy.i
# no if because here it is sure to used NonLinearSolver
set(MAKE_C_FLAGS " ${CMAKE_C_FLAGS} -D_HAVE_NLMECHSOL")
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -D_HAVE_NLMECHSOL")




