# Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  bframe.cpp
  bsearch.cpp
  frame.cpp
  huff.cpp
  jrevdct.cpp
  param.cpp
  postdct.cpp
  rate.cpp
  specifics.cpp
  bitio.cpp
  combine.cpp
  frametype.cpp
  iframe.cpp
  libpnmrw.cpp
  mfwddct.cpp
  mpeg.cpp
  psearch.cpp
  readframe.cpp
  subsample.cpp
  block.cpp
  fsize.cpp
  nojpeg.cpp
  noparallel.cpp
  main.cpp
  mheaders.cpp
  opts.cpp
  pframe.cpp
  rgbtoycc.cpp
)

file(GLOB_RECURSE HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} headers/*.h)
append_gmsh_src(contrib/mpeg_encode "${SRC};${HDR}")
