SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=lp.a

ifneq ($(CPLEX_LIB),)
LIBSRCS=lpcplex.c
else
LIBSRCS=lpsolve.c
endif
ALLSRCS=lpsolve.c lpcplex.c

all: $(LIB)

clean:
	-rm -f *.$o $(LIB)

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

lpcplex.$o:  lpcplex.c  $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/lp.h       
lpsolve.$o:  lpsolve.c  $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/lp.h       
