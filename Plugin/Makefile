# $Id: Makefile,v 1.102 2006-07-25 12:08:24 remacle Exp $
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

LIB     = ../lib/libGmshPlugin.a
INCLUDE = -I../Common -I../Graphics -I../DataStr -I../Geo -I../Fltk\
          -I../Mesh -I../Numeric -I../contrib/ANN/include\
          -I../contrib/Triangle -I../contrib/MathEval
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Plugin.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp \
        Smooth.cpp CutParametric.cpp\
        Lambda2.cpp\
        Eigenvectors.cpp Eigenvalues.cpp\
        StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
        Triangulate.cpp\
        Warp.cpp\
	StructuralSolver.cpp\
        Skin.cpp\
        Extract.cpp ExtractElements.cpp ExtractEdges.cpp\
        DecomposeInSimplex.cpp\
        Evaluate.cpp\
        Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp\
        Annotate.cpp Remove.cpp\
        Probe.cpp\
        HarmonicToTime.cpp ModulusPhase.cpp

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
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h PluginManager.h CutMap.h Levelset.h CutGrid.h \
  StreamLines.h CutPlane.h CutParametric.h CutSphere.h Skin.h \
  ../DataStr/Tree.h ../DataStr/avl.h Extract.h ExtractElements.h \
  ExtractEdges.h HarmonicToTime.h ModulusPhase.h Integrate.h Gradient.h \
  Curl.h Divergence.h Annotate.h Remove.h DecomposeInSimplex.h Smooth.h \
  Transform.h Triangulate.h Warp.h StructuralSolver.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/GmshDefines.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h ../Common/GmshUI.h Eigenvectors.h Eigenvalues.h \
  Lambda2.h Evaluate.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h Probe.h ../Common/Context.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h DecomposeInSimplex.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../Graphics/Iso.h \
  ../Common/Context.h ../DataStr/Malloc.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Smooth.h ../Common/Context.h
CutParametric.o: CutParametric.cpp ../Common/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Common/Message.h ../Common/Views.h \
  ../Common/ColorTable.h ../DataStr/List.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../contrib/MathEval/matheval.h
Lambda2.o: Lambda2.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Lambda2.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Eigenvectors.o: Eigenvectors.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Eigenvectors.h ../Common/Context.h \
  ../DataStr/Malloc.h ../Numeric/EigSolve.h
Eigenvalues.o: Eigenvalues.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Eigenvalues.h ../Common/Context.h \
  ../DataStr/Malloc.h
StreamLines.o: StreamLines.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h StreamLines.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
CutGrid.o: CutGrid.cpp ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Transform.h ../Common/Context.h
Triangulate.o: Triangulate.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Plugin.h ../Common/Options.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Triangulate.h ../Common/Context.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/GmshDefines.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h ../Mesh/Utils.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../contrib/Triangle/triangle.h
Warp.o: Warp.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Warp.h ../Common/Context.h
StructuralSolver.o: StructuralSolver.cpp StructuralSolver.h ../Geo/Geo.h \
  ../DataStr/List.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshDefines.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/GmshUI.h ../Common/Context.h \
  ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  ../Graphics/Draw.h ../Mesh/Utils.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Fltk/Shortcut_Window.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Common/Context.h ../DataStr/Malloc.h
Extract.o: Extract.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Extract.h ../Common/Context.h \
  ../DataStr/Malloc.h ../contrib/MathEval/matheval.h
ExtractElements.o: ExtractElements.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ExtractElements.h ../Common/Context.h \
  ../DataStr/Malloc.h
ExtractEdges.o: ExtractEdges.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ExtractEdges.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Common/Context.h ../DataStr/Malloc.h ../Mesh/BDS.h \
  ../contrib/ANN/include/ANN/ANN.h
DecomposeInSimplex.o: DecomposeInSimplex.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h DecomposeInSimplex.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Common/Context.h ../DataStr/Malloc.h
Evaluate.o: Evaluate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Evaluate.h ../Common/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h ../Common/Context.h \
  ../contrib/MathEval/matheval.h
Integrate.o: Integrate.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Integrate.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Gradient.o: Gradient.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Gradient.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Curl.o: Curl.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Curl.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Divergence.o: Divergence.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Divergence.h ../Common/Context.h \
  ../Common/ShapeFunctions.h
Annotate.o: Annotate.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Annotate.h ../Common/Context.h \
  ../Common/GmshUI.h ../Fltk/GUI.h ../Fltk/Opengl_Window.h ../Mesh/Mesh.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Common/GmshDefines.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Fltk/Colorbar_Window.h ../Fltk/Popup_Button.h ../Graphics/Draw.h
Remove.o: Remove.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../DataStr/List.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h Remove.h ../Common/Context.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ../Common/Context.h ../Common/GmshUI.h \
  ../Graphics/Draw.h ../Common/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h
HarmonicToTime.o: HarmonicToTime.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h HarmonicToTime.h ../Common/Context.h
ModulusPhase.o: ModulusPhase.cpp Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../DataStr/List.h ../Common/VertexArray.h ../Common/SmoothNormals.h \
  ../Numeric/Numeric.h ../Common/GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h ../Common/AdaptiveViews.h \
  ../Common/GmshMatrix.h ModulusPhase.h ../Common/Context.h
