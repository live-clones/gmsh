# $Id: Makefile,v 1.52 2008-05-19 18:50:34 remacle Exp $
#
# Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

LIB = ../lib/libGmshNumeric${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../DataStr ${DASH}I../Numeric ${DASH}I../contrib/NR

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Numeric.cpp\
        NumericEmbedded.cpp\
      EigSolve.cpp\
      FunctionSpace.cpp\
      gmsh_predicates.cpp\
      gsl_newt.cpp\
      gsl_min.cpp\
      gsl_brent.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
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
Numeric.o: Numeric.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw//include/gsl/gsl_version.h /sw//include/gsl/gsl_types.h \
  /sw//include/gsl/gsl_errno.h /sw//include/gsl/gsl_vector.h \
  /sw//include/gsl/gsl_vector_complex_long_double.h \
  /sw//include/gsl/gsl_complex.h /sw//include/gsl/gsl_check_range.h \
  /sw//include/gsl/gsl_vector_long_double.h \
  /sw//include/gsl/gsl_block_long_double.h \
  /sw//include/gsl/gsl_vector_complex.h \
  /sw//include/gsl/gsl_block_complex_long_double.h \
  /sw//include/gsl/gsl_vector_complex_double.h \
  /sw//include/gsl/gsl_vector_double.h \
  /sw//include/gsl/gsl_block_double.h \
  /sw//include/gsl/gsl_block_complex_double.h \
  /sw//include/gsl/gsl_vector_complex_float.h \
  /sw//include/gsl/gsl_vector_float.h /sw//include/gsl/gsl_block_float.h \
  /sw//include/gsl/gsl_block_complex_float.h \
  /sw//include/gsl/gsl_vector_ulong.h /sw//include/gsl/gsl_block_ulong.h \
  /sw//include/gsl/gsl_vector_long.h /sw//include/gsl/gsl_block_long.h \
  /sw//include/gsl/gsl_vector_uint.h /sw//include/gsl/gsl_block_uint.h \
  /sw//include/gsl/gsl_vector_int.h /sw//include/gsl/gsl_block_int.h \
  /sw//include/gsl/gsl_vector_ushort.h \
  /sw//include/gsl/gsl_block_ushort.h /sw//include/gsl/gsl_vector_short.h \
  /sw//include/gsl/gsl_block_short.h /sw//include/gsl/gsl_vector_uchar.h \
  /sw//include/gsl/gsl_block_uchar.h /sw//include/gsl/gsl_vector_char.h \
  /sw//include/gsl/gsl_block_char.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_matrix.h \
  /sw//include/gsl/gsl_matrix_complex_long_double.h \
  /sw//include/gsl/gsl_matrix_complex_double.h \
  /sw//include/gsl/gsl_matrix_complex_float.h \
  /sw//include/gsl/gsl_matrix_long_double.h \
  /sw//include/gsl/gsl_matrix_double.h \
  /sw//include/gsl/gsl_matrix_float.h /sw//include/gsl/gsl_matrix_ulong.h \
  /sw//include/gsl/gsl_matrix_long.h /sw//include/gsl/gsl_matrix_uint.h \
  /sw//include/gsl/gsl_matrix_int.h /sw//include/gsl/gsl_matrix_ushort.h \
  /sw//include/gsl/gsl_matrix_short.h /sw//include/gsl/gsl_matrix_uchar.h \
  /sw//include/gsl/gsl_matrix_char.h
NumericEmbedded.o: NumericEmbedded.cpp NumericEmbedded.h \
  ../Common/Message.h
EigSolve.o: EigSolve.cpp
FunctionSpace.o: FunctionSpace.cpp FunctionSpace.h ../Common/GmshMatrix.h \
  /sw//include/gsl/gsl_linalg.h /sw//include/gsl/gsl_mode.h \
  /sw//include/gsl/gsl_permutation.h /sw//include/gsl/gsl_types.h \
  /sw//include/gsl/gsl_errno.h /sw//include/gsl/gsl_check_range.h \
  /sw//include/gsl/gsl_vector.h \
  /sw//include/gsl/gsl_vector_complex_long_double.h \
  /sw//include/gsl/gsl_complex.h \
  /sw//include/gsl/gsl_vector_long_double.h \
  /sw//include/gsl/gsl_block_long_double.h \
  /sw//include/gsl/gsl_vector_complex.h \
  /sw//include/gsl/gsl_block_complex_long_double.h \
  /sw//include/gsl/gsl_vector_complex_double.h \
  /sw//include/gsl/gsl_vector_double.h \
  /sw//include/gsl/gsl_block_double.h \
  /sw//include/gsl/gsl_block_complex_double.h \
  /sw//include/gsl/gsl_vector_complex_float.h \
  /sw//include/gsl/gsl_vector_float.h /sw//include/gsl/gsl_block_float.h \
  /sw//include/gsl/gsl_block_complex_float.h \
  /sw//include/gsl/gsl_vector_ulong.h /sw//include/gsl/gsl_block_ulong.h \
  /sw//include/gsl/gsl_vector_long.h /sw//include/gsl/gsl_block_long.h \
  /sw//include/gsl/gsl_vector_uint.h /sw//include/gsl/gsl_block_uint.h \
  /sw//include/gsl/gsl_vector_int.h /sw//include/gsl/gsl_block_int.h \
  /sw//include/gsl/gsl_vector_ushort.h \
  /sw//include/gsl/gsl_block_ushort.h /sw//include/gsl/gsl_vector_short.h \
  /sw//include/gsl/gsl_block_short.h /sw//include/gsl/gsl_vector_uchar.h \
  /sw//include/gsl/gsl_block_uchar.h /sw//include/gsl/gsl_vector_char.h \
  /sw//include/gsl/gsl_block_char.h /sw//include/gsl/gsl_matrix.h \
  /sw//include/gsl/gsl_matrix_complex_long_double.h \
  /sw//include/gsl/gsl_matrix_complex_double.h \
  /sw//include/gsl/gsl_matrix_complex_float.h \
  /sw//include/gsl/gsl_matrix_long_double.h \
  /sw//include/gsl/gsl_matrix_double.h \
  /sw//include/gsl/gsl_matrix_float.h /sw//include/gsl/gsl_matrix_ulong.h \
  /sw//include/gsl/gsl_matrix_long.h /sw//include/gsl/gsl_matrix_uint.h \
  /sw//include/gsl/gsl_matrix_int.h /sw//include/gsl/gsl_matrix_ushort.h \
  /sw//include/gsl/gsl_matrix_short.h /sw//include/gsl/gsl_matrix_uchar.h \
  /sw//include/gsl/gsl_matrix_char.h /sw//include/gsl/gsl_blas.h \
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h \
  ../Common/GmshDefines.h
gmsh_predicates.o: gmsh_predicates.cpp
gsl_newt.o: gsl_newt.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw//include/gsl/gsl_math.h /sw//include/gsl/gsl_sys.h \
  /sw//include/gsl/gsl_machine.h /sw//include/gsl/gsl_precision.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_nan.h \
  /sw//include/gsl/gsl_pow_int.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_multiroots.h /sw//include/gsl/gsl_vector.h \
  /sw//include/gsl/gsl_vector_complex_long_double.h \
  /sw//include/gsl/gsl_complex.h /sw//include/gsl/gsl_check_range.h \
  /sw//include/gsl/gsl_vector_long_double.h \
  /sw//include/gsl/gsl_block_long_double.h \
  /sw//include/gsl/gsl_vector_complex.h \
  /sw//include/gsl/gsl_block_complex_long_double.h \
  /sw//include/gsl/gsl_vector_complex_double.h \
  /sw//include/gsl/gsl_vector_double.h \
  /sw//include/gsl/gsl_block_double.h \
  /sw//include/gsl/gsl_block_complex_double.h \
  /sw//include/gsl/gsl_vector_complex_float.h \
  /sw//include/gsl/gsl_vector_float.h /sw//include/gsl/gsl_block_float.h \
  /sw//include/gsl/gsl_block_complex_float.h \
  /sw//include/gsl/gsl_vector_ulong.h /sw//include/gsl/gsl_block_ulong.h \
  /sw//include/gsl/gsl_vector_long.h /sw//include/gsl/gsl_block_long.h \
  /sw//include/gsl/gsl_vector_uint.h /sw//include/gsl/gsl_block_uint.h \
  /sw//include/gsl/gsl_vector_int.h /sw//include/gsl/gsl_block_int.h \
  /sw//include/gsl/gsl_vector_ushort.h \
  /sw//include/gsl/gsl_block_ushort.h /sw//include/gsl/gsl_vector_short.h \
  /sw//include/gsl/gsl_block_short.h /sw//include/gsl/gsl_vector_uchar.h \
  /sw//include/gsl/gsl_block_uchar.h /sw//include/gsl/gsl_vector_char.h \
  /sw//include/gsl/gsl_block_char.h /sw//include/gsl/gsl_matrix.h \
  /sw//include/gsl/gsl_matrix_complex_long_double.h \
  /sw//include/gsl/gsl_matrix_complex_double.h \
  /sw//include/gsl/gsl_matrix_complex_float.h \
  /sw//include/gsl/gsl_matrix_long_double.h \
  /sw//include/gsl/gsl_matrix_double.h \
  /sw//include/gsl/gsl_matrix_float.h /sw//include/gsl/gsl_matrix_ulong.h \
  /sw//include/gsl/gsl_matrix_long.h /sw//include/gsl/gsl_matrix_uint.h \
  /sw//include/gsl/gsl_matrix_int.h /sw//include/gsl/gsl_matrix_ushort.h \
  /sw//include/gsl/gsl_matrix_short.h /sw//include/gsl/gsl_matrix_uchar.h \
  /sw//include/gsl/gsl_matrix_char.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h
gsl_min.o: gsl_min.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw//include/gsl/gsl_errno.h /sw//include/gsl/gsl_types.h \
  /sw//include/gsl/gsl_math.h /sw//include/gsl/gsl_sys.h \
  /sw//include/gsl/gsl_machine.h /sw//include/gsl/gsl_precision.h \
  /sw//include/gsl/gsl_nan.h /sw//include/gsl/gsl_pow_int.h \
  /sw//include/gsl/gsl_multimin.h /sw//include/gsl/gsl_vector.h \
  /sw//include/gsl/gsl_vector_complex_long_double.h \
  /sw//include/gsl/gsl_complex.h /sw//include/gsl/gsl_check_range.h \
  /sw//include/gsl/gsl_vector_long_double.h \
  /sw//include/gsl/gsl_block_long_double.h \
  /sw//include/gsl/gsl_vector_complex.h \
  /sw//include/gsl/gsl_block_complex_long_double.h \
  /sw//include/gsl/gsl_vector_complex_double.h \
  /sw//include/gsl/gsl_vector_double.h \
  /sw//include/gsl/gsl_block_double.h \
  /sw//include/gsl/gsl_block_complex_double.h \
  /sw//include/gsl/gsl_vector_complex_float.h \
  /sw//include/gsl/gsl_vector_float.h /sw//include/gsl/gsl_block_float.h \
  /sw//include/gsl/gsl_block_complex_float.h \
  /sw//include/gsl/gsl_vector_ulong.h /sw//include/gsl/gsl_block_ulong.h \
  /sw//include/gsl/gsl_vector_long.h /sw//include/gsl/gsl_block_long.h \
  /sw//include/gsl/gsl_vector_uint.h /sw//include/gsl/gsl_block_uint.h \
  /sw//include/gsl/gsl_vector_int.h /sw//include/gsl/gsl_block_int.h \
  /sw//include/gsl/gsl_vector_ushort.h \
  /sw//include/gsl/gsl_block_ushort.h /sw//include/gsl/gsl_vector_short.h \
  /sw//include/gsl/gsl_block_short.h /sw//include/gsl/gsl_vector_uchar.h \
  /sw//include/gsl/gsl_block_uchar.h /sw//include/gsl/gsl_vector_char.h \
  /sw//include/gsl/gsl_block_char.h /sw//include/gsl/gsl_matrix.h \
  /sw//include/gsl/gsl_matrix_complex_long_double.h \
  /sw//include/gsl/gsl_matrix_complex_double.h \
  /sw//include/gsl/gsl_matrix_complex_float.h \
  /sw//include/gsl/gsl_matrix_long_double.h \
  /sw//include/gsl/gsl_matrix_double.h \
  /sw//include/gsl/gsl_matrix_float.h /sw//include/gsl/gsl_matrix_ulong.h \
  /sw//include/gsl/gsl_matrix_long.h /sw//include/gsl/gsl_matrix_uint.h \
  /sw//include/gsl/gsl_matrix_int.h /sw//include/gsl/gsl_matrix_ushort.h \
  /sw//include/gsl/gsl_matrix_short.h /sw//include/gsl/gsl_matrix_uchar.h \
  /sw//include/gsl/gsl_matrix_char.h /sw//include/gsl/gsl_min.h
gsl_brent.o: gsl_brent.cpp ../Common/Message.h Numeric.h \
  NumericEmbedded.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_math.h \
  /sw//include/gsl/gsl_sys.h /sw//include/gsl/gsl_machine.h \
  /sw//include/gsl/gsl_precision.h /sw//include/gsl/gsl_nan.h \
  /sw//include/gsl/gsl_pow_int.h /sw//include/gsl/gsl_min.h
