# $Id: Makefile,v 1.166 2001-11-23 13:51:14 geuzaine Exp $

GMSH_MAJOR_VERSION = 1
GMSH_MINOR_VERSION = 31
GMSH_PATCH_VERSION = 0

MAKE = make
CXX = c++
CC = cc
FLAGS = -g -Wall
RM = rm
RMFLAGS = -f 
OPENGL_LIB = -lGLU -lGL
FLTK_LIB = -lfltk
X11_LIB = -lX11

# ----------------------------------------------------------------------
#  Gmsh definitions
# ----------------------------------------------------------------------

GMSH_COMMON_DIR = Adapt Common DataStr Geo Mesh Parallel Parser Plugin Triangle
GMSH_BOX_DIR =$(GMSH_COMMON_DIR) Box
GMSH_FLTK_DIR = $(GMSH_COMMON_DIR) Graphics Fltk jpeg
GMSH_DIR = $(GMSH_COMMON_DIR) Box Graphics Fltk jpeg utils
GMSH_BIN_DIR = bin
GMSH_LIB_DIR = lib
GMSH_DOC_DIR = doc
GMSH_DEMO_DIR = demos
GMSH_TUTORIAL_DIR = tutorial
GMSH_ARCHIVE_DIR = archives

GMSH_BOX_LIB = -L$(GMSH_LIB_DIR) -lBox -lParser -lMesh -lGeo -lAdapt\
               -lPlugin -lCommon -lDataStr -lParallel -lTriangle
GMSH_FLTK_LIB = -L$(GMSH_LIB_DIR) -lFltk -lParser -lGraphics -lMesh\
                -lGeo -lAdapt -lCommon -lDataStr -lJpeg -lPlugin -lParallel -lTriangle

GMSH_RELEASE = $(GMSH_MAJOR_VERSION).$(GMSH_MINOR_VERSION).$(GMSH_PATCH_VERSION)
GMSH_ARCHIVE = $(GMSH_ARCHIVE_DIR)/gmsh-`date "+%Y.%m.%d"`
GMSH_SRCRPM = gmsh-$(GMSH_RELEASE)
GMSH_UNAME = `uname`
GMSH_SOURCES = `find . \( ! -name "*.tar*" -a ! -name "*.tgz" \
                       -a ! -name "*.o"    -a ! -name "lib*.a"   \
                       -a ! -name "*.msh"  -a ! -name "*.bak" \
                       -a ! -name "gmsh"   -a ! -name "gmsh-*"\
                       -a ! -type d \)`

# ----------------------------------------------------------------------
# Rules for developers
# ----------------------------------------------------------------------

default: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done

gmsh:
	$(CXX) $(FLAGS) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lm

static:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-static/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_FLTK_LIB)\
                 $(HOME)/SOURCES/Mesa-static/lib/libGLU.a\
                 $(HOME)/SOURCES/Mesa-static/lib/libGL.a\
                 $(HOME)/SOURCES/fltk-static/lib/libfltk.a -lX11 -lm

purify:
	purify -cache-dir=/space g++ -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket

efence:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lefence -lm

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
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
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

src:
	tar cvf $(GMSH_SRCRPM).tar $(GMSH_SOURCES)
	gzip $(GMSH_SRCRPM).tar

distrib:
	mkdir gmsh-$(GMSH_RELEASE)
	cp $(GMSH_BIN_DIR)/gmsh gmsh-$(GMSH_RELEASE)
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

strip_bin:
	strip $(GMSH_BIN_DIR)/gmsh

dem:
	gtar zcvf gmsh-demos.tgz $(GMSH_DEMO_DIR)
	gtar zcvf gmsh-tutorial.tgz $(GMSH_TUTORIAL_DIR)

# ----------------------------------------------------------------------
# Black Box
# ----------------------------------------------------------------------

bb: tag
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-bb $(GMSH_BOX_LIB) -lm

bb-parallel: tag
	PARALLEL=1
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

bb-mingw: tag
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

# ----------------------------------------------------------------------
# Ready to compile for some platforms
# ----------------------------------------------------------------------

#
# Linux standard
#
compile_linux:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-g -O2 -Wall -Wno-uninitialized" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_linux:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lm -ldl
linux: tag compile_linux link_linux strip_bin

#
# Test for fltk 1.1
#
compile_fltk1:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-g -Wall" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk-1.1" \
        ); done
link_fltk1:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 $(HOME)/SOURCES/fltk-1.1/lib/libfltk_gl.a\
                 $(OPENGL_LIB) \
                 $(HOME)/SOURCES/fltk-1.1/lib/libfltk.a \
                 -L/usr/X11R6/lib $(X11_LIB) -lm
fltk1: compile_fltk1 link_fltk1

#
# Test for fltk 2.0
#
compile_fltk2:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-g -Wall" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk-2.0" \
        ); done
