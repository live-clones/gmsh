# $Id: Makefile,v 1.2 2002-05-18 09:14:33 geuzaine Exp $
#
# Makefile for "libGmshNumeric.a"
#

.IGNORE:

CXX    = c++
AR     = ar ruvs
RM     = rm
RANLIB = ranlib

LIB     = ../lib/libGmshNumeric.a
INCLUDE = -I../Common -I../DataStr

OPT_FLAGS     =
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = 

RMFLAGS = -f
CFLAGS  = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Numeric.cpp\
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

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CXX) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
mnbrak.o: mnbrak.cpp nrutil.h Numeric.h
brent.o: brent.cpp nrutil.h Numeric.h
nrutil.o: nrutil.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h
dsvdcmp.o: dsvdcmp.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h nrutil.h Numeric.h
newt.o: newt.cpp nrutil.h Numeric.h
fmin.o: fmin.cpp nrutil.h Numeric.h
fdjac.o: fdjac.cpp nrutil.h Numeric.h
lnsrch.o: lnsrch.cpp nrutil.h Numeric.h
lubksb.o: lubksb.cpp
ludcmp.o: ludcmp.cpp nrutil.h Numeric.h
