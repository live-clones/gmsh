#!/bin/bash
#$1 svn revision id
source run_test.sh
mkdir -p ../build
CDIR=$PWD
for i in ../build/*; do 
  cd $i
  NAME=`basename $i`
  run_test "make -j3" "compilation_$NAME" "$1" $HOME/validation/results
  cd $CDIR
done

