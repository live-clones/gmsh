all :
	python gen.py
	g++ -c gmshc.cc -shared -o libgmshc.so
	gcc main.c -L. -L../build -Wl,-rpath=../build -lstdc++ -lgmsh  -lgmshc -lgmsh -o main
