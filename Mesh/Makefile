# $Id: Makefile,v 1.8 2001-01-08 08:05:45 geuzaine Exp $
#
# Makefile for "libMesh.a"
#

.IGNORE:

CC      = c++
RM      = rm
RANLIB  = ranlib

LIB     = ../lib/libMesh.a
INCLUDE = -I../Adapt -I../Common -I../DataStr -I../Geo -I../Mesh\
          -I../Graphics -I../Motif -I../Parser -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(INCLUDE)

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
      3D_Mesh.cpp \
        3D_SMesh.cpp \
        3D_BGMesh.cpp \
        3D_Extrude.cpp \
        3D_Coherence.cpp \
        3D_Divide.cpp \
        3D_Bricks.cpp \
      MeshQuality.cpp \
      Create.cpp \
      Generator.cpp \
      Print_Mesh.cpp \
      Read_Mesh.cpp \
      STL.cpp \
      SwapEdge.cpp \
      Numeric.cpp \
      Metric.cpp \
      Nurbs.cpp \
      Interpolation.cpp \
      SecondOrder.cpp \
      Smoothing.cpp \
      CrossData.cpp \
      Vertex.cpp \
      Edge.cpp \
      Simplex.cpp 

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	ar rvs $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
1D_Mesh.o: 1D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h \
  ../Common/Context.h Interpolation.h Numeric.h
2D_Mesh.o: 2D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Create.h \
  2D_Mesh.h Numeric.h ../Common/Context.h
2D_SMesh.o: 2D_SMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h Numeric.h \
  Interpolation.h
2D_Elliptic.o: 2D_Elliptic.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h
2D_BGMesh.o: 2D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Recombine.o: 2D_Recombine.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h Create.h \
  Numeric.h
2D_InitMesh.o: 2D_InitMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h Numeric.h
2D_Bowyer.o: 2D_Bowyer.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Bricks.o: 2D_Bricks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_DivAndConq.o: 2D_DivAndConq.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Util.o: 2D_Util.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Links.o: 2D_Links.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Tree.o: 2D_Tree.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h
2D_Cylindrical.o: 2D_Cylindrical.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h ../Common/Context.h \
  Numeric.h
2D_Parametric.o: 2D_Parametric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Interpolation.h \
  Mesh.h 2D_Mesh.h Create.h ../Common/Context.h Numeric.h
2D_Mesh_Aniso.o: 2D_Mesh_Aniso.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h \
  Interpolation.h Create.h ../Common/Context.h Numeric.h
3D_Mesh.o: 3D_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h 3D_Mesh.h Create.h \
  Numeric.h ../Common/Context.h
3D_SMesh.o: 3D_SMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h Metric.h Interpolation.h Create.h
3D_BGMesh.o: 3D_BGMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h Metric.h 2D_Mesh.h 3D_Mesh.h ../Adapt/Adapt.h \
  ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Numeric.h
3D_Extrude.o: 3D_Extrude.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h \
  ../Common/Context.h Create.h
3D_Coherence.o: 3D_Coherence.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h \
  3D_Mesh.h Create.h Numeric.h
3D_Divide.o: 3D_Divide.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h
3D_Bricks.o: 3D_Bricks.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h
MeshQuality.o: MeshQuality.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h Numeric.h
Create.o: Create.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Numeric.h \
  ../Common/Context.h
Generator.o: Generator.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h Create.h \
  ../Common/Context.h ../Parser/OpenFile.h
Print_Mesh.o: Print_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Create.h \
  ../Common/Context.h
Read_Mesh.o: Read_Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h Create.h \
  ../Geo/MinMax.h
STL.o: STL.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h
SwapEdge.o: SwapEdge.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h SwapPatterns.h
Numeric.o: Numeric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Numeric.h \
  Interpolation.h ../Adapt/nrutil.h
Metric.o: Metric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Matrix.h \
  Interpolation.h
Nurbs.o: Nurbs.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h Metric.h
Interpolation.o: Interpolation.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  ../Geo/CAD.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Mesh.h Numeric.h \
  Interpolation.h
SecondOrder.o: SecondOrder.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Geo/Geo.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h Interpolation.h \
  Numeric.h
Smoothing.o: Smoothing.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h Mesh.h Vertex.h \
  Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h
CrossData.o: CrossData.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Mesh.h Vertex.h Simplex.h Edge.h \
  ../Geo/ExtrudeParams.h Metric.h
Vertex.o: Vertex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Vertex.h ../Common/Context.h \
  ../Common/Const.h
Edge.o: Edge.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h \
  ../Common/Const.h
Simplex.o: Simplex.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../Common/Const.h ../Geo/Geo.h \
  Mesh.h Vertex.h Simplex.h Edge.h ../Geo/ExtrudeParams.h Metric.h \
  Numeric.h
