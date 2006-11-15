# $Id: Makefile,v 1.109 2006-11-15 20:46:46 remacle Exp $
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

LIB     = ../lib/libGmshGeo.a
INCLUDE = -I../Common -I../DataStr -I../Geo -I../Mesh -I../Numeric\
          -I../Parser -I../Fltk -I../contrib/NR -I../contrib/FourierModel
CFLAGS  = ${OPTIM} ${FLAGS} ${INCLUDE} 

SRC = CAD.cpp \
      ExtrudeParams.cpp \
      Geo.cpp \
      GeoUtils.cpp \
      GEntity.cpp\
      GVertex.cpp\
      GEdge.cpp\
      GFace.cpp\
      GRegion.cpp\
      MVertex.cpp \
      MElement.cpp \
      GModel.cpp\
      GModelIO_Mesh.cpp\
      GModelIO_Geo.cpp\
      GModelIO_Fourier.cpp\
      GModelIO_OCC.cpp\
      gmshEdge.cpp\
      gmshFace.cpp\
      gmshRegion.cpp\
      OCCVertex.cpp\
      OCCEdge.cpp\
      OCCFace.cpp\
      OCCRegion.cpp\
      SVector3.cpp\
      SBoundingBox3d.cpp\
      projectionFace.cpp\
      ExtractContour.cpp

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
CAD.o: CAD.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h ExtrudeParams.h \
  ../Common/Context.h
ExtrudeParams.o: ExtrudeParams.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h
Geo.o: Geo.cpp ../Common/Gmsh.h ../Common/Message.h ../DataStr/Malloc.h \
  ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h ../DataStr/Tools.h \
  ../DataStr/List.h ../DataStr/Tree.h ../Numeric/Numeric.h Geo.h CAD.h \
  ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h \
  ../Parser/Parser.h ../Common/Context.h GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
GeoUtils.o: GeoUtils.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h CAD.h ../Mesh/Mesh.h ../Common/GmshDefines.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h ExtrudeParams.h \
  ../Numeric/Numeric.h
GEntity.o: GEntity.cpp GEntity.h Range.h SPoint3.h SBoundingBox3d.h \
  ../Common/GmshDefines.h MRep.h GEdge.h GVertex.h MVertex.h GPoint.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/VertexArray.h \
  ../Common/Message.h ../Common/OS.h
GVertex.o: GVertex.cpp GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h
GEdge.o: GEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
GFace.o: GFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Common/Message.h ../Mesh/Utils.h ../Mesh/Vertex.h ../Mesh/Mesh.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h /sw/include/gsl/gsl_vector.h \
  /sw/include/gsl/gsl_vector_complex_long_double.h \
  /sw/include/gsl/gsl_types.h /sw/include/gsl/gsl_errno.h \
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
GRegion.o: GRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h
MVertex.o: MVertex.cpp MVertex.h SPoint3.h
MElement.o: MElement.cpp MElement.h ../Common/GmshDefines.h MVertex.h \
  SPoint3.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h GEntity.h \
  Range.h SBoundingBox3d.h
GModel.o: GModel.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  MRep.h ../Common/VertexArray.h ../Common/Message.h ../Common/OS.h
GModelIO_Mesh.o: GModelIO_Mesh.cpp ../Common/Message.h \
  ../Common/GmshDefines.h GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h MVertex.h GPoint.h GEdge.h SVector3.h SPoint2.h \
  MElement.h MEdge.h ../Common/Hash.h MFace.h ../Numeric/Numeric.h \
  ../Common/Context.h ../DataStr/List.h ExtrudeParams.h GFace.h Pair.h \
  GRegion.h ../Common/SmoothNormals.h gmshRegion.h ../Mesh/Mesh.h \
  ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Geo/ExtrudeParams.h \
  ../Mesh/Metric.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h \
  ../Mesh/Matrix.h gmshFace.h gmshVertex.h gmshEdge.h
GModelIO_Geo.o: GModelIO_Geo.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h Geo.h \
  ../Parser/OpenFile.h ../DataStr/Tools.h ../DataStr/List.h \
  ../DataStr/Tree.h ../Common/Message.h gmshVertex.h gmshFace.h \
  gmshEdge.h gmshRegion.h
GModelIO_Fourier.o: GModelIO_Fourier.cpp GModel.h GVertex.h GEntity.h \
  Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h \
  GPoint.h GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h \
  ../Common/Hash.h MFace.h ../Numeric/Numeric.h ../Common/Context.h \
  ../DataStr/List.h ExtrudeParams.h GFace.h Pair.h GRegion.h \
  ../Common/SmoothNormals.h fourierFace.h ../Common/Message.h \
  ../Common/Views.h ../Common/ColorTable.h ../Common/VertexArray.h \
  ../Common/SmoothNormals.h ../Common/AdaptiveViews.h \
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
  /sw/include/gsl/gsl_cblas.h
