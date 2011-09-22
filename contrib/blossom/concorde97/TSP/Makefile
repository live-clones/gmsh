SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=tsp.a
LIBSRCS=prob_io.c  tsp_lp.c   qsparse.c  cliqhash.c generate.c edgemap.c \
        ex_price.c cutcall.c  tighten.c  cutpool.c  branch.c   control.c \
        cliqwork.c teething.c bcontrol.c xtour.c
ALLSRCS=concorde.c poolcat.c  $(LIBSRCS)
LIBS=$(ROOT)/LINKERN/linkern.a $(ROOT)/EDGEGEN/edgegen.a \
     $(ROOT)/KDTREE/kdtree.a   $(ROOT)/FMATCH/fmatch.a   \
     $(ROOT)/XSTUFF/Xstuff.a   $(ROOT)/UTIL/util.a       \
     $(ROOT)/BIGGUY/bigguy.a   $(ROOT)/CUT/cut.a         \
     $(ROOT)/LP/lp.a

all: concorde poolcat $(LIB)

concorde: concorde.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ $(CPLEX_LIB) -lm

poolcat: poolcat.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ $(CPLEX_LIB) -lm

clean:
	-rm -f *.$o $(LIB) concorde poolcat

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

bcontrol.$o: bcontrol.c $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  \
        $(I)/tsp.h      $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
branch.$o:   branch.c   $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/tsp.h      $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
cliqhash.$o: cliqhash.c $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
cliqwork.$o: cliqwork.c $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
concorde.$o: concorde.c $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  \
        $(I)/tsp.h      $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   $(I)/linkern.h  $(I)/macrorus.h 
control.$o:  control.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   $(I)/Xstuff.h   
cutcall.$o:  cutcall.c  $(I)/machdefs.h $(I)/macrorus.h $(I)/util.h     \
        $(I)/tsp.h      $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
cutpool.$o:  cutpool.c  $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/tsp.h      $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
edgemap.$o:  edgemap.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   $(I)/macrorus.h 
ex_price.$o: ex_price.c $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/bigguy.h   $(I)/tsp.h      $(I)/edgegen.h  $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
generate.$o: generate.c $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/tsp.h      $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
poolcat.$o:  poolcat.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
prob_io.$o:  prob_io.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
qsparse.$o:  qsparse.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
teething.$o: teething.c $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
tighten.$o:  tighten.c  $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   
tsp_lp.$o:   tsp_lp.c   $(I)/machdefs.h $(I)/util.h     $(I)/macrorus.h \
        $(I)/fmatch.h   $(I)/edgegen.h  $(I)/linkern.h  $(I)/tsp.h      \
        $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      $(I)/kdtree.h   
xtour.$o:    xtour.c    $(I)/machdefs.h $(I)/util.h     $(I)/edgegen.h  \
        $(I)/linkern.h  $(I)/tsp.h      $(I)/bigguy.h   $(I)/lp.h       \
        $(I)/cut.h      $(I)/kdtree.h   
