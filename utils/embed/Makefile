# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshEmbedded${LIBEXT}

INC = ${DASH}I. ${DASH}I../../Common

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}DHAVE_GMSH_EMBEDDED

SRC = GModel.cpp\
        GModelIO_Mesh.cpp\
      GEntity.cpp\
        GVertex.cpp GEdge.cpp GEdgeLoop.cpp GFace.cpp GRegion.cpp\
        discreteEdge.cpp discreteFace.cpp discreteRegion.cpp\
      MElement.cpp\
        MFace.cpp MVertex.cpp\
      NumericEmbedded.cpp\
        FunctionSpace.cpp\
      StringUtils.cpp\
      GmshEmbedded.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	rm -f *.o *.obj

distclean:
	rm -f *.a *.lib
	rm -f *.o *.obj
	mkdir tmp
	mv GmshEmbedded.* tmp
	rm -f *.cpp *.h
	mv tmp/* .
	rmdir tmp

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
