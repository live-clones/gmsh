# $Id: Makefile,v 1.161 2008-07-10 13:34:41 geuzaine Exp $
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

LIB = ../lib/libGmshParser${LIBEXT}

INC = ${DASH}I../Parser ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Fltk\
      ${DASH}I../Plugin ${DASH}I../contrib/ANN/include 

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Gmsh.tab.cpp\
      Gmsh.yy.cpp\
      FunctionManager.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

# Don't optimize Gmsh.tab.o: on many architectures, g++ -O2 generates
# assembly code too large to be addressed correctly
Gmsh.tab${OBJEXT}:
	${CXX} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}c Gmsh.tab.cpp

parser:
	bison -p gmsh_yy --output Gmsh.tab.cpp -d Gmsh.y 
	if [ -r Gmsh.tab.cpp.h ]; then mv Gmsh.tab.cpp.h Gmsh.tab.hpp ; fi
	flex -P gmsh_yy -oGmsh.yy.cpp Gmsh.l

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
Gmsh.tab.o: Gmsh.tab.cpp ../Common/Message.h ../Common/MallocUtils.h \
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/Context.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GeoInterpolation.h ../Geo/Geo.h \
  ../Mesh/Generator.h ../Graphics/Draw.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Colors.h ../Common/Options.h Parser.h \
  ../Common/OpenFile.h ../Common/CommandLine.h FunctionManager.h \
  ../Common/OS.h ../Common/CreateFile.h ../Mesh/Field.h ../Post/PView.h \
  ../Mesh/BackgroundMesh.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/GmshMatrix.h
Gmsh.yy.o: Gmsh.yy.cpp ../Common/Message.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  Gmsh.tab.hpp
FunctionManager.o: FunctionManager.cpp FunctionManager.h
