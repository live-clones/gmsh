# $Id: Makefile,v 1.35 2002-05-18 16:31:16 geuzaine Exp $
#
# Makefile for "libGmshFltk.a"
#

CXX    = c++
AR     = ar ruvs
RM     = rm
RANLIB = ranlib

LIB     = ../lib/libGmshFltk.a
INCLUDE = -I../Common -I../DataStr -I../Graphics -I../Geo\
          -I../Mesh -I../Numeric -I../Parser -I../Fltk -I../Plugin -I../utils

OPT_FLAGS     = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_FLTK

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
          $(GUI_INCLUDE) $(GL_INCLUDE)

SRC = Main.cpp \
      Message.cpp \
      GUI.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      GmshServer.cpp\
      Solvers.cpp


OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

res:
	windres Icon.rc -O coff Icon.res

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM -MG $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
Main.o: Main.cpp ../Plugin/PluginManager.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Common/GmshVersion.h ../Geo/Geo.h ../Geo/Verif.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h ../Common/Options.h ../Parser/Parser.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Parser/OpenFile.h \
  ../Common/GetOptions.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/GmshVersion.h ../Common/Context.h ../Common/Options.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Common/ColorTable.h
GUI.o: GUI.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Gmsh.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Common/GmshVersion.h ../Common/Context.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Callbacks.h Bitmaps.h \
  ../Parser/OpenFile.h ../Common/GetOptions.h Solvers.h
Callbacks.o: Callbacks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Geo/Verif.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Timer.h ../Graphics/CreateFile.h \
  ../Parser/OpenFile.h ../Common/GetOptions.h ../Common/Context.h \
  ../Common/Options.h GUI.h Opengl_Window.h Colorbar_Window.h Callbacks.h \
  ../Plugin/Plugin.h ../Graphics/Visibility.h Solvers.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h \
  ../Common/GmshUI.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h GUI.h \
  Opengl_Window.h Colorbar_Window.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Common/ColorTable.h ../Common/Context.h
GmshServer.o: GmshServer.cpp
Solvers.o: Solvers.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../utils/GmshClient.h GmshServer.h \
  ../Parser/OpenFile.h Solvers.h ../Common/GmshUI.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Common/ColorTable.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/Context.h
