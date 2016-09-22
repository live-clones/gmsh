#!/bin/sh

DATE=`date "+%d/%m/%Y"`

echo "This ONELAB bundle was built on ${DATE} with the latest nightly snapshots
of Gmsh (http://gmsh.info) and GetDP (http://getdp.info).

Launch Gmsh and open a GetDP .pro file (e.g. models/magnetometer/magnetometer.pro)
with the File/Open menu, then click on \"Run\".

The software is distributed under the terms of the GNU General Public License. 
See the LICENSE and CREDITS files for more information. 

The 'models' directory contains a selection of ready-to-use examples from
http://onelab.info. The 'template' directory contains GetDP templates. The
'tutorial' directory contains the Gmsh tutorial.

See http://onelab.info, http://gmsh.info and http://getdp.info for additional
examples, up-to-date versions and documentation." > /tmp/README.txt

GMSH=svn
GETDP=svn

#GMSH=2.13.2
#GETDP=2.9.1

MODELS='machines relay inductor indheat magnetometer antennas acoustic_scattering time_reversal shielding waveguides transfo_simple ddm_waves bloch_periodic_waveguides magnets thermal_conduction magnetostriction superconductors'

# get onelab models
mkdir /tmp/models
for m in ${MODELS}; do
  curl -O http://onelab.info/files/${m}.zip
  unzip -q -o ${m}.zip -d /tmp/models
  rm -f ${m}.zip
done

if [ $# -lt 1 ] || [ $1 == "source" ]; then
  rm -rf onelab-source*
  mkdir onelab-source
  curl -O http://gmsh.info/src/gmsh-${GMSH}-source.tgz
  curl -O http://getdp.info/src/getdp-${GETDP}-source.tgz
  mv gmsh-${GMSH}-source.tgz /tmp
  mv getdp-${GETDP}-source.tgz /tmp
  tar zxvf /tmp/gmsh-${GMSH}-source.tgz -C /tmp
  tar zxvf /tmp/getdp-${GETDP}-source.tgz -C /tmp
  cp /tmp/README.txt onelab-source
  mv /tmp/gmsh-*${GMSH}*-source onelab-source
  mv /tmp/getdp-*${GETDP}*-source onelab-source
  cp onelab-source/gmsh-*${GMSH}*-source/doc/LICENSE.txt onelab-source/LICENSE.txt
  echo "\n\n" >> onelab-source/LICENSE.txt
  cat onelab-source/getdp-*${GETDP}*-source/doc/LICENSE.txt >> onelab-source/LICENSE.txt
  cp onelab-source/gmsh-*${GMSH}*-source/doc/CREDITS.txt onelab-source/CREDITS.txt
  echo "\n\n" >> onelab-source/CREDITS.txt
  cat onelab-source/getdp-*${GETDP}*-source/doc/CREDITS.txt >> onelab-source/CREDITS.txt
  cp -R /tmp/models onelab-source
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  zip -r onelab-source.zip onelab-source
  rm -rf onelab-source
fi

if [ $# -lt 1 ] || [ $1 == "win64" ]; then
  rm -rf onelab-Windows64*
  mkdir onelab-Windows64
  curl -O http://gmsh.info/bin/Windows/gmsh-${GMSH}-Windows64.zip
  curl -O http://getdp.info/bin/Windows/getdp-${GETDP}-Windows64c.zip
  mv gmsh-${GMSH}-Windows64.zip /tmp
  mv getdp-${GETDP}-Windows64c.zip /tmp
  unzip -q -o /tmp/gmsh-${GMSH}-Windows64.zip -d /tmp
  unzip -q -o /tmp/getdp-${GETDP}-Windows64c.zip -d /tmp
  cp /tmp/README.txt onelab-Windows64
  perl -pi -e 's/\n/\r\n/' onelab-Windows64/README.txt
  mv /tmp/gmsh-*${GMSH}-Windows/gmsh.exe onelab-Windows64
  mv /tmp/gmsh-*${GMSH}-Windows/onelab.py onelab-Windows64
  mv /tmp/getdp-*${GETDP}-Windows/getdp.exe onelab-Windows64
  mv /tmp/gmsh-*${GMSH}-Windows/LICENSE.txt onelab-Windows64/LICENSE.txt
  echo "\n\n" >> onelab-Windows64/LICENSE.txt
  cat /tmp/getdp-*${GETDP}-Windows/LICENSE.txt >> onelab-Windows64/LICENSE.txt
  mv /tmp/gmsh-*${GMSH}-Windows/CREDITS.txt onelab-Windows64/CREDITS.txt
  echo "\n\n" >> onelab-Windows64/CREDITS.txt
  cat /tmp/getdp-*${GETDP}-Windows/CREDITS.txt >> onelab-Windows64/CREDITS.txt
  mv /tmp/getdp-*${GETDP}-Windows/templates onelab-Windows64
  mv /tmp/gmsh-*${GMSH}-Windows/tutorial onelab-Windows64
  cp -R /tmp/models onelab-Windows64
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  zip -r onelab-Windows64.zip onelab-Windows64
  rm -rf onelab-Windows64
fi

if [ $# -lt 1 ] || [ $1 == "win32" ]; then
  rm -rf onelab-Windows32*
  mkdir onelab-Windows32
  curl -O http://gmsh.info/bin/Windows/gmsh-${GMSH}-Windows32.zip
  curl -O http://getdp.info/bin/Windows/getdp-${GETDP}-Windows32c.zip
  mv gmsh-${GMSH}-Windows32.zip /tmp
  mv getdp-${GETDP}-Windows32c.zip /tmp
  unzip -q -o /tmp/gmsh-${GMSH}-Windows32.zip -d /tmp
  unzip -q -o /tmp/getdp-${GETDP}-Windows32c.zip -d /tmp
  cp /tmp/README.txt onelab-Windows32
  perl -pi -e 's/\n/\r\n/' onelab-Windows32/README.txt
  mv /tmp/gmsh-*${GMSH}-Windows/gmsh.exe onelab-Windows32
  mv /tmp/gmsh-*${GMSH}-Windows/onelab.py onelab-Windows32
  mv /tmp/getdp-*${GETDP}-Windows/getdp.exe onelab-Windows32
  mv /tmp/gmsh-*${GMSH}-Windows/LICENSE.txt onelab-Windows32/LICENSE.txt
  echo "\n\n" >> onelab-Windows32/LICENSE.txt
  cat /tmp/getdp-*${GETDP}-Windows/LICENSE.txt >> onelab-Windows32/LICENSE.txt
  mv /tmp/gmsh-*${GMSH}-Windows/CREDITS.txt onelab-Windows32/CREDITS.txt
  echo "\n\n" >> onelab-Windows32/CREDITS.txt
  cat /tmp/getdp-*${GETDP}-Windows/CREDITS.txt >> onelab-Windows32/CREDITS.txt
  mv /tmp/getdp-*${GETDP}-Windows/templates onelab-Windows32
  mv /tmp/gmsh-*${GMSH}-Windows/tutorial onelab-Windows32
  cp -R /tmp/models onelab-Windows32
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  zip -r onelab-Windows32.zip onelab-Windows32
  rm -rf onelab-Windows32
fi

if [ $# -lt 1 ] || [ $1 == "linux32" ]; then
  rm -rf onelab-Linux32*
  mkdir onelab-Linux32
  curl -O http://gmsh.info/bin/Linux/gmsh-${GMSH}-Linux32.tgz
  curl -O http://getdp.info/bin/Linux/getdp-${GETDP}-Linux32c.tgz
  mv gmsh-${GMSH}-Linux32.tgz /tmp
  mv getdp-${GETDP}-Linux32c.tgz /tmp
  tar zxvf /tmp/gmsh-${GMSH}-Linux32.tgz -C /tmp
  tar zxvf /tmp/getdp-${GETDP}-Linux32c.tgz -C /tmp
  cp /tmp/README.txt onelab-Linux32
  mv /tmp/gmsh-*${GMSH}-Linux/bin/gmsh onelab-Linux32
  mv /tmp/gmsh-*${GMSH}-Linux/bin/onelab.py onelab-Linux32
  mv /tmp/getdp-*${GETDP}-Linux/bin/getdp onelab-Linux32
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/LICENSE.txt onelab-Linux32/LICENSE.txt
  echo "\n\n" >> onelab-Linux32/LICENSE.txt
  cat /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/LICENSE.txt >> onelab-Linux32/LICENSE.txt
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/CREDITS.txt onelab-Linux32/CREDITS.txt
  echo "\n\n" >> onelab-Linux32/CREDITS.txt
  cat /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/CREDITS.txt >> onelab-Linux32/CREDITS.txt
  mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/templates onelab-Linux32
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/tutorial onelab-Linux32
  cp -R /tmp/models onelab-Linux32
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  zip -r onelab-Linux32.zip onelab-Linux32
  rm -rf onelab-Linux32
fi

if [ $# -lt 1 ] || [ $1 == "linux64" ]; then
  rm -rf onelab-Linux64*
  mkdir onelab-Linux64
  curl -O http://gmsh.info/bin/Linux/gmsh-${GMSH}-Linux64.tgz
  curl -O http://getdp.info/bin/Linux/getdp-${GETDP}-Linux64c.tgz
  mv gmsh-${GMSH}-Linux64.tgz /tmp
  mv getdp-${GETDP}-Linux64c.tgz /tmp
  tar zxvf /tmp/gmsh-${GMSH}-Linux64.tgz -C /tmp
  tar zxvf /tmp/getdp-${GETDP}-Linux64c.tgz -C /tmp
  cp /tmp/README.txt onelab-Linux64
  mv /tmp/gmsh-*${GMSH}-Linux/bin/gmsh onelab-Linux64
  mv /tmp/gmsh-*${GMSH}-Linux/bin/onelab.py onelab-Linux64
  mv /tmp/getdp-*${GETDP}-Linux/bin/getdp onelab-Linux64
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/LICENSE.txt onelab-Linux64/LICENSE.txt
  echo "\n\n" >> onelab-Linux64/LICENSE.txt
  cat /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/LICENSE.txt >> onelab-Linux64/LICENSE.txt
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/CREDITS.txt onelab-Linux64/CREDITS.txt
  echo "\n\n" >> onelab-Linux64/CREDITS.txt
  cat /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/CREDITS.txt >> onelab-Linux64/CREDITS.txt
  mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/templates onelab-Linux64
  mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/tutorial onelab-Linux64
  cp -R /tmp/models onelab-Linux64
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  zip -r onelab-Linux64.zip onelab-Linux64
  rm -rf onelab-Linux64
fi

if [ $# -lt 1 ] || [ $1 == "mac" ]; then
  rm -rf onelab-MacOSX*
  mkdir onelab-MacOSX
  curl -O http://gmsh.info/bin/MacOSX/gmsh-${GMSH}-MacOSX.dmg
  curl -O http://getdp.info/bin/MacOSX/getdp-${GETDP}-MacOSX64c.tgz
  mv gmsh-${GMSH}-MacOSX.dmg /tmp
  mv getdp-${GETDP}-MacOSX64c.tgz /tmp
  hdiutil convert /tmp/gmsh-${GMSH}-MacOSX.dmg -format UDTO -o /tmp/gmsh-tmp.cdr
  hdiutil attach -nobrowse -noverify -noautoopen -mountpoint gmsh_mount /tmp/gmsh-tmp.cdr
  tar zxvf /tmp/getdp-${GETDP}-MacOSX64c.tgz -C /tmp
  cp /tmp/README.txt onelab-MacOSX
  cp -R gmsh_mount/Gmsh.app onelab-MacOSX
  mv /tmp/getdp-*${GETDP}-MacOSX/bin/getdp onelab-MacOSX/Gmsh.app/Contents/MacOS/
  security unlock-keychain -p "FIXME" ${HOME}/Library/Keychains/login.keychain
  codesign -v --force --deep --sign "Developer ID Application: Christophe Geuzaine" onelab-MacOSX/Gmsh.app
  cp gmsh_mount/LICENSE.txt onelab-MacOSX/LICENSE.txt
  echo "\n\n" >> onelab-MacOSX/LICENSE.txt
  cat /tmp/getdp-*${GETDP}-MacOSX/share/doc/getdp/LICENSE.txt >> onelab-MacOSX/LICENSE.txt
  cp gmsh_mount/CREDITS.txt onelab-MacOSX/CREDITS.txt
  echo "\n\n" >> onelab-MacOSX/CREDITS.txt
  cat /tmp/getdp-*${GETDP}-MacOSX/share/doc/getdp/CREDITS.txt >> onelab-MacOSX/CREDITS.txt
  mv /tmp/getdp-*${GETDP}-MacOSX/share/doc/getdp/templates onelab-MacOSX
  cp -R gmsh_mount/tutorial onelab-MacOSX
  cp -R /tmp/models onelab-MacOSX
  umount gmsh_mount
  rm -rf /tmp/gmsh-*
  rm -rf /tmp/getdp-*
  # if we use a zip file we need to move onelab.py from MacOS/ to Resources/, as zip
  # does not preserve extended file attributes; dmg does
  hdiutil create -srcfolder onelab-MacOSX onelab-MacOSX.dmg
  codesign -v --sign "Developer ID Application: Christophe Geuzaine" onelab-MacOSX.dmg
  rm -rf onelab-MacOSX
fi

rm -rf /tmp/models
