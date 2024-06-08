set(IFF_SRC
  odecoFrames.cxx
  IffTools.cxx
  IntegrableFrameFields.cxx
  ObjectiveFunctions.cxx
  Solver.cxx
  Visualization.cxx
  FrameField.cxx
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.hxx)
append_gmsh_src(contrib/IntegrableFrameFields "${IFF_SRC};${HDR}")
