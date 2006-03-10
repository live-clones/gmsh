# $Id: Makefile,v 1.106.2.1 2006-03-10 06:35:01 geuzaine Exp $
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

LIB     = ../lib/libGmshMesh.a
INCLUDE = -I../Numeric -I../Common -I../DataStr -I../Geo -I../Mesh\
          -I../Graphics -I../Parser -I../Fltk\
          -I../contrib/NR -I../contrib/Triangle -I../contrib/Tetgen\
          -I../contrib/Netgen -I../contrib/Netgen/libsrc/include\
          -I../contrib/Netgen/libsrc/interface -I../contrib/ANN/include\
          -I../contrib/Metis
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = 1D_Mesh.cpp \
      2D_Mesh.cpp \
        2D_Transfinite.cpp \
        2D_Elliptic.cpp \
        2D_BGMesh.cpp \
        2D_Recombine.cpp \
        2D_InitMesh.cpp \
        2D_Bowyer.cpp \
        2D_Bricks.cpp \
        2D_DivAndConq.cpp \
        2D_Util.cpp \
        2D_Links.cpp \
        2D_Tree.cpp \
        2D_Cylindrical.cpp \
        2D_Parametric.cpp \
        2D_Mesh_Aniso.cpp \
        2D_Mesh_Triangle.cpp \
        3D_Mesh.cpp \
        3D_Transfinite.cpp \
        3D_BGMesh.cpp \
        3D_Extrude.cpp \
        3D_Extrude_Old.cpp \
        3D_Coherence.cpp \
        3D_Divide.cpp \
        3D_Mesh_Netgen.cpp \
        3D_Mesh_Tetgen.cpp \
      BDS.cpp \
      MeshQuality.cpp \
      Create.cpp \
      Generator.cpp \
      Print_Mesh.cpp \
      Read_Mesh.cpp \
      DiscreteSurface.cpp \
      SwapEdge.cpp \
      Utils.cpp \
      Metric.cpp \
      Nurbs.cpp \
      Interpolation.cpp \
      SecondOrder.cpp \
      PartitionMesh.cpp\
      Smoothing.cpp \
      CrossData.cpp \
      Vertex.cpp \
      Edge.cpp \
      Face.cpp \
      Element.cpp \
      Simplex.cpp 

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

# Don't optimize 3D_Mesh: it sometimes mysteriously crashes on Linux
3D_Mesh.o:
	${CXX} ${FLAGS} ${INCLUDE} -c $<
# Don't optimize BDS: it leads to erroneous results with gcc 4.0
BDS.o:
	${CXX} ${FLAGS} ${INCLUDE} -c $<

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
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
1D_Mesh.o: 1D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h \
  Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h Utils.h ../Common/Context.h \
  Interpolation.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Mesh.o: 2D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Utils.h Vertex.h Create.h 2D_Mesh.h \
  ../Common/Context.h Interpolation.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Transfinite.o: 2D_Transfinite.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  Interpolation.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Elliptic.o: 2D_Elliptic.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_BGMesh.o: 2D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Recombine.o: 2D_Recombine.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h \
  Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h Interpolation.h Utils.h \
  2D_Mesh.h Create.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_InitMesh.o: 2D_InitMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Bowyer.o: 2D_Bowyer.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Bricks.o: 2D_Bricks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_DivAndConq.o: 2D_DivAndConq.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Util.o: 2D_Util.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Links.o: 2D_Links.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 2D_Mesh.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Tree.o: 2D_Tree.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  2D_Mesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Cylindrical.o: 2D_Cylindrical.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Parametric.o: 2D_Parametric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Interpolation.h Vertex.h Mesh.h 2D_Mesh.h \
  Create.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Mesh_Aniso.o: 2D_Mesh_Aniso.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Interpolation.h Vertex.h Create.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
2D_Mesh_Triangle.o: 2D_Mesh_Triangle.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Mesh.o: 3D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h \
  Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 3D_Mesh.h Create.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Transfinite.o: 3D_Transfinite.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  Interpolation.h Create.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_BGMesh.o: 3D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Extrude.o: 3D_Extrude.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h ../Common/Context.h Create.h Vertex.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Extrude_Old.o: 3D_Extrude_Old.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h ../Common/Context.h Create.h Vertex.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Coherence.o: 3D_Coherence.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h \
  Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h 3D_Mesh.h Create.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Divide.o: 3D_Divide.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Mesh_Netgen.o: 3D_Mesh_Netgen.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  Create.h ../Common/Context.h ../Common/OS.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
3D_Mesh_Tetgen.o: 3D_Mesh_Tetgen.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  Create.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
BDS.o: BDS.cpp ../Numeric/Numeric.h ../Common/GmshMatrix.h BDS.h \
  ../Common/Message.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
MeshQuality.o: MeshQuality.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Create.o: Create.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Utils.h Vertex.h ../Common/Context.h \
  Create.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Generator.o: Generator.cpp BDS.h ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h Create.h \
  ../Common/Context.h ../Parser/OpenFile.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
  ../Common/AdaptiveViews.h ../Common/GmshMatrix.h PartitionMesh.h \
  ../Common/OS.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Print_Mesh.o: Print_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Create.h Vertex.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Read_Mesh.o: Read_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h 3D_Mesh.h Create.h Vertex.h \
  ../Common/Context.h PartitionMesh.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
DiscreteSurface.o: DiscreteSurface.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h Mesh.h Vertex.h Element.h \
  Simplex.h Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Geo/ExtrudeParams.h ../Geo/Geo.h Create.h \
  Interpolation.h ../Common/Context.h BDS.h PartitionMesh.h \
  ../Common/OS.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
SwapEdge.o: SwapEdge.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h SwapPatterns.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Utils.o: Utils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Interpolation.h Vertex.h \
  ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Metric.o: Metric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Geo/ExtrudeParams.h Mesh.h Matrix.h Interpolation.h Vertex.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Nurbs.o: Nurbs.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Nurbs.h Vertex.h Mesh.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  ../Geo/Geo.h ../Geo/GeoUtils.h ../Mesh/Mesh.h Create.h ../Geo/CAD.h \
  ../Mesh/Vertex.h ../Geo/ExtrudeParams.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Interpolation.o: Interpolation.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Nurbs.h Vertex.h Mesh.h Element.h \
  Simplex.h Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Geo/ExtrudeParams.h Utils.h Interpolation.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
SecondOrder.o: SecondOrder.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h \
  Utils.h Interpolation.h ../Common/OS.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
PartitionMesh.o: PartitionMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Geo/CAD.h ../Mesh/Mesh.h \
  ../Mesh/Vertex.h ../Geo/ExtrudeParams.h ../Geo/Geo.h Create.h \
  Interpolation.h ../Common/Context.h BDS.h PartitionMesh.h \
  ../Parser/OpenFile.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Smoothing.o: Smoothing.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
CrossData.o: CrossData.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Vertex.o: Vertex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Vertex.h Mesh.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Common/Context.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Edge.o: Edge.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Element.h Simplex.h Face.h Edge.h ../Geo/ExtrudeParams.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Face.o: Face.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Element.h Simplex.h Face.h Edge.h ../Geo/ExtrudeParams.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Element.o: Element.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Mesh.h Vertex.h Element.h Simplex.h Face.h Edge.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h Metric.h Matrix.h
# 1 "/Users/geuzaine/src/gmsh-1.64-branch/Mesh//"
Simplex.o: Simplex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h ../Geo/Geo.h Mesh.h Vertex.h Element.h Simplex.h \
  Face.h Edge.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h Metric.h Matrix.h ../Common/Context.h
