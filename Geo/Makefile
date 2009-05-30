# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshGeo${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../contrib/ANN/include\
      ${DASH}I../contrib/kbipack\
      ${DASH}I../contrib/MathEval ${DASH}I../contrib/gmm

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = GEntity.cpp\
        GVertex.cpp GEdge.cpp GFace.cpp GRegion.cpp\
        GEdgeLoop.cpp GEdgeCompound.cpp GFaceCompound.cpp GRegionCompound.cpp\
        gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
        OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
        discreteEdge.cpp discreteFace.cpp discreteRegion.cpp\
        fourierEdge.cpp fourierFace.cpp fourierProjectionFace.cpp\
      GModel.cpp\
        GModelIO_Geo.cpp\
        GModelIO_Mesh.cpp\
        GModelIO_OCC.cpp\
          OCC_Connect.cpp\
        GModelIO_Fourier.cpp\
        GModelIO_CGNS.cpp\
        GModelIO_MED.cpp\
      ExtrudeParams.cpp\
      Geo.cpp\
      GeoStringInterface.cpp GeoInterpolation.cpp\
      findLinks.cpp\
      MVertex.cpp\
      MFace.cpp\
      MElement.cpp\
        MLine.cpp MTriangle.cpp MQuadrangle.cpp MTetrahedron.cpp\
        MHexahedron.cpp MPrism.cpp MPyramid.cpp\
      MZone.cpp MZoneBoundary.cpp\
      CellComplex.cpp\
      ChainComplex.cpp\
      STensor3.cpp


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
  SVector3.h Pair.h MPoint.h MElement.h ../Common/GmshDefines.h MVertex.h \
  MEdge.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h
GEdge${OBJEXT}: GEdge.cpp ../Common/GmshConfig.h ../Common/GmshDefines.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MLine.h MElement.h MVertex.h MEdge.h \
  MFace.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/GaussLegendre1D.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GFace${OBJEXT}: GFace.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h MTriangle.h MElement.h ../Common/GmshDefines.h MVertex.h \
  MEdge.h MFace.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h MQuadrangle.h ../Common/VertexArray.h \
  ../Geo/SVector3.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Numeric/EigSolve.h ../Numeric/GaussLegendre1D.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GRegion${OBJEXT}: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MTetrahedron.h MElement.h \
  ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  MHexahedron.h MPrism.h MPyramid.h
GEdgeLoop${OBJEXT}: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  ../Common/GmshMessage.h
GEdgeCompound${OBJEXT}: GEdgeCompound.cpp ../Common/GmshConfig.h GEdgeCompound.h \
  GFace.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h \
  GEdgeLoop.h GEdge.h GVertex.h SPoint2.h SVector3.h Pair.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshMessage.h
GFaceCompound${OBJEXT}: GFaceCompound.cpp ../Common/GmshConfig.h GFaceCompound.h \
  GFace.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h \
  GEdgeLoop.h GEdge.h GVertex.h SPoint2.h SVector3.h Pair.h \
  GEdgeCompound.h MLine.h MElement.h ../Common/GmshDefines.h MVertex.h \
  MEdge.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h MTriangle.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Numeric/gmshAssembler.h \
  ../Numeric/gmshLinearSystem.h ../Numeric/gmshLaplace.h \
  ../Numeric/gmshTermOfFormulation.h ../Numeric/GmshMatrix.h \
  ../Numeric/gmshFunction.h ../Numeric/gmshAssembler.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Numeric/gmshFunction.h ../Common/Gmsh.h \
  ../Common/GmshMessage.h ../Numeric/GmshMatrix.h \
  ../Numeric/gmshLinearSystemGmm.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/gmshLinearSystemFull.h ../Numeric/gmshLinearSystem.h \
  ../Numeric/GmshMatrix.h
GRegionCompound${OBJEXT}: GRegionCompound.cpp ../Common/GmshConfig.h \
  GRegionCompound.h GRegion.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GFace.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h \
  SPoint2.h SVector3.h Pair.h GFaceCompound.h GEdgeCompound.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/GmshMessage.h
