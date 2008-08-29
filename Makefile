# Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

include variables

GMSH_MAJOR_VERSION = 2
GMSH_MINOR_VERSION = 2
GMSH_PATCH_VERSION = 4
GMSH_EXTRA_VERSION =

GMSH_VERSION = ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}

GMSH_SHORT_LICENSE = "GNU General Public License"

GMSH_VERSION_FILE = Common/GmshVersion.h
GMSH_DATE = `date "+%Y%m%d"`

GMSH_API = Geo/GModel.h Geo/GEntity.h Geo/GPoint.h\
           Geo/GVertex.h Geo/GEdge.h Geo/GEdgeLoop.h Geo/GFace.h Geo/GRegion.h\
           Geo/MVertex.h Geo/MEdge.h Geo/MFace.h Geo/MElement.h\
           Geo/discreteVertex.h Geo/discreteEdge.h Geo/discreteFace.h Geo/discreteRegion.h\
           Geo/SPoint2.h Geo/SPoint3.h Geo/SVector3.h Geo/SBoundingBox3d.h\
           Geo/Pair.h Geo/Range.h\
           Post/PView.h Post/PViewData.h Post/PViewDataGModel.h\
           Common/VertexArray.h Common/Message.h\
           Common/Gmsh.h Common/GmshDefines.h Common/GmshVersion.h Common/GmshMatrix.h

GMSH_EMBEDDED = ${GMSH_API} Geo/discrete*.cpp\
                Geo/GModel.cpp Geo/GModelIO_Mesh.cpp\
                Geo/GEntity.cpp Geo/GVertex.cpp Geo/GEdge.cpp\
                Geo/GEdgeLoop.cpp Geo/GFace.cpp Geo/GRegion.cpp\
                Geo/MElement.cpp Geo/MFace.cpp Geo/MVertex.cpp\
                Common/StringUtils.{cpp,h}\
                Numeric/NumericEmbedded.{cpp,h} Numeric/FunctionSpace.{cpp,h}\
                utils/embed/GmshEmbedded.{cpp,h} utils/embed/Makefile

all: link

link: compile
	${LINKER} ${OPTIM} ${DASH}o bin/gmsh${EXEEXT} ${GMSH_LIBS}

link-mac-universal: compile
	${LINKER} -arch i386 ${OPTIM} -o bin/gmsh_i386 ${GMSH_LIBS}
	${LINKER} -arch ppc ${OPTIM} -o bin/gmsh_ppc ${GMSH_LIBS}
	lipo -create bin/gmsh_i386 bin/gmsh_ppc -output bin/gmsh
	rm -f bin/gmsh_i386 bin/gmsh_ppc

compile: variables initialtag
	@for i in ${GMSH_DIRS}; do (cd $$i && ${MAKE}); done

install: variables
	mkdir -p ${bindir}
	cp -f bin/gmsh${EXEEXT} ${bindir}
	chmod 755 ${bindir}/gmsh${EXEEXT}
	mkdir -p ${mandir}/man1
	cp -f doc/gmsh.1 ${mandir}/man1

uninstall:
	rm -f ${bindir}/gmsh${EXEEXT}
	rm -f ${mandir}/man1/gmsh.1

install-mac: variables package-mac
	cp -rf gmsh-${GMSH_VERSION}/Gmsh.app /Applications
	rm -rf gmsh-${GMSH_VERSION} gmsh-${GMSH_VERSION}-MacOSX.tgz

uninstall-mac:
	rm -rf /Applications/Gmsh.app

