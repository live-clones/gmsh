#!/bin/bash -

for A in  $*
do
sed "s|1997-2004|1997-2005|g" $A > $A.XXX
echo modif $A
rm -f $A
mv -f $A.XXX $A
done
