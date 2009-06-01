# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshFltk${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Graphics\
      ${DASH}I../Geo ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Numeric\
      ${DASH}I../Parser ${DASH}I../Fltk ${DASH}I../Plugin ${DASH}I../utils/solvers\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/NativeFileChooser\
      ${DASH}I../contrib/TreeBrowser

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
  ../Mesh/meshPartitionOptions.h ../Common/Options.h ../Post/ColorTable.h \
  ../Parser/Parser.h ../Common/OpenFile.h ../Common/CommandLine.h \
  Solvers.h ../Plugin/PluginManager.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Mesh/Field.h ../Common/GmshConfig.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Numeric/GmshMatrix.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Post/PView.h \
  ../Mesh/BackgroundMesh.h
GUI${OBJEXT}: GUI.cpp GUI.h graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  menuWindow.h popupButton.h optionWindow.h spherePositionWidget.h \
  colorbarWindow.h ../Post/ColorTable.h fieldWindow.h pluginWindow.h \
  statisticsWindow.h visibilityWindow.h ../Common/GmshConfig.h \
  clippingWindow.h messageWindow.h manipWindow.h contextWindow.h \
  solverWindow.h aboutWindow.h fileDialogs.h Draw.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h ../Post/PView.h Solvers.h \
  ../Mesh/Field.h ../Geo/STensor3.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Common/ListUtils.h ../Plugin/PluginManager.h ../Common/OpenFile.h \
  Win32Icon.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
graphicWindow${OBJEXT}: graphicWindow.cpp GUI.h graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  paletteWindow.h mainWindow.h menuWindow.h popupButton.h messageWindow.h \
  manipWindow.h extraDialogs.h Draw.h ../Post/PView.h ../Post/PViewData.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  ../Common/OS.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
openglWindow${OBJEXT}: openglWindow.cpp openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h graphicWindow.h manipWindow.h \
  contextWindow.h visibilityWindow.h ../Common/GmshConfig.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h Draw.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h GUI.h ../Common/VertexArray.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
menuWindow${OBJEXT}: menuWindow.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GUI.h Draw.h menuWindow.h popupButton.h \
  mainWindow.h graphicWindow.h openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h optionWindow.h \
  spherePositionWidget.h colorbarWindow.h ../Post/ColorTable.h \
  statisticsWindow.h messageWindow.h contextWindow.h visibilityWindow.h \
  clippingWindow.h manipWindow.h fieldWindow.h pluginWindow.h \
  solverWindow.h aboutWindow.h fileDialogs.h partitionDialog.h \
  projectionEditor.h ../Geo/fourierProjectionFace.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/Range.h \
  classificationEditor.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h ../Common/Options.h \
  Solvers.h ../Common/CommandLine.h ../Mesh/Generator.h \
  ../Mesh/HighOrder.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Mesh/Field.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/OS.h ../Common/StringUtils.h \
  ../Common/OpenFile.h ../Common/CreateFile.h ../Geo/findLinks.h \
  ../Common/ListUtils.h ../Geo/GeoStringInterface.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
optionWindow${OBJEXT}: optionWindow.cpp ../Common/GmshConfig.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h GUI.h optionWindow.h \
  spherePositionWidget.h colorbarWindow.h ../Post/ColorTable.h \
  paletteWindow.h menuWindow.h popupButton.h extraDialogs.h Draw.h \
  ../Common/Options.h Solvers.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Common/OS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
colorbarWindow${OBJEXT}: colorbarWindow.cpp colorbarWindow.h \
  ../Post/ColorTable.h Draw.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
fieldWindow${OBJEXT}: fieldWindow.cpp GUI.h Draw.h fieldWindow.h paletteWindow.h \
  fileDialogs.h ../Common/GmshDefines.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h ../Common/GmshMessage.h \
  ../Mesh/Field.h ../Common/GmshConfig.h ../Geo/STensor3.h \
  ../Geo/SVector3.h ../Numeric/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Geo/GeoStringInterface.h \
  ../Common/ListUtils.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
pluginWindow${OBJEXT}: pluginWindow.cpp GUI.h Draw.h pluginWindow.h \
  paletteWindow.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
statisticsWindow${OBJEXT}: statisticsWindow.cpp GUI.h Draw.h statisticsWindow.h \
  paletteWindow.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/SVector3.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Post/PView.h ../Mesh/Generator.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
