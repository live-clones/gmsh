#!/bin/sh -

files=`git grep -l '(C) 1997-2024 C. Geuzaine'`

for file in $files; do
  echo "modifying $file"
  sed -i '' -e "s/(C) 1997-2023 C\. Geuzaine/(C) 1997-2024 C\. Geuzaine/g" $file
done

files=`git grep -l '(C) 2013-2024 UCLouvain-ULiege'`

for file in $files; do
  echo "modifying $file"
  sed -i '' -e "s/(C) 2013-2024 UCLouvain-ULiege/(C) 2013-2024 UCLouvain-ULiege/g" $file
done

# Need to manually change:
#   CREDITS.txt
#   doc/texinfo/gmsh.texi
#   src/fltk/helpWindow.cpp
#   src/common/onelab.h
#   doc/gmsh.html
#   contrib/mobile/README.txt
#   contrib/mobile/androidUtils.cpp
#   contrib/mobile/iOS/Onelab/AboutViewController.mm
#   contrib/mobile/Android/app/src/main/java/org/geuz/onelab/AboutActivity.java
#   contrib/onelab/README.txt
#   contrib/onelab/python/onelab.py
