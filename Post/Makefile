# $Id: Makefile,v 1.19 2008-01-18 20:02:29 geuzaine Exp $
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

LIB     = ../lib/libGmshPost${LIBEXT}
INCLUDE = ${ISYM}../Common ${ISYM}../DataStr ${ISYM}../Geo ${ISYM}../Mesh\
          ${ISYM}../Post ${ISYM}../Graphics ${ISYM}../Numeric ${ISYM}../Parser\
          ${ISYM}../Plugin ${ISYM}../Fltk ${ISYM}../contrib/MathEval\
          ${ISYM}../contrib/ANN/include
CFLAGS  =${OPTIM} ${FLAGS} ${INCLUDE} ${SYSINCLUDE}

SRC = PView.cpp\
        PViewData.cpp\
          PViewDataList.cpp PViewDataListIO.cpp\
          PViewDataGModel.cpp\
        PViewOptions.cpp\
      AdaptiveViews.cpp\
      OctreePost.cpp\
      ColorTable.cpp

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
