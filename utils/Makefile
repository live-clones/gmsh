# $Id: Makefile,v 1.12 2003-02-18 05:50:10 geuzaine Exp $

include ../variables

dxf2geo: dxf2geo.c message.c 
	${CXX} ${OPTIM} -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libGmshDataStr.a -lm

mysolver: mysolver.c
	${CXX} ${OPTIM} -o mysolver.exe mysolver.c GmshClient.c

mysolvertgz:
	gtar zcvf mysolver.tgz mysolver.c mysolver.opt GmshClient.c GmshClient.h

myperlsolvertgz:
	gtar zcvf myperlsolver.tgz myperlsolver.pl myperlsolver.opt GMSH_CLIENT.pm

clean:
	rm -f *.o

depend:
	true
