# $Id: Makefile,v 1.54 2004-02-07 01:40:22 geuzaine Exp $
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

LIB     = ../lib/libGmshMesh.a
INCLUDE = -I../Numeric -I../NR -I../Common -I../DataStr -I../Geo -I../Mesh\
          -I../Graphics -I../Parser -I../Fltk -I../Triangle
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = 1D_Mesh.cpp \
      2D_Mesh.cpp \
        2D_SMesh.cpp \
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
        3D_SMesh.cpp \
        3D_BGMesh.cpp \
        3D_Extrude.cpp \
        3D_Extrude_Old.cpp \
        3D_Coherence.cpp \
        3D_Divide.cpp \
        3D_Bricks.cpp \
      MeshQuality.cpp \
      Create.cpp \
      Generator.cpp \
      Print_Mesh.cpp \
      Read_Mesh.cpp \
      STL.cpp \
      SMS.cpp \
      SwapEdge.cpp \
      Utils.cpp \
      Metric.cpp \
      Nurbs.cpp \
      Interpolation.cpp \
      SecondOrder.cpp \
      Smoothing.cpp \
      CrossData.cpp \
      Vertex.cpp \
      Edge.cpp \
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
1D_Mesh.o: 1D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h Utils.h ../Common/Context.h Interpolation.h
2D_Mesh.o: 2D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Utils.h Create.h 2D_Mesh.h ../Common/Context.h
2D_SMesh.o: 2D_SMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h \
  ../Numeric/Numeric.h Interpolation.h
2D_Elliptic.o: 2D_Elliptic.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h
2D_BGMesh.o: 2D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_Recombine.o: 2D_Recombine.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h Utils.h 2D_Mesh.h Create.h ../Common/Context.h
2D_InitMesh.o: 2D_InitMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_Bowyer.o: 2D_Bowyer.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_Bricks.o: 2D_Bricks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_DivAndConq.o: 2D_DivAndConq.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_Util.o: 2D_Util.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h ../Common/Context.h
2D_Links.o: 2D_Links.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 2D_Mesh.h
2D_Tree.o: 2D_Tree.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h 2D_Mesh.h
2D_Cylindrical.o: 2D_Cylindrical.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h ../Common/Context.h
2D_Parametric.o: 2D_Parametric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Interpolation.h 2D_Mesh.h Create.h ../Common/Context.h
2D_Mesh_Aniso.o: 2D_Mesh_Aniso.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Interpolation.h Create.h ../Common/Context.h
2D_Mesh_Triangle.o: 2D_Mesh_Triangle.cpp ../Common/Gmsh.h \
  ../Common/Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h \
  ../Numeric/Numeric.h ../Common/Context.h
3D_Mesh.o: 3D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 3D_Mesh.h Create.h ../Common/Context.h
3D_SMesh.o: 3D_SMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h Interpolation.h Create.h
3D_BGMesh.o: 3D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h 2D_Mesh.h 3D_Mesh.h \
  ../Common/Views.h ../Common/ColorTable.h ../Numeric/Numeric.h \
  ../Common/Context.h
3D_Extrude.o: 3D_Extrude.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Common/Context.h Create.h
3D_Extrude_Old.o: 3D_Extrude_Old.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h ../Common/Context.h Create.h
3D_Coherence.o: 3D_Coherence.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h 3D_Mesh.h Create.h
3D_Divide.o: 3D_Divide.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h
3D_Bricks.o: 3D_Bricks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h
MeshQuality.o: MeshQuality.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h
Create.o: Create.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Utils.h ../Common/Context.h Create.h
Generator.o: Generator.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h Create.h ../Common/Context.h ../Parser/OpenFile.h
Print_Mesh.o: Print_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Create.h ../Common/Context.h
Read_Mesh.o: Read_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h \
  3D_Mesh.h Create.h ../Geo/MinMax.h ../Common/Context.h
STL.o: STL.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h
SMS.o: SMS.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Geo/Geo.h Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h \
  STL.h Metric.h Matrix.h Create.h ../Geo/MinMax.h ../Geo/CAD.h \
  ../Common/Context.h
SwapEdge.o: SwapEdge.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h SwapPatterns.h
Utils.o: Utils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Interpolation.h ../Common/Context.h
Metric.o: Metric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Interpolation.h
Nurbs.o: Nurbs.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h
Interpolation.o: Interpolation.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/STL.h ../Mesh/Metric.h \
  ../Mesh/Matrix.h Utils.h Interpolation.h
SecondOrder.o: SecondOrder.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h Utils.h \
  Interpolation.h ../Numeric/Numeric.h
Smoothing.o: Smoothing.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Mesh.h \
  Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h
CrossData.o: CrossData.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h
Vertex.o: Vertex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h Vertex.h \
  Mesh.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h \
  ../Common/Context.h
Edge.o: Edge.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h STL.h Metric.h Matrix.h
Simplex.o: Simplex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Numeric/Numeric.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h STL.h Metric.h \
  Matrix.h ../Common/Context.h
