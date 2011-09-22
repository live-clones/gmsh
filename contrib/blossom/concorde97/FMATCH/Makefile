SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=fmatch.a
LIBSRCS=fmatch.c
LIBS=$(ROOT)/EDGEGEN/edgegen.a $(ROOT)/KDTREE/kdtree.a \
     $(ROOT)/LINKERN/linkern.a $(ROOT)/UTIL/util.a
ALLSRCS=fm_main.c $(LIBSRCS)

all: fmatch $(LIB)

fmatch: fm_main.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

clean:
	-rm -f *.$o $(LIB) fmatch

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

fm_main.$o:  fm_main.c  $(I)/machdefs.h $(I)/util.h     $(I)/fmatch.h   \
        $(I)/kdtree.h   $(I)/edgegen.h  
fmatch.$o:   fmatch.c   $(I)/machdefs.h $(I)/util.h     $(I)/fmatch.h   \
        $(I)/kdtree.h   