visibilityWindow${OBJEXT}: visibilityWindow.cpp ../Common/GmshConfig.h GUI.h \
  Draw.h visibilityWindow.h paletteWindow.h contextWindow.h \
  graphicWindow.h openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Common/GmshMessage.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/GeoStringInterface.h ../Common/ListUtils.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h ../Parser/Parser.h
clippingWindow${OBJEXT}: clippingWindow.cpp GUI.h Draw.h clippingWindow.h \
  paletteWindow.h ../Common/GmshDefines.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
messageWindow${OBJEXT}: messageWindow.cpp GUI.h messageWindow.h paletteWindow.h \
  fileDialogs.h ../Common/GmshMessage.h ../Common/OS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
manipWindow${OBJEXT}: manipWindow.cpp GUI.h Draw.h manipWindow.h paletteWindow.h \
  graphicWindow.h openglWindow.h ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
contextWindow${OBJEXT}: contextWindow.cpp GUI.h Draw.h contextWindow.h \
  paletteWindow.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GeoStringInterface.h \
  ../Common/ListUtils.h ../Common/OpenFile.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
solverWindow${OBJEXT}: solverWindow.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h GUI.h solverWindow.h paletteWindow.h \
  optionWindow.h spherePositionWidget.h colorbarWindow.h \
  ../Post/ColorTable.h messageWindow.h fileDialogs.h \
  ../Common/GmshMessage.h Solvers.h ../Common/StringUtils.h \
  ../Common/Options.h ../Common/OS.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
aboutWindow${OBJEXT}: aboutWindow.cpp GUI.h aboutWindow.h paletteWindow.h \
  ../Common/CommandLine.h ../Common/StringUtils.h ../Common/OS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
fileDialogs${OBJEXT}: fileDialogs.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Common/GmshDefines.h GUI.h \
  ../Common/CreateFile.h ../Common/Options.h ../Post/ColorTable.h Draw.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
extraDialogs${OBJEXT}: extraDialogs.cpp GUI.h paletteWindow.h \
  ../Common/GmshDefines.h ../Common/OpenFile.h ../Common/CreateFile.h \
  ../Common/Options.h ../Post/ColorTable.h Draw.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
projectionEditor${OBJEXT}: projectionEditor.cpp ../Common/GmshConfig.h GUI.h \
  projectionEditor.h ../Geo/fourierProjectionFace.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/Range.h ../Post/ColorTable.h \
  paletteWindow.h fileDialogs.h ../Geo/GModelIO_Fourier.h ../Geo/GModel.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h Draw.h ../Common/Options.h \
  ../Common/StringUtils.h ../Geo/fourierFace.h ../Geo/GFace.h \
  ../Geo/GModel.h ../Geo/Range.h ../Geo/fourierEdge.h ../Geo/GEdge.h \
  ../Geo/GModel.h ../Geo/fourierVertex.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/MVertex.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
classificationEditor${OBJEXT}: classificationEditor.cpp GUI.h \
  classificationEditor.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/SVector3.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Post/ColorTable.h \
  paletteWindow.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h Draw.h \
  ../Common/Options.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Geo/MLine.h ../Geo/MElement.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Geo/MTriangle.h \
  ../Geo/MElement.h ../Mesh/meshGFaceOptimize.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Geo/discreteEdge.h \
  ../Geo/GModel.h ../Geo/GEdge.h ../Geo/discreteVertex.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/MVertex.h ../Geo/discreteFace.h ../Geo/GModel.h \
  ../Geo/GFace.h ../Geo/discreteEdge.h ../Geo/MEdge.h
partitionDialog${OBJEXT}: partitionDialog.cpp ../Common/GmshConfig.h \
  ../Common/GmshDefines.h ../Common/GmshMessage.h GUI.h paletteWindow.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h Draw.h ../Common/Options.h ../Post/ColorTable.h \
  ../Mesh/meshPartition.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
Draw${OBJEXT}: Draw.cpp GUI.h graphicWindow.h openglWindow.h \
  ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  optionWindow.h spherePositionWidget.h colorbarWindow.h \
  ../Post/ColorTable.h ../Common/GmshDefines.h ../Common/GmshMessage.h \
  Draw.h ../Common/StringUtils.h ../Graphics/gl2ps.h \
  ../Common/GmshConfig.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
Solvers${OBJEXT}: Solvers.cpp GUI.h solverWindow.h menuWindow.h popupButton.h \
  ../Common/GmshMessage.h ../Common/StringUtils.h Solvers.h \
  ../Common/GmshSocket.h ../Common/GmshConfig.h ../Common/OpenFile.h \
  ../Post/PView.h ../Geo/SPoint3.h Draw.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h ../Common/OS.h
