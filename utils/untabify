#!/bin/sh

if [ $# -lt 1 ] ; then
  echo "Usage: untabify files" 1>&2
  exit 1
else 
  for file in $@; do
    echo Modifying $file
    mv $file $file~
    expand $file~ > $file
  done
fi


