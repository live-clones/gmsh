# $Id: Makefile,v 1.20 2001-03-10 19:55:07 remacle Exp $
#
# Makefile for "libGraphics.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RANLIB   = ranlib
RM       = rm
LIB      = ../lib/libGraphics.a
INCLUDE  = -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Motif -I../Fltk -I../Mesh -I../Parser -I../jpeg

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_XMOTIF

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GL_INCLUDE) $(GUI_INCLUDE)

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      PostSimplex.cpp \
      Iso.cpp \
      IsoSimplex.cpp \
      Entity.cpp \
      Scale.cpp \
      Axes.cpp \
      CreateFile.cpp \
      XDump.cpp\
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2ppm.cpp\
      gl2yuv.cpp


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
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h gl2ps.h ../Geo/Verif.h ../Mesh/Numeric.h \
 ../Geo/Visibility.h
Geom.o: Geom.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/Verif.h ../Mesh/Interpolation.h ../Mesh/Numeric.h \
 ../Geo/Visibility.h
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
 ../Common/Const.h ../Common/ColorTable.h Iso.h IsoSimplex.h \
 ../Common/Context.h
Iso.o: Iso.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h Draw.h ../Common/Views.h ../Common/Const.h \
 ../Common/ColorTable.h ../Mesh/Numeric.h
IsoSimplex.o: IsoSimplex.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h ../Common/Views.h \
 ../Common/Const.h ../Common/ColorTable.h Iso.h ../Common/Context.h \
 ../Mesh/Numeric.h
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
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
 ../Motif/XContext.h
Axes.o: Axes.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Const.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h
CreateFile.o: CreateFile.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Parser/OpenFile.h \
 ../Common/Const.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Common/Context.h ../Motif/Widgets.h ../Motif/XContext.h XDump.h \
 gl2ps.h gl2gif.h gl2jpeg.h gl2ppm.h gl2yuv.h
XDump.o: XDump.cpp
gl2ps.o: gl2ps.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h gl2ps.h
gl2gif.o: gl2gif.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h gl2gif.h
gl2jpeg.o: gl2jpeg.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../jpeg/jpeglib.h ../jpeg/jconfig.h ../jpeg/jmorecfg.h \
 ../jpeg/jerror.h
gl2ppm.o: gl2ppm.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
gl2yuv.o: gl2yuv.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h
