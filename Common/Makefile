# $Id: Makefile,v 1.37 2003-02-11 08:54:55 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshCommon.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Numeric -I../Parser -I../Fltk
CFLAGS  = ${OPT_FLAGS} ${OS_FLAGS} ${VERSION_FLAGS} ${INCLUDE} ${GUI_INCLUDE}

SRC = Context.cpp\
      Views.cpp\
      Options.cpp\
      CommandLine.cpp\
      Timer.cpp\
      ColorTable.cpp\
      Trackball.cpp

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
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h ../Graphics/Draw.h ../Common/Views.h \
  ../Common/ColorTable.h Context.h Options.h DefaultOptions.h Trackball.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../Numeric/Numeric.h Views.h ColorTable.h Context.h Options.h
Options.o: Options.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h ../Common/Views.h ../Common/ColorTable.h Context.h \
  Options.h ../Fltk/Solvers.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h \
  ../Fltk/Colorbar_Window.h
CommandLine.o: CommandLine.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  GmshUI.h GmshVersion.h ../Numeric/Numeric.h Context.h Options.h \
  ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Edge.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Matrix.h \
  Views.h ColorTable.h ../Parser/OpenFile.h ../Parser/Parser.h
Timer.o: Timer.cpp
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ColorTable.h Context.h
Trackball.o: Trackball.cpp Trackball.h
