SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=edgegen.a
LIBSRCS=edgegen.c  xnear.c
ALLSRCS=eg_main.c  $(LIBSRCS)

LIBS=$(ROOT)/KDTREE/kdtree.a   $(ROOT)/FMATCH/fmatch.a \
     $(ROOT)/LINKERN/linkern.a $(ROOT)/UTIL/util.a

all: edgegen $(LIB)

edgegen: eg_main.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

clean:
	-rm -f *.$o $(LIB) edgegen

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

edgegen.$o:  edgegen.c  $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  \
        $(I)/kdtree.h   $(I)/linkern.h  $(I)/fmatch.h   
eg_main.$o:  eg_main.c  $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  
xnear.$o:    xnear.c    $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  