GModelIO_OCC.o: GModelIO_OCC.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  ../Common/Message.h OCCIncludes.h /usr/local/opencascade/inc/config.h \
  /usr/local/opencascade/inc/BRep_Tool.hxx \
  /usr/local/opencascade/inc/Standard_Boolean.hxx \
  /usr/local/opencascade/inc/Standard_TypeDef.hxx \
  /usr/local/opencascade/inc/Standard_Macro.hxx \
  /usr/local/opencascade/inc/Standard_Stream.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Surface.hxx \
  /usr/local/opencascade/inc/Standard.hxx \
  /usr/local/opencascade/inc/Standard_Address.hxx \
  /usr/local/opencascade/inc/Standard_Integer.hxx \
  /usr/local/opencascade/inc/Standard_values.h \
  /usr/local/opencascade/inc/Standard_OStream.hxx \
  /usr/local/opencascade/inc/Standard_CString.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_PrimitiveTypes.hxx \
  /usr/local/opencascade/inc/Standard_Real.hxx \
  /usr/local/opencascade/inc/Standard_Character.hxx \
  /usr/local/opencascade/inc/Standard_ctype.hxx \
  /usr/local/opencascade/inc/Standard_ExtCharacter.hxx \
  /usr/local/opencascade/inc/Standard_ExtString.hxx \
  /usr/local/opencascade/inc/Standard_Storable.hxx \
  /usr/local/opencascade/inc/Standard_Transient_proto.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon3D.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon2D.hxx \
  /usr/local/opencascade/inc/Handle_Poly_PolygonOnTriangulation.hxx \
  /usr/local/opencascade/inc/GeomAbs_Shape.hxx \
  /usr/local/opencascade/inc/Geom_Curve.hxx \
  /usr/local/opencascade/inc/Geom_Geometry.hxx \
  /usr/local/opencascade/inc/MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_Type.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Type.hxx \
  /usr/local/opencascade/inc/Standard_KindOfType.hxx \
  /usr/local/opencascade/inc/Standard_Type.lxx \
  /usr/local/opencascade/inc/Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Geom_Surface.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPS.hxx \
  /usr/local/opencascade/inc/Adaptor3d_SurfacePtr.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElS.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.hxx \
  /usr/local/opencascade/inc/gp_Pnt.hxx \
  /usr/local/opencascade/inc/gp_XYZ.hxx \
  /usr/local/opencascade/inc/gp_XYZ.lxx /usr/local/opencascade/inc/gp.hxx \
  /usr/local/opencascade/inc/gp.lxx /usr/local/opencascade/inc/gp_Mat.hxx \
  /usr/local/opencascade/inc/gp_Mat.lxx \
  /usr/local/opencascade/inc/Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_SStream.hxx \
  /usr/local/opencascade/inc/Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_Failure.lxx \
  /usr/local/opencascade/inc/Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/gp_Pnt.lxx \
  /usr/local/opencascade/inc/gp_Trsf.hxx \
  /usr/local/opencascade/inc/gp_TrsfForm.hxx \
  /usr/local/opencascade/inc/gp_Trsf.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.lxx \
  /usr/local/opencascade/inc/gp_XY.hxx \
  /usr/local/opencascade/inc/gp_XY.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.lxx \
  /usr/local/opencascade/inc/gp_Pnt2d.hxx \
  /usr/local/opencascade/inc/gp_Pnt2d.lxx \
  /usr/local/opencascade/inc/gp_Vec2d.hxx \
  /usr/local/opencascade/inc/gp_Vec2d.lxx \
  /usr/local/opencascade/inc/gp_Dir2d.hxx \
  /usr/local/opencascade/inc/gp_Dir2d.lxx \
  /usr/local/opencascade/inc/gp_Ax2d.hxx \
  /usr/local/opencascade/inc/gp_Ax2d.lxx \
  /usr/local/opencascade/inc/gp_Vec.hxx \
  /usr/local/opencascade/inc/gp_Vec.lxx \
  /usr/local/opencascade/inc/gp_Dir.hxx \
  /usr/local/opencascade/inc/gp_Dir.lxx \
  /usr/local/opencascade/inc/gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Handle_gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.lxx \
  /usr/local/opencascade/inc/Extrema_GenExtPS.hxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray2OfPnt.hxx \
  /usr/local/opencascade/inc/Extrema_FuncExtPS.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfReal.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.lxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfReal.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_SeqNode.hxx \
  /usr/local/opencascade/inc/TCollection_Sequence.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/math_FunctionSetWithDerivatives.hxx \
  /usr/local/opencascade/inc/math_FunctionSet.hxx \
  /usr/local/opencascade/inc/GeomAbs_SurfaceType.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Surface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineSurface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/Quantity_Parameter.hxx \
  /usr/local/opencascade/inc/Quantity_Length.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElC.hxx \
  /usr/local/opencascade/inc/Extrema_POnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_Point.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_EPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_PCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Extrema_SeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/math_FunctionWithDerivative.hxx \
  /usr/local/opencascade/inc/math_Function.hxx \
  /usr/local/opencascade/inc/GeomAbs_CurveType.hxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.lxx \
  /usr/local/opencascade/inc/BRepTools.hxx \
  /usr/local/opencascade/inc/Standard_IStream.hxx \
  /usr/local/opencascade/inc/TopExp.hxx \
  /usr/local/opencascade/inc/TopAbs_ShapeEnum.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShape.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.hxx \
  /usr/local/opencascade/inc/TopLoc_SListOfItemLocation.hxx \
  /usr/local/opencascade/inc/Handle_TopLoc_SListNodeOfSListOfItemLocation.hxx \
  /usr/local/opencascade/inc/TCollection_SList.lxx \
  /usr/local/opencascade/inc/Handle_TopLoc_Datum3D.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.lxx \
  /usr/local/opencascade/inc/TopLoc_ItemLocation.hxx \
  /usr/local/opencascade/inc/TopLoc_TrsfPtr.hxx \
  /usr/local/opencascade/inc/TopAbs_Orientation.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopoDS_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_MapNode.hxx \
  /usr/local/opencascade/inc/TCollection_List.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.lxx \
  /usr/local/opencascade/inc/TopAbs.hxx \
  /usr/local/opencascade/inc/TopAbs_State.hxx \
  /usr/local/opencascade/inc/TopTools_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/BRepLib_Command.hxx \
  /usr/local/opencascade/inc/BRepLib_ShapeModification.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Command.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepOffsetAPI_Sewing.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/Handle_BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.hxx \
  /usr/local/opencascade/inc/TCollection_MapNodePtr.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.lxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedMapNodeOfIndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/TopTools_MapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_StdMapNodeOfMapOfShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.lxx \
  /usr/local/opencascade/inc/BRepLProp_SLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/TopoDS_Face.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/LProp_Status.hxx \
  /usr/local/opencascade/inc/Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt.hxx \
  /usr/local/opencascade/inc/TCollection_Array1.lxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray1OfPnt2d.hxx \
  /usr/local/opencascade/inc/Poly_Array1OfTriangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.lxx \
  /usr/local/opencascade/inc/Poly_Triangulation.lxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt2d.hxx \
  /usr/local/opencascade/inc/GProp_GProps.hxx \
  /usr/local/opencascade/inc/BRepGProp.hxx \
  /usr/local/opencascade/inc/TopoDS.hxx \
  /usr/local/opencascade/inc/TopoDS.lxx \
  /usr/local/opencascade/inc/Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/Handle_Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/TopoDS_Solid.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.hxx \
  /usr/local/opencascade/inc/TopExp_Stack.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.lxx \
  /usr/local/opencascade/inc/TopoDS_Wire.hxx \
  /usr/local/opencascade/inc/BRepTools_WireExplorer.hxx \
  /usr/local/opencascade/inc/TopoDS_Edge.hxx \
  /usr/local/opencascade/inc/TopoDS_Vertex.hxx \
  /usr/local/opencascade/inc/BRepLProp_CLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurveOnSurface.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.hxx \
  /usr/local/opencascade/inc/XSControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_XSControl_WorkSession.hxx \
  /usr/local/opencascade/inc/Handle_IFSelect_WorkSession.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/TopTools_SequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_SequenceNodeOfSequenceOfShape.hxx \
  /usr/local/opencascade/inc/IFSelect_ReturnStatus.hxx \
  /usr/local/opencascade/inc/Handle_Interface_InterfaceModel.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintCount.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESModel.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintFail.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.lxx \
  /usr/local/opencascade/inc/STEPControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_StepData_StepModel.hxx \
  /usr/local/opencascade/inc/IGESToBRep_Reader.hxx \
  /usr/local/opencascade/inc/Handle_IGESToBRep_Actor.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfTransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfProcessForTransient.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_TransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForTransient.hxx \
  /usr/local/opencascade/inc/Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Handle_MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.lxx \
  /usr/local/opencascade/inc/Interface_ParamType.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HArray1OfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfInteger.hxx \
  /usr/local/opencascade/inc/Interface_StaticSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Interface_ValueInterpret.hxx \
  /usr/local/opencascade/inc/Interface_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueType.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueInterpret.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HExtendedString.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.lxx \
  /usr/local/opencascade/inc/MoniTool_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfHAsciiString.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtCC.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.lxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.hxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.lxx \
  /usr/local/opencascade/inc/ShapeUpgrade_ShellSewing.hxx \
  /usr/local/opencascade/inc/Handle_ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_BasicMsgRegistrator.hxx \
  /usr/local/opencascade/inc/Message_Gravity.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.lxx \
  /usr/local/opencascade/inc/Precision.hxx \
  /usr/local/opencascade/inc/Precision.lxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Edge.hxx \
  /usr/local/opencascade/inc/ShapeExtend_Status.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.lxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.lxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Compound.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.lxx \
  /usr/local/opencascade/inc/ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Surface.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/ShapeFix_Face.lxx \
  /usr/local/opencascade/inc/ShapeExtend.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.lxx \
  /usr/local/opencascade/inc/ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_HSequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.lxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.lxx \
  /usr/local/opencascade/inc/BRepMesh.hxx \
  /usr/local/opencascade/inc/BRepMesh_IncrementalMesh.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_FastDiscret.hxx \
  /usr/local/opencascade/inc/BRepMesh_DataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_DataMapNodeOfDataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Bnd_Box.hxx \
  /usr/local/opencascade/inc/Bnd_Box.lxx \
  /usr/local/opencascade/inc/BRepBndLib.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis.hxx \
  /usr/local/opencascade/inc/ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/IGESControl_Writer.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_FinderProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForFinder.hxx \
  /usr/local/opencascade/inc/IGESData_BasicEditor.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_Protocol.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Protocol.hxx \
  /usr/local/opencascade/inc/Interface_GeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_NodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GeneralModule.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GlobalNodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/IGESData_SpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_NodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESEntity.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_SpecificModule.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_GlobalNodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/STEPControl_Writer.hxx \
  /usr/local/opencascade/inc/STEPControl_StepModelType.hxx \
  /usr/local/opencascade/inc/StlAPI_Writer.hxx \
  /usr/local/opencascade/inc/Handle_StlMesh_Mesh.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeTolerance.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_DataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_DataMapNodeOfDataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_Fuse.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_BooleanOperation.hxx \
  /usr/local/opencascade/inc/BOP_Operation.hxx \
  /usr/local/opencascade/inc/BOPTools_PDSFiller.hxx \
  /usr/local/opencascade/inc/BOP_PBuilder.hxx \
  /usr/local/opencascade/inc/Handle_BOP_HistoryCollector.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.hxx \
  /usr/local/opencascade/inc/BRepCheck_DataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_Result.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_DataMapNodeOfDataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.lxx \
  /usr/local/opencascade/inc/BRepLib.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Plane.hxx \
  /usr/local/opencascade/inc/Handle_Geom_ElementarySurface.hxx \
  /usr/local/opencascade/inc/ShapeFix.hxx \
  /usr/local/opencascade/inc/ShapeFix_FixSmallFace.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_FixSmallFace.hxx OCCVertex.h \
  ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h ../Mesh/Element.h \
  ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCEdge.h OCCFace.h \
  OCCRegion.h
