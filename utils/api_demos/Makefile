#
# how to build a standalone 64 bit gmsh graphics lib on OSX:
# 
#   export CC="gcc -m64"
#   export CXX="g++ -m64"
#   ./configure --disable-gui --disable-netgen --disable-fm --disable-kbipack\
#               --disable-occ --enable-graphics --disable-med --disable-chaco\
#               --disable-metis --prefix=$HOME/src/gmsh/utils/api_demos
#   make install-lib
# 
GMSHLIBDIR = $(DEVROOT)/gmshLib
GMSHINCDIR = $(DEVROOT)/gmsh/include

mainAntTweakBar: mainAntTweakBar.cpp
	g++ -g -m64 -o mainAntTweakBar -Iinclude mainAntTweakBar.cpp -Llib\
          -lGmsh -lAntTweakBar -framework OpenGL -framework GLUT -framework Cocoa\
          -framework ApplicationServices -llapack -lblas -lz -lm

mainGlut: mainGlut.cpp
	g++ -g -m64 -o mainGlut -Iinclude mainGlut.cpp -Llib -lGmsh\
          -framework OpenGL -framework GLUT -framework Cocoa\
          -framework ApplicationServices -llapack -lblas -lz -lm

mainPost: mainPost.cpp
	g++ -g -m64 -o mainPost -Iinclude mainPost.cpp -Llib -lGmsh\
          -framework ApplicationServices -llapack -lblas -lz -lm

levelset: mainLevelset.cpp
	g++ -g -I${GMSHINCDIR} -DHAVE_GSL -DHAVE_GLEVELSETS -DHAVE_GMM -DHAVE_SPARSKIT \
	-o levelset mainLevelset.cpp -L${GMSHLIBDIR} -lGmsh -lgsl -lgslcblas -llapack -lblas

