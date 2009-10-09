FLAGS = -g -O2 ${CXXFLAGS}
INC = -I/usr/local/include -I.
GMSH = -L/usr/local/lib -lGmsh
GLUT = -framework OpenGL -framework GLUT -framework Cocoa -framework ApplicationServices
#GLUT = -lGLUT -lGLU -lGL -lX11
OCC = /Users/remacle/SOURCES/opencascade/lib/libTKSTEP.a /Users/remacle/SOURCES/opencascade/lib/libTKSTEP209.a /Users/remacle/SOURCES/opencascade/lib/libTKSTEPAttr.a /Users/remacle/SOURCES/opencascade/lib/libTKSTEPBase.a /Users/remacle/SOURCES/opencascade/lib/libTKIGES.a /Users/remacle/SOURCES/opencascade/lib/libTKXSBase.a /Users/remacle/SOURCES/opencascade/lib/libTKOffset.a /Users/remacle/SOURCES/opencascade/lib/libTKFeat.a /Users/remacle/SOURCES/opencascade/lib/libTKFillet.a /Users/remacle/SOURCES/opencascade/lib/libTKBool.a /Users/remacle/SOURCES/opencascade/lib/libTKShHealing.a /Users/remacle/SOURCES/opencascade/lib/libTKMesh.a /Users/remacle/SOURCES/opencascade/lib/libTKHLR.a /Users/remacle/SOURCES/opencascade/lib/libTKBO.a /Users/remacle/SOURCES/opencascade/lib/libTKPrim.a /Users/remacle/SOURCES/opencascade/lib/libTKTopAlgo.a /Users/remacle/SOURCES/opencascade/lib/libTKGeomAlgo.a /Users/remacle/SOURCES/opencascade/lib/libTKBRep.a /Users/remacle/SOURCES/opencascade/lib/libTKGeomBase.a /Users/remacle/SOURCES/opencascade/lib/libTKG3d.a /Users/remacle/SOURCES/opencascade/lib/libTKG2d.a /Users/remacle/SOURCES/opencascade/lib/libTKAdvTools.a /Users/remacle/SOURCES/opencascade/lib/libTKMath.a /Users/remacle/SOURCES/opencascade/lib/libTKernel.a 

mainElasticity: mainElasticity.cpp
	g++ ${FLAGS} -o mainElasticity ${INC} mainElasticity.cpp\
          ${GMSH} -llapack -lblas -lm -L/Users/remacle/SOURCES/gmsh/contrib/taucs/lib -ltaucs

mainCartesian: mainCartesian.cpp
	g++ ${FLAGS} -o mainCartesian ${INC} mainCartesian.cpp\
          ${GMSH} -llapack -lblas -lm -L/Users/remacle/SOURCES/gmsh/contrib/taucs/lib -ltaucs ${OCC}

mainSimple: mainSimple.cpp
	g++ ${FLAGS} -o mainSimple ${INC} mainSimple.cpp\
          ${GMSH} -llapack -lblas -lm

mainAntTweakBar: mainAntTweakBar.cpp
	g++ ${FLAGS} -o mainAntTweakBar ${INC} mainAntTweakBar.cpp\
          ${GMSH} -lAntTweakBar ${GLUT} -llapack -lblas -lz -lm

mainGlut: mainGlut.cpp
	g++ ${FLAGS} -o mainGlut ${INC} mainGlut.cpp\
          ${GMSH} ${GLUT} -llapack -lblas -lz -lm

mainPost: mainPost.cpp
	g++ ${FLAGS} -o mainPost ${INC} mainPost.cpp\
          ${GMSH} -llapack -lblas -lm

mainLevelset: mainLevelset.cpp
	g++ ${FLAGS} -o mainLevelset ${INC} mainLevelset.cpp\
          ${GMSH} -llapack -lblas

clean:
	rm -rf mainSimple mainAntTweakBar mainGlut mainPost mainLevelset\
              *.dSYM *.msh *.pos
