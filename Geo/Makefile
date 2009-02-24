# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshGeo${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../contrib/ANN/include\
      ${DASH}I../contrib/MathEval ${DASH}I../contrib/gmm

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GFaceCompound.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
      discreteEdge.cpp discreteFace.cpp discreteRegion.cpp\
      fourierEdge.cpp fourierFace.cpp fourierProjectionFace.cpp\
      GModel.cpp\
      GModelIO_Geo.cpp\
      GModelIO_Mesh.cpp\
      GModelIO_OCC.cpp\
      GModelIO_Fourier.cpp\
      GModelIO_CGNS.cpp\
      GModelIO_MED.cpp\
      ExtrudeParams.cpp \
      Geo.cpp \
      GeoStringInterface.cpp GeoInterpolation.cpp\
      findLinks.cpp\
      MVertex.cpp\
      MFace.cpp\
      MElement.cpp\
      MZone.cpp MZoneBoundary.cpp

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
GEntity${OBJEXT}: GEntity.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Common/VertexArray.h \
  ../Geo/SVector3.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
GVertex${OBJEXT}: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GFace.h GEdgeLoop.h GEdge.h \
  SVector3.h Pair.h MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h \
  MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h
GEdge${OBJEXT}: GEdge.cpp ../Common/GmshConfig.h ../Common/GmshDefines.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Numeric/GaussLegendre1D.h
GEdgeLoop${OBJEXT}: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  ../Common/GmshMessage.h
GFace${OBJEXT}: GFace.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Numeric/GaussLegendre1D.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GFaceCompound${OBJEXT}: GFaceCompound.cpp ../Common/GmshConfig.h GFaceCompound.h \
  GFace.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h \
  GEdgeLoop.h GEdge.h GVertex.h SPoint2.h SVector3.h Pair.h \
  ../Numeric/gmshAssembler.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/gmshLaplace.h ../Numeric/gmshTermOfFormulation.h \
  ../Numeric/GmshMatrix.h ../Common/GmshMessage.h \
  ../Numeric/gmshFunction.h ../Numeric/gmshAssembler.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Numeric/gmshFunction.h ../Common/Gmsh.h ../Common/GmshMessage.h \
  ../Numeric/GmshMatrix.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Numeric/gmshLinearSystemGmm.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/gmshLinearSystemFull.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/GmshMatrix.h
GRegion${OBJEXT}: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h
gmshVertex${OBJEXT}: gmshVertex.cpp GFace.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h SPoint2.h \
  SVector3.h Pair.h gmshVertex.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h MVertex.h \
  MElement.h MEdge.h MFace.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h
gmshEdge${OBJEXT}: gmshEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h GFaceCompound.h gmshEdge.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoInterpolation.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
gmshFace${OBJEXT}: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h gmshFace.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
gmshRegion${OBJEXT}: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h gmshRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h
gmshSurface${OBJEXT}: gmshSurface.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h
OCCVertex${OBJEXT}: OCCVertex.cpp ../Common/GmshConfig.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h MVertex.h MElement.h \
  ../Common/GmshDefines.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h
OCCEdge${OBJEXT}: OCCEdge.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCEdge.h OCCVertex.h OCCIncludes.h OCCFace.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
OCCFace${OBJEXT}: OCCFace.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/VertexArray.h \
  ../Geo/SVector3.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
OCCRegion${OBJEXT}: OCCRegion.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h OCCRegion.h
discreteEdge${OBJEXT}: discreteEdge.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h discreteEdge.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ExtrudeParams.h \
  ../Common/SmoothData.h
discreteFace${OBJEXT}: discreteFace.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h discreteFace.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ExtrudeParams.h \
  ../Common/SmoothData.h
discreteRegion${OBJEXT}: discreteRegion.cpp ../Common/GmshConfig.h \
  discreteRegion.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ExtrudeParams.h \
  ../Common/SmoothData.h
fourierEdge${OBJEXT}: fourierEdge.cpp ../Common/GmshConfig.h fourierEdge.h \
  GEdge.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h \
  SPoint2.h SVector3.h GModel.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  fourierVertex.h MVertex.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