.PHONY: lib
lib: variables initialtag
	@for i in ${GMSH_DIRS}; do (cd $$i && ${MAKE} cpobj); done
	${AR} ${ARFLAGS}lib/libGmsh${LIBEXT} lib/*${OBJEXT}
	${RANLIB} lib/libGmsh${LIBEXT}
	rm -f lib/*${OBJEXT}

install-lib: lib
	mkdir -p ${includedir}/gmsh
	rm -f ${includedir}/gmsh/*
	cp -f ${GMSH_API} ${includedir}/gmsh
	mkdir -p ${libdir}
	cp -f lib/libGmsh${LIBEXT} ${libdir}/libGmsh${LIBSUFFIX}${LIBEXT}

uninstall-lib:
	rm -rf ${includedir}/gmsh
	rm -rf ${libdir}/libGmsh${LIBSUFFIX}${LIBEXT}

framework: lib
	rm -rf Gmsh.framework
	mkdir -p Gmsh.framework
	mkdir -p Gmsh.framework/Versions
	mkdir -p Gmsh.framework/Versions/A
	mkdir -p Gmsh.framework/Versions/A/Headers
	mkdir -p Gmsh.framework/Versions/A/Resources
	cp lib/libGmsh${LIBEXT} Gmsh.framework/Versions/A/Gmsh
	cp ${GMSH_API} Gmsh.framework/Versions/A/Headers/
	sed -e "s/GMSH_VERSION/${GMSH_VERSION}/g" utils/misc/Info_framework.plist\
             > Gmsh.framework/Versions/A/Resources/Info.plist
	cd Gmsh.framework/Versions && ln -s A Current
	cd Gmsh.framework && ln -s Versions/Current/Gmsh
	cd Gmsh.framework && ln -s Versions/Current/Headers
	cd Gmsh.framework && ln -s Versions/Current/Resources

embed:
	@if [ -r ../getdp/contrib/gmsh/Makefile ]; then \
          rsync -av ${GMSH_EMBEDDED} ../getdp/contrib/gmsh;\
        fi

variables: configure
	@echo "********************************************************************"
	@echo "Please configure Gmsh by running ./configure"
	@echo "For help, type ./configure --help"
	@echo "********************************************************************"
	@exit 1

.PHONY: parser
parser:
	cd Parser && ${MAKE} parser

.PHONY: utils
utils:
	cd utils/converters/autocad && ${MAKE}
	cd utils/misc && ${MAKE}

.PHONY: doc
doc:
	cd doc/texinfo && ${MAKE} all
	cd doc && tar zcf ../gmsh-${GMSH_VERSION}-doc.tgz\
          FAQ.txt CREDITS.txt VERSIONS.txt README.win32 gmsh.1\
          texinfo/gmsh.pdf texinfo/gmsh.txt\
          texinfo/*.html texinfo/gmsh-info.tgz

doc-info:
	cd doc/texinfo && ${MAKE} info

purge:
	rm -f `find . -name "*~" -o -name "*~~" -o -name ".gmsh-errors"\
               -o -name "\#*" -o -name ".\#*" -o -name ".DS_Store"\
               -o -name "gmon.out" -o -name ".gdb_history" -o -name "debug?.pos"\
               -o -name "*.bak"`

clean:
	for i in doc lib ${GMSH_DIRS}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

clean-most:
	for i in doc lib ${GMSH_DIRS:contrib/Netgen=}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

clean-fm:
	rm -f Geo/fourier*.o Geo/GModelIO_Fourier.o Fltk/GUI_Projection.o 

depend: initialtag
	for i in ${GMSH_DIRS};\
        do (cd $$i && ${MAKE} depend "FLAGS=-DHAVE_GSL -DHAVE_FLTK -DHAVE_METIS"); done

nodepend:
	for i in ${GMSH_DIRS} ; do \
          (cd $$i && (sed '/^# DO NOT DELETE THIS LINE/q' Makefile) > Makefile.new \
          && cp Makefile Makefile.bak \
          && cp Makefile.new Makefile \
          && rm -f Makefile.new); \
        done 

tag:
	rm -f ${GMSH_VERSION_FILE}
	echo "#define GMSH_MAJOR_VERSION ${GMSH_MAJOR_VERSION}" > ${GMSH_VERSION_FILE}
	echo "#define GMSH_MINOR_VERSION ${GMSH_MINOR_VERSION}" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PATCH_VERSION ${GMSH_PATCH_VERSION}" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_EXTRA_VERSION \"${GMSH_EXTRA_VERSION}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_VERSION       \"${GMSH_VERSION}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_DATE          \"`date`\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_HOST          \"${HOSTNAME}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PACKAGER      \"`whoami`\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_OS            \"${UNAME}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_SHORT_LICENSE \"${GMSH_SHORT_LICENSE}\"" >> ${GMSH_VERSION_FILE}

initialtag:
	@if [ ! -r ${GMSH_VERSION_FILE} ]; then ${MAKE} tag ; fi

tags:
	gtags
	htags

etags:
	etags `find . \( -name "*.cpp" -o -name "*.c" -o -name "*.h"\
                      -o -name "*.y" -o -name "*.l" \)`

# Rules to package the sources

source-tree: purge
	rm -rf gmsh-${GMSH_VERSION}
	tar zcf gmsh.tgz --exclude "*.o" --exclude "*.a" --exclude "gmsh"\
          --exclude "variables" --exclude "config.log" --exclude "config.status"\
          --exclude "autom4*" --exclude "Makefile.distrib" --exclude "Makefile.bak"\
          --exclude "benchmarks" --exclude "zzz_*" --exclude "HTML"\
          --exclude "*TAGS*" --exclude "GSYMS" --exclude "GPATH" --exclude "CVS"\
          *
	mkdir gmsh-${GMSH_VERSION}
	cd gmsh-${GMSH_VERSION} && tar zxf ../gmsh.tgz
	rm -f gmsh.tgz

source: source-tree
	cd gmsh-${GMSH_VERSION} && rm -rf ${GMSH_VERSION_FILE}\
          contrib/NR contrib/Tetgen/*.{cxx,h} contrib/misc/variables.i*\
	tar zcf gmsh-${GMSH_VERSION}-source.tgz gmsh-${GMSH_VERSION}

# Rules to package the binaries

package-unix:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	cp bin/gmsh gmsh-${GMSH_VERSION}
	strip gmsh-${GMSH_VERSION}/gmsh
	cp doc/gmsh.1 doc/LICENSE.txt doc/VERSIONS.txt doc/FAQ.txt doc/CREDITS.txt\
          gmsh-${GMSH_VERSION}
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/tutorial/t*.msh
	rm -f gmsh-${GMSH_VERSION}/*/*~
	tar cf gmsh-${GMSH_VERSION}-${UNAME}.tar gmsh-${GMSH_VERSION}
	gzip gmsh-${GMSH_VERSION}-${UNAME}.tar
	mv gmsh-${GMSH_VERSION}-${UNAME}.tar.gz gmsh-${GMSH_VERSION}-${UNAME}.tgz

