# $Id: Makefile,v 1.8 2002-04-13 04:01:09 geuzaine Exp $
#
# Makefile for "libParallel.a"
#

.IGNORE:
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib
LIB      = ../lib/libParallel.a
CC       = gcc

OPT_FLAGS     = -g
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = ParUtil.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CXX) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
ParUtil.o: ParUtil.cpp ParUtil.h
