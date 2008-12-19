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
      GaussQuadratureTri.cpp\
      GaussQuadratureQuad.cpp\
      GaussQuadratureTet.cpp\
      GaussQuadratureHex.cpp\
      GaussLegendreSimplex.cpp\
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
         ${CXX} -MM ${CFLAGS} ${SRC} | sed 's/.o:/$${OBJEXT}:/g' \
        ) > Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
Numeric${OBJEXT}: Numeric.cpp ../Common/GmshMessage.h Numeric.h \
  NumericEmbedded.h
NumericEmbedded${OBJEXT}: NumericEmbedded.cpp NumericEmbedded.h \
  ../Common/GmshMessage.h
gmshAssembler${OBJEXT}: gmshAssembler.cpp ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h gmshAssembler.h gmshLinearSystem.h
gmshTermOfFormulation${OBJEXT}: gmshTermOfFormulation.cpp ../Common/Gmsh.h \
  ../Common/GmshMessage.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  GmshMatrix.h gmshTermOfFormulation.h gmshFunction.h gmshLinearSystem.h \
  gmshAssembler.h
gmshLaplace${OBJEXT}: gmshLaplace.cpp gmshLaplace.h gmshTermOfFormulation.h \
  GmshMatrix.h ../Common/GmshMessage.h gmshFunction.h ../Common/Gmsh.h \
  ../Common/GmshMessage.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  Numeric.h
gmshElasticity${OBJEXT}: gmshElasticity.cpp gmshElasticity.h \
  gmshTermOfFormulation.h GmshMatrix.h ../Common/GmshMessage.h \
  ../Common/Gmsh.h ../Common/GmshMessage.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MElement.h ../Common/GmshDefines.h \
  ../Geo/MVertex.h ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  Numeric.h
EigSolve${OBJEXT}: EigSolve.cpp
FunctionSpace${OBJEXT}: FunctionSpace.cpp FunctionSpace.h GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/GmshDefines.h
GaussQuadratureTri${OBJEXT}: GaussQuadratureTri.cpp Gauss.h Numeric.h \
  NumericEmbedded.h GaussLegendre1D.h
GaussQuadratureQuad${OBJEXT}: GaussQuadratureQuad.cpp Gauss.h Numeric.h \
  NumericEmbedded.h GaussLegendre1D.h
GaussQuadratureTet${OBJEXT}: GaussQuadratureTet.cpp Gauss.h Numeric.h \
  NumericEmbedded.h GaussLegendre1D.h
GaussQuadratureHex${OBJEXT}: GaussQuadratureHex.cpp Gauss.h Numeric.h \
  NumericEmbedded.h GaussLegendre1D.h
GaussLegendreSimplex${OBJEXT}: GaussLegendreSimplex.cpp Gauss.h Numeric.h \
  NumericEmbedded.h GaussLegendre1D.h
gmsh_predicates${OBJEXT}: gmsh_predicates.cpp
gsl_newt${OBJEXT}: gsl_newt.cpp ../Common/GmshMessage.h Numeric.h \
  NumericEmbedded.h
gsl_min${OBJEXT}: gsl_min.cpp ../Common/GmshMessage.h Numeric.h \
  NumericEmbedded.h
gsl_brent${OBJEXT}: gsl_brent.cpp ../Common/GmshMessage.h Numeric.h \
  NumericEmbedded.h
