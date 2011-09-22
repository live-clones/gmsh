SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=cut.a
LIBSRCS=segments.c connect.c  shrink.c mincut.c cut_st.c
ALLSRCS=mc_main.c  $(LIBSRCS)
LIBS=$(ROOT)/UTIL/util.a

all: mincut $(LIB)

mincut: mc_main.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

clean:
	-rm -f *.$o $(LIB) mincut

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

connect.$o:  connect.c  $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
cut_st.$o:   cut_st.c   $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
mc_main.$o:  mc_main.c  $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
mincut.$o:   mincut.c   $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
segments.$o: segments.c $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
shrink.$o:   shrink.c   $(I)/machdefs.h $(I)/util.h     $(I)/cut.h      
