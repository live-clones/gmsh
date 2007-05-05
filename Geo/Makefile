# $Id: Makefile,v 1.145 2007-05-05 10:24:53 geuzaine Exp $
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

LIB     = ../lib/libGmshGeo.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../contrib/NR -I../contrib/FourierModel -I../contrib/ANN/include -I../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
      FEdge.cpp FFace.cpp\
      projectionFace.cpp\
      GModel.cpp\
        GModelIO_Geo.cpp\
        GModelIO_Mesh.cpp\
        GModelIO_OCC.cpp\
        GModelIO_F.cpp\
        GModelIO_CGNS.cpp\
        GModelIO_MED.cpp\
      ExtrudeParams.cpp \
      Geo.cpp \
	GeoStringInterface.cpp GeoInterpolation.cpp\
      findLinks.cpp\
      MVertex.cpp \
      MElement.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

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
GEntity.o: GEntity.cpp GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  ../Common/GmshDefines.h MRep.h GEdge.h GVertex.h MVertex.h GPoint.h \
  SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/VertexArray.h ../Common/Message.h ../Common/OS.h
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GFace.h GEdgeLoop.h GEdge.h SVector3.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h ../Common/SmoothData.h Pair.h
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h
GEdgeLoop.o: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h GVertex.h MVertex.h \
  GPoint.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h ../Common/Message.h
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/Message.h
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h
gmshVertex.o: gmshVertex.cpp GFace.h GPoint.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GEdgeLoop.h GEdge.h GVertex.h \
  MVertex.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h Pair.h gmshVertex.h Geo.h \
  gmshSurface.h ../DataStr/Tree.h ../DataStr/avl.h GeoInterpolation.h \
  ../Common/Message.h
gmshEdge.o: gmshEdge.cpp GFace.h GPoint.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GEdgeLoop.h GEdge.h GVertex.h \
  MVertex.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h Pair.h gmshEdge.h Geo.h \
  gmshSurface.h ../DataStr/Tree.h ../DataStr/avl.h gmshVertex.h \
  GeoInterpolation.h ../Common/Message.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h gmshVertex.h Geo.h gmshSurface.h ../DataStr/Tree.h \
  ../DataStr/avl.h gmshEdge.h gmshFace.h GeoInterpolation.h \
  ../Common/Message.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h gmshFace.h Geo.h gmshSurface.h ../DataStr/Tree.h \
  ../DataStr/avl.h gmshVertex.h gmshRegion.h ../Common/Message.h
gmshSurface.o: gmshSurface.cpp gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ../Common/Message.h
OCCVertex.o: OCCVertex.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/Message.h OCCEdge.h OCCVertex.h OCCIncludes.h \
  OCCFace.h
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h \
  ../Common/Message.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h OCCRegion.h \
  ../Common/Message.h
FEdge.o: FEdge.cpp ../Common/Message.h FEdge.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h GVertex.h MVertex.h \
  GPoint.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GModel.h GFace.h GEdgeLoop.h \
  Pair.h GRegion.h FVertex.h
FFace.o: FFace.cpp FVertex.h GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h FFace.h FEdge.h ../Common/Message.h
projectionFace.o: projectionFace.cpp projectionFace.h GFace.h GPoint.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  GEdgeLoop.h GEdge.h GVertex.h MVertex.h SPoint2.h SVector3.h MElement.h \
  MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h \
  ../Common/SmoothData.h Pair.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h gmshSurface.h ../Mesh/Field.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Geo/Geo.h \
  ../Geo/gmshSurface.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Geo/GEdge.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  MRep.h ../Common/Message.h ../Common/OS.h ../Mesh/BackgroundMesh.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h Geo.h gmshSurface.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Parser/OpenFile.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/Message.h gmshVertex.h gmshFace.h \
  gmshEdge.h gmshRegion.h ../Parser/Parser.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp ../Common/Message.h \
  ../Common/GmshDefines.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h \
  ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  gmshRegion.h Geo.h gmshSurface.h ../DataStr/Tree.h ../DataStr/avl.h \
  gmshFace.h gmshVertex.h gmshEdge.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModelIO_OCC.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h ../Common/SmoothData.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h OCCIncludes.h ../Common/Message.h \
  OCCVertex.h OCCEdge.h OCCFace.h OCCRegion.h
GModelIO_F.o: GModelIO_F.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h FFace.h FEdge.h \
  FVertex.h ../Mesh/meshGFace.h
GModelIO_CGNS.o: GModelIO_CGNS.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/Message.h MNeighbour.h
GModelIO_MED.o: GModelIO_MED.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/SmoothData.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/Message.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../Common/GmshDefines.h gmshSurface.h Pair.h Range.h SPoint2.h \
  SPoint3.h SVector3.h SBoundingBox3d.h ExtrudeParams.h \
  ../Common/SmoothData.h GModel.h GVertex.h GEntity.h MVertex.h GPoint.h \
  GEdge.h MElement.h MEdge.h ../Common/Hash.h MFace.h ../Common/Context.h \
  GFace.h GEdgeLoop.h GRegion.h GeoInterpolation.h
GeoStringInterface.o: GeoStringInterface.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h ../Common/GmshDefines.h \
  gmshSurface.h Pair.h Range.h SPoint2.h SPoint3.h SVector3.h \
  SBoundingBox3d.h ExtrudeParams.h ../Common/SmoothData.h \
  GeoStringInterface.h ../Parser/Parser.h ../Parser/OpenFile.h \
  ../Common/Context.h GModel.h GVertex.h GEntity.h MVertex.h GPoint.h \
  GEdge.h MElement.h MEdge.h ../Common/Hash.h MFace.h GFace.h GEdgeLoop.h \
  GRegion.h
GeoInterpolation.o: GeoInterpolation.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h Geo.h ../Common/GmshDefines.h gmshSurface.h Pair.h \
  Range.h SPoint2.h SPoint3.h SVector3.h SBoundingBox3d.h ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h GeoInterpolation.h \
  GeoStringInterface.h
findLinks.o: findLinks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  GModel.h GVertex.h GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ExtrudeParams.h ../Common/SmoothData.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h
MVertex.o: MVertex.cpp MVertex.h SPoint3.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h GEntity.h \
  Range.h SBoundingBox3d.h ../Common/Message.h
