set(QMT_SRC
  qmtCrossField.cpp
  arrayGeometry.cpp
  cppUtils.cpp
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadMeshingTools "${QMT_SRC};${HDR}")
