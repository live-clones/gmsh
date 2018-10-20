#!/bin/sh -

files=`git grep -l '(C) 1997-2017 C. Geuzaine'`

# FIXME for 2019: change "send email to gmsh@onelab.info" into
# create an issue on https://gitlab.onelab.info/gmsh/gmsh/issues

for file in $files; do
  echo "modifying $file"
  sed -i '' -e "s/(C) 1997-2017 C\. Geuzaine/(C) 1997-2018 C\. Geuzaine/g" $file
done

# Need to manually change:
#   CREDITS.txt
#   doc/texinfo/gmsh.texi
#   Fltk/helpWindow.cpp
#   doc/gmsh.html
