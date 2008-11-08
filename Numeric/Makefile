# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshNumeric${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Numeric ${DASH}I../contrib/NR ${DASH}I../Geo

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Numeric.cpp\
      NumericEmbedded.cpp\
      gmshAssembler.cpp\
      gmshTermOfFormulation.cpp\
      gmshLaplace.cpp\
      gmshElasticity.cpp\
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
	${RM} *.o *.obj 

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Numeric.o: Numeric.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw/include/gsl/gsl_errno.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_vector.h \
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
  /sw/include/gsl/gsl_linalg.h /sw/include/gsl/gsl_mode.h \
  /sw/include/gsl/gsl_permutation.h /sw/include/gsl/gsl_matrix.h \
  /sw/include/gsl/gsl_matrix_complex_long_double.h \
  /sw/include/gsl/gsl_matrix_complex_double.h \
  /sw/include/gsl/gsl_matrix_complex_float.h \
  /sw/include/gsl/gsl_matrix_long_double.h \
  /sw/include/gsl/gsl_matrix_double.h /sw/include/gsl/gsl_matrix_float.h \
  /sw/include/gsl/gsl_matrix_ulong.h /sw/include/gsl/gsl_matrix_long.h \
  /sw/include/gsl/gsl_matrix_uint.h /sw/include/gsl/gsl_matrix_int.h \
  /sw/include/gsl/gsl_matrix_ushort.h /sw/include/gsl/gsl_matrix_short.h \
  /sw/include/gsl/gsl_matrix_uchar.h /sw/include/gsl/gsl_matrix_char.h
NumericEmbedded.o: NumericEmbedded.cpp NumericEmbedded.h \
  ../Common/Message.h
gmshAssembler.o: gmshAssembler.cpp gmshAssembler.h gmshLinearSystem.h
gmshTermOfFormulation.o: gmshTermOfFormulation.cpp \
  gmshTermOfFormulation.h ../Common/GmshMatrix.h \
  /sw/include/gsl/gsl_linalg.h /sw/include/gsl/gsl_mode.h \
  /sw/include/gsl/gsl_permutation.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_errno.h /sw/include/gsl/gsl_check_range.h \
  /sw/include/gsl/gsl_vector.h \
  /sw/include/gsl/gsl_vector_complex_long_double.h \
  /sw/include/gsl/gsl_complex.h /sw/include/gsl/gsl_vector_long_double.h \
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
  /sw/include/gsl/gsl_blas.h /sw/include/gsl/gsl_blas_types.h \
  /sw/include/gsl/gsl_cblas.h gmshFunction.h ../Common/Gmsh.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h \
  ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h \
  ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Message.h ../Numeric/FunctionSpace.h gmshLinearSystem.h \
  gmshAssembler.h
gmshLaplace.o: gmshLaplace.cpp gmshLaplace.h gmshTermOfFormulation.h \
  ../Common/GmshMatrix.h /sw/include/gsl/gsl_linalg.h \
  /sw/include/gsl/gsl_mode.h /sw/include/gsl/gsl_permutation.h \
  /sw/include/gsl/gsl_types.h /sw/include/gsl/gsl_errno.h \
  /sw/include/gsl/gsl_check_range.h /sw/include/gsl/gsl_vector.h \
  /sw/include/gsl/gsl_vector_complex_long_double.h \
  /sw/include/gsl/gsl_complex.h /sw/include/gsl/gsl_vector_long_double.h \
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
  /sw/include/gsl/gsl_blas.h /sw/include/gsl/gsl_blas_types.h \
  /sw/include/gsl/gsl_cblas.h ../Common/Gmsh.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Common/Message.h ../Numeric/FunctionSpace.h
EigSolve.o: EigSolve.cpp
FunctionSpace.o: FunctionSpace.cpp FunctionSpace.h ../Common/GmshMatrix.h \
  /sw/include/gsl/gsl_linalg.h /sw/include/gsl/gsl_mode.h \
  /sw/include/gsl/gsl_permutation.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_errno.h /sw/include/gsl/gsl_check_range.h \
  /sw/include/gsl/gsl_vector.h \
  /sw/include/gsl/gsl_vector_complex_long_double.h \
  /sw/include/gsl/gsl_complex.h /sw/include/gsl/gsl_vector_long_double.h \
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
  /sw/include/gsl/gsl_blas.h /sw/include/gsl/gsl_blas_types.h \
  /sw/include/gsl/gsl_cblas.h ../Common/GmshDefines.h ../Common/Message.h
gmsh_predicates.o: gmsh_predicates.cpp
gsl_newt.o: gsl_newt.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw/include/gsl/gsl_math.h /sw/include/gsl/gsl_sys.h \
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
gsl_min.o: gsl_min.cpp ../Common/Message.h Numeric.h NumericEmbedded.h \
  /sw/include/gsl/gsl_errno.h /sw/include/gsl/gsl_types.h \
  /sw/include/gsl/gsl_math.h /sw/include/gsl/gsl_sys.h \
  /sw/include/gsl/gsl_machine.h /sw/include/gsl/gsl_precision.h \
  /sw/include/gsl/gsl_nan.h /sw/include/gsl/gsl_pow_int.h \
  /sw/include/gsl/gsl_multimin.h /sw/include/gsl/gsl_vector.h \
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
  /sw/include/gsl/gsl_min.h
gsl_brent.o: gsl_brent.cpp ../Common/Message.h Numeric.h \
  NumericEmbedded.h /sw/include/gsl/gsl_errno.h \
  /sw/include/gsl/gsl_types.h /sw/include/gsl/gsl_math.h \
  /sw/include/gsl/gsl_sys.h /sw/include/gsl/gsl_machine.h \
  /sw/include/gsl/gsl_precision.h /sw/include/gsl/gsl_nan.h \
  /sw/include/gsl/gsl_pow_int.h /sw/include/gsl/gsl_min.h
