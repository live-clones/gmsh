#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 file1.geo file2.geo ..." 1>&2;
  exit 1;
fi

files=$*
rm -rf Archive
mkdir Archive

cp *.step Archive/
cat <<EOT >> Archive/infos.xml
<?xml version="1.0" encoding="utf-8"?>
<models>
EOT

for file in $files ; do
    cp $file Archive/
    echo "<model>" >> Archive/infos.xml
    echo "<title>$file</title>" >> Archive/infos.xml
    echo "<summary>$file</summary>" >> Archive/infos.xml
    echo "<file type=\"geo\">$file</file>" >> Archive/infos.xml
    echo "</model>" >> Archive/infos.xml
    cat <<EOT > Archive/${file%.geo}.pro
DefineConstant[
  R_ = {"", Name "GetDP/1ResolutionChoices", Visible 0},
  C_ = {"", Name "GetDP/9ComputeCommand", Visible 0},
  P_ = {"", Name "GetDP/2PostOperationChoices", Visible 0}
];
EOT
done

cat <<EOT >> Archive/infos.xml
</models>
EOT

zip -r Archive.zip Archive
