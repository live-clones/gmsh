LIB = -L/usr/local/lib -lGmsh -L.
INC = -I/usr/local/include -I.
FLAGS = -g -O2

mainSimple: mainSimple.cpp
	g++ ${FLAGS} -o mainSimple ${INC} mainSimple.cpp ${LIB}\
          -llapack -lblas -lm

mainAntTweakBar: mainAntTweakBar.cpp
	g++ ${FLAGS} -o mainAntTweakBar ${INC} mainAntTweakBar.cpp ${LIB}\
          -lAntTweakBar -framework OpenGL -framework GLUT -framework Cocoa\
          -framework ApplicationServices -llapack -lblas -lz -lm

mainGlut: mainGlut.cpp
	g++ ${FLAGS} -o mainGlut ${INC} mainGlut.cpp ${LIB}\
          -framework OpenGL -framework GLUT -framework Cocoa\
          -framework ApplicationServices -llapack -lblas -lz -lm

mainPost: mainPost.cpp
	g++ ${FLAGS} -o mainPost -Iinclude mainPost.cpp ${LIB}\
          -framework ApplicationServices -llapack -lblas -lm


mainLevelset: mainLevelset.cpp
	g++ ${FLAGS} $(INC) -DHAVE_GSL -DHAVE_GLEVELSETS -DHAVE_GMM -DHAVE_SPARSKIT \
	-o mainLevelset mainLevelset.cpp ${LIB} -lgsl -lgslcblas -llapack -lblas

clean:
	rm -rf mainSimple mainAntTweakBar mainGlut mainPost mainLevelset\
              *.dSYM *.msh *.pos
