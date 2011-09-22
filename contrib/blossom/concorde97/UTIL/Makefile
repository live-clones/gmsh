SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=util.a
LIBSRCS=allocrus.c bgetopt.c  dheaps_i.c edg2cyc.c  edgelen.c  fastread.c \
        getdata.c  safe_io.c  sortrus.c  urandom.c  util.c     zeit.c     \
        genhash.c  priority.c
ALLSRCS=$(LIBSRCS)

all: $(LIB)

clean:
	-rm -f *.$o $(LIB)

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

allocrus.$o: allocrus.c $(I)/machdefs.h $(I)/util.h     
bgetopt.$o:  bgetopt.c  $(I)/machdefs.h $(I)/util.h     
dheaps_i.$o: dheaps_i.c $(I)/machdefs.h $(I)/util.h     
edg2cyc.$o:  edg2cyc.c  $(I)/machdefs.h $(I)/util.h     
edgelen.$o:  edgelen.c  $(I)/machdefs.h $(I)/util.h     
fastread.$o: fastread.c $(I)/machdefs.h $(I)/util.h     
genhash.$o:  genhash.c  $(I)/machdefs.h $(I)/util.h     
getdata.$o:  getdata.c  $(I)/machdefs.h $(I)/util.h     
priority.$o: priority.c $(I)/machdefs.h $(I)/util.h     
safe_io.$o:  safe_io.c  $(I)/machdefs.h $(I)/util.h     
sortrus.$o:  sortrus.c  $(I)/machdefs.h $(I)/util.h     
urandom.$o:  urandom.c  $(I)/machdefs.h $(I)/util.h     
util.$o:     util.c     $(I)/machdefs.h $(I)/macrorus.h $(I)/util.h     
zeit.$o:     zeit.c     $(I)/machdefs.h $(I)/util.h     
