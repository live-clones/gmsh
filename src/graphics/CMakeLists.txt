# Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file in the Gmsh root directory for license information.
# Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  Camera.cpp
  Trackball.cpp
  ReadImg.cpp
  glApi.cpp
  glLegacy.cpp
  glMatrix.cpp
  glImmediate.cpp
  glShader.cpp
  drawContext.cpp
  drawPick.cpp
  drawQuery.cpp
  drawMesh.cpp
  drawGeom.cpp
  drawPost.cpp
  drawAxes.cpp
  drawScales.cpp
  drawGraph2d.cpp
  axisTicks.cpp
  drawGlyph.cpp
  glyphList.cpp
  stringQueue.cpp
  stbStrings.cpp
  offscreenContext.cpp
  drawContextOffscreen.cpp
  webView.cpp
  gl2ps.cpp
  gl2gif.cpp
  gl2jpeg.cpp
  gl2png.cpp
  gl2ppm.cpp
  gl2yuv.cpp
  gl2pgf.cpp
  gl2mp4.cpp
  gl2mpeg.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(src/graphics "${SRC};${HDR}")
