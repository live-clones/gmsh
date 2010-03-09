FLAGS = -g -O2 ${CXXFLAGS}
INC = -I/usr/local/include -I. -I /home/gauthier/distgmsh/trunk/buildlib/lib/include
GMSH = -L/home/gauthier/distgmsh/trunk/buildlib/lib/lib -lGmsh
METIS= -L/usr/local/lib -lmetis
GLUT = -framework OpenGL -framework GLUT -framework Cocoa -framework ApplicationServices
#GLUT = -lGLUT -lGLU -lGL -lX11
OCC = -L/usr/local/opencascade/lib -L/Users/remacle/SOURCES/opencascade/lib -lTKSTEP -lTKSTEP209 -lTKSTEPAttr -lTKSTEPBase -lTKIGES -lTKXSBase -lTKOffset -lTKFeat -lTKFillet -lTKBool -lTKShHealing -lTKMesh -lTKHLR -lTKBO -lTKPrim -lTKTopAlgo -lTKGeomAlgo -lTKBRep -lTKGeomBase -lTKG3d -lTKG2d -lTKAdvTools -lTKMath -lTKernel
TAUCS = -L/Users/remacle/SOURCES/gmsh/contrib/taucs/lib -L/home/gaetan/develop/gmsh/contrib/taucs/lib/linux -ltaucs

mainLua: mainLua.cpp
	g++ ${FLAGS} -I../../Geo/ -I../../lib/Common -I../../Common -DHAVE_LUA -o mainLua ${INC} mainLua.cpp\
          ${GMSH} -llapack -lblas -lm ${TAUCS} ${OCC} -llua

mainElasticity: mainElasticity.cpp
	g++ ${FLAGS} -o mainElasticity ${INC} mainElasticity.cpp\
          ${GMSH} -llapack -lblas -lm -lmetis ${TAUCS}

mainFDPlate: mainFDPlate.cpp
	g++ ${FLAGS} -o mainFDPlate ${INC} mainFDPlate.cpp\
          ${GMSH} -llapack -lblas -lm ${TAUCS} ${OCC}

mainCartesian: mainCartesian.cpp
	g++ ${FLAGS} -o mainCartesian ${INC} mainCartesian.cpp\
          ${GMSH} -llapack -lblas -lm ${OCC} ${GLUT}

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
          ${GMSH} -llapack -lblas -lm -lmetis ${TAUCS}

clean:
	rm -rf mainSimple mainAntTweakBar mainGlut mainPost mainLevelset\
              *.dSYM *.msh *.pos