gmshVertex${OBJEXT}: gmshVertex.cpp GFace.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h SPoint2.h \
  SVector3.h Pair.h gmshVertex.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h GeoInterpolation.h MVertex.h \
  MPoint.h MElement.h MEdge.h MFace.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h
gmshEdge${OBJEXT}: gmshEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h GFaceCompound.h GEdgeCompound.h gmshEdge.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
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
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h MVertex.h MPoint.h \
  MElement.h ../Common/GmshDefines.h MEdge.h MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h OCCVertex.h OCCIncludes.h \
  OCCEdge.h OCCFace.h
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
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h discreteVertex.h \
  MVertex.h MLine.h MElement.h ../Common/GmshDefines.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h MPoint.h MTriangle.h \
  MQuadrangle.h MPrism.h MTetrahedron.h MHexahedron.h MPyramid.h Geo.h \
  gmshSurface.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ExtrudeParams.h \
  ../Common/SmoothData.h
discreteFace${OBJEXT}: discreteFace.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h discreteFace.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h discreteEdge.h \
  discreteVertex.h MVertex.h MEdge.h MTriangle.h MElement.h \
  ../Common/GmshDefines.h MFace.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h Geo.h gmshSurface.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ExtrudeParams.h ../Common/SmoothData.h
discreteRegion${OBJEXT}: discreteRegion.cpp ../Common/GmshConfig.h \
  discreteRegion.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MVertex.h Geo.h ../Common/GmshDefines.h \
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
  ../Common/GmshMessage.h fourierProjectionFace.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/VertexArray.h \
  ../Geo/SVector3.h
GModel${OBJEXT}: GModel.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h MPoint.h MElement.h ../Common/GmshDefines.h MVertex.h MEdge.h \
  MFace.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h MLine.h MTriangle.h MQuadrangle.h MTetrahedron.h \
  MHexahedron.h MPrism.h MPyramid.h discreteRegion.h discreteFace.h \
  discreteEdge.h discreteVertex.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Common/SmoothData.h ../Mesh/Field.h ../Geo/STensor3.h \
  ../Geo/SVector3.h ../Post/PView.h ../Geo/SPoint3.h ../Mesh/Generator.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
GModelIO_Geo${OBJEXT}: GModelIO_Geo.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/GmshMatrix.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ExtrudeParams.h ../Common/SmoothData.h \
  ../Common/OpenFile.h gmshVertex.h gmshFace.h GFaceCompound.h \
  GEdgeCompound.h GRegionCompound.h gmshEdge.h gmshRegion.h \
  ../Mesh/Field.h ../Geo/STensor3.h ../Geo/SVector3.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Parser/Parser.h
GModelIO_Mesh${OBJEXT}: GModelIO_Mesh.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshDefines.h MPoint.h \
  MElement.h MVertex.h MEdge.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h MLine.h MTriangle.h \
  MQuadrangle.h MTetrahedron.h MHexahedron.h MPrism.h MPyramid.h \
  ../Common/StringUtils.h discreteVertex.h discreteEdge.h discreteFace.h \
  discreteRegion.h GEdgeCompound.h GFaceCompound.h
GModelIO_OCC${OBJEXT}: GModelIO_OCC.cpp ../Common/GmshConfig.h \
  ../Common/GmshMessage.h GModelIO_OCC.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h OCCIncludes.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  OCCVertex.h OCCEdge.h OCCFace.h OCCRegion.h MElement.h \
  ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  MLine.h ../Common/OpenFile.h OCC_Connect.h
OCC_Connect${OBJEXT}: OCC_Connect.cpp OCC_Connect.h ../Common/GmshConfig.h
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
  ../Mesh/Field.h ../Geo/STensor3.h ../Geo/SVector3.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
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
  GeoStringInterface.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
findLinks${OBJEXT}: findLinks.cpp ../Common/GmshMessage.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h
MVertex${OBJEXT}: MVertex.cpp MVertex.h SPoint2.h SPoint3.h GVertex.h GEntity.h \
  Range.h SBoundingBox3d.h GPoint.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GFaceCompound.h GEdgeCompound.h \
  ../Common/GmshMessage.h ../Common/StringUtils.h
