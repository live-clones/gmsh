# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshTetgen${LIBEXT}

# Don't optimize Tetgen
CFLAGS = ${FLAGS} ${DASH}DTETLIBRARY

SRC = behavior.cxx\
      constrain.cxx\
      delaunay.cxx\
      flip.cxx\
      geom.cxx\
      io.cxx\
      main.cxx\
      memorypool.cxx\
      meshio.cxx\
      meshstat.cxx\
      predicates.cxx\
      surface.cxx

OBJ = ${SRC:.cxx=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cxx

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cxx${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	${RM} *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
behavior${OBJEXT}: behavior.cxx tetgen.h
constrain${OBJEXT}: constrain.cxx tetgen.h
delaunay${OBJEXT}: delaunay.cxx tetgen.h
flip${OBJEXT}: flip.cxx tetgen.h
geom${OBJEXT}: geom.cxx tetgen.h
io${OBJEXT}: io.cxx tetgen.h
main${OBJEXT}: main.cxx tetgen.h
memorypool${OBJEXT}: memorypool.cxx tetgen.h
meshio${OBJEXT}: meshio.cxx tetgen.h
meshstat${OBJEXT}: meshstat.cxx tetgen.h
predicates${OBJEXT}: predicates.cxx tetgen.h
surface${OBJEXT}: surface.cxx tetgen.h
