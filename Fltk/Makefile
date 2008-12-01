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
        graphicWindow.cpp\
          openglWindow.cpp\
        menuWindow.cpp\
        optionWindow.cpp\
          colorbarWindow.cpp\
        fieldWindow.cpp\
        pluginWindow.cpp\
        statisticsWindow.cpp\
        visibilityWindow.cpp\
        clippingWindow.cpp\
        messageWindow.cpp\
        manipWindow.cpp\
        contextWindow.cpp\
        solverWindow.cpp\
        aboutWindow.cpp\
        fileDialogs.cpp\
        extraDialogs.cpp\
        projectionEditor.cpp\
        classificationEditor.cpp\
        partitionDialog.cpp\
      Callbacks.cpp\
      Draw.cpp\
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
Main${OBJEXT}: Main.cpp GUI.h menuWindow.h popupButton.h ../Common/Gmsh.h \
  ../Common/GmshMessage.h Draw.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/Options.h ../Post/ColorTable.h \
  ../Parser/Parser.h ../Common/OpenFile.h ../Common/CommandLine.h \
  Solvers.h ../Plugin/PluginManager.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Mesh/Field.h ../Post/PView.h \
  ../Mesh/BackgroundMesh.h
GUI${OBJEXT}: GUI.cpp GUI.h graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  menuWindow.h popupButton.h optionWindow.h spherePositionWidget.h \
  colorbarWindow.h ../Post/ColorTable.h fieldWindow.h pluginWindow.h \
  statisticsWindow.h visibilityWindow.h clippingWindow.h messageWindow.h \
  manipWindow.h contextWindow.h solverWindow.h aboutWindow.h \
  fileDialogs.h ../Common/GmshDefines.h ../Common/GmshMessage.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h Solvers.h ../Mesh/Field.h \
  ../Plugin/Plugin.h ../Common/Options.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Common/ListUtils.h ../Numeric/GmshMatrix.h \
  ../Plugin/PluginManager.h Callbacks.h ../Common/OpenFile.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
graphicWindow${OBJEXT}: graphicWindow.cpp graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  shortcutWindow.h ../Post/PView.h ../Post/PViewData.h Callbacks.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
openglWindow${OBJEXT}: openglWindow.cpp openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h graphicWindow.h manipWindow.h \
  contextWindow.h ../Common/GmshDefines.h ../Common/GmshMessage.h Draw.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Graphics/SelectBuffer.h ../Graphics/drawContext.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h GUI.h \
  ../Geo/MElement.h ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h
menuWindow${OBJEXT}: menuWindow.cpp GUI.h menuWindow.h popupButton.h \
  shortcutWindow.h Callbacks.h ../Common/Options.h ../Post/ColorTable.h \
  Solvers.h ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
optionWindow${OBJEXT}: optionWindow.cpp GUI.h optionWindow.h \
  spherePositionWidget.h colorbarWindow.h ../Post/ColorTable.h \
  shortcutWindow.h ../Common/GmshMessage.h ../Common/Options.h \
  Callbacks.h ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
colorbarWindow${OBJEXT}: colorbarWindow.cpp colorbarWindow.h \
  ../Post/ColorTable.h GUI.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
fieldWindow${OBJEXT}: fieldWindow.cpp GUI.h fieldWindow.h shortcutWindow.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h Callbacks.h \
  ../Common/GmshMessage.h ../Mesh/Field.h ../Geo/GeoStringInterface.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
pluginWindow${OBJEXT}: pluginWindow.cpp GUI.h pluginWindow.h shortcutWindow.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Numeric/GmshMatrix.h Callbacks.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
statisticsWindow${OBJEXT}: statisticsWindow.cpp GUI.h statisticsWindow.h \
  shortcutWindow.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Post/PView.h Callbacks.h \
  ../Mesh/Generator.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
visibilityWindow${OBJEXT}: visibilityWindow.cpp GUI.h visibilityWindow.h \
  shortcutWindow.h Callbacks.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
clippingWindow${OBJEXT}: clippingWindow.cpp GUI.h clippingWindow.h \
  shortcutWindow.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h Callbacks.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
messageWindow${OBJEXT}: messageWindow.cpp GUI.h messageWindow.h shortcutWindow.h \
  Callbacks.h ../Common/GmshMessage.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
manipWindow${OBJEXT}: manipWindow.cpp GUI.h manipWindow.h shortcutWindow.h \
  Callbacks.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
