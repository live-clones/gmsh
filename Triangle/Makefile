# $Id: Makefile,v 1.13 2003-02-18 05:50:10 geuzaine Exp $

include ../variables

LIB = ../lib/libGmshTriangle.a

# Do not optimize triangle: it crashes badly on Linux
OPTIM = -O0
CFLAGS = ${OPTIM} ${FLAGS} -DTRILIBRARY

SRC = triangle.c

OBJ = ${SRC:.c=.o}

.SUFFIXES: .o .c

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f *.o

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CC} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
triangle.o: triangle.c triangle.h
