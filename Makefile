# $Id: Makefile,v 1.11 2000-12-05 19:38:11 geuzaine Exp $
# ----------------------------------------------------------------------
#  Makefile for Gmsh  
# ----------------------------------------------------------------------

    GMSH_RELEASE = 0.995

            MAKE = make
              CC = g++
           FLAGS = -g -Wall
              RM = rm
         RMFLAGS = -f 

      OPENGL_INC = -I/usr/include/X11/GLw\
                   -I$(HOME)/SOURCES/Mesa-3.1/include\
                   -I$(HOME)/SOURCES/Mesa-3.1/include/GL
       MOTIF_INC = -I/usr/X11R6/LessTif/Motif1.2/include

      OPENGL_LIB = -lGLw -lGLU -lGL
        MESA_LIB = -L$(HOME)/SOURCES/Mesa-3.1/lib -lGLw -lGLU -lGL
 MESA_STATIC_LIB = $(HOME)/SOURCES/Mesa-3.0-static/lib/libGLw.a\
                   $(HOME)/SOURCES/Mesa-3.0-static/lib/libGLU.a\
                   $(HOME)/SOURCES/Mesa-3.0-static/lib/libGL.a
       MOTIF_LIB = -L/usr/local/lib -L/usr/X11R6/LessTif/Motif1.2/lib -lXm 
           X_LIB = -L/usr/X11R6/lib -lXt -lX11 -lXext
      THREAD_LIB = -L/usr/lib -lpthread

        GMSH_DIR = Adapt Common DataStr Geo Graphics Mesh Parser Unix
GMSH_DISTRIB_DIR = $(GMSH_DIR) utils
    GMSH_BOX_DIR = Adapt Box Common DataStr Geo Mesh Parser
    GMSH_BIN_DIR = bin
    GMSH_LIB_DIR = lib
    GMSH_DOC_DIR = doc
   GMSH_DEMO_DIR = demos
GMSH_ARCHIVE_DIR = archives
        GMSH_LIB = -L$(GMSH_LIB_DIR) -lUnix -lGraphics -lParser -lMesh -lGeo\
                                     -lAdapt -lCommon -lDataStr
    GMSH_BOX_LIB = -L$(GMSH_LIB_DIR) -lBox -lParser -lMesh -lGeo\
                                     -lAdapt -lCommon -lDataStr
    GMSH_ARCHIVE = $(GMSH_ARCHIVE_DIR)/gmsh-`date "+%Y.%m.%d"`
     GMSH_SRCRPM = gmsh-$(GMSH_RELEASE)
    GMSH_SOURCES = `find . \( ! -name "*.tar*" -a ! -name "*.tgz" \
                           -a ! -name "*.o"    -a ! -name "lib*.a"   \
                           -a ! -name "*.msh"  -a ! -name "*.bak" \
                           -a ! -name "gmsh"   -a ! -name "gmsh-*"\
                           -a ! -type d \)`
      GMSH_UNAME = `uname`

