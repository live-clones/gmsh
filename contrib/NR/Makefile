# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshNR${LIBEXT}

INC = ${DASH}I../../Common ${DASH}I.

# don't optimize this library: there are some problems with gcc...
CFLAGS  = ${FLAGS} ${INC}

SRC = brent.cpp\
      dpythag.cpp\
      dsvdcmp.cpp\
      fdjac.cpp\
      fmin.cpp\
      lnsrch.cpp\
      lubksb.cpp\
      ludcmp.cpp\
      newt.cpp\
      nrutil.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	rm -f *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
brent.o: brent.cpp nrutil.h
dpythag.o: dpythag.cpp nrutil.h
dsvdcmp.o: dsvdcmp.cpp nrutil.h
fdjac.o: fdjac.cpp nrutil.h
fmin.o: fmin.cpp nrutil.h
lnsrch.o: lnsrch.cpp nrutil.h
lubksb.o: lubksb.cpp
ludcmp.o: ludcmp.cpp nrutil.h
newt.o: newt.cpp nrutil.h
nrutil.o: nrutil.cpp ../../Common/Message.h
