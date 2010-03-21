#!/bin/sh

files=`find ../.. \( -name "*.cpp" -or -name "*.h" \) -and -not -path "*contrib*"`

echo $files

for file in $files; do
  echo Untabifying $file
  expand $file > $file~
  mv -f $file~ $file
done
