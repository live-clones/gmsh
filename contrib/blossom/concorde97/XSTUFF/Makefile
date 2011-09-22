SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=Xstuff.a
LIBSRCS=Xourallo.c Xgraph.c   Xshrink.c Xflow.c   Xcututil.c Xcuthash.c \
        Xcclean.c  Xcutload.c Xblock.c  Xclique.c Xgomhu.c   Xblossom.c \
        Xcuts.c    Xblobs.c   Xstuff.c  Xpqnew.c  Xnewkids.c Xallcuts.c \
        Xnecklac.c
ALLSRCS=Xtest.c    $(LIBSRCS)

LIBS=$(ROOT)/TSP/tsp.a       $(ROOT)/BIGGUY/bigguy.a   \
     $(ROOT)/LP/lp.a         $(ROOT)/CUT/cut.a         \
     $(ROOT)/FMATCH/fmatch.a $(ROOT)/EDGEGEN/edgegen.a \
     $(ROOT)/KDTREE/kdtree.a $(ROOT)/LINKERN/linkern.a \
     $(ROOT)/UTIL/util.a

all: Xtest $(LIB)

Xtest: Xtest.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ $(CPLEX_LIB) -lm

clean:
	-rm -f *.$o $(LIB) Xtest

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

Xallcuts.$o: Xallcuts.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xblobs.$o:   Xblobs.c   $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xblock.$o:   Xblock.c   $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xblossom.$o: Xblossom.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xcclean.$o:  Xcclean.c  $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xclique.$o:  Xclique.c  $(I)/machdefs.h      Xsubtour.h      Xcutpool.h 
Xcuthash.$o: Xcuthash.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xcutload.$o: Xcutload.c $(I)/machdefs.h      Xsubtour.h      Xcutpool.h 
Xcuts.$o:    Xcuts.c    $(I)/machdefs.h      Xsubtour.h      Xcutpool.h 
Xcututil.$o: Xcututil.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xflow.$o:    Xflow.c    $(I)/machdefs.h      Xsubtour.h      Xcutpool.h 
Xgomhu.$o:   Xgomhu.c   $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xgraph.$o:   Xgraph.c   $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h 
Xnecklac.$o: Xnecklac.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h      Xpq.h           Xpqsets.h       Xnecklac.h 
Xnewkids.$o: Xnewkids.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h      Xpq.h           Xpqsets.h  
Xourallo.$o: Xourallo.c $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h      Xnecklac.h 
Xpqnew.$o:   Xpqnew.c   $(I)/machdefs.h $(I)/util.h          Xsubtour.h \
             Xcutpool.h      Xpq.h           Xpqsets.h  
Xshrink.$o:  Xshrink.c  $(I)/machdefs.h      Xsubtour.h      Xcutpool.h 
Xstuff.$o:   Xstuff.c   $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h        Xsubtour.h      Xcutpool.h $(I)/Xstuff.h   
Xtest.$o:    Xtest.c    $(I)/machdefs.h $(I)/util.h     $(I)/tsp.h      \
        $(I)/edgegen.h  $(I)/bigguy.h   $(I)/lp.h       $(I)/cut.h      \
        $(I)/kdtree.h   $(I)/Xstuff.h   
