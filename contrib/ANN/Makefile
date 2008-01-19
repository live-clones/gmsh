# $Id: Makefile,v 1.18 2008-01-19 00:49:08 geuzaine Exp $
#
# Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

include ../../variables

LIB     = ../../lib/libGmshANN${LIBEXT}
INCLUDE = ${DASH}I../../Common ${DASH}I./include
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} ${SYSINCLUDE}

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

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $< ${DASH}o ${<:.cpp=${OBJEXT}}
	if [ -r ${notdir ${<:.cpp=${OBJEXT}}} ]; then\
           mv -f ${notdir ${<:.cpp=${OBJEXT}}} ${<:.cpp=${OBJEXT}};\
        fi

clean:
	rm -f src/*${OBJEXT}

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
ANN.o: src/ANN.cpp include/ANN/ANNx.h include/ANN/ANN.h \
  include/ANN/ANNperf.h
bd_fix_rad_search.o: src/bd_fix_rad_search.cpp src/bd_tree.h \
  include/ANN/ANNx.h include/ANN/ANN.h src/kd_tree.h \
  src/kd_fix_rad_search.h src/kd_util.h src/pr_queue_k.h \
  include/ANN/ANNperf.h
bd_pr_search.o: src/bd_pr_search.cpp src/bd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/kd_tree.h src/kd_pr_search.h src/kd_util.h \
  src/pr_queue.h include/ANN/ANNperf.h src/pr_queue_k.h
bd_search.o: src/bd_search.cpp src/bd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/kd_tree.h src/kd_search.h src/kd_util.h \
  src/pr_queue_k.h include/ANN/ANNperf.h
bd_tree.o: src/bd_tree.cpp src/bd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/kd_tree.h src/kd_util.h src/kd_split.h \
  include/ANN/ANNperf.h
brute.o: src/brute.cpp include/ANN/ANNx.h include/ANN/ANN.h \
  src/pr_queue_k.h include/ANN/ANNperf.h
kd_dump.o: src/kd_dump.cpp src/kd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/bd_tree.h
kd_fix_rad_search.o: src/kd_fix_rad_search.cpp src/kd_fix_rad_search.h \
  src/kd_tree.h include/ANN/ANNx.h include/ANN/ANN.h src/kd_util.h \
  src/pr_queue_k.h include/ANN/ANNperf.h
kd_pr_search.o: src/kd_pr_search.cpp src/kd_pr_search.h src/kd_tree.h \
  include/ANN/ANNx.h include/ANN/ANN.h src/kd_util.h src/pr_queue.h \
  include/ANN/ANNperf.h src/pr_queue_k.h
kd_search.o: src/kd_search.cpp src/kd_search.h src/kd_tree.h \
  include/ANN/ANNx.h include/ANN/ANN.h src/kd_util.h src/pr_queue_k.h \
  include/ANN/ANNperf.h
kd_split.o: src/kd_split.cpp src/kd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/kd_util.h src/kd_split.h
kd_tree.o: src/kd_tree.cpp src/kd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h src/kd_split.h src/kd_util.h include/ANN/ANNperf.h
kd_util.o: src/kd_util.cpp src/kd_util.h src/kd_tree.h include/ANN/ANNx.h \
  include/ANN/ANN.h include/ANN/ANNperf.h
perf.o: src/perf.cpp include/ANN/ANN.h include/ANN/ANNperf.h
