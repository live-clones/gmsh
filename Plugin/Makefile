# $Id: Makefile,v 1.158 2008-03-25 20:25:35 remacle Exp $
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

LIB = ../lib/libGmshPlugin${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Graphics ${DASH}I../DataStr ${DASH}I../Geo\
      ${DASH}I../Mesh ${DASH}I../Post ${DASH}I../Fltk ${DASH}I../Numeric\
      ${DASH}I../contrib/ANN/include ${DASH}I../contrib/Triangle\
      ${DASH}I../contrib/MathEval

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Plugin.cpp PluginManager.cpp\
        Levelset.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp \
        Smooth.cpp CutParametric.cpp\
        Lambda2.cpp\
        Eigenvectors.cpp Eigenvalues.cpp\
        StreamLines.cpp CutGrid.cpp\
        Transform.cpp\
          TransformLatLon.cpp\
        Triangulate.cpp\
        Warp.cpp SphericalRaise.cpp\
        Skin.cpp GSHHS.cpp GeoEarthImport.cpp\
        Extract.cpp ExtractElements.cpp ExtractEdges.cpp\
        MakeSimplex.cpp\
        Evaluate.cpp FieldView.cpp \
        Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp\
        Annotate.cpp Remove.cpp\
        Probe.cpp\
        HarmonicToTime.cpp ModulusPhase.cpp

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

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
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
PluginManager.o: PluginManager.cpp Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  PluginManager.h CutMap.h Levelset.h CutGrid.h StreamLines.h CutPlane.h \
  CutParametric.h CutSphere.h Skin.h ../DataStr/Tree.h ../DataStr/avl.h \
  Extract.h ExtractElements.h ExtractEdges.h HarmonicToTime.h \
  ModulusPhase.h Integrate.h Gradient.h Curl.h Divergence.h Annotate.h \
  Remove.h MakeSimplex.h Smooth.h Transform.h TransformLatLon.h \
  Triangulate.h Warp.h SphericalRaise.h Eigenvectors.h Eigenvalues.h \
  Lambda2.h Evaluate.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h Probe.h FieldView.h GSHHS.h \
  ../Common/Context.h
Levelset.o: Levelset.cpp Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  MakeSimplex.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
CutPlane.o: CutPlane.cpp CutPlane.h Levelset.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
CutSphere.o: CutSphere.cpp CutSphere.h Levelset.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
CutMap.o: CutMap.cpp CutMap.h Levelset.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h
Smooth.o: Smooth.cpp Smooth.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
CutParametric.o: CutParametric.cpp ../Post/OctreePost.h \
  ../Common/Octree.h ../Common/OctreeInternals.h CutParametric.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h \
  ../contrib/MathEval/matheval.h
Lambda2.o: Lambda2.cpp Lambda2.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/ShapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Eigenvectors.o: Eigenvectors.cpp Eigenvectors.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Numeric/EigSolve.h
Eigenvalues.o: Eigenvalues.cpp Eigenvalues.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
StreamLines.o: StreamLines.cpp StreamLines.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
CutGrid.o: CutGrid.cpp ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h CutGrid.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Common/GmshUI.h ../Graphics/Draw.h
Transform.o: Transform.cpp Transform.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
TransformLatLon.o: TransformLatLon.cpp TransformLatLon.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
Triangulate.o: Triangulate.cpp ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SBoundingBox3d.h \
  ../Geo/discreteFace.h ../Geo/GModel.h ../Geo/GFace.h ../Geo/Geo.h \
  ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Mesh/DivideAndConquer.h ../Common/Message.h \
  ../Geo/MVertex.h ../Geo/SPoint3.h Triangulate.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Post/PView.h \
  ../Post/PViewData.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h
Warp.o: Warp.cpp Warp.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
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
  ../Common/SmoothData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
SphericalRaise.o: SphericalRaise.cpp SphericalRaise.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
Skin.o: Skin.cpp Skin.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
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
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Malloc.h \
  ../Common/Context.h
GSHHS.o: GSHHS.cpp GSHHS.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SBoundingBox3d.h ../Geo/GeoStringInterface.h \
  ../Common/Context.h GeoEarthImport.h
GeoEarthImport.o: GeoEarthImport.cpp GeoEarthImport.h ../Geo/SPoint3.h \
  ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Geo/SPoint2.h ../Geo/ExtrudeParams.h \
  ../Common/SmoothData.h ../Post/PView.h ../Post/PViewData.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Geo/GeoStringInterface.h
Extract.o: Extract.cpp Extract.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../contrib/MathEval/matheval.h
ExtractElements.o: ExtractElements.cpp ExtractElements.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
ExtractEdges.o: ExtractEdges.cpp ExtractEdges.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Mesh/BDS.h ../Geo/GFace.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h
MakeSimplex.o: MakeSimplex.cpp MakeSimplex.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
Evaluate.o: Evaluate.cpp Evaluate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Post/OctreePost.h ../Common/Octree.h ../Common/OctreeInternals.h \
  ../contrib/MathEval/matheval.h
FieldView.o: FieldView.cpp FieldView.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Mesh/Field.h ../Geo/Geo.h ../Common/GmshDefines.h \
  ../Geo/gmshSurface.h ../Geo/Pair.h ../Geo/Range.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h \
  ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h \
  ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h \
  ../Geo/GEntity.h ../Geo/SBoundingBox3d.h
Integrate.o: Integrate.cpp Integrate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/ShapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Gradient.o: Gradient.cpp Gradient.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/ShapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Curl.o: Curl.cpp Curl.h Plugin.h ../Common/Options.h ../Post/ColorTable.h \
  ../Common/Message.h ../Post/PView.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Post/PViewOptions.h \
  ../Post/ColorTable.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Post/AdaptiveViews.h ../DataStr/List.h ../Common/GmshMatrix.h \
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
  ../Common/ShapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Divergence.o: Divergence.cpp Divergence.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/ShapeFunctions.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h
Annotate.o: Annotate.cpp Annotate.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Common/GmshUI.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h \
  ../Fltk/Popup_Button.h ../Fltk/SpherePosition_Widget.h ../Mesh/Field.h \
  ../Geo/Geo.h ../Common/GmshDefines.h ../Geo/gmshSurface.h ../Geo/Pair.h \
  ../Geo/Range.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Geo/SPoint2.h ../Geo/ExtrudeParams.h ../Common/SmoothData.h \
  ../Graphics/Draw.h
Remove.o: Remove.cpp Remove.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
Probe.o: Probe.cpp Probe.h Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Post/PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Post/PViewOptions.h ../Post/ColorTable.h ../Post/PViewDataList.h \
  ../Post/PViewData.h ../Post/AdaptiveViews.h ../DataStr/List.h \
  ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  ../Common/Context.h ../Post/OctreePost.h ../Common/Octree.h \
  ../Common/OctreeInternals.h ../Common/GmshUI.h ../Graphics/Draw.h
HarmonicToTime.o: HarmonicToTime.cpp HarmonicToTime.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
ModulusPhase.o: ModulusPhase.cpp ModulusPhase.h Plugin.h \
  ../Common/Options.h ../Post/ColorTable.h ../Common/Message.h \
  ../Post/PView.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Post/PViewOptions.h ../Post/ColorTable.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Post/AdaptiveViews.h \
  ../DataStr/List.h ../Common/GmshMatrix.h /sw//include/gsl/gsl_linalg.h \
  /sw//include/gsl/gsl_mode.h /sw//include/gsl/gsl_permutation.h \
  /sw//include/gsl/gsl_types.h /sw//include/gsl/gsl_errno.h \
  /sw//include/gsl/gsl_check_range.h /sw//include/gsl/gsl_vector.h \
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
  /sw//include/gsl/gsl_blas_types.h /sw//include/gsl/gsl_cblas.h
