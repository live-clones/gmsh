# $Id: Makefile,v 1.4 2000-11-25 15:26:10 geuzaine Exp $
#
# Makefile for "libCommon.a"
#

.IGNORE:

CC        = c++
C_FLAGS   = -g -Wall

OS_FLAGS  = -D_UNIX

RANLIB   = ranlib
RM       = rm
RMFLAGS  = -f

LIB      = ../lib/libCommon.a
INCLUDE  = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Mesh -I../Parser -I../Unix

CFLAGS = $(C_FLAGS) $(OS_FLAGS) $(INCLUDE) $(GL_INCLUDE)

SRC =  	Context.cpp\
        Views.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	ar ruvs $(LIB) $(OBJ)
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
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Const.h ../Geo/Geo.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Graphics/ColorTable.h \
 Context.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
 ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../DataStr/Tools.h Views.h Const.h ../Graphics/ColorTable.h Context.h
