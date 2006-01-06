#!/bin/bash -

for A in  $*
do
sed "s|1997-2005|1997-2006|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done
