# $Id: Makefile,v 1.113 2006-11-21 07:51:47 guzik Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

SRC = CAD.cpp \
      ExtrudeParams.cpp \
      Geo.cpp \
      GeoUtils.cpp \
      GEntity.cpp\
      GVertex.cpp\
      GEdge.cpp\
      GEdgeLoop.cpp\
      GFace.cpp\
      GRegion.cpp\
      MVertex.cpp \
      MElement.cpp \
      GModel.cpp\
      GModelIO_Mesh.cpp\
      GModelIO_Geo.cpp\
      GModelIO_Fourier.cpp\
      GModelIO_OCC.cpp\
      GModelIO_CGNS.cpp\
      gmshEdge.cpp\
      gmshFace.cpp\
      gmshRegion.cpp\
      OCCVertex.cpp\
      OCCEdge.cpp\
      OCCFace.cpp\
      OCCRegion.cpp\
      SVector3.cpp\
      SBoundingBox3d.cpp\
      projectionFace.cpp\
      ExtractContour.cpp

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
CAD.o: CAD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../DataStr/List.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h ../Mesh/Create.h CAD.h ../Mesh/Vertex.h \
  ExtrudeParams.h ../Mesh/Edge.h ../Common/Context.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../DataStr/List.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Mesh/Vertex.h \
  ExtrudeParams.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../DataStr/List.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Mesh/Vertex.h \
  ExtrudeParams.h ../Parser/Parser.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/Context.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h
GeoUtils.o: GeoUtils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../DataStr/List.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Mesh/Vertex.h \
  ExtrudeParams.h ../Numeric/Numeric.h
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
  ../Common/SmoothNormals.h ../Numeric/Numeric.h
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
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/Message.h \
  ../Mesh/Utils.h ../DataStr/List.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h
MVertex.o: MVertex.cpp MVertex.h SPoint3.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h GEntity.h \
  Range.h SBoundingBox3d.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h MRep.h \
  ../Common/VertexArray.h ../Common/Message.h ../Common/OS.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp ../Common/Message.h \
  ../Common/GmshDefines.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h SPoint2.h GEdge.h SVector3.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h GFace.h \
  GEdgeLoop.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h gmshRegion.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Mesh.h ../Mesh/Matrix.h gmshFace.h gmshVertex.h gmshEdge.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Mesh.h ../Mesh/Matrix.h Geo.h ../DataStr/List.h \
  ../Parser/OpenFile.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/Message.h gmshVertex.h gmshFace.h \
  gmshEdge.h gmshRegion.h
GModelIO_Fourier.o: GModelIO_Fourier.cpp GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h \
  GPoint.h SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h fourierFace.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/Message.h \
  OCCIncludes.h OCCVertex.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  OCCEdge.h OCCFace.h OCCRegion.h
GModelIO_CGNS.o: GModelIO_CGNS.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/Message.h \
  MNeighbour.h
gmshEdge.o: gmshEdge.cpp gmshEdge.h GEdge.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GVertex.h MVertex.h GPoint.h \
  SPoint2.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h gmshVertex.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h CAD.h ../DataStr/List.h ../Mesh/Vertex.h Geo.h \
  ../Mesh/Create.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h gmshVertex.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h gmshEdge.h gmshFace.h \
  ../Mesh/Interpolation.h CAD.h ../DataStr/List.h ../Mesh/Vertex.h Geo.h \
  ../Mesh/Create.h ../Mesh/Utils.h ../Common/Message.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  SPoint2.h GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h gmshFace.h gmshVertex.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h gmshRegion.h Geo.h \
  ../DataStr/List.h ../Mesh/Create.h
OCCVertex.o: OCCVertex.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h OCCVertex.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  OCCEdge.h OCCFace.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/Message.h \
  OCCEdge.h OCCVertex.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  OCCIncludes.h OCCFace.h
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h OCCVertex.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  OCCEdge.h OCCFace.h ../Common/Message.h ../Mesh/Utils.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h SPoint2.h \
  GEdge.h SVector3.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h GEdgeLoop.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h OCCVertex.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  OCCEdge.h OCCFace.h OCCRegion.h ../Common/Message.h
SVector3.o: SVector3.cpp SVector3.h SPoint3.h
SBoundingBox3d.o: SBoundingBox3d.cpp SBoundingBox3d.h SPoint3.h
projectionFace.o: projectionFace.cpp projectionFace.h GFace.h GPoint.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  GEdgeLoop.h GEdge.h GVertex.h MVertex.h SPoint2.h SVector3.h MElement.h \
  MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h Pair.h
ExtractContour.o: ExtractContour.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h ../DataStr/List.h GeoUtils.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h CAD.h ../Mesh/Vertex.h ExtrudeParams.h \
  ../Numeric/Numeric.h
