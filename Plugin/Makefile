# $Id: Makefile,v 1.49 2004-05-29 10:11:12 geuzaine Exp $
#
# Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo\
            -I../Mesh -I../Numeric -I../Triangle -I../MathEval
CFLAGS  = -DMPICH_SKIP_MPICXX ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Plugin.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp\
        Smooth.cpp\
	Octree.cpp OctreeInternals.cpp OctreePost.cpp\
          StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
        Triangulate.cpp\
        SphericalRaise.cpp\
        DisplacementRaise.cpp\
        Skin.cpp\
        Extract.cpp\
        DecomposeInSimplex.cpp\
        Evaluate.cpp\
        Harmonic2Time.cpp

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
  ../Common/VertexArray.h PluginManager.h CutMap.h Levelset.h CutGrid.h \
  StreamLines.h CutPlane.h CutSphere.h Skin.h ../DataStr/Tree.h \
  ../DataStr/avl.h Extract.h Harmonic2Time.h DecomposeInSimplex.h \
  Smooth.h Transform.h Triangulate.h SphericalRaise.h DisplacementRaise.h \
  Evaluate.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h DecomposeInSimplex.h \
  ../DataStr/Tools.h ../DataStr/Tree.h ../DataStr/avl.h ../Graphics/Iso.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/Malloc.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/Context.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/Context.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h Smooth.h ../Common/Context.h
Octree.o: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals.o: OctreeInternals.cpp ../Common/Message.h \
  OctreeInternals.h
OctreePost.o: OctreePost.cpp Octree.h OctreeInternals.h OctreePost.h \
  ../DataStr/List.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Numeric/Numeric.h ../Common/Message.h
StreamLines.o: StreamLines.cpp OctreePost.h Octree.h OctreeInternals.h \
  StreamLines.h Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/Context.h
CutGrid.o: CutGrid.cpp OctreePost.h Octree.h OctreeInternals.h CutGrid.h \
  Plugin.h ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/Context.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h Transform.h \
  ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Plugin.h ../Common/Options.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  Triangulate.h ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Simplex.h ../Mesh/Face.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Mesh/Utils.h ../Mesh/Create.h
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h SphericalRaise.h \
  ../Common/Context.h ../Numeric/Numeric.h
DisplacementRaise.o: DisplacementRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h DisplacementRaise.h \
  ../Common/Context.h ../Numeric/Numeric.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Common/Context.h ../DataStr/Malloc.h
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h Extract.h ../Common/Context.h \
  ../DataStr/Malloc.h
DecomposeInSimplex.o: DecomposeInSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h DecomposeInSimplex.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Common/Context.h \
  ../DataStr/Malloc.h
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h Evaluate.h ../Common/Context.h \
  ../Numeric/Numeric.h
Harmonic2Time.o: Harmonic2Time.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h Harmonic2Time.h \
  ../Common/Context.h ../Numeric/Numeric.h
