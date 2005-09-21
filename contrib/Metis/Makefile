# $Id: Makefile,v 1.2 2005-09-21 18:09:21 geuzaine Exp $
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

include ../../variables

LIB     = ../../lib/libGmshMetis.a
INCLUDE = -I.
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

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

OBJ = ${SRC:.c=.o}

.SUFFIXES: .o .c

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

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
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
balance.o: balance.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
fm.o: fm.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kwayfm.o: kwayfm.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mcoarsen.o: mcoarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
minitpart2.o: minitpart2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mpmetis.o: mpmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
pmetis.o: pmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
subdomains.o: subdomains.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
bucketsort.o: bucketsort.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
fortran.o: fortran.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kwayrefine.o: kwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
memory.o: memory.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
minitpart.o: minitpart.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mrefine2.o: mrefine2.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
pqueue.o: pqueue.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
timing.o: timing.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
ccgraph.o: ccgraph.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
frename.o: frename.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kwayvolfm.o: kwayvolfm.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mesh.o: mesh.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mkmetis.o: mkmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mrefine.o: mrefine.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
refine.o: refine.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
util.o: util.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
coarsen.o: coarsen.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
graph.o: graph.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kwayvolrefine.o: kwayvolrefine.c metis.h defs.h struct.h macros.h \
  rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
meshpart.o: meshpart.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mkwayfmh.o: mkwayfmh.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mutil.o: mutil.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
separator.o: separator.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
compress.o: compress.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
initpart.o: initpart.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
match.o: match.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mfm2.o: mfm2.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mkwayrefine.o: mkwayrefine.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
myqsort.o: myqsort.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
sfm.o: sfm.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
debug.o: debug.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kmetis.o: kmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mbalance2.o: mbalance2.c metis.h defs.h struct.h macros.h rename.h \
  proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mfm.o: mfm.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mmatch.o: mmatch.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
ometis.o: ometis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
srefine.o: srefine.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
estmem.o: estmem.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
kvmetis.o: kvmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mbalance.o: mbalance.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mincover.o: mincover.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
mmd.o: mmd.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
parmetis.o: parmetis.c metis.h defs.h struct.h macros.h rename.h proto.h
# 1 "/Users/geuzaine/.gmsh/contrib/Metis//"
stat.o: stat.c metis.h defs.h struct.h macros.h rename.h proto.h
