# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB = ../../lib/libGmshNativeFileChooser${LIBEXT}

INC = ${DASH}I.

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}DFLTK1

SRC = Fl_Native_File_Chooser.cxx
OBJ = ${SRC:.cxx=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cxx

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../../lib/

.cxx${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

clean:
	rm -f *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Fl_Native_File_Chooser.o: Fl_Native_File_Chooser.cxx \
  Fl_Native_File_Chooser_MAC.cxx common.cxx FL/Fl_Native_File_Chooser.H \
  FL/Fl_Native_File_Chooser_MAC.H
