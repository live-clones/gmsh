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
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Plugin${OBJEXT}: Plugin.cpp Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h
PluginManager${OBJEXT}: PluginManager.cpp Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h PluginManager.h CutMap.h Levelset.h CutGrid.h \
  StreamLines.h CutPlane.h CutParametric.h CutSphere.h Skin.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h Extract.h \
  ExtractElements.h ExtractEdges.h HarmonicToTime.h ModulusPhase.h \
  Integrate.h Gradient.h Curl.h Divergence.h Annotate.h Remove.h \
  MakeSimplex.h Smooth.h Transform.h LongitudeLatitude.h Triangulate.h \
  Warp.h SphericalRaise.h Eigenvectors.h Eigenvalues.h Lambda2.h \
  Evaluate.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h Probe.h FieldView.h GSHHS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
Levelset${OBJEXT}: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h MakeSimplex.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Post/adaptiveData.h
CutPlane${OBJEXT}: CutPlane.cpp ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Fltk/Draw.h CutPlane.h \
  Levelset.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
CutSphere${OBJEXT}: CutSphere.cpp ../Fltk/Draw.h CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
CutMap${OBJEXT}: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Smooth${OBJEXT}: Smooth.cpp Smooth.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h
CutParametric${OBJEXT}: CutParametric.cpp ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Fltk/Draw.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  CutParametric.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
Lambda2${OBJEXT}: Lambda2.cpp Lambda2.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
Eigenvectors${OBJEXT}: Eigenvectors.cpp Eigenvectors.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/EigSolve.h
Eigenvalues${OBJEXT}: Eigenvalues.cpp Eigenvalues.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
StreamLines${OBJEXT}: StreamLines.cpp ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Fltk/Draw.h StreamLines.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h
CutGrid${OBJEXT}: CutGrid.cpp ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Graphics/drawContext.h ../Fltk/Draw.h
Transform${OBJEXT}: Transform.cpp Transform.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h
LongitudeLatitude${OBJEXT}: LongitudeLatitude.cpp LongitudeLatitude.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h
Triangulate${OBJEXT}: Triangulate.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/discreteFace.h ../Geo/GModel.h \
  ../Geo/GFace.h ../Mesh/DivideAndConquer.h ../Common/GmshMessage.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h Triangulate.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h ../Post/PView.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
Warp${OBJEXT}: Warp.cpp Warp.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SphericalRaise${OBJEXT}: SphericalRaise.cpp SphericalRaise.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Skin${OBJEXT}: Skin.cpp Skin.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ../Common/MallocUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
GSHHS${OBJEXT}: GSHHS.cpp GSHHS.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Mesh/Field.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h
Extract${OBJEXT}: Extract.cpp Extract.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h
ExtractElements${OBJEXT}: ExtractElements.cpp ExtractElements.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
ExtractEdges${OBJEXT}: ExtractEdges.cpp ExtractEdges.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Mesh/BDS.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h
MakeSimplex${OBJEXT}: MakeSimplex.cpp MakeSimplex.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h
Evaluate${OBJEXT}: Evaluate.cpp Evaluate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h
FieldView${OBJEXT}: FieldView.cpp FieldView.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Mesh/Field.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h
Integrate${OBJEXT}: Integrate.cpp Integrate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h
Gradient${OBJEXT}: Gradient.cpp Gradient.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Curl${OBJEXT}: Curl.cpp Curl.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Divergence${OBJEXT}: Divergence.cpp Divergence.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Annotate${OBJEXT}: Annotate.cpp ../Graphics/drawContext.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Fltk/Draw.h ../Fltk/GUI.h \
  Annotate.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
Remove${OBJEXT}: Remove.cpp Remove.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h
Probe${OBJEXT}: Probe.cpp ../Graphics/drawContext.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Fltk/Draw.h Probe.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h
HarmonicToTime${OBJEXT}: HarmonicToTime.cpp HarmonicToTime.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h
ModulusPhase${OBJEXT}: ModulusPhase.cpp ModulusPhase.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h
