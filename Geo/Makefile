# $Id: Makefile,v 1.20 2001-08-07 21:00:10 remacle Exp $
#
# Makefile for "libGeo.a"
#

.IGNORE:

CC      = c++
AR      = ar ruvs
RANLIB  = ranlib
RM      = rm

LIB       = ../lib/libGeo.a
INCLUDE   = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Parser\
            -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)

SRC =  	CAD.cpp \
        DataBase.cpp \
        MinMax.cpp \
        ExtrudeParams.cpp \
        Geo.cpp \
        StepGeomDatabase.cpp \
	Verif.cpp \
	Visibility.cpp \
        Print_Geo.cpp

OBJ = $(SRC:.cpp=.o)

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
