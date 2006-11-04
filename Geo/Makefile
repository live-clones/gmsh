# $Id: Makefile,v 1.102 2006-11-04 00:17:08 geuzaine Exp $
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
      GFace.cpp\
      GRegion.cpp\
      GModel.cpp\
      GModelIO.cpp\
      MVertex.cpp \
      MElement.cpp \
      gmshModel.cpp\
      gmshEdge.cpp\
      gmshFace.cpp\
      gmshRegion.cpp\
      fourierModel.cpp\
      SVector3.cpp\
      SBoundingBox3d.cpp\
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
# 1 "/Users/geuzaine/.gmsh/Geo//"
CAD.o: CAD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h ExtrudeParams.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h CAD.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h \
  ../Parser/Parser.h ../Common/Context.h gmshModel.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GeoUtils.o: GeoUtils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h \
  ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GEntity.o: GEntity.cpp GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  ../Common/GmshDefines.h MRep.h GEdge.h GVertex.h MVertex.h GPoint.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/VertexArray.h \
  ../Common/Message.h ../Common/OS.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Common/Message.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
GModelIO.o: GModelIO.cpp ../Common/Message.h ../Common/GmshDefines.h \
  gmshRegion.h ../Mesh/Mesh.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  gmshModel.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h GEdge.h SVector3.h SPoint2.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ExtrudeParams.h GFace.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h gmshFace.h gmshVertex.h gmshEdge.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
MVertex.o: MVertex.cpp MVertex.h SPoint3.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h GEntity.h \
  Range.h SBoundingBox3d.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
gmshModel.o: gmshModel.cpp gmshModel.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h \
  GPoint.h GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  Geo.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/Message.h gmshVertex.h gmshFace.h gmshEdge.h gmshRegion.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
gmshEdge.o: gmshEdge.cpp gmshModel.h GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  gmshEdge.h gmshVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h Geo.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
gmshFace.o: gmshFace.cpp gmshModel.h GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  gmshVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h gmshEdge.h gmshFace.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h Geo.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h ../Mesh/Utils.h \
  ../Mesh/Vertex.h ../Mesh/Mesh.h ../Common/Message.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
gmshRegion.o: gmshRegion.cpp gmshModel.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h \
  GPoint.h GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h gmshFace.h gmshVertex.h ../Mesh/Mesh.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h gmshRegion.h Geo.h ../Mesh/Create.h ../Mesh/Vertex.h \
  ../Mesh/Mesh.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
fourierModel.o: fourierModel.cpp fourierModel.h GModel.h GVertex.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  MVertex.h GPoint.h GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
SVector3.o: SVector3.cpp SVector3.h SPoint3.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
SBoundingBox3d.o: SBoundingBox3d.cpp SBoundingBox3d.h SPoint3.h
# 1 "/Users/geuzaine/.gmsh/Geo//"
ExtractContour.o: ExtractContour.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h GeoUtils.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h CAD.h ExtrudeParams.h \
  ../Numeric/Numeric.h
