set(SRC
  ap.cpp
  alglibinternal.cpp
  alglibmisc.cpp
  linalg.cpp
  optimization.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/lbfgs "${SRC};${HDR}")
