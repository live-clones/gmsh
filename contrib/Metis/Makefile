# $Id: Makefile,v 1.16 2008-02-17 08:48:09 geuzaine Exp $
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

include ../../variables

LIB     = ../../lib/libGmshMetis.a

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

.c${OBJEXT}:
	${CC} ${CFLAGS} ${DASH}c $< ${DASH}o ${<:.c=${OBJEXT}}
	if [ -r ${notdir ${<:.c=${OBJEXT}}} ]; then\
           mv -f ${notdir ${<:.c=${OBJEXT}}} ${<:.c=${OBJEXT}};\
        fi

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
