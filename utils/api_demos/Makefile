#
# how to build a standalone 64 bit gmsh lib on OSX:
# 
#   export CC="gcc -m64"
#   export CXX="g++ -m64"
#   ./configure --disable-gui --disable-netgen --disable-fm --disable-kbipack\
#               --disable-occ --enable-graphics --disable-med --disable-chaco\
#               --disable-metis --prefix=$HOME/src/gmsh/utils/api_demos
#   make install-lib
# 

mainAntTweakBar: mainAntTweakBar.cpp
	g++ -m64 -o mainAntTweakBar -Iinclude mainAntTweakBar.cpp -Llib\
          -lGmsh -lAntTweakBar\
          -framework OpenGL -framework GLUT -framework Cocoa -framework ApplicationServices\
          -llapack -lblas -lz -lm

mainGlut: mainGlut.cpp
	g++ -m64 -o mainGlut -Iinclude mainGlut.cpp -Llib -lGmsh\
          -framework OpenGL -framework GLUT -framework Cocoa -framework ApplicationServices\
          -llapack -lblas -lz -lm

