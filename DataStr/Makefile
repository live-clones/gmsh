#
# Makefile for "libSataStr.a"
#

.IGNORE:

CC        = c++
C_FLAGS   = -g -Wall

RANLIB   = /usr/bin/ranlib

LIB      = ../lib/libDataStr.a
INCLUDE  = -I../Common

CFLAGS = $(C_FLAGS) $(OS_FLAGS) $(INCLUDE)

SRC = List.cpp \
      Malloc.cpp \
      Tree.cpp \
      avl.cpp \
      Tools.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ)
	ar ruvs $(LIB) $(OBJ)
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	lint $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) Makefile.new


# DO NOT DELETE THIS LINE
List.o: List.cpp Malloc.h List.h ../Common/Message.h
Malloc.o: Malloc.cpp Malloc.h ../Common/Message.h
Tree.o: Tree.cpp Malloc.h Tree.h avl.h ../Common/Message.h
avl.o: avl.cpp avl.h Malloc.h
Tools.o: Tools.cpp Tools.h List.h Tree.h avl.h
