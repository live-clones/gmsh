# $Id: Makefile,v 1.25 2003-02-11 08:54:58 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshJpeg.a
INCLUDE = -I.
CFLAGS  = ${OPT_FLAGS} ${OS_FLAGS} ${VERSION_FLAGS} ${INCLUDE}

SRC = jcomapi.c jutils.c jerror.c jmemmgr.c jmemnobs.c \
      jcapi.c jcparam.c jdatadst.c jcmaster.c jcmarker.c jcmainct.c \
      jcprepct.c jccoefct.c jccolor.c jcsample.c jchuff.c jcdctmgr.c \
      jfdctfst.c jfdctflt.c jfdctint.c

OBJ = ${SRC:.c=.o}

.SUFFIXES: .o .c

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.c.o:
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
jcomapi.o: jcomapi.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jutils.o: jutils.c jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h \
 jerror.h
jerror.o: jerror.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jversion.h jerror.h
jmemmgr.o: jmemmgr.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jmemsys.h
jmemnobs.o: jmemnobs.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jmemsys.h
jcapi.o: jcapi.c jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h \
 jerror.h
jcparam.o: jcparam.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jdatadst.o: jdatadst.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jerror.h
jcmaster.o: jcmaster.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jcmarker.o: jcmarker.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jcmainct.o: jcmainct.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jcprepct.o: jcprepct.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jccoefct.o: jccoefct.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jccolor.o: jccolor.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jcsample.o: jcsample.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h
jchuff.o: jchuff.c jinclude.h jconfig.h jpeglib.h jmorecfg.h jpegint.h \
 jerror.h
jcdctmgr.o: jcdctmgr.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jdct.h
jfdctfst.o: jfdctfst.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jdct.h
jfdctflt.o: jfdctflt.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jdct.h
jfdctint.o: jfdctint.c jinclude.h jconfig.h jpeglib.h jmorecfg.h \
 jpegint.h jerror.h jdct.h
