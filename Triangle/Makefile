# $Id: Makefile,v 1.9 2003-02-10 23:07:05 geuzaine Exp $

CC     = gcc
AR     = ar ruvs
RM     = rm
RANLIB = ranlib
RMFLAGS = -f

LIB = ../lib/libGmshTriangle.a

# Do not optimize: it crashed on Linux
CFLAGS  = -O0 $(OS_FLAGS) -DTRILIBRARY

SRC = triangle.c

OBJ = $(SRC:.c=.o)

.SUFFIXES: .o .c

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o triangle showme tricall *.?.poly *.?.node *.?.ele

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
triangle.o: triangle.c triangle.h
