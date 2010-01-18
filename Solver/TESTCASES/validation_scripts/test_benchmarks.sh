#!/bin/bash
# $1 svn revision id (ex 0)
source run_test.sh
result=true;
CDIR=$PWD
cd ../gmsh/Solver/TESTCASES/validation
for i in `find  . -name '*.lua' | grep -v '.svn' | sort`; do
  NAME=$(basename $i .lua)
  echo $NAME
  run_test "$CDIR/../build/default/gmsh $i -" "$NAME" "$1" "$CDIR/results" 
done
cd $CDIR