package-win:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	cp bin/gmsh.exe gmsh-${GMSH_VERSION}
	strip gmsh-${GMSH_VERSION}/gmsh.exe
	cp doc/README.win32 gmsh-${GMSH_VERSION}/README.txt
	cp doc/LICENSE.txt doc/VERSIONS.txt doc/FAQ.txt doc/CREDITS.txt\
          gmsh-${GMSH_VERSION}
	cd utils/misc && ./unix2dos.bash ../../gmsh-${GMSH_VERSION}/*.txt
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/tutorial/t*.msh
	rm -f gmsh-${GMSH_VERSION}/*/*~
	cd utils/misc && ./unix2dos.bash ../../gmsh-${GMSH_VERSION}/tutorial/*\
                                         ../../gmsh-${GMSH_VERSION}/demos/*
	cd gmsh-${GMSH_VERSION} && zip -r gmsh-${GMSH_VERSION}-Windows.zip *
	mv gmsh-${GMSH_VERSION}/gmsh-${GMSH_VERSION}-Windows.zip .

package-mac:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}/Gmsh.app
	mkdir gmsh-${GMSH_VERSION}/Gmsh.app/Contents
	mkdir gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources
	mkdir gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS
	echo "APPLGMSH" > gmsh-${GMSH_VERSION}/Gmsh.app/Contents/PkgInfo 
	sed -e "s/GMSH_VERSION/Gmsh ${GMSH_VERSION}/g" utils/misc/Info.plist\
             > gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Info.plist
	cp bin/gmsh gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS/Gmsh
	strip gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS/Gmsh
	cp Fltk/MacIcons.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/Gmsh.icns
	cp Fltk/MacIconsGeo.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshGeo.icns
	cp Fltk/MacIconsMsh.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshMsh.icns
	cp Fltk/MacIconsPos.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshPos.icns
	cp -R tutorial demos gmsh-${GMSH_VERSION}
	cp doc/LICENSE.txt doc/VERSIONS.txt doc/FAQ.txt doc/CREDITS.txt\
          gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS\
               gmsh-${GMSH_VERSION}/tutorial/t*.msh\
               gmsh-${GMSH_VERSION}/*/*~
	tar zcf gmsh-${GMSH_VERSION}-MacOSX.tgz gmsh-${GMSH_VERSION}

package-rpm:
	tar zcf /usr/src/rpm/SOURCES/gmsh-${GMSH_VERSION}.tar.gz .
	rpmbuild -bb --define 'gmshversion ${GMSH_VERSION}' utils/misc/gmsh.spec
	mv /usr/src/rpm/RPMS/i386/gmsh-${GMSH_VERSION}-?.i386.rpm .
	mv /usr/src/rpm/BUILD/gmsh-${GMSH_VERSION}/gmsh-${GMSH_VERSION}-${UNAME}.tgz .
	rm -f /usr/src/rpm/SOURCES/gmsh-${GMSH_VERSION}.tar.gz
	rm -rf /usr/src/rpm/BUILD/gmsh-${GMSH_VERSION}

# Rules to distribute official releases

distrib-pre:
	mv -f Makefile Makefile.distrib
	sed -e "s/^GMSH_EXTRA_VERSION.*/GMSH_EXTRA_VERSION =/g"\
          Makefile.distrib > Makefile
	make tag

distrib-pre-cvs:
	mv -f Makefile Makefile.distrib
	sed -e "s/^GMSH_EXTRA_VERSION.*/GMSH_EXTRA_VERSION = \"-cvs-${GMSH_DATE}\"/g"\
          Makefile.distrib > Makefile
	make tag

distrib-post:
	mv -f Makefile.distrib Makefile
	rm -f ${GMSH_VERSION_FILE}

distrib-unix:
	make distrib-pre
	make link
	make package-unix
	make distrib-post
	ldd bin/gmsh

distrib-unix-nightly:
	make distrib-pre-cvs
	make link
	make package-unix
	make distrib-post

distrib-win:
	make distrib-pre
	make link
	make package-win
	make distrib-post
	objdump -p bin/gmsh.exe | grep DLL

distrib-win-nightly:
	make distrib-pre-cvs
	make link
	make package-win
	make distrib-post

distrib-mac:
	make distrib-pre
	make link-mac-universal
	make package-mac
	make distrib-post
	otool -L bin/gmsh

distrib-mac-nightly:
	make distrib-pre-cvs
	make link-mac-universal
	make package-mac
	make distrib-post

distrib-source:
	make distrib-pre
	make source
	make distrib-post

distrib-source-nightly:
	make distrib-pre-cvs
	make source
	make distrib-post
