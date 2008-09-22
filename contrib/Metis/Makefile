# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshMetis${LIBEXT}

INC = ${DASH}I.

CFLAGS  = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = balance.c \
      fm.c        \
      kwayfm.c    \
      mcoarsen.c  \
      minitpart2.c \
      mpmetis.c   \
      pmetis.c     \
      subdomains.c\
      bucketsort.c  \
      fortran.c  \
      kwayrefine.c\
      memory.c  \
      minitpart.c  \
      mrefine2.c\
      pqueue.c\
      timing.c\
      ccgraph.c \
      frename.c \
      kwayvolfm.c\
      mesh.c\
      mkmetis.c\
      mrefine.c \
      refine.c  \
      util.c\
      coarsen.c \
      graph.c\
      kwayvolrefine.c  \
      meshpart.c  \
      mkwayfmh.c \
      mutil.c \
      separator.c\
      compress.c\
      initpart.c\
      match.c\
      mfm2.c \
      mkwayrefine.c\
      myqsort.c\
      sfm.c\
      debug.c \
      kmetis.c  \
      mbalance2.c\
      mfm.c  \
      mmatch.c \
      ometis.c \
      srefine.c\
      estmem.c \
      kvmetis.c\
      mbalance.c \
      mincover.c  \
      mmd.c  \
      parmetis.c \
     stat.c

OBJ = ${SRC:.c=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .c

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.c${OBJEXT}:
	${CC} ${CFLAGS} ${DASH}c $<

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
balance.o: balance.c metis.h defs.h struct.h macros.h rename.h proto.h
fm.o: fm.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayfm.o: kwayfm.c metis.h defs.h struct.h macros.h rename.h proto.h
mcoarsen.o: mcoarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
minitpart2.o: minitpart2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mpmetis.o: mpmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
pmetis.o: pmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
subdomains.o: subdomains.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
bucketsort.o: bucketsort.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
fortran.o: fortran.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayrefine.o: kwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
memory.o: memory.c metis.h defs.h struct.h macros.h rename.h proto.h
minitpart.o: minitpart.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mrefine2.o: mrefine2.c metis.h defs.h struct.h macros.h rename.h proto.h
pqueue.o: pqueue.c metis.h defs.h struct.h macros.h rename.h proto.h
timing.o: timing.c metis.h defs.h struct.h macros.h rename.h proto.h
ccgraph.o: ccgraph.c metis.h defs.h struct.h macros.h rename.h proto.h
frename.o: frename.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayvolfm.o: kwayvolfm.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mesh.o: mesh.c metis.h defs.h struct.h macros.h rename.h proto.h
mkmetis.o: mkmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mrefine.o: mrefine.c metis.h defs.h struct.h macros.h rename.h proto.h
refine.o: refine.c metis.h defs.h struct.h macros.h rename.h proto.h
util.o: util.c metis.h defs.h struct.h macros.h rename.h proto.h
coarsen.o: coarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
graph.o: graph.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayvolrefine.o: kwayvolrefine.c metis.h defs.h struct.h macros.h \
  rename.h proto.h
meshpart.o: meshpart.c metis.h defs.h struct.h macros.h rename.h proto.h
mkwayfmh.o: mkwayfmh.c metis.h defs.h struct.h macros.h rename.h proto.h
mutil.o: mutil.c metis.h defs.h struct.h macros.h rename.h proto.h
separator.o: separator.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
compress.o: compress.c metis.h defs.h struct.h macros.h rename.h proto.h
initpart.o: initpart.c metis.h defs.h struct.h macros.h rename.h proto.h
match.o: match.c metis.h defs.h struct.h macros.h rename.h proto.h
mfm2.o: mfm2.c metis.h defs.h struct.h macros.h rename.h proto.h
mkwayrefine.o: mkwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
myqsort.o: myqsort.c metis.h defs.h struct.h macros.h rename.h proto.h
sfm.o: sfm.c metis.h defs.h struct.h macros.h rename.h proto.h
debug.o: debug.c metis.h defs.h struct.h macros.h rename.h proto.h
kmetis.o: kmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mbalance2.o: mbalance2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mfm.o: mfm.c metis.h defs.h struct.h macros.h rename.h proto.h
mmatch.o: mmatch.c metis.h defs.h struct.h macros.h rename.h proto.h
ometis.o: ometis.c metis.h defs.h struct.h macros.h rename.h proto.h
srefine.o: srefine.c metis.h defs.h struct.h macros.h rename.h proto.h
estmem.o: estmem.c metis.h defs.h struct.h macros.h rename.h proto.h
kvmetis.o: kvmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mbalance.o: mbalance.c metis.h defs.h struct.h macros.h rename.h proto.h
mincover.o: mincover.c metis.h defs.h struct.h macros.h rename.h proto.h
mmd.o: mmd.c metis.h defs.h struct.h macros.h rename.h proto.h
parmetis.o: parmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
stat.o: stat.c metis.h defs.h struct.h macros.h rename.h proto.h
