set(QUAD_OPTIMIZER_SRC
  intrinsicTriangulation.cpp
  quadFinalRepair.cpp
  quadOptimizerIntegration.cpp
  halfEdge.cpp
  quadQuality.cpp
  smallCavityOptimizer.cpp
  smallCavityOptimizerV2.cpp
  smallCavityWinslow.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadOptimizer "${QUAD_OPTIMIZER_SRC};${HDR}")

# Reuse the shared solver without requiring the BoundaryLayers plugin.
if(NOT HAVE_BOUNDARY_LAYERS)
  append_gmsh_src(contrib/BoundaryLayers "gmshLBFGS.cpp")
endif()
