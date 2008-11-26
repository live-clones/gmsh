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
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
balance${OBJEXT}: balance.c metis.h defs.h struct.h macros.h rename.h proto.h
fm${OBJEXT}: fm.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayfm${OBJEXT}: kwayfm.c metis.h defs.h struct.h macros.h rename.h proto.h
mcoarsen${OBJEXT}: mcoarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
minitpart2${OBJEXT}: minitpart2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mpmetis${OBJEXT}: mpmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
pmetis${OBJEXT}: pmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
subdomains${OBJEXT}: subdomains.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
bucketsort${OBJEXT}: bucketsort.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
fortran${OBJEXT}: fortran.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayrefine${OBJEXT}: kwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
memory${OBJEXT}: memory.c metis.h defs.h struct.h macros.h rename.h proto.h
minitpart${OBJEXT}: minitpart.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mrefine2${OBJEXT}: mrefine2.c metis.h defs.h struct.h macros.h rename.h proto.h
pqueue${OBJEXT}: pqueue.c metis.h defs.h struct.h macros.h rename.h proto.h
timing${OBJEXT}: timing.c metis.h defs.h struct.h macros.h rename.h proto.h
ccgraph${OBJEXT}: ccgraph.c metis.h defs.h struct.h macros.h rename.h proto.h
frename${OBJEXT}: frename.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayvolfm${OBJEXT}: kwayvolfm.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mesh${OBJEXT}: mesh.c metis.h defs.h struct.h macros.h rename.h proto.h
mkmetis${OBJEXT}: mkmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mrefine${OBJEXT}: mrefine.c metis.h defs.h struct.h macros.h rename.h proto.h
refine${OBJEXT}: refine.c metis.h defs.h struct.h macros.h rename.h proto.h
util${OBJEXT}: util.c metis.h defs.h struct.h macros.h rename.h proto.h
coarsen${OBJEXT}: coarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
graph${OBJEXT}: graph.c metis.h defs.h struct.h macros.h rename.h proto.h
kwayvolrefine${OBJEXT}: kwayvolrefine.c metis.h defs.h struct.h macros.h \
  rename.h proto.h
meshpart${OBJEXT}: meshpart.c metis.h defs.h struct.h macros.h rename.h proto.h
mkwayfmh${OBJEXT}: mkwayfmh.c metis.h defs.h struct.h macros.h rename.h proto.h
mutil${OBJEXT}: mutil.c metis.h defs.h struct.h macros.h rename.h proto.h
separator${OBJEXT}: separator.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
compress${OBJEXT}: compress.c metis.h defs.h struct.h macros.h rename.h proto.h
initpart${OBJEXT}: initpart.c metis.h defs.h struct.h macros.h rename.h proto.h
match${OBJEXT}: match.c metis.h defs.h struct.h macros.h rename.h proto.h
mfm2${OBJEXT}: mfm2.c metis.h defs.h struct.h macros.h rename.h proto.h
mkwayrefine${OBJEXT}: mkwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
myqsort${OBJEXT}: myqsort.c metis.h defs.h struct.h macros.h rename.h proto.h
sfm${OBJEXT}: sfm.c metis.h defs.h struct.h macros.h rename.h proto.h
debug${OBJEXT}: debug.c metis.h defs.h struct.h macros.h rename.h proto.h
kmetis${OBJEXT}: kmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mbalance2${OBJEXT}: mbalance2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
mfm${OBJEXT}: mfm.c metis.h defs.h struct.h macros.h rename.h proto.h
mmatch${OBJEXT}: mmatch.c metis.h defs.h struct.h macros.h rename.h proto.h
ometis${OBJEXT}: ometis.c metis.h defs.h struct.h macros.h rename.h proto.h
srefine${OBJEXT}: srefine.c metis.h defs.h struct.h macros.h rename.h proto.h
estmem${OBJEXT}: estmem.c metis.h defs.h struct.h macros.h rename.h proto.h
kvmetis${OBJEXT}: kvmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
mbalance${OBJEXT}: mbalance.c metis.h defs.h struct.h macros.h rename.h proto.h
mincover${OBJEXT}: mincover.c metis.h defs.h struct.h macros.h rename.h proto.h
mmd${OBJEXT}: mmd.c metis.h defs.h struct.h macros.h rename.h proto.h
parmetis${OBJEXT}: parmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
stat${OBJEXT}: stat.c metis.h defs.h struct.h macros.h rename.h proto.h
