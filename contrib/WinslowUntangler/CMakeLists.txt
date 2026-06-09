set(WU_SRC
  gmshLBFGS.cpp
  winslowUntanglerGMSH.cpp
  winslowUntangler.cpp
  meshSurfaceUntangling.cpp
  meshVolumeUntangling.cpp
  )

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(contrib/WinslowUntangler "${WU_SRC};${HDR}")
