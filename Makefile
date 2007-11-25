# $Id: Makefile,v 1.443 2007-11-25 08:35:11 geuzaine Exp $
#
# Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
# 
# Please report all bugs and problems to <gmsh@geuz.org>.

include variables

GMSH_MAJOR_VERSION = 2
GMSH_MINOR_VERSION = 1
GMSH_PATCH_VERSION = 0
GMSH_EXTRA_VERSION = 

GMSH_VERSION = ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}

GMSH_SHORT_LICENSE = "GNU General Public License"

GMSH_VERSION_FILE = Common/GmshVersion.h
GMSH_DATE = `date "+%Y%m%d"`

all: link

link: compile
	${LINKER} ${OPTIM} -o bin/gmsh ${GMSH_LIBS}
	${POSTBUILD}

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

install-mac: variables package-mac
	cp -rf gmsh-${GMSH_VERSION}/Gmsh.app /Applications
	rm -rf gmsh-${GMSH_VERSION} gmsh-${GMSH_VERSION}-MacOSX.tgz

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
	cd doc && tar zcvf ../gmsh-${GMSH_VERSION}-doc.tgz\
          FAQ CREDITS VERSIONS README.win32 gmsh.1\
          texinfo/gmsh.ps texinfo/gmsh.pdf texinfo/gmsh.txt\
          texinfo/*.html texinfo/gmsh-info.tgz

doc-info:
	cd doc/texinfo && ${MAKE} info

purge:
	rm -f `find . -name "*~" -o -name "*~~" -o -name ".gmsh-errors"\
               -o -name "\#*" -o -name ".\#*" -o -name ".DS_Store"\
               -o -name "gmon.out" -o -name ".gdb_history" -o -name "debug?.pos"`

clean:
	for i in doc lib ${GMSH_DIRS}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

clean-most:
	for i in doc lib ${GMSH_DIRS:contrib/Netgen=}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

clean-fm:
	rm -f Geo/F*.o Geo/GModelIO_F.o Fltk/GUI_Projection.o 

depend: initialtag
	for i in ${GMSH_DIRS};\
        do (cd $$i && ${MAKE} depend "FLAGS=-DHAVE_GSL -DHAVE_FLTK"); done

nodepend:
	for i in ${GMSH_DIRS} ; do \
          (cd $$i && (sed '/^# DO NOT DELETE THIS LINE/q' Makefile) > Makefile.new \
          && cp Makefile Makefile.bak \
          && cp Makefile.new Makefile \
          && rm -f Makefile.new); \
        done 

tag:
	rm -f ${GMSH_VERSION_FILE}
	echo "#define GMSH_MAJOR_VERSION ${GMSH_MAJOR_VERSION}" >  ${GMSH_VERSION_FILE}
	echo "#define GMSH_MINOR_VERSION ${GMSH_MINOR_VERSION}" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PATCH_VERSION ${GMSH_PATCH_VERSION}" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_EXTRA_VERSION \"${GMSH_EXTRA_VERSION}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_VERSION  \"${GMSH_VERSION}\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_DATE     \"`date`\""     >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_HOST     \"`hostname`\"" >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PACKAGER \"`whoami`\""   >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_OS       \"${UNAME}\""   >> ${GMSH_VERSION_FILE}
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
	tar zcvf gmsh.tgz --exclude "*.o" --exclude "*.a" --exclude "gmsh"\
          --exclude "variables" --exclude "config.log" --exclude "config.status"\
          --exclude "autom4*" --exclude "Makefile.distrib" --exclude "Makefile.back"\
          --exclude "benchmarks" --exclude "zzz_*" --exclude "HTML"\
          --exclude "*TAGS*" --exclude "GSYMS" --exclude "GPATH" --exclude "CVS"\
          *
	mkdir gmsh-${GMSH_VERSION}
	cd gmsh-${GMSH_VERSION} && tar zxvf ../gmsh.tgz
	rm -f gmsh.tgz

source: source-tree
	cd gmsh-${GMSH_VERSION} && rm -rf ${GMSH_VERSION_FILE}\
          contrib/NR contrib/Triangle/triangle.* contrib/Tetgen/tetgen.*\
          contrib/Tetgen/predicates.* utils/commercial 
	tar zcvf gmsh-${GMSH_VERSION}-source.tgz gmsh-${GMSH_VERSION}

source-commercial: source-tree
	cd gmsh-${GMSH_VERSION} && rm -rf ${GMSH_VERSION_FILE}\
          contrib/MathEval contrib/Triangle/triangle.* contrib/Tetgen/tetgen.*\
          contrib/Tetgen/predicates.* contrib/Netgen/libsrc contrib/Metis\
          doc/TODO doc/gmsh.html doc/README.cvs\
          utils/commercial
	cp -f utils/commercial/README gmsh-${GMSH_VERSION}/README
	cp -f utils/commercial/LICENSE gmsh-${GMSH_VERSION}/doc/LICENSE
	cp -f utils/commercial/License.cpp gmsh-${GMSH_VERSION}/Common/License.cpp
	cp -f utils/commercial/license.texi gmsh-${GMSH_VERSION}/doc/texinfo/license.texi
	cp -f utils/commercial/copying.texi gmsh-${GMSH_VERSION}/doc/texinfo/copying.texi
	utils/commercial/sanitize.sh gmsh-${GMSH_VERSION}
	tar zcvf gmsh-${GMSH_VERSION}-source-commercial.tgz gmsh-${GMSH_VERSION}

# Rules to package the binaries

package-unix:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	cp bin/gmsh gmsh-${GMSH_VERSION}
	strip gmsh-${GMSH_VERSION}/gmsh
	cp doc/gmsh.1 doc/LICENSE doc/VERSIONS doc/FAQ doc/CREDITS gmsh-${GMSH_VERSION}
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/tutorial/*.msh
	rm -f gmsh-${GMSH_VERSION}/*/*~
	tar cvf gmsh-${GMSH_VERSION}-${UNAME}.tar gmsh-${GMSH_VERSION}
	gzip gmsh-${GMSH_VERSION}-${UNAME}.tar
	mv gmsh-${GMSH_VERSION}-${UNAME}.tar.gz gmsh-${GMSH_VERSION}-${UNAME}.tgz

