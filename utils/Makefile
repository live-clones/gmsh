# $Id: Makefile,v 1.2 2000-11-25 15:26:12 geuzaine Exp $
# $Id: Makefile,v 1.2 2000-11-25 15:26:12 geuzaine Exp $

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
