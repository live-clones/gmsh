SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=kdtree.a
LIBSRCS=kdbuild.c kdnear.c kdspan.c kdtwoopt.c
LIBS=$(ROOT)/UTIL/util.a
ALLSRCS=kd_main.c $(LIBSRCS)

all: kdtree $(LIB)

kdtree: kd_main.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

clean:
	-rm -f *.$o $(LIB) kdtree

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

kd_main.$o:  kd_main.c  $(I)/machdefs.h $(I)/util.h     $(I)/kdtree.h   
kdbuild.$o:  kdbuild.c  $(I)/machdefs.h $(I)/util.h     $(I)/kdtree.h   
kdnear.$o:   kdnear.c   $(I)/machdefs.h $(I)/util.h     $(I)/kdtree.h   
kdspan.$o:   kdspan.c   $(I)/machdefs.h $(I)/util.h     $(I)/kdtree.h   
kdtwoopt.$o: kdtwoopt.c $(I)/machdefs.h $(I)/util.h     $(I)/kdtree.h   
