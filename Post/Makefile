# $Id: Makefile,v 1.15 2007-09-11 15:29:02 geuzaine Exp $
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

LIB     = ../lib/libGmshPost.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Post\
          -I../Graphics -I../Numeric -I../Parser -I../Plugin -I../Fltk\
          -I../contrib/MathEval -I../contrib/ANN/include/
CFLAGS  =${OPTIM} ${FLAGS} ${INCLUDE}

SRC = PView.cpp\
        PViewData.cpp\
          PViewDataList.cpp PViewDataListIO.cpp\
          PViewDataGModel.cpp\
        PViewOptions.cpp\
      AdaptiveViews.cpp\
      OctreePost.cpp\
      ColorTable.cpp

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
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
PView.o: PView.cpp PView.h ../Common/VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewOptions.h \
  ColorTable.h PViewDataList.h AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Common/Message.h
PViewData.o: PViewData.cpp PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
PViewDataList.o: PViewDataList.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Common/SmoothData.h ../Common/Message.h ../Common/Context.h
PViewDataListIO.o: PViewDataListIO.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Common/Message.h ../Common/Context.h
PViewDataGModel.o: PViewDataGModel.cpp PViewDataGModel.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewDataList.h \
  AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Common/Context.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h
PViewOptions.o: PViewOptions.cpp PViewOptions.h ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Message.h
AdaptiveViews.o: AdaptiveViews.cpp AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../Common/OS.h
OctreePost.o: OctreePost.cpp ../Common/Octree.h \
  ../Common/OctreeInternals.h OctreePost.h ../DataStr/List.h PView.h \
  ../Common/VertexArray.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewOptions.h ColorTable.h \
  PViewDataList.h AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Message.h ../Common/ShapeFunctions.h
ColorTable.o: ColorTable.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ColorTable.h ../Common/Context.h ../Numeric/Numeric.h
