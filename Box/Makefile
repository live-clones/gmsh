# $Id: Makefile,v 1.32 2006-11-25 18:55:50 geuzaine Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

LIB     = ../lib/libGmshBox.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../Plugin -I../Parallel
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Box.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} Main.o
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
Box.o: Box.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/ExtrudeParams.h ../Mesh/Generator.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Parser/Parser.h ../Common/Context.h \
  ../Common/Options.h ../Parser/OpenFile.h ../Common/CommandLine.h \
  ../Parser/CreateFile.h ../Parallel/ParUtil.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h
