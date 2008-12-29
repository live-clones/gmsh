# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include ../variables

LIB = ../lib/libGmshPost${LIBEXT}

INC = ${DASH}I../Common ${DASH}I../Geo ${DASH}I../Mesh\
      ${DASH}I../Post ${DASH}I../Graphics ${DASH}I../Numeric ${DASH}I../Parser\
      ${DASH}I../Plugin ${DASH}I../Fltk ${DASH}I../contrib/MathEval\
      ${DASH}I../contrib/ANN/include

CFLAGS =${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}

SRC = PView.cpp PViewIO.cpp\
        PViewData.cpp PViewDataIO.cpp\
          PViewDataList.cpp PViewDataListIO.cpp\
          PViewDataGModel.cpp PViewDataGModelIO.cpp\
        PViewOptions.cpp\
      adaptiveData.cpp\
      OctreePost.cpp\
      ColorTable.cpp

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
PView${OBJEXT}: PView.cpp PView.h ../Geo/SPoint3.h PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/ListUtils.h PViewDataGModel.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h PViewOptions.h ColorTable.h \
  ../Common/VertexArray.h ../Common/SmoothData.h adaptiveData.h
PViewIO${OBJEXT}: PViewIO.cpp PView.h ../Geo/SPoint3.h PViewDataList.h \
  PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Common/GmshMessage.h ../Common/ListUtils.h \
  PViewDataGModel.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Common/StringUtils.h
PViewData${OBJEXT}: PViewData.cpp PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshMessage.h \
  ../Common/ListUtils.h adaptiveData.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GmshMatrix.h
PViewDataIO${OBJEXT}: PViewDataIO.cpp ../Common/GmshMessage.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Numeric/GmshMatrix.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
PViewDataList${OBJEXT}: PViewDataList.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GmshMatrix.h \
  ../Common/SmoothData.h ../Common/Context.h ../Geo/CGNSOptions.h \
  ../Mesh/PartitionOptions.h
PViewDataListIO${OBJEXT}: PViewDataListIO.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Common/ListUtils.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GmshMatrix.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  adaptiveData.h
PViewDataGModel${OBJEXT}: PViewDataGModel.cpp PViewDataGModel.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint2.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Numeric/GmshMatrix.h
PViewDataGModelIO${OBJEXT}: PViewDataGModelIO.cpp ../Common/GmshMessage.h \
  PViewDataGModel.h PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Numeric/GmshMatrix.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/MEdge.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h \
  ../Numeric/Gauss.h ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Numeric/GmshMatrix.h ../Common/StringUtils.h
PViewOptions${OBJEXT}: PViewOptions.cpp PViewOptions.h ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/GmshMessage.h
adaptiveData${OBJEXT}: adaptiveData.cpp adaptiveData.h ../Numeric/GmshMatrix.h \
  ../Common/GmshMessage.h ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Post/PView.h ../Geo/SPoint3.h \
  ../Post/PViewDataList.h ../Post/PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h ../Common/OS.h
OctreePost${OBJEXT}: OctreePost.cpp ../Common/Octree.h \
  ../Common/OctreeInternals.h OctreePost.h ../Common/ListUtils.h PView.h \
  ../Geo/SPoint3.h PViewDataList.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Numeric/GmshMatrix.h ../Common/GmshMessage.h \
  PViewDataGModel.h ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h \
  ../Geo/Range.h ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Numeric/GmshMatrix.h shapeFunctions.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint2.h ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h \
  ../Geo/SVector3.h ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Numeric/FunctionSpace.h ../Numeric/GmshMatrix.h ../Numeric/Gauss.h
ColorTable${OBJEXT}: ColorTable.cpp ../Common/GmshMessage.h ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Numeric/GmshMatrix.h
