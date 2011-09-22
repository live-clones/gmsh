SHELL=/bin/sh
ROOT=..
INCLUDE=$(ROOT)/INCLUDE

include $(ROOT)/Makefile.conf

# place overrides for COMFLAGS, OPTFLAGS, and LOADFLAGS here
#OPTFLAGS=-g

LIB=linkern.a
LIBSRCS=linkern.c flip_two.c
ALLSRCS=lk_main.c  linkern.c  flip_ary.c flip_bt0.c flip_bt1.c \
        flip_bt2.c flip_bt3.c flip_bt4.c flip_bt5.c flip_btc.c \
        flip_btd.c flip_btr.c flip_ll0.c flip_ll1.c flip_ll2.c \
        flip_ll3.c flip_ll4.c flip_ll5.c flip_ll6.c flip_ll7.c \
        flip_ll8.c flip_ll9.c flip_llA.c flip_llB.c flip_llC.c \
        flip_llD.c flip_sg1.c flip_sg2.c flip_sg3.c flip_sp1.c \
        flip_sp2.c flip_try.c flip_tw2.c flip_two.c

LIBS=$(ROOT)/EDGEGEN/edgegen.a $(ROOT)/KDTREE/kdtree.a \
     $(ROOT)/FMATCH/fmatch.a   $(ROOT)/UTIL/util.a

all: linkern $(LIB)

linkern: lk_main.$o $(LIB) $(LIBS)
	$(CC) $(LDFLAGS) -o $@ $+ -lm

clean:
	-rm -f *.$o $(LIB) linkern

include $(INCLUDE)/Makefile.common

# DO NOT DELETE THIS LINE -- make depend depends on it.

I=$(INCLUDE)

flip_ary.$o: flip_ary.c $(I)/machdefs.h $(I)/util.h     
flip_bt0.$o: flip_bt0.c $(I)/machdefs.h $(I)/util.h     
flip_bt1.$o: flip_bt1.c $(I)/machdefs.h $(I)/util.h     
flip_bt2.$o: flip_bt2.c $(I)/machdefs.h $(I)/util.h     
flip_bt3.$o: flip_bt3.c $(I)/machdefs.h $(I)/util.h     
flip_bt4.$o: flip_bt4.c $(I)/machdefs.h $(I)/util.h     
flip_bt5.$o: flip_bt5.c $(I)/machdefs.h $(I)/util.h     
flip_btc.$o: flip_btc.c $(I)/machdefs.h $(I)/util.h     
flip_btd.$o: flip_btd.c $(I)/machdefs.h $(I)/util.h     
flip_btr.$o: flip_btr.c $(I)/machdefs.h $(I)/util.h     
flip_ll0.$o: flip_ll0.c $(I)/machdefs.h $(I)/util.h     
flip_ll1.$o: flip_ll1.c $(I)/machdefs.h $(I)/util.h     
flip_ll2.$o: flip_ll2.c $(I)/machdefs.h $(I)/util.h     
flip_ll3.$o: flip_ll3.c $(I)/machdefs.h $(I)/util.h     
flip_ll4.$o: flip_ll4.c $(I)/machdefs.h $(I)/util.h     
flip_ll5.$o: flip_ll5.c $(I)/machdefs.h $(I)/util.h     
flip_ll6.$o: flip_ll6.c $(I)/machdefs.h $(I)/util.h     
flip_ll7.$o: flip_ll7.c $(I)/machdefs.h $(I)/util.h     
flip_ll8.$o: flip_ll8.c $(I)/machdefs.h $(I)/util.h     
flip_ll9.$o: flip_ll9.c $(I)/machdefs.h $(I)/util.h     
flip_llA.$o: flip_llA.c $(I)/machdefs.h $(I)/util.h     
flip_llB.$o: flip_llB.c $(I)/machdefs.h $(I)/util.h     
flip_llC.$o: flip_llC.c $(I)/machdefs.h $(I)/util.h     
flip_llD.$o: flip_llD.c $(I)/machdefs.h $(I)/util.h     
flip_sg1.$o: flip_sg1.c $(I)/machdefs.h $(I)/util.h     
flip_sg2.$o: flip_sg2.c $(I)/machdefs.h $(I)/util.h     
flip_sg3.$o: flip_sg3.c $(I)/machdefs.h $(I)/util.h     
flip_sp1.$o: flip_sp1.c $(I)/machdefs.h $(I)/util.h     
flip_sp2.$o: flip_sp2.c $(I)/machdefs.h $(I)/util.h     
flip_try.$o: flip_try.c $(I)/machdefs.h $(I)/util.h     
flip_tw2.$o: flip_tw2.c $(I)/machdefs.h $(I)/util.h     
flip_two.$o: flip_two.c $(I)/machdefs.h $(I)/util.h     $(I)/linkern.h  
linkern.$o:  linkern.c  $(I)/machdefs.h $(I)/util.h     $(I)/linkern.h  \
        $(I)/kdtree.h   
lk_main.$o:  lk_main.c  $(I)/machdefs.h $(I)/util.h     $(I)/linkern.h  \
        $(I)/kdtree.h   $(I)/edgegen.h  
