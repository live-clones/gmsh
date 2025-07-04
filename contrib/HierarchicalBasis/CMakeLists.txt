# Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
    OrthogonalPoly.cpp
    #  Triangle/H1.cpp
    #  Triangle/Hcurl.cpp
    #  Quadrangle/H1.cpp
    #  Quadrangle/Hcurl.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/HierarchicalBasis "${SRC};${HDR}")
