# $Id: Makefile,v 1.22 2003-03-02 18:44:15 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshBox.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../Plugin -I../Parallel
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Main.cpp

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
Main.o: Main.cpp ../Parallel/ParUtil.h ../Plugin/PluginManager.h \
  ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshVersion.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Common/Views.h ../Common/ColorTable.h ../Parser/Parser.h \
  ../Common/Context.h ../Common/Options.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Geo/MinMax.h
