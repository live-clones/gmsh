#!/bin/bash -

for A in  $*
do
sed "s|MA 02111-1307 USA.|MA 02111-1307\\
// USA.\\
// \\
// Please report all bugs and problems to \"gmsh@geuz.org\".|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done
