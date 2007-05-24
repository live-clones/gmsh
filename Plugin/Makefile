# $Id: Makefile,v 1.125 2007-05-24 13:58:06 remacle Exp $
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
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo -I../Fltk\
          -I../Mesh -I../Numeric -I../contrib/ANN/include\
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
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  PluginManager.h CutMap.h Levelset.h CutGrid.h StreamLines.h CutPlane.h \
  CutParametric.h CutSphere.h Skin.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h Extract.h ExtractElements.h ExtractEdges.h \
  HarmonicToTime.h ModulusPhase.h Integrate.h Gradient.h Curl.h \
  Divergence.h Annotate.h Remove.h MakeSimplex.h Smooth.h Transform.h \
  Triangulate.h Warp.h SphericalRaise.h Eigenvectors.h Eigenvalues.h \
  Lambda2.h ../Numeric/Numeric.h Evaluate.h ../Common/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h Probe.h FieldView.h \
  ../Common/Context.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h MakeSimplex.h ../DataStr/List.h \
  ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Graphics/Iso.h ../Common/Views.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/Malloc.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/GmshMatrix.h ../DataStr/List.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../DataStr/List.h ../Common/Views.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/GmshMatrix.h ../DataStr/List.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../DataStr/List.h ../Common/Views.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../DataStr/List.h ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Smooth.h ../DataStr/List.h ../Common/Context.h
CutParametric.o: CutParametric.cpp ../Common/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothData.h ../Numeric/Numeric.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/GmshMatrix.h ../DataStr/List.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../DataStr/List.h ../Common/Views.h
Lambda2.o: Lambda2.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Lambda2.h ../DataStr/List.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Eigenvectors.o: Eigenvectors.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Eigenvectors.h ../DataStr/List.h \
  ../Common/Context.h ../DataStr/Malloc.h ../Numeric/Numeric.h \
  ../Numeric/EigSolve.h
Eigenvalues.o: Eigenvalues.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Eigenvalues.h ../DataStr/List.h \
  ../Common/Context.h ../DataStr/Malloc.h ../Numeric/Numeric.h
StreamLines.o: StreamLines.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h StreamLines.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../DataStr/List.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../DataStr/List.h \
  ../Common/Views.h
CutGrid.o: CutGrid.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../DataStr/List.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../DataStr/List.h \
  ../Common/Views.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Transform.h ../DataStr/List.h \
  ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Plugin.h ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Triangulate.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/gmshFace.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/GFace.h \
  ../Geo/GPoint.h ../Geo/GEntity.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/GVertex.h ../Geo/MVertex.h ../Geo/MElement.h ../Geo/MEdge.h \
  ../Common/Hash.h ../Geo/MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../Geo/gmshVertex.h
Warp.o: Warp.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Warp.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Common/SmoothData.h
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h SphericalRaise.h ../DataStr/List.h \
  ../Common/Context.h ../Numeric/Numeric.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Skin.h ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Common/Context.h ../DataStr/Malloc.h
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Extract.h ../DataStr/List.h ../Common/Context.h ../DataStr/Malloc.h
ExtractElements.o: ExtractElements.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ExtractElements.h ../DataStr/List.h \
  ../Common/Context.h ../DataStr/Malloc.h
ExtractEdges.o: ExtractEdges.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ExtractEdges.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Mesh/BDS.h ../Geo/GFace.h ../Geo/GPoint.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/GmshDefines.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/GVertex.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/MElement.h ../Geo/MEdge.h ../Common/Hash.h \
  ../Geo/MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Geo/ExtrudeParams.h ../Common/SmoothData.h ../Geo/Pair.h \
  ../Common/Views.h
MakeSimplex.o: MakeSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h MakeSimplex.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Numeric/Numeric.h
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Evaluate.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../DataStr/List.h ../Common/Context.h \
  ../Numeric/Numeric.h
FieldView.o: FieldView.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../Mesh/Field.h ../Common/Views.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/MVertex.h \
  ../Geo/GPoint.h ../Geo/MElement.h ../Geo/MEdge.h ../Common/Hash.h \
  ../Geo/MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  FieldView.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Common/ShapeFunctions.h
Integrate.o: Integrate.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Integrate.h ../DataStr/List.h \
  ../Common/Context.h ../Numeric/Numeric.h ../Common/ShapeFunctions.h
Gradient.o: Gradient.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Gradient.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Common/ShapeFunctions.h
Curl.o: Curl.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Curl.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Common/ShapeFunctions.h
Divergence.o: Divergence.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h Divergence.h ../DataStr/List.h \
  ../Common/Context.h ../Numeric/Numeric.h ../Common/ShapeFunctions.h
Annotate.o: Annotate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Annotate.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h \
  ../Common/GmshUI.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
  ../Fltk/Colorbar_Window.h ../Common/GmshUI.h ../Common/ColorTable.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h \
  ../Graphics/Draw.h ../DataStr/List.h ../Common/Views.h
Remove.o: Remove.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshMatrix.h \
  Remove.h ../DataStr/List.h ../Common/Context.h ../Numeric/Numeric.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ../DataStr/List.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../DataStr/List.h \
  ../Common/Views.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h
HarmonicToTime.o: HarmonicToTime.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h HarmonicToTime.h ../DataStr/List.h \
  ../Common/Context.h ../Numeric/Numeric.h
ModulusPhase.o: ModulusPhase.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/GmshMatrix.h ModulusPhase.h ../DataStr/List.h \
  ../Common/Context.h ../Numeric/Numeric.h
