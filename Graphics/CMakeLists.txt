# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Trackball.cpp 
  ReadImg.cpp 
  drawContext.cpp 
  drawMesh.cpp 
  drawGeom.cpp 
  drawPost.cpp 
  drawAxes.cpp 
  drawScales.cpp 
  drawGraph2d.cpp 
  drawGlyph.cpp 
  gl2ps.cpp
  gl2gif.cpp
  gl2jpeg.cpp
  gl2png.cpp
  gl2ppm.cpp
  gl2yuv.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Graphics *.h) 
append_gmsh_src(Graphics "${SRC};${HDR}")
