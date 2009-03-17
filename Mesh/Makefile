# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshMesh${LIBEXT}

INC = ${DASH}I../Numeric ${DASH}I../Common ${DASH}I../Geo\
      ${DASH}I../Mesh ${DASH}I../Post\
      ${DASH}I../contrib/Tetgen ${DASH}I../contrib/Netgen\
      ${DASH}I../contrib/Netgen/libsrc/include\
      ${DASH}I../contrib/Netgen/libsrc/interface\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/Metis\
      ${DASH}I../contrib/MathEval ${DASH}I../contrib/gmm


CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Generator.cpp \
      Field.cpp\
        gmshSmoothHighOrder.cpp \
        meshGEdge.cpp \
        meshGEdgeExtruded.cpp \
        meshGFace.cpp \
        meshGFaceTransfinite.cpp \
        meshGFaceExtruded.cpp \
        meshGFaceBDS.cpp \
        meshGFaceDelaunayInsertion.cpp \
        meshGFaceOptimize.cpp \
        meshGFaceQuadrilateralize.cpp \
        meshGRegion.cpp \
        meshGRegionDelaunayInsertion.cpp \
        meshGRegionTransfinite.cpp \
        meshGRegionExtruded.cpp \
        meshGRegionCarveHole.cpp \
	meshGRegionLocalMeshMod.cpp\
        DivideAndConquer.cpp \
        BackgroundMesh.cpp \
        qualityMeasures.cpp \
        BoundaryLayers.cpp \
        BDS.cpp \
        HighOrder.cpp \
	meshPartition.cpp \
        meshRefine.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

# Don't optimize BDS: it crashes with some flavors of gcc 4.1 (e.g. on debian etch)
BDS.o:
	${CXX} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}c BDS.cpp

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
Generator${OBJEXT}: Generator.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h ../Common/OS.h \
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
  ../Numeric/Gauss.h meshGEdge.h meshGFace.h meshGFaceBDS.h meshGRegion.h \
  BackgroundMesh.h BoundaryLayers.h HighOrder.h Generator.h \
  ../Post/PView.h ../Post/PViewData.h
Field${OBJEXT}: Field.cpp ../Common/GmshConfig.h \
  ../contrib/ANN/include/ANN/ANN.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h Field.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Geo/GeoInterpolation.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshMessage.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h
gmshSmoothHighOrder${OBJEXT}: gmshSmoothHighOrder.cpp HighOrder.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h meshGFaceOptimize.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  meshGFaceDelaunayInsertion.h gmshSmoothHighOrder.h \
  ../Numeric/gmshAssembler.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/gmshLaplace.h ../Numeric/gmshTermOfFormulation.h \
  ../Numeric/GmshMatrix.h ../Numeric/gmshFunction.h \
  ../Numeric/gmshAssembler.h ../Numeric/gmshFunction.h ../Common/Gmsh.h \
  ../Common/GmshMessage.h ../Numeric/GmshMatrix.h \
  ../Numeric/gmshElasticity.h ../Numeric/gmshTermOfFormulation.h \
  ../Numeric/GmshMatrix.h ../Numeric/gmshLinearSystemGmm.h \
  ../Numeric/gmshLinearSystem.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
meshGEdge${OBJEXT}: meshGEdge.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h meshGEdge.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  BackgroundMesh.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshGEdgeExtruded${OBJEXT}: meshGEdgeExtruded.cpp ../Geo/GModel.h \
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
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h
meshGFace${OBJEXT}: meshGFace.cpp meshGFace.h meshGFaceBDS.h \
  meshGFaceDelaunayInsertion.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h meshGFaceQuadrilateralize.h \
  meshGFaceOptimize.h DivideAndConquer.h BackgroundMesh.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h BDS.h qualityMeasures.h \
  Field.h ../Post/PView.h ../Common/OS.h HighOrder.h
