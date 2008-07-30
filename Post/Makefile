# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
	rm -f *.o *.obj

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	${CXX} -MM -MG ${CFLAGS} ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	rm -f Makefile.new

# DO NOT DELETE THIS LINE
PView.o: PView.cpp PView.h ../Geo/SPoint3.h PViewOptions.h ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h PViewData.h PViewDataList.h \
  ../Common/ListUtils.h ../Common/VertexArray.h ../Geo/SVector3.h \
  ../Geo/SPoint3.h ../Common/SmoothData.h adaptiveData.h \
  ../Common/GmshMatrix.h ../Common/Message.h
PViewIO.o: PViewIO.cpp PView.h ../Geo/SPoint3.h PViewDataList.h \
  PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Common/ListUtils.h PViewDataGModel.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Common/StringUtils.h \
  ../Common/Message.h
PViewData.o: PViewData.cpp PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h ../Common/ListUtils.h adaptiveData.h \
  ../Common/GmshMatrix.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Message.h
PViewDataIO.o: PViewDataIO.cpp ../Common/Message.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h
PViewDataList.o: PViewDataList.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h \
  ../Common/SmoothData.h ../Common/Message.h ../Common/Context.h \
  ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h
PViewDataListIO.o: PViewDataListIO.cpp PViewDataList.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h ../Common/Message.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  adaptiveData.h ../Common/GmshMatrix.h
PViewDataGModel.o: PViewDataGModel.cpp PViewDataGModel.h PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Geo/GModel.h \
  ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/MElement.h \
  ../Common/GmshDefines.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Message.h
PViewDataGModelIO.o: PViewDataGModelIO.cpp ../Common/Message.h \
  PViewDataGModel.h PViewData.h ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h \
  ../Geo/GModel.h ../Geo/GVertex.h ../Geo/GEntity.h ../Geo/Range.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Geo/GPoint.h \
  ../Geo/SPoint2.h ../Geo/GEdge.h ../Geo/GEntity.h ../Geo/GVertex.h \
  ../Geo/SVector3.h ../Geo/SPoint3.h ../Geo/SPoint3.h ../Geo/SPoint2.h \
  ../Geo/GFace.h ../Geo/GEntity.h ../Geo/GPoint.h ../Geo/GEdgeLoop.h \
  ../Geo/GEdge.h ../Geo/SPoint2.h ../Geo/SVector3.h ../Geo/Pair.h \
  ../Geo/GRegion.h ../Geo/GEntity.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/MVertex.h ../Geo/SPoint3.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h ../Geo/MFace.h \
  ../Geo/MVertex.h ../Geo/SVector3.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/StringUtils.h
PViewOptions.o: PViewOptions.cpp PViewOptions.h ColorTable.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/Message.h
adaptiveData.o: adaptiveData.cpp ../Plugin/Plugin.h ../Common/Options.h \
  ../Post/ColorTable.h ../Common/Message.h ../Post/PView.h \
  ../Geo/SPoint3.h ../Post/PViewDataList.h ../Post/PViewData.h \
  ../Geo/SBoundingBox3d.h ../Geo/SPoint3.h ../Common/ListUtils.h \
  ../Common/GmshMatrix.h adaptiveData.h
OctreePost.o: OctreePost.cpp ../Common/Octree.h \
  ../Common/OctreeInternals.h OctreePost.h ../Common/ListUtils.h PView.h \
  ../Geo/SPoint3.h PViewDataList.h PViewData.h ../Geo/SBoundingBox3d.h \
  ../Geo/SPoint3.h PViewDataGModel.h ../Geo/GModel.h ../Geo/GVertex.h \
  ../Geo/GEntity.h ../Geo/Range.h ../Geo/SPoint3.h \
  ../Geo/SBoundingBox3d.h ../Geo/GPoint.h ../Geo/SPoint2.h ../Geo/GEdge.h \
  ../Geo/GEntity.h ../Geo/GVertex.h ../Geo/SVector3.h ../Geo/SPoint3.h \
  ../Geo/SPoint3.h ../Geo/SPoint2.h ../Geo/GFace.h ../Geo/GEntity.h \
  ../Geo/GPoint.h ../Geo/GEdgeLoop.h ../Geo/GEdge.h ../Geo/SPoint2.h \
  ../Geo/SVector3.h ../Geo/Pair.h ../Geo/GRegion.h ../Geo/GEntity.h \
  ../Geo/SPoint3.h ../Geo/SBoundingBox3d.h ../Numeric/Numeric.h \
  ../Numeric/NumericEmbedded.h ../Common/Message.h shapeFunctions.h \
  ../Geo/MElement.h ../Common/GmshDefines.h ../Geo/MVertex.h \
  ../Geo/SPoint3.h ../Geo/MEdge.h ../Geo/MVertex.h ../Geo/SVector3.h \
  ../Geo/MFace.h ../Geo/MVertex.h ../Geo/SVector3.h
ColorTable.o: ColorTable.cpp ../Common/Message.h ColorTable.h \
  ../Common/Context.h ../Geo/CGNSOptions.h ../Mesh/PartitionOptions.h \
  ../Numeric/Numeric.h ../Numeric/NumericEmbedded.h