MFace${OBJEXT}: MFace.cpp ../Common/GmshConfig.h MFace.h MVertex.h SPoint2.h \
  SPoint3.h MEdge.h SVector3.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/GmshMessage.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h
MElement${OBJEXT}: MElement.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  MElement.h ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h \
  MEdge.h SVector3.h MFace.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Numeric/Gauss.h MPoint.h MLine.h MTriangle.h \
  MQuadrangle.h MTetrahedron.h MHexahedron.h MPrism.h MPyramid.h \
  GEntity.h Range.h SBoundingBox3d.h GFace.h GPoint.h GEdgeLoop.h GEdge.h \
  GVertex.h Pair.h ../Common/StringUtils.h ../Numeric/Numeric.h \
  ../Numeric/GmshMatrix.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h
MLine${OBJEXT}: MLine.cpp MLine.h MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint2.h SPoint3.h MEdge.h SVector3.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Common/GmshConfig.h ../Numeric/Gauss.h ../Numeric/GaussLegendre1D.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Mesh/qualityMeasures.h
MTriangle${OBJEXT}: MTriangle.cpp MTriangle.h MElement.h ../Common/GmshDefines.h \
  MVertex.h SPoint2.h SPoint3.h MEdge.h SVector3.h MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Mesh/qualityMeasures.h
MQuadrangle${OBJEXT}: MQuadrangle.cpp MQuadrangle.h MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/GaussLegendre1D.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/meshPartitionOptions.h ../Mesh/qualityMeasures.h
MTetrahedron${OBJEXT}: MTetrahedron.cpp MTetrahedron.h MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/meshPartitionOptions.h \
  ../Mesh/qualityMeasures.h ../Mesh/meshGFaceDelaunayInsertion.h \
  ../Geo/MTriangle.h ../Geo/MElement.h \
  ../Mesh/meshGRegionDelaunayInsertion.h ../Geo/MTetrahedron.h \
  ../Mesh/BackgroundMesh.h ../Geo/STensor3.h ../Geo/SVector3.h \
  ../Mesh/qualityMeasures.h
MHexahedron${OBJEXT}: MHexahedron.cpp MHexahedron.h MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h MEdge.h \
  SVector3.h MFace.h ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
MPrism${OBJEXT}: MPrism.cpp MPrism.h MElement.h ../Common/GmshDefines.h \
  MVertex.h SPoint2.h SPoint3.h MEdge.h SVector3.h MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
MPyramid${OBJEXT}: MPyramid.cpp MPyramid.h MElement.h ../Common/GmshDefines.h \
  MVertex.h SPoint2.h SPoint3.h MEdge.h SVector3.h MFace.h \
  ../Common/GmshMessage.h ../Numeric/FunctionSpace.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
MZone${OBJEXT}: MZone.cpp ../Common/GmshConfig.h
MZoneBoundary${OBJEXT}: MZoneBoundary.cpp ../Common/GmshConfig.h
CellComplex${OBJEXT}: CellComplex.cpp CellComplex.h ../Common/GmshConfig.h \
  MElement.h ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h \
  MEdge.h SVector3.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  GModel.h GVertex.h GEntity.h Range.h SBoundingBox3d.h GPoint.h GEdge.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h
ChainComplex${OBJEXT}: ChainComplex.cpp ChainComplex.h ../Common/GmshConfig.h \
  MElement.h ../Common/GmshDefines.h MVertex.h SPoint2.h SPoint3.h \
  MEdge.h SVector3.h MFace.h ../Common/GmshMessage.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  GModel.h GVertex.h GEntity.h Range.h SBoundingBox3d.h GPoint.h GEdge.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h CellComplex.h
STensor3${OBJEXT}: STensor3.cpp STensor3.h SVector3.h SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  ../Numeric/Numeric.h ../Numeric/GmshMatrix.h