meshGFaceTransfinite${OBJEXT}: meshGFaceTransfinite.cpp meshGFace.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
meshGFaceExtruded${OBJEXT}: meshGFaceExtruded.cpp ../Geo/GModel.h \
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
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshGFaceBDS${OBJEXT}: meshGFaceBDS.cpp ../Common/GmshMessage.h \
  ../Numeric/GmshPredicates.h meshGFace.h meshGFaceOptimize.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h meshGFaceDelaunayInsertion.h \
  BackgroundMesh.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  BDS.h qualityMeasures.h Field.h ../Post/PView.h ../Common/OS.h
meshGFaceDelaunayInsertion${OBJEXT}: meshGFaceDelaunayInsertion.cpp \
  ../Common/GmshMessage.h ../Numeric/GmshPredicates.h BackgroundMesh.h \
  meshGFaceDelaunayInsertion.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  meshGFaceOptimize.h meshGFace.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
meshGFaceOptimize${OBJEXT}: meshGFaceOptimize.cpp meshGFaceOptimize.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  meshGFaceDelaunayInsertion.h qualityMeasures.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h BackgroundMesh.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h Generator.h
meshGFaceQuadrilateralize${OBJEXT}: meshGFaceQuadrilateralize.cpp \
  meshGFaceQuadrilateralize.h ../Common/GmshMessage.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h meshGFaceDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  meshGFaceOptimize.h meshGFaceBDS.h BDS.h
meshGRegion${OBJEXT}: meshGRegion.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h meshGRegion.h meshGRegionDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  BackgroundMesh.h qualityMeasures.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/gmshRegion.h ../Geo/Geo.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GRegion.h BDS.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshGRegionDelaunayInsertion${OBJEXT}: meshGRegionDelaunayInsertion.cpp \
  ../Common/GmshMessage.h ../Numeric/GmshPredicates.h ../Common/OS.h \
  BackgroundMesh.h meshGRegion.h meshGRegionLocalMeshMod.h \
  meshGRegionDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h qualityMeasures.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h
meshGRegionTransfinite${OBJEXT}: meshGRegionTransfinite.cpp meshGFace.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshGRegionExtruded${OBJEXT}: meshGRegionExtruded.cpp ../Geo/GModel.h \
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
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h meshGFace.h meshGRegion.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshGRegionCarveHole${OBJEXT}: meshGRegionCarveHole.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Geo/GModel.h ../Geo/GVertex.h \
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
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../contrib/ANN/include/ANN/ANN.h
meshGRegionLocalMeshMod${OBJEXT}: meshGRegionLocalMeshMod.cpp \
  meshGRegionLocalMeshMod.h meshGRegionDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h BackgroundMesh.h \
  qualityMeasures.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GRegion.h \
  ../Geo/GEntity.h
DivideAndConquer${OBJEXT}: DivideAndConquer.cpp ../Common/GmshMessage.h \
  ../Numeric/GmshPredicates.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h DivideAndConquer.h \
  ../Common/MallocUtils.h
BackgroundMesh${OBJEXT}: BackgroundMesh.cpp ../Common/GmshMessage.h \
  BackgroundMesh.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h Field.h ../Post/PView.h
qualityMeasures${OBJEXT}: qualityMeasures.cpp qualityMeasures.h BDS.h \
  ../Common/GmshMessage.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
BoundaryLayers${OBJEXT}: BoundaryLayers.cpp ../Geo/GModel.h ../Geo/GVertex.h \
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
  ../Geo/SVector3.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  BoundaryLayers.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  meshGEdge.h meshGFace.h
BDS${OBJEXT}: BDS.cpp ../Common/GmshMessage.h ../Numeric/GmshPredicates.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshConfig.h \
  BDS.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h meshGFaceDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  qualityMeasures.h
HighOrder${OBJEXT}: HighOrder.cpp HighOrder.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  gmshSmoothHighOrder.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Common/OS.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
meshPartition${OBJEXT}: meshPartition.cpp ../Common/GmshConfig.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h meshPartition.h meshPartitionObjects.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h meshPartitionOptions.h
meshRefine${OBJEXT}: meshRefine.cpp HighOrder.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Common/OS.h
