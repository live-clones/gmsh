# $Id: Makefile,v 1.233 2002-10-16 17:33:03 geuzaine Exp $

GMSH_MAJOR_VERSION = 1
GMSH_MINOR_VERSION = 35
GMSH_PATCH_VERSION = 2

MAKE = make
CXX = c++
CC = cc
FLAGS = -g -Wall
RM = rm
RMFLAGS = -f 

FLTK_DIR = $(HOME)/SOURCES/fltk-1.1

# ----------------------------------------------------------------------
#  Gmsh definitions
# ----------------------------------------------------------------------

GMSH_COMMON_DIR = Common DataStr Geo Mesh Numeric Parallel Parser Plugin Triangle
GMSH_BOX_DIR =$(GMSH_COMMON_DIR) Box
GMSH_FLTK_DIR = $(GMSH_COMMON_DIR) Graphics Fltk jpeg
GMSH_DIR = $(GMSH_COMMON_DIR) Box Graphics Fltk jpeg utils
GMSH_BIN_DIR = bin
GMSH_LIB_DIR = lib
GMSH_DOC_DIR = doc
GMSH_DEMO_DIR = demos
GMSH_TUTORIAL_DIR = tutorial
GMSH_ARCHIVE_DIR = archives

GMSH_BOX_LIB = -L$(GMSH_LIB_DIR) -lGmshBox -lGmshParser -lGmshMesh -lGmshGeo -lGmshNumeric\
               -lGmshPlugin -lGmshCommon -lGmshDataStr -lGmshParallel -lGmshTriangle
GMSH_FLTK_LIB = -L$(GMSH_LIB_DIR) -lGmshFltk -lGmshParser -lGmshGraphics -lGmshMesh\
                -lGmshGeo -lGmshNumeric -lGmshCommon -lGmshDataStr -lGmshJpeg -lGmshPlugin\
                -lGmshParallel -lGmshTriangle

GMSH_RELEASE = $(GMSH_MAJOR_VERSION).$(GMSH_MINOR_VERSION).$(GMSH_PATCH_VERSION)
GMSH_ARCHIVE = $(GMSH_ARCHIVE_DIR)/gmsh-`date "+%Y.%m.%d"`
GMSH_UNAME = `uname`
GMSH_SOURCES = `find . \( ! -name "*.tar*" -a ! -name "*.tgz" \
                       -a ! -name "*.o"    -a ! -name "lib*.a"   \
                       -a ! -name "*.msh"  -a ! -name "*.bak" \
                       -a ! -name "gmsh"   -a ! -name "gmsh-*"\
                       -a ! -type d \)`

default:
	@echo "Type one of the following:"
	@echo "  make aix                  for IBM RS/6000 with AIX"
	@echo "  make cygwin               for Win95/NT using Cygnus-Win32"
	@echo "  make gcc                  for a generic system with GCC"
	@echo "  make hpux                 for HP systems with HPUX 9.x/10.x using GCC"
	@echo "  make irix                 for SGI systems with IRIX"
	@echo "  make linux                for Linux systems"
	@echo "  make macosx               for Macintosh with Mac OS X and GCC"
	@echo "  make osf1                 for DEC Alpha systems with OSF/1"
	@echo "  make sunos                for Suns with SunOS"
	@echo ""
	@echo "You need fltk (http://www.fltk.org) version 1.1.x installed"
	@echo "in $(FLTK_DIR) (or add \"FLTK_DIR=dir\""
	@echo "to the above commands, e.g., make linux \"FLTK_DIR=/opt/fltk\")"
	@echo ""
	@echo "If your system is not listed above, edit the Makefile"

# ----------------------------------------------------------------------
# Ready to compile for some platforms
# ----------------------------------------------------------------------

