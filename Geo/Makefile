# $Id: Makefile,v 1.11 2001-02-09 14:51:31 geuzaine Exp $
#
# Makefile for "libGeo.a"
#

.IGNORE:

CC      = c++
AR      = ar ruvs
RANLIB  = ranlib
RM      = rm

LIB       = ../lib/libGeo.a
INCLUDE   = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Parser\
            -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)

SRC =  	CAD.cpp \
        DataBase.cpp \
        MinMax.cpp \
        ExtrudeParams.cpp \
        Geo.cpp \
        StepGeomDatabase.cpp \
	Verif.cpp \
	Visibility.cpp \
        Print_Geo.cpp

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
CAD.o: CAD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h DataBase.h \
  ../Mesh/Interpolation.h ../Mesh/Numeric.h ../Common/Const.h \
  ../Mesh/Create.h CAD.h ../Common/Context.h
DataBase.o: DataBase.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h CAD.h ../Mesh/Create.h Verif.h \
  ../Common/Context.h
MinMax.o: MinMax.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Mesh/Vertex.h \
  ../Common/Context.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ExtrudeParams.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/Const.h Geo.h CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h DataBase.h ../Parser/Parser.h
StepGeomDatabase.o: StepGeomDatabase.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h \
  Geo.h StepGeomDatabase.h DataBase.h ../Common/Context.h
Verif.o: Verif.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h DataBase.h
Visibility.o: Visibility.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h DataBase.h
Print_Geo.o: Print_Geo.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h CAD.h ../Common/Context.h \
  ../Common/Const.h
