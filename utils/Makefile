# $Id: Makefile,v 1.11 2003-02-11 22:50:41 geuzaine Exp $

include ../variables

dxf2geo: dxf2geo.c message.c 
	${CXX} ${OPT_FLAGS} -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libGmshDataStr.a -lm

mysolver: mysolver.c
	${CXX} ${OPT_FLAGS} -o mysolver.exe mysolver.c GmshClient.c

mysolvertgz:
	gtar zcvf mysolver.tgz mysolver.c mysolver.opt GmshClient.c GmshClient.h

myperlsolvertgz:
	gtar zcvf myperlsolver.tgz myperlsolver.pl myperlsolver.opt GMSH_CLIENT.pm

clean:
	rm -f *.o

depend:
	true
