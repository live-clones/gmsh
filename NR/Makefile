# $Id: Makefile,v 1.1 2003-02-18 05:50:05 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshNR.a
INCLUDE = -I../Common -I../DataStr -I../Numeric
# don't optimize this library: there are some problems with gcc...
OPTIM = -O0
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = brent.cpp\
      dpythag.cpp\
      dsvdcmp.cpp\
      fdjac.cpp\
      fmin.cpp\
      lnsrch.cpp\
      lubksb.cpp\
      ludcmp.cpp\
      mnbrak.cpp\
      newt.cpp\
      nrutil.cpp

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
brent.o: brent.cpp nrutil.h ../Numeric/Numeric.h
dpythag.o: dpythag.cpp nrutil.h ../Numeric/Numeric.h
dsvdcmp.o: dsvdcmp.cpp nrutil.h ../Numeric/Numeric.h
fdjac.o: fdjac.cpp nrutil.h ../Numeric/Numeric.h
fmin.o: fmin.cpp nrutil.h ../Numeric/Numeric.h
lnsrch.o: lnsrch.cpp nrutil.h ../Numeric/Numeric.h
lubksb.o: lubksb.cpp
ludcmp.o: ludcmp.cpp nrutil.h ../Numeric/Numeric.h
mnbrak.o: mnbrak.cpp nrutil.h ../Numeric/Numeric.h
newt.o: newt.cpp nrutil.h ../Numeric/Numeric.h
nrutil.o: nrutil.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h
