# $Id: Makefile,v 1.1 2001-01-08 08:16:27 geuzaine Exp $
#
# Makefile for "libFltk.a"
#

.IGNORE:

CC       = c++
RM       = rm
RANLIB   = ranlib

LIB      = ../lib/libFltk.a
INCLUDE  = -I../Common -I../DataStr -I../Graphics -I../Geo\
           -I../Mesh -I../Parser -I../Fltk

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
      Opengl.cpp\
      Callbacks.cpp


OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	ar ruvs $(LIB) $(OBJ) 
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
Main.o: Main.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Geo/Verif.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
  ../Common/Context.h ../Parser/Parser.h ../Common/Static.h \
  ../Common/Version.h GUI.h ../Parser/OpenFile.h ../Common/GetOptions.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Version.h ../Common/Context.h ../Common/Const.h
GUI.o: GUI.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshUI.h ../Common/Context.h ../Common/Const.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/Version.h GUI.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
  ../Common/Context.h ../Common/Const.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/ColorTable.h GUI.h
