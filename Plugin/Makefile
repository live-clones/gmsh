# $Id: Makefile,v 1.75 2005-01-01 19:35:39 geuzaine Exp $
#
# Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
            -I../Mesh -I../Numeric -I../Triangle -I../MathEval
CFLAGS  = -DMPICH_SKIP_MPICXX ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Plugin.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp \
        Smooth.cpp CutParametric.cpp\
        Lambda2.cpp\
        Eigenvectors.cpp\
	Octree.cpp OctreeInternals.cpp OctreePost.cpp\
          StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
        Triangulate.cpp\
        SphericalRaise.cpp\
        DisplacementRaise.cpp\
	StructuralSolver.cpp\
        Skin.cpp\
        Extract.cpp\
        DecomposeInSimplex.cpp\
        Evaluate.cpp\
        Integrate.cpp\
        Annotate.cpp Remove.cpp\
        Probe.cpp\
        HarmonicToTime.cpp

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
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h PluginManager.h \
  CutMap.h Levelset.h CutGrid.h StreamLines.h CutPlane.h CutParametric.h \
  CutSphere.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h Extract.h \
  HarmonicToTime.h Integrate.h Annotate.h Remove.h DecomposeInSimplex.h \
  Smooth.h Transform.h Triangulate.h SphericalRaise.h DisplacementRaise.h \
  StructuralSolver.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Common/GmshUI.h Eigenvectors.h Lambda2.h ../Numeric/Numeric.h \
  Evaluate.h Probe.h ../Common/Context.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h DecomposeInSimplex.h \
  ../DataStr/Tools.h ../DataStr/Tree.h ../DataStr/avl.h ../Graphics/Iso.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/Malloc.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Smooth.h \
  ../Common/Context.h
CutParametric.o: CutParametric.cpp OctreePost.h Octree.h \
  OctreeInternals.h CutParametric.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/Context.h
Lambda2.o: Lambda2.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Lambda2.h \
  ../Numeric/Numeric.h ../Common/Context.h ShapeFunctions.h
Eigenvectors.o: Eigenvectors.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Eigenvectors.h \
  ../Common/Context.h ../DataStr/Malloc.h ../Numeric/Numeric.h \
  ../Numeric/EigSolve.h
Octree.o: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals.o: OctreeInternals.cpp ../Common/Message.h \
  OctreeInternals.h
OctreePost.o: OctreePost.cpp Octree.h OctreeInternals.h OctreePost.h \
  ../DataStr/List.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Numeric/Numeric.h \
  ../Common/Message.h
StreamLines.o: StreamLines.cpp OctreePost.h Octree.h OctreeInternals.h \
  StreamLines.h Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h
CutGrid.o: CutGrid.cpp OctreePost.h Octree.h OctreeInternals.h CutGrid.h \
  Plugin.h ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Transform.h \
  ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Plugin.h ../Common/Options.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h Triangulate.h ../Common/Context.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/STL.h ../Mesh/Metric.h ../Mesh/Matrix.h ../Mesh/Utils.h \
  ../Mesh/Create.h
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h SphericalRaise.h \
  ../Common/Context.h ../Numeric/Numeric.h
DisplacementRaise.o: DisplacementRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h DisplacementRaise.h \
  ../Common/Context.h ../Numeric/Numeric.h
StructuralSolver.o: StructuralSolver.cpp StructuralSolver.h ../Geo/Geo.h \
  ../DataStr/List.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshUI.h ../Common/Context.h \
  ../DataStr/Tools.h ../Graphics/Draw.h ../Mesh/Utils.h \
  ../Numeric/Numeric.h ../Fltk/Shortcut_Window.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Skin.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Extract.h \
  ../Common/Context.h ../DataStr/Malloc.h
DecomposeInSimplex.o: DecomposeInSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h DecomposeInSimplex.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Evaluate.h \
  ../Common/Context.h ../Numeric/Numeric.h
Integrate.o: Integrate.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Integrate.h \
  ../Common/Context.h ../Numeric/Numeric.h ShapeFunctions.h
Annotate.o: Annotate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Annotate.h \
  ../Common/Context.h ../Numeric/Numeric.h ../Common/GmshUI.h \
  ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h ../Fltk/Colorbar_Window.h
Remove.o: Remove.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h Remove.h \
  ../Common/Context.h ../Numeric/Numeric.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/Context.h \
  ../Common/GmshUI.h ../Graphics/Draw.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h \
  ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h OctreePost.h Octree.h \
  OctreeInternals.h
HarmonicToTime.o: HarmonicToTime.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h HarmonicToTime.h \
  ../Common/Context.h ../Numeric/Numeric.h
