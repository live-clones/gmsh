# $Id: Makefile,v 1.9 2001-01-09 14:24:05 geuzaine Exp $
#
# Makefile for "libCommon.a"
#

.IGNORE:

CC      = c++
RANLIB  = ranlib
RM      = rm

LIB     = ../lib/libCommon.a
INCLUDE = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Parser -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS = -f
CFLAGS  = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
          $(GL_INCLUDE) $(GUI_INCLUDE)

SRC =  	Context.cpp\
        Views.cpp\
        GetOptions.cpp\
        Timer.cpp\
        ColorTable.cpp

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
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Const.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Context.h \
 trackball.c trackball.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Views.h Const.h ColorTable.h Context.h
GetOptions.o: GetOptions.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Const.h Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Views.h ColorTable.h \
 Version.h
Timer.o: Timer.cpp
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h ColorTable.h Context.h Const.h
