# $Id: Makefile,v 1.295 2003-07-23 17:57:42 geuzaine Exp $
#
# Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
# Please report all bugs and problems to "gmsh@geuz.org".

include variables

GMSH_MAJOR_VERSION = 1
GMSH_MINOR_VERSION = 45
GMSH_PATCH_VERSION = 2

GMSH_VERSION_FILE = Common/GmshVersion.h
GMSH_RELEASE = ${GMSH_MAJOR_VERSION}.${GMSH_MINOR_VERSION}.${GMSH_PATCH_VERSION}
GMSH_ARCHIVE = archives/gmsh-`date "+%Y.%m.%d"`
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

source-common:
	rm -rf gmsh-${GMSH_RELEASE}
	tar zcvf gmsh.tgz `ls TODO README* */README* configure *.in *.spec Makefile\
                           */Makefile */*.[chylr] */*.[ch]pp */*.rc */*.res */*.ico\
                           */*.icns`\
                           doc demos tutorial utils
	mkdir gmsh-${GMSH_RELEASE}
	cd gmsh-${GMSH_RELEASE} && tar zxvf ../gmsh.tgz
	rm -f gmsh.tgz

source: source-common
	cd gmsh-${GMSH_RELEASE} && rm -rf CVS */CVS */*/CVS */.globalrc ${GMSH_VERSION_FILE}\
           NR Triangle/triangle.*
	tar zcvf gmsh-${GMSH_RELEASE}-source.tgz gmsh-${GMSH_RELEASE}

source-nonfree: source-common
	cd gmsh-${GMSH_RELEASE} && rm -rf CVS */CVS */*/CVS */.globalrc ${GMSH_VERSION_FILE}
	tar zcvf gmsh-${GMSH_RELEASE}-source-nonfree.tgz gmsh-${GMSH_RELEASE}

parser:
	cd Parser && ${MAKE} parser

converters:
	cd utils/converters/autocad && ${MAKE}

.PHONY: doc
doc:
	cd doc/texinfo && ${MAKE} all
	cd doc && tar zcvf ../gmsh-${GMSH_RELEASE}-doc.tgz\
          FAQ CREDITS VERSIONS README.win32 gmsh.1\
          texinfo/gmsh.ps texinfo/gmsh.pdf texinfo/gmsh.txt\
          texinfo/*.html texinfo/gmsh-info.tgz

doc-info:
	cd doc/texinfo && ${MAKE} info

purge:
	for i in . bin lib utils archives demos tutorial doc doc/texinfo ${GMSH_DIRS}; \
        do (cd $$i && rm -f *~ *~~ .gmsh-tmp .gmsh-errors gmon.out); \
        done

clean:
	for i in doc lib ${GMSH_DIRS}; do (cd $$i && ${MAKE} clean); done
	rm -f ${GMSH_VERSION_FILE}

depend:
	for i in ${GMSH_DIRS}; do (cd $$i && ${MAKE} depend "FLAGS=-DHAVE_GSL -DHAVE_FLTK"); done

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
	echo "#define GMSH_VERSION  ((double)GMSH_MAJOR_VERSION + \\" >> ${GMSH_VERSION_FILE}
	echo "                0.01 * (double)GMSH_MINOR_VERSION + \\" >> ${GMSH_VERSION_FILE}
	echo "              0.0001 * (double)GMSH_PATCH_VERSION)"     >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_DATE     \"`date`\""      >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_HOST     \"`hostname`\""  >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_PACKAGER \"`whoami`\""    >> ${GMSH_VERSION_FILE}
	echo "#define GMSH_OS       \"`uname -sr`\"" >> ${GMSH_VERSION_FILE}

initialtag:
	@if [ ! -r ${GMSH_VERSION_FILE} ]; then ${MAKE} tag ; fi

tags:
	gtags
	htags

tgz:
	if (test -f ${GMSH_ARCHIVE}.tar.gz); then \
	  mv -f ${GMSH_ARCHIVE}.tar.gz ${GMSH_ARCHIVE}.tar.gz~; \
	fi
	tar cvf ${GMSH_ARCHIVE}.tar ${GMSH_SOURCES}
	gzip ${GMSH_ARCHIVE}.tar
	chmod 640 ${GMSH_ARCHIVE}.tar.gz

minizip:
	tar jcvf gmsh-`date "+%Y.%m.%d"`.tar.bz2 \
        `ls Makefile */Makefile */*.[chyl] */*.[ch]pp */*.rc */*.res */*.ico`

distrib-msg:
	@echo "********************************************************************"
	@echo "Remember to change -ljpeg, etc. to /usr/lib/libjpeg.a, etc. in"
	@echo "./variables and relink if the list below contains non-standard"
	@echo "dynamic libs and you want to distribute a portable binary:"
	@echo "********************************************************************"

distrib-unix: clean all package-unix distrib-msg
	ldd bin/gmsh

distrib-win: clean all package-win distrib-msg
	objdump -p bin/gmsh.exe | grep DLL

distrib-mac: clean all package-mac distrib-msg
	otool -L bin/gmsh

package-unix:
	rm -rf gmsh-${GMSH_RELEASE}
	mkdir gmsh-${GMSH_RELEASE}
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_RELEASE}
	cp doc/gmsh.1 doc/COPYING doc/VERSIONS doc/FAQ doc/CREDITS gmsh-${GMSH_RELEASE}
	cp -R tutorial gmsh-${GMSH_RELEASE}
	cp -R demos gmsh-${GMSH_RELEASE}
	rm -rf gmsh-${GMSH_RELEASE}/*/CVS
	rm -f gmsh-${GMSH_RELEASE}/*/*.msh
	rm -f gmsh-${GMSH_RELEASE}/*/*~
	tar cvf gmsh-${GMSH_RELEASE}-${UNAME}.tar gmsh-${GMSH_RELEASE}
	gzip gmsh-${GMSH_RELEASE}-${UNAME}.tar
	mv gmsh-${GMSH_RELEASE}-${UNAME}.tar.gz gmsh-${GMSH_RELEASE}-${UNAME}.tgz

