include ../../variables

LIB = ../../lib/libGmshFourierModel.a

CFLAGS = ${OPTIM} ${FLAGS}

SRC = ProjectionSurface.cpp \
	CylindricalProjectionSurface.cpp \
	RevolvedParabolaProjectionSurface.cpp \
      Patch.h \
	FPatch.cpp \
	ContinuationPatch.cpp \
	ExactPatch.cpp\
      Curve.cpp \
	FCurve.cpp\
	IntersectionCurve.cpp \
      Point.cpp \
      BlendedPatch.cpp \
      BlendOperator.cpp \
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
