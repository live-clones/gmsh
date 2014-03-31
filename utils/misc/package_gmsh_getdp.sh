#!/bin/sh

DATE=`date "+%d/%m/%Y"`

echo "This archive was built on ${DATE} with the latest nightly snapshots of
Gmsh (http://gmsh.info) and GetDP (http://getdp.info).

Both Gmsh and GetDP are distributed under the terms of the GNU General Public
License. See the LICENSE and CREDITS files for more information. 

See the official websites http://gmsh.info and http://getdp.info for
up-to-date versions, documentation and examples." > /tmp/README.txt

GMSH=svn
GETDP=svn

#GMSH=2.8.4
#GETDP=2.4.3

rm -rf gmsh-getdp-Windows64
mkdir gmsh-getdp-Windows64
curl -O http://geuz.org/gmsh/bin/Windows/gmsh-${GMSH}-Windows64.zip
curl -O http://geuz.org/getdp/bin/Windows/getdp-${GETDP}-Windows64c.zip
mv gmsh-${GMSH}-Windows64.zip /tmp
mv getdp-${GETDP}-Windows64c.zip /tmp
unzip -q -o /tmp/gmsh-${GMSH}-Windows64.zip -d /tmp
unzip -q -o /tmp/getdp-${GETDP}-Windows64c.zip -d /tmp
cp /tmp/README.txt gmsh-getdp-Windows64
mv /tmp/gmsh-*${GMSH}-Windows/gmsh.exe gmsh-getdp-Windows64
mv /tmp/gmsh-*${GMSH}-Windows/onelab.py gmsh-getdp-Windows64
mv /tmp/getdp-*${GETDP}-Windows/getdp.exe gmsh-getdp-Windows64
mv /tmp/gmsh-*${GMSH}-Windows/LICENSE.txt gmsh-getdp-Windows64/LICENSE_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Windows/LICENSE.txt gmsh-getdp-Windows64/LICENSE_GetDP.txt
mv /tmp/gmsh-*${GMSH}-Windows/CREDITS.txt gmsh-getdp-Windows64/CREDITS_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Windows/CREDITS.txt gmsh-getdp-Windows64/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Windows64.zip gmsh-getdp-Windows64
rm -rf gmsh-getdp-Windows64

rm -rf gmsh-getdp-Windows32
mkdir gmsh-getdp-Windows32
curl -O http://geuz.org/gmsh/bin/Windows/gmsh-${GMSH}-Windows.zip
curl -O http://geuz.org/getdp/bin/Windows/getdp-${GETDP}-Windows32c.zip
mv gmsh-${GMSH}-Windows.zip /tmp
mv getdp-${GETDP}-Windows32c.zip /tmp
unzip -q -o /tmp/gmsh-${GMSH}-Windows.zip -d /tmp
unzip -q -o /tmp/getdp-${GETDP}-Windows32c.zip -d /tmp
cp /tmp/README.txt gmsh-getdp-Windows32
mv /tmp/gmsh-*${GMSH}-Windows/gmsh.exe gmsh-getdp-Windows32
mv /tmp/gmsh-*${GMSH}-Windows/onelab.py gmsh-getdp-Windows32
mv /tmp/getdp-*${GETDP}-Windows/getdp.exe gmsh-getdp-Windows32
mv /tmp/gmsh-*${GMSH}-Windows/LICENSE.txt gmsh-getdp-Windows32/LICENSE_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Windows/LICENSE.txt gmsh-getdp-Windows32/LICENSE_GetDP.txt
mv /tmp/gmsh-*${GMSH}-Windows/CREDITS.txt gmsh-getdp-Windows32/CREDITS_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Windows/CREDITS.txt gmsh-getdp-Windows32/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Windows32.zip gmsh-getdp-Windows32
rm -rf gmsh-getdp-Windows32

rm -rf gmsh-getdp-Linux32
mkdir gmsh-getdp-Linux32
curl -O http://geuz.org/gmsh/bin/Linux/gmsh-${GMSH}-Linux.tgz
curl -O http://geuz.org/getdp/bin/Linux/getdp-${GETDP}-Linux32c.tgz
mv gmsh-${GMSH}-Linux.tgz /tmp
mv getdp-${GETDP}-Linux32c.tgz /tmp
tar zxvf /tmp/gmsh-${GMSH}-Linux.tgz -C /tmp
tar zxvf /tmp/getdp-${GETDP}-Linux32c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-Linux32
mv /tmp/gmsh-*${GMSH}-Linux/bin/gmsh gmsh-getdp-Linux32
mv /tmp/gmsh-*${GMSH}-Linux/bin/onelab.py gmsh-getdp-Linux32
mv /tmp/getdp-*${GETDP}-Linux/bin/getdp gmsh-getdp-Linux32
mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/LICENSE.txt gmsh-getdp-Linux32/LICENSE_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/LICENSE.txt gmsh-getdp-Linux32/LICENSE_GetDP.txt
mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/CREDITS.txt gmsh-getdp-Linux32/CREDITS_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/CREDITS.txt gmsh-getdp-Linux32/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Linux32.zip gmsh-getdp-Linux32
rm -rf gmsh-getdp-Linux32

rm -rf gmsh-getdp-Linux64
mkdir gmsh-getdp-Linux64
curl -O http://geuz.org/gmsh/bin/Linux/gmsh-${GMSH}-Linux64.tgz
curl -O http://geuz.org/getdp/bin/Linux/getdp-${GETDP}-Linux64c.tgz
mv gmsh-${GMSH}-Linux64.tgz /tmp
mv getdp-${GETDP}-Linux64c.tgz /tmp
tar zxvf /tmp/gmsh-${GMSH}-Linux64.tgz -C /tmp
tar zxvf /tmp/getdp-${GETDP}-Linux64c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-Linux64
mv /tmp/gmsh-*${GMSH}-Linux/bin/gmsh gmsh-getdp-Linux64
mv /tmp/gmsh-*${GMSH}-Linux/bin/onelab.py gmsh-getdp-Linux64
mv /tmp/getdp-*${GETDP}-Linux/bin/getdp gmsh-getdp-Linux64
mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/LICENSE.txt gmsh-getdp-Linux64/LICENSE_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/LICENSE.txt gmsh-getdp-Linux64/LICENSE_GetDP.txt
mv /tmp/gmsh-*${GMSH}-Linux/share/doc/gmsh/CREDITS.txt gmsh-getdp-Linux64/CREDITS_Gmsh.txt
mv /tmp/getdp-*${GETDP}-Linux/share/doc/getdp/CREDITS.txt gmsh-getdp-Linux64/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Linux64.zip gmsh-getdp-Linux64
rm -rf gmsh-getdp-Linux64

rm -rf gmsh-getdp-MacOSX
mkdir gmsh-getdp-MacOSX
curl -O http://geuz.org/gmsh/bin/MacOSX/gmsh-${GMSH}-MacOSX.dmg
curl -O http://geuz.org/getdp/bin/MacOSX/getdp-${GETDP}-MacOSX64c.tgz
mv gmsh-${GMSH}-MacOSX.dmg /tmp
mv getdp-${GETDP}-MacOSX64c.tgz /tmp
# open -W /tmp/gmsh-${GMSH}-MacOSX.dmg
hdiutil convert /tmp/gmsh-${GMSH}-MacOSX.dmg -format UDTO -o /tmp/gmsh-tmp.cdr
hdiutil attach -nobrowse -noverify -noautoopen -mountpoint gmsh_mount /tmp/gmsh-tmp.cdr
tar zxvf /tmp/getdp-${GETDP}-MacOSX64c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-MacOSX
cp -R gmsh_mount/Gmsh.app gmsh-getdp-MacOSX
mv /tmp/getdp-*${GETDP}-MacOSX/bin/getdp gmsh-getdp-MacOSX/Gmsh.app/Contents/MacOS/
cp gmsh_mount/LICENSE.txt gmsh-getdp-MacOSX/LICENSE_Gmsh.txt
mv /tmp/getdp-*${GETDP}-MacOSX/share/doc/getdp/LICENSE.txt gmsh-getdp-MacOSX/LICENSE_GetDP.txt
cp gmsh_mount/CREDITS.txt gmsh-getdp-MacOSX/CREDITS_Gmsh.txt
mv /tmp/getdp-*${GETDP}-MacOSX/share/doc/getdp/CREDITS.txt gmsh-getdp-MacOSX/CREDITS_GetDP.txt
umount gmsh_mount
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-MacOSX.zip gmsh-getdp-MacOSX
rm -rf gmsh-getdp-MacOSX
