# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshPlugin${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Graphics ${DASH}I../Geo\
      ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Fltk ${DASH}I../Numeric\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/MathEval\
      ${DASH}I../contrib/gmm

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
        HarmonicToTime.cpp ModulusPhase.cpp\
        FiniteElement.cpp\
        HomologyComputation.cpp

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
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/ListUtils.h
PluginManager${OBJEXT}: PluginManager.cpp ../Common/GmshConfig.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h PluginManager.h CutMap.h \
  Levelset.h CutGrid.h StreamLines.h CutPlane.h CutParametric.h \
  CutSphere.h Skin.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h Extract.h ExtractElements.h ExtractEdges.h \
  HarmonicToTime.h ModulusPhase.h Integrate.h Gradient.h Curl.h \
  Divergence.h Annotate.h Remove.h MakeSimplex.h Smooth.h Transform.h \
  LongitudeLatitude.h Triangulate.h Warp.h SphericalRaise.h \
  Eigenvectors.h Eigenvalues.h Lambda2.h Evaluate.h Probe.h FieldView.h \
  GSHHS.h FiniteElement.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
Levelset${OBJEXT}: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h MakeSimplex.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Post/adaptiveData.h
CutPlane${OBJEXT}: CutPlane.cpp ../Common/GmshConfig.h CutPlane.h Levelset.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h
CutSphere${OBJEXT}: CutSphere.cpp ../Common/GmshConfig.h CutSphere.h Levelset.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h
CutMap${OBJEXT}: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
Smooth${OBJEXT}: Smooth.cpp Smooth.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h
CutParametric${OBJEXT}: CutParametric.cpp ../Common/GmshConfig.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  CutParametric.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h
Lambda2${OBJEXT}: Lambda2.cpp Lambda2.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
Eigenvectors${OBJEXT}: Eigenvectors.cpp Eigenvectors.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Numeric/EigSolve.h
Eigenvalues${OBJEXT}: Eigenvalues.cpp Eigenvalues.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
StreamLines${OBJEXT}: StreamLines.cpp ../Common/GmshConfig.h StreamLines.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Graphics/drawContext.h \
  ../Fltk/Draw.h
CutGrid${OBJEXT}: CutGrid.cpp ../Common/GmshConfig.h ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutGrid.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h
Transform${OBJEXT}: Transform.cpp Transform.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h
LongitudeLatitude${OBJEXT}: LongitudeLatitude.cpp LongitudeLatitude.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Common/OpenFile.h
Triangulate${OBJEXT}: Triangulate.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/discreteFace.h ../Geo/GModel.h \
  ../Geo/GFace.h ../Geo/discreteEdge.h ../Geo/GModel.h ../Geo/GEdge.h \
  ../Geo/discreteVertex.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Mesh/DivideAndConquer.h \
  ../Common/GmshMessage.h Triangulate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Post/PView.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/ListUtils.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
Warp${OBJEXT}: Warp.cpp Warp.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/ListUtils.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
SphericalRaise${OBJEXT}: SphericalRaise.cpp SphericalRaise.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
Skin${OBJEXT}: Skin.cpp Skin.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ../Common/MallocUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GSHHS${OBJEXT}: GSHHS.cpp ../Mesh/Field.h ../Common/GmshConfig.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Post/PView.h ../Geo/SPoint2.h GSHHS.h \
  Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h
Extract${OBJEXT}: Extract.cpp ../Common/GmshConfig.h Extract.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h
ExtractElements${OBJEXT}: ExtractElements.cpp ExtractElements.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
ExtractEdges${OBJEXT}: ExtractEdges.cpp ExtractEdges.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Mesh/BDS.h
MakeSimplex${OBJEXT}: MakeSimplex.cpp MakeSimplex.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h
Evaluate${OBJEXT}: Evaluate.cpp ../Common/GmshConfig.h Evaluate.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h
FieldView${OBJEXT}: FieldView.cpp FieldView.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Mesh/Field.h \
  ../Geo/STensor3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h
Integrate${OBJEXT}: Integrate.cpp Integrate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Post/shapeFunctions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h
Gradient${OBJEXT}: Gradient.cpp Gradient.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Post/shapeFunctions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
Curl${OBJEXT}: Curl.cpp Curl.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshMessage.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/ListUtils.h ../Post/shapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
Divergence${OBJEXT}: Divergence.cpp Divergence.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h ../Post/shapeFunctions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
Annotate${OBJEXT}: Annotate.cpp ../Common/GmshConfig.h Annotate.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h ../Fltk/GUI.h
Remove${OBJEXT}: Remove.cpp Remove.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/ListUtils.h
Probe${OBJEXT}: Probe.cpp ../Common/GmshConfig.h Probe.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Graphics/drawContext.h ../Fltk/Draw.h
HarmonicToTime${OBJEXT}: HarmonicToTime.cpp HarmonicToTime.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h
ModulusPhase${OBJEXT}: ModulusPhase.cpp ModulusPhase.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/GmshMessage.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h
FiniteElement${OBJEXT}: FiniteElement.cpp ../Common/GmshConfig.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h FiniteElement.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/GmshMessage.h ../Post/PView.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Numeric/gmshAssembler.h \
  ../Numeric/gmshLinearSystem.h ../Numeric/gmshProjection.h \
  ../Numeric/gmshTermOfFormulation.h ../Numeric/GmshMatrix.h \
  ../Numeric/gmshFunction.h ../Numeric/gmshAssembler.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Numeric/gmshFunction.h ../Common/Gmsh.h ../Common/GmshMessage.h \
  ../Numeric/GmshMatrix.h ../Numeric/gmshLaplace.h \
  ../Numeric/gmshTermOfFormulation.h ../Numeric/gmshFunction.h \
  ../Numeric/GmshMatrix.h ../Numeric/gmshHelmholtz.h \
  ../Numeric/gmshTermOfFormulation.h ../Numeric/gmshFunction.h \
  ../Numeric/GmshMatrix.h ../Numeric/gmshLinearSystemGmm.h \
  ../Numeric/gmshLinearSystem.h
HomologyComputation${OBJEXT}: HomologyComputation.cpp Plugin.h \
  ../Geo/GModel.h ../Geo/GEntity.h ../Geo/CellComplex.h \
  ../Post/PView.h HomologyComputation.h
