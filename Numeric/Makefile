# $Id: Makefile,v 1.7 2003-02-18 05:50:05 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshNumeric.a
INCLUDE = -I../Common -I../DataStr
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Numeric.cpp\
      gsl_newt.cpp\
      gsl_brent.cpp

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
  ../DataStr/avl.h ../DataStr/Tools.h Numeric.h \
  /usr/local/include/gsl/gsl_version.h /usr/local/include/gsl/gsl_types.h
