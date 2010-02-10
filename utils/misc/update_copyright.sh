#!/bin/sh -

files=`find ../.. -not -path "*.svn*" -and -not -path "*lib*" -and -not -path "*bin*" -and -not -name "update_copyright.sh" | xargs grep 'Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle' -sl`

echo $files

for file in $files 
do
sed "s|(C) 1997-2009 C|(C) 1997-2010 C|g" $file > $file.tmp
echo modified $file
rm -f $file
mv $file.tmp $file
done
