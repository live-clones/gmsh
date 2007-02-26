# $Id: Makefile,v 1.123 2007-02-26 08:25:37 geuzaine Exp $
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

LIB     = ../lib/libGmshFltk.a
INCLUDE = -I../Common -I../DataStr -I../Graphics -I../Geo -I../Mesh\
          -I../Numeric -I../Parser -I../Fltk -I../Plugin -I../utils/solvers\
          -I../contrib/ANN/include
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Main.cpp \
      Message.cpp \
      GUI.cpp GUI_Extras.cpp GUI_Projection.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      Solvers.cpp


OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

res:
	windres Win32Icon.rc -O coff Win32Icon.res

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
Main.o: Main.cpp GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Common/GmshUI.h ../Common/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Mesh/Generator.h ../Parser/CreateFile.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/Options.h ../Parser/Parser.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h Solvers.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h \
  ../Geo/SBoundingBox3d.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/Context.h ../Common/Options.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Common/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h GUI_Extras.h ../Common/OS.h
GUI.o: GUI.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Common/GmshDefines.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Common/Options.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Popup_Button.h SpherePosition_Widget.h Callbacks.h \
  Bitmaps.h Win32Icon.h ../Parser/OpenFile.h ../Common/CommandLine.h \
  ../Mesh/Generator.h Solvers.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h Shortcut_Window.h
GUI_Extras.o: GUI_Extras.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/GmshDefines.h File_Picker.h \
  Shortcut_Window.h ../Parser/CreateFile.h ../Common/Options.h \
  ../Common/Context.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h
GUI_Projection.o: GUI_Projection.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Common/Context.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  ../Geo/projectionFace.h ../Geo/GFace.h ../Graphics/Draw.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Options.h Shortcut_Window.h
Callbacks.o: Callbacks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Geo/GeoStringInterface.h ../Geo/Geo.h ../Geo/findLinks.h \
  ../Mesh/Generator.h ../Mesh/SecondOrder.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Common/Context.h ../Geo/ExtrudeParams.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/ExtrudeParams.h ../Geo/SBoundingBox3d.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Graphics/SelectBuffer.h ../Parser/CreateFile.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Common/Options.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Popup_Button.h SpherePosition_Widget.h GUI_Extras.h \
  Callbacks.h ../Plugin/Plugin.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Common/Visibility.h ../Common/GmshDefines.h \
  Solvers.h ../Common/OS.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Graphics/SelectBuffer.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Common/GmshUI.h ../Common/Context.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Graphics/SelectBuffer.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/MElement.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/ExtrudeParams.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/ExtrudeParams.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Common/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Common/Context.h
Solvers.o: Solvers.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Solvers.h GmshServer.h ../Parser/OpenFile.h ../Common/GmshUI.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Common/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h
