# $Id: Makefile,v 1.2 2007-07-26 16:35:01 geuzaine Exp $
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

LIB     = ../lib/libGmshPost.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Post\
          -I../Graphics -I../Numeric -I../Parser -I../Plugin -I../Fltk\
          -I../contrib/MathEval -I../contrib/ANN/include/
CFLAGS  =${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Views.cpp ViewsIO.cpp\
      AdaptiveViews.cpp\
      OctreePost.cpp\
      ColorTable.cpp

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
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Views.o: Views.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Views.h ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h \
  ../Common/Options.h ../Mesh/BackgroundMesh.h
ViewsIO.o: ViewsIO.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Numeric/Numeric.h Views.h ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothData.h ../Numeric/Numeric.h \
  AdaptiveViews.h ../Common/GmshMatrix.h ../Common/Context.h
AdaptiveViews.o: AdaptiveViews.cpp AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Post/Views.h ../Post/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h ../Post/AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Common/OS.h
OctreePost.o: OctreePost.cpp ../Common/Octree.h \
  ../Common/OctreeInternals.h OctreePost.h ../DataStr/List.h Views.h \
  ColorTable.h ../Common/VertexArray.h ../Common/SmoothData.h \
  ../Numeric/Numeric.h AdaptiveViews.h ../Common/GmshMatrix.h \
  ../Numeric/Numeric.h ../Common/Message.h ../Common/ShapeFunctions.h
ColorTable.o: ColorTable.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ColorTable.h ../Common/Context.h ../Numeric/Numeric.h
