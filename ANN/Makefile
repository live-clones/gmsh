# $Id: Makefile,v 1.1 2005-08-19 09:55:00 remacle Exp $
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

LIB     = ../lib/libGmshANN.a
INCLUDE = -I../Common -I./include/
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} -DNO_PARALLEL_THREADS -UWIN32

SRC = src/ANN.cpp\
      src/bd_fix_rad_search.cpp\
src/bd_pr_search.cpp\
src/bd_search.cpp\
src/bd_tree.cpp\
src/brute.cpp\
src/kd_dump.cpp\
src/kd_fix_rad_search.cpp\
src/kd_pr_search.cpp\
src/kd_search.cpp\
src/kd_split.cpp\
src/kd_tree.cpp\
src/kd_util.cpp\
src/perf.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $< -o ${<:.cpp=.o}

clean:
	rm -f src/*.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
