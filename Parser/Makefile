#
# Makefile for "libParser.a"
#

.IGNORE:

CC        = c++
C_FLAGS   = -g -Wall

OS_FLAGS  = -D_UNIX

RANLIB   = /usr/bin/ranlib
RM       = rm
YACC     = bison
LEX      = flex

RMFLAGS  = -f

LIB      = ../lib/libParser.a
INCLUDE  = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Mesh -I../Unix

CFLAGS = $(C_FLAGS) $(OS_FLAGS) $(INCLUDE) 

SRC =  	Gmsh.yy.cpp \
	Gmsh.tab.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	ar ruvs $(LIB) $(OBJ)
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
 ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h ../Geo/CAD.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Gmsh.tab.cpp.h
Gmsh.tab.o: Gmsh.tab.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h \
 ../Common/Context.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Geo/DataBase.h \
 ../Mesh/Create.h ../Common/Views.h ../Graphics/ColorTable.h \
 ../Geo/StepGeomDatabase.h ../Common/Colors.h Parser.h
