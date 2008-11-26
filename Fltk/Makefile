# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshFltk${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Graphics\
      ${DASH}I../Geo ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Numeric\
      ${DASH}I../Parser ${DASH}I../Fltk ${DASH}I../Plugin ${DASH}I../utils/solvers\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/NativeFileChooser

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Main.cpp \
      GUI.cpp\
        GUI_Extras.cpp\
        GUI_Projection.cpp\
        GUI_Classifier.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      Solvers.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

res:
	windres Win32Icon.rc -O coff Win32Icon.res

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
Main${OBJEXT}: Main.cpp GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Common/GmshUI.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Common/Gmsh.h ../Common/GmshMessage.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Common/Options.h ../Parser/Parser.h ../Common/OpenFile.h \
  ../Common/CommandLine.h Solvers.h ../Plugin/PluginManager.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Mesh/BackgroundMesh.h
GUI${OBJEXT}: GUI.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/Options.h ../Post/ColorTable.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h Callbacks.h \
  Win32Icon.h ../Common/OpenFile.h ../Common/CommandLine.h \
  ../Mesh/Generator.h Solvers.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Common/ListUtils.h ../Numeric/GmshMatrix.h Shortcut_Window.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GeoStringInterface.h \
  ../Common/StringUtils.h ../Common/GmshSocket.h
GUI_Extras${OBJEXT}: GUI_Extras.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Common/CreateFile.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  Shortcut_Window.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Mesh/Partition.h File_Picker.h
GUI_Projection${OBJEXT}: GUI_Projection.cpp ../Geo/GModelIO_Fourier.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Graphics/Draw.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/StringUtils.h \
  ../Graphics/SelectBuffer.h GUI_Projection.h ../Common/GmshUI.h \
  ../Geo/fourierProjectionFace.h ../Geo/GModel.h ../Geo/Range.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  Shortcut_Window.h GUI_Extras.h ../Geo/fourierFace.h ../Geo/GFace.h \
  ../Geo/GModel.h ../Geo/Range.h ../Geo/fourierEdge.h ../Geo/GEdge.h \
  ../Geo/GModel.h ../Geo/fourierVertex.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/MVertex.h
GUI_Classifier${OBJEXT}: GUI_Classifier.cpp GUI_Classifier.h ../Common/GmshUI.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Post/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Mesh/Field.h ../Post/PView.h Shortcut_Window.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Graphics/Draw.h ../Common/Options.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Graphics/SelectBuffer.h GUI_Projection.h \
  ../Geo/fourierProjectionFace.h ../Geo/GModel.h ../Geo/Range.h \
  GUI_Extras.h ../Mesh/meshGFaceDelaunayInsertion.h \
  ../Mesh/meshGFaceOptimize.h ../Mesh/meshGFaceDelaunayInsertion.h \
  ../Geo/discreteEdge.h ../Geo/GModel.h ../Geo/GEdge.h \
  ../Geo/discreteFace.h ../Geo/GModel.h ../Geo/GFace.h
Callbacks${OBJEXT}: Callbacks.cpp ../Common/GmshUI.h ../Common/GmshMessage.h \
  ../Common/MallocUtils.h ../Common/ListUtils.h ../Common/StringUtils.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Geo/GeoStringInterface.h ../Geo/findLinks.h ../Mesh/Generator.h \
  ../Mesh/HighOrder.h ../Graphics/Draw.h ../Graphics/SelectBuffer.h \
  ../Post/PView.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewData.h ../Common/CreateFile.h ../Common/OpenFile.h \
  ../Common/CommandLine.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/Options.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Popup_Button.h SpherePosition_Widget.h \
  ../Mesh/Field.h GUI_Extras.h Callbacks.h ../Plugin/Plugin.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Plugin/PluginManager.h \
  ../Common/Visibility.h ../Common/GmshDefines.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h Solvers.h ../Common/OS.h \
  ../Mesh/BackgroundMesh.h
Opengl${OBJEXT}: Opengl.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Graphics/Draw.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Graphics/SelectBuffer.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Common/StringUtils.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Post/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Mesh/Field.h ../Post/PView.h ../Graphics/gl2ps.h
Opengl_Window${OBJEXT}: Opengl_Window.cpp ../Common/GmshUI.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Graphics/Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Graphics/SelectBuffer.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  ../Geo/MElement.h ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h
Colorbar_Window${OBJEXT}: Colorbar_Window.cpp ../Common/GmshUI.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Mesh/Field.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Solvers${OBJEXT}: Solvers.cpp ../Common/GmshMessage.h ../Common/StringUtils.h \
  Solvers.h ../Common/GmshSocket.h ../Common/OpenFile.h \
  ../Common/GmshUI.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Post/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Mesh/Field.h ../Post/PView.h ../Geo/SPoint3.h ../Graphics/Draw.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Common/OS.h
