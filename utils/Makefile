# $Id: Makefile,v 1.3 2001-02-03 13:10:26 geuzaine Exp $

CC       = c++
C_FLAGS  = -g

RM       = rm
RMFLAGS  = -f

dxf2geo: dxf2geo.c message.c 
	$(CC) $(C_FLAGS) -o ../bin/dxf2geo -I../DataStr\
              dxf2geo.c message.c ../lib/libDataStr.a -lm

clean:
	$(RM) $(RMFLAGS) *.o

depend:
	true
