#!/bin/sh -

files=`find ../.. -not -path "*.svn*" -and -not -path "*lib*" -and -not -path "*bin*" -and -not -name "update_copyright.sh" -print0 | xargs -0 grep 'Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle' -sl`

#echo $files

for file in $files 
do
sed "s|(C) 1997-2010 C|(C) 1997-2011 C|g" $file > $file.tmp
echo modified $file
rm -f $file
mv $file.tmp $file
done