#
# Source distribution
#
source:
	tar zcvf gmsh.tgz `ls README* Makefile */Makefile */*.[chyl] */*.[ch]pp\
                           */*.rc */*.res */*.ico */*.pl */*.pm */*.opt */*.spec`\
                           doc demos tutorial
	mkdir gmsh-$(GMSH_RELEASE)
	cd gmsh-$(GMSH_RELEASE) && tar zxvf ../gmsh.tgz
	rm -f gmsh.tgz
	cd gmsh-$(GMSH_RELEASE) && rm -rf CVS */CVS */*/CVS */.globalrc
#	cd gmsh-$(GMSH_RELEASE) && zip -r gmsh-$(GMSH_RELEASE)-source.zip *
#	mv gmsh-$(GMSH_RELEASE)/gmsh-$(GMSH_RELEASE)-source.zip .
	tar zcvf gmsh-$(GMSH_RELEASE)-source.tgz gmsh-$(GMSH_RELEASE)
	rm -rf gmsh-$(GMSH_RELEASE)

#
# Generic little endian machine (e.g. with gcc)
#
compile: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link:
	$(CXX) $(FLAGS) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
               -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
               -L/usr/X11R6/lib -lX11 -lm
gcc: compile link

#
# Linux
#
compile-linux: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3 -Wall -Wno-uninitialized" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-linux:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
                 -L/usr/X11R6/lib -lX11 -lm -ldl
linux: compile-linux link-linux

#
# Linux fltk 2.0 (beta)
#
compile-fltk2: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-g -Wall" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk-2.0" \
        ); done
link-fltk2:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 $(HOME)/SOURCES/fltk-2.0/lib/libfltk_gl.so.2\
                 -lGLU -lGL \
                 $(HOME)/SOURCES/fltk-2.0/lib/libfltk.so.2 \
                 -L/usr/X11R6/lib -lX11 -lm
fltk2: compile-fltk2 link-fltk2

#
# Linux fltk 1.0 (obsolete)
#
compile-fltk1: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-g -Wall" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link-fltk1:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                -L$(HOME)/SOURCES/fltk/lib -lfltk -lGLU -lGL \
                -L/usr/X11R6/lib -lX11 -lm
fltk1: compile-fltk1 link-fltk1

#
# Linux, gcc-2.95.x (optimized build is very buggy)
# 
compile-linux-gcc-2.95: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(HOME)/gcc-2.95.3/bin/g++" \
           "CC=$(HOME)/gcc-2.95.3/bin/gcc" \
           "OPT_FLAGS=-g" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I/usr/X11R6/include" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-linux-gcc-2.95:
	$(HOME)/gcc-2.95.3/bin/g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
                 -L/usr/X11R6/lib -lX11 -lm -ldl
linux-gcc-2.95: compile-linux-gcc-2.95 link-linux-gcc-2.95
distrib-linux-gcc-2.95:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(HOME)/gcc-2.95.3/bin/g++" \
           "CC=$(HOME)/gcc-2.95.3/bin/gcc" \
           "OPT_FLAGS=-g" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(HOME)/gcc-2.95.3/bin/g++ -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm -ldl
	make clean
	make linux-gcc-2.95
	make distrib
rpm:
	tar zcvf gmsh-$(GMSH_RELEASE).tar.gz $(GMSH_SOURCES)
	mv gmsh-$(GMSH_RELEASE).tar.gz /usr/src/redhat/SOURCES
	rpm -bb --define 'gmshversion $(GMSH_RELEASE)' utils/gmsh.spec
	cp /usr/src/redhat/RPMS/i386/gmsh-$(GMSH_RELEASE)-?.i386.rpm .
	cp /usr/src/redhat/BUILD/gmsh-$(GMSH_RELEASE)/gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tgz .

#
# Linux SCOREC
#
compile-linux-scorec: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link-linux-scorec:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-linux $(GMSH_FLTK_LIB) -lGLU -lGL \
                 /users/develop/develop/visual/fltk/1.0/lib/x86_linux/libfltk.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl 
linux-scorec: compile-linux-scorec link-linux-scorec

#
# Digital (Compaq) OSF1/Digital Unix/Tru64
#
compile-osf1: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-osf1:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
                 -lX11 -lm
