include ../../variables

LIB = ../../lib/libGmshFourierModel.a

CFLAGS = ${OPTIM} ${FLAGS}

SRC = ProjectionSurface.cpp \
	CylindricalProjectionSurface.cpp \
	RevolvedParabolaProjectionSurface.cpp \
      ContinuationPatch.cpp \
      ExactPatch.cpp\
      Patch.cpp\
      BlendedPatch.cpp \
      BlendOperator.cpp \
      Curve.cpp\
      FM_Edge.cpp\
      FM_Face.cpp\
      FM_Info.cpp\
      FM_Reader.cpp\
      FM_Vertex.cpp\
      Message.cpp \
      Utils.cpp \
      PartitionOfUnity.cpp \
      Interpolator1D.cpp

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
ProjectionSurface.o: ProjectionSurface.cpp ProjectionSurface.h
CylindricalProjectionSurface.o: CylindricalProjectionSurface.cpp \
  CylindricalProjectionSurface.h ProjectionSurface.h
RevolvedParabolaProjectionSurface.o: RevolvedParabolaProjectionSurface.cpp \
  RevolvedParabolaProjectionSurface.h ProjectionSurface.h
ContinuationPatch.o: ContinuationPatch.cpp Message.h ContinuationPatch.h \
  Patch.h FM_Info.h PartitionOfUnity.h
ExactPatch.o: ExactPatch.cpp Message.h ExactPatch.h Patch.h FM_Info.h
Patch.o: Patch.cpp Patch.h FM_Info.h
BlendedPatch.o: BlendedPatch.cpp BlendedPatch.h BlendOperator.h Patch.h
BlendOperator.o: BlendOperator.cpp BlendOperator.h Patch.h ProjectionSurface.h
Curve.o: Curve.cpp Message.h Curve.h Patch.h FM_Info.h
FM_Edge.o: FM_Edge.cpp FM_Edge.h Curve.h Patch.h FM_Info.h FM_Vertex.h \
  Message.h
FM_Face.o: FM_Face.cpp FM_Face.h Patch.h FM_Info.h FM_Edge.h Curve.h \
  FM_Vertex.h Message.h
FM_Info.o: FM_Info.cpp FM_Info.h
FM_Reader.o: FM_Reader.cpp Message.h FM_Reader.h Curve.h Patch.h \
  FM_Info.h ExactPatch.h ContinuationPatch.h FM_Face.h FM_Edge.h \
  FM_Vertex.h
FM_Vertex.o: FM_Vertex.cpp
Message.o: Message.cpp Message.h
Utils.o: Utils.cpp Utils.h
PartitionOfUnity.o: PartitionOfUnity.cpp PartitionOfUnity.h
Interpolator1D.o: Interpolator1D.cpp Interpolator1D.h Message.h
