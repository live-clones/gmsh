# $Id: Makefile,v 1.9 2002-05-19 20:29:47 geuzaine Exp $

CXX       = c++
OPT_FLAGS = -g

RM      = rm
RMFLAGS = -f

dxf2geo: dxf2geo.c message.c 
	$(CXX) $(OPT_FLAGS) -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libGmshDataStr.a -lm

mysolver: mysolver.c
	$(CXX) $(OPT_FLAGS) -o mysolver.exe mysolver.c GmshClient.c

mysolvertgz:
	gtar zcvf mysolver.tgz mysolver.c mysolver.opt GmshClient.c GmshClient.h

myperlsolvertgz:
	gtar zcvf myperlsolver.tgz myperlsolver.pl myperlsolver.opt GMSH_CLIENT.pm

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	true
