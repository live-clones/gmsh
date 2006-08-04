# $Id: Makefile,v 1.34 2006-08-04 14:28:01 geuzaine Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

LIB     = ../lib/libGmshDataStr.a
INCLUDE = -I../Common
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = List.cpp \
      Malloc.cpp \
      SafeIO.cpp \
      Tree.cpp \
      avl.cpp \
      Tools.cpp

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
# 1 "/Users/geuzaine/.gmsh/DataStr//"
List.o: List.cpp Malloc.h List.h ../Common/Message.h SafeIO.h
# 1 "/Users/geuzaine/.gmsh/DataStr//"
Malloc.o: Malloc.cpp Malloc.h ../Common/Message.h
# 1 "/Users/geuzaine/.gmsh/DataStr//"
SafeIO.o: SafeIO.cpp SafeIO.h ../Common/Message.h
# 1 "/Users/geuzaine/.gmsh/DataStr//"
Tree.o: Tree.cpp Malloc.h Tree.h avl.h ../Common/Message.h
# 1 "/Users/geuzaine/.gmsh/DataStr//"
avl.o: avl.cpp avl.h Malloc.h
# 1 "/Users/geuzaine/.gmsh/DataStr//"
Tools.o: Tools.cpp Tools.h List.h Tree.h avl.h
