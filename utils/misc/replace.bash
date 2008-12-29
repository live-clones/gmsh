#!/bin/bash -

for A in  $*
do
sed "s|1997-2008|1997-2009|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done

# Makefile */Makefile */*/Makefile *.in
# */*.cpp */*/*.cpp */*.h */*.y */*.l 
# doc/CREDITS.txt doc/gmsh.html doc/texinfo/gmsh.texi
# */*/*.plist
