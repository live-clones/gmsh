#!/bin/sh

# This script removes all references to the GPL in the source code and documentation

if [ $# -lt 1 ]; then
  echo "Usage: $0 path" 1>&2;
  exit 1;
fi

path=$1

# Remove the big license blocks

files=`find ${path} -name "*.cpp" -o -name "*.h" -o -name "*.y" -o -name "*.in"\
                 -o -name "*.l" -o -name "*.texi" -o -name "Makefile*"`

for A in $files; do
  echo "cleaning up \"$A\""
  mv $A $A.old
  sed -e "/\/\/ This program is free software; you can redistribute/,/USA./D"\
      -e '/\/\/ Copyright (C).*Remacle/a\
//\
// This software is provided "as is" without express or implied warranty.\
// See the file "doc/LICENSE" for the licensing terms.'\
      -e "/# This program is free software; you can redistribute/,/USA./D"\
      -e '/# Copyright (C).*Remacle/a\
#\
# This software is provided "as is" without express or implied warranty.\
# See the file "doc/LICENSE" for the licensing terms.'\
      -e "/@c This program is free software; you can redistribute/,/USA./D"\
      -e '/@c Copyright (C).*Remacle/a\
@c\
@c This software is provided "as is" without express or implied warranty.\
@c See the file "doc/LICENSE" for the licensing terms.'\
      -e "/dnl This program is free software; you can redistribute/,/USA./D"\
      -e '/dnl Copyright (C).*Remacle/a\
dnl\
dnl This software is provided "as is" without express or implied warranty.\
dnl See the file "doc/LICENSE" for the licensing terms.'\
  $A.old > $A
  rm -f $A.old
done

# Remove the license string in the top makefile

files=`find ${path} -name "Makefile*"`

for A in $files; do
  echo "cleaning up \"$A\""
  mv $A $A.old
  sed -e "s/GNU General Public License/Commercial/g" $A.old > $A
  rm -f $A.old
done
