# $Id: Makefile,v 1.18 2001-08-11 23:24:10 geuzaine Exp $
#
# Makefile for "libJpeg.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib

LIB      = ../lib/libJpeg.a
INCLUDE  = -I.

C_FLAGS       = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)

SRC = jcomapi.c jutils.c jerror.c jmemmgr.c jmemnobs.c \
      jcapi.c jcparam.c jdatadst.c jcmaster.c jcmarker.c jcmainct.c \
      jcprepct.c jccoefct.c jccolor.c jcsample.c jchuff.c jcdctmgr.c \
      jfdctfst.c jfdctflt.c jfdctint.c

OBJ = $(SRC:.c=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
