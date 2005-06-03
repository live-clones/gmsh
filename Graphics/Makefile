# $Id: Makefile,v 1.71 2005-06-03 17:32:29 geuzaine Exp $
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

LIB     = ../lib/libGmshGraphics.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Fltk -I../Mesh -I../Numeric -I../Parser -I../Plugin
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
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Geo/MinMax.h ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Geo/MinMax.h gl2ps.h ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Geom.o: Geom.cpp ../Mesh/BDS.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h ../Mesh/Utils.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  Draw.h ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Plugin/Plugin.h ../Common/Options.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Post.o: Post.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
PostElement.o: PostElement.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h Iso.h \
  ../Common/Context.h ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Iso.o: Iso.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Entity.o: Entity.cpp ../Mesh/Mesh.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
ReadImg.o: ReadImg.cpp ReadImg.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Scale.o: Scale.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
Graph2D.o: Graph2D.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
CreateFile.o: CreateFile.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Parser/OpenFile.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Common/Options.h gl2ps.h gl2gif.h gl2jpeg.h \
  gl2png.h gl2ppm.h gl2yuv.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2ps.o: gl2ps.cpp gl2ps.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2gif.o: gl2gif.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h gl2gif.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2jpeg.o: gl2jpeg.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2png.o: gl2png.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2ppm.o: gl2ppm.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h
# 1 "/Users/geuzaine/.gmsh/Graphics//"
gl2yuv.o: gl2yuv.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h
