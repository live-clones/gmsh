# $Id: Makefile,v 1.20 2003-02-23 05:51:27 geuzaine Exp $

include ../variables

LIB     = ../lib/libGmshDataStr.a
INCLUDE = -I../Common
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = List.cpp \
      Malloc.cpp \
      SafeIO.cpp \
      Tree.cpp \
      avl.cpp \
      Tools.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ}
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

clean:
	rm -f *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
List.o: List.cpp Malloc.h List.h ../Common/Message.h SafeIO.h
Malloc.o: Malloc.cpp Malloc.h ../Common/Message.h
SafeIO.o: SafeIO.cpp SafeIO.h ../Common/Message.h
Tree.o: Tree.cpp Malloc.h Tree.h avl.h ../Common/Message.h
avl.o: avl.cpp avl.h Malloc.h
Tools.o: Tools.cpp Tools.h List.h Tree.h avl.h
