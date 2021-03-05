set(QMT_SRC
  qmtMeshGeometryOptimization.cpp
  qmtDiskQuadrangulationRemeshing.cpp
  qmtQuadCavityRemeshing.cpp
  qmtCrossField.cpp
  qmtCurveQuantization.cpp
  qmtSizeMap.cpp
  qmtMeshUtils.cpp
  arrayGeometry.cpp
  cppUtils.cpp
  geolog.cpp
  row_echelon_integer.cpp
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/QuadMeshingTools "${QMT_SRC};${HDR}")