package-win:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	cp bin/gmsh.exe gmsh-${GMSH_VERSION}
	strip gmsh-${GMSH_VERSION}/gmsh.exe
	cp doc/README.win32 gmsh-${GMSH_VERSION}/README.txt
	cp doc/VERSIONS gmsh-${GMSH_VERSION}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_VERSION}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_VERSION}/CREDITS.txt
	cp doc/LICENSE gmsh-${GMSH_VERSION}/LICENSE.txt
	cd utils/misc && ./unix2dos.bash ../../gmsh-${GMSH_VERSION}/*.txt
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/tutorial/*.msh
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
	echo -e "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"\
        "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\""\
                              " \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"\
        "<plist version=\"1.0\">\n"\
        "  <dict>\n"\
        "    <key>CFBundleName</key><string>Gmsh</string>\n"\
        "    <key>CFBundleExecutable</key><string>Gmsh</string>\n"\
        "    <key>CFBundlePackageType</key><string>APPL</string>\n"\
        "    <key>CFBundleVersion</key><string>${GMSH_VERSION}</string>\n"\
        "    <key>CFBundleShortVersionString</key><string>${GMSH_VERSION}</string>\n"\
        "    <key>CFBundleIconFile</key><string>Gmsh.icns</string>\n"\
        "    <key>CFBundleSignature</key><string>GMSH</string>\n"\
        "    <key>CFBundleGetInfoString</key><string>Gmsh ${GMSH_VERSION},"\
                  "Copyright (C) 1997-2007 C. Geuzaine and J.-F. Remacle</string>\n"\
        "    <key>CFBundleIdentifier</key><string>org.geuz.Gmsh</string>\n"\
        "    <key>CFBundleDocumentTypes</key>\n"\
        "      <array>\n"\
        "        <dict>\n"\
        "          <key>CFBundleTypeExtensions</key><array>\n"\
        "            <string>geo</string>\n"\
        "            <string>brep</string><string>brp</string><string>rle</string>\n"\
        "            <string>igs</string><string>iges</string>\n"\
        "            <string>stp</string><string>step</string></array>\n"\
        "          <key>CFBundleTypeIconFile</key><string>GmshGeo.icns</string>\n"\
        "          <key>CFBundleTypeName</key><string>Gmsh Geometry File</string>\n"\
        "          <key>CFBundleTypeOSTypes</key><array><string>GGEO</string></array>\n"\
        "          <key>CFBundleTypeRole</key><string>Editor</string>\n"\
        "        </dict>\n"\
        "        <dict>\n"\
        "          <key>CFBundleTypeExtensions</key><array>\n"\
        "            <string>msh</string>\n"\
        "            <string>unv</string>\n"\
        "            <string>vrml</string><string>wrl</string><string>iv</string>\n"\
        "            <string>bdf</string><string>nas</string>\n"\
        "            <string>mesh</string></array>\n"\
        "          <key>CFBundleTypeIconFile</key><string>GmshMsh.icns</string>\n"\
        "          <key>CFBundleTypeName</key><string>Gmsh Mesh File</string>\n"\
        "          <key>CFBundleTypeOSTypes</key><array><string>GMSH</string></array>\n"\
        "          <key>CFBundleTypeRole</key><string>Viewer</string>\n"\
        "        </dict>\n"\
        "        <dict>\n"\
        "          <key>CFBundleTypeExtensions</key><array><string>pos</string></array>\n"\
        "          <key>CFBundleTypeIconFile</key><string>GmshPos.icns</string>\n"\
        "          <key>CFBundleTypeName</key><string>Gmsh Post-Processing File</string>\n"\
        "          <key>CFBundleTypeOSTypes</key><array><string>GPOS</string></array>\n"\
        "          <key>CFBundleTypeRole</key><string>Viewer</string>\n"\
        "        </dict>\n"\
        "      </array>\n"\
        "  </dict>\n"\
        "</plist>" > gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Info.plist
	cp bin/gmsh gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS/Gmsh
	strip gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS/Gmsh
	cp Fltk/MacIcons.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/Gmsh.icns
	cp Fltk/MacIconsGeo.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshGeo.icns
	cp Fltk/MacIconsMsh.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshMsh.icns
	cp Fltk/MacIconsPos.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/GmshPos.icns
	cp -R tutorial demos gmsh-${GMSH_VERSION}
	cp doc/VERSIONS gmsh-${GMSH_VERSION}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_VERSION}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_VERSION}/CREDITS.txt
	cp doc/LICENSE gmsh-${GMSH_VERSION}/LICENSE.txt
	rm -rf gmsh-${GMSH_VERSION}/*/CVS\
               gmsh-${GMSH_VERSION}/tutorial/*.msh\
               gmsh-${GMSH_VERSION}/*/*~
	tar zcvf gmsh-${GMSH_VERSION}-MacOSX.tgz gmsh-${GMSH_VERSION}

package-rpm:
	tar zcvf /usr/src/rpm/SOURCES/gmsh-${GMSH_VERSION}.tar.gz .
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
	${POSTBUILD}
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

distrib-source-commercial:
	make distrib-pre
	make source-commercial
	make distrib-post
