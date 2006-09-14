# $Id: Makefile,v 1.106 2006-09-14 15:23:28 remacle Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
      GUI.cpp GUI_Extras.cpp\
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
Main.o: Main.cpp GUI.h Opengl_Window.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  Colorbar_Window.h ../Common/GmshUI.h ../Common/ColorTable.h \
  Popup_Button.h SpherePosition_Widget.h ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Geo/Geo.h ../Parser/CreateFile.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gsl/gsl_linalg.h \
  gsl/gsl_matrix.h gsl/gsl_vector.h gsl/gsl_blas.h ../Common/Context.h \
  ../Common/Options.h ../Parser/Parser.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h Solvers.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Geo/gmshModel.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/SBoundingBox3d.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Common/Context.h ../Common/Options.h GUI.h \
  Opengl_Window.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Colorbar_Window.h \
  ../Common/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  GUI_Extras.h ../Common/OS.h
GUI.o: GUI.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Common/GmshUI.h \
  ../Numeric/Numeric.h ../Common/Context.h ../Common/Options.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gsl/gsl_linalg.h \
  gsl/gsl_matrix.h gsl/gsl_vector.h gsl/gsl_blas.h GUI.h Opengl_Window.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Colorbar_Window.h \
  Popup_Button.h SpherePosition_Widget.h Callbacks.h Bitmaps.h \
  Win32Icon.h ../Parser/OpenFile.h ../Common/CommandLine.h Solvers.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h Shortcut_Window.h
GUI_Extras.o: GUI_Extras.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h File_Picker.h \
  Shortcut_Window.h ../Parser/CreateFile.h ../Common/Options.h \
  ../Common/Context.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gsl/gsl_linalg.h \
  gsl/gsl_matrix.h gsl/gsl_vector.h gsl/gsl_blas.h
Callbacks.o: Callbacks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Common/GmshDefines.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h ../Geo/ExtrudeParams.h ../Geo/ExtractContour.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gsl/gsl_linalg.h \
  gsl/gsl_matrix.h gsl/gsl_vector.h gsl/gsl_blas.h \
  ../Graphics/SelectBuffer.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Context.h \
  ../Geo/GFace.h ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/MElement.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Parser/CreateFile.h \
  ../Parser/OpenFile.h ../Common/CommandLine.h ../Common/Options.h GUI.h \
  Opengl_Window.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h GUI_Extras.h Callbacks.h ../Plugin/Plugin.h \
  ../Plugin/PluginManager.h ../Plugin/Plugin.h ../Common/Visibility.h \
  ../Common/GmshDefines.h Solvers.h ../Common/OS.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEdge.h ../Geo/GFace.h ../Geo/GRegion.h \
  ../Geo/SBoundingBox3d.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Common/GmshUI.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Geo/Geo.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h gsl/gsl_linalg.h gsl/gsl_matrix.h \
  gsl/gsl_vector.h gsl/gsl_blas.h ../Graphics/SelectBuffer.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h GUI.h \
  Opengl_Window.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h ../Graphics/gl2ps.h
Opengl_Window.o: Opengl_Window.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Common/GmshUI.h ../Common/Context.h \
  ../Geo/Geo.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h gsl/gsl_linalg.h gsl/gsl_matrix.h \
  gsl/gsl_vector.h gsl/gsl_blas.h ../Graphics/SelectBuffer.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/MElement.h GUI.h \
  Opengl_Window.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h Colorbar_Window.h Popup_Button.h \
  SpherePosition_Widget.h
Colorbar_Window.o: Colorbar_Window.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/GmshUI.h GUI.h Opengl_Window.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Colorbar_Window.h \
  ../Common/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Common/Context.h
Solvers.o: Solvers.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Solvers.h GmshServer.h ../Parser/OpenFile.h ../Common/GmshUI.h GUI.h \
  Opengl_Window.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Colorbar_Window.h \
  ../Common/ColorTable.h Popup_Button.h SpherePosition_Widget.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h gsl/gsl_linalg.h \
  gsl/gsl_matrix.h gsl/gsl_vector.h gsl/gsl_blas.h ../Common/Context.h
