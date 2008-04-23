# $Id: Makefile,v 1.215 2008-04-23 22:38:50 geuzaine Exp $
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

LIB = ../lib/libGmshMesh${LIBEXT}

INC = ${DASH}I../Numeric ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo\
      ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Parser\
      ${DASH}I../Fltk ${DASH}I../contrib/NR ${DASH}I../contrib/Triangle\
      ${DASH}I../contrib/Tetgen ${DASH}I../contrib/Netgen\
      ${DASH}I../contrib/Netgen/libsrc/include\
      ${DASH}I../contrib/Netgen/libsrc/interface\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/Metis\
      ${DASH}I../contrib/MathEval

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Generator.cpp \
      Field.cpp\
        meshGEdge.cpp \
        meshGEdgeExtruded.cpp \
        meshGFace.cpp \
        meshGFaceTransfinite.cpp \
        meshGFaceExtruded.cpp \
        meshGFaceBDS.cpp \
        meshGFaceDelaunayInsertion.cpp \
        meshGFaceOptimize.cpp \
        meshGRegion.cpp \
        meshGRegionDelaunayInsertion.cpp \
        meshGRegionTransfinite.cpp \
        meshGRegionExtruded.cpp \
        meshGRegionCarveHole.cpp \
	meshGRegionLocalMeshMod.cpp\
        DivideAndConquer.cpp \
        BackgroundMesh.cpp \
        qualityMeasures.cpp \
        BoundaryLayer.cpp \
        BDS.cpp \
        HighOrder.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

lib: ${OBJ} 
	${AR} ${ARFLAGS}../lib/libGmsh${LIBEXT} ${OBJ}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

# Don't optimize BDS: it crashes with some flavors of gcc 4.1 (e.g. on debian etch)
BDS.o:
	${CXX} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}c BDS.cpp

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
Generator.o: Generator.cpp ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Context.h ../Post/PView.h \
  ../Post/PViewData.h ../DataStr/List.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Common/OS.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h meshGEdge.h \
  meshGFace.h meshGFaceBDS.h meshGRegion.h BackgroundMesh.h \
  BoundaryLayer.h HighOrder.h
Field.o: Field.cpp ../Common/Context.h Field.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Post/PView.h \
  ../Post/PViewData.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Geo/GeoInterpolation.h ../Geo/Geo.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Common/Message.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Post/PViewDataList.h ../Post/PViewData.h
meshGEdge.o: meshGEdge.cpp meshGEdge.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  BackgroundMesh.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/Message.h ../DataStr/List.h ../Common/Context.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SBoundingBox3d.h
meshGEdgeExtruded.o: meshGEdgeExtruded.cpp ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Common/Message.h
meshGFace.o: meshGFace.cpp meshGFace.h meshGFaceBDS.h \
  meshGFaceDelaunayInsertion.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h meshGFaceOptimize.h DivideAndConquer.h \
  BackgroundMesh.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Common/Context.h ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h BDS.h ../Post/PView.h ../Post/PViewData.h \
  ../DataStr/List.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  qualityMeasures.h Field.h ../Geo/Geo.h ../Geo/gmshSurface.h \
  ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h \
  ../Geo/SVector3.h ../Geo/SBoundingBox3d.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Common/OS.h
meshGFaceTransfinite.o: meshGFaceTransfinite.cpp meshGFace.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Context.h ../Common/Message.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
meshGFaceExtruded.o: meshGFaceExtruded.cpp ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Common/Context.h \
  ../Common/Message.h
meshGFaceBDS.o: meshGFaceBDS.cpp meshGFace.h meshGFaceOptimize.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  meshGFaceDelaunayInsertion.h BackgroundMesh.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Common/Context.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Common/Message.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  BDS.h ../Post/PView.h ../Post/PViewData.h ../DataStr/List.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h qualityMeasures.h Field.h \
  ../Geo/Geo.h ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Common/OS.h
meshGFaceDelaunayInsertion.o: meshGFaceDelaunayInsertion.cpp BDS.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Post/PView.h ../Post/PViewData.h \
  ../DataStr/List.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  BackgroundMesh.h meshGFaceDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h meshGFaceOptimize.h meshGFace.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Message.h \
  ../Common/Context.h
meshGFaceOptimize.o: meshGFaceOptimize.cpp meshGFaceOptimize.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  meshGFaceDelaunayInsertion.h qualityMeasures.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h BackgroundMesh.h
meshGRegion.o: meshGRegion.cpp meshGRegion.h \
  meshGRegionDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h BackgroundMesh.h qualityMeasures.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/gmshRegion.h ../Geo/Geo.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GRegion.h BDS.h ../Post/PView.h \
  ../Post/PViewData.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Common/Message.h ../Common/Context.h
meshGRegionDelaunayInsertion.o: meshGRegionDelaunayInsertion.cpp \
  ../Common/OS.h BackgroundMesh.h meshGRegion.h meshGRegionLocalMeshMod.h \
  meshGRegionDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h qualityMeasures.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SBoundingBox3d.h ../Common/Message.h
meshGRegionTransfinite.o: meshGRegionTransfinite.cpp meshGFace.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Context.h ../Common/Message.h
meshGRegionExtruded.o: meshGRegionExtruded.cpp ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h meshGFace.h meshGRegion.h \
  ../Common/Context.h ../Common/Message.h
meshGRegionCarveHole.o: meshGRegionCarveHole.cpp ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Message.h
meshGRegionLocalMeshMod.o: meshGRegionLocalMeshMod.cpp \
  meshGRegionLocalMeshMod.h meshGRegionDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h BackgroundMesh.h \
  qualityMeasures.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Common/Message.h
DivideAndConquer.o: DivideAndConquer.cpp ../Common/Message.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h DivideAndConquer.h \
  ../DataStr/Malloc.h
BackgroundMesh.o: BackgroundMesh.cpp ../Common/Message.h BackgroundMesh.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h Field.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h
qualityMeasures.o: qualityMeasures.cpp qualityMeasures.h BDS.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Post/PView.h ../Post/PViewData.h \
  ../DataStr/List.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
BoundaryLayer.o: BoundaryLayer.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h BoundaryLayer.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h meshGEdge.h meshGFace.h \
  ../Common/Message.h
BDS.o: BDS.cpp ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h BDS.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Post/PView.h ../Post/PViewData.h \
  ../DataStr/List.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Common/Message.h meshGFaceDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h qualityMeasures.h
HighOrder.o: HighOrder.cpp HighOrder.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  meshGFaceOptimize.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  meshGFaceDelaunayInsertion.h ../Common/Message.h ../Common/OS.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../Common/GmshMatrix.h ../Numeric/FunctionSpace.h
