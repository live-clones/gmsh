# $Id: Makefile,v 1.6 2002-01-03 10:25:06 geuzaine Exp $

CXX        = c++
OPT_FLAGS  = -g

RM       = rm
RMFLAGS  = -f

dxf2geo: dxf2geo.c message.c 
	$(CXX) $(OPT_FLAGS) -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libDataStr.a -lm

mysolver: mysolver.c
	$(CXX) $(OPT_FLAGS) -o mysolver.exe mysolver.c GmshClient.c

mysolvertgz:
	gtar zcvf mysolver.tgz mysolver.c mysolver.opt GmshClient.c GmshClient.h

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	true
