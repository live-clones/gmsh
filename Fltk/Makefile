# $Id: Makefile,v 1.53 2004-05-25 23:16:25 geuzaine Exp $
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

LIB     = ../lib/libGmshFltk.a
INCLUDE = -I../Common -I../DataStr -I../Graphics -I../Geo -I../Mesh\
          -I../Numeric -I../Parser -I../Fltk -I../Plugin -I../utils/solvers
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Main.cpp \
      Message.cpp \
      GUI.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      GmshServer.cpp\
      Solvers.cpp


OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

res:
	windres Win32Icon.rc -O coff Win32Icon.res

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
Main.o: Main.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/Gmsh.h \
  ../DataStr/Malloc.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../DataStr/Tools.h ../Common/GmshUI.h ../Common/GmshVersion.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/STL.h ../Mesh/Metric.h ../Mesh/Matrix.h ../Graphics/Draw.h \
  ../Common/Context.h ../Parser/Parser.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Parser/OpenFile.h ../Common/CommandLine.h \
  ../Numeric/Numeric.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/GmshVersion.h ../Common/Context.h ../Common/Options.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Common/ColorTable.h
GUI.o: GUI.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/Gmsh.h \
  ../DataStr/Malloc.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../DataStr/Tools.h ../Common/GmshUI.h ../Numeric/Numeric.h \
  ../Common/GmshVersion.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Callbacks.h Bitmaps.h Win32Icon.h \
  ../Parser/OpenFile.h ../Common/CommandLine.h Solvers.h
Callbacks.o: Callbacks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/STL.h ../Mesh/Metric.h ../Mesh/Matrix.h ../Geo/ExtractContour.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Timer.h ../Graphics/CreateFile.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Common/Context.h ../Common/Options.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Callbacks.h ../Plugin/Plugin.h \
  ../Common/Visibility.h ../Geo/MinMax.h Solvers.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h \
  ../Common/GmshUI.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h GUI.h Opengl_Window.h Colorbar_Window.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Common/ColorTable.h ../Common/Context.h
GmshServer.o: GmshServer.cpp
Solvers.o: Solvers.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../utils/solvers/GmshClient.h \
  GmshServer.h ../Parser/OpenFile.h Solvers.h ../Common/GmshUI.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Common/ColorTable.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/Context.h
