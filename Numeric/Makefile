# $Id: Makefile,v 1.27 2006-07-25 12:08:24 remacle Exp $
#
# Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

include ../variables

LIB     = ../lib/libGmshNumeric.a
INCLUDE = -I../Common -I../DataStr
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = Numeric.cpp\
      EigSolve.cpp\
      gsl_newt.cpp\
      gsl_brent.cpp

OBJ = ${SRC:.cpp=.o}

.SUFFIXES: .o .cpp

${LIB}: ${OBJ}
	${AR} ${LIB} ${OBJ}
	${RANLIB} ${LIB}

.cpp.o:
	${CXX} ${CFLAGS} -c $<

clean:
	rm -f *.o 

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Numeric.o: Numeric.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Numeric.h /sw/include/gsl/gsl_version.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_errno.h
EigSolve.o: EigSolve.cpp
gsl_newt.o: gsl_newt.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Numeric.h /sw/include/gsl/gsl_math.h /sw/include/gsl/gsl_sys.h \
  /sw/include/gsl/gsl_machine.h /sw/include/gsl/gsl_precision.h \
  /sw/include/gsl/gsl_types.h /sw/include/gsl/gsl_nan.h \
  /sw/include/gsl/gsl_pow_int.h /sw/include/gsl/gsl_errno.h \
  /sw/include/gsl/gsl_multiroots.h /sw/include/gsl/gsl_vector.h \
  /sw/include/gsl/gsl_vector_complex_long_double.h \
  /sw/include/gsl/gsl_complex.h /sw/include/gsl/gsl_check_range.h \
  /sw/include/gsl/gsl_vector_long_double.h \
  /sw/include/gsl/gsl_block_long_double.h \
  /sw/include/gsl/gsl_vector_complex.h \
  /sw/include/gsl/gsl_block_complex_long_double.h \
  /sw/include/gsl/gsl_vector_complex_double.h \
  /sw/include/gsl/gsl_vector_double.h /sw/include/gsl/gsl_block_double.h \
  /sw/include/gsl/gsl_block_complex_double.h \
  /sw/include/gsl/gsl_vector_complex_float.h \
  /sw/include/gsl/gsl_vector_float.h /sw/include/gsl/gsl_block_float.h \
  /sw/include/gsl/gsl_block_complex_float.h \
  /sw/include/gsl/gsl_vector_ulong.h /sw/include/gsl/gsl_block_ulong.h \
  /sw/include/gsl/gsl_vector_long.h /sw/include/gsl/gsl_block_long.h \
  /sw/include/gsl/gsl_vector_uint.h /sw/include/gsl/gsl_block_uint.h \
  /sw/include/gsl/gsl_vector_int.h /sw/include/gsl/gsl_block_int.h \
  /sw/include/gsl/gsl_vector_ushort.h /sw/include/gsl/gsl_block_ushort.h \
  /sw/include/gsl/gsl_vector_short.h /sw/include/gsl/gsl_block_short.h \
  /sw/include/gsl/gsl_vector_uchar.h /sw/include/gsl/gsl_block_uchar.h \
  /sw/include/gsl/gsl_vector_char.h /sw/include/gsl/gsl_block_char.h \
  /sw/include/gsl/gsl_matrix.h \
  /sw/include/gsl/gsl_matrix_complex_long_double.h \
  /sw/include/gsl/gsl_matrix_complex_double.h \
  /sw/include/gsl/gsl_matrix_complex_float.h \
  /sw/include/gsl/gsl_matrix_long_double.h \
  /sw/include/gsl/gsl_matrix_double.h /sw/include/gsl/gsl_matrix_float.h \
  /sw/include/gsl/gsl_matrix_ulong.h /sw/include/gsl/gsl_matrix_long.h \
  /sw/include/gsl/gsl_matrix_uint.h /sw/include/gsl/gsl_matrix_int.h \
  /sw/include/gsl/gsl_matrix_ushort.h /sw/include/gsl/gsl_matrix_short.h \
  /sw/include/gsl/gsl_matrix_uchar.h /sw/include/gsl/gsl_matrix_char.h \
  /sw/include/gsl/gsl_linalg.h /sw/include/gsl/gsl_mode.h \
  /sw/include/gsl/gsl_permutation.h
gsl_brent.o: gsl_brent.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Numeric.h /sw/include/gsl/gsl_errno.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_math.h /sw/include/gsl/gsl_sys.h \
  /sw/include/gsl/gsl_machine.h /sw/include/gsl/gsl_precision.h \
  /sw/include/gsl/gsl_nan.h /sw/include/gsl/gsl_pow_int.h \
  /sw/include/gsl/gsl_min.h
