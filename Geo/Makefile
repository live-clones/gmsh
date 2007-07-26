# $Id: Makefile,v 1.150 2007-07-26 16:28:27 anand Exp $
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

LIB     = ../lib/libGmshGeo.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Post -I../Numeric\
          -I../Parser -I../Fltk -I../contrib/NR -I../contrib/FourierModel\
          -I../contrib/ANN/include -I../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
      FEdge.cpp FFace.cpp\
      FProjectionFace.cpp\
      GModel.cpp\
        GModelIO_Geo.cpp\
        GModelIO_Mesh.cpp\
        GModelIO_OCC.cpp\
        GModelIO_F.cpp\
        GModelIO_CGNS.cpp\
        GModelIO_MED.cpp\
      ExtrudeParams.cpp \
      Geo.cpp \
	GeoStringInterface.cpp GeoInterpolation.cpp\
      findLinks.cpp\
      MVertex.cpp \
      MElement.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

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
