# $Id: Makefile,v 1.336 2004-04-15 05:56:31 geuzaine Exp $
#
# Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

GMSH_MAJOR_VERSION = 1
GMSH_MINOR_VERSION = 51
GMSH_PATCH_VERSION = 5
GMSH_EXTRA_VERSION = "-cvs"

GMSH_VERSION = ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}${GMSH_EXTRA_VERSION}

GMSH_SHORT_LICENSE = "GNU General Public License"

GMSH_VERSION_FILE = Common/GmshVersion.h
GMSH_DATE = `date "+%Y%m%d"`
GMSH_SOURCES = `find . \( ! -name "*.tar*" -a ! -name "*.tgz" \
                       -a ! -name "*.o"    -a ! -name "lib*.a"   \
                       -a ! -name "*.msh"  -a ! -name "*.bak" \
                       -a ! -name "gmsh"   -a ! -name "gmsh-*"\
                       -a ! -type d \)`

all: variables initialtag compile link

compile: variables initialtag
	@for i in ${GMSH_DIRS}; do (cd $$i && ${MAKE}); done

link: variables
	${LINKER} ${OPTIM} -o bin/gmsh ${GMSH_LIBS}
	${POSTBUILD}

install: variables
	-mkdir -p ${bindir}
	-cp bin/gmsh${EXEEXT} ${bindir}
	-chmod 755 ${bindir}/gmsh${EXEEXT}
	-mkdir -p ${mandir}/man1
	-cp doc/gmsh.1 ${mandir}/man1

variables: configure
	@echo "********************************************************************"
	@echo "Please configure Gmsh by running ./configure"
	@echo "For help, type ./configure --help"
	@echo "********************************************************************"
	@exit 1

.PHONY: parser
parser:
	cd Parser && ${MAKE} parser

