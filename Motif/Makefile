# $Id: Makefile,v 1.8 2001-02-17 22:04:05 geuzaine Exp $
#
# Makefile for "libMotif.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib

LIB      = ../lib/libMotif.a
INCLUDE  = -I../Common -I../DataStr -I../Graphics -I../Geo\
           -I../Mesh -I../Parser -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_XMOTIF -D_NOTHREADS

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GUI_INCLUDE) $(GL_INCLUDE)

SRC = Main.cpp \
      Widgets.cpp \
      Geometry.cpp \
      Register.cpp \
      Pixmaps.cpp \
      Opengl.cpp \
      XColors.cpp \
      Message.cpp \
      CbContext.cpp \
      CbPost.cpp \
      CbColorbar.cpp \
      CbGeom.cpp \
      CbMesh.cpp \
      CbOptions.cpp \
      CbFile.cpp \
      CbInput.cpp \
      CbGeneral.cpp 


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
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/GmshVersion.h ../Geo/Geo.h ../Geo/Verif.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
 ../Common/Context.h ../Parser/Parser.h Widgets.h Pixmaps.h XColors.h \
 XContext.h XRessources.h CbContext.h CbGeom.h Register.h Geometry.h \
 ../Parser/OpenFile.h ../Common/GetOptions.h ../Common/Static.h \
 XStatic.h
Widgets.o: Widgets.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Common/Context.h \
 ../Common/Const.h XContext.h Info.h Widgets.h Help.h
Geometry.o: Geometry.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Context.h ../Common/Const.h XContext.h Widgets.h
Register.o: Register.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Context.h ../Common/Const.h XContext.h Widgets.h Register.h \
 CbOptions.h CbContext.h CbFile.h CbGeom.h CbMesh.h CbPost.h
Pixmaps.o: Pixmaps.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h Widgets.h \
 ../Common/Context.h ../Common/Const.h Pixmaps.h ../Common/Bitmaps.h \
 XColors.h
Opengl.o: Opengl.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
 ../Common/Context.h ../Geo/MinMax.h Widgets.h XContext.h \
 ../Graphics/gl2ps.h
XColors.o: XColors.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h XContext.h
Message.o: Message.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/GmshVersion.h ../Common/Context.h ../Common/Const.h \
 Widgets.h
CbContext.o: CbContext.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Widgets.h \
 ../Common/Context.h XContext.h CbContext.h CbGeom.h CbMesh.h
CbPost.o: CbPost.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Widgets.h \
 ../Common/Context.h XContext.h ../Parser/OpenFile.h CbPost.h CbGeom.h \
 CbMesh.h CbColorbar.h
CbColorbar.o: CbColorbar.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Common/Const.h XColors.h Widgets.h Register.h ../Common/Context.h \
 XContext.h ../Common/ColorTable.h CbColorbar.h
CbGeom.o: CbGeom.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Widgets.h \
 ../Common/Context.h ../Geo/Verif.h ../Parser/OpenFile.h CbGeom.h
CbMesh.o: CbMesh.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h CbMesh.h \
 ../Common/Context.h Widgets.h
CbOptions.o: CbOptions.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Geo/Geo.h \
 ../Geo/Verif.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
 ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
 ../Graphics/Draw.h ../Common/Views.h ../Common/Const.h \
 ../Common/ColorTable.h Widgets.h Pixmaps.h ../Common/Context.h \
 ../Common/Options.h XContext.h Register.h ../Common/Timer.h \
 ../Geo/Visibility.h CbOptions.h CbGeom.h CbMesh.h CbPost.h
CbFile.o: CbFile.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h \
 ../Parser/OpenFile.h ../Common/Const.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/ColorTable.h Widgets.h \
 ../Common/Context.h ../Common/Options.h ../Graphics/CreateFile.h \
 CbFile.h CbColorbar.h
CbInput.o: CbInput.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h Widgets.h \
 ../Common/Context.h ../Common/Options.h XContext.h Register.h \
 CbContext.h CbGeom.h CbPost.h CbMesh.h
CbGeneral.o: CbGeneral.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h ../Common/GmshUI.h ../Mesh/Mesh.h \
 ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Edge.h \
 ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Graphics/Draw.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
 ../Common/Context.h XContext.h Widgets.h
