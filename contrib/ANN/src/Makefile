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
ANN.o: ANN.cpp ../include/ANN/ANNx.h ../include/ANN/ANN.h \
  ../include/ANN/ANNperf.h
bd_fix_rad_search.o: bd_fix_rad_search.cpp bd_tree.h \
  ../include/ANN/ANNx.h ../include/ANN/ANN.h kd_tree.h \
  kd_fix_rad_search.h kd_util.h pr_queue_k.h ../include/ANN/ANNperf.h
bd_pr_search.o: bd_pr_search.cpp bd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_tree.h kd_pr_search.h kd_util.h pr_queue.h \
  ../include/ANN/ANNperf.h pr_queue_k.h
bd_search.o: bd_search.cpp bd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_tree.h kd_search.h kd_util.h pr_queue_k.h \
  ../include/ANN/ANNperf.h
bd_tree.o: bd_tree.cpp bd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_tree.h kd_util.h kd_split.h \
  ../include/ANN/ANNperf.h
brute.o: brute.cpp ../include/ANN/ANNx.h ../include/ANN/ANN.h \
  pr_queue_k.h ../include/ANN/ANNperf.h
kd_dump.o: kd_dump.cpp kd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h bd_tree.h
kd_fix_rad_search.o: kd_fix_rad_search.cpp kd_fix_rad_search.h kd_tree.h \
  ../include/ANN/ANNx.h ../include/ANN/ANN.h kd_util.h pr_queue_k.h \
  ../include/ANN/ANNperf.h
kd_pr_search.o: kd_pr_search.cpp kd_pr_search.h kd_tree.h \
  ../include/ANN/ANNx.h ../include/ANN/ANN.h kd_util.h pr_queue.h \
  ../include/ANN/ANNperf.h pr_queue_k.h
kd_search.o: kd_search.cpp kd_search.h kd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_util.h pr_queue_k.h ../include/ANN/ANNperf.h
kd_split.o: kd_split.cpp kd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_util.h kd_split.h
kd_tree.o: kd_tree.cpp kd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h kd_split.h kd_util.h ../include/ANN/ANNperf.h
kd_util.o: kd_util.cpp kd_util.h kd_tree.h ../include/ANN/ANNx.h \
  ../include/ANN/ANN.h ../include/ANN/ANNperf.h
perf.o: perf.cpp ../include/ANN/ANN.h ../include/ANN/ANNperf.h
