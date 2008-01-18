# $Id: Makefile,v 1.6 2008-01-18 20:41:33 geuzaine Exp $
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

LIB     = ../../lib/libGmshNR${LIBEXT}
INCLUDE = ${ISYM}../../Common ${ISYM}../../DataStr ${ISYM}../../Numeric
# don't optimize this library: there are some problems with gcc...
CFLAGS  = ${FLAGS} ${INCLUDE} ${SYSINCLUDE}

SRC = brent.cpp\
      dpythag.cpp\
      dsvdcmp.cpp\
      fdjac.cpp\
      fmin.cpp\
      lnsrch.cpp\
      lubksb.cpp\
      ludcmp.cpp\
      mnbrak.cpp\
      newt.cpp\
      nrutil.cpp

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
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
