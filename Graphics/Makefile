# $Id: Makefile,v 1.60 2004-07-16 18:59:52 geuzaine Exp $
#
# Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

LIB     = ../lib/libGmshGraphics.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Fltk -I../Mesh -I../Numeric -I../Parser
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      PostElement.cpp \
      Iso.cpp \
      Entity.cpp \
      ReadImg.cpp \
      Scale.cpp \
      Graph2D.cpp \
      Axes.cpp \
      CreateFile.cpp \
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2png.cpp\
      gl2ppm.cpp\
      gl2yuv.cpp


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
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h ../Geo/MinMax.h ../Numeric/Numeric.h
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h ../Geo/MinMax.h gl2ps.h ../Numeric/Numeric.h
Geom.o: Geom.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Mesh/Utils.h Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h ../Mesh/Interpolation.h \
  gl2ps.h
Post.o: Post.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h gl2ps.h
PostElement.o: PostElement.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h Iso.h \
  ../Common/Context.h ../Numeric/Numeric.h
Iso.o: Iso.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
  ../Numeric/Numeric.h
Entity.o: Entity.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/STL.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h
ReadImg.o: ReadImg.cpp ReadImg.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h
Scale.o: Scale.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/STL.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h gl2ps.h
Graph2D.o: Graph2D.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Context.h ../Numeric/Numeric.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  gl2ps.h
Axes.o: Axes.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h gl2ps.h
CreateFile.o: CreateFile.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Parser/OpenFile.h Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h ../Common/Options.h gl2ps.h \
  gl2gif.h gl2jpeg.h gl2png.h gl2ppm.h gl2yuv.h
gl2ps.o: gl2ps.cpp gl2ps.h
gl2gif.o: gl2gif.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h gl2gif.h
gl2jpeg.o: gl2jpeg.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
gl2png.o: gl2png.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
gl2ppm.o: gl2ppm.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
gl2yuv.o: gl2yuv.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
