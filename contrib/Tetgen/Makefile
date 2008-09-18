# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshTetgen${LIBEXT}

# Do not optimize (same as Triangle...) 
CFLAGS = ${FLAGS} ${DASH}DTETLIBRARY

SRC = predicates.cxx tetgen.cxx
OBJ = ${SRC:.cxx=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cxx

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cxx${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	${RM} *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
predicates.o: predicates.cxx tetgen.h
tetgen.o: tetgen.cxx tetgen.h
