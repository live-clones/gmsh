set(SRC
  GModelIO_ACIS.cpp
  ACISVertex.cpp
  ACISEdge.cpp
  ACISFace.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_pro_src(ACIS "${SRC};${HDR}")
