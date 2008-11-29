# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
      Options.cpp\
      CommandLine.cpp\
      OS.cpp\
      OpenFile.cpp\
      CreateFile.cpp\
      Visibility.cpp\
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
Gmsh${OBJEXT}: Gmsh.cpp GmshDefines.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GmshMessage.h OpenFile.h CreateFile.h Options.h \
  ../Post/ColorTable.h CommandLine.h OS.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Mesh/Generator.h ../Mesh/Field.h \
  ../Post/PView.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Mesh/Partition.h GmshDaemon.h \
  ../Plugin/PluginManager.h
GmshMessage${OBJEXT}: GmshMessage.cpp GmshMessage.h Gmsh.h Options.h \
  ../Post/ColorTable.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h OS.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Fltk/Colorbar_Window.h ../Common/GmshUI.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  ../Fltk/GUI_Extras.h
GmshDaemon${OBJEXT}: GmshDaemon.cpp GmshMessage.h OS.h GmshSocket.h
Options${OBJEXT}: Options.cpp GmshUI.h GmshDefines.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GmshMessage.h ../Fltk/Draw.h \
  ../Mesh/Generator.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h Options.h ../Post/ColorTable.h \
  DefaultOptions.h ../Mesh/Field.h ../Post/PView.h \
  ../Mesh/BackgroundMesh.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewData.h ../Post/adaptiveData.h ../Common/ListUtils.h \
  ../Numeric/GmshMatrix.h ../Common/GmshMessage.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Fltk/Solvers.h \
  ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Graphics/drawContext.h \
  ../Fltk/Colorbar_Window.h ../Common/GmshUI.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h
CommandLine${OBJEXT}: CommandLine.cpp GmshUI.h GmshDefines.h GmshVersion.h \
  GmshMessage.h OpenFile.h CommandLine.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h Options.h ../Post/ColorTable.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h CreateFile.h OS.h ../Post/PView.h
OS${OBJEXT}: OS.cpp GmshMessage.h
OpenFile${OBJEXT}: OpenFile.cpp GmshMessage.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h OpenFile.h \
  CommandLine.h ../Graphics/ReadImg.h OS.h StringUtils.h \
  ../Parser/Parser.h ../Post/PView.h ../Post/PViewData.h GmshUI.h \
  ../Fltk/Draw.h ../Graphics/SelectBuffer.h ../Graphics/drawContext.h \
  ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h \
  ../Common/GmshUI.h ../Post/ColorTable.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h
CreateFile${OBJEXT}: CreateFile.cpp GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GmshDefines.h StringUtils.h Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h Options.h \
  ../Post/ColorTable.h GmshUI.h ../Graphics/gl2ps.h ../Graphics/gl2gif.h \
  ../Graphics/PixelBuffer.h ../Common/GmshUI.h ../Common/GmshMessage.h \
  ../Fltk/Draw.h ../Common/MallocUtils.h ../Graphics/gl2jpeg.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2png.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2ppm.h \
  ../Graphics/PixelBuffer.h ../Graphics/gl2yuv.h \
  ../Graphics/PixelBuffer.h
Visibility${OBJEXT}: Visibility.cpp Visibility.h GmshDefines.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Parser/Parser.h
VertexArray${OBJEXT}: VertexArray.cpp VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SmoothData${OBJEXT}: SmoothData.cpp SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Octree${OBJEXT}: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals${OBJEXT}: OctreeInternals.cpp GmshMessage.h OctreeInternals.h
StringUtils${OBJEXT}: StringUtils.cpp StringUtils.h
ListUtils${OBJEXT}: ListUtils.cpp MallocUtils.h ListUtils.h TreeUtils.h avl.h \
  GmshMessage.h
TreeUtils${OBJEXT}: TreeUtils.cpp MallocUtils.h TreeUtils.h avl.h ListUtils.h
avl${OBJEXT}: avl.cpp avl.h MallocUtils.h
MallocUtils${OBJEXT}: MallocUtils.cpp MallocUtils.h GmshMessage.h
