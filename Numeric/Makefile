# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshNumeric${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Numeric ${DASH}I../Geo

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = Numeric.cpp\
      GmshMatrix.cpp\
      gmshLaplace.cpp\
        gmshHelmholtz.cpp\
        gmshElasticity.cpp\
        gmshProjection.cpp\
      EigSolve.cpp\
      FunctionSpace.cpp\
      GaussQuadratureLin.cpp\
        GaussQuadratureTri.cpp\
        GaussQuadratureQuad.cpp\
        GaussQuadratureTet.cpp\
        GaussQuadratureHex.cpp\
        GaussLegendreSimplex.cpp\
      GmshPredicates.cpp\

OBJ = ${SRC:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

${LIB}: ${OBJ}
	${AR} ${ARFLAGS}${LIB} ${OBJ}
	${RANLIB} ${LIB}

cpobj: ${OBJ} 
	cp -f ${OBJ} ../lib/

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

# Don't optimize J. Shewchuk's predicates. Otherwise, Gmsh may not
# work properly.
GmshPredicates${OBJEXT}:
	${CXX} ${FLAGS} ${INC} ${SYSINCLUDE} ${DASH}c GmshPredicates.cpp

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
Numeric${OBJEXT}: Numeric.cpp ../Common/GmshConfig.h ../Common/GmshMessage.h \
  Numeric.h GmshMatrix.h
GmshMatrix${OBJEXT}: GmshMatrix.cpp ../Common/GmshConfig.h GmshMatrix.h \
  ../Common/GmshMessage.h
gmshLaplace${OBJEXT}: gmshLaplace.cpp gmshLaplace.h gmshTermOfFormulation.h \
  GmshMatrix.h ../Common/GmshConfig.h ../Common/GmshMessage.h \
  gmshFunction.h gmshAssembler.h gmshLinearSystem.h ../Geo/GModel.h \
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
  ../Numeric/Gauss.h ../Common/Gmsh.h ../Common/GmshMessage.h Numeric.h
gmshHelmholtz${OBJEXT}: gmshHelmholtz.cpp gmshHelmholtz.h \
  gmshTermOfFormulation.h GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h gmshFunction.h gmshAssembler.h \
  gmshLinearSystem.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/Gmsh.h ../Common/GmshMessage.h Numeric.h
gmshElasticity${OBJEXT}: gmshElasticity.cpp gmshElasticity.h \
  gmshTermOfFormulation.h GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h gmshFunction.h gmshAssembler.h \
  gmshLinearSystem.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/Gmsh.h ../Common/GmshMessage.h Numeric.h
gmshProjection${OBJEXT}: gmshProjection.cpp gmshProjection.h \
  gmshTermOfFormulation.h GmshMatrix.h ../Common/GmshConfig.h \
  ../Common/GmshMessage.h gmshFunction.h gmshAssembler.h \
  gmshLinearSystem.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Common/Gmsh.h ../Common/GmshMessage.h Numeric.h
EigSolve${OBJEXT}: EigSolve.cpp
FunctionSpace${OBJEXT}: FunctionSpace.cpp FunctionSpace.h GmshMatrix.h \
  ../Common/GmshConfig.h ../Common/GmshMessage.h ../Common/GmshDefines.h
GaussQuadratureLin${OBJEXT}: GaussQuadratureLin.cpp Gauss.h GaussLegendre1D.h
GaussQuadratureTri${OBJEXT}: GaussQuadratureTri.cpp Gauss.h GaussLegendre1D.h
GaussQuadratureQuad${OBJEXT}: GaussQuadratureQuad.cpp Gauss.h GaussLegendre1D.h
GaussQuadratureTet${OBJEXT}: GaussQuadratureTet.cpp Gauss.h GaussLegendre1D.h
GaussQuadratureHex${OBJEXT}: GaussQuadratureHex.cpp Gauss.h GaussLegendre1D.h
GaussLegendreSimplex${OBJEXT}: GaussLegendreSimplex.cpp Gauss.h \
  GaussLegendre1D.h
GmshPredicates${OBJEXT}: GmshPredicates.cpp