osf1: compile-osf1 link-osf1
distrib-osf1:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm
	make clean
	make osf1
	make distrib
#
# HP-UX
#
compile-hpux: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-3.1/include" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-hpux:
	g++ -Wl,+s -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                      -L$(FLTK_DIR)/lib -lfltk_gl\
                      -L$(HOME)/SOURCES/Mesa-3.1/lib -lGLU -lGL -lfltk\
                      -lX11 -lm
hpux: compile-hpux link-hpux
distrib-hpux:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	g++ -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm
	make clean
	make hpux
	make distrib
#
# IBM AIX
#
compile-aix: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-D_BSD" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-aix:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
                  -lX11 -lm
aix: compile-aix link-aix
distrib-aix:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-D_BSD" \
           "VERSION_FLAGS=-D_BLACKBOX -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm
	make clean
	make aix
	make distrib
#
# SGI Irix
#
compile-irix: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=CC" \
           "CC=cc" \
           "OPT_FLAGS=-O2 -OPT:Olimit=0 -LANG:std" \
           "RANLIB=true"\
           "AR=CC -mips3 -n32 -ar -o"\
           "OS_FLAGS=-mips3 -n32" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-irix:
	CC -O2 -mips3 -n32 -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
               -L$(FLTK_DIR)/lib -lfltk_gl -lfltk -lX11 -lGLU -lGL -lm
irix: compile-irix link-irix
distrib-irix:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=CC" \
           "CC=cc" \
           "OPT_FLAGS=-O2 -OPT:Olimit=0 -LANG:std" \
           "RANLIB=true"\
           "AR=CC -mips3 -n32 -ar -o"\
           "OS_FLAGS=-mips3 -n32" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	CC -O2 -mips3 -n32 -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm
	make clean
	make irix
	make distrib

#
# Cygwin
#
compile-cygwin: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-mwindows -DWIN32 -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK -I/usr/include/w32api" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-cygwin:
	g++ -Wl,--subsystem,windows -mwindows -o $(GMSH_BIN_DIR)/gmsh.exe\
                 $(GMSH_FLTK_LIB) Fltk/Icon.res $(FLTK_DIR)/lib/libfltk_gl.a\
                 -lglu32 -lopengl32 $(FLTK_DIR)/lib/libfltk.a \
                 -lole32 -luuid -lcomctl32 -lwsock32 -lm
cygwin: compile-cygwin link-cygwin
distrib-cygwin:
	make tag
	make clean
	make cygwin
	make distrib-win

#
# Cygwin gertha-buro
#
cygwin-gertha-buro: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-DWIN32 -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I../../fltk" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB)\
                 Fltk/Icon.res ../fltk/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

#
# Cygwin laptop jf
#
cygwin-laptopjf: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-DWIN32 -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I../../fltk-1.0.9" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh-cyg.exe $(GMSH_FLTK_LIB)\
                 Fltk/Icon.res ../fltk-1.0.9/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm
cygwin-laptopjf_tag: tag cygwin-laptopjf

#
# Sun SunOS
#
compile-sunos: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-3.1/include" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-sunos:
	g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl\
                 -L$(HOME)/SOURCES/Mesa-3.1/lib -lGLU -lGL -lfltk\
                 -lX11 -lXext -lsocket -lnsl -ldl -lm
sunos: compile-sunos link-sunos
distrib-sunos:
	make tag
	make clean
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	g++ -o $(GMSH_BIN_DIR)/gmsh-batch $(GMSH_BOX_LIB) -lm
	make clean
	make sunos
	make distrib
#
# Solaris SCOREC
#
compile-solaris-scorec: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link-solaris-scorec:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) -lGLU -lGL \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket
solaris-scorec: compile-solaris-scorec link-solaris-scorec

