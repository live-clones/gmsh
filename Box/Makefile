# $Id: Makefile,v 1.27 2005-01-09 02:40:13 geuzaine Exp $
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

LIB     = ../lib/libGmshBox.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../Plugin -I../Parallel
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Main.cpp

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
Main.o: Main.cpp ../Parallel/ParUtil.h ../Plugin/PluginManager.h \
  ../Plugin/Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h ../Common/Gmsh.h \
  ../DataStr/Malloc.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../DataStr/Tools.h ../Common/GmshVersion.h ../Numeric/Numeric.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Simplex.h ../Mesh/Face.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/DiscreteSurface.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Parser/Parser.h ../Common/Context.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Geo/MinMax.h
