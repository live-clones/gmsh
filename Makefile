# $Id: Makefile,v 1.127 2001-08-13 14:51:12 geuzaine Exp $
# ----------------------------------------------------------------------
#  Makefile for Gmsh  
# ----------------------------------------------------------------------

           GMSH_RELEASE = 1.23

                   MAKE = make
                     CC = c++
                  FLAGS = -g -Wall
                     RM = rm
                RMFLAGS = -f 

# ----------------------------------------------------------------------
#  Includes
# ----------------------------------------------------------------------

             OPENGL_INC = -I/usr/X11R6/include\
                          -I/usr/include/X11/GLw\
                          -I$(HOME)/SOURCES/Mesa-3.1/include\
                          -I$(HOME)/SOURCES/Mesa-3.1/include/GL
              MOTIF_INC = -I/usr/X11R6/LessTif/Motif1.2/include
               FLTK_INC = -I$(HOME)/SOURCES/fltk
        FLTK_INC_SCOREC = -I/users/develop/develop/visual/fltk/1.0/include
      FLTK_INC_LAPTOPJF = -I../../fltk-1.0.9
   FLTK_INC_GERTHA_BURO = -I../../fltk

# ----------------------------------------------------------------------
#  3rd party libraries
# ----------------------------------------------------------------------

             OPENGL_LIB = -lGLU -lGL
       OPENGL_MOTIF_LIB = -lGLw
               MESA_LIB = -L$(HOME)/SOURCES/Mesa-3.1/lib -lGLU -lGL
         MESA_MOTIF_LIB = -L$(HOME)/SOURCES/Mesa-3.1/lib -lGLw
        MESA_STATIC_LIB = $(HOME)/SOURCES/Mesa-static/lib/libGLU.a\
                          $(HOME)/SOURCES/Mesa-static/lib/libGL.a
  MESA_MOTIF_STATIC_LIB = $(HOME)/SOURCES/Mesa-static/lib/libGLw.a
#            XMOTIF_LIB = /usr/local/lib/libXm.so.2 -L/usr/X11R6/lib -lXt -lX11 -lXext
             XMOTIF_LIB = -L/usr/local/lib -L/usr/X11R6/LessTif/Motif1.2/lib -lXm\
                          -L/usr/X11R6/lib -lXt -lX11 -lXext 
               FLTK_LIB = -L$(HOME)/SOURCES/fltk/lib -lfltk -L/usr/X11R6/lib -lX11
        FLTK_STATIC_LIB = -L$(HOME)/SOURCES/fltk-static/lib -lfltk -L/usr/X11R6/lib -lX11
FLTK_LIB_SOLARIS_SCOREC = /users/develop/develop/visual/fltk/1.0/lib/sun4_5/libfltk-gcc.a\
                          -L/usr/X11R6/lib -lX11
  FLTK_LIB_LINUX_SCOREC = /users/develop/develop/visual/fltk/1.0/lib/x86_linux/libfltk.a\
                          -L/usr/X11R6/lib -lX11

             THREAD_LIB = -L/usr/lib -lpthread

# ----------------------------------------------------------------------
#  Gmsh definitions
# ----------------------------------------------------------------------

               GMSH_DIR = Adapt Common DataStr Geo Graphics Mesh Parser\
                          Motif Fltk Plugin jpeg utils Parallel
        GMSH_XMOTIF_DIR = Adapt Common DataStr Geo Graphics Mesh Parser Motif jpeg Parallel
          GMSH_FLTK_DIR = Adapt Common DataStr Geo Graphics Mesh Parser Fltk jpeg Plugin Parallel
           GMSH_BOX_DIR = Adapt Box Common DataStr Geo Mesh Parser Plugin Parallel
           GMSH_BIN_DIR = bin
           GMSH_LIB_DIR = lib
           GMSH_DOC_DIR = doc
          GMSH_DEMO_DIR = demos
         GMSH_TUTOR_DIR = tutorial
       GMSH_ARCHIVE_DIR = archives


        GMSH_XMOTIF_LIB = -L$(GMSH_LIB_DIR) -lMotif -lGraphics -lParser -lMesh -lGeo\
                                            -lAdapt -lCommon -lDataStr -lJpeg -lParallel
          GMSH_FLTK_LIB = -L$(GMSH_LIB_DIR) -lFltk -lParser -lGraphics -lMesh -lGeo\
                                            -lAdapt -lCommon -lDataStr -lJpeg -lPlugin -lParallel
           GMSH_BOX_LIB = -L$(GMSH_LIB_DIR) -lBox -lParser -lMesh -lGeo\
                                            -lAdapt -lPlugin -lCommon -lDataStr -lParallel
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
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

static:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=-I$(HOME)/SOURCES/Mesa-static/include -I$(HOME)/SOURCES/Mesa-static/include/GL" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done
	$(CC) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_FLTK_LIB) $(MESA_STATIC_LIB) \
                 $(FLTK_STATIC_LIB) -lm

