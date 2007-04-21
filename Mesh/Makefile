# $Id: Makefile,v 1.171 2007-04-21 20:20:57 geuzaine Exp $
#
# Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

LIB     = ../lib/libGmshMesh.a
INCLUDE = -I../Numeric -I../Common -I../DataStr -I../Geo -I../Mesh\
          -I../Graphics -I../Parser -I../Fltk\
          -I../contrib/NR -I../contrib/Triangle -I../contrib/Tetgen\
          -I../contrib/Netgen -I../contrib/Netgen/libsrc/include\
          -I../contrib/Netgen/libsrc/interface -I../contrib/ANN/include\
          -I../contrib/Metis -I../contrib/MathEval
CFLAGS  =  ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Generator.cpp \
      Field.cpp\
        meshGEdge.cpp \
        meshGEdgeExtruded.cpp \
        meshGFace.cpp \
        meshGFaceTransfinite.cpp \
        meshGFaceExtruded.cpp \
        meshGFaceDelaunayInsertion.cpp \
        meshGRegion.cpp \
        meshGRegionDelaunayInsertion.cpp \
        meshGRegionTransfinite.cpp \
        meshGRegionExtruded.cpp \
        DivideAndConquer.cpp \
        BackgroundMesh.cpp \
        BoundaryLayer.cpp \
        BDS.cpp \
        HighOrder.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

# Don't optimize BDS: it crashes with some flavors of gcc 4.1 (e.g. on debian etch)
BDS.o:
	${CXX} ${FLAGS} ${INCLUDE} -c $<

clean:
	rm -f *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Generator.o: Generator.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Common/Context.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/OS.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/ExtrudeParams.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  meshGEdge.h meshGFace.h meshGRegion.h BackgroundMesh.h BoundaryLayer.h \
  HighOrder.h
Field.o: Field.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Field.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Context.h \
  ../Geo/ExtrudeParams.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Geo/GeoInterpolation.h ../Geo/Geo.h
meshGEdge.o: meshGEdge.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  meshGEdge.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Geo/MRep.h ../Geo/GEdge.h ../Geo/GFace.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/ExtrudeParams.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MElement.h ../Common/VertexArray.h ../Common/OS.h \
  BackgroundMesh.h
meshGEdgeExtruded.o: meshGEdgeExtruded.cpp ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Context.h ../DataStr/List.h ../Geo/ExtrudeParams.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  ../Common/Message.h
meshGFace.o: meshGFace.cpp meshGFace.h meshGFaceDelaunayInsertion.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h DivideAndConquer.h BackgroundMesh.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/MVertex.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/MRep.h ../Geo/GEdge.h \
  ../Geo/GFace.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/ExtrudeParams.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MElement.h ../Common/VertexArray.h ../Common/Message.h \
  ../Common/OS.h BDS.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
meshGFaceTransfinite.o: meshGFaceTransfinite.cpp meshGFace.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Common/Message.h
meshGFaceExtruded.o: meshGFaceExtruded.cpp ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Context.h ../DataStr/List.h ../Geo/ExtrudeParams.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  ../Common/Message.h
meshGFaceDelaunayInsertion.o: meshGFaceDelaunayInsertion.cpp BDS.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/MElement.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  BackgroundMesh.h meshGFaceDelaunayInsertion.h ../Common/Message.h
meshGRegion.o: meshGRegion.cpp meshGRegion.h \
  meshGRegionDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/MVertex.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h ../Geo/gmshRegion.h ../Geo/Geo.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SBoundingBox3d.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/MRep.h ../Geo/GEdge.h \
  ../Geo/GFace.h ../Geo/GRegion.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MElement.h ../Common/VertexArray.h ../Common/Message.h \
  ../Common/OS.h BDS.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
meshGRegionDelaunayInsertion.o: meshGRegionDelaunayInsertion.cpp \
  BackgroundMesh.h meshGRegionDelaunayInsertion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/MVertex.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h ../Common/Message.h
meshGRegionTransfinite.o: meshGRegionTransfinite.cpp meshGFace.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/MElement.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/ExtrudeParams.h ../Common/Message.h
meshGRegionExtruded.o: meshGRegionExtruded.cpp ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Context.h ../DataStr/List.h ../Geo/ExtrudeParams.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  meshGFace.h meshGRegion.h ../Common/Message.h
DivideAndConquer.o: DivideAndConquer.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h DivideAndConquer.h
BackgroundMesh.o: BackgroundMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h BackgroundMesh.h ../Common/Context.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h Field.h ../Geo/Geo.h ../Geo/gmshSurface.h \
  ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h \
  ../Geo/SVector3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h
BoundaryLayer.o: BoundaryLayer.cpp BoundaryLayer.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  meshGEdge.h meshGFace.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
BDS.o: BDS.cpp ../Numeric/Numeric.h ../Common/GmshMatrix.h BDS.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/GmshDefines.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Context.h ../DataStr/List.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Message.h
HighOrder.o: HighOrder.cpp HighOrder.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  ../Geo/MRep.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MElement.h \
  ../Common/VertexArray.h ../Common/Message.h ../Common/OS.h
