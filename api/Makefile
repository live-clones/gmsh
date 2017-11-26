# this is temporary - will be integrated in the main CMakeLists.txt

all :
	python gen.py

linux:
	g++ gmshc.cpp -shared -fPIC -L. -L../build -Wl,-rpath=../build -lstdc++ -lgmsh -o libgmshc.so
	gcc main.c -L. -Wl,-rpath=. -L../build -Wl,-rpath=../build  -lgmshc -lgmsh -lstdc++ -o main

mac:
	g++ gmshc.cpp -shared -fPIC -L../bin  -L. -lstdc++ -lgmsh -o libgmshc.so
	gcc main.c -L. -lgmshc -lgmsh -lstdc++ -o main
