# $Id: Makefile,v 1.167 2008-04-06 07:51:36 geuzaine Exp $
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

LIB = ../lib/libGmshCommon${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../Plugin ${DASH}I../Fltk ${DASH}I../contrib/MathEval\
      ${DASH}I../contrib/ANN/include

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Context.cpp\
      Octree.cpp OctreeInternals.cpp\
      Options.cpp\
      CommandLine.cpp\
      Gmsh.cpp\
      OS.cpp\
      Visibility.cpp\
      Trackball.cpp\
      VertexArray.cpp\
      SmoothData.cpp\
      StringUtils.cpp\
      License.cpp

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
Context.o: Context.cpp ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  Context.h DefaultOptions.h GmshDefines.h Options.h ../Post/ColorTable.h \
  Trackball.h
Octree.o: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals.o: OctreeInternals.cpp Message.h OctreeInternals.h
Options.o: Options.cpp GmshUI.h GmshDefines.h Message.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PView.h ../Post/PViewData.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Mesh/Generator.h Context.h Options.h \
  ../Mesh/BackgroundMesh.h ../Plugin/PluginManager.h ../Plugin/Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Fltk/Solvers.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h ../Common/GmshUI.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h
CommandLine.o: CommandLine.cpp GmshUI.h GmshDefines.h GmshVersion.h \
  Message.h ../Parser/OpenFile.h CommandLine.h Context.h Options.h \
  ../Post/ColorTable.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SBoundingBox3d.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Parser/CreateFile.h OS.h
Gmsh.o: Gmsh.cpp ../Parser/Parser.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h Options.h ../Post/ColorTable.h CommandLine.h OS.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
OS.o: OS.cpp Message.h
Visibility.o: Visibility.cpp Visibility.h GmshDefines.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Geo/SBoundingBox3d.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Parser/Parser.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h
Trackball.o: Trackball.cpp Trackball.h
VertexArray.o: VertexArray.cpp VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h Context.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SmoothData.o: SmoothData.cpp SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
StringUtils.o: StringUtils.cpp StringUtils.h
License.o: License.cpp Message.h