win: initialtag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-g -Wall -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB) \
            $(HOME)/SOURCES/fltk/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

motif: initialtag
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_LITTLE_ENDIAN -D_NOPLUGIN" \
           "VERSION_FLAGS=-D_XMOTIF" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

gmsh:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lm

efence:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lefence -lm

gmsh2:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lfltk_gl $(THREAD_LIB) -lm

motifgl:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
              $(OPENGL_MOTIF_LIB) $(OPENGL_LIB) $(XMOTIF_LIB) $(THREAD_LIB) -lm

motifmesa:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
              $(MESA_MOTIF_LIB) $(MESA_LIB) $(XMOTIF_LIB) $(THREAD_LIB) -lm

motifmesastatic:
	$(CC) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_XMOTIF_LIB)\
              $(MESA_MOTIF_STATIC_LIB) $(MESA_STATIC_LIB)\
              $(XMOTIF_LIB) $(THREAD_LIB) -lm


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
           "VERSION_FLAGS=-D_FLTK -D_XMOTIF" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC) $(FLTK_INC)" \
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

# ----------------------------------------------------------------------
# Demos
# ----------------------------------------------------------------------

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

bbn: tag
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
# Ready to compile for some platforms with MOTIF
# ----------------------------------------------------------------------

motif_dec: tag motif_compile_little_endian motif_link_opengl strip_bin

motif_linux: tag motif_compile_little_endian motif_link_mesa strip_bin

motif_linux_2952: tag motif_compile_little_endian_2952 motif_link_mesa_2952 strip_bin

motif_ibm: tag motif_compile_big_endian motif_link_mesa strip_bin

motif_sun: tag motif_compile_big_endian motif_link_opengl strip_bin

motif_hp: tag motif_compile_big_endian motif_link_hp strip_bin

motif_sgi: tag motif_compile_sgi motif_link_sgi strip_bin

motif_rpm: src
	mv $(GMSH_SRCRPM).tar.gz /usr/src/redhat/SOURCES
	rpm -bb utils/gmsh_motif.spec
	cp /usr/src/redhat/RPMS/i386/$(GMSH_SRCRPM)-1.i386.rpm .
	cp /usr/src/redhat/BUILD/$(GMSH_SRCRPM)/bin/gmsh .
	gtar zcvf gmsh-$(GMSH_UNAME).tgz gmsh
	rm -f gmsh

motif_compile_little_endian:
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

motif_compile_little_endian_2952:
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=$(HOME)/gcc-2.95.2/bin/g++" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

motif_compile_little_endian_threads:
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-D_REENTRANT -O3" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN -D_USETHREADS" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

motif_compile_big_endian:
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

# special car -O2 merde dans 3d_smesh.c sur TransfiniteHex()
motif_compile_sgi:
	@for i in $(GMSH_XMOTIF_DIR); do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O2 -o32 -Olimit 3000" \
           "RANLIB=true"\
           "AR=CC -o32 -ar -o"\
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done
	@for i in Mesh; do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O1 -o32" \
           "AR=CC -o32 -ar -o"\
           "RANLIB=true"\
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_XMOTIF -D_NOPLUGIN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(MOTIF_INC)" \
        ); done

motif_link_sgi:
	CC -O2 -o32 -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
           $(OPENGL_MOTIF_LIB) $(OPENGL_LIB) $(XMOTIF_LIB) -lm

motif_link_opengl:
	g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
            $(OPENGL_MOTIF_LIB) $(OPENGL_LIB) $(XMOTIF_LIB) -lm

motif_link_mesa:
	g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
            $(MESA_MOTIF_LIB) $(MESA_LIB) $(XMOTIF_LIB) -lm

motif_link_mesa_2952:
	$(HOME)/gcc-2.95.2/bin/g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
               $(MESA_MOTIF_LIB) $(MESA_LIB) $(XMOTIF_LIB) -lm

motif_link_mesa_threads:
	g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
               $(MESA_MOTIF_LIB) $(MESA_LIB) $(XMOTIF_LIB) $(THREAD_LIB) -lm

# special car +s necessaire pour shared libs avec SHLIB_PATH variable.
motif_link_hp:
	g++ -Wl,+s -o $(GMSH_BIN_DIR)/gmsh $(GMSH_XMOTIF_LIB)\
                      $(MESA_MOTIF_LIB) $(MESA_LIB) $(XMOTIF_LIB) -lm


# ----------------------------------------------------------------------
# Ready to compile for some platforms with FLTK
# ----------------------------------------------------------------------

fltk_compile_little_endian:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

# optimized gcc fucks up with 3D_Extrude on old linux boxes...
fltk_compile_little_endian_2952:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(HOME)/gcc-2.95.3/bin/g++" \
           "C_FLAGS=-O2" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done
	rm -f Mesh/3D_Extrude.o
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(HOME)/gcc-2.95.3/bin/g++" \
           "C_FLAGS=-O0" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done