#
# MacOS X
#
compile-macosx: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "AR=ar ruv" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
link-macosx:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) -L$(FLTK_DIR)/lib -lfltk_gl -lfltk \
               -framework AGL -framework OpenGL -framework Carbon -framework ApplicationServices
	/Developer/Tools/Rez -t APPL -o $(GMSH_BIN_DIR)/gmsh $(FLTK_DIR)/FL/mac.r
macosx: compile-macosx link-macosx

# ----------------------------------------------------------------------
# Rules for developers
# ----------------------------------------------------------------------

gmsh: link

static:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-static/include" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_FLTK_LIB)\
                 $(FLTK_DIR)/lib/libfltk_gl.a\
                 $(HOME)/SOURCES/Mesa-static/lib/libGLU.a\
                 $(HOME)/SOURCES/Mesa-static/lib/libGL.a\
                 $(FLTK_DIR)/lib/libfltk.a -lX11 -lm

purify:
	purify -cache-dir=/space g++ -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) -lGLU -lGL \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket

efence:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(FLTK_DIR)/lib -lfltk_gl -lGLU -lGL -lfltk\
                 -L/usr/X11R6/lib -lX11 -lefence -lm

# ----------------------------------------------------------------------
# Utilities
# ----------------------------------------------------------------------

parser:
	cd Parser && $(MAKE) parser

utilities:
	cd utils && $(MAKE)

purge:
	for i in "." $(GMSH_DIR) $(GMSH_LIB_DIR) $(GMSH_ARCHIVE_DIR)\
                     $(GMSH_DEMO_DIR) $(GMSH_TUTORIAL_DIR) $(GMSH_DOC_DIR); \
        do (cd $$i && $(RM) $(RMFLAGS) *~ *~~ .gmsh-tmp .gmsh-errors gmon.out); \
        done

clean:
	for i in $(GMSH_DIR) $(GMSH_DOC_DIR) $(GMSH_LIB_DIR) ; \
        do (cd $$i && $(MAKE) clean); \
        done

