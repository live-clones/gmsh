# $Id: Makefile,v 1.58 2005-01-08 20:15:12 geuzaine Exp $
#
# Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Numeric -I../NR\
          -I../Parser -I../Fltk 
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = CAD.cpp \
      MinMax.cpp \
      ExtrudeParams.cpp \
      Geo.cpp \
      GeoUtils.cpp \
      StepGeomDatabase.cpp \
      ExtractContour.cpp \
      Print_Geo.cpp

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
  ../Numeric/Numeric.h Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Mesh/Interpolation.h ../Mesh/Create.h CAD.h \
  ../Common/Visibility.h ../Common/Context.h
MinMax.o: MinMax.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h \
  ../Mesh/Vertex.h ../Common/Context.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Geo.h CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Parser/Parser.h ../Common/Context.h
GeoUtils.o: GeoUtils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Numeric/Numeric.h
StepGeomDatabase.o: StepGeomDatabase.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Geo.h GeoUtils.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Mesh/Nurbs.h CAD.h StepGeomDatabase.h \
  ../Mesh/Create.h ../Common/Context.h
ExtractContour.o: ExtractContour.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h GeoUtils.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h CAD.h ../Numeric/Numeric.h
Print_Geo.o: Print_Geo.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/DiscreteSurface.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h CAD.h ../Numeric/Numeric.h ../Common/Context.h
