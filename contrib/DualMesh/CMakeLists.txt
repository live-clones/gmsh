set(SRC
  DualMesh.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/DualMesh "${SRC};${HDR}")
