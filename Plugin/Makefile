# $Id: Makefile,v 1.30 2003-02-11 08:54:57 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshPlugin.a
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo\
            -I../Mesh -I../Numeric -I../Triangle
CFLAGS  = -DMPICH_SKIP_MPICXX ${OPT_FLAGS} ${OS_FLAGS} ${VERSION_FLAGS} ${INCLUDE} ${GUI_INCLUDE} 

SRC = Plugin.cpp\
        LevelsetPlugin.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp\
        Smooth.cpp\
        Transform.cpp\
        Triangulate.cpp\
        SphericalRaise.cpp\
        Skin.cpp\
        Harmonic2Time.cpp

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
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  PluginManager.h CutMap.h LevelsetPlugin.h CutPlane.h CutSphere.h Skin.h \
  Smooth.h Transform.h Triangulate.h SphericalRaise.h
LevelsetPlugin.o: LevelsetPlugin.cpp LevelsetPlugin.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
  ../Common/Views.h ../Common/ColorTable.h ../Graphics/Iso.h \
  ../Numeric/Numeric.h
CutPlane.o: CutPlane.cpp CutPlane.h LevelsetPlugin.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
  ../Common/Context.h
CutSphere.o: CutSphere.cpp CutSphere.h LevelsetPlugin.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
  ../Common/Context.h
CutMap.o: CutMap.cpp CutMap.h LevelsetPlugin.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
  ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  Smooth.h ../DataStr/List.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h Transform.h ../DataStr/List.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Plugin.h ../Common/Options.h \
  Triangulate.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/Context.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Edge.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Matrix.h ../Mesh/Utils.h ../Mesh/Create.h \
  ../Triangle/triangle.h
SphericalRaise.o: SphericalRaise.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h SphericalRaise.h ../DataStr/List.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
  ../Numeric/Numeric.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h Skin.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h ../DataStr/Malloc.h
Harmonic2Time.o: Harmonic2Time.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h Harmonic2Time.h ../DataStr/List.h ../Common/Views.h \
  ../Common/ColorTable.h ../Common/Context.h ../Numeric/Numeric.h
