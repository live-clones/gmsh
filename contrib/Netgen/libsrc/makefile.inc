# Gmsh - This replaces the original makefile.inc provided by Netgen

include ../../../../variables

INC = ${DASH}I../../../../Common ${DASH}I../include ${DASH}I../interface

CFLAGS = ${OPTIM} ${FLAGS} ${INC} ${SYSINCLUDE}\
         ${DASH}DNO_PARALLEL_THREADS ${DASH}UWIN32

OBJ = ${src:.cpp=${OBJEXT}}

.SUFFIXES: ${OBJEXT} .cpp

default: ${OBJ} 

.cpp${OBJEXT}:
	${CXX} ${CFLAGS} ${DASH}c $<

