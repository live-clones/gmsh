# $Id: Makefile,v 1.6 2003-02-11 08:54:56 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshNumeric.a
INCLUDE = -I../Common -I../DataStr
CFLAGS  = ${OPT_FLAGS} ${OS_FLAGS} ${VERSION_FLAGS} ${INCLUDE} 

SRC = Numeric.cpp\
      Newton.cpp \
      Opti.cpp \
      SVD.cpp \
      NRUtil.cpp

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
Numeric.o: Numeric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Numeric.h
Newton.o: Newton.cpp NRUtil.h Numeric.h
Opti.o: Opti.cpp NRUtil.h Numeric.h
SVD.o: SVD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  NRUtil.h Numeric.h
NRUtil.o: NRUtil.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h