link_fltk2:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 $(HOME)/SOURCES/fltk-2.0/lib/libfltk_gl.so.2\
                 $(OPENGL_LIB) \
                 $(HOME)/SOURCES/fltk-2.0/lib/libfltk_forms.so.2 \
                 $(HOME)/SOURCES/fltk-2.0/lib/libfltk.so.2 \
                 -L/usr/X11R6/lib $(X11_LIB) -lm
fltk2: compile_fltk2 link_fltk2

#
# Linux, gcc-2.95.x (optimized build is very buggy)
# 
compile_linux_gcc-2.95:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(HOME)/gcc-2.95.3/bin/g++" \
           "CC=$(HOME)/gcc-2.95.3/bin/gcc" \
           "OPT_FLAGS=-g" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I/usr/X11R6/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_linux_gcc-2.95:
	$(HOME)/gcc-2.95.3/bin/g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lm -ldl
linux_gcc-2.95: tag compile_linux_gcc-2.95 link_linux_gcc-2.95 strip_bin
rpm: src
	mv $(GMSH_SRCRPM).tar.gz /usr/src/redhat/SOURCES
	rpm -bb --define 'gmshversion $(GMSH_RELEASE)' utils/gmsh.spec
	cp /usr/src/redhat/RPMS/i386/$(GMSH_SRCRPM)-?.i386.rpm .
	cp /usr/src/redhat/BUILD/$(GMSH_SRCRPM)/gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tgz .

#
# Linux SCOREC
#
compile_linux_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link_linux_scorec:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-linux $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/x86_linux/libfltk.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl 
linux_scorec : compile_linux_scorec link_linux_scorec strip_bin 

#
# Digital (Compaq) Tru64
#
compile_dec:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_dec:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) -lm
dec: tag compile_dec link_dec strip_bin

#
# HP-UX
#
compile_hp:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-3.1/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_hp:
	g++ -Wl,+s -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                      -L$(HOME)/SOURCES/Mesa-3.1/lib $(OPENGL_LIB)\
                      -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) -lm
hp: tag compile_hp link_hp strip_bin

#
# IBM Aix
#
compile_ibm:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=-D_BSD" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_ibm:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) -lm
ibm: tag compile_ibm link_ibm strip_bin

#
# SGI Irix
#
compile_sgi:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=CC" \
           "CC=cc" \
           "OPT_FLAGS=-O2 -OPT:Olimit=0 -LANG:std" \
           "RANLIB=true"\
           "AR=CC -mips3 -n32 -ar -o"\
           "OS_FLAGS=-mips3 -n32" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_sgi:
	CC -O2 -mips3 -n32 -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
               -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) $(OPENGL_LIB) -lm
sgi: tag compile_sgi link_sgi strip_bin

#
# Mingw
#
compile_mingw:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-DWIN32 -D_LITTLE_ENDIAN -mno-cygwin -I/mingw/include" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_mingw:
	g++ -mno-cygwin -L/mingw/lib -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB)\
                 Common/Icon.res $(HOME)/SOURCES/fltk/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm
mingw: tag compile_mingw link_mingw
	strip $(GMSH_BIN_DIR)/gmsh.exe

#
# Cygwin
#
compile_cygwin:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-DWIN32 -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK -I/usr/include/w32api" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_cygwin:
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB)\
                 Common/Icon.res $(HOME)/SOURCES/fltk/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm
cygwin: tag compile_cygwin link_cygwin
	strip $(GMSH_BIN_DIR)/gmsh.exe

#
# Cygwin with fltk 1.1
#
compile_cygwin1:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=g++" \
           "CC=gcc" \
           "OPT_FLAGS=-O2" \
           "OS_FLAGS=-DWIN32 -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK -I/usr/include/w32api" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk-1.1" \
        ); done
link_cygwin1:
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB)\
                 Common/Icon.res $(HOME)/SOURCES/fltk/lib/libfltk_gl.a\
                 -lglu32 -lopengl32\
                 $(HOME)/SOURCES/fltk/lib/libfltk.a\
                 -lgdi32 -lwsock32 -lm
cygwin1: tag compile_cygwin1 link_cygwin1
	strip $(GMSH_BIN_DIR)/gmsh.exe

#
# Cygwin gertha_buro
#
cygwin_gertha_buro: tag
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
                 Common/Icon.res ../fltk/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

#
# Cygwin laptop jf
#
cygwin_laptopjf: 
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
                 Common/Icon.res ../fltk-1.0.9/lib/libfltk.a\
                 -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm
cygwin_laptopjf_tag: tag cygwin_laptopjf

#
# Sun SunOS
#
compile_sun:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-3.1/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_sun:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(HOME)/SOURCES/Mesa-3.1/lib $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB)\
                 $(X11_LIB) -lXext -lsocket -lnsl -ldl -lm
sun: tag compile_sun link_sun strip_bin

#
# Solaris SCOREC
#
compile_solaris_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CXX=$(CXX)" \
           "CC=$(CC)" \
           "OPT_FLAGS=-O3" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link_solaris_scorec:
	$(CXX) -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket
solaris_scorec : compile_solaris_scorec link_solaris_scorec strip_bin 

