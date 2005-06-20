# $Id: Makefile,v 1.5 2005-06-20 16:35:30 geuzaine Exp $
#
# Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

LIB = ../lib/libGmshMathEval.a
INCLUDE = -I../Common -I../DataStr

CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = matheval.cpp\
      node.cpp\
      scanner.yy.cpp\
      parser.tab.cpp\
      symbol_table.cpp\
      xmath.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ}
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

parser:
	bison --output parser.tab.cpp -pme -d parser.y
	if [ -r parser.tab.cpp.h ]; then mv parser.tab.cpp.h parser.tab.hpp ; fi
	flex -oscanner.yy.cpp -Pme scanner.l

clean:
	rm -f *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CC} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
# 1 "/Users/geuzaine/.gmsh/MathEval//"
matheval.o: matheval.cpp common.h ../DataStr/Malloc.h matheval.h node.h \
  symbol_table.h
# 1 "/Users/geuzaine/.gmsh/MathEval//"
node.o: node.cpp common.h ../DataStr/Malloc.h node.h symbol_table.h
# 1 "/Users/geuzaine/.gmsh/MathEval//"
scanner.o: scanner.cpp common.h ../DataStr/Malloc.h node.h symbol_table.h \
  parser.h
# 1 "/Users/geuzaine/.gmsh/MathEval//"
parser.o: parser.cpp common.h ../DataStr/Malloc.h node.h symbol_table.h
# 1 "/Users/geuzaine/.gmsh/MathEval//"
symbol_table.o: symbol_table.cpp common.h ../DataStr/Malloc.h \
  symbol_table.h xmath.h
# 1 "/Users/geuzaine/.gmsh/MathEval//"
xmath.o: xmath.cpp xmath.h