gmshEdge.o: gmshEdge.cpp gmshEdge.h GEdge.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h GVertex.h MVertex.h GPoint.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h gmshVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h Geo.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h
gmshFace.o: gmshFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  gmshVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h gmshEdge.h gmshFace.h \
  ../Mesh/Interpolation.h ../Mesh/Vertex.h ../Mesh/Mesh.h CAD.h Geo.h \
  ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h ../Mesh/Utils.h \
  ../Mesh/Vertex.h ../Mesh/Mesh.h ../Common/Message.h
gmshRegion.o: gmshRegion.cpp GModel.h GVertex.h GEntity.h Range.h \
  SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h \
  GEdge.h SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h \
  MFace.h ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  gmshFace.h gmshVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Geo/ExtrudeParams.h ../Mesh/Metric.h \
  ../Mesh/Vertex.h ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h \
  gmshRegion.h Geo.h ../Mesh/Create.h ../Mesh/Vertex.h ../Mesh/Mesh.h
OCCEdge.o: OCCEdge.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  OCCEdge.h OCCVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  /usr/local/opencascade/inc/config.h \
  /usr/local/opencascade/inc/BRep_Tool.hxx \
  /usr/local/opencascade/inc/Standard_Boolean.hxx \
  /usr/local/opencascade/inc/Standard_TypeDef.hxx \
  /usr/local/opencascade/inc/Standard_Macro.hxx \
  /usr/local/opencascade/inc/Standard_Stream.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Surface.hxx \
  /usr/local/opencascade/inc/Standard.hxx \
  /usr/local/opencascade/inc/Standard_Address.hxx \
  /usr/local/opencascade/inc/Standard_Integer.hxx \
  /usr/local/opencascade/inc/Standard_values.h \
  /usr/local/opencascade/inc/Standard_OStream.hxx \
  /usr/local/opencascade/inc/Standard_CString.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_PrimitiveTypes.hxx \
  /usr/local/opencascade/inc/Standard_Real.hxx \
  /usr/local/opencascade/inc/Standard_Character.hxx \
  /usr/local/opencascade/inc/Standard_ctype.hxx \
  /usr/local/opencascade/inc/Standard_ExtCharacter.hxx \
  /usr/local/opencascade/inc/Standard_ExtString.hxx \
  /usr/local/opencascade/inc/Standard_Storable.hxx \
  /usr/local/opencascade/inc/Standard_Transient_proto.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon3D.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon2D.hxx \
  /usr/local/opencascade/inc/Handle_Poly_PolygonOnTriangulation.hxx \
  /usr/local/opencascade/inc/GeomAbs_Shape.hxx \
  /usr/local/opencascade/inc/Geom_Curve.hxx \
  /usr/local/opencascade/inc/Geom_Geometry.hxx \
  /usr/local/opencascade/inc/MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_Type.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Type.hxx \
  /usr/local/opencascade/inc/Standard_KindOfType.hxx \
  /usr/local/opencascade/inc/Standard_Type.lxx \
  /usr/local/opencascade/inc/Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Geom_Surface.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPS.hxx \
  /usr/local/opencascade/inc/Adaptor3d_SurfacePtr.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElS.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.hxx \
  /usr/local/opencascade/inc/gp_Pnt.hxx \
  /usr/local/opencascade/inc/gp_XYZ.hxx \
  /usr/local/opencascade/inc/gp_XYZ.lxx /usr/local/opencascade/inc/gp.hxx \
  /usr/local/opencascade/inc/gp.lxx /usr/local/opencascade/inc/gp_Mat.hxx \
  /usr/local/opencascade/inc/gp_Mat.lxx \
  /usr/local/opencascade/inc/Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_SStream.hxx \
  /usr/local/opencascade/inc/Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_Failure.lxx \
  /usr/local/opencascade/inc/Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/gp_Pnt.lxx \
  /usr/local/opencascade/inc/gp_Trsf.hxx \
  /usr/local/opencascade/inc/gp_TrsfForm.hxx \
  /usr/local/opencascade/inc/gp_Trsf.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.lxx \
  /usr/local/opencascade/inc/gp_XY.hxx \
  /usr/local/opencascade/inc/gp_XY.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.lxx \
  /usr/local/opencascade/inc/gp_Pnt2d.hxx \
  /usr/local/opencascade/inc/gp_Pnt2d.lxx \
  /usr/local/opencascade/inc/gp_Vec2d.hxx \
  /usr/local/opencascade/inc/gp_Vec2d.lxx \
  /usr/local/opencascade/inc/gp_Dir2d.hxx \
  /usr/local/opencascade/inc/gp_Dir2d.lxx \
  /usr/local/opencascade/inc/gp_Ax2d.hxx \
  /usr/local/opencascade/inc/gp_Ax2d.lxx \
  /usr/local/opencascade/inc/gp_Vec.hxx \
  /usr/local/opencascade/inc/gp_Vec.lxx \
  /usr/local/opencascade/inc/gp_Dir.hxx \
  /usr/local/opencascade/inc/gp_Dir.lxx \
  /usr/local/opencascade/inc/gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Handle_gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.lxx \
  /usr/local/opencascade/inc/Extrema_GenExtPS.hxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray2OfPnt.hxx \
  /usr/local/opencascade/inc/Extrema_FuncExtPS.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfReal.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.lxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfReal.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_SeqNode.hxx \
  /usr/local/opencascade/inc/TCollection_Sequence.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/math_FunctionSetWithDerivatives.hxx \
  /usr/local/opencascade/inc/math_FunctionSet.hxx \
  /usr/local/opencascade/inc/GeomAbs_SurfaceType.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Surface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineSurface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/Quantity_Parameter.hxx \
  /usr/local/opencascade/inc/Quantity_Length.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElC.hxx \
  /usr/local/opencascade/inc/Extrema_POnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_Point.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_EPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_PCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Extrema_SeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/math_FunctionWithDerivative.hxx \
  /usr/local/opencascade/inc/math_Function.hxx \
  /usr/local/opencascade/inc/GeomAbs_CurveType.hxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.lxx \
  /usr/local/opencascade/inc/BRepTools.hxx \
  /usr/local/opencascade/inc/Standard_IStream.hxx \
  /usr/local/opencascade/inc/TopExp.hxx \
  /usr/local/opencascade/inc/TopAbs_ShapeEnum.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShape.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.hxx \
  /usr/local/opencascade/inc/TopLoc_SListOfItemLocation.hxx \
  /usr/local/opencascade/inc/Handle_TopLoc_SListNodeOfSListOfItemLocation.hxx \
  /usr/local/opencascade/inc/TCollection_SList.lxx \
  /usr/local/opencascade/inc/Handle_TopLoc_Datum3D.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.lxx \
  /usr/local/opencascade/inc/TopLoc_ItemLocation.hxx \
  /usr/local/opencascade/inc/TopLoc_TrsfPtr.hxx \
  /usr/local/opencascade/inc/TopAbs_Orientation.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopoDS_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_MapNode.hxx \
  /usr/local/opencascade/inc/TCollection_List.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.lxx \
  /usr/local/opencascade/inc/TopAbs.hxx \
  /usr/local/opencascade/inc/TopAbs_State.hxx \
  /usr/local/opencascade/inc/TopTools_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/BRepLib_Command.hxx \
  /usr/local/opencascade/inc/BRepLib_ShapeModification.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Command.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepOffsetAPI_Sewing.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/Handle_BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.hxx \
  /usr/local/opencascade/inc/TCollection_MapNodePtr.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.lxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedMapNodeOfIndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/TopTools_MapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_StdMapNodeOfMapOfShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.lxx \
  /usr/local/opencascade/inc/BRepLProp_SLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/TopoDS_Face.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/LProp_Status.hxx \
  /usr/local/opencascade/inc/Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt.hxx \
  /usr/local/opencascade/inc/TCollection_Array1.lxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray1OfPnt2d.hxx \
  /usr/local/opencascade/inc/Poly_Array1OfTriangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.lxx \
  /usr/local/opencascade/inc/Poly_Triangulation.lxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt2d.hxx \
  /usr/local/opencascade/inc/GProp_GProps.hxx \
  /usr/local/opencascade/inc/BRepGProp.hxx \
  /usr/local/opencascade/inc/TopoDS.hxx \
  /usr/local/opencascade/inc/TopoDS.lxx \
  /usr/local/opencascade/inc/Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/Handle_Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/TopoDS_Solid.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.hxx \
  /usr/local/opencascade/inc/TopExp_Stack.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.lxx \
  /usr/local/opencascade/inc/TopoDS_Wire.hxx \
  /usr/local/opencascade/inc/BRepTools_WireExplorer.hxx \
  /usr/local/opencascade/inc/TopoDS_Edge.hxx \
  /usr/local/opencascade/inc/TopoDS_Vertex.hxx \
  /usr/local/opencascade/inc/BRepLProp_CLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurveOnSurface.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.hxx \
  /usr/local/opencascade/inc/XSControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_XSControl_WorkSession.hxx \
  /usr/local/opencascade/inc/Handle_IFSelect_WorkSession.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/TopTools_SequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_SequenceNodeOfSequenceOfShape.hxx \
  /usr/local/opencascade/inc/IFSelect_ReturnStatus.hxx \
  /usr/local/opencascade/inc/Handle_Interface_InterfaceModel.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintCount.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESModel.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintFail.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.lxx \
  /usr/local/opencascade/inc/STEPControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_StepData_StepModel.hxx \
  /usr/local/opencascade/inc/IGESToBRep_Reader.hxx \
  /usr/local/opencascade/inc/Handle_IGESToBRep_Actor.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfTransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfProcessForTransient.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_TransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForTransient.hxx \
  /usr/local/opencascade/inc/Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Handle_MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.lxx \
  /usr/local/opencascade/inc/Interface_ParamType.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HArray1OfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfInteger.hxx \
  /usr/local/opencascade/inc/Interface_StaticSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Interface_ValueInterpret.hxx \
  /usr/local/opencascade/inc/Interface_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueType.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueInterpret.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HExtendedString.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.lxx \
  /usr/local/opencascade/inc/MoniTool_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfHAsciiString.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtCC.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.lxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.hxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.lxx \
  /usr/local/opencascade/inc/ShapeUpgrade_ShellSewing.hxx \
  /usr/local/opencascade/inc/Handle_ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_BasicMsgRegistrator.hxx \
  /usr/local/opencascade/inc/Message_Gravity.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.lxx \
  /usr/local/opencascade/inc/Precision.hxx \
  /usr/local/opencascade/inc/Precision.lxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Edge.hxx \
  /usr/local/opencascade/inc/ShapeExtend_Status.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.lxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.lxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Compound.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.lxx \
  /usr/local/opencascade/inc/ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Surface.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/ShapeFix_Face.lxx \
  /usr/local/opencascade/inc/ShapeExtend.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.lxx \
  /usr/local/opencascade/inc/ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_HSequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.lxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.lxx \
  /usr/local/opencascade/inc/BRepMesh.hxx \
  /usr/local/opencascade/inc/BRepMesh_IncrementalMesh.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_FastDiscret.hxx \
  /usr/local/opencascade/inc/BRepMesh_DataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_DataMapNodeOfDataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Bnd_Box.hxx \
  /usr/local/opencascade/inc/Bnd_Box.lxx \
  /usr/local/opencascade/inc/BRepBndLib.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis.hxx \
  /usr/local/opencascade/inc/ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/IGESControl_Writer.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_FinderProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForFinder.hxx \
  /usr/local/opencascade/inc/IGESData_BasicEditor.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_Protocol.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Protocol.hxx \
  /usr/local/opencascade/inc/Interface_GeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_NodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GeneralModule.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GlobalNodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/IGESData_SpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_NodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESEntity.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_SpecificModule.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_GlobalNodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/STEPControl_Writer.hxx \
  /usr/local/opencascade/inc/STEPControl_StepModelType.hxx \
  /usr/local/opencascade/inc/StlAPI_Writer.hxx \
  /usr/local/opencascade/inc/Handle_StlMesh_Mesh.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeTolerance.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_DataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_DataMapNodeOfDataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_Fuse.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_BooleanOperation.hxx \
  /usr/local/opencascade/inc/BOP_Operation.hxx \
  /usr/local/opencascade/inc/BOPTools_PDSFiller.hxx \
  /usr/local/opencascade/inc/BOP_PBuilder.hxx \
  /usr/local/opencascade/inc/Handle_BOP_HistoryCollector.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.hxx \
  /usr/local/opencascade/inc/BRepCheck_DataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_Result.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_DataMapNodeOfDataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.lxx \
  /usr/local/opencascade/inc/BRepLib.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Plane.hxx \
  /usr/local/opencascade/inc/Handle_Geom_ElementarySurface.hxx \
  /usr/local/opencascade/inc/ShapeFix.hxx \
  /usr/local/opencascade/inc/ShapeFix_FixSmallFace.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_FixSmallFace.hxx