depend:
	for i in $(GMSH_DIR); \
        do (cd $$i && $(MAKE) depend \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(FLTK_DIR)" \
        ); done

nodepend:
	for i in $(GMSH_DIR) ; do \
          (cd $$i && (sed '/^# DO NOT DELETE THIS LINE/q' Makefile) > Makefile.new \
          && cp Makefile Makefile.bak \
          && cp Makefile.new Makefile \
          && $(RM) $(RMFLAGS) Makefile.new); \
        done 

tag:
	$(RM) $(RMFLAGS) Common/GmshVersion.h
	echo "#define GMSH_MAJOR_VERSION $(GMSH_MAJOR_VERSION)" >  Common/GmshVersion.h
	echo "#define GMSH_MINOR_VERSION $(GMSH_MINOR_VERSION)" >> Common/GmshVersion.h
	echo "#define GMSH_PATCH_VERSION $(GMSH_PATCH_VERSION)" >> Common/GmshVersion.h
	echo "#define GMSH_VERSION  ((double)GMSH_MAJOR_VERSION + \\" >> Common/GmshVersion.h
	echo "                0.01 * (double)GMSH_MINOR_VERSION + \\" >> Common/GmshVersion.h
	echo "              0.0001 * (double)GMSH_PATCH_VERSION)"     >> Common/GmshVersion.h
	echo "#define GMSH_DATE     \"`date`\""      >> Common/GmshVersion.h
	echo "#define GMSH_HOST     \"`hostname`\""  >> Common/GmshVersion.h
	echo "#define GMSH_PACKAGER \"`whoami`\""    >> Common/GmshVersion.h
	echo "#define GMSH_OS       \"`uname -sr`\"" >> Common/GmshVersion.h

initialtag:
	@if [ ! -r Common/GmshVersion.h ]; then \
          $(MAKE) tag ; \
        fi

tags:
	gtags
	htags

tgz:
	if (test -f $(GMSH_ARCHIVE).tar.gz); then \
	  mv -f $(GMSH_ARCHIVE).tar.gz $(GMSH_ARCHIVE).tar.gz~; \
	fi
	tar cvf $(GMSH_ARCHIVE).tar $(GMSH_SOURCES)
	gzip $(GMSH_ARCHIVE).tar
	chmod 640 $(GMSH_ARCHIVE).tar.gz

minizip:
	tar jcvf gmsh-`date "+%Y.%m.%d"`.tar.bz2 \
        `ls Makefile */Makefile */*.[chyl] */*.[ch]pp */*.rc */*.res */*.ico`

# Add doc/COPYING as soon as we are GPL'ed

distrib:
	mkdir gmsh-$(GMSH_RELEASE)
	strip $(GMSH_BIN_DIR)/gmsh
	cp $(GMSH_BIN_DIR)/gmsh gmsh-$(GMSH_RELEASE)
	strip $(GMSH_BIN_DIR)/gmsh-batch
	cp $(GMSH_BIN_DIR)/gmsh-batch gmsh-$(GMSH_RELEASE)
	cp doc/gmsh.1 doc/FORMATS doc/VERSIONS doc/FAQ doc/CONTRIBUTORS gmsh-$(GMSH_RELEASE)
	cp -R tutorial gmsh-$(GMSH_RELEASE)
	cp -R demos gmsh-$(GMSH_RELEASE)
	rm -rf gmsh-$(GMSH_RELEASE)/*/CVS
	rm -f gmsh-$(GMSH_RELEASE)/*/*.msh
	rm -f gmsh-$(GMSH_RELEASE)/*/*~
	tar cvf gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tar gmsh-$(GMSH_RELEASE)
	gzip gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tar
	mv gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tar.gz gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tgz
	rm -rf gmsh-$(GMSH_RELEASE)

distrib-win:
	strip $(GMSH_BIN_DIR)/gmsh.exe
	cp $(GMSH_BIN_DIR)/gmsh.exe ../gmsh-distrib
	cp doc/README.txt ../gmsh-distrib
	cp doc/FORMATS ../gmsh-distrib/FORMATS.txt
	cp doc/VERSIONS ../gmsh-distrib/VERSIONS.txt
	cp doc/FAQ ../gmsh-distrib/FAQ.txt
	cp doc/CONTRIBUTORS ../gmsh-distrib/CONTRIBUTORS.txt
	cd utils && unix2dos ../../gmsh-distrib/*.txt
	cp -R tutorial ../gmsh-distrib
	cp -R demos ../gmsh-distrib
	rm -rf ../gmsh-distrib/*/CVS
	rm -f ../gmsh-distrib/*/*.msh
	rm -f ../gmsh-distrib/*/*~
	cd utils && unix2dos ../../gmsh-distrib/tutorial/* ../../gmsh-distrib/demos/*
	cd ../gmsh-distrib && zip -r gmsh-$(GMSH_RELEASE)-Windows.zip *
	mv ../gmsh-distrib/gmsh-$(GMSH_RELEASE)-Windows.zip .
	rm -rf ../gmsh-distrib/*.txt
	rm -rf ../gmsh-distrib/tutorial
	rm -rf ../gmsh-distrib/demos

dem:
	gtar zcvf gmsh-demos.tgz $(GMSH_DEMO_DIR)
	gtar zcvf gmsh-tutorial.tgz $(GMSH_TUTORIAL_DIR)

# ----------------------------------------------------------------------
# Black Box
# ----------------------------------------------------------------------

bb: initialtag
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=$(FLAGS)" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-bb $(GMSH_BOX_LIB) -lm

bb-parallel: initialtag
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=mpiCC" \
           "CC=mpicc" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX -DPARALLEL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	mpiCC -o $(GMSH_BIN_DIR)/gmsh-bb $(GMSH_BOX_LIB) -lm

bb-mingw: initialtag
	@for i in $(GMSH_BOX_DIR) ; do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=-mno-cygwin -I/mingw/include" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	g++ -o $(GMSH_BIN_DIR)/gmsh.exe -mno-cygwin -L/mingw/lib $(GMSH_BOX_LIB) -lm
