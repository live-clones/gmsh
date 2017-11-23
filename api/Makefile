all :
	python gen.py
	g++  gmshc.cc -shared -fPIC -L. -L../build -Wl,-rpath=../build -lstdc++ -lgmsh -o libgmshc.so
	gcc main.c -L. -Wl,-rpath=. -L../build -Wl,-rpath=../build  -lgmshc -lgmsh -lstdc++ -o main