package-win:
	rm -rf gmsh-${GMSH_RELEASE}
	mkdir gmsh-${GMSH_RELEASE}
	strip bin/gmsh.exe
	cp /usr/bin/cygwin1.dll gmsh-${GMSH_RELEASE}
	cp bin/gmsh.exe gmsh-${GMSH_RELEASE}
	cp doc/README.win32 gmsh-${GMSH_RELEASE}/README.txt
	cp doc/VERSIONS gmsh-${GMSH_RELEASE}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_RELEASE}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_RELEASE}/CREDITS.txt
	cp doc/COPYING gmsh-${GMSH_RELEASE}/COPYING.txt
	cd utils/misc && unix2dos.bash ../../gmsh-${GMSH_RELEASE}/*.txt
	cp -R tutorial gmsh-${GMSH_RELEASE}
	cp -R demos gmsh-${GMSH_RELEASE}
	rm -rf gmsh-${GMSH_RELEASE}/*/CVS
	rm -f gmsh-${GMSH_RELEASE}/*/*.msh
	rm -f gmsh-${GMSH_RELEASE}/*/*~
	cd utils/misc && unix2dos.bash ../../gmsh-${GMSH_RELEASE}/tutorial/*\
                                       ../../gmsh-${GMSH_RELEASE}/demos/*
	cd gmsh-${GMSH_RELEASE} && zip -r gmsh-${GMSH_RELEASE}-Windows.zip *
	mv gmsh-${GMSH_RELEASE}/gmsh-${GMSH_RELEASE}-Windows.zip .

package-mac:
	rm -rf gmsh-${GMSH_RELEASE}
	mkdir gmsh-${GMSH_RELEASE}
	mkdir gmsh-${GMSH_RELEASE}/Gmsh.app
	mkdir gmsh-${GMSH_RELEASE}/Gmsh.app/Contents
	mkdir gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Resources
	mkdir gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/MacOS
	echo "APPLGMSH" > gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/PkgInfo 
	echo -e "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"\
        "<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\""\
                              " \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n"\
        "<plist version=\"1.0\">\n"\
        "  <dict>\n"\
        "    <key>CFBundleName</key><string>Gmsh</string>\n"\
        "    <key>CFBundleExecutable</key><string>Gmsh</string>\n"\
        "    <key>CFBundlePackageType</key><string>APPL</string>\n"\
        "    <key>CFBundleVersion</key><string>${GMSH_RELEASE}</string>\n"\
        "    <key>CFBundleShortVersionString</key><string>${GMSH_RELEASE}</string>\n"\
        "    <key>CFBundleIconFile</key><string>gmsh.icns</string>\n"\
        "    <key>CFBundleSignature</key><string>GMSH</string>\n"\
        "    <key>CFBundleGetInfoString</key><string>Gmsh ${GMSH_RELEASE},"\
              "(c) C. Geuzaine and J.-F. Remacle, 1997-2003</string>\n"\
        "    <key>CFBundleIdentifier</key><string>org.geuz.Gmsh</string>\n"\
        "  </dict>\n"\
        "</plist>" > gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Info.plist
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/MacOS/Gmsh
	cp Fltk/MacIcons.icns gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Resources/gmsh.icns
	cp -R doc/gmsh.1 tutorial demos gmsh-${GMSH_RELEASE}
	cp doc/VERSIONS gmsh-${GMSH_RELEASE}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_RELEASE}/FAQ.txt
	cp doc/CREDITS gmsh-${GMSH_RELEASE}/CREDITS.txt
	cp doc/COPYING gmsh-${GMSH_RELEASE}/COPYING.txt
	rm -rf gmsh-${GMSH_RELEASE}/*/CVS\
               gmsh-${GMSH_RELEASE}/*/*~\
               gmsh-${GMSH_RELEASE}/*/*.msh
	tar zcvf gmsh-${GMSH_RELEASE}-MacOSX.tgz gmsh-${GMSH_RELEASE}

rpmold:
	tar zcvf gmsh-${GMSH_RELEASE}.tar.gz ${GMSH_SOURCES}
	mv gmsh-${GMSH_RELEASE}.tar.gz /usr/src/redhat/SOURCES
	rpm -bb --define 'gmshversion ${GMSH_RELEASE}' gmsh.spec
	cp /usr/src/redhat/RPMS/i386/gmsh-${GMSH_RELEASE}-?.i386.rpm .
	cp /usr/src/redhat/BUILD/gmsh-${GMSH_RELEASE}/gmsh-${GMSH_RELEASE}-${UNAME}.tgz .

rpm:
	tar zcvf gmsh-${GMSH_RELEASE}.tar.gz ${GMSH_SOURCES}
	mv gmsh-${GMSH_RELEASE}.tar.gz /usr/src/redhat/SOURCES
	rpmbuild -bb --define 'gmshversion ${GMSH_RELEASE}' gmsh.spec
	cp /usr/src/redhat/RPMS/i386/gmsh-${GMSH_RELEASE}-?.i386.rpm .
	cp /usr/src/redhat/BUILD/gmsh-${GMSH_RELEASE}/gmsh-${GMSH_RELEASE}-${UNAME}.tgz .
