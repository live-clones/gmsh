# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshMathEval${LIBEXT}

INC = ${DASH}I../../Common

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = matheval.cpp\
      node.cpp\
      scanner.yy.cpp\
      parser.tab.cpp\
      symbol_table.cpp\
      xmath.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

parser:
	bison --output parser.tab.cpp -pme -d parser.y
	if [ -r parser.tab.cpp.h ]; then mv parser.tab.cpp.h parser.tab.hpp ; fi
	flex -oscanner.yy.cpp -Pme scanner.l

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
matheval.o: matheval.cpp common.h ../../Common/MallocUtils.h matheval.h \
  node.h symbol_table.h
node.o: node.cpp common.h ../../Common/MallocUtils.h node.h \
  symbol_table.h
scanner.yy.o: scanner.yy.cpp common.h ../../Common/MallocUtils.h node.h \
  symbol_table.h parser.tab.hpp
parser.tab.o: parser.tab.cpp common.h ../../Common/MallocUtils.h node.h \
  symbol_table.h
symbol_table.o: symbol_table.cpp common.h ../../Common/MallocUtils.h \
  symbol_table.h xmath.h
xmath.o: xmath.cpp xmath.h
