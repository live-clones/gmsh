# $Id: Makefile,v 1.37 2002-05-18 00:55:14 geuzaine Exp $
#
# Makefile for "libGmshParser.a"
#

.IGNORE:

CXX      = c++
AR       = ar ruvs
RANLIB   = ranlib
RM       = rm
YACC     = bison
LEX      = flex

LIB      = ../lib/libGmshParser.a
INCLUDE  = -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Mesh -I../Fltk -I../Plugin -I../Parallel

OPT_FLAGS     = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = 

RMFLAGS  = -f
CFLAGS   = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
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
	$(CXX) $(CFLAGS) -c $<

parser:
	$(YACC) --output Gmsh.tab.cpp -d Gmsh.y 
	$(LEX)  -oGmsh.yy.cpp Gmsh.l

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
Gmsh.yy.o: Gmsh.yy.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Numeric.h ../Geo/Geo.h \
 ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Mesh/Matrix.h Gmsh.tab.cpp.h
Gmsh.tab.o: Gmsh.tab.cpp ../Plugin/PluginManager.h \
 ../Parallel/ParUtil.h ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Numeric.h \
 ../Common/Context.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
 ../Geo/DataBase.h ../Graphics/Draw.h ../Common/Views.h \
 ../Common/ColorTable.h ../Mesh/Create.h ../Geo/StepGeomDatabase.h \
 ../Common/Options.h ../Common/Colors.h Parser.h OpenFile.h \
 FunctionManager.h ../Common/Timer.h ../Graphics/CreateFile.h \
 ../Mesh/STL.h
OpenFile.o: OpenFile.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Numeric.h \
 ../Common/Context.h Parser.h OpenFile.h ../Common/GetOptions.h \
 ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Mesh/Matrix.h ../Common/Views.h ../Common/ColorTable.h \
 ../Geo/MinMax.h ../Graphics/Visibility.h ../Common/GmshUI.h \
 ../Graphics/Draw.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
 ../Fltk/Colorbar_Window.h
FunctionManager.o: FunctionManager.cpp FunctionManager.h