default: initialtag
	@for i in $(GMSH_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_UNIX -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done

threads: initialtag
	@for i in $(GMSH_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=$(FLAGS)" \
           "OS_FLAGS=-D_UNIX -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done

profile: initialtag
	@for i in $(GMSH_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3 -pg" \
           "OS_FLAGS=-D_UNIX -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done
	$(CC) -pg -o $(GMSH_BIN_DIR)/gmsh-profile $(GMSH_LIB) $(OPENGL_LIB) \
                 $(MOTIF_LIB) $(X_LIB) $(THREAD_LIB) -lm

gmsh:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_LIB) $(OPENGL_LIB) \
                 $(MOTIF_LIB) $(X_LIB) $(THREAD_LIB) -lm

gmsh2:
	$(CC) -o $(GMSH_BIN_DIR)/gmsh $(GMSH_LIB) $(MESA_LIB) \
                 $(MOTIF_LIB) $(X_LIB) $(THREAD_LIB) -lm

gmshm:
	$(CC) -o $(GMSH_BIN_DIR)/gmshm $(GMSH_LIB) $(MESA_STATIC_LIB) \
                 $(MOTIF_LIB) $(X_LIB) $(THREAD_LIB) -lm

parser:
	cd Parser && $(MAKE) parser

purge:
	for i in "." $(GMSH_DISTRIB_DIR) $(GMSH_LIB_DIR) $(GMSH_ARCHIVE_DIR)\
                     $(GMSH_DEMO_DIR) $(GMSH_DOC_DIR) $(GMSH_BOX_DIR); \
        do (cd $$i && $(RM) $(RMFLAGS) *~ *~~); \
        done

clean:
	for i in $(GMSH_DISTRIB_DIR) $(GMSH_DOC_DIR) $(GMSH_LIB_DIR) ; \
        do (cd $$i && $(MAKE) clean); \
        done

depend:
	for i in $(GMSH_DISTRIB_DIR); \
        do (cd $$i && $(MAKE) depend \
           "CC=$(CC)" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done

nodepend:
	for i in $(GMSH_DISTRIB_DIR) ; do \
          (cd $$i && (sed '/^# DO NOT DELETE THIS LINE/q' Makefile) > Makefile.new \
          && cp Makefile Makefile.bak \
          && cp Makefile.new Makefile \
          && $(RM) $(RMFLAGS) Makefile.new); \
        done 

tag:
	$(RM) $(RMFLAGS) Common/Version.h
	echo "#define GMSH_VERSION  $(GMSH_RELEASE)" >  Common/Version.h
	echo "#define GMSH_DATE     \"`date`\""      >> Common/Version.h
	echo "#define GMSH_HOST     \"`hostname`\""  >> Common/Version.h
	echo "#define GMSH_PACKAGER \"`logname`\""   >> Common/Version.h
	echo "#define GMSH_OS       \"`uname -sr`\"" >> Common/Version.h

initialtag:
	@if [ ! -r Common/Version.h ]; then \
        $(MAKE) tag ; \
        fi

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

# ----------------------------------------------------------------------
# Demos
# ----------------------------------------------------------------------

dem:
	gtar zcvf gmsh-demos.tgz $(GMSH_DEMO_DIR)

# ----------------------------------------------------------------------
# Black Box
# ----------------------------------------------------------------------

bb: tag
	@for i in $(GMSH_BOX_DIR); do (cd $$i && $(MAKE) \
           "CC=$(CC)" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_UNIX" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=" \
           "MOTIF_INCLUDE=" \
        ); done
	$(CC) -o $(GMSH_BIN_DIR)/gmsh-box $(GMSH_BOX_LIB) -lm

bbn: tag
	@for i in $(GMSH_BOX_DIR) ; do (cd $$i && $(MAKE) \
           "CC=g++ -mno-cygwin -I/mingw/include" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_UNIX" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=" \
           "MOTIF_INCLUDE=" \
        ); done
	g++ -o $(GMSH_BIN_DIR)/gmsh.exe -mno-cygwin -L/mingw/lib $(GMSH_BOX_LIB) -lm

# ----------------------------------------------------------------------
# Ready to compile for somes platforms
# ----------------------------------------------------------------------

#### -O2 merde dans 3d_smesh.c sur TransfiniteHex()

sgi: tag
	@for i in $(GMSH_DIR); do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O2 -o32" \
           "RANLIB=true"\
           "OS_FLAGS=-D_UNIX" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done
	@for i in Mesh; do (cd $$i && $(MAKE) \
           "CC=CC" \
           "C_FLAGS=-O1 -o32" \
           "RANLIB=true"\
           "OS_FLAGS=-D_UNIX" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done
	CC -O2 -o32 -o $(GMSH_BIN_DIR)/gmsh-IRIX $(GMSH_LIB) $(OPENGL_LIB) \
              $(MOTIF_LIB) $(X_LIB) -lm
	strip $(GMSH_BIN_DIR)/gmsh-IRIX

little_endian: tag
	@for i in $(GMSH_DISTRIB_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_UNIX -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done

little_endian_threads: tag
	@for i in $(GMSH_DISTRIB_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-D_REENTRANT -O3" \
           "OS_FLAGS=-D_UNIX -D_LITTLE_ENDIAN" \
           "VERSION_FLAGS=-D_USETHREADS" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done

big_endian: tag
	@for i in $(GMSH_DISTRIB_DIR); do (cd $$i && $(MAKE) \
           "CC=g++" \
           "C_FLAGS=-O3" \
           "OS_FLAGS=-D_UNIX" \
           "VERSION_FLAGS=" \
           "GL_INCLUDE=$(OPENGL_INC)" \
           "MOTIF_INCLUDE=$(MOTIF_INC)" \
        ); done


ogl:
	g++ -o $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME) $(GMSH_LIB)\
               $(OPENGL_LIB) $(MOTIF_LIB) $(X_LIB) -lm
	strip $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME)

mesa:
	g++ -o $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME) $(GMSH_LIB)\
               $(MESA_LIB) $(MOTIF_LIB) $(X_LIB) -lm
	strip $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME)

mesa_threads:
	g++ -o $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME) $(GMSH_LIB)\
               $(MESA_LIB) $(MOTIF_LIB) $(X_LIB) $(THREAD_LIB) -lm
	strip $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME)

dec: little_endian ogl

linux: little_endian_threads mesa_threads

ibm: big_endian mesa

sun: big_endian mesa

# HP : special linker option is necessary (+s) + set the SHLIB_PATH variable.
hp: big_endian
	g++ -Wl,+s -o $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME) $(GMSH_LIB)\
                      $(MESA_LIB) $(MOTIF_LIB) $(X_LIB) -lm
	strip $(GMSH_BIN_DIR)/gmsh-$(GMSH_UNAME)

