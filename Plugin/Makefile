# $Id: Makefile,v 1.91.2.1 2006-03-10 06:35:01 geuzaine Exp $
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

LIB     = ../lib/libGmshPlugin.a
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo -I../Fltk\
          -I../Mesh -I../Numeric\
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
        SphericalRaise.cpp\
        DisplacementRaise.cpp\
	StructuralSolver.cpp\
        Skin.cpp\
        Extract.cpp ExtractElements.cpp\
        DecomposeInSimplex.cpp\
        Evaluate.cpp\
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
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  PluginManager.h CutMap.h Levelset.h CutGrid.h StreamLines.h CutPlane.h \
  CutParametric.h CutSphere.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h \
  Extract.h ExtractElements.h HarmonicToTime.h ModulusPhase.h Integrate.h \
  Gradient.h Curl.h Divergence.h Annotate.h Remove.h DecomposeInSimplex.h \
  Smooth.h Transform.h Triangulate.h SphericalRaise.h DisplacementRaise.h \
  StructuralSolver.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Common/GmshUI.h \
  Eigenvectors.h Eigenvalues.h Lambda2.h Evaluate.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  Probe.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h DecomposeInSimplex.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Graphics/Iso.h \
  ../Common/Context.h ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Smooth.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
CutParametric.o: CutParametric.cpp ../Common/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Lambda2.o: Lambda2.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Lambda2.h ../Common/Context.h ../Common/ShapeFunctions.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Eigenvectors.o: Eigenvectors.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Eigenvectors.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Numeric/EigSolve.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Eigenvalues.o: Eigenvalues.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Eigenvalues.h ../Common/Context.h \
  ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
StreamLines.o: StreamLines.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h StreamLines.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
CutGrid.o: CutGrid.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Transform.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Plugin.h ../Common/Options.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Triangulate.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ../Mesh/Utils.h \
  ../Mesh/Vertex.h ../Mesh/Mesh.h ../Mesh/Create.h ../Mesh/Vertex.h \
  ../Mesh/Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h SphericalRaise.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
DisplacementRaise.o: DisplacementRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h DisplacementRaise.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
StructuralSolver.o: StructuralSolver.cpp StructuralSolver.h ../Geo/Geo.h \
  ../DataStr/List.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  Plugin.h ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/GmshUI.h \
  ../Common/Context.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Graphics/Draw.h ../Mesh/Utils.h ../Mesh/Vertex.h \
  ../Mesh/Mesh.h ../Fltk/Shortcut_Window.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Skin.h ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Extract.h ../Common/Context.h ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
ExtractElements.o: ExtractElements.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ExtractElements.h ../Common/Context.h \
  ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
DecomposeInSimplex.o: DecomposeInSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h DecomposeInSimplex.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Common/Context.h ../DataStr/Malloc.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Evaluate.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Integrate.o: Integrate.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Integrate.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Gradient.o: Gradient.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Gradient.h ../Common/Context.h ../Common/ShapeFunctions.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Curl.o: Curl.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Curl.h ../Common/Context.h ../Common/ShapeFunctions.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Divergence.o: Divergence.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Divergence.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Annotate.o: Annotate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Annotate.h ../Common/Context.h ../Common/GmshUI.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Fltk/Colorbar_Window.h ../Fltk/Popup_Button.h ../Graphics/Draw.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Remove.o: Remove.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/GmshMatrix.h \
  Remove.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
HarmonicToTime.o: HarmonicToTime.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h HarmonicToTime.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Plugin//"
ModulusPhase.o: ModulusPhase.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ModulusPhase.h ../Common/Context.h
