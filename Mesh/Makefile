# $Id: Makefile,v 1.190 2008-01-18 20:02:28 geuzaine Exp $
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

LIB     = ../lib/libGmshMesh${OBJEXT}
INCLUDE = ${ISYM}../Numeric ${ISYM}../Common ${ISYM}../DataStr ${ISYM}../Geo\
          ${ISYM}../Mesh ${ISYM}../Post ${ISYM}../Graphics ${ISYM}../Parser\
          ${ISYM}../Fltk ${ISYM}../contrib/NR ${ISYM}../contrib/Triangle\
          ${ISYM}../contrib/Tetgen ${ISYM}../contrib/Netgen\
          ${ISYM}../contrib/Netgen/libsrc/include\
          ${ISYM}../contrib/Netgen/libsrc/interface\
          ${ISYM}../contrib/ANN/include ${ISYM}../contrib/Metis\
          ${ISYM}../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} ${SYSINCLUDE}

SRC = Generator.cpp \
      Field.cpp\
        meshGEdge.cpp \
        meshGEdgeExtruded.cpp \
        meshGFace.cpp \
        meshGFaceTransfinite.cpp \
        meshGFaceExtruded.cpp \
        meshGFaceDelaunayInsertion.cpp \
        meshGFaceOptimize.cpp \
        meshGRegion.cpp \
        meshGRegionDelaunayInsertion.cpp \
        meshGRegionTransfinite.cpp \
        meshGRegionExtruded.cpp \
        meshGRegionCarveHole.cpp \
	meshGRegionLocalMeshMod.cpp\
        DivideAndConquer.cpp \
        BackgroundMesh.cpp \
        qualityMeasures.cpp \
        BoundaryLayer.cpp \
        BDS.cpp \
        HighOrder.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${CSYM} $<

# Don't optimize BDS: it crashes with some flavors of gcc 4.1 (e.g. on debian etch)
BDS.o:
	${CXX} ${FLAGS} ${INCLUDE} ${SYSINCLUDE} ${CSYM} BDS.cpp

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
