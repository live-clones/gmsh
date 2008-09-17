# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshNumeric${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Numeric ${DASH}I../contrib/NR

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Numeric.cpp\
        NumericEmbedded.cpp\
      EigSolve.cpp\
      FunctionSpace.cpp\
      gmsh_predicates.cpp\
      gsl_newt.cpp\
      gsl_min.cpp\
      gsl_brent.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
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
Numeric.o: Numeric.cpp ../Common/Message.h Numeric.h NumericEmbedded.h
NumericEmbedded.o: NumericEmbedded.cpp NumericEmbedded.h \
  ../Common/Message.h
EigSolve.o: EigSolve.cpp
FunctionSpace.o: FunctionSpace.cpp FunctionSpace.h ../Common/GmshMatrix.h \
  ../Common/GmshDefines.h ../Common/Message.h
gmsh_predicates.o: gmsh_predicates.cpp
gsl_newt.o: gsl_newt.cpp ../Common/Message.h Numeric.h NumericEmbedded.h
gsl_min.o: gsl_min.cpp ../Common/Message.h Numeric.h NumericEmbedded.h
gsl_brent.o: gsl_brent.cpp ../Common/Message.h Numeric.h \
  NumericEmbedded.h
