# $Id: Makefile,v 1.26 2001-08-07 21:00:10 remacle Exp $
#
# Makefile for "libGraphics.a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RANLIB   = ranlib
RM       = rm
LIB      = ../lib/libGraphics.a
INCLUDE  = -I../Common -I../DataStr -I../Geo -I../Graphics\
           -I../Motif -I../Fltk -I../Mesh -I../Parser -I../jpeg

C_FLAGS       = -g -Wall
OS_FLAGS      = -D_LITTLE_ENDIAN
VERSION_FLAGS = -D_XMOTIF

GL_INCLUDE    = -I$(HOME)/SOURCES/Mesa-3.1/include\
                -I$(HOME)/SOURCES/Mesa-3.1/include/GL
GUI_INCLUDE   = -I/usr/X11R6/LessTif/Motif1.2/include

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE)\
           $(GL_INCLUDE) $(GUI_INCLUDE)

SRC = Draw.cpp \
      Mesh.cpp \
      Geom.cpp \
      Post.cpp \
      PostSimplex.cpp \
      IsoSimplex.cpp \
      Entity.cpp \
      Scale.cpp \
      Axes.cpp \
      CreateFile.cpp \
      XDump.cpp\
      gl2ps.cpp\
      gl2gif.cpp\
      gl2jpeg.cpp\
      gl2ppm.cpp\
      gl2yuv.cpp


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
