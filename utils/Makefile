# $Id: Makefile,v 1.4 2001-08-20 08:03:00 geuzaine Exp $

CC         = c++
OPT_FLAGS  = -g

RM       = rm
RMFLAGS  = -f

dxf2geo: dxf2geo.c message.c 
	$(CC) $(OPT_FLAGS) -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libDataStr.a -lm

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	true
