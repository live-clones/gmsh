# $Id: Makefile,v 1.34 2001-12-03 08:41:43 geuzaine Exp $
#
# Makefile for "libGraphics.a"
#

.IGNORE:

CXX      = c++
AR       = ar ruvs
RANLIB   = ranlib
RM       = rm
LIB      = ../lib/libGraphics.a
INCLUDE  = -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Fltk -I../Mesh -I../Parser -I../jpeg

OPT_FLAGS     = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = 

RMFLAGS  = -f
CFLAGS   = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GL_INCLUDE) $(GUI_INCLUDE)

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      PostSimplex.cpp \
      IsoSimplex.cpp \
      Entity.cpp \
      Visibility.cpp \
      Scale.cpp \
      Graph2D.cpp \
      Axes.cpp \
      CreateFile.cpp \
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
	$(CXX) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
Draw.o: Draw.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h
Mesh.o: Mesh.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/MinMax.h gl2ps.h ../Geo/Verif.h ../Common/Numeric.h
Geom.o: Geom.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h ../Mesh/Matrix.h ../Mesh/Utils.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
 ../Geo/Verif.h ../Mesh/Interpolation.h ../Mesh/STL.h gl2ps.h
Post.o: Post.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
 ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
 ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h ../Common/Views.h \
 ../Common/ColorTable.h ../Common/Context.h gl2ps.h
PostSimplex.o: PostSimplex.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Iso.h IsoSimplex.h \
 ../Common/Context.h ../Common/Numeric.h
IsoSimplex.o: IsoSimplex.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Iso.h \
 ../Common/Context.h ../Common/Numeric.h
Entity.o: Entity.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Common/Context.h
Scale.o: Scale.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Common/Context.h gl2ps.h
Graph2D.o: Graph2D.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Context.h ../Common/Numeric.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h Draw.h \
 ../Common/Views.h ../Common/ColorTable.h gl2ps.h
Axes.o: Axes.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Numeric.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Mesh/Matrix.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Common/Context.h gl2ps.h
CreateFile.o: CreateFile.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
 ../Parser/OpenFile.h Draw.h ../Common/Views.h ../Common/ColorTable.h \
 ../Common/Context.h gl2ps.h gl2gif.h gl2jpeg.h gl2ppm.h gl2yuv.h
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
