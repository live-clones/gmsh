# $Id: Makefile,v 1.128 2007-01-31 12:27:18 remacle Exp $
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
          -I../Parser -I../Fltk -I../contrib/NR -I../contrib/FourierModel
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
      projectionFace.cpp\
      GModel.cpp\
        GModelIO_Geo.cpp\
        GModelIO_Mesh.cpp\
        GModelIO_Fourier.cpp\
        GModelIO_OCC.cpp\
        GModelIO_CGNS.cpp\
        GModelIO_MED.cpp\
      ExtrudeParams.cpp \
      Geo.cpp \
	GeoStringInterface.cpp GeoInterpolation.cpp\
        GeoUtils.cpp GeoExtractContour.cpp\
      MVertex.cpp \
      MElement.cpp \
      SVector3.cpp\
      projectionFace.cpp\
      SBoundingBox3d.cpp

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
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/VertexArray.h ../Common/Message.h ../Common/OS.h
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GFace.h GEdgeLoop.h GEdge.h SVector3.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h Pair.h
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h
GEdgeLoop.o: GEdgeLoop.cpp GEdgeLoop.h GEdge.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h GVertex.h MVertex.h \
  GPoint.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h ../Common/Message.h
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Common/Message.h
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h
gmshVertex.o: gmshVertex.cpp GFace.h GPoint.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GEdgeLoop.h GEdge.h GVertex.h \
  MVertex.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h Pair.h gmshVertex.h Geo.h ../DataStr/Tree.h \
  ../DataStr/avl.h GeoInterpolation.h ../Common/Message.h
gmshEdge.o: gmshEdge.cpp GFace.h GPoint.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GEdgeLoop.h GEdge.h GVertex.h \
  MVertex.h SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h Pair.h gmshEdge.h Geo.h ../DataStr/Tree.h \
  ../DataStr/avl.h gmshVertex.h GeoInterpolation.h ../Common/Message.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h gmshVertex.h Geo.h ../DataStr/Tree.h \
  ../DataStr/avl.h gmshEdge.h gmshFace.h GeoInterpolation.h \
  ../Common/Message.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h gmshFace.h Geo.h ../DataStr/Tree.h \
  ../DataStr/avl.h gmshVertex.h gmshRegion.h ../Common/Message.h
OCCVertex.o: OCCVertex.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Common/Message.h OCCEdge.h OCCVertex.h \
  OCCIncludes.h OCCFace.h
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h \
  ../Common/Message.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h OCCVertex.h OCCIncludes.h OCCEdge.h OCCFace.h \
  OCCRegion.h ../Common/Message.h
projectionFace.o: projectionFace.cpp projectionFace.h GFace.h GPoint.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  GEdgeLoop.h GEdge.h GVertex.h MVertex.h SPoint2.h SVector3.h MElement.h \
  MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h Pair.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h MRep.h ../Common/VertexArray.h \
  ../Common/Message.h ../Common/OS.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h Geo.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Parser/OpenFile.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/Message.h gmshVertex.h gmshFace.h \
  gmshEdge.h gmshRegion.h ../Parser/Parser.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp ../Common/Message.h \
  ../Common/GmshDefines.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/SmoothNormals.h gmshRegion.h \
  Geo.h ../DataStr/Tree.h ../DataStr/avl.h gmshFace.h gmshVertex.h \
  gmshEdge.h
GModelIO_Fourier.o: GModelIO_Fourier.cpp GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h fourierFace.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Common/Message.h OCCIncludes.h OCCVertex.h \
  OCCEdge.h OCCFace.h OCCRegion.h
GModelIO_CGNS.o: GModelIO_CGNS.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Common/Message.h MNeighbour.h
GModelIO_MED.o: GModelIO_MED.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h GModelIO_MED.h ../Common/Message.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../Common/GmshDefines.h ExtrudeParams.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../Common/GmshDefines.h ExtrudeParams.h GeoUtils.h GeoInterpolation.h \
  ../Common/Context.h
GeoStringInterface.o: GeoStringInterface.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h ../Common/GmshDefines.h \
  ExtrudeParams.h GeoStringInterface.h ../Parser/Parser.h \
  ../Common/Context.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h GFace.h GEdgeLoop.h Pair.h \
  GRegion.h ../Common/SmoothNormals.h
GeoInterpolation.o: GeoInterpolation.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h Geo.h ../Common/GmshDefines.h ExtrudeParams.h \
  GeoInterpolation.h GeoStringInterface.h GeoUtils.h ../Numeric/Numeric.h
GeoUtils.o: GeoUtils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../Common/GmshDefines.h ExtrudeParams.h ../Numeric/Numeric.h
GeoExtractContour.o: GeoExtractContour.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h Geo.h ../Common/GmshDefines.h ExtrudeParams.h \
  GeoUtils.h ../Numeric/Numeric.h
MVertex.o: MVertex.cpp MVertex.h SPoint3.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h GEntity.h \
  Range.h SBoundingBox3d.h ../Common/Message.h
SVector3.o: SVector3.cpp SVector3.h SPoint3.h
projectionFace.o: projectionFace.cpp projectionFace.h GFace.h GPoint.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  GEdgeLoop.h GEdge.h GVertex.h MVertex.h SPoint2.h SVector3.h MElement.h \
  MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h Pair.h
SBoundingBox3d.o: SBoundingBox3d.cpp SBoundingBox3d.h SPoint3.h
