#!/bin/sh

enscript -t "Gmsh tutorial" -Ecpp --color -Whtml --toc -pt.html README *.geo

cat t.html | \
sed "s/<FONT COLOR=\"#BC8F8F\"><B>//g" | \
sed "s/<B><FONT COLOR=\"#5F9EA0\">//g" | \
sed "s/<B><FONT COLOR=\"#A020F0\">//g" | \
sed "s/<B><FONT COLOR=\"#0000FF\">//g" | \
sed "s/<\/FONT><\/B>//g" > tutorial.html

rm -f t.html

echo output moved to tutorial.html
