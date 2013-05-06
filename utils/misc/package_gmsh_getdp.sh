#!/bin/sh

DATE=`date "+%d/%m/%Y"`

echo "This archive was built on ${DATE} with the latest nightly snapshots of
Gmsh (http://geuz.org/gmsh) and GetDP (http://geuz.org/getdp).

Both Gmsh and GetDP are distributed under the terms of the GNU General Public
License. See the LICENSE_*.txt and CREDITS_*.txt files for more information. 

See the official websites http://geuz.org/gmsh and http://geuz.org/getdp for
up-to-date versions, documentation and examples." > /tmp/README.txt

rm -rf gmsh-getdp-Windows64
mkdir gmsh-getdp-Windows64
curl -O http://geuz.org/gmsh/bin/Windows/gmsh-svn-Windows64.zip
curl -O http://geuz.org/getdp/bin/Windows/getdp-svn-Windows64c.zip
mv gmsh-svn-Windows64.zip /tmp
mv getdp-svn-Windows64c.zip /tmp
unzip -q -o /tmp/gmsh-svn-Windows64.zip -d /tmp
unzip -q -o /tmp/getdp-svn-Windows64c.zip -d /tmp
cp /tmp/README.txt gmsh-getdp-Windows64
mv /tmp/gmsh-*-svn-Windows/gmsh.exe gmsh-getdp-Windows64
mv /tmp/gmsh-*-svn-Windows/onelab.py gmsh-getdp-Windows64
mv /tmp/getdp-*-svn-Windows/getdp.exe gmsh-getdp-Windows64
mv /tmp/gmsh-*-svn-Windows/LICENSE.txt gmsh-getdp-Windows64/LICENSE_Gmsh.txt
mv /tmp/getdp-*-svn-Windows/LICENSE.txt gmsh-getdp-Windows64/LICENSE_GetDP.txt
mv /tmp/gmsh-*-svn-Windows/CREDITS.txt gmsh-getdp-Windows64/CREDITS_Gmsh.txt
mv /tmp/getdp-*-svn-Windows/CREDITS.txt gmsh-getdp-Windows64/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Windows64.zip gmsh-getdp-Windows64
rm -rf gmsh-getdp-Windows64

rm -rf gmsh-getdp-Windows32
mkdir gmsh-getdp-Windows32
curl -O http://geuz.org/gmsh/bin/Windows/gmsh-svn-Windows.zip
curl -O http://geuz.org/getdp/bin/Windows/getdp-svn-Windows32c.zip
mv gmsh-svn-Windows.zip /tmp
mv getdp-svn-Windows32c.zip /tmp
unzip -q -o /tmp/gmsh-svn-Windows.zip -d /tmp
unzip -q -o /tmp/getdp-svn-Windows32c.zip -d /tmp
cp /tmp/README.txt gmsh-getdp-Windows32
mv /tmp/gmsh-*-svn-Windows/gmsh.exe gmsh-getdp-Windows32
mv /tmp/gmsh-*-svn-Windows/onelab.py gmsh-getdp-Windows32
mv /tmp/getdp-*-svn-Windows/getdp.exe gmsh-getdp-Windows32
mv /tmp/gmsh-*-svn-Windows/LICENSE.txt gmsh-getdp-Windows32/LICENSE_Gmsh.txt
mv /tmp/getdp-*-svn-Windows/LICENSE.txt gmsh-getdp-Windows32/LICENSE_GetDP.txt
mv /tmp/gmsh-*-svn-Windows/CREDITS.txt gmsh-getdp-Windows32/CREDITS_Gmsh.txt
mv /tmp/getdp-*-svn-Windows/CREDITS.txt gmsh-getdp-Windows32/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Windows32.zip gmsh-getdp-Windows32
rm -rf gmsh-getdp-Windows32

rm -rf gmsh-getdp-Linux32
mkdir gmsh-getdp-Linux32
curl -O http://geuz.org/gmsh/bin/Linux/gmsh-svn-Linux.tgz
curl -O http://geuz.org/getdp/bin/Linux/getdp-svn-Linux32c.tgz
mv gmsh-svn-Linux.tgz /tmp
mv getdp-svn-Linux32c.tgz /tmp
tar zxvf /tmp/gmsh-svn-Linux.tgz -C /tmp
tar zxvf /tmp/getdp-svn-Linux32c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-Linux32
mv /tmp/gmsh-*-svn-Linux/bin/gmsh gmsh-getdp-Linux32
mv /tmp/gmsh-*-svn-Linux/bin/onelab.py gmsh-getdp-Linux32
mv /tmp/getdp-*-svn-Linux/bin/getdp gmsh-getdp-Linux32
mv /tmp/gmsh-*-svn-Linux/share/doc/gmsh/LICENSE.txt gmsh-getdp-Linux32/LICENSE_Gmsh.txt
mv /tmp/getdp-*-svn-Linux/share/doc/getdp/LICENSE.txt gmsh-getdp-Linux32/LICENSE_GetDP.txt
mv /tmp/gmsh-*-svn-Linux/share/doc/gmsh/CREDITS.txt gmsh-getdp-Linux32/CREDITS_Gmsh.txt
mv /tmp/getdp-*-svn-Linux/share/doc/getdp/CREDITS.txt gmsh-getdp-Linux32/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Linux32.zip gmsh-getdp-Linux32
rm -rf gmsh-getdp-Linux32

rm -rf gmsh-getdp-Linux64
mkdir gmsh-getdp-Linux64
curl -O http://geuz.org/gmsh/bin/Linux/gmsh-svn-Linux64.tgz
curl -O http://geuz.org/getdp/bin/Linux/getdp-svn-Linux64c.tgz
mv gmsh-svn-Linux64.tgz /tmp
mv getdp-svn-Linux64c.tgz /tmp
tar zxvf /tmp/gmsh-svn-Linux64.tgz -C /tmp
tar zxvf /tmp/getdp-svn-Linux64c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-Linux64
mv /tmp/gmsh-*-svn-Linux/bin/gmsh gmsh-getdp-Linux64
mv /tmp/gmsh-*-svn-Linux/bin/onelab.py gmsh-getdp-Linux64
mv /tmp/getdp-*-svn-Linux/bin/getdp gmsh-getdp-Linux64
mv /tmp/gmsh-*-svn-Linux/share/doc/gmsh/LICENSE.txt gmsh-getdp-Linux64/LICENSE_Gmsh.txt
mv /tmp/getdp-*-svn-Linux/share/doc/getdp/LICENSE.txt gmsh-getdp-Linux64/LICENSE_GetDP.txt
mv /tmp/gmsh-*-svn-Linux/share/doc/gmsh/CREDITS.txt gmsh-getdp-Linux64/CREDITS_Gmsh.txt
mv /tmp/getdp-*-svn-Linux/share/doc/getdp/CREDITS.txt gmsh-getdp-Linux64/CREDITS_GetDP.txt
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-Linux64.zip gmsh-getdp-Linux64
rm -rf gmsh-getdp-Linux64

rm -rf gmsh-getdp-MacOSX
mkdir gmsh-getdp-MacOSX
curl -O http://geuz.org/gmsh/bin/MacOSX/gmsh-svn-MacOSX.dmg
curl -O http://geuz.org/getdp/bin/MacOSX/getdp-svn-MacOSX64c.tgz
mv gmsh-svn-MacOSX.dmg /tmp
mv getdp-svn-MacOSX64c.tgz /tmp
open -W /tmp/gmsh-svn-MacOSX.dmg
tar zxvf /tmp/getdp-svn-MacOSX64c.tgz -C /tmp
cp /tmp/README.txt gmsh-getdp-MacOSX
cp -R /Volumes/gmsh-*-svn-MacOSX/Gmsh.app gmsh-getdp-MacOSX
mv /tmp/getdp-*-svn-MacOSX/bin/getdp gmsh-getdp-MacOSX/Gmsh.app/Contents/MacOS/
cp /Volumes/gmsh-*-svn-MacOSX/LICENSE.txt gmsh-getdp-MacOSX/LICENSE_Gmsh.txt
mv /tmp/getdp-*-svn-MacOSX/share/doc/getdp/LICENSE.txt gmsh-getdp-MacOSX/LICENSE_GetDP.txt
cp /Volumes/gmsh-*-svn-MacOSX/CREDITS.txt gmsh-getdp-MacOSX/CREDITS_Gmsh.txt
mv /tmp/getdp-*-svn-MacOSX/share/doc/getdp/CREDITS.txt gmsh-getdp-MacOSX/CREDITS_GetDP.txt
umount /Volumes/gmsh-*-svn-MacOSX
rm -rf /tmp/gmsh-*
rm -rf /tmp/getdp-*
zip -r gmsh-getdp-MacOSX.zip gmsh-getdp-MacOSX
rm -rf gmsh-getdp-MacOSX
