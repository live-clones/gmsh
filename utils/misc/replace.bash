#!/bin/bash -

for A in  $*
do
sed "s|1997-2007|1997-2008|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done

# Makefile */Makefile */*/Makefile *.in
# */*.cpp */*/*.cpp */*.h */*.y */*.l 
# doc/CREDITS doc/gmsh.html doc/texinfo/gmsh.texi
# */*/*.plist
