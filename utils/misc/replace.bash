#!/bin/bash -

for A in  $*
do
sed "s|1997-2006|1997-2007|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done
