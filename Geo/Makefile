# $Id: Makefile,v 1.202 2008-04-23 08:20:40 geuzaine Exp $
#
# Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshGeo${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Numeric ${DASH}I../Parser ${DASH}I../Fltk\
      ${DASH}I../contrib/NR ${DASH}I../contrib/ANN/include\
      ${DASH}I../contrib/MathEval

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
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
      MElement.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	rm -f *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
GEntity.o: GEntity.cpp GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/Context.h
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GFace.h GEdgeLoop.h GEdge.h \
  SVector3.h Pair.h MVertex.h ../Common/Message.h
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/Message.h \
  ../Numeric/GaussLegendre1D.h
GEdgeLoop.o: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  ../Common/Message.h
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GaussLegendre1D.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Common/Context.h
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h ../Common/Message.h
gmshVertex.o: gmshVertex.cpp GFace.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h SPoint2.h \
  SVector3.h Pair.h gmshVertex.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h MVertex.h GeoInterpolation.h ../Common/Message.h
gmshEdge.o: gmshEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h gmshEdge.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h GeoInterpolation.h ../Common/Message.h \
  ../Common/Context.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h gmshFace.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h GeoInterpolation.h ../Common/Message.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h gmshRegion.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ExtrudeParams.h ../Common/SmoothData.h \
  ../Common/Message.h
gmshSurface.o: gmshSurface.cpp gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Message.h
OCCVertex.o: OCCVertex.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCVertex.h OCCIncludes.h MVertex.h \
  OCCEdge.h OCCFace.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/Message.h OCCEdge.h OCCVertex.h \
  OCCIncludes.h MVertex.h OCCFace.h ../Common/Context.h
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCVertex.h OCCIncludes.h MVertex.h \
  OCCEdge.h OCCFace.h ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/VertexArray.h ../Geo/SVector3.h \
  ../Common/Context.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCVertex.h OCCIncludes.h MVertex.h \
  OCCEdge.h OCCFace.h OCCRegion.h ../Common/Message.h
fourierEdge.o: fourierEdge.cpp fourierEdge.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h \
  GModel.h GFace.h GEdgeLoop.h Pair.h GRegion.h fourierVertex.h MVertex.h \
  ../Common/Context.h
fourierFace.o: fourierFace.cpp fourierVertex.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h MVertex.h fourierFace.h \
  fourierEdge.h ../Common/Message.h
fourierProjectionFace.o: fourierProjectionFace.cpp \
  fourierProjectionFace.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/VertexArray.h ../Geo/SVector3.h \
  ../Common/Context.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h MElement.h ../Common/GmshDefines.h \
  MVertex.h MEdge.h MFace.h discreteRegion.h Geo.h gmshSurface.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h discreteFace.h discreteEdge.h discreteVertex.h \
  ../Common/Message.h ../Mesh/Field.h ../Geo/Geo.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Mesh/Generator.h ../Common/Context.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h ../Parser/OpenFile.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/Message.h gmshVertex.h \
  MVertex.h gmshFace.h gmshEdge.h gmshRegion.h ../Parser/Parser.h \
  ../Mesh/Field.h ../Geo/Geo.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Post/PViewOptions.h ../Post/ColorTable.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/GmshDefines.h MElement.h \
  MVertex.h MEdge.h MFace.h discreteRegion.h Geo.h gmshSurface.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h discreteFace.h discreteEdge.h discreteVertex.h \
  ../Common/StringUtils.h ../Common/Message.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModelIO_OCC.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h OCCIncludes.h \
  ../Common/Message.h ../Common/Context.h OCCVertex.h MVertex.h OCCEdge.h \
  OCCFace.h OCCRegion.h
GModelIO_Fourier.o: GModelIO_Fourier.cpp GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/Message.h \
  fourierVertex.h MVertex.h fourierEdge.h fourierFace.h \
  GModelIO_Fourier.h
GModelIO_CGNS.o: GModelIO_CGNS.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/Message.h MElement.h \
  ../Common/GmshDefines.h MVertex.h MEdge.h MFace.h MNeighbour.h \
  MEdgeHash.h ../Common/Hash.h MFaceHash.h
GModelIO_MED.o: GModelIO_MED.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  GFace.h GEdgeLoop.h Pair.h GRegion.h ../Common/Message.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Message.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ExtrudeParams.h ../Common/SmoothData.h
Geo.o: Geo.cpp ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/Malloc.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ExtrudeParams.h \
  ../Common/SmoothData.h GModel.h GVertex.h GEntity.h GPoint.h GEdge.h \
  GFace.h GEdgeLoop.h GRegion.h GeoInterpolation.h ../Parser/Parser.h \
  ../Mesh/Field.h ../Geo/Geo.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Common/Context.h
GeoStringInterface.o: GeoStringInterface.cpp ../Common/Message.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../DataStr/Malloc.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ExtrudeParams.h \
  ../Common/SmoothData.h GeoStringInterface.h ../Parser/Parser.h \
  ../Parser/OpenFile.h ../Common/Context.h GModel.h GVertex.h GEntity.h \
  GPoint.h GEdge.h GFace.h GEdgeLoop.h GRegion.h
GeoInterpolation.o: GeoInterpolation.cpp ../Common/Message.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoInterpolation.h GeoStringInterface.h
findLinks.o: findLinks.cpp ../Common/Message.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h GPoint.h SPoint2.h GEdge.h \
  SVector3.h GFace.h GEdgeLoop.h Pair.h GRegion.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/List.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h
MVertex.o: MVertex.cpp MVertex.h SPoint3.h GEdge.h GEntity.h Range.h \
  SBoundingBox3d.h GVertex.h GPoint.h SPoint2.h SVector3.h GFace.h \
  GEdgeLoop.h Pair.h ../Common/Message.h
GaussQuadratureTri.o: GaussQuadratureTri.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint3.h MEdge.h SVector3.h MFace.h \
  GaussLegendreSimplex.h
GaussQuadratureQuad.o: GaussQuadratureQuad.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint3.h MEdge.h SVector3.h MFace.h \
  GaussLegendreSimplex.h ../Numeric/GaussLegendre1D.h
GaussQuadratureTet.o: GaussQuadratureTet.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint3.h MEdge.h SVector3.h MFace.h \
  GaussLegendreSimplex.h
GaussQuadratureHex.o: GaussQuadratureHex.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint3.h MEdge.h SVector3.h MFace.h \
  GaussLegendreSimplex.h ../Numeric/GaussLegendre1D.h
GaussLegendreSimplex.o: GaussLegendreSimplex.cpp MElement.h \
  ../Common/GmshDefines.h MVertex.h SPoint3.h MEdge.h SVector3.h MFace.h \
  GaussLegendreSimplex.h ../Numeric/GaussLegendre1D.h
MFace.o: MFace.cpp MFace.h MVertex.h SPoint3.h SVector3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h MFace.h GEntity.h Range.h SBoundingBox3d.h \
  GFace.h GPoint.h GEdgeLoop.h GEdge.h GVertex.h SPoint2.h Pair.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Numeric/FunctionSpace.h ../Common/GmshMatrix.h ../Common/Message.h \
  ../Common/Context.h ../Mesh/qualityMeasures.h
