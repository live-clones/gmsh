# $Id: Makefile,v 1.211 2008-06-05 13:58:43 geuzaine Exp $
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

include ../variables

LIB = ../lib/libGmshGeo${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Numeric ${DASH}I../Parser ${DASH}I../Fltk\
      ${DASH}I../contrib/NR ${DASH}I../contrib/ANN/include\
      ${DASH}I../contrib/MathEval

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = GEntity.cpp\
      GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
      gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp\
      OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp\
      discreteEdge.cpp discreteFace.cpp discreteRegion.cpp\
      fourierEdge.cpp fourierFace.cpp fourierProjectionFace.cpp\
      GModel.cpp\
        GModelIO_Geo.cpp\
        GModelIO_Mesh.cpp\
        GModelIO_OCC.cpp\
        GModelIO_Fourier.cpp\
        GModelIO_CGNS.cpp\
        GModelIO_MED.cpp\
      ExtrudeParams.cpp \
      Geo.cpp \
	GeoStringInterface.cpp GeoInterpolation.cpp\
      findLinks.cpp\
      MVertex.cpp\
      GaussQuadratureTri.cpp\
      GaussQuadratureQuad.cpp\
      GaussQuadratureTet.cpp\
      GaussQuadratureHex.cpp\
      GaussLegendreSimplex.cpp\
      MFace.cpp\
      MElement.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

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
