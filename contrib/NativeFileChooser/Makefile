# $Id: Makefile,v 1.4 2008-01-23 07:45:30 geuzaine Exp $
#
# Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to <gmsh@geuz.org>.

include ../../variables

LIB     = ../../lib/libGmshNativeFileChooser${LIBEXT}
INCLUDE = ${DASH}I.
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} ${SYSINCLUDE} ${DASH}DFLTK1

SRC = Fl_Native_File_Chooser.cxx
OBJ = ${SRC:.cxx=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cxx

${LIB}: ${OBJ} 
	${AR} ${ARFLAGS}${LIB} ${OBJ} 
	${RANLIB} ${LIB}

.cxx.o:
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
