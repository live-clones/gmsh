# $Id: Makefile,v 1.19 2002-09-24 02:04:33 geuzaine Exp $
#
# Makefile for "libGmshBox.a"
#

CXX    = c++
AR     = ar ruvs
RM     = rm
RANLIB = ranlib

LIB     = ../lib/libGmshBox.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../Plugin -I../Parallel

OPT_FLAGS     =
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Main.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
Main.o: Main.cpp ../Parallel/ParUtil.h ../Plugin/PluginManager.h \
  ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Common/GmshVersion.h ../Numeric/Numeric.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Common/Views.h ../Common/ColorTable.h ../Parser/Parser.h \
  ../Common/Context.h ../Common/Options.h ../Parser/OpenFile.h \
  ../Common/CommandLine.h ../Geo/MinMax.h