contextWindow${OBJEXT}: contextWindow.cpp GUI.h contextWindow.h shortcutWindow.h \
  Callbacks.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
solverWindow${OBJEXT}: solverWindow.cpp GUI.h solverWindow.h shortcutWindow.h \
  Solvers.h Callbacks.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
aboutWindow${OBJEXT}: aboutWindow.cpp GUI.h aboutWindow.h shortcutWindow.h \
  ../Common/CommandLine.h ../Common/StringUtils.h Callbacks.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
fileDialogs${OBJEXT}: fileDialogs.cpp GUI.h shortcutWindow.h \
  ../Common/GmshDefines.h ../Common/CreateFile.h ../Common/Options.h \
  ../Post/ColorTable.h Draw.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h fileChooser.h
extraDialogs${OBJEXT}: extraDialogs.cpp GUI.h shortcutWindow.h \
  ../Common/GmshDefines.h ../Common/CreateFile.h ../Common/Options.h \
  ../Post/ColorTable.h Draw.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
projectionEditor${OBJEXT}: projectionEditor.cpp GUI.h projectionEditor.h \
  shortcutWindow.h ../Geo/fourierProjectionFace.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/Range.h ../Post/ColorTable.h \
  fileDialogs.h ../Geo/GModelIO_Fourier.h ../Geo/GModel.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h Draw.h ../Common/Options.h \
  ../Common/StringUtils.h ../Graphics/SelectBuffer.h \
  ../Graphics/drawContext.h ../Geo/fourierFace.h ../Geo/GFace.h \
  ../Geo/GModel.h ../Geo/Range.h ../Geo/fourierEdge.h ../Geo/GEdge.h \
  ../Geo/GModel.h ../Geo/fourierVertex.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/MVertex.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
classificationEditor${OBJEXT}: classificationEditor.cpp GUI.h \
  classificationEditor.h shortcutWindow.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Post/ColorTable.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h Draw.h ../Common/Options.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Graphics/SelectBuffer.h ../Graphics/drawContext.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Mesh/meshGFaceOptimize.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Geo/discreteEdge.h \
  ../Geo/GModel.h ../Geo/GEdge.h ../Geo/discreteFace.h ../Geo/GModel.h \
  ../Geo/GFace.h
partitionDialog${OBJEXT}: partitionDialog.cpp GUI.h shortcutWindow.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h Draw.h ../Common/Options.h ../Post/ColorTable.h \
  ../Mesh/Partition.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Callbacks${OBJEXT}: Callbacks.cpp GUI.h menuWindow.h popupButton.h \
  graphicWindow.h openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h optionWindow.h \
  spherePositionWidget.h colorbarWindow.h ../Post/ColorTable.h \
  visibilityWindow.h clippingWindow.h statisticsWindow.h solverWindow.h \
  manipWindow.h messageWindow.h fieldWindow.h pluginWindow.h \
  contextWindow.h aboutWindow.h partitionDialog.h extraDialogs.h \
  fileDialogs.h ../Common/GmshMessage.h ../Common/MallocUtils.h \
  ../Common/ListUtils.h ../Common/StringUtils.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Geo/GeoStringInterface.h ../Geo/findLinks.h ../Mesh/Generator.h \
  ../Mesh/HighOrder.h Draw.h ../Graphics/SelectBuffer.h \
  ../Graphics/drawContext.h ../Post/PView.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewData.h ../Common/CreateFile.h \
  ../Common/OpenFile.h ../Common/CommandLine.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Common/Options.h \
  Callbacks.h ../Plugin/Plugin.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Plugin/PluginManager.h ../Common/Visibility.h \
  ../Common/GmshDefines.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h Solvers.h ../Common/OS.h ../Mesh/Field.h \
  ../Mesh/BackgroundMesh.h
Draw${OBJEXT}: Draw.cpp GUI.h graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h Draw.h ../Common/StringUtils.h \
  ../Graphics/gl2ps.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Solvers${OBJEXT}: Solvers.cpp GUI.h solverWindow.h menuWindow.h popupButton.h \
  ../Common/GmshMessage.h ../Common/StringUtils.h Solvers.h \
  ../Common/GmshSocket.h ../Common/OpenFile.h ../Post/PView.h \
  ../Geo/SPoint3.h Draw.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/OS.h
