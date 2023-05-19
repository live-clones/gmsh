# Written by Emanuele Rodola
# USI Lugano, Apr 2016
# -Wl,--out-implib,./$(LIBNAME).a

LIBNAME=geodesic
DEBUG=release
CXXFLAGS=-Wall -O2 -fPIC

all: release example0 example1

debug: CXXFLAGS += -DDEBUG -g
#debug: CCFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: matlab_api

release: matlab_api

matlab_api:
	g++ -c ./geodesic_matlab_api.cpp -o ./geodesic_matlab_api.o $(CXXFLAGS) 
	g++ -shared -o ./$(LIBNAME)_$(DEBUG).so ./geodesic_matlab_api.o

example0: 
	g++ ./example0.cpp -o ./example0.out

example1: 
	g++ ./example1.cpp -o ./example1.out

clean:
	rm -f ./geodesic_matlab_api.o ./$(LIBNAME)_release.so  ./$(LIBNAME)_debug.so ./$(LIBNAME).a
	rm -f ./*.out

