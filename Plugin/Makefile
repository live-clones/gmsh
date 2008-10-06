# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshPlugin${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Graphics ${DASH}I../Geo\
      ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Fltk ${DASH}I../Numeric\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/Triangle\
      ${DASH}I../contrib/MathEval

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Plugin.cpp PluginManager.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp \
        Smooth.cpp CutParametric.cpp\
        Lambda2.cpp\
        Eigenvectors.cpp Eigenvalues.cpp\
        StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
          LongitudeLatitude.cpp\
        Triangulate.cpp\
        Warp.cpp SphericalRaise.cpp\
        Skin.cpp GSHHS.cpp \
        Extract.cpp ExtractElements.cpp ExtractEdges.cpp\
        MakeSimplex.cpp\
        Evaluate.cpp FieldView.cpp \
        Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp\
        Annotate.cpp Remove.cpp\
        Probe.cpp\
        HarmonicToTime.cpp ModulusPhase.cpp

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
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Common/GmshMatrix.h
PluginManager.o: PluginManager.cpp /usr/include/fltk-1.1/FL/Fl.H \
  /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H \
  /usr/include/fltk-1.1/FL/filename.H Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h PluginManager.h CutMap.h Levelset.h CutGrid.h \
  StreamLines.h CutPlane.h CutParametric.h CutSphere.h Skin.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h Extract.h \
  ExtractElements.h ExtractEdges.h HarmonicToTime.h ModulusPhase.h \
  Integrate.h Gradient.h Curl.h Divergence.h Annotate.h Remove.h \
  MakeSimplex.h Smooth.h Transform.h LongitudeLatitude.h Triangulate.h \
  Warp.h SphericalRaise.h Eigenvectors.h Eigenvalues.h Lambda2.h \
  Evaluate.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h Probe.h FieldView.h GSHHS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h MakeSimplex.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Post/adaptiveData.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Smooth.o: Smooth.cpp Smooth.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h
CutParametric.o: CutParametric.cpp ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h ../contrib/MathEval/matheval.h
Lambda2.o: Lambda2.cpp Lambda2.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Eigenvectors.o: Eigenvectors.cpp Eigenvectors.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/EigSolve.h
Eigenvalues.o: Eigenvalues.cpp Eigenvalues.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
StreamLines.o: StreamLines.cpp StreamLines.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Common/GmshUI.h /usr/include/fltk-1.1/FL/Fl.H \
  /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h
CutGrid.o: CutGrid.cpp ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h
Transform.o: Transform.cpp Transform.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h
LongitudeLatitude.o: LongitudeLatitude.cpp LongitudeLatitude.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h
Triangulate.o: Triangulate.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/discreteFace.h ../Geo/GModel.h \
  ../Mesh/DivideAndConquer.h ../Common/Message.h ../Geo/MVertex.h \
  Triangulate.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Warp.o: Warp.cpp Warp.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Common/GmshMatrix.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SphericalRaise.o: SphericalRaise.cpp SphericalRaise.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Skin.o: Skin.cpp Skin.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Common/GmshMatrix.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ../Common/MallocUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
