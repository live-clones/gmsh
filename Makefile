# $Id: Makefile,v 1.130 2001-08-14 16:10:47 geuzaine Exp $

GMSH_RELEASE = 1.23
MAKE = make
CC = c++
FLAGS = -g -Wall
RM = rm
RMFLAGS = -f 
OPENGL_LIB = -lGLU -lGL
FLTK_LIB = -lfltk
X11_LIB = -lX11

# ----------------------------------------------------------------------
#  Gmsh definitions
# ----------------------------------------------------------------------

GMSH_DIR = Adapt Common DataStr Geo Graphics Mesh Parser Motif Fltk\
           Plugin jpeg utils Parallel
GMSH_FLTK_DIR = Adapt Common DataStr Geo Graphics Mesh Parser Fltk\
                jpeg Plugin Parallel
GMSH_BOX_DIR = Adapt Box Common DataStr Geo Mesh Parser Plugin Parallel
GMSH_BIN_DIR = bin
GMSH_LIB_DIR = lib
GMSH_DOC_DIR = doc
GMSH_DEMO_DIR = demos
GMSH_TUTOR_DIR = tutorial
GMSH_ARCHIVE_DIR = archives
GMSH_FLTK_LIB = -L$(GMSH_LIB_DIR) -lFltk -lParser -lGraphics -lMesh\
                -lGeo -lAdapt -lCommon -lDataStr -lJpeg -lPlugin -lParallel
GMSH_BOX_LIB = -L$(GMSH_LIB_DIR) -lBox -lParser -lMesh -lGeo -lAdapt\
               -lPlugin -lCommon -lDataStr -lParallel
GMSH_ARCHIVE = $(GMSH_ARCHIVE_DIR)/gmsh-`date "+%Y.%m.%d"`
GMSH_SRCRPM = gmsh-$(GMSH_RELEASE)
GMSH_SOURCES = `find . \( ! -name "*.tar*" -a ! -name "*.tgz" \
                       -a ! -name "*.o"    -a ! -name "lib*.a"   \
                       -a ! -name "*.msh"  -a ! -name "*.bak" \
                       -a ! -name "gmsh"   -a ! -name "gmsh-*"\
                       -a ! -type d \)`
GMSH_UNAME = `uname`

# ----------------------------------------------------------------------
# Rules for developers
# ----------------------------------------------------------------------

default: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done

static:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-static/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
	$(CC) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_FLTK_LIB)\
                 $(HOME)/SOURCES/Mesa-static/lib/libGLU.a\
                 $(HOME)/SOURCES/Mesa-static/lib/libGL.a\
                 $(HOME)/SOURCES/fltk-static/lib/libfltk.a -lX11 -lm

win: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-g -Wall -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB) \
            $(HOME)/SOURCES/fltk/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

purify:
	purify -cache-dir=/space g++ -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket

gmsh:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lm

efence:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lefence -lm

gmsh2:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -lfltk_gl -L/usr/X11R6/lib $(X11_LIB) -lpthread -lm

# ----------------------------------------------------------------------
# Utilities
# ----------------------------------------------------------------------

parser:
	cd Parser && $(MAKE) parser

utilities:
	cd utils && $(MAKE)

purge:
	for i in "." $(GMSH_DIR) $(GMSH_LIB_DIR) $(GMSH_ARCHIVE_DIR)\
                     $(GMSH_DEMO_DIR) $(GMSH_TUTOR_DIR) $(GMSH_DOC_DIR) $(GMSH_BOX_DIR); \
        do (cd $$i && $(RM) $(RMFLAGS) *~ *~~ .gmsh-tmp .gmsh-errors gmon.out); \
        done

clean:
	for i in $(GMSH_DIR) $(GMSH_DOC_DIR) $(GMSH_LIB_DIR) ; \
        do (cd $$i && $(MAKE) clean); \
        done

