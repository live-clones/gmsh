# $Id: Makefile,v 1.255 2003-02-11 09:18:48 geuzaine Exp $

include variables

GMSH_MAJOR_VERSION = 1
GMSH_MINOR_VERSION = 38
GMSH_PATCH_VERSION = 0

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
	${LINKER} -o bin/gmsh ${GMSH_LIBS}
	${POSTBUILD}

install: variables
	-mkdir -p ${bindir}
	-cp bin/gmsh${EXEEXT} ${bindir}
	-chmod 755 ${bindir}/gmsh${EXEEXT}
	-mkdir -p ${mandir}/man1
	-cp doc/gmsh.1 ${mandir}/man1

variables: configure
	@echo "*******************************************************************"
	@echo "Please configure Gmsh by running ./configure"
	@echo "For help, type ./configure --help"
	@echo "*******************************************************************"
	@exit 1

source:
	tar zcvf gmsh.tgz `ls README* Makefile */Makefile */*.[chyl] */*.[ch]pp\
                           */*.rc */*.res */*.ico */*.icns */*.pl */*.pm */*.opt */*.spec`\
                           doc demos tutorial
	mkdir gmsh-${GMSH_RELEASE}
	cd gmsh-${GMSH_RELEASE} && tar zxvf ../gmsh.tgz
	rm -f gmsh.tgz
	cd gmsh-${GMSH_RELEASE} && rm -rf CVS */CVS */*/CVS */.globalrc ${GMSH_VERSION_FILE}
	tar zcvf gmsh-${GMSH_RELEASE}-source.tgz gmsh-${GMSH_RELEASE}
	rm -rf gmsh-${GMSH_RELEASE}

parser:
	cd Parser && ${MAKE} parser

utilities:
	cd utils && ${MAKE}

purge:
	for i in . lib archives demos tutorial doc ${GMSH_DIRS}; \
        do (cd $$i && rm -f *~ *~~ .gmsh-tmp .gmsh-errors gmon.out); \
        done

clean:
	for i in doc lib ${GMSH_DIRS}; \
        do (cd $$i && ${MAKE} clean); \
        done
	rm -f ${GMSH_VERSION_FILE}

depend:
	for i in ${GMSH_DIRS}; do (cd $$i && ${MAKE} depend ); done

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
	echo "#define GMSH_VERSION  ((double}GMSH_MAJOR_VERSION + \\" >> ${GMSH_VERSION_FILE}
	echo "                0.01 * (double}GMSH_MINOR_VERSION + \\" >> ${GMSH_VERSION_FILE}
	echo "              0.0001 * (double}GMSH_PATCH_VERSION}"     >> ${GMSH_VERSION_FILE}
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

distrib-unix:
	rm -rf gmsh-${GMSH_RELEASE}
	mkdir gmsh-${GMSH_RELEASE}
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_RELEASE}
	strip bin/gmsh-batch
	cp bin/gmsh-batch gmsh-${GMSH_RELEASE}
	cp doc/COPYING doc/gmsh.1 doc/FORMATS doc/VERSIONS doc/FAQ doc/CONTRIBUTORS gmsh-${GMSH_RELEASE}
	cp -R tutorial gmsh-${GMSH_RELEASE}
	cp -R demos gmsh-${GMSH_RELEASE}
	rm -rf gmsh-${GMSH_RELEASE}/*/CVS
	rm -f gmsh-${GMSH_RELEASE}/*/*.msh
	rm -f gmsh-${GMSH_RELEASE}/*/*~
	tar cvf gmsh-${GMSH_RELEASE}-${UNAME}.tar gmsh-${GMSH_RELEASE}
	gzip gmsh-${GMSH_RELEASE}-${UNAME}.tar
	mv gmsh-${GMSH_RELEASE}-${UNAME}.tar.gz gmsh-${GMSH_RELEASE}-${UNAME}.tgz

distrib-windows:
	strip bin/gmsh.exe
	cp bin/gmsh.exe ../gmsh-distrib
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
	cd ../gmsh-distrib && zip -r gmsh-${GMSH_RELEASE}-Windows.zip *
	mv ../gmsh-distrib/gmsh-${GMSH_RELEASE}-Windows.zip .
	rm -rf ../gmsh-distrib/*.txt
	rm -rf ../gmsh-distrib/tutorial
	rm -rf ../gmsh-distrib/demos

distrib-mac:
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
        "    <key>NSHelpFile</key><string>tutorial.html</string>\n"\
        "  </dict>\n"\
        "</plist>" > gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Info.plist
	strip bin/gmsh
	cp bin/gmsh gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/MacOS/Gmsh
	cp Fltk/MacIcons.icns gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Resources/gmsh.icns
	cp tutorial/tutorial.html gmsh-${GMSH_RELEASE}/Gmsh.app/Contents/Resources
	cp -R doc/gmsh.1 tutorial demos gmsh-${GMSH_RELEASE}
	cp doc/FORMATS gmsh-${GMSH_RELEASE}/FORMATS.txt
	cp doc/VERSIONS gmsh-${GMSH_RELEASE}/VERSIONS.txt
	cp doc/FAQ gmsh-${GMSH_RELEASE}/FAQ.txt
	cp doc/CONTRIBUTORS gmsh-${GMSH_RELEASE}/CONTRIBUTORS.txt
	rm -rf gmsh-${GMSH_RELEASE}/*/CVS\
               gmsh-${GMSH_RELEASE}/*/*~\
               gmsh-${GMSH_RELEASE}/*/*.msh
	tar zcvf gmsh-${GMSH_RELEASE}-MacOSX.tgz gmsh-${GMSH_RELEASE}

rpm:
	tar zcvf gmsh-${GMSH_RELEASE}.tar.gz ${GMSH_SOURCES}
	mv gmsh-${GMSH_RELEASE}.tar.gz /usr/src/redhat/SOURCES
	rpm -bb --define 'gmshversion ${GMSH_RELEASE}' utils/gmsh.spec
	cp /usr/src/redhat/RPMS/i386/gmsh-${GMSH_RELEASE}-?.i386.rpm .
	cp /usr/src/redhat/BUILD/gmsh-${GMSH_RELEASE}/gmsh-${GMSH_RELEASE}-${UNAME}.tgz .

