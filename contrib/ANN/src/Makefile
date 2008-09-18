# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../../variables

LIB = ../../../lib/libGmshANN${LIBEXT}

INC = ${DASH}I../../../Common ${DASH}I../include

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = ANN.cpp\
      bd_fix_rad_search.cpp\
      bd_pr_search.cpp\
      bd_search.cpp\
      bd_tree.cpp\
      brute.cpp\
      kd_dump.cpp\
      kd_fix_rad_search.cpp\
      kd_pr_search.cpp\
      kd_search.cpp\
      kd_split.cpp\
      kd_tree.cpp\
      kd_util.cpp\
      perf.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../../lib/

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