OCCFace.o: OCCFace.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  OCCVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  /usr/local/opencascade/inc/config.h \
  /usr/local/opencascade/inc/BRep_Tool.hxx \
  /usr/local/opencascade/inc/Standard_Boolean.hxx \
  /usr/local/opencascade/inc/Standard_TypeDef.hxx \
  /usr/local/opencascade/inc/Standard_Macro.hxx \
  /usr/local/opencascade/inc/Standard_Stream.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Surface.hxx \
  /usr/local/opencascade/inc/Standard.hxx \
  /usr/local/opencascade/inc/Standard_Address.hxx \
  /usr/local/opencascade/inc/Standard_Integer.hxx \
  /usr/local/opencascade/inc/Standard_values.h \
  /usr/local/opencascade/inc/Standard_OStream.hxx \
  /usr/local/opencascade/inc/Standard_CString.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_PrimitiveTypes.hxx \
  /usr/local/opencascade/inc/Standard_Real.hxx \
  /usr/local/opencascade/inc/Standard_Character.hxx \
  /usr/local/opencascade/inc/Standard_ctype.hxx \
  /usr/local/opencascade/inc/Standard_ExtCharacter.hxx \
  /usr/local/opencascade/inc/Standard_ExtString.hxx \
  /usr/local/opencascade/inc/Standard_Storable.hxx \
  /usr/local/opencascade/inc/Standard_Transient_proto.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon3D.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon2D.hxx \
  /usr/local/opencascade/inc/Handle_Poly_PolygonOnTriangulation.hxx \
  /usr/local/opencascade/inc/GeomAbs_Shape.hxx \
  /usr/local/opencascade/inc/Geom_Curve.hxx \
  /usr/local/opencascade/inc/Geom_Geometry.hxx \
  /usr/local/opencascade/inc/MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_Type.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Type.hxx \
  /usr/local/opencascade/inc/Standard_KindOfType.hxx \
  /usr/local/opencascade/inc/Standard_Type.lxx \
  /usr/local/opencascade/inc/Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Geom_Surface.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPS.hxx \
  /usr/local/opencascade/inc/Adaptor3d_SurfacePtr.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElS.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.hxx \
  /usr/local/opencascade/inc/gp_Pnt.hxx \
  /usr/local/opencascade/inc/gp_XYZ.hxx \
  /usr/local/opencascade/inc/gp_XYZ.lxx /usr/local/opencascade/inc/gp.hxx \
  /usr/local/opencascade/inc/gp.lxx /usr/local/opencascade/inc/gp_Mat.hxx \
  /usr/local/opencascade/inc/gp_Mat.lxx \
  /usr/local/opencascade/inc/Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_SStream.hxx \
  /usr/local/opencascade/inc/Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_Failure.lxx \
  /usr/local/opencascade/inc/Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/gp_Pnt.lxx \
  /usr/local/opencascade/inc/gp_Trsf.hxx \
  /usr/local/opencascade/inc/gp_TrsfForm.hxx \
  /usr/local/opencascade/inc/gp_Trsf.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.lxx \
  /usr/local/opencascade/inc/gp_XY.hxx \
  /usr/local/opencascade/inc/gp_XY.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.lxx \
  /usr/local/opencascade/inc/gp_Pnt2d.hxx \
  /usr/local/opencascade/inc/gp_Pnt2d.lxx \
  /usr/local/opencascade/inc/gp_Vec2d.hxx \
  /usr/local/opencascade/inc/gp_Vec2d.lxx \
  /usr/local/opencascade/inc/gp_Dir2d.hxx \
  /usr/local/opencascade/inc/gp_Dir2d.lxx \
  /usr/local/opencascade/inc/gp_Ax2d.hxx \
  /usr/local/opencascade/inc/gp_Ax2d.lxx \
  /usr/local/opencascade/inc/gp_Vec.hxx \
  /usr/local/opencascade/inc/gp_Vec.lxx \
  /usr/local/opencascade/inc/gp_Dir.hxx \
  /usr/local/opencascade/inc/gp_Dir.lxx \
  /usr/local/opencascade/inc/gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Handle_gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.lxx \
  /usr/local/opencascade/inc/Extrema_GenExtPS.hxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray2OfPnt.hxx \
  /usr/local/opencascade/inc/Extrema_FuncExtPS.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfReal.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.lxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfReal.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_SeqNode.hxx \
  /usr/local/opencascade/inc/TCollection_Sequence.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/math_FunctionSetWithDerivatives.hxx \
  /usr/local/opencascade/inc/math_FunctionSet.hxx \
  /usr/local/opencascade/inc/GeomAbs_SurfaceType.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Surface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineSurface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/Quantity_Parameter.hxx \
  /usr/local/opencascade/inc/Quantity_Length.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElC.hxx \
  /usr/local/opencascade/inc/Extrema_POnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_Point.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_EPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_PCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Extrema_SeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/math_FunctionWithDerivative.hxx \
  /usr/local/opencascade/inc/math_Function.hxx \
  /usr/local/opencascade/inc/GeomAbs_CurveType.hxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.lxx \
  /usr/local/opencascade/inc/BRepTools.hxx \
  /usr/local/opencascade/inc/Standard_IStream.hxx \
  /usr/local/opencascade/inc/TopExp.hxx \
  /usr/local/opencascade/inc/TopAbs_ShapeEnum.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShape.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.hxx \
  /usr/local/opencascade/inc/TopLoc_SListOfItemLocation.hxx \
  /usr/local/opencascade/inc/Handle_TopLoc_SListNodeOfSListOfItemLocation.hxx \
  /usr/local/opencascade/inc/TCollection_SList.lxx \
  /usr/local/opencascade/inc/Handle_TopLoc_Datum3D.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.lxx \
  /usr/local/opencascade/inc/TopLoc_ItemLocation.hxx \
  /usr/local/opencascade/inc/TopLoc_TrsfPtr.hxx \
  /usr/local/opencascade/inc/TopAbs_Orientation.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopoDS_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_MapNode.hxx \
  /usr/local/opencascade/inc/TCollection_List.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.lxx \
  /usr/local/opencascade/inc/TopAbs.hxx \
  /usr/local/opencascade/inc/TopAbs_State.hxx \
  /usr/local/opencascade/inc/TopTools_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/BRepLib_Command.hxx \
  /usr/local/opencascade/inc/BRepLib_ShapeModification.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Command.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepOffsetAPI_Sewing.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/Handle_BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.hxx \
  /usr/local/opencascade/inc/TCollection_MapNodePtr.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.lxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedMapNodeOfIndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/TopTools_MapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_StdMapNodeOfMapOfShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.lxx \
  /usr/local/opencascade/inc/BRepLProp_SLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/TopoDS_Face.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/LProp_Status.hxx \
  /usr/local/opencascade/inc/Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt.hxx \
  /usr/local/opencascade/inc/TCollection_Array1.lxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray1OfPnt2d.hxx \
  /usr/local/opencascade/inc/Poly_Array1OfTriangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.lxx \
  /usr/local/opencascade/inc/Poly_Triangulation.lxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt2d.hxx \
  /usr/local/opencascade/inc/GProp_GProps.hxx \
  /usr/local/opencascade/inc/BRepGProp.hxx \
  /usr/local/opencascade/inc/TopoDS.hxx \
  /usr/local/opencascade/inc/TopoDS.lxx \
  /usr/local/opencascade/inc/Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/Handle_Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/TopoDS_Solid.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.hxx \
  /usr/local/opencascade/inc/TopExp_Stack.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.lxx \
  /usr/local/opencascade/inc/TopoDS_Wire.hxx \
  /usr/local/opencascade/inc/BRepTools_WireExplorer.hxx \
  /usr/local/opencascade/inc/TopoDS_Edge.hxx \
  /usr/local/opencascade/inc/TopoDS_Vertex.hxx \
  /usr/local/opencascade/inc/BRepLProp_CLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurveOnSurface.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.hxx \
  /usr/local/opencascade/inc/XSControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_XSControl_WorkSession.hxx \
  /usr/local/opencascade/inc/Handle_IFSelect_WorkSession.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/TopTools_SequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_SequenceNodeOfSequenceOfShape.hxx \
  /usr/local/opencascade/inc/IFSelect_ReturnStatus.hxx \
  /usr/local/opencascade/inc/Handle_Interface_InterfaceModel.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintCount.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESModel.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintFail.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.lxx \
  /usr/local/opencascade/inc/STEPControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_StepData_StepModel.hxx \
  /usr/local/opencascade/inc/IGESToBRep_Reader.hxx \
  /usr/local/opencascade/inc/Handle_IGESToBRep_Actor.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfTransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfProcessForTransient.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_TransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForTransient.hxx \
  /usr/local/opencascade/inc/Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Handle_MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.lxx \
  /usr/local/opencascade/inc/Interface_ParamType.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HArray1OfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfInteger.hxx \
  /usr/local/opencascade/inc/Interface_StaticSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Interface_ValueInterpret.hxx \
  /usr/local/opencascade/inc/Interface_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueType.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueInterpret.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HExtendedString.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.lxx \
  /usr/local/opencascade/inc/MoniTool_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfHAsciiString.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtCC.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.lxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.hxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.lxx \
  /usr/local/opencascade/inc/ShapeUpgrade_ShellSewing.hxx \
  /usr/local/opencascade/inc/Handle_ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_BasicMsgRegistrator.hxx \
  /usr/local/opencascade/inc/Message_Gravity.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.lxx \
  /usr/local/opencascade/inc/Precision.hxx \
  /usr/local/opencascade/inc/Precision.lxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Edge.hxx \
  /usr/local/opencascade/inc/ShapeExtend_Status.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.lxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.lxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Compound.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.lxx \
  /usr/local/opencascade/inc/ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Surface.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/ShapeFix_Face.lxx \
  /usr/local/opencascade/inc/ShapeExtend.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.lxx \
  /usr/local/opencascade/inc/ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_HSequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.lxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.lxx \
  /usr/local/opencascade/inc/BRepMesh.hxx \
  /usr/local/opencascade/inc/BRepMesh_IncrementalMesh.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_FastDiscret.hxx \
  /usr/local/opencascade/inc/BRepMesh_DataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_DataMapNodeOfDataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Bnd_Box.hxx \
  /usr/local/opencascade/inc/Bnd_Box.lxx \
  /usr/local/opencascade/inc/BRepBndLib.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis.hxx \
  /usr/local/opencascade/inc/ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/IGESControl_Writer.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_FinderProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForFinder.hxx \
  /usr/local/opencascade/inc/IGESData_BasicEditor.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_Protocol.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Protocol.hxx \
  /usr/local/opencascade/inc/Interface_GeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_NodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GeneralModule.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GlobalNodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/IGESData_SpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_NodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESEntity.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_SpecificModule.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_GlobalNodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/STEPControl_Writer.hxx \
  /usr/local/opencascade/inc/STEPControl_StepModelType.hxx \
  /usr/local/opencascade/inc/StlAPI_Writer.hxx \
  /usr/local/opencascade/inc/Handle_StlMesh_Mesh.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeTolerance.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_DataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_DataMapNodeOfDataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_Fuse.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_BooleanOperation.hxx \
  /usr/local/opencascade/inc/BOP_Operation.hxx \
  /usr/local/opencascade/inc/BOPTools_PDSFiller.hxx \
  /usr/local/opencascade/inc/BOP_PBuilder.hxx \
  /usr/local/opencascade/inc/Handle_BOP_HistoryCollector.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.hxx \
  /usr/local/opencascade/inc/BRepCheck_DataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_Result.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_DataMapNodeOfDataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.lxx \
  /usr/local/opencascade/inc/BRepLib.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Plane.hxx \
  /usr/local/opencascade/inc/Handle_Geom_ElementarySurface.hxx \
  /usr/local/opencascade/inc/ShapeFix.hxx \
  /usr/local/opencascade/inc/ShapeFix_FixSmallFace.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_FixSmallFace.hxx OCCEdge.h \
  OCCFace.h ../Common/Message.h
