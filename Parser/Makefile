# $Id: Makefile,v 1.120 2007-05-24 13:58:06 remacle Exp $
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

LIB     = ../lib/libGmshParser.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Numeric -I../Fltk -I../Plugin -I../Parallel\
          -I../contrib/ANN/include 
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Gmsh.tab.cpp\
      Gmsh.yy.cpp\
      OpenFile.cpp\
      CreateFile.cpp\
      FunctionManager.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

# Don't optimize Gmsh.tab.o: on many architectures, g++ -O2 generates
# assembly code too large to be addressed correctly
Gmsh.tab.o:
	${CXX} ${FLAGS} ${INCLUDE} -c $<

# Don't do this: it would be triggered when we check out a new version via CVS
# Gmsh.tab.cpp: Gmsh.y
#	bison --output Gmsh.tab.cpp -d Gmsh.y 
#	if [ -r Gmsh.tab.cpp.h ]; then mv Gmsh.tab.cpp.h Gmsh.tab.hpp ; fi
#
# Gmsh.yy.cpp: Gmsh.l
#	flex -oGmsh.yy.cpp Gmsh.l
#
# parser: Gmsh.yy.cpp Gmsh.tab.cpp

parser:
	bison --output Gmsh.tab.cpp -d Gmsh.y 
	if [ -r Gmsh.tab.cpp.h ]; then mv Gmsh.tab.cpp.h Gmsh.tab.hpp ; fi
	flex -oGmsh.yy.cpp Gmsh.l

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
Gmsh.tab.o: Gmsh.tab.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/GmshMatrix.h ../Parallel/ParUtil.h \
  ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/MElement.h ../Geo/MEdge.h ../Common/Hash.h \
  ../Geo/MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/Geo.h \
  ../Geo/gmshSurface.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/GeoInterpolation.h ../Geo/Geo.h ../Mesh/Generator.h \
  ../Graphics/Draw.h ../DataStr/List.h ../Common/Views.h \
  ../Common/Views.h ../Common/Options.h ../Common/Colors.h \
  ../Common/Options.h Parser.h ../DataStr/List.h ../DataStr/Tree.h \
  OpenFile.h ../Common/CommandLine.h FunctionManager.h \
  ../Common/ColorTable.h ../Common/OS.h CreateFile.h ../Geo/gmshSurface.h \
  ../Mesh/Field.h ../Common/Views.h ../Geo/Geo.h ../Geo/GEdge.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Mesh/BackgroundMesh.h
Gmsh.yy.o: Gmsh.yy.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SBoundingBox3d.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h Gmsh.tab.hpp
OpenFile.o: OpenFile.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/GPoint.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/MEdge.h \
  ../Common/Hash.h ../Geo/MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/GRegion.h \
  ../Numeric/Numeric.h ../Common/Context.h Parser.h ../DataStr/List.h \
  ../DataStr/Tree.h OpenFile.h ../Common/CommandLine.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Graphics/ReadImg.h \
  ../Common/OS.h ../Mesh/HighOrder.h ../Geo/GModel.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../DataStr/List.h ../Common/Views.h \
  ../Graphics/SelectBuffer.h ../Geo/GVertex.h ../Geo/GEdge.h \
  ../Geo/GFace.h ../Geo/GRegion.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
  ../Fltk/Colorbar_Window.h ../Common/GmshUI.h ../Common/ColorTable.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h
CreateFile.o: CreateFile.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  OpenFile.h ../Common/Context.h ../Common/Options.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/GPoint.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/MEdge.h \
  ../Common/Hash.h ../Geo/MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/GRegion.h \
  ../Common/GmshUI.h ../Graphics/gl2ps.h ../Graphics/gl2gif.h \
  ../Graphics/PixelBuffer.h ../Common/Gmsh.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../DataStr/List.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Graphics/gl2jpeg.h \
  ../Graphics/gl2png.h ../Graphics/gl2ppm.h ../Graphics/gl2yuv.h
FunctionManager.o: FunctionManager.cpp FunctionManager.h
