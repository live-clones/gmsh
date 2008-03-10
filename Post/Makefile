# $Id: Makefile,v 1.32 2008-03-10 16:01:16 geuzaine Exp $
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

LIB = ../lib/libGmshPost${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../Plugin ${DASH}I../Fltk ${DASH}I../contrib/MathEval\
      ${DASH}I../contrib/ANN/include

CFLAGS =${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = PView.cpp\
        PViewData.cpp PViewDataIO.cpp\
          PViewDataList.cpp PViewDataListIO.cpp\
          PViewDataGModel.cpp PViewDataGModelIO.cpp\
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
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	rm -f *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
PView.o: PView.cpp PView.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h PViewOptions.h ColorTable.h PViewDataList.h \
  AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
  PViewDataGModel.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Common/VertexArray.h ../Common/Context.h ../Common/SmoothData.h \
  ../Common/StringUtils.h ../Common/Message.h
PViewData.o: PViewData.cpp PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
PViewDataIO.o: PViewDataIO.cpp ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
PViewDataList.o: PViewDataList.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/SmoothData.h ../Common/Message.h \
  ../Common/Context.h
PViewDataListIO.o: PViewDataListIO.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Message.h ../Common/Context.h
PViewDataGModel.o: PViewDataGModel.cpp PViewDataGModel.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewDataList.h \
  AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h
PViewDataGModelIO.o: PViewDataGModelIO.cpp ../Common/Message.h \
  PViewDataGModel.h PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  PViewDataList.h AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SBoundingBox3d.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/StringUtils.h
PViewOptions.o: PViewOptions.cpp PViewOptions.h ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Message.h
AdaptiveViews.o: AdaptiveViews.cpp AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h
OctreePost.o: OctreePost.cpp ../Common/Octree.h \
  ../Common/OctreeInternals.h OctreePost.h ../DataStr/List.h PView.h \
  PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewOptions.h \
  ColorTable.h PViewDataList.h AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Message.h \
  ../Common/ShapeFunctions.h
ColorTable.o: ColorTable.cpp ../Common/Message.h ColorTable.h \
  ../Common/Context.h ../DataStr/List.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
