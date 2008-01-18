# $Id: Makefile,v 1.145 2008-01-18 20:02:27 geuzaine Exp $
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

include ../variables

LIB     = ../lib/libGmshCommon${LIBEXT}
INCLUDE = ${ISYM}../Common ${ISYM}../DataStr ${ISYM}../Geo ${ISYM}../Mesh\
          ${ISYM}../Post ${ISYM}../Graphics ${ISYM}../Numeric ${ISYM}../Parser\
          ${ISYM}../Plugin ${ISYM}../Fltk ${ISYM}../contrib/MathEval\
          ${ISYM}../contrib/ANN/include
CFLAGS  =${OPTIM} ${FLAGS} ${INCLUDE} ${SYSINCLUDE}

SRC = Context.cpp\
      Octree.cpp OctreeInternals.cpp\
      Options.cpp\
      CommandLine.cpp\
      OS.cpp\
      Visibility.cpp\
      Trackball.cpp\
      VertexArray.cpp\
      SmoothData.cpp\
      License.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${CSYM} $<

clean:
	rm -f *${OBJEXT}

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
