# $Id: Makefile,v 1.4 2002-05-18 21:34:29 geuzaine Exp $
#
# Makefile for "libGmshNumeric.a"
#

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
      Newton.cpp \
      Opti.cpp \
      SVD.cpp \
      NRUtil.cpp \

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
Numeric.o: Numeric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h Numeric.h
Newton.o: Newton.cpp NRUtil.h Numeric.h
Opti.o: Opti.cpp NRUtil.h Numeric.h
SVD.o: SVD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  NRUtil.h Numeric.h
NRUtil.o: NRUtil.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h
