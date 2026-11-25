set(SRC
  NonConformalRefinement.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/NonConformalRefinement "${SRC};${HDR}")
