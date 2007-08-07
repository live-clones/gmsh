include ../../variables

LIB = ../../lib/libGmshFourierModel.a

CFLAGS = ${OPTIM} ${FLAGS}

SRC = ProjectionSurface.cpp \
	PlaneProjectionSurface.cpp \
	ParaboloidProjectionSurface.cpp \
	CylindricalProjectionSurface.cpp \
	RevolvedParabolaProjectionSurface.cpp \
      Patch.cpp \
	FPatch.cpp \
	ContinuationPatch.cpp \
	ExactPatch.cpp\
      Curve.cpp \
	FCurve.cpp\
	IntersectionCurve.cpp \
      BlendedPatch.cpp \
      BlendOperator.cpp \
      FM_Edge.cpp\
      FM_Face.cpp\
      FM_Info.cpp\
      FM_Reader.cpp\
      FM_Vertex.cpp\
      Message.cpp \
      Utils.cpp \
      PartitionOfUnity.cpp

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
PlaneProjectionSurface.o: PlaneProjectionSurface.cpp \
  PlaneProjectionSurface.h ProjectionSurface.h
ParaboloidProjectionSurface.o: ParaboloidProjectionSurface.cpp \
  ParaboloidProjectionSurface.h Utils.h ProjectionSurface.h
CylindricalProjectionSurface.o: CylindricalProjectionSurface.cpp \
  CylindricalProjectionSurface.h ProjectionSurface.h
RevolvedParabolaProjectionSurface.o:  \
 RevolvedParabolaProjectionSurface.cpp \
  RevolvedParabolaProjectionSurface.h Utils.h ProjectionSurface.h
Patch.o: Patch.cpp Patch.h ProjectionSurface.h
FPatch.o: FPatch.cpp Message.h FPatch.h Patch.h ProjectionSurface.h \
  PartitionOfUnity.h
ContinuationPatch.o: ContinuationPatch.cpp Message.h ContinuationPatch.h \
  Patch.h ProjectionSurface.h FM_Info.h PartitionOfUnity.h
ExactPatch.o: ExactPatch.cpp Message.h ExactPatch.h Patch.h \
  ProjectionSurface.h FM_Info.h
Curve.o: Curve.cpp Curve.h
FCurve.o: FCurve.cpp FCurve.h Curve.h Patch.h ProjectionSurface.h
IntersectionCurve.o: IntersectionCurve.cpp Message.h IntersectionCurve.h \
  Curve.h Patch.h ProjectionSurface.h FM_Info.h
BlendedPatch.o: BlendedPatch.cpp BlendedPatch.h Message.h Patch.h \
  ProjectionSurface.h BlendOperator.h FM_Info.h PartitionOfUnity.h
BlendOperator.o: BlendOperator.cpp BlendOperator.h FM_Info.h Patch.h \
  ProjectionSurface.h
FM_Edge.o: FM_Edge.cpp FM_Edge.h Curve.h FM_Vertex.h Message.h
FM_Face.o: FM_Face.cpp FM_Face.h Patch.h ProjectionSurface.h FM_Edge.h \
  Curve.h FM_Vertex.h Message.h
FM_Info.o: FM_Info.cpp FM_Info.h
FM_Reader.o: FM_Reader.cpp Message.h FM_Reader.h Curve.h \
  IntersectionCurve.h Patch.h ProjectionSurface.h FM_Info.h ExactPatch.h \
  ContinuationPatch.h PartitionOfUnity.h PlaneProjectionSurface.h \
  CylindricalProjectionSurface.h ParaboloidProjectionSurface.h Utils.h \
  RevolvedParabolaProjectionSurface.h FM_Face.h FM_Edge.h FM_Vertex.h \
  BlendOperator.h BlendedPatch.h
FM_Vertex.o: FM_Vertex.cpp
Message.o: Message.cpp Message.h
Utils.o: Utils.cpp Utils.h Message.h
PartitionOfUnity.o: PartitionOfUnity.cpp PartitionOfUnity.h
