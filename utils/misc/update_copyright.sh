#!/bin/sh -

files=`git grep -l '(C) 1997-2017 C. Geuzaine'`

for file in $files; do
  echo "modifying $file"
  sed -i '' -e "s/(C) 1997-2017 C. Geuzaine/(C) 1997-2018 C. Geuzaine/g" $file
done

# Need to manually change:
#   CREDITS.txt
#   doc/texinfo/gmsh.texi
#   Fltk/helpWindow.cpp
#   doc/gmsh.html
