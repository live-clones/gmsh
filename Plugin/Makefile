# $Id: Makefile,v 1.10 2001-07-30 15:40:04 geuzaine Exp $
#
# Makefile for "libAdapt.a"
#

.IGNORE:

CC        = c++
AR        = ar ruvs
RM        = rm
RANLIB    = ranlib

LIB       = ../lib/libPlugin.a
INCLUDE   = -I../Common -I../Graphics -I../DataStr

C_FLAGS       = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS   = -f
CFLAGS    = $(C_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) $(GUI_INCLUDE) 

SRC = Plugin.cpp CutPlane.cpp CutSphere.cpp LevelsetPlugin.cpp CutMap.cpp

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
Plugin.o: Plugin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
 PluginManager.h CutPlane.h LevelsetPlugin.h CutSphere.h CutMap.h
CutPlane.o: CutPlane.cpp CutPlane.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h
CutSphere.o: CutSphere.cpp CutSphere.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h
LevelsetPlugin.o: LevelsetPlugin.cpp LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
 ../Common/Views.h ../Common/Const.h ../Common/ColorTable.h \
 ../Graphics/Iso.h
CutMap.o: CutMap.cpp CutMap.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h
