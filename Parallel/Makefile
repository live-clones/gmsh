# $Id: Makefile,v 1.11 2002-05-18 16:31:16 geuzaine Exp $
#
# Makefile for "libGmshParallel.a"
#

CXX    = c++
AR     = ar ruvs
RM     = rm
RANLIB = ranlib

LIB     = ../lib/libGmshParallel.a
INCLUDE =

OPT_FLAGS     =
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

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

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
ParUtil.o: ParUtil.cpp ParUtil.h
