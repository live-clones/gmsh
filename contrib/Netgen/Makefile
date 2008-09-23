# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshNetgen${LIBEXT}

INC = ${DASH}I../../Common ${DASH}Ilibsrc/include ${DASH}Ilibsrc/interface

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}\
         ${DASH}DNO_PARALLEL_THREADS ${DASH}UWIN32

${LIB}: recur nglib_addon${OBJEXT}
	${AR} ${ARFLAGS}${LIB} *${OBJEXT} libsrc/*/*${OBJEXT}
	${RANLIB} ${LIB}

cpobj: recur nglib_addon${OBJEXT}
	${CP} *${OBJEXT} libsrc/*/*${OBJEXT} ../../lib/

recur:
	@cd libsrc/linalg && ${MAKE}
	@cd libsrc/general && ${MAKE}
	@cd libsrc/gprim && ${MAKE}
	@cd libsrc/meshing && ${MAKE}
	@cd libsrc/opti && ${MAKE}
	@cd libsrc/interface && ${MAKE}

nglib_addon${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c nglib_addon.cpp

clean:
	rm -f *.o *.obj libsrc/*/*.o libsrc/*/*.obj

depend:
	true
