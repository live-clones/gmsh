#!/bin/sh -

files=`git grep -l '(C) 1997-2021 C. Geuzaine'`

for file in $files; do
  echo "modifying $file"
  sed -i '' -e "s/(C) 1997-2020 C\. Geuzaine/(C) 1997-2021 C\. Geuzaine/g" $file
done

# Need to manually change:
#   CREDITS.txt
#   doc/texinfo/gmsh.texi
#   Fltk/helpWindow.cpp
#   Common/onelab.h
#   doc/gmsh.html
#   contrib/mobile/README.txt
#   contrib/mobile/androidUtils.cpp
#   contrib/mobile/iOS/Onelab/AboutViewController.mm
#   contrib/mobile/Android/app/src/main/java/org/geuz/onelab/AboutActivity.java
#   contrib/onelab/README.txt
#   contrib/onelab/python/onelab.py