converters:
	cd utils/converters/autocad && ${MAKE}

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
               -o -name "\#*" -o -name "gmon.out" -o -name ".gdb_history"`

clean:
	for i in doc lib ${GMSH_DIRS}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

depend:
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
	echo "#define GMSH_DATE     \"`date`\""      >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_HOST     \"`hostname`\""  >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PACKAGER \"`whoami`\""    >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_OS       \"`uname -sr`\"" >> ${GMSH_VERSION_FILE}
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

source-common:
	rm -rf gmsh-${GMSH_VERSION}
	tar zcvf gmsh.tgz `ls TODO README* */README* configure *.in *.spec Makefile\
                           */Makefile */*.[chylr] */*.[ch]pp */*.rc */*.res */*.ico\
                           */*.icns`\
                           doc demos tutorial utils
	mkdir gmsh-${GMSH_VERSION}
	cd gmsh-${GMSH_VERSION} && tar zxvf ../gmsh.tgz
	rm -f gmsh.tgz

source: source-common
	cd gmsh-${GMSH_VERSION} && rm -rf CVS */CVS */*/CVS */.globalrc ${GMSH_VERSION_FILE}\
          NR Triangle/triangle.* utils/commercial
	tar zcvf gmsh-${GMSH_VERSION}-source.tgz gmsh-${GMSH_VERSION}

source-commercial: source-common
	cd gmsh-${GMSH_VERSION} && rm -rf CVS */CVS */*/CVS */.globalrc ${GMSH_VERSION_FILE}\
          Triangle/triangle.* TODO *.spec doc/gmsh.html doc/FAQ doc/README.cvs\
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
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_VERSION}
	cp doc/gmsh.1 doc/LICENSE doc/VERSIONS doc/FAQ doc/CREDITS gmsh-${GMSH_VERSION}
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/*/*.msh
	rm -f gmsh-${GMSH_VERSION}/*/*~
	tar cvf gmsh-${GMSH_VERSION}-${UNAME}.tar gmsh-${GMSH_VERSION}
	gzip gmsh-${GMSH_VERSION}-${UNAME}.tar
	mv gmsh-${GMSH_VERSION}-${UNAME}.tar.gz gmsh-${GMSH_VERSION}-${UNAME}.tgz

package-win:
	rm -rf gmsh-${GMSH_VERSION}
	mkdir gmsh-${GMSH_VERSION}
	strip bin/gmsh.exe
	cp /usr/bin/cygwin1.dll gmsh-${GMSH_VERSION}
	cp bin/gmsh.exe gmsh-${GMSH_VERSION}
	cp doc/README.win32 gmsh-${GMSH_VERSION}/README.txt
	cp doc/VERSIONS gmsh-${GMSH_VERSION}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_VERSION}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_VERSION}/CREDITS.txt
	cp doc/LICENSE gmsh-${GMSH_VERSION}/LICENSE.txt
	cd utils/misc && unix2dos.bash ../../gmsh-${GMSH_VERSION}/*.txt
	cp -R tutorial gmsh-${GMSH_VERSION}
	cp -R demos gmsh-${GMSH_VERSION}
	rm -rf gmsh-${GMSH_VERSION}/*/CVS
	rm -f gmsh-${GMSH_VERSION}/*/*.msh
	rm -f gmsh-${GMSH_VERSION}/*/*~
	cd utils/misc && unix2dos.bash ../../gmsh-${GMSH_VERSION}/tutorial/*\
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
        "    <key>CFBundleIconFile</key><string>gmsh.icns</string>\n"\
        "    <key>CFBundleSignature</key><string>GMSH</string>\n"\
        "    <key>CFBundleGetInfoString</key><string>Gmsh version ${GMSH_VERSION}, "\
              "Copyright (C) 1997-2004 C. Geuzaine and J.-F. Remacle</string>\n"\
        "    <key>CFBundleIdentifier</key><string>org.geuz.Gmsh</string>\n"\
        "  </dict>\n"\
        "</plist>" > gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Info.plist
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_VERSION}/Gmsh.app/Contents/MacOS/Gmsh
	cp Fltk/MacIcons.icns gmsh-${GMSH_VERSION}/Gmsh.app/Contents/Resources/gmsh.icns
	cp -R doc/gmsh.1 tutorial demos gmsh-${GMSH_VERSION}
	cp doc/VERSIONS gmsh-${GMSH_VERSION}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_VERSION}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_VERSION}/CREDITS.txt
	cp doc/LICENSE gmsh-${GMSH_VERSION}/LICENSE.txt
	rm -rf gmsh-${GMSH_VERSION}/*/CVS\
               gmsh-${GMSH_VERSION}/*/*~\
               gmsh-${GMSH_VERSION}/*/*.msh
	tar zcvf gmsh-${GMSH_VERSION}-MacOSX.tgz gmsh-${GMSH_VERSION}

package-rpm:
	tar zcvf /usr/src/redhat/SOURCES/gmsh-${GMSH_VERSION}.tar.gz ${GMSH_SOURCES}
	rpmbuild -bb --define 'gmshversion ${GMSH_VERSION}' gmsh.spec
	cp /usr/src/redhat/RPMS/i386/gmsh-${GMSH_VERSION}-?.i386.rpm .
	cp /usr/src/redhat/BUILD/gmsh-${GMSH_VERSION}/gmsh-${GMSH_VERSION}-${UNAME}.tgz .

# Rules to distribute official releases

distrib-pre:
	mv -f Makefile Makefile.distrib
	sed -e "s/^GMSH_EXTRA_VERSION.*/GMSH_EXTRA_VERSION =/g"\
          Makefile.distrib > Makefile

distrib-post:
	mv -f Makefile.distrib Makefile
	rm -f ${GMSH_VERSION_FILE}

distrib-unix: clean
	make distrib-pre
	make all
	make package-unix
	make distrib-post
	ldd bin/gmsh

distrib-win: clean
	make distrib-pre
	make all
	make package-win
	make distrib-post
	objdump -p bin/gmsh.exe | grep DLL

distrib-mac: clean
	make distrib-pre
	make all
	make package-mac
	make distrib-post
	${POSTBUILD}
	otool -L bin/gmsh

distrib-rpm:
	make distrib-pre
	make package-rpm
	make distrib-post

distrib-source:
	make distrib-pre
	make source
	make distrib-post

distrib-source-commercial:
	make distrib-pre
	make source-commercial
	make distrib-post

distrib-source-nightly:
	mv -f Makefile Makefile.distrib
	sed -e "s/^GMSH_EXTRA_VERSION.*/GMSH_EXTRA_VERSION = \"-nightly-${GMSH_DATE}\"/g"\
          Makefile.distrib > Makefile
	make source
	make distrib-post
