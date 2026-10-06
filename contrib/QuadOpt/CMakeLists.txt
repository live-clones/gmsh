set(QUAD_OPT_SRC
  qoFace.cpp
  qoOptimizer.cpp
  qoPack.cpp
  qoQMorph.cpp
  intrinsicTriangulation.cpp
  smallCavityWinslow.cpp
)
file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadOpt "${QUAD_OPT_SRC};${HDR}")
