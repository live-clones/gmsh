# $Id: Makefile,v 1.5 2001-08-20 08:25:24 geuzaine Exp $

CXX        = c++
OPT_FLAGS  = -g

RM       = rm
RMFLAGS  = -f

dxf2geo: dxf2geo.c message.c 
	$(CXX) $(OPT_FLAGS) -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libDataStr.a -lm

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	true
