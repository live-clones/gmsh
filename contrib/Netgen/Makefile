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
ifneq (${UNAME},WIN32MSVC)
	${AR} ${ARFLAGS}${LIB} *${OBJEXT} libsrc/*/*${OBJEXT}
else
	copy libsrc\linalg\*.obj
	copy libsrc\general\*.obj
	copy libsrc\gprim\*.obj
	copy libsrc\meshing\*.obj
	copy libsrc\opti\*.obj
	copy libsrc\interface\*.obj
	${AR} ${ARFLAGS}${LIB} *${OBJEXT}
endif
	${RANLIB} ${LIB}

cpobj: recur nglib_addon${OBJEXT}
	cp -f *${OBJEXT} libsrc/*/*${OBJEXT} ../../lib/

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
	@cd libsrc/linalg && ${MAKE} clean
	@cd libsrc/general && ${MAKE} clean
	@cd libsrc/gprim && ${MAKE} clean
	@cd libsrc/meshing && ${MAKE} clean
	@cd libsrc/opti && ${MAKE} clean
	@cd libsrc/interface && ${MAKE} clean
	${RM} *.o *.obj

depend:
	true
