# $Id: Makefile,v 1.23 2001-08-09 18:28:23 remacle Exp $
#
# Makefile for "libFltk.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib

LIB      = ../lib/libFltk.a
INCLUDE  = -I../Common -I../DataStr -I../Graphics -I../Geo\
           -I../Mesh -I../Parser -I../Fltk -I../Plugin

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_NOTHREADS -D_FLTK

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I$(HOME)/SOURCES/fltk

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GUI_INCLUDE) $(GL_INCLUDE)

SRC = Main.cpp \
      Message.cpp \
      GUI.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      Socket.cpp\
      Solvers.cpp


OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
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
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
  ../Common/Context.h ../Common/Options.h ../Parser/Parser.h \
  ../Common/Static.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Parser/OpenFile.h ../Common/GetOptions.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/GmshVersion.h ../Common/Context.h ../Common/Const.h \
  ../Common/Options.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Common/ColorTable.h
GUI.o: GUI.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Gmsh.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/GmshVersion.h ../Common/Context.h ../Common/Const.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Callbacks.h ../Common/Bitmaps.h \
  ../Common/Icon.h ../Common/GetOptions.h
Callbacks.o: Callbacks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
  ../Geo/Verif.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/Const.h \
  ../Common/ColorTable.h ../Common/Timer.h ../Geo/Visibility.h \
  ../Graphics/CreateFile.h ../Parser/OpenFile.h ../Common/GetOptions.h \
  ../Common/Context.h ../Common/Options.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Callbacks.h ../Plugin/Plugin.h Solvers.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Context.h ../Common/Const.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/ColorTable.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Context.h ../Common/Const.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/ColorTable.h GUI.h Opengl_Window.h \
  Colorbar_Window.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Common/ColorTable.h ../Common/Context.h ../Common/Const.h
Socket.o: Socket.cpp ../Common/Message.h
Solvers.o: Solvers.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Socket.h ../Parser/OpenFile.h \
  ../Common/Const.h Solvers.h ../Common/GmshUI.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Common/ColorTable.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/Context.h
