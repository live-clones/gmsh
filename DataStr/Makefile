# $Id: Makefile,v 1.17 2003-02-10 18:57:02 geuzaine Exp $
#
# Makefile for "libGmshDataStr.a"
#

CXX    = c++
AR     = ar ruvs
RM     = rm
RANLIB = ranlib

LIB     = ../lib/libGmshDataStr.a
INCLUDE = -I../Common

OPT_FLAGS     =
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)

SRC = List.cpp \
      Malloc.cpp \
      SafeIO.cpp \
      Tree.cpp \
      avl.cpp \
      Tools.cpp

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
	$(RM) Makefile.new

# DO NOT DELETE THIS LINE
List.o: List.cpp Malloc.h List.h SafeIO.h ../Common/Message.h
Malloc.o: Malloc.cpp Malloc.h ../Common/Message.h
SafeIO.o: SafeIO.cpp SafeIO.h ../Common/Message.h
Tree.o: Tree.cpp Malloc.h Tree.h avl.h ../Common/Message.h
avl.o: avl.cpp avl.h Malloc.h
Tools.o: Tools.cpp Tools.h List.h Tree.h avl.h
