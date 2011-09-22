SHELL=/bin/sh

DIRS=BIGGUY CUT EDGEGEN FMATCH KDTREE LINKERN LP TSP UTIL XSTUFF

.PHONY: top
top: concorde.h concorde.a

all: concorde.h concorde.a
	for i in $(DIRS); do $(MAKE) -C $$i $@; done

.PHONY: concorde.a
concorde.a:
	for i in $(DIRS); do $(MAKE) -C $$i concorde.a; done

INC_LIST=INCLUDE/util.h     INCLUDE/bigguy.h   INCLUDE/lp.h       \
         INCLUDE/kdtree.h   INCLUDE/cut.h      INCLUDE/edgegen.h  \
         INCLUDE/tsp.h      INCLUDE/Xstuff.h   INCLUDE/fmatch.h   \
         INCLUDE/linkern.h  INCLUDE/macrorus.h

concorde.h: INCLUDE/prefix.h $(INC_LIST) Makefile
	cat INCLUDE/prefix.h > concorde.h
	cat $(INC_LIST) | grep -v '#include' >> concorde.h

clean:
	-rm -f *.o concorde.h concorde.a
	for i in $(DIRS); do $(MAKE) -C $$i $@; done

%:
	for i in $(DIRS); do $(MAKE) -C $$i $@; done
