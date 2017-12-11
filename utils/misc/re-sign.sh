#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Usage: $0 filename" 1>&2;
  exit 1;
fi

security unlock-keychain -p FIXME ${HOME}/Library/Keychains/login.keychain

file="$1"
base="${file%.*}"
ext="${file##*.}"
ext2="${base##*.}"

# gmsh*.dmg
if [ $ext == "dmg" ]; then
  hdiutil convert ${file} -format UDTO -o /tmp/tmp.cdr
  hdiutil attach -nobrowse -noverify -noautoopen -mountpoint /tmp/tmp_mount /tmp/tmp.cdr
  mkdir ${base}
  cp -R /tmp/tmp_mount/* ${base}/
  codesign -v --force --deep --sign "Developer ID Application: Christophe Geuzaine" ${base}/Gmsh.app
  hdiutil eject /tmp/tmp_mount
  rm -rf ${file} /tmp/tmp.cdr
  hdiutil create -srcfolder ${base} ${file}
  codesign -v --sign "Developer ID Application: Christophe Geuzaine" ${file}
  rm -rf ${base}
fi

# getdp*.tar.gz
if [ $ext == "gz" ] && [ $ext2 == "tar" ] ; then
  cd /tmp
  name=$(basename ${file})
  tar zxvf ${name}
  dir=`ls -d getdp-*/`
  codesign -v --force --sign "Developer ID Application: Christophe Geuzaine" ${dir}/bin/getdp
  tar zcvf ${name} ${dir}
  rm -rf ${dir}
fi
