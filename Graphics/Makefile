# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshGraphics${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Fltk ${DASH}I../Numeric\
      ${DASH}I../Plugin\
      ${DASH}I../contrib/MathEval ${DASH}I../contrib/ANN/include

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Trackball.cpp \
      Iso.cpp \
      ReadImg.cpp \
      drawContext.cpp \
      drawMesh.cpp \
      drawGeom.cpp \
      drawPost.cpp \
      drawAxes.cpp \
      drawScales.cpp \
      drawGraph2d.cpp \
      drawGlyph.cpp \
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2png.cpp\
      gl2ppm.cpp\
      gl2yuv.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ}
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	${RM} *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Trackball${OBJEXT}: Trackball.cpp Trackball.h
Iso${OBJEXT}: Iso.cpp ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h
ReadImg${OBJEXT}: ReadImg.cpp ReadImg.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h
drawContext${OBJEXT}: drawContext.cpp ../Common/GmshMessage.h drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h Trackball.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h gl2ps.h
drawMesh${OBJEXT}: drawMesh.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/GmshMessage.h ../Common/GmshDefines.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MLine.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Geo/MTriangle.h \
  ../Geo/MElement.h ../Geo/MQuadrangle.h ../Geo/MElement.h \
  ../Geo/MTetrahedron.h ../Geo/MElement.h ../Geo/MHexahedron.h \
  ../Geo/MElement.h ../Geo/MPrism.h ../Geo/MElement.h ../Geo/MPyramid.h \
  ../Geo/MElement.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Common/OS.h gl2ps.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Post/PView.h \
  ../Post/PViewData.h
drawGeom${OBJEXT}: drawGeom.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h gl2ps.h ../Common/GmshConfig.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h
drawPost${OBJEXT}: drawPost.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h Iso.h ../Post/PView.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewData.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/SmoothData.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h gl2ps.h
drawAxes${OBJEXT}: drawAxes.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  gl2ps.h
drawScales${OBJEXT}: drawScales.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PView.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewData.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h gl2ps.h
drawGraph2d${OBJEXT}: drawGraph2d.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PView.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewData.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h gl2ps.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
drawGlyph${OBJEXT}: drawGlyph.cpp drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Fltk/Draw.h ../Common/GmshDefines.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Common/StringUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h gl2ps.h
gl2ps${OBJEXT}: gl2ps.cpp gl2ps.h ../Common/GmshConfig.h
gl2gif${OBJEXT}: gl2gif.cpp ../Common/MallocUtils.h gl2gif.h PixelBuffer.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Fltk/Draw.h
gl2jpeg${OBJEXT}: gl2jpeg.cpp ../Common/GmshConfig.h gl2jpeg.h PixelBuffer.h \
  ../Common/GmshMessage.h ../Fltk/Draw.h
gl2png${OBJEXT}: gl2png.cpp ../Common/GmshConfig.h gl2png.h PixelBuffer.h \
  ../Common/GmshMessage.h ../Fltk/Draw.h
gl2ppm${OBJEXT}: gl2ppm.cpp gl2ppm.h PixelBuffer.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Fltk/Draw.h
gl2yuv${OBJEXT}: gl2yuv.cpp ../Common/MallocUtils.h gl2yuv.h PixelBuffer.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Fltk/Draw.h
