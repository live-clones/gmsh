# $Id: Makefile,v 1.10 2001-08-12 13:08:20 geuzaine Exp $
#
# Makefile for "libBox.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib
LIB      = ../lib/libBox.a
INCLUDE  = -I../Common -I../DataStr -I../Geo\
           -I../Graphics -I../Mesh -I../Parser -I../Motif -I../Fltk -I../Plugin -I../Parallel

C_FLAGS       = -g
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Main.cpp

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
Main.o: Main.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshVersion.h \
 ../Common/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h ../Common/Views.h ../Common/ColorTable.h \
 ../Parser/Parser.h ../Common/Context.h ../Parser/OpenFile.h \
 ../Common/GetOptions.h ../Geo/MinMax.h ../Common/Static.h
