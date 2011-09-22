SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=bigguy.a
LIBSRCS=bigguy.c
ALLSRCS=bg_test.c $(LIBSRCS)
LIBS=$(ROOT)/UTIL/util.a

all: bg_test $(LIB)

bg_test: bg_test.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

test: bg_test
	time bg_test < bigguy.tst > bigguy.ts2
	cmp bigguy.tst bigguy.ts2

clean:
	-rm -f *.$o $(LIB) bg_test bigguy.ts2

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

bg_test.$o:  bg_test.c  $(I)/machdefs.h $(I)/util.h     $(I)/bigguy.h   
bigguy.$o:   bigguy.c   $(I)/machdefs.h $(I)/util.h     $(I)/bigguy.h   
