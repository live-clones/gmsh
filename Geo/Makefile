# $Id: Makefile,v 1.33 2003-02-11 08:54:55 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshGeo.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk
CFLAGS  = ${OPT_FLAGS} ${OS_FLAGS} ${VERSION_FLAGS} ${INCLUDE}

SRC = CAD.cpp \
      DataBase.cpp \
      MinMax.cpp \
      ExtrudeParams.cpp \
      Geo.cpp \
      StepGeomDatabase.cpp \
      Verif.cpp \
      Print_Geo.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

clean:
	rm -f *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
CAD.o: CAD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h DataBase.h ../Mesh/Interpolation.h \
  ../Mesh/Create.h CAD.h ../Common/Context.h
DataBase.o: DataBase.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h CAD.h \
  ../Mesh/Create.h Verif.h ../Common/Context.h
MinMax.o: MinMax.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h \
  ../Mesh/Vertex.h ../Common/Context.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ExtrudeParams.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Geo.h CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h DataBase.h ../Parser/Parser.h \
  ../Common/Context.h
StepGeomDatabase.o: StepGeomDatabase.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Geo.h StepGeomDatabase.h DataBase.h \
  ../Common/Context.h
Verif.o: Verif.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h DataBase.h
Print_Geo.o: Print_Geo.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h CAD.h \
  ../Common/Context.h
