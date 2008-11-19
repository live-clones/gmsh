# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshGeo${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Numeric ${DASH}I../Parser ${DASH}I../Fltk\
      ${DASH}I../contrib/NR ${DASH}I../contrib/ANN/include\
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
      GaussQuadratureTri.cpp\
      GaussQuadratureQuad.cpp\
      GaussQuadratureTet.cpp\
      GaussQuadratureHex.cpp\
      GaussLegendreSimplex.cpp\
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
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
GEntity.o: GEntity.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GFace.h GEdgeLoop.h GEdge.h \
  SVector3.h Pair.h MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h \
  MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h \
  ../Numeric/GaussLegendre1D.h
GEdgeLoop.o: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  ../Common/GmshMessage.h
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GaussLegendre1D.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
GFaceCompound.o: GFaceCompound.cpp GFaceCompound.h GFace.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h GEdgeLoop.h GEdge.h \
  GVertex.h SPoint2.h SVector3.h Pair.h ../Numeric/gmshAssembler.h \
  ../Numeric/gmshLinearSystem.h ../Numeric/gmshLaplace.h \
  ../Numeric/gmshTermOfFormulation.h ../Common/GmshMatrix.h \
  ../Common/Gmsh.h ../Common/GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Numeric/gmshLinearSystemGmm.h \
  ../Numeric/gmshLinearSystem.h
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h
gmshVertex.o: gmshVertex.cpp GFace.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h SPoint2.h \
  SVector3.h Pair.h gmshVertex.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoInterpolation.h ../Common/GmshMessage.h MVertex.h MElement.h MEdge.h \
  MFace.h ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h
gmshEdge.o: gmshEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h GFaceCompound.h gmshEdge.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h \
  ../Common/GmshMessage.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h gmshFace.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoInterpolation.h ../Common/GmshMessage.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h gmshRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h ../Common/GmshMessage.h
gmshSurface.o: gmshSurface.cpp gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/GmshMessage.h
OCCVertex.o: OCCVertex.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MVertex.h MElement.h \
  ../Common/GmshDefines.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h OCCVertex.h \
  OCCIncludes.h OCCEdge.h OCCFace.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h OCCEdge.h \
  OCCVertex.h OCCIncludes.h OCCFace.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h \
  OCCFace.h ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/VertexArray.h ../Geo/SVector3.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h \
  OCCFace.h OCCRegion.h ../Common/GmshMessage.h
discreteEdge.o: discreteEdge.cpp discreteEdge.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
discreteFace.o: discreteFace.cpp discreteFace.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
discreteRegion.o: discreteRegion.cpp discreteRegion.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
fourierEdge.o: fourierEdge.cpp fourierEdge.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  GModel.h GFace.h GEdgeLoop.h Pair.h GRegion.h fourierVertex.h MVertex.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
fourierFace.o: fourierFace.cpp fourierVertex.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h MVertex.h fourierFace.h \
  fourierEdge.h ../Common/GmshMessage.h
fourierProjectionFace.o: fourierProjectionFace.cpp \
  fourierProjectionFace.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/VertexArray.h ../Geo/SVector3.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h discreteRegion.h \
  discreteFace.h discreteEdge.h discreteVertex.h gmshSurface.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Common/SmoothData.h ../Mesh/Field.h \
  ../Post/PView.h ../Geo/SPoint3.h ../Mesh/Generator.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  ../Common/OpenFile.h ../Common/GmshMessage.h gmshVertex.h gmshFace.h \
  GFaceCompound.h gmshEdge.h gmshRegion.h ../Mesh/Field.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Parser/Parser.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshDefines.h MElement.h \
  MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h discreteRegion.h \
  discreteFace.h ../Common/StringUtils.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModelIO_OCC.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h OCCIncludes.h \
  ../Common/GmshMessage.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h OCCVertex.h OCCEdge.h OCCFace.h OCCRegion.h \
  MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h ../Common/OpenFile.h
GModelIO_Fourier.o: GModelIO_Fourier.cpp GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h \
  fourierVertex.h MVertex.h fourierEdge.h fourierFace.h \
  GModelIO_Fourier.h
GModelIO_CGNS.o: GModelIO_CGNS.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h \
  CGNSOptions.h
GModelIO_MED.o: GModelIO_MED.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshMessage.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/GmshMessage.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
Geo.o: Geo.cpp ../Common/GmshMessage.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/MallocUtils.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GModel.h GVertex.h GEntity.h \
  GPoint.h GEdge.h GFace.h GEdgeLoop.h GRegion.h GeoInterpolation.h \
  ../Mesh/Field.h ../Post/PView.h ../Geo/SPoint3.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
GeoStringInterface.o: GeoStringInterface.cpp ../Common/GmshMessage.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/StringUtils.h Geo.h ../Common/GmshDefines.h gmshSurface.h \
  Pair.h Range.h SPoint2.h SPoint3.h SVector3.h SBoundingBox3d.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoStringInterface.h ../Common/OpenFile.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h GModel.h GVertex.h \
  GEntity.h GPoint.h GEdge.h GFace.h GEdgeLoop.h GRegion.h \
  ../Parser/Parser.h
GeoInterpolation.o: GeoInterpolation.cpp ../Common/GmshMessage.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h \
  GeoStringInterface.h
findLinks.o: findLinks.cpp ../Common/GmshMessage.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h
MVertex.o: MVertex.cpp MVertex.h SPoint2.h SPoint3.h GVertex.h GEntity.h \
  Range.h SBoundingBox3d.h GPoint.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GFaceCompound.h ../Common/GmshMessage.h \
  ../Common/StringUtils.h
GaussQuadratureTri.o: GaussQuadratureTri.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h GaussLegendreSimplex.h
GaussQuadratureQuad.o: GaussQuadratureQuad.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h GaussLegendreSimplex.h \
  ../Numeric/GaussLegendre1D.h
GaussQuadratureTet.o: GaussQuadratureTet.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h GaussLegendreSimplex.h
GaussQuadratureHex.o: GaussQuadratureHex.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h GaussLegendreSimplex.h \
  ../Numeric/GaussLegendre1D.h
GaussLegendreSimplex.o: GaussLegendreSimplex.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Common/GmshMatrix.h GaussLegendreSimplex.h \
  ../Numeric/GaussLegendre1D.h
MFace.o: MFace.cpp MFace.h MVertex.h SPoint2.h SPoint3.h SVector3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint2.h SPoint3.h MEdge.h SVector3.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h GEntity.h Range.h \
  SBoundingBox3d.h GFace.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h Pair.h \
  ../Common/StringUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GaussLegendre1D.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Mesh/qualityMeasures.h ../Mesh/meshGFaceDelaunayInsertion.h \
  ../Geo/MElement.h ../Mesh/meshGRegionDelaunayInsertion.h \
  ../Mesh/BackgroundMesh.h ../Mesh/qualityMeasures.h
MZone.o: MZone.cpp
MZoneBoundary.o: MZoneBoundary.cpp
