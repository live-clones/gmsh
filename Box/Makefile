# $Id: Makefile,v 1.5 2001-02-09 14:51:31 geuzaine Exp $
#
# Makefile for ".a"
#

.IGNORE:

CC       = c++
AR       = ar ruvs
RM       = rm
RANLIB   = ranlib
LIB      = ../lib/libBox.a
INCLUDE  = -I../Common -I../DataStr -I../Geo\
           -I../Graphics -I../Mesh -I../Parser -I../Motif -I../Fltk

C_FLAGS       = -g
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS  = -f
CFLAGS   = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) 

SRC = Box.cpp

OBJ = $(SRC:.cpp=.o)

.SUFFIXES: .o .cpp

$(LIB): $(OBJ) 
	$(AR) $(LIB) $(OBJ) 
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
