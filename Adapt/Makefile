# $Id: Makefile,v 1.24 2001-12-04 10:47:39 geuzaine Exp $
#
# Makefile for "libAdapt.a"
#

.IGNORE:

CXX       = c++
AR        = ar ruvs
RM        = rm
RANLIB    = ranlib

LIB       = ../lib/libAdapt.a
INCLUDE   = -I../Common -I../DataStr

OPT_FLAGS     = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS   = -f
CFLAGS    = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Adapt.cpp \
      mnbrak.cpp \
      brent.cpp \
      nrutil.cpp \
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
Adapt.o: Adapt.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h Adapt.h nrutil.h \
 ../Common/Numeric.h
mnbrak.o: mnbrak.cpp nrutil.h ../Common/Numeric.h
brent.o: brent.cpp nrutil.h ../Common/Numeric.h
nrutil.o: nrutil.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h
dsvdcmp.o: dsvdcmp.cpp ../Common/Gmsh.h ../Common/Message.h \
 ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
 ../DataStr/avl.h ../DataStr/Tools.h nrutil.h ../Common/Numeric.h
newt.o: newt.cpp nrutil.h ../Common/Numeric.h
fmin.o: fmin.cpp nrutil.h ../Common/Numeric.h
fdjac.o: fdjac.cpp nrutil.h ../Common/Numeric.h
lnsrch.o: lnsrch.cpp nrutil.h ../Common/Numeric.h
lubksb.o: lubksb.cpp
ludcmp.o: ludcmp.cpp nrutil.h ../Common/Numeric.h
