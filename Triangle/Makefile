# $Id: Makefile,v 1.11 2003-02-12 01:41:33 geuzaine Exp $

include ../variables

LIB = ../lib/libGmshTriangle.a

# Do not optimize: it crashes badly on Linux
CFLAGS  = -O0 ${OS_FLAGS} -DTRILIBRARY

SRC = triangle.c

OBJ = ${SRC:.c=.o}

.SUFFIXES: .o .c

${LIB}: ${OBJ} 
	${AR} ${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.c.o:
	${CC} ${CFLAGS} -c $<

clean:
	rm -f *.o triangle showme tricall *.?.poly *.?.node *.?.ele

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CC} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
triangle.o: triangle.c triangle.h