depend:
	for i in $(GMSH_DIR); \
        do (cd $$i && $(MAKE) depend \
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
	echo "#define GMSH_VERSION  $(GMSH_RELEASE)" >  Common/GmshVersion.h
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
	if (test -f $(GMSH_ARCHIVE).tar.gz); \
	then mv -f $(GMSH_ARCHIVE).tar.gz $(GMSH_ARCHIVE).tar.gz~; \
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
	cp -R tutorial ../gmsh-distrib
	cp -R demos ../gmsh-distrib
	rm -f ../gmsh-distrib/tutorial/README
	rm -rf ../gmsh-distrib/*/CVS
	rm -f ../gmsh-distrib/*/*.msh
	rm -f ../gmsh-distrib/*/*~
	cd ../gmsh-distrib && zip -r gmsh-$(GMSH_RELEASE)-Windows.zip *
	mv ../gmsh-distrib/gmsh-$(GMSH_RELEASE)-Windows.zip .
	rm -rf ../gmsh-distrib/tutorial
	rm -rf ../gmsh-distrib/demos

strip_bin:
	strip $(GMSH_BIN_DIR)/gmsh

dem:
	gtar zcvf gmsh-demos.tgz $(GMSH_DEMO_DIR)
	gtar zcvf gmsh-tutorial.tgz $(GMSH_TUTOR_DIR)

# ----------------------------------------------------------------------
# Black Box
# ----------------------------------------------------------------------

bb: tag
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-bb $(GMSH_BOX_LIB) -lm

bb-parallel: tag
	PARALLEL=1
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CC=mpiCC" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_BLACKBOX -DPARALLEL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=" \
        ); done
	mpiCC -o $(GMSH_BIN_DIR)/gmsh-bb $(GMSH_BOX_LIB) -lm

bb-mingw: tag
	@for i in $(GMSH_BOX_DIR) ; do (cd $$i && $(MAKE) \
           "CC=g++ -mno-cygwin -I/mingw/include" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
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
           "CC=$(CC)" \
           "C_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_linux:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) -L/usr/X11R6/lib $(X11_LIB) -lm -ldl
linux: tag compile_linux link_linux strip_bin

#
# Linux, gcc-2.95.x
# 
compile_linux_gcc-2.95:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(HOME)/gcc-2.95.3/bin/g++" \
           "C_FLAGS=-O2" \
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
	rpm -bb utils/gmsh_fltk.spec
	cp /usr/src/redhat/RPMS/i386/$(GMSH_SRCRPM)-1.i386.rpm .
	cp /usr/src/redhat/BUILD/$(GMSH_SRCRPM)/gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tgz .

#
# Linux SCOREC
#
compile_linux_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O2" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link_linux_scorec:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-linux $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/x86_linux/libfltk.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl 
linux_scorec : compile_linux_scorec link_linux_scorec strip_bin 

#
# Digital (Compaq) Tru64
#
compile_dec:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_dec:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) -lm
dec: tag compile_dec link_dec strip_bin

#
# HP-UX
#
compile_hp:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
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
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_BSD" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_ibm:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB) $(X11_LIB) -lm
ibm: tag compile_ibm link_ibm strip_bin

#
# SGI Irix
#
compile_sgi:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O2 -mips3 -n32 -OPT:Olimit=0 -LANG:std" \
           "RANLIB=true"\
           "AR=CC -mips3 -n32 -ar -o"\
           "OS_FLAGS=" \
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
           "CC=g++ -mno-cygwin -I/mingw/include" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
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
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
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
# Cygwin gertha_buro
#
cygwin_gertha_buro: tag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
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
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
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
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-3.1/include" \
           "GUI_INCLUDE=-I$(HOME)/SOURCES/fltk" \
        ); done
link_sun:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                 -L$(HOME)/SOURCES/Mesa-3.1/lib $(OPENGL_LIB) \
                 -L$(HOME)/SOURCES/fltk/lib $(FLTK_LIB)\
                 $(X11_LIB) -lXext -lsocket -lnsl -ldl -lm
sun: tag compile_sun link_sun strip_bin

#
# Solaris SCOREC
#
compile_solaris_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=" \
           "GL_INCLUDE=" \
           "GUI_INCLUDE=-I/users/develop/develop/visual/fltk/1.0/include" \
        ); done
link_solaris_scorec:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                 -L/usr/X11R6/lib -lX11 -lm -ldl -lsocket
solaris_scorec : compile_solaris_scorec link_solaris_scorec strip_bin 






