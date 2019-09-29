#!/bin/sh

# run this e.g. in "petsc/ios_real/lib" or "occt/build_ios" on all the .a static
# libs you want to merge

mkdir -p tmplib
cd tmplib
for i in $*; do
    ar x ../${i}
done
cd ..
ar r lib_combined.a tmplib/*.o
rm -rf tmplib
