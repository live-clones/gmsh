#!/bin/bash -

for A in $*
do
echo modifying $A
awk -f unix2dos.awk $A > $A.XXX
/bin/rm -f $A
mv $A.XXX $A   
done
