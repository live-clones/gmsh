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
	${RM} *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
brent${OBJEXT}: brent.cpp nrutil.h
dpythag${OBJEXT}: dpythag.cpp nrutil.h
dsvdcmp${OBJEXT}: dsvdcmp.cpp nrutil.h
fdjac${OBJEXT}: fdjac.cpp nrutil.h
fmin${OBJEXT}: fmin.cpp nrutil.h
lnsrch${OBJEXT}: lnsrch.cpp nrutil.h
lubksb${OBJEXT}: lubksb.cpp
ludcmp${OBJEXT}: ludcmp.cpp nrutil.h
newt${OBJEXT}: newt.cpp nrutil.h
nrutil${OBJEXT}: nrutil.cpp ../../Common/GmshMessage.h
