# $Id: Makefile,v 1.177 2008-06-07 17:20:44 geuzaine Exp $
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

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
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
      Message.cpp\
      Visibility.cpp\
      Trackball.cpp\
      VertexArray.cpp\
      SmoothData.cpp\
      StringUtils.cpp\
      ListUtils.cpp\
      TreeUtils.cpp\
      MallocUtils.cpp\
      License.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} Main${OBJEXT}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

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
  ../Mesh/Generator.h Context.h Options.h ../Post/ColorTable.h \
  ../Mesh/BackgroundMesh.h ../Post/PView.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewData.h ../Post/adaptiveData.h \
  ../Common/ListUtils.h ../Common/GmshMatrix.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Fltk/Solvers.h \
  ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h \
  ../Common/GmshUI.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h
CommandLine.o: CommandLine.cpp GmshUI.h GmshDefines.h GmshVersion.h \
  Message.h ../Parser/OpenFile.h CommandLine.h Context.h Options.h \
  ../Post/ColorTable.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SBoundingBox3d.h ../Parser/CreateFile.h OS.h ../Post/PView.h
Gmsh.o: Gmsh.cpp GmshDefines.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h Message.h \
  ../Parser/Parser.h ../Common/ListUtils.h ../Common/TreeUtils.h \
  ../Common/avl.h ../Common/ListUtils.h ../Parser/OpenFile.h \
  ../Parser/CreateFile.h Options.h ../Post/ColorTable.h CommandLine.h \
  OS.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Mesh/Generator.h ../Mesh/Field.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Post/PView.h Context.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Common/GmshMatrix.h
OS.o: OS.cpp Message.h
Message.o: Message.cpp Message.h Options.h ../Post/ColorTable.h Context.h \
  OS.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h \
  ../Common/GmshUI.h ../Fltk/Popup_Button.h \
  ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/ListUtils.h \
  ../Common/TreeUtils.h ../Common/avl.h ../Common/ListUtils.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Post/PView.h ../Fltk/GUI_Extras.h
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
  ../Common/ListUtils.h ../Common/TreeUtils.h ../Common/avl.h \
  ../Common/ListUtils.h
Trackball.o: Trackball.cpp Trackball.h
VertexArray.o: VertexArray.cpp VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h Context.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SmoothData.o: SmoothData.cpp SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
StringUtils.o: StringUtils.cpp StringUtils.h
ListUtils.o: ListUtils.cpp MallocUtils.h ListUtils.h TreeUtils.h avl.h \
  Message.h
TreeUtils.o: TreeUtils.cpp MallocUtils.h TreeUtils.h avl.h ListUtils.h \
  Message.h
MallocUtils.o: MallocUtils.cpp MallocUtils.h Message.h
License.o: License.cpp Message.h
