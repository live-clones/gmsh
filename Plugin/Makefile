# $Id: Makefile,v 1.17 2001-08-20 08:03:00 geuzaine Exp $
#
# Makefile for "libAdapt.a"
#

.IGNORE:

CC        = c++
AR        = ar ruvs
RM        = rm
RANLIB    = ranlib

LIB       = ../lib/libPlugin.a
INCLUDE   = -I../Common -I../Graphics -I../DataStr -I../Mesh

OPT_FLAGS     = -g -Wall
OS_FLAGS      = 
VERSION_FLAGS = 

RMFLAGS   = -f
CFLAGS    = $(OPT_FLAGS) $(OS_FLAGS) $(VERSION_FLAGS) $(INCLUDE) $(GUI_INCLUDE) 

SRC = Plugin.cpp\
        LevelsetPlugin.cpp\
          CutPlane.cpp CutSphere.cpp CutMap.cpp\
        Smooth.cpp\
        Transform.cpp\
        Skin.cpp

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
 PluginManager.h CutMap.h LevelsetPlugin.h CutPlane.h CutSphere.h \
 Skin.h Smooth.h Transform.h
LevelsetPlugin.o: LevelsetPlugin.cpp LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Iso.h \
 ../Common/Numeric.h
CutPlane.o: CutPlane.cpp CutPlane.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h
CutSphere.o: CutSphere.cpp CutSphere.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h
CutMap.o: CutMap.cpp CutMap.h LevelsetPlugin.h Plugin.h \
 ../Common/Options.h ../Common/Message.h ../DataStr/List.h
Smooth.o: Smooth.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
 Smooth.h ../DataStr/List.h ../Common/Views.h ../Common/ColorTable.h
Transform.o: Transform.cpp Plugin.h ../Common/Options.h \
 ../Common/Message.h Transform.h ../DataStr/List.h ../Common/Views.h \
 ../Common/ColorTable.h
Skin.o: Skin.cpp Plugin.h ../Common/Options.h ../Common/Message.h \
 Skin.h ../DataStr/List.h ../DataStr/Tree.h ../DataStr/avl.h \
 ../Common/Views.h ../Common/ColorTable.h ../Common/Context.h \
 ../DataStr/Malloc.h
