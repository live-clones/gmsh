# $Id: Makefile,v 1.48 2004-02-07 01:40:17 geuzaine Exp $
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

LIB     = ../lib/libGmshCommon.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Numeric -I../Parser -I../Fltk
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Context.cpp\
      Views.cpp\
      Options.cpp\
      CommandLine.cpp\
      Timer.cpp\
      ColorTable.cpp\
      Visibility.cpp\
      Trackball.cpp\
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
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h Context.h Options.h DefaultOptions.h Trackball.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Views.h ColorTable.h Context.h Options.h
Options.o: Options.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h Context.h Options.h ../Fltk/Solvers.h \
  ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h
CommandLine.o: CommandLine.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  GmshUI.h GmshVersion.h CommandLine.h ../Numeric/Numeric.h Context.h \
  Options.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h Views.h ColorTable.h \
  ../Parser/OpenFile.h ../Parser/Parser.h
Timer.o: Timer.cpp
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ColorTable.h Context.h
Visibility.o: Visibility.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h ../Geo/DataBase.h ../Parser/Parser.h \
  Visibility.h
Trackball.o: Trackball.cpp Trackball.h
License.o: License.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h
