set(QMT_SRC
    qmt_simplification.cpp
    qmt_smoothing.cpp
    qmt_linalg_solver.cpp
    qmt_cross_field.cpp
    qmt_projection.cpp
    geolog.cpp
    linearSystemMUMPS2.cpp
 )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadMeshingTools "${QMT_SRC};${HDR}")