OCCRegion.o: OCCRegion.cpp GModel.h GVertex.h GEntity.h Range.h SPoint3.h \
  SBoundingBox3d.h ../Common/GmshDefines.h MVertex.h GPoint.h GEdge.h \
  SVector3.h SPoint2.h MElement.h MEdge.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h \
  ExtrudeParams.h GFace.h Pair.h GRegion.h ../Common/SmoothNormals.h \
  OCCVertex.h ../Mesh/Mesh.h ../DataStr/Tree.h ../DataStr/avl.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h OCCIncludes.h \
  /usr/local/opencascade/inc/config.h \
  /usr/local/opencascade/inc/BRep_Tool.hxx \
  /usr/local/opencascade/inc/Standard_Boolean.hxx \
  /usr/local/opencascade/inc/Standard_TypeDef.hxx \
  /usr/local/opencascade/inc/Standard_Macro.hxx \
  /usr/local/opencascade/inc/Standard_Stream.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Surface.hxx \
  /usr/local/opencascade/inc/Standard.hxx \
  /usr/local/opencascade/inc/Standard_Address.hxx \
  /usr/local/opencascade/inc/Standard_Integer.hxx \
  /usr/local/opencascade/inc/Standard_values.h \
  /usr/local/opencascade/inc/Standard_OStream.hxx \
  /usr/local/opencascade/inc/Standard_CString.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_PrimitiveTypes.hxx \
  /usr/local/opencascade/inc/Standard_Real.hxx \
  /usr/local/opencascade/inc/Standard_Character.hxx \
  /usr/local/opencascade/inc/Standard_ctype.hxx \
  /usr/local/opencascade/inc/Standard_ExtCharacter.hxx \
  /usr/local/opencascade/inc/Standard_ExtString.hxx \
  /usr/local/opencascade/inc/Standard_Storable.hxx \
  /usr/local/opencascade/inc/Standard_Transient_proto.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon3D.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Handle_Poly_Polygon2D.hxx \
  /usr/local/opencascade/inc/Handle_Poly_PolygonOnTriangulation.hxx \
  /usr/local/opencascade/inc/GeomAbs_Shape.hxx \
  /usr/local/opencascade/inc/Geom_Curve.hxx \
  /usr/local/opencascade/inc/Geom_Geometry.hxx \
  /usr/local/opencascade/inc/MMgt_TShared.hxx \
  /usr/local/opencascade/inc/Standard_Transient.hxx \
  /usr/local/opencascade/inc/Standard_Type.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Type.hxx \
  /usr/local/opencascade/inc/Standard_KindOfType.hxx \
  /usr/local/opencascade/inc/Standard_Type.lxx \
  /usr/local/opencascade/inc/Geom2d_Curve.hxx \
  /usr/local/opencascade/inc/Geom2d_Geometry.hxx \
  /usr/local/opencascade/inc/Geom_Surface.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPS.hxx \
  /usr/local/opencascade/inc/Adaptor3d_SurfacePtr.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElS.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.hxx \
  /usr/local/opencascade/inc/gp_Pnt.hxx \
  /usr/local/opencascade/inc/gp_XYZ.hxx \
  /usr/local/opencascade/inc/gp_XYZ.lxx /usr/local/opencascade/inc/gp.hxx \
  /usr/local/opencascade/inc/gp.lxx /usr/local/opencascade/inc/gp_Mat.hxx \
  /usr/local/opencascade/inc/gp_Mat.lxx \
  /usr/local/opencascade/inc/Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_OutOfRange.hxx \
  /usr/local/opencascade/inc/Handle_Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_SStream.hxx \
  /usr/local/opencascade/inc/Standard_RangeError.hxx \
  /usr/local/opencascade/inc/Standard_DomainError.hxx \
  /usr/local/opencascade/inc/Standard_Failure.hxx \
  /usr/local/opencascade/inc/Standard_Failure.lxx \
  /usr/local/opencascade/inc/Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/Handle_Standard_ConstructionError.hxx \
  /usr/local/opencascade/inc/gp_Pnt.lxx \
  /usr/local/opencascade/inc/gp_Trsf.hxx \
  /usr/local/opencascade/inc/gp_TrsfForm.hxx \
  /usr/local/opencascade/inc/gp_Trsf.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.hxx \
  /usr/local/opencascade/inc/gp_Mat2d.lxx \
  /usr/local/opencascade/inc/gp_XY.hxx \
  /usr/local/opencascade/inc/gp_XY.lxx \
  /usr/local/opencascade/inc/gp_Trsf2d.lxx \
  /usr/local/opencascade/inc/gp_Pnt2d.hxx \
  /usr/local/opencascade/inc/gp_Pnt2d.lxx \
  /usr/local/opencascade/inc/gp_Vec2d.hxx \
  /usr/local/opencascade/inc/gp_Vec2d.lxx \
  /usr/local/opencascade/inc/gp_Dir2d.hxx \
  /usr/local/opencascade/inc/gp_Dir2d.lxx \
  /usr/local/opencascade/inc/gp_Ax2d.hxx \
  /usr/local/opencascade/inc/gp_Ax2d.lxx \
  /usr/local/opencascade/inc/gp_Vec.hxx \
  /usr/local/opencascade/inc/gp_Vec.lxx \
  /usr/local/opencascade/inc/gp_Dir.hxx \
  /usr/local/opencascade/inc/gp_Dir.lxx \
  /usr/local/opencascade/inc/gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Handle_gp_VectorWithNullMagnitude.hxx \
  /usr/local/opencascade/inc/Extrema_POnSurf.lxx \
  /usr/local/opencascade/inc/Extrema_GenExtPS.hxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray2OfPnt.hxx \
  /usr/local/opencascade/inc/Extrema_FuncExtPS.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfReal.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.hxx \
  /usr/local/opencascade/inc/TCollection_BaseSequence.lxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfReal.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_SeqNode.hxx \
  /usr/local/opencascade/inc/TCollection_Sequence.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnSurf.hxx \
  /usr/local/opencascade/inc/math_FunctionSetWithDerivatives.hxx \
  /usr/local/opencascade/inc/math_FunctionSet.hxx \
  /usr/local/opencascade/inc/GeomAbs_SurfaceType.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Surface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedSurface.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineSurface.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/Quantity_Parameter.hxx \
  /usr/local/opencascade/inc/Quantity_Length.hxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnSurf.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_ExtPElC.hxx \
  /usr/local/opencascade/inc/Extrema_POnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_Point.lxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfPOnCurv.hxx \
  /usr/local/opencascade/inc/Extrema_EPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Extrema_PCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/Extrema_SeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSeqPCOfPCFOfEPCOfExtPC.hxx \
  /usr/local/opencascade/inc/math_FunctionWithDerivative.hxx \
  /usr/local/opencascade/inc/math_Function.hxx \
  /usr/local/opencascade/inc/GeomAbs_CurveType.hxx \
  /usr/local/opencascade/inc/Extrema_SequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/Handle_Extrema_SequenceNodeOfSequenceOfBoolean.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Adaptor3d_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BezierCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BoundedCurve.hxx \
  /usr/local/opencascade/inc/Handle_Geom_BSplineCurve.hxx \
  /usr/local/opencascade/inc/GeomAdaptor_Curve.lxx \
  /usr/local/opencascade/inc/GeomAPI_ProjectPointOnCurve.lxx \
  /usr/local/opencascade/inc/BRepTools.hxx \
  /usr/local/opencascade/inc/Standard_IStream.hxx \
  /usr/local/opencascade/inc/TopExp.hxx \
  /usr/local/opencascade/inc/TopAbs_ShapeEnum.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeVertex.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShape.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.hxx \
  /usr/local/opencascade/inc/TopLoc_SListOfItemLocation.hxx \
  /usr/local/opencascade/inc/Handle_TopLoc_SListNodeOfSListOfItemLocation.hxx \
  /usr/local/opencascade/inc/TCollection_SList.lxx \
  /usr/local/opencascade/inc/Handle_TopLoc_Datum3D.hxx \
  /usr/local/opencascade/inc/TopLoc_Location.lxx \
  /usr/local/opencascade/inc/TopLoc_ItemLocation.hxx \
  /usr/local/opencascade/inc/TopLoc_TrsfPtr.hxx \
  /usr/local/opencascade/inc/TopAbs_Orientation.hxx \
  /usr/local/opencascade/inc/TopoDS_Shape.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.hxx \
  /usr/local/opencascade/inc/TopoDS_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopoDS_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_MapNode.hxx \
  /usr/local/opencascade/inc/TCollection_List.lxx \
  /usr/local/opencascade/inc/TopoDS_TShape.lxx \
  /usr/local/opencascade/inc/TopAbs.hxx \
  /usr/local/opencascade/inc/TopAbs_State.hxx \
  /usr/local/opencascade/inc/TopTools_ListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_ListNodeOfListOfShape.hxx \
  /usr/local/opencascade/inc/BRepLib_Command.hxx \
  /usr/local/opencascade/inc/BRepLib_ShapeModification.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Command.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeShell.hxx \
  /usr/local/opencascade/inc/BRepLib_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_ShellError.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepLib_MakeSolid.hxx \
  /usr/local/opencascade/inc/BRepOffsetAPI_Sewing.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/Handle_BRepBuilderAPI_Sewing.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.hxx \
  /usr/local/opencascade/inc/TCollection_MapNodePtr.hxx \
  /usr/local/opencascade/inc/TCollection_BasicMap.lxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedMapNodeOfIndexedMapOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_IndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_IndexedDataMapNodeOfIndexedDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeShape.hxx \
  /usr/local/opencascade/inc/TopTools_DataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_DataMapNodeOfDataMapOfShapeListOfShape.hxx \
  /usr/local/opencascade/inc/Handle_BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/TopTools_MapOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_StdMapNodeOfMapOfShape.hxx \
  /usr/local/opencascade/inc/BRepBuilderAPI_Sewing.lxx \
  /usr/local/opencascade/inc/BRepLProp_SLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.hxx \
  /usr/local/opencascade/inc/TopoDS_Face.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Surface.lxx \
  /usr/local/opencascade/inc/LProp_Status.hxx \
  /usr/local/opencascade/inc/Poly_Triangulation.hxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt.hxx \
  /usr/local/opencascade/inc/TCollection_Array1.lxx \
  /usr/local/opencascade/inc/Handle_TColgp_HArray1OfPnt2d.hxx \
  /usr/local/opencascade/inc/Poly_Array1OfTriangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.hxx \
  /usr/local/opencascade/inc/Poly_Triangle.lxx \
  /usr/local/opencascade/inc/Poly_Triangulation.lxx \
  /usr/local/opencascade/inc/TColgp_Array1OfPnt2d.hxx \
  /usr/local/opencascade/inc/GProp_GProps.hxx \
  /usr/local/opencascade/inc/BRepGProp.hxx \
  /usr/local/opencascade/inc/TopoDS.hxx \
  /usr/local/opencascade/inc/TopoDS.lxx \
  /usr/local/opencascade/inc/Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/Handle_Standard_TypeMismatch.hxx \
  /usr/local/opencascade/inc/TopoDS_Solid.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.hxx \
  /usr/local/opencascade/inc/TopExp_Stack.hxx \
  /usr/local/opencascade/inc/TopExp_Explorer.lxx \
  /usr/local/opencascade/inc/TopoDS_Wire.hxx \
  /usr/local/opencascade/inc/BRepTools_WireExplorer.hxx \
  /usr/local/opencascade/inc/TopoDS_Edge.hxx \
  /usr/local/opencascade/inc/TopoDS_Vertex.hxx \
  /usr/local/opencascade/inc/BRepLProp_CLProps.hxx \
  /usr/local/opencascade/inc/BRepAdaptor_Curve.hxx \
  /usr/local/opencascade/inc/Handle_Adaptor3d_HCurveOnSurface.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.hxx \
  /usr/local/opencascade/inc/XSControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_XSControl_WorkSession.hxx \
  /usr/local/opencascade/inc/Handle_IFSelect_WorkSession.hxx \
  /usr/local/opencascade/inc/TColStd_SequenceOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_SequenceNodeOfSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/TopTools_SequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_SequenceNodeOfSequenceOfShape.hxx \
  /usr/local/opencascade/inc/IFSelect_ReturnStatus.hxx \
  /usr/local/opencascade/inc/Handle_Interface_InterfaceModel.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfTransient.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintCount.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESModel.hxx \
  /usr/local/opencascade/inc/IFSelect_PrintFail.hxx \
  /usr/local/opencascade/inc/IGESControl_Reader.lxx \
  /usr/local/opencascade/inc/STEPControl_Reader.hxx \
  /usr/local/opencascade/inc/Handle_StepData_StepModel.hxx \
  /usr/local/opencascade/inc/IGESToBRep_Reader.hxx \
  /usr/local/opencascade/inc/Handle_IGESToBRep_Actor.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfTransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ActorOfProcessForTransient.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_TransientProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForTransient.hxx \
  /usr/local/opencascade/inc/Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Static.hxx \
  /usr/local/opencascade/inc/Handle_Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Handle_MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.hxx \
  /usr/local/opencascade/inc/TCollection_AsciiString.lxx \
  /usr/local/opencascade/inc/Interface_ParamType.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HArray1OfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfInteger.hxx \
  /usr/local/opencascade/inc/Interface_StaticSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Interface_TypedValue.hxx \
  /usr/local/opencascade/inc/Interface_ValueInterpret.hxx \
  /usr/local/opencascade/inc/Interface_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/MoniTool_TypedValue.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueType.hxx \
  /usr/local/opencascade/inc/MoniTool_ValueInterpret.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_TCollection_HExtendedString.hxx \
  /usr/local/opencascade/inc/TCollection_HAsciiString.lxx \
  /usr/local/opencascade/inc/MoniTool_ValueSatisfies.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfAsciiString.hxx \
  /usr/local/opencascade/inc/Handle_Dico_DictionaryOfTransient.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfHAsciiString.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.hxx \
  /usr/local/opencascade/inc/Extrema_ExtCC.hxx \
  /usr/local/opencascade/inc/GeomAPI_ExtremaCurveCurve.lxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.hxx \
  /usr/local/opencascade/inc/Standard_ErrorHandler.lxx \
  /usr/local/opencascade/inc/ShapeUpgrade_ShellSewing.hxx \
  /usr/local/opencascade/inc/Handle_ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shape.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_BasicMsgRegistrator.hxx \
  /usr/local/opencascade/inc/Message_Gravity.hxx \
  /usr/local/opencascade/inc/ShapeFix_Root.lxx \
  /usr/local/opencascade/inc/Precision.hxx \
  /usr/local/opencascade/inc/Precision.lxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Edge.hxx \
  /usr/local/opencascade/inc/ShapeExtend_Status.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shape.lxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.hxx \
  /usr/local/opencascade/inc/ShapeFix_Solid.lxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Shell.hxx \
  /usr/local/opencascade/inc/TopoDS_Compound.hxx \
  /usr/local/opencascade/inc/ShapeFix_Shell.lxx \
  /usr/local/opencascade/inc/ShapeFix_Face.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Surface.hxx \
  /usr/local/opencascade/inc/Handle_ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/ShapeFix_Face.lxx \
  /usr/local/opencascade/inc/ShapeExtend.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wire.lxx \
  /usr/local/opencascade/inc/ShapeExtend_WireData.hxx \
  /usr/local/opencascade/inc/Handle_TopTools_HSequenceOfShape.hxx \
  /usr/local/opencascade/inc/Handle_TColStd_HSequenceOfInteger.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_Wire.lxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_Wireframe.hxx \
  /usr/local/opencascade/inc/ShapeFix_Wireframe.lxx \
  /usr/local/opencascade/inc/BRepMesh.hxx \
  /usr/local/opencascade/inc/BRepMesh_IncrementalMesh.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_FastDiscret.hxx \
  /usr/local/opencascade/inc/BRepMesh_DataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Handle_BRepMesh_DataMapNodeOfDataMapOfShapeReal.hxx \
  /usr/local/opencascade/inc/Bnd_Box.hxx \
  /usr/local/opencascade/inc/Bnd_Box.lxx \
  /usr/local/opencascade/inc/BRepBndLib.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis.hxx \
  /usr/local/opencascade/inc/ShapeBuild_ReShape.hxx \
  /usr/local/opencascade/inc/BRepTools_ReShape.hxx \
  /usr/local/opencascade/inc/IGESControl_Writer.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_FinderProcess.hxx \
  /usr/local/opencascade/inc/Handle_Transfer_ProcessForFinder.hxx \
  /usr/local/opencascade/inc/IGESData_BasicEditor.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_Protocol.hxx \
  /usr/local/opencascade/inc/Handle_Interface_Protocol.hxx \
  /usr/local/opencascade/inc/Interface_GeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_NodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GeneralModule.hxx \
  /usr/local/opencascade/inc/Handle_Interface_GlobalNodeOfGeneralLib.hxx \
  /usr/local/opencascade/inc/IGESData_SpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_NodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_IGESEntity.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_SpecificModule.hxx \
  /usr/local/opencascade/inc/Handle_IGESData_GlobalNodeOfSpecificLib.hxx \
  /usr/local/opencascade/inc/STEPControl_Writer.hxx \
  /usr/local/opencascade/inc/STEPControl_StepModelType.hxx \
  /usr/local/opencascade/inc/StlAPI_Writer.hxx \
  /usr/local/opencascade/inc/Handle_StlMesh_Mesh.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeTolerance.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_ShapeContents.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.hxx \
  /usr/local/opencascade/inc/ShapeAnalysis_CheckSmallFace.lxx \
  /usr/local/opencascade/inc/ShapeAnalysis_DataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/Handle_ShapeAnalysis_DataMapNodeOfDataMapOfShapeListOfReal.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_Fuse.hxx \
  /usr/local/opencascade/inc/BRepAlgoAPI_BooleanOperation.hxx \
  /usr/local/opencascade/inc/BOP_Operation.hxx \
  /usr/local/opencascade/inc/BOPTools_PDSFiller.hxx \
  /usr/local/opencascade/inc/BOP_PBuilder.hxx \
  /usr/local/opencascade/inc/Handle_BOP_HistoryCollector.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.hxx \
  /usr/local/opencascade/inc/BRepCheck_DataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_Result.hxx \
  /usr/local/opencascade/inc/Handle_BRepCheck_DataMapNodeOfDataMapOfShapeResult.hxx \
  /usr/local/opencascade/inc/BRepCheck_Analyzer.lxx \
  /usr/local/opencascade/inc/BRepLib.hxx \
  /usr/local/opencascade/inc/Handle_Geom_Plane.hxx \
  /usr/local/opencascade/inc/Handle_Geom_ElementarySurface.hxx \
  /usr/local/opencascade/inc/ShapeFix.hxx \
  /usr/local/opencascade/inc/ShapeFix_FixSmallFace.hxx \
  /usr/local/opencascade/inc/Handle_ShapeFix_FixSmallFace.hxx OCCEdge.h \
  OCCFace.h OCCRegion.h ../Common/Message.h
