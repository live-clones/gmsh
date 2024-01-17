# Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.


# This CMakeList is only part of Gmsh
# To compile hxt separately, use the CMakeLists in the module you would like to use
# except for sizeField, which can only be compiled with Gmsh

# Fixme: HXT should rather be included using simple target_link_library calls,
# as for external libraries


#################################################################################
# HXT combine (Identifying combinations of tetrahedra into hexahedra: a vertex based strategy)
#################################################################################
set(SRC
    algorithms.cpp
    candidate_cell.cpp
    compute_candidate_cells.cpp
    hxt_combine_c_api.cpp
    hxt_combine_cpp_api.cpp
    tet_mesh.cpp
    hxt_quality.cpp
    cell_types.cpp
    algorithms.h
    basic_types.h
    bvh_tree.h
    candidate_cell.h
    cell_types.h
    combine_quality.h
    compute_candidate_cells.h
    hxt_combine_c_api.h
    hxt_combine_cell.h
    hxt_combine_cpp_api.h
    tet_mesh.h
    hxt_quality.h
    expansion.h
   )

append_gmsh_src(contrib/hxt/Combine/src "${SRC}")
#append_gmsh_src(contrib/hxt/Combine/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/Combine/src)


#################################################################################
# HXT core
#################################################################################
set(SRC
    hxt_bbox.c
    hxt_mesh.c
    hxt_message.c
    hxt_sort.c
   )

set(INC
    hxt_bbox.h
    hxt_mesh.h
    hxt_message.h
    hxt_omp.h
    hxt_sort.h
    hxt_tools.h
   )

append_gmsh_src(contrib/hxt/core/src "${SRC}")
append_gmsh_src(contrib/hxt/core/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/core/src
     contrib/hxt/core/include)


#################################################################################
# HXT reparam
#################################################################################
set(SRC
    hxt_class_macro.h
    hxt_curvature.c
    hxt_edge.c
    hxt_linear_system.c
    hxt_linear_system_lu.c
    hxt_linear_system_lu.h
    hxt_linear_system_petsc.c
    hxt_linear_system_petsc.h
    hxt_mean_values.c
    hxt_non_linear_solver.c
    hxt_non_linear_solver.h
   )

set(INC
    hxt_curvature.h
    hxt_edge.h
    hxt_linear_system.h
    hxt_mean_values.h
   )

append_gmsh_src(contrib/hxt/reparam/src "${SRC}")
append_gmsh_src(contrib/hxt/reparam/include "${INC}")
list(APPEND HXT_INC_DIRS
     contrib/hxt/reparam/src
     contrib/hxt/reparam/include)

#################################################################################
# HXT predicates
#################################################################################
append_gmsh_src(contrib/hxt/predicates/src predicates.c)
append_gmsh_src(contrib/hxt/predicates/include predicates.h)
list(APPEND HXT_INC_DIRS
     contrib/hxt/predicates/src
     contrib/hxt/predicates/include)


#################################################################################
# HXT tetBR
#################################################################################
append_gmsh_src(contrib/hxt/tetBR/src hxt_boundary_recovery.cxx)
append_gmsh_src(contrib/hxt/tetBR/include hxt_boundary_recovery.h)
list(APPEND HXT_INC_DIRS
     contrib/hxt/tetBR/src
     contrib/hxt/tetBR/include)


#################################################################################
# HXT tetMesh
#################################################################################
set(SRC
    hxt_edgeRemoval.c
    hxt_edgeRemoval.h
    hxt_smoothing.c
    hxt_smoothing.h
    HXTSPR.c
    HXTSPR.h
    hxt_tetColor.c
    hxt_tetColor.h
    hxt_tetDelaunay.c
    hxt_tetDelaunayReshape.c
    hxt_tetDelaunayReshape.h
    hxt_tetFlag.c
    hxt_tetMesh.c
    hxt_tetNodalSize.c
    hxt_tetOpti.c
    hxt_tetOptiUtils.h
    hxt_tetPartition.h
    hxt_tetQuality.c
    hxt_tetQuality.h
    hxt_tetRefine.c
    hxt_tetRefine.h
    hxt_tetRepair.c
    hxt_tetSync.c
    hxt_tetSync.h
    hxt_tetUtils.c
    hxt_tetUtils.h
    hxt_vertices.c
   )

set(INC
    hxt_tetDelaunay.h
    hxt_tetFlag.h
    hxt_tetMesh.h
    hxt_tetNodalSize.h
    hxt_tetOpti.h
    hxt_tetRepair.h
    hxt_vertices.h
   )

append_gmsh_src(contrib/hxt/tetMesh/src "${SRC}")
append_gmsh_src(contrib/hxt/tetMesh/include "${INC}")

list(APPEND HXT_INC_DIRS
     contrib/hxt/tetMesh/src
     contrib/hxt/tetMesh/include)


#################################################################################
# propagate HXT_INC_DIRS to parent CMakeLists
#################################################################################
set(HXT_INC_DIRS ${HXT_INC_DIRS} PARENT_SCOPE)
