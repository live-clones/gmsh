# $Id: Makefile,v 1.23 2001-07-26 18:47:59 remacle Exp $
#
# Makefile for "libMesh.a"
#

.IGNORE:

CC      = c++
AR      = ar ruvs
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
	$(AR) $(LIB) $(OBJ) 
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
