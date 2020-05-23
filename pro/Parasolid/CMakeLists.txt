set(SRC
  GModelIO_Parasolid.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_pro_src(Parasolid "${SRC};${HDR}")
