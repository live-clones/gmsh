# $Id: Makefile,v 1.130 2007-09-22 20:35:18 geuzaine Exp $
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

LIB     = ../lib/libGmshGraphics.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Post\
          -I../Graphics -I../Fltk -I../Numeric -I../Parser -I../Plugin\
          -I../contrib/MathEval -I../contrib/ANN/include
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      SelectBuffer.cpp \
      Iso.cpp \
      Entity.cpp \
      ReadImg.cpp \
      Scale.cpp \
      Graph2D.cpp \
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2png.cpp\
      gl2ppm.cpp\
      gl2yuv.cpp

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
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Common/GmshDefines.h Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/Context.h ../Numeric/Numeric.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
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
  ../Geo/SBoundingBox3d.h Draw.h ../Common/OS.h gl2ps.h \
  ../Common/VertexArray.h ../Common/Context.h
Geom.o: Geom.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h Draw.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Context.h gl2ps.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/Numeric.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h
Post.o: Post.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  Iso.h ../Post/PView.h ../Common/SmoothData.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Common/VertexArray.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Common/Context.h gl2ps.h
SelectBuffer.o: SelectBuffer.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/GmshDefines.h Draw.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Context.h \
  SelectBuffer.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/SBoundingBox3d.h ../Common/VertexArray.h ../Common/Context.h
Iso.o: Iso.cpp ../Numeric/Numeric.h
Entity.o: Entity.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/Context.h gl2ps.h
ReadImg.o: ReadImg.cpp ReadImg.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Post/PView.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../Common/GmshMatrix.h
Scale.o: Scale.cpp ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PView.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/PViewData.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Common/Context.h ../DataStr/List.h gl2ps.h
Graph2D.o: Graph2D.cpp ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PView.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/PViewData.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h gl2ps.h ../Common/Context.h ../DataStr/List.h
gl2ps.o: gl2ps.cpp gl2ps.h
gl2gif.o: gl2gif.cpp gl2gif.h PixelBuffer.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
gl2jpeg.o: gl2jpeg.cpp gl2jpeg.h PixelBuffer.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
gl2png.o: gl2png.cpp gl2png.h PixelBuffer.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
gl2ppm.o: gl2ppm.cpp gl2ppm.h PixelBuffer.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
gl2yuv.o: gl2yuv.cpp gl2yuv.h PixelBuffer.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
