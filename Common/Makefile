# $Id: Makefile,v 1.95 2006-07-25 12:08:23 remacle Exp $
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

LIB     = ../lib/libGmshCommon.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Graphics -I../Mesh\
          -I../Numeric -I../Parser -I../Plugin -I../Fltk\
          -I../contrib/MathEval
CFLAGS  =${OPTIM} ${FLAGS} ${INCLUDE}

SRC = Context.cpp\
      AdaptiveViews.cpp\
      Views.cpp ViewsIO.cpp\
      Octree.cpp OctreeInternals.cpp OctreePost.cpp\
      Options.cpp\
      CommandLine.cpp\
      OS.cpp\
      ColorTable.cpp\
      Visibility.cpp\
      Trackball.cpp\
      VertexArray.cpp\
      SmoothNormals.cpp\
      License.cpp

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
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Context.o: Context.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Context.h \
  DefaultOptions.h Options.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshDefines.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  Views.h ColorTable.h VertexArray.h SmoothNormals.h GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h AdaptiveViews.h Trackball.h
AdaptiveViews.o: AdaptiveViews.cpp AdaptiveViews.h ../DataStr/List.h \
  GmshMatrix.h /sw/include/gsl/gsl_linalg.h /sw/include/gsl/gsl_mode.h \
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
  /sw/include/gsl/gsl_cblas.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Common/Message.h ../Common/Views.h ../Common/ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothNormals.h ../Numeric/Numeric.h \
  ../Common/GmshMatrix.h ../Common/AdaptiveViews.h OS.h
Views.o: Views.cpp Gmsh.h Message.h ../DataStr/Malloc.h ../DataStr/List.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Numeric/Numeric.h Views.h ColorTable.h \
  VertexArray.h SmoothNormals.h GmshMatrix.h /sw/include/gsl/gsl_linalg.h \
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
  /sw/include/gsl/gsl_cblas.h AdaptiveViews.h Context.h Options.h \
  ../contrib/MathEval/matheval.h
ViewsIO.o: ViewsIO.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Views.h \
  ColorTable.h VertexArray.h SmoothNormals.h GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h AdaptiveViews.h Context.h
Octree.o: Octree.cpp Octree.h OctreeInternals.h
OctreeInternals.o: OctreeInternals.cpp Message.h OctreeInternals.h
OctreePost.o: OctreePost.cpp Octree.h OctreeInternals.h OctreePost.h \
  ../DataStr/List.h Views.h ColorTable.h VertexArray.h SmoothNormals.h \
  ../Numeric/Numeric.h GmshMatrix.h /sw/include/gsl/gsl_linalg.h \
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
  /sw/include/gsl/gsl_cblas.h AdaptiveViews.h Message.h ShapeFunctions.h
Options.o: Options.cpp ../Plugin/PluginManager.h ../Plugin/Plugin.h \
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
  ../Common/GmshMatrix.h Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h GmshUI.h ../Geo/Geo.h ../Mesh/Mesh.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Common/GmshDefines.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Graphics/Draw.h Context.h Options.h ../Fltk/Solvers.h ../Fltk/GUI.h \
  ../Fltk/Opengl_Window.h ../Fltk/Colorbar_Window.h ../Common/GmshUI.h \
  ../Fltk/Popup_Button.h
CommandLine.o: CommandLine.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h GmshUI.h GmshVersion.h \
  CommandLine.h ../Numeric/Numeric.h Context.h Options.h ../Geo/Geo.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/GmshDefines.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  Views.h ColorTable.h VertexArray.h SmoothNormals.h GmshMatrix.h \
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
  /sw/include/gsl/gsl_cblas.h AdaptiveViews.h ../Parser/OpenFile.h \
  ../Parser/Parser.h OS.h
OS.o: OS.cpp Message.h
ColorTable.o: ColorTable.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ColorTable.h Context.h \
  ../Numeric/Numeric.h
Visibility.o: Visibility.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Geo/Geo.h ../Geo/CAD.h \
  ../Mesh/Mesh.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Numeric/Numeric.h ../Common/GmshDefines.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h ../Geo/ExtrudeParams.h ../Parser/Parser.h Visibility.h
Trackball.o: Trackball.cpp Trackball.h
VertexArray.o: VertexArray.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h VertexArray.h Context.h \
  ../Numeric/Numeric.h
SmoothNormals.o: SmoothNormals.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h \
  SmoothNormals.h
License.o: License.cpp Gmsh.h Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h
