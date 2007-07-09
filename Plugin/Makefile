# $Id: Makefile,v 1.127 2007-07-09 13:54:37 geuzaine Exp $
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

LIB     = ../lib/libGmshPlugin.a
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo -I../Mesh\
          -I../Post -I../Fltk -I../Numeric -I../contrib/ANN/include\
          -I../contrib/Triangle -I../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Plugin.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp \
        Smooth.cpp CutParametric.cpp\
        Lambda2.cpp\
        Eigenvectors.cpp Eigenvalues.cpp\
        StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
        Triangulate.cpp\
        Warp.cpp SphericalRaise.cpp\
        Skin.cpp\
        Extract.cpp ExtractElements.cpp ExtractEdges.cpp\
        MakeSimplex.cpp\
        Evaluate.cpp FieldView.cpp\
        Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp\
        Annotate.cpp Remove.cpp\
        Probe.cpp\
        HarmonicToTime.cpp ModulusPhase.cpp

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
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h PluginManager.h CutMap.h \
  Levelset.h CutGrid.h StreamLines.h CutPlane.h CutParametric.h \
  CutSphere.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h Extract.h \
  ExtractElements.h ExtractEdges.h HarmonicToTime.h ModulusPhase.h \
  Integrate.h Gradient.h Curl.h Divergence.h Annotate.h Remove.h \
  MakeSimplex.h Smooth.h Transform.h Triangulate.h Warp.h \
  SphericalRaise.h Eigenvectors.h Eigenvalues.h Lambda2.h Evaluate.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  Probe.h FieldView.h ../Common/Context.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  MakeSimplex.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Graphics/Iso.h ../Common/Context.h \
  ../DataStr/Malloc.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Post/Views.h \
  ../Post/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Post/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Post/Views.h \
  ../Post/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Post/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Smooth.h \
  ../Common/Context.h
CutParametric.o: CutParametric.cpp ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Post/Views.h \
  ../Post/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Post/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
Lambda2.o: Lambda2.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Lambda2.h \
  ../Common/Context.h ../Common/ShapeFunctions.h
Eigenvectors.o: Eigenvectors.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Eigenvectors.h ../Common/Context.h ../DataStr/Malloc.h \
  ../Numeric/EigSolve.h
Eigenvalues.o: Eigenvalues.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Eigenvalues.h ../Common/Context.h ../DataStr/Malloc.h
StreamLines.o: StreamLines.cpp ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h StreamLines.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
CutGrid.o: CutGrid.cpp ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Transform.h ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Plugin.h ../Common/Options.h ../Post/Views.h ../Post/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Triangulate.h \
  ../Common/Context.h ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/gmshFace.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/MVertex.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/ExtrudeParams.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h ../Geo/gmshVertex.h ../Geo/Geo.h \
  ../Geo/GVertex.h ../Geo/Range.h
Warp.o: Warp.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Warp.h \
  ../Common/Context.h
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  SphericalRaise.h ../Common/Context.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Skin.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Common/Context.h ../DataStr/Malloc.h
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Extract.h \
  ../Common/Context.h ../DataStr/Malloc.h
ExtractElements.o: ExtractElements.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ExtractElements.h ../Common/Context.h ../DataStr/Malloc.h
ExtractEdges.o: ExtractEdges.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ExtractEdges.h ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Mesh/BDS.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshDefines.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/MElement.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Common/Hash.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/ExtrudeParams.h \
  ../Geo/MElement.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/ExtrudeParams.h
MakeSimplex.o: MakeSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  MakeSimplex.h ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Evaluate.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Common/Context.h
FieldView.o: FieldView.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/MElement.h \
  ../Geo/MVertex.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Hash.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Context.h ../Geo/ExtrudeParams.h ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h FieldView.h \
  ../Common/ShapeFunctions.h
Integrate.o: Integrate.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Integrate.h ../Common/Context.h ../Common/ShapeFunctions.h
Gradient.o: Gradient.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Gradient.h \
  ../Common/Context.h ../Common/ShapeFunctions.h
Curl.o: Curl.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Curl.h \
  ../Common/Context.h ../Common/ShapeFunctions.h
Divergence.o: Divergence.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  Divergence.h ../Common/Context.h ../Common/ShapeFunctions.h
Annotate.o: Annotate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Annotate.h \
  ../Common/Context.h ../Common/GmshUI.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h \
  ../Graphics/Draw.h
Remove.o: Remove.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Post/Views.h ../Post/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Post/AdaptiveViews.h ../Common/GmshMatrix.h Remove.h \
  ../Common/Context.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h
HarmonicToTime.o: HarmonicToTime.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  HarmonicToTime.h ../Common/Context.h
ModulusPhase.o: ModulusPhase.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ModulusPhase.h ../Common/Context.h
