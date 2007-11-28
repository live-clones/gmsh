#
# makefile to create the nightly builds
#

# finish the rules even if we encounter errors?
# .IGNORE:

# be quiet?
.SILENT: gmsh-update gmsh-windows-nightly gmsh-linux-nightly gmsh-mac-nightly

GMSH=${HOME}/src/gmsh
LOG=${GMSH}/nightly.log
WEB_BIN=geuzaine@geuz.org:/home/www/geuz.org/gmsh/bin

gmsh-update:
	rm -f ${LOG}
	rm -f ${GMSH}/Makefile*
	echo "BUILD BEGIN: `date`" > ${LOG}
	cd ${GMSH} && export CVS_RSH=ssh && cvs update -dPA >> ${LOG} 2>&1
	cd ${GMSH} && ./configure --enable-universal --disable-fm\
                                  --with-occ-prefix=/usr/local/opencascade\
                                  --with-fltk-prefix=/usr/local >> ${LOG} 2>&1
	cd ${GMSH} && rm -rf gmsh-*cvs*
	cd ${GMSH} && make clean >> ${LOG} 2>&1

gmsh-windows-nightly: gmsh-update
	cd ${GMSH} && make distrib-win-nightly >> ${LOG} 2>&1
	scp ${GMSH}/gmsh-*cvs*.zip ${WEB_BIN}/Windows/gmsh-nightly-Windows.zip
	echo "BUILD END: `date`" >> ${LOG}
	scp ${LOG} ${WEB_BIN}/Windows/

gmsh-linux-nightly: gmsh-update
	cd ${GMSH} && make distrib-unix-nightly >> ${LOG} 2>&1
	scp ${GMSH}/gmsh-*cvs*.tgz ${WEB_BIN}/Linux/gmsh-nightly-Linux.tgz
	echo "BUILD END: `date`" >> ${LOG}
	scp ${LOG} ${WEB_BIN}/Linux/

gmsh-mac-nightly: gmsh-update
	cd ${GMSH} && make distrib-mac-nightly >> ${LOG} 2>&1
	scp ${GMSH}/gmsh-*cvs*.tgz ${WEB_BIN}/MacOSX/gmsh-nightly-MacOSX.tgz
	echo "BUILD END: `date`" >> ${LOG}
	scp ${LOG} ${WEB_BIN}/MacOSX/