fltk_compile_big_endian:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=-I/usr/include/X11/GLw -I$(HOME)/SOURCES/Mesa-3.1/include -I$(HOME)/SOURCES/Mesa-3.1/include/GL" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

fltk_compile_ibm:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_BSD" \
           "VERSION_FLAGS=-D_FLTK -D_NODLL" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

fltk_compile_solaris_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC_SCOREC)" \
        ); done

fltk_compile_linux_scorec :
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O2" \
           "VERSION_FLAGS=-D_FLTK" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC_SCOREC)" \
        ); done

fltk_compile_sgi:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O2 -mips3 -n32 -OPT:Olimit=0 -LANG:std" \
           "RANLIB=true"\
           "AR=CC -mips3 -n32 -ar -o"\
           "OS_FLAGS=" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

fltk_compile_mingw:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++ -mno-cygwin -I/mingw/include" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

fltk_compile_cygwin:
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK -I/usr/include/w32api" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC)" \
        ); done

fltk_link_solaris_scorec:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 $(FLTK_LIB_SOLARIS_SCOREC) -lm -ldl -lsocket

fltk_purify:
	purify -cache-dir=/space g++ -o $(GMSH_BIN_DIR)/gmsh-sun $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 $(FLTK_LIB_SOLARIS_SCOREC) -lm -ldl -lsocket

fltk_link_linux_scorec:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-linux $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 $(FLTK_LIB_LINUX_SCOREC) -lm -ldl 
fltk_link_mesa:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lm -ldl

fltk_link_mesa_2952:
	$(HOME)/gcc-2.95.2/bin/g++ -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lm -ldl

fltk_link_opengl:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(OPENGL_LIB) \
                 $(FLTK_LIB) -lm
fltk_link_sgi:
	CC -O2 -mips3 -n32 -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                  $(FLTK_LIB) $(OPENGL_LIB) -lm
fltk_link_sun:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lXext -lsocket -lnsl -ldl -lm
fltk_link_hp:
	g++ -Wl,+s -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB)\
                      $(MESA_LIB) $(FLTK_LIB) -lm

fltk_link_ibm:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_FLTK_LIB) $(MESA_LIB) \
                 $(FLTK_LIB) -lm

fltk_link_mingw:
	g++ -mno-cygwin -L/mingw/lib -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB) Common/Icon.res \
                 $(HOME)/SOURCES/fltk/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

fltk_link_cygwin:
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB) Common/Icon.res \
                 $(HOME)/SOURCES/fltk/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

fltk_linux: tag fltk_compile_little_endian fltk_link_mesa strip_bin

fltk_linux_2952: tag fltk_compile_little_endian_2952 fltk_link_mesa_2952 strip_bin

fltk_rpm: src
	mv $(GMSH_SRCRPM).tar.gz /usr/src/redhat/SOURCES
	rpm -bb utils/gmsh_fltk.spec
	cp /usr/src/redhat/RPMS/i386/$(GMSH_SRCRPM)-1.i386.rpm .
	cp /usr/src/redhat/BUILD/$(GMSH_SRCRPM)/gmsh-$(GMSH_RELEASE)-$(GMSH_UNAME).tgz .

fltk_dec: tag fltk_compile_little_endian fltk_link_opengl strip_bin

fltk_sun: tag fltk_compile_big_endian fltk_link_sun strip_bin

fltk_hp: tag fltk_compile_big_endian fltk_link_hp strip_bin

fltk_ibm: tag fltk_compile_ibm fltk_link_ibm strip_bin

fltk_solaris_scorec : fltk_compile_solaris_scorec fltk_link_solaris_scorec strip_bin 

fltk_linux_scorec : fltk_compile_linux_scorec fltk_link_linux_scorec strip_bin 

fltk_sgi: tag fltk_compile_sgi fltk_link_sgi strip_bin

fltk_mingw: tag fltk_compile_mingw fltk_link_mingw
	strip $(GMSH_BIN_DIR)/gmsh.exe

fltk_cygwin: tag fltk_compile_cygwin fltk_link_cygwin
	strip $(GMSH_BIN_DIR)/gmsh.exe

fltk_cygwin_gertha_buro: tag
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC_GERTHA_BURO)" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh.exe $(GMSH_FLTK_LIB) Common/Icon.res \
                 ../fltk/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

fltk_cygwin_laptopjf: 
	@for i in $(GMSH_FLTK_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O2 -DWIN32" \
           "OS_FLAGS=-D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_FLTK" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "GUI_INCLUDE=$(FLTK_INC_LAPTOPJF)" \
        ); done
	g++ -Wl,--subsystem,windows -o $(GMSH_BIN_DIR)/gmsh-cyg.exe $(GMSH_FLTK_LIB) Common/Icon.res \
                 ../fltk-1.0.9/lib/libfltk.a -lglu32 -lopengl32 -lgdi32 -lwsock32 -lm

fltk_cygwin_laptopjf_tag: tag fltk_cygwin_laptopjf


