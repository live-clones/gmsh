# $Id: Makefile,v 1.86 2006-02-26 16:26:08 geuzaine Exp $
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

LIB     = ../lib/libGmshCommon.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh\
          -I../Numeric -I../Parser -I../Plugin -I../Fltk\
          -I../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Context.cpp\
      AdaptiveViews.cpp\
      Views.cpp ViewsIO.cpp\
      Octree.cpp OctreeInternals.cpp OctreePost.cpp\
      Options.cpp\
      CommandLine.cpp\
      OS.cpp\
      ColorTable.cpp\
      Visibility.cpp\
      Trackball.cpp\
      VertexArray.cpp\
      SmoothNormals.cpp\
      License.cpp

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
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
# 1 "/Users/geuzaine/.gmsh/Common//"
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Context.h \
  DefaultOptions.h Options.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Views.h ColorTable.h \
  VertexArray.h SmoothNormals.h GmshMatrix.h AdaptiveViews.h Trackball.h
# 1 "/Users/geuzaine/.gmsh/Common//"
AdaptiveViews.o: AdaptiveViews.cpp AdaptiveViews.h ../DataStr/List.h \
  GmshMatrix.h ../Plugin/Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h OS.h
# 1 "/Users/geuzaine/.gmsh/Common//"
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h Views.h ColorTable.h \
  VertexArray.h SmoothNormals.h GmshMatrix.h AdaptiveViews.h Context.h \
  Options.h
# 1 "/Users/geuzaine/.gmsh/Common//"
ViewsIO.o: ViewsIO.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Views.h \
  ColorTable.h VertexArray.h SmoothNormals.h GmshMatrix.h AdaptiveViews.h \
  Context.h
# 1 "/Users/geuzaine/.gmsh/Common//"
Octree.o: Octree.cpp Octree.h OctreeInternals.h
# 1 "/Users/geuzaine/.gmsh/Common//"
OctreeInternals.o: OctreeInternals.cpp Message.h OctreeInternals.h
# 1 "/Users/geuzaine/.gmsh/Common//"
OctreePost.o: OctreePost.cpp Octree.h OctreeInternals.h OctreePost.h \
  ../DataStr/List.h Views.h ColorTable.h VertexArray.h SmoothNormals.h \
  ../Numeric/Numeric.h GmshMatrix.h AdaptiveViews.h Message.h \
  ShapeFunctions.h
# 1 "/Users/geuzaine/.gmsh/Common//"
Options.o: Options.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h Gmsh.h Message.h \
  ../DataStr/Malloc.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h GmshUI.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h Context.h Options.h \
  ../Fltk/Solvers.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
  ../Fltk/Colorbar_Window.h ../Common/GmshUI.h
# 1 "/Users/geuzaine/.gmsh/Common//"
CommandLine.o: CommandLine.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h GmshUI.h GmshVersion.h \
  CommandLine.h ../Numeric/Numeric.h Context.h Options.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Views.h ColorTable.h \
  VertexArray.h SmoothNormals.h GmshMatrix.h AdaptiveViews.h \
  ../Parser/OpenFile.h ../Parser/Parser.h OS.h
# 1 "/Users/geuzaine/.gmsh/Common//"
OS.o: OS.cpp Message.h
# 1 "/Users/geuzaine/.gmsh/Common//"
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ColorTable.h Context.h \
  ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Common//"
Visibility.o: Visibility.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Geo/Geo.h ../Geo/CAD.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h ../Parser/Parser.h Visibility.h
# 1 "/Users/geuzaine/.gmsh/Common//"
Trackball.o: Trackball.cpp Trackball.h
# 1 "/Users/geuzaine/.gmsh/Common//"
VertexArray.o: VertexArray.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h VertexArray.h Context.h \
  ../Numeric/Numeric.h
# 1 "/Users/geuzaine/.gmsh/Common//"
SmoothNormals.o: SmoothNormals.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h \
  SmoothNormals.h
# 1 "/Users/geuzaine/.gmsh/Common//"
License.o: License.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h
