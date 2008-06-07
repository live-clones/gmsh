# $Id: Makefile,v 1.56 2008-06-07 17:20:48 geuzaine Exp $
#
# Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to <gmsh@geuz.org>.

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
	rm -f *.o *.obj 

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
  ../Common/GmshDefines.h
gmsh_predicates.o: gmsh_predicates.cpp
gsl_newt.o: gsl_newt.cpp ../Common/Message.h Numeric.h NumericEmbedded.h
gsl_min.o: gsl_min.cpp ../Common/Message.h Numeric.h NumericEmbedded.h
gsl_brent.o: gsl_brent.cpp ../Common/Message.h Numeric.h \
  NumericEmbedded.h
