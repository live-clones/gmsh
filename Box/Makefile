# $Id: Makefile,v 1.2 2000-11-25 15:26:10 geuzaine Exp $
#
# Makefile for ".a"
#

.IGNORE:

CC            = c++
C_FLAGS       = -g

VERSION_FLAGS = 
OS_FLAGS      = -D_UNIX 

RM       = rm
RMFLAGS  = -f
RANLIB   = ranlib

LIB      = ../lib/libBox.a
INCLUDE  = -I../Common -I../DataStr -I../Geo\
           -I../Graphics -I../Mesh -I../Parser -I../Unix

CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Box.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	ar ruvs $(LIB) $(OBJ) 
	$(RANLIB) $(LIB)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(RMFLAGS) *.o

lint:
	$(LINT) $(CFLAGS) $(SRC)

depend:
	(sed '/^# DO NOT DELETE THIS LINE/q' Makefile && \
	$(CC) -MM $(CFLAGS) ${SRC} \
	) >Makefile.new
	cp Makefile Makefile.bak
	cp Makefile.new Makefile
	$(RM) $(RMFLAGS) Makefile.new

# DO NOT DELETE THIS LINE
box.o: box.cpp ../includes/msh_Include.h ../GmshDataStr/listman.h \
 ../GmshDataStr/treeman.h ../GmshDataStr/avl.h ../GmshDataStr/ualloc.h \
 ../GmshDataStr/outil.h ../base/base.h ../geo/geo.h \
 ../GmshUnix/message.h ../includes/msh_Const.h ../mesh/structure.h \
 ../includes/msh_Tree.h ../includes/msh_Proto.h \
 ../includes/msh_Version.h ../geo/context.h ../GmshGL/Draw_Post.h \
 ../GmshGL/colortable.h
