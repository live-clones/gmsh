# $Id: Makefile,v 1.170 2008-02-23 15:30:07 geuzaine Exp $
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

LIB = ../lib/libGmshFltk${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Graphics\
      ${DASH}I../Geo ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Numeric\
      ${DASH}I../Parser ${DASH}I../Fltk ${DASH}I../Plugin ${DASH}I../utils/solvers\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/NativeFileChooser

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Main.cpp \
      Message.cpp \
      GUI.cpp\
        GUI_Extras.cpp\
        GUI_Projection.cpp\
        GUI_Classifier.cpp\
      Callbacks.cpp\
      Opengl.cpp\
      Opengl_Window.cpp\
      Colorbar_Window.cpp\
      Solvers.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} ${DASH}c $<

res:
	windres Win32Icon.rc -O coff Win32Icon.res

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
Main.o: Main.cpp GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Common/GmshUI.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Common/Message.h ../DataStr/Malloc.h \
  ../Common/OS.h ../Mesh/Generator.h ../Parser/CreateFile.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/Context.h ../DataStr/List.h ../Common/Options.h \
  ../Parser/Parser.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Parser/OpenFile.h ../Common/CommandLine.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h Solvers.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GEdge.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Mesh/BackgroundMesh.h
Message.o: Message.cpp ../Common/Message.h ../Common/GmshUI.h \
  ../Common/Context.h ../DataStr/List.h ../Common/Options.h \
  ../Post/ColorTable.h GUI.h Opengl_Window.h Colorbar_Window.h \
  Popup_Button.h SpherePosition_Widget.h GUI_Extras.h ../Common/OS.h
GUI.o: GUI.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Common/Message.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/Context.h ../DataStr/List.h ../Common/Options.h \
  ../Post/ColorTable.h ../Graphics/Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h GUI.h Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h Callbacks.h Win32Icon.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Mesh/Generator.h Solvers.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Post/PView.h \
  ../Post/PViewData.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Shortcut_Window.h
GUI_Extras.o: GUI_Extras.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Parser/CreateFile.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Context.h ../DataStr/List.h ../Graphics/Draw.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h GUI.h Opengl_Window.h \
  Colorbar_Window.h Popup_Button.h SpherePosition_Widget.h \
  Shortcut_Window.h File_Picker.h
GUI_Projection.o: GUI_Projection.cpp ../Geo/GModelIO_Fourier.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/SVector3.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MFace.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Context.h ../DataStr/List.h \
  ../Parser/OpenFile.h ../Graphics/SelectBuffer.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h GUI_Projection.h \
  ../Common/GmshUI.h ../Geo/GModel.h ../Geo/fourierProjectionFace.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h Shortcut_Window.h GUI_Extras.h \
  ../Geo/fourierFace.h ../Geo/fourierEdge.h ../Geo/fourierVertex.h \
  ../Common/Message.h
GUI_Classifier.o: GUI_Classifier.cpp GUI_Classifier.h ../Common/GmshUI.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/SVector3.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MFace.h \
  GUI.h Opengl_Window.h Colorbar_Window.h ../Post/ColorTable.h \
  Popup_Button.h SpherePosition_Widget.h Shortcut_Window.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Common/Options.h \
  ../Common/Context.h ../DataStr/List.h ../Graphics/SelectBuffer.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  GUI_Projection.h ../Geo/fourierProjectionFace.h ../Geo/GModel.h \
  GUI_Extras.h ../Common/Message.h ../Mesh/meshGFaceDelaunayInsertion.h \
  ../Mesh/meshGFaceOptimize.h ../Geo/MEdge.h \
  ../Mesh/meshGFaceDelaunayInsertion.h ../Geo/discreteEdge.h ../Geo/Geo.h \
  ../Geo/gmshSurface.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Geo/discreteFace.h
Callbacks.o: Callbacks.cpp ../Common/GmshUI.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MFace.h \
  ../Geo/GeoStringInterface.h ../DataStr/List.h ../Geo/findLinks.h \
  ../Mesh/Generator.h ../Mesh/HighOrder.h ../Graphics/Draw.h \
  ../Geo/SBoundingBox3d.h ../Graphics/SelectBuffer.h ../Geo/GVertex.h \
  ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h ../Post/PView.h \
  ../Post/PViewData.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Parser/CreateFile.h ../Parser/OpenFile.h ../Common/CommandLine.h \
  ../Common/Context.h ../Common/Options.h ../Post/ColorTable.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h GUI_Extras.h Callbacks.h ../Plugin/Plugin.h \
  ../Post/PViewDataList.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Visibility.h \
  ../Common/GmshDefines.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h Solvers.h ../Common/OS.h ../Mesh/Field.h \
  ../Geo/Geo.h ../Geo/gmshSurface.h ../DataStr/Tree.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h ../Mesh/BackgroundMesh.h
Opengl.o: Opengl.cpp ../Common/GmshUI.h ../Common/GmshDefines.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Context.h \
  ../DataStr/List.h ../Graphics/Draw.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Graphics/SelectBuffer.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/GFace.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/Pair.h \
  ../Geo/GRegion.h GUI.h Opengl_Window.h Colorbar_Window.h \
  ../Post/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/GmshUI.h \
  ../Common/GmshDefines.h ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Context.h ../DataStr/List.h \
  ../Graphics/Draw.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Graphics/SelectBuffer.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/GEdge.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/GFace.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/Pair.h ../Geo/GRegion.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MFace.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/GmshUI.h GUI.h \
  Opengl_Window.h Colorbar_Window.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Common/Context.h ../DataStr/List.h
Solvers.o: Solvers.cpp ../Common/Message.h Solvers.h GmshServer.h \
  ../Parser/OpenFile.h ../Common/GmshUI.h GUI.h Opengl_Window.h \
  Colorbar_Window.h ../Post/ColorTable.h Popup_Button.h \
  SpherePosition_Widget.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Graphics/Draw.h ../Common/Context.h \
  ../DataStr/List.h
