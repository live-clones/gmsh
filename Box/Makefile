# $Id: Makefile,v 1.47 2008-02-21 12:42:40 geuzaine Exp $
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

LIB = ../lib/libGmshBox${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../Fltk ${DASH}I../Plugin ${DASH}I../Parallel\
      ${DASH}I../contrib/ANN/include

CFLAGS  = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Box.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} Main${OBJEXT}
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

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
Box.o: Box.cpp ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SBoundingBox3d.h ../Common/Message.h ../Common/OS.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Mesh/Generator.h \
  ../Parser/Parser.h ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Common/Context.h ../Common/Options.h ../Post/ColorTable.h \
  ../Parser/OpenFile.h ../Common/CommandLine.h ../Parser/CreateFile.h \
  ../Parallel/ParUtil.h ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Post/PView.h ../Post/PViewData.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h ../Mesh/Field.h \
  ../contrib/ANN/include/ANN/ANN.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Mesh/BackgroundMesh.h
