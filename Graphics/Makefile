# $Id: Makefile,v 1.8 2000-12-21 08:02:05 geuzaine Exp $
#
# Makefile for "libGraphics.a"
#

.IGNORE:

CC            = c++
C_FLAGS       = -g -Wall

VERSION_FLAGS = 
OS_FLAGS      = -D_UNIX

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
MOTIF_INCLUDE = -I/usr/X11R6/LessTif/Motif1.2/include

RANLIB   = ranlib
RM       = rm
RMFLAGS  = -f

LIB      = ../lib/libGraphics.a
INCLUDE  = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Unix -I../Mesh -I../jpeg

CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GL_INCLUDE) $(MOTIF_INCLUDE)

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      PostSimplex.cpp \
      Iso.cpp \
      Entity.cpp \
      Scale.cpp \
      Axes.cpp \
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2ppm.cpp


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
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h ../Unix/CbGeneral.h ../Unix/Widgets.h \
 ../Unix/XContext.h
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h gl2ps.h ../Geo/Verif.h ../Mesh/Numeric.h
Geom.o: Geom.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/Verif.h ../Mesh/Interpolation.h ../Mesh/Numeric.h
Post.o: Post.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h
PostSimplex.o: PostSimplex.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h Iso.h ../Common/Context.h
Iso.o: Iso.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h Draw.h ../Common/Views.h ../Common/Const.h \
 ../Common/ColorTable.h
Entity.o: Entity.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h
Scale.o: Scale.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Const.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h gl2ps.h \
 ../Unix/XContext.h
Axes.o: Axes.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Const.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h
gl2ps.o: gl2ps.cpp gl2ps.h
gl2gif.o: gl2gif.cpp gl2gif.h
