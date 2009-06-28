# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshCommon${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../Plugin ${DASH}I../Fltk ${DASH}I../contrib/MathEval\
      ${DASH}I../contrib/ANN/include

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Gmsh.cpp\
      GmshMessage.cpp\
      GmshDaemon.cpp\
      Context.cpp\
      Options.cpp\
      CommandLine.cpp\
      OS.cpp\
      OpenFile.cpp\
      CreateFile.cpp\
      VertexArray.cpp\
      SmoothData.cpp\
      Octree.cpp OctreeInternals.cpp\
      StringUtils.cpp\
      ListUtils.cpp\
      TreeUtils.cpp avl.cpp\
      MallocUtils.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} Main${OBJEXT}
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
Gmsh${OBJEXT}: Gmsh.cpp GmshConfig.h GmshDefines.h ../Numeric/GmshPredicates.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SOrientedBoundingBox.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/Pair.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h GmshMessage.h OpenFile.h \
  CreateFile.h Options.h ../Post/ColorTable.h CommandLine.h OS.h \
  ../Mesh/Generator.h ../Mesh/Field.h ../Common/GmshConfig.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Post/PView.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Mesh/meshPartition.h GmshDaemon.h \
  ../Plugin/PluginManager.h
GmshMessage${OBJEXT}: GmshMessage.cpp GmshConfig.h GmshMessage.h Gmsh.h \
  Options.h ../Post/ColorTable.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h OS.h ../Fltk/GUI.h \
  ../Fltk/messageWindow.h ../Fltk/extraDialogs.h
GmshDaemon${OBJEXT}: GmshDaemon.cpp GmshMessage.h OS.h GmshSocket.h GmshConfig.h
Context${OBJEXT}: Context.cpp GmshConfig.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
Options${OBJEXT}: Options.cpp GmshConfig.h GmshDefines.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/SOrientedBoundingBox.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/Pair.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GmshMessage.h ../Fltk/Draw.h \
  ../Mesh/Generator.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h Options.h ../Post/ColorTable.h \
  DefaultOptions.h ../Mesh/Field.h ../Common/GmshConfig.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Post/PView.h ../Mesh/BackgroundMesh.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewData.h ../Post/adaptiveData.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Fltk/GUI.h \
  ../Fltk/Solvers.h ../Fltk/menuWindow.h ../Fltk/popupButton.h \
  ../Fltk/graphicWindow.h ../Fltk/openglWindow.h \
  ../Graphics/drawContext.h ../Fltk/optionWindow.h \
  ../Fltk/spherePositionWidget.h ../Fltk/colorbarWindow.h \
  ../Fltk/solverWindow.h ../Fltk/manipWindow.h ../Fltk/messageWindow.h \
  ../Fltk/contextWindow.h ../Fltk/clippingWindow.h
CommandLine${OBJEXT}: CommandLine.cpp GmshConfig.h GmshDefines.h GmshVersion.h \
  GmshMessage.h OpenFile.h CommandLine.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h Options.h ../Post/ColorTable.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SOrientedBoundingBox.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/Pair.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h CreateFile.h OS.h \
  ../Post/PView.h
OS${OBJEXT}: OS.cpp GmshMessage.h
OpenFile${OBJEXT}: OpenFile.cpp GmshConfig.h GmshMessage.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SOrientedBoundingBox.h ../Geo/SVector3.h \
  ../Geo/SPoint2.h ../Geo/Pair.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Mesh/HighOrder.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SVector3.h \
  Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  OpenFile.h CommandLine.h ../Graphics/ReadImg.h OS.h StringUtils.h \
  ../Geo/GeomMeshMatcher.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Geo/Pair.h \
  ../Parser/Parser.h ../Post/PView.h ../Post/PViewData.h ../Fltk/GUI.h \
  ../Fltk/Draw.h
CreateFile${OBJEXT}: CreateFile.cpp GmshConfig.h GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/SOrientedBoundingBox.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/Pair.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GmshDefines.h StringUtils.h Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h Options.h \
  ../Post/ColorTable.h ../Fltk/GUI.h ../Fltk/graphicWindow.h \
  ../Fltk/openglWindow.h ../Graphics/drawContext.h ../Graphics/gl2ps.h \
  ../Common/GmshConfig.h ../Graphics/gl2gif.h ../Graphics/PixelBuffer.h \
  ../Common/GmshMessage.h ../Fltk/Draw.h ../Graphics/gl2jpeg.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2png.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2ppm.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2yuv.h \
  ../Graphics/PixelBuffer.h
VertexArray${OBJEXT}: VertexArray.cpp VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h
SmoothData${OBJEXT}: SmoothData.cpp SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h
Octree${OBJEXT}: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals${OBJEXT}: OctreeInternals.cpp GmshMessage.h OctreeInternals.h
StringUtils${OBJEXT}: StringUtils.cpp StringUtils.h GmshMessage.h
ListUtils${OBJEXT}: ListUtils.cpp MallocUtils.h ListUtils.h TreeUtils.h avl.h \
  GmshMessage.h
TreeUtils${OBJEXT}: TreeUtils.cpp MallocUtils.h TreeUtils.h avl.h ListUtils.h
avl${OBJEXT}: avl.cpp avl.h MallocUtils.h
MallocUtils${OBJEXT}: MallocUtils.cpp MallocUtils.h GmshMessage.h