GSHHS.o: GSHHS.cpp GSHHS.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Mesh/Field.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/SVector3.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/Pair.h ../Geo/GRegion.h
Extract.o: Extract.cpp Extract.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../contrib/MathEval/matheval.h
ExtractElements.o: ExtractElements.cpp ExtractElements.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
ExtractEdges.o: ExtractEdges.cpp ExtractEdges.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Mesh/BDS.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SBoundingBox3d.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GVertex.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h
MakeSimplex.o: MakeSimplex.cpp MakeSimplex.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h
Evaluate.o: Evaluate.cpp Evaluate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../contrib/MathEval/matheval.h
FieldView.o: FieldView.cpp FieldView.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Mesh/Field.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/SVector3.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/Pair.h ../Geo/GRegion.h
Integrate.o: Integrate.cpp Integrate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h
Gradient.o: Gradient.cpp Gradient.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Curl.o: Curl.cpp Curl.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Common/GmshMatrix.h \
  ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Divergence.o: Divergence.cpp Divergence.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Annotate.o: Annotate.cpp Annotate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Fltk/GUI.h /usr/include/fltk-1.1/FL/Fl_Window.H \
  /usr/include/fltk-1.1/FL/Fl_Group.H \
  /usr/include/fltk-1.1/FL/Fl_Widget.H \
  /usr/include/fltk-1.1/FL/Fl_Double_Window.H \
  /usr/include/fltk-1.1/FL/Fl_Window.H /usr/include/fltk-1.1/FL/Fl_Box.H \
  /usr/include/fltk-1.1/FL/Fl_Menu_Bar.H \
  /usr/include/fltk-1.1/FL/Fl_Menu_.H \
  /usr/include/fltk-1.1/FL/Fl_Menu_Item.H \
  /usr/include/fltk-1.1/FL/Fl_Image.H \
  /usr/include/fltk-1.1/FL/Fl_Menu_Button.H \
  /usr/include/fltk-1.1/FL/fl_draw.H /usr/include/fltk-1.1/FL/Fl_Choice.H \
  /usr/include/fltk-1.1/FL/Fl_Scroll.H \
  /usr/include/fltk-1.1/FL/Fl_Scrollbar.H \
  /usr/include/fltk-1.1/FL/Fl_Slider.H \
  /usr/include/fltk-1.1/FL/Fl_Valuator.H \
  /usr/include/fltk-1.1/FL/Fl_Tabs.H /usr/include/fltk-1.1/FL/Fl_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Return_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Repeat_Button.H \
  /usr/include/fltk-1.1/FL/Fl.H \
  /usr/include/fltk-1.1/FL/Fl_Light_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Check_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Light_Button.H \
  /usr/include/fltk-1.1/FL/Fl_Input.H \
  /usr/include/fltk-1.1/FL/Fl_Input_.H \
  /usr/include/fltk-1.1/FL/Fl_Value_Input.H \
  /usr/include/fltk-1.1/FL/Fl_Input.H \
  /usr/include/fltk-1.1/FL/Fl_Output.H \
  /usr/include/fltk-1.1/FL/Fl_Multiline_Output.H \
  /usr/include/fltk-1.1/FL/Fl_Output.H \
  /usr/include/fltk-1.1/FL/Fl_Bitmap.H \
  /usr/include/fltk-1.1/FL/Fl_Browser.H \
  /usr/include/fltk-1.1/FL/Fl_Browser_.H \
  /usr/include/fltk-1.1/FL/Fl_Multi_Browser.H \
  /usr/include/fltk-1.1/FL/Fl_Browser.H \
  /usr/include/fltk-1.1/FL/Fl_Hold_Browser.H /usr/include/fltk-1.1/FL/x.H \
  /usr/include/fltk-1.1/FL/Fl_Color_Chooser.H \
  /usr/include/fltk-1.1/FL/Fl_Group.H /usr/include/fltk-1.1/FL/fl_ask.H \
  /usr/include/fltk-1.1/FL/Fl_Tooltip.H \
  /usr/include/fltk-1.1/FL/Fl_Widget.H \
  /usr/include/fltk-1.1/FL/Fl_Shared_Image.H \
  /usr/include/fltk-1.1/FL/Fl_File_Icon.H ../Fltk/Opengl_Window.h \
  /usr/include/fltk-1.1/FL/Fl_Gl_Window.H ../Fltk/Colorbar_Window.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h \
  ../Graphics/Draw.h
Remove.o: Remove.cpp Remove.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Common/GmshUI.h \
  /usr/include/fltk-1.1/FL/Fl.H /usr/include/fltk-1.1/FL/Enumerations.H \
  /usr/include/fltk-1.1/FL/Fl_Export.H /usr/include/fltk-1.1/FL/gl.h \
  ../Graphics/Draw.h
HarmonicToTime.o: HarmonicToTime.cpp HarmonicToTime.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h
ModulusPhase.o: ModulusPhase.cpp ModulusPhase.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h