fourierFace${OBJEXT}: fourierFace.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h fourierVertex.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h MVertex.h fourierFace.h \
  fourierEdge.h
fourierProjectionFace${OBJEXT}: fourierProjectionFace.cpp ../Common/GmshConfig.h \
  fourierProjectionFace.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/VertexArray.h ../Geo/SVector3.h
GModel${OBJEXT}: GModel.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  discreteRegion.h discreteFace.h discreteEdge.h discreteVertex.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/Octree.h ../Common/OctreeInternals.h ../Common/SmoothData.h \
  ../Mesh/Field.h ../Post/PView.h ../Geo/SPoint3.h ../Mesh/Generator.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GModelIO_Geo${OBJEXT}: GModelIO_Geo.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  ../Common/OpenFile.h gmshVertex.h gmshFace.h GFaceCompound.h gmshEdge.h \
  gmshRegion.h ../Mesh/Field.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Parser/Parser.h
GModelIO_Mesh${OBJEXT}: GModelIO_Mesh.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshDefines.h MElement.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h discreteRegion.h \
  discreteFace.h ../Common/StringUtils.h
GModelIO_OCC${OBJEXT}: GModelIO_OCC.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModelIO_OCC.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h OCCIncludes.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  OCCVertex.h OCCEdge.h OCCFace.h OCCRegion.h MElement.h \
  ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/OpenFile.h
GModelIO_Fourier${OBJEXT}: GModelIO_Fourier.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h fourierVertex.h MVertex.h fourierEdge.h \
  fourierFace.h GModelIO_Fourier.h
GModelIO_CGNS${OBJEXT}: GModelIO_CGNS.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h CGNSOptions.h
GModelIO_MED${OBJEXT}: GModelIO_MED.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h
ExtrudeParams${OBJEXT}: ExtrudeParams.cpp ../Common/GmshMessage.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
Geo${OBJEXT}: Geo.cpp ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/MallocUtils.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GModel.h GVertex.h GEntity.h \
  GPoint.h GEdge.h GFace.h GEdgeLoop.h GRegion.h GeoInterpolation.h \
  ../Mesh/Field.h ../Post/PView.h ../Geo/SPoint3.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GeoStringInterface${OBJEXT}: GeoStringInterface.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/StringUtils.h Geo.h ../Common/GmshDefines.h gmshSurface.h \
  Pair.h Range.h SPoint2.h SPoint3.h SVector3.h SBoundingBox3d.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoStringInterface.h ../Common/OpenFile.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h GModel.h GVertex.h \
  GEntity.h GPoint.h GEdge.h GFace.h GEdgeLoop.h GRegion.h \
  ../Parser/Parser.h
GeoInterpolation${OBJEXT}: GeoInterpolation.cpp ../Common/GmshMessage.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h \
  GeoStringInterface.h
findLinks${OBJEXT}: findLinks.cpp ../Common/GmshMessage.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h
MVertex${OBJEXT}: MVertex.cpp MVertex.h SPoint2.h SPoint3.h GVertex.h GEntity.h \
  Range.h SBoundingBox3d.h GPoint.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GFaceCompound.h ../Common/GmshMessage.h \
  ../Common/StringUtils.h
MFace${OBJEXT}: MFace.cpp ../Common/GmshConfig.h MFace.h MVertex.h SPoint2.h \
  SPoint3.h SVector3.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
MElement${OBJEXT}: MElement.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  MElement.h ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h \
  MEdge.h SVector3.h MFace.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h GEntity.h Range.h \
  SBoundingBox3d.h GFace.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h Pair.h \
  ../Common/StringUtils.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Numeric/GaussLegendre1D.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Mesh/qualityMeasures.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Geo/MElement.h \
  ../Mesh/meshGRegionDelaunayInsertion.h ../Mesh/BackgroundMesh.h \
  ../Mesh/qualityMeasures.h
MZone${OBJEXT}: MZone.cpp ../Common/GmshConfig.h
MZoneBoundary${OBJEXT}: MZoneBoundary.cpp ../Common/GmshConfig.h
