# $Id: Makefile,v 1.20 2001-04-23 10:38:16 geuzaine Exp $
#
# Makefile for "libParser.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RANLIB   = ranlib
RM       = rm
YACC     = bison
LEX      = flex

LIB      = ../lib/libParser.a
INCLUDE  = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Mesh -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_XMOTIF

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GL_INCLUDE) $(GUI_INCLUDE)

SRC =  	Gmsh.yy.cpp \
	Gmsh.tab.cpp\
        OpenFile.cpp\
	FunctionManager.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ)
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

parser:
	$(YACC) --output Gmsh.tab.cpp -d Gmsh.y 
	$(LEX)  -oGmsh.yy.cpp Gmsh.l

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
Gmsh.yy.o: Gmsh.yy.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
 ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Gmsh.tab.cpp.h
Gmsh.tab.o: Gmsh.tab.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h \
 ../Common/Context.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Geo/DataBase.h \
 ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Mesh/Create.h ../Geo/StepGeomDatabase.h ../Common/Options.h \
 ../Common/Colors.h Parser.h OpenFile.h FunctionManager.h \
 ../Common/Timer.h ../Graphics/CreateFile.h
OpenFile.o: OpenFile.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h \
 ../Common/Context.h Parser.h OpenFile.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Common/Views.h \
 ../Common/ColorTable.h ../Geo/MinMax.h ../Geo/Visibility.h \
 ../Common/GmshUI.h ../Graphics/Draw.h ../Motif/Widgets.h
FunctionManager.o: FunctionManager.cpp FunctionManager.h
