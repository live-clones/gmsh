FLAGS = -g -O2
INC = -I/usr/local/include -I.
GMSH = -L/usr/local/lib -lGmsh
GLUT = -framework OpenGL -framework GLUT -framework Cocoa -framework ApplicationServices
#GLUT = -lGLUT -lGLU -lGL -lX11

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
