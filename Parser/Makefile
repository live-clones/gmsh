# $Id: Makefile,v 1.144 2008-03-18 08:41:26 remacle Exp $
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

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Fltk\
      ${DASH}I../Plugin ${DASH}I../Parallel ${DASH}I../contrib/ANN/include 

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Gmsh.tab.cpp\
      Gmsh.yy.cpp\
      OpenFile.cpp\
      CreateFile.cpp\
      FunctionManager.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

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
Gmsh.tab.o: Gmsh.tab.cpp ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../Parallel/ParUtil.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Context.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Numeric/Numeric.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Post/PView.h ../Geo/Geo.h ../Geo/GeoInterpolation.h ../Geo/Geo.h \
  ../Mesh/Generator.h ../Graphics/Draw.h ../Geo/SBoundingBox3d.h \
  ../Post/PView.h ../Post/PViewDataList.h ../Common/Options.h \
  ../Common/Colors.h ../Common/Options.h Parser.h ../DataStr/List.h \
  ../DataStr/Tree.h OpenFile.h ../Common/CommandLine.h FunctionManager.h \
  ../Post/ColorTable.h ../Common/OS.h CreateFile.h ../Geo/gmshSurface.h \
  ../Mesh/Field.h ../Mesh/BackgroundMesh.h
Gmsh.yy.o: Gmsh.yy.cpp ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SBoundingBox3d.h \
  ../Numeric/Numeric.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  Gmsh.tab.hpp
OpenFile.o: OpenFile.cpp ../Common/Message.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/GRegion.h \
  ../Mesh/Field.h ../Geo/Geo.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Numeric/Numeric.h ../Common/Context.h Parser.h ../DataStr/List.h \
  ../DataStr/Tree.h OpenFile.h ../Common/CommandLine.h ../Post/PView.h \
  ../Graphics/ReadImg.h ../Common/OS.h ../Mesh/HighOrder.h \
  ../Geo/GModel.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../Geo/SBoundingBox3d.h ../Graphics/SelectBuffer.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h ../Common/GmshUI.h \
  ../Post/ColorTable.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h
CreateFile.o: CreateFile.cpp ../Common/Message.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Common/GmshDefines.h OpenFile.h \
  ../Common/Context.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/GmshUI.h ../Graphics/gl2ps.h ../Graphics/gl2gif.h \
  ../Graphics/PixelBuffer.h ../Common/GmshUI.h ../Common/Message.h \
  ../DataStr/Malloc.h ../Graphics/Draw.h ../Geo/SBoundingBox3d.h \
  ../Graphics/gl2jpeg.h ../Graphics/gl2png.h ../Graphics/gl2ppm.h \
  ../Graphics/gl2yuv.h
FunctionManager.o: FunctionManager.cpp FunctionManager.h
