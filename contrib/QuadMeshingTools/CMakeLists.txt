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
  crossfields.cxx
  integrableFrameField.cxx
  mesh.cxx
  objectiveFunction.cxx
  solver.cxx
  timer.cxx
  tools.cxx
  visualization.cxx
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hxx)
append_gmsh_src(contrib/QuadMeshingTools "${QMT_SRC};${HDR}")
