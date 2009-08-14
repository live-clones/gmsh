#!/bin/sh

to_delete=`find . -name "*~" -o -name "*~~" -o -name ".gmsh-errors"\
           -o -name "\#*" -o -name ".\#*" -o -name ".DS_Store"\
           -o -name "gmon.out" -o -name ".gdb_history" -o -name "debug?.pos"\
           -o -name "*.bak"`
rm -f ${to_delete}
