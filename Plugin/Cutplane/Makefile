# $Id: Makefile,v 1.2 2001-03-04 22:57:36 remacle Exp $
#
# Makefile for "libAdapt.a"
#

.IGNORE:

CC        = c++
AR        = c++ -Wl,--subsystem,windows -shared -o
RM        = rm
RANLIB    = ranlib

LIB       = ../lib/libCutPlane.so
INCLUDE   = -I../../Common -I../

C_FLAGS       = -g -Wall 
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS   = -f
CFLAGS    = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = CutPlane.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ)
	$(AR) $(LIB) $(OBJ)

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
