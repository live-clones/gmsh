#!/bin/sh

archs="i386 x86_64"
#archs="armv7 armv7s arm64"

mkdir -p tmplib
for arch in $archs; do
  mkdir -p $arch
  for i in $*; do
    lipo $i -thin $arch -o ${i}_${arch}
    cd $arch
    ar x ../${i}_${arch}
    cd ..
    rm ${i}_${arch}
  done
  ar r tmplib/${arch}.a ${arch}/*.o
  rm -rf ${arch}
done
lipo -create tmplib/*.a -output merged_petsc_lib.a
rm -rf tmplib
