#
# Makefile for "libAdapt.a"
#

.IGNORE:

CC        = c++
C_FLAGS   = -g

OS_FLAGS  = -D_UNIX

RM        = rm
RMFLAGS   = -f
RANLIB    = ranlib

LIB       = ../lib/libAdapt.a
INCLUDE   = -I../Common -I../DataStr

CFLAGS    = $(C_FLAGS) $(OS_FLAGS) $(INCLUDE) 

SRC = brent.cpp \
      mnbrak.cpp \
      nrutil.cpp \
      optimesh.cpp \
      dsvdcmp.cpp \
      newt.cpp \
      fmin.cpp \
      fdjac.cpp \
      lnsrch.cpp \
      lubksb.cpp \
      ludcmp.cpp

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
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
brent.o: brent.cpp nrutil.h ../Common/Const.h
mnbrak.o: mnbrak.cpp nrutil.h ../Common/Const.h
nrutil.o: nrutil.cpp
optimesh.o: optimesh.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h Adapt.h nrutil.h \
 ../Common/Const.h
dsvdcmp.o: dsvdcmp.cpp nrutil.h ../Common/Const.h
newt.o: newt.cpp nrutil.h ../Common/Const.h
fmin.o: fmin.cpp nrutil.h ../Common/Const.h
fdjac.o: fdjac.cpp nrutil.h ../Common/Const.h
lnsrch.o: lnsrch.cpp nrutil.h ../Common/Const.h
lubksb.o: lubksb.cpp
ludcmp.o: ludcmp.cpp nrutil.h ../Common/Const.h