SVector3.o: SVector3.cpp SVector3.h SPoint3.h
SBoundingBox3d.o: SBoundingBox3d.cpp SBoundingBox3d.h SPoint3.h
projectionFace.o: projectionFace.cpp projectionFace.h GFace.h GPoint.h \
  GEntity.h Range.h SPoint3.h SBoundingBox3d.h ../Common/GmshDefines.h \
  MElement.h MVertex.h MEdge.h SVector3.h ../Common/Hash.h MFace.h \
  ../Numeric/Numeric.h ../Common/Context.h ../DataStr/List.h SPoint2.h \
  Pair.h ExtrudeParams.h
ExtractContour.o: ExtractContour.cpp ../Common/Gmsh.h ../Common/Message.h \
  ../DataStr/Malloc.h ../DataStr/List.h ../DataStr/Tree.h \
  ../DataStr/avl.h ../DataStr/Tools.h ../DataStr/List.h ../DataStr/Tree.h \
  Geo.h GeoUtils.h ../Mesh/Mesh.h ../Common/GmshDefines.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Mesh/Vertex.h ../Mesh/Element.h ../Mesh/Face.h ../Mesh/Vertex.h \
  ../Mesh/Element.h ../Mesh/Edge.h ../Mesh/Vertex.h ../Mesh/Simplex.h \
  ../Geo/ExtrudeParams.h ../Mesh/Metric.h ../Mesh/Vertex.h \
  ../Mesh/Simplex.h ../Mesh/Mesh.h ../Mesh/Matrix.h CAD.h ExtrudeParams.h \
  ../Numeric/Numeric.h
