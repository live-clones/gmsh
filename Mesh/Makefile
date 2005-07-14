# $Id: Makefile,v 1.91 2005-07-14 14:28:15 remacle Exp $
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

LIB     = ../lib/libGmshMesh.a
INCLUDE = -I../Numeric -I../NR -I../Common -I../DataStr -I../Geo -I../Mesh\
          -I../Graphics -I../Parser -I../Fltk -I../Triangle -I../Tetgen\
          -I../Netgen -I../Netgen/libsrc/include  -I../Netgen/libsrc/interface
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
        3D_Bricks.cpp \
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
