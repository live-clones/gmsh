set(QUAD_OPTIMIZER_SRC
  quadQuality.cpp
  smallCavityOptimizer.cpp
  smallCavityWinslow.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadOptimizer "${QUAD_OPTIMIZER_SRC};${HDR}")
