# $Id: Makefile,v 1.28 2001-08-20 08:25:23 geuzaine Exp $
#
# Makefile for "libCommon.a"
#

.IGNORE:

CXX     = c++
AR      = ar ruvs
RANLIB  = ranlib
RM      = rm

LIB     = ../lib/libCommon.a
INCLUDE = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Parser -I../Motif -I../Fltk

OPT_FLAGS     = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_FLTK

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
          $(GL_INCLUDE) $(GUI_INCLUDE)

SRC =  	Context.cpp\
        Views.cpp\
        Iso.cpp\
        Options.cpp\
        GetOptions.cpp\
        Timer.cpp\
        ColorTable.cpp\
        Numeric.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ)
	$(RANLIB) $(LIB)

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

res:
	windres Icon.rc -O coff Icon.res

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/ColorTable.h Context.h Options.h \
 DefaultOptions.h trackball.c trackball.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Numeric.h Views.h ColorTable.h Context.h Options.h
Iso.o: Iso.cpp Gmsh.h Message.h ../DataStr/Malloc.h ../DataStr/List.h \
 ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/ColorTable.h Numeric.h
Options.o: Options.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/ColorTable.h Context.h Options.h \
 ../Fltk/Solvers.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
 ../Fltk/Colorbar_Window.h
GetOptions.o: GetOptions.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h GmshUI.h GmshVersion.h Numeric.h Context.h \
 Options.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h Views.h ColorTable.h ../Parser/OpenFile.h \
 ../Parser/Parser.h
Timer.o: Timer.cpp
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h ColorTable.h Context.h
Numeric.o: Numeric.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Numeric.h
