# this is temporary - will be integrated in the main CMakeLists.txt

all :
	python gen.py

linux:
	g++ gmshc.cpp -shared -fPIC -L. -L../build -Wl,-rpath=../build -lstdc++ -lgmsh -o libgmshc.so
	gcc test.c -L. -Wl,-rpath=. -L../build -Wl,-rpath=../build  -lgmshc -lgmsh -lstdc++ -o test

mac:
	g++ gmshc.cpp -shared -fPIC -L../bin  -L. -lstdc++ -lgmsh -o libgmshc.so
	gcc test.c -L. -lgmshc -lgmsh -lstdc++ -o test
