set(QMT_SRC
  qmtCrossField.cpp
  qmtSizeMap.cpp
  qmtMeshUtils.cpp
  arrayGeometry.cpp
  cppUtils.cpp
  geolog.cpp
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadMeshingTools "${QMT_SRC};${HDR}")
