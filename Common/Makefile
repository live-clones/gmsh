# $Id: Makefile,v 1.25 2001-08-11 23:24:10 geuzaine Exp $
#
# Makefile for "libCommon.a"
#

.IGNORE:

CC      = c++
AR      = ar ruvs
RANLIB  = ranlib
RM      = rm

LIB     = ../lib/libCommon.a
INCLUDE = -I../includes -I../Common -I../DataStr -I../Geo -I../Graphics\
          -I../Mesh -I../Parser -I../Motif -I../Fltk

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_FLTK

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS = -f
CFLAGS  = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
          $(GL_INCLUDE) $(GUI_INCLUDE)

SRC =  	Context.cpp\
        Views.cpp\
        Iso.cpp\
        Options.cpp\
        GetOptions.cpp\
        Timer.cpp\
        ColorTable.cpp\
        Numeric.cpp

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

res:
	windres Icon.rc -O coff Icon.res

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
