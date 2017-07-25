#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 file1.geo file2.geo ..." 1>&2;
  exit 1;
fi

name=demos_boolean

files=$*
rm -rf ${name}
mkdir ${name}

cp *.step ${name}/
cat <<EOT >> ${name}/infos.xml
<?xml version="1.0" encoding="utf-8"?>
<models>
EOT

for file in $files ; do
    cp $file ${name}/
    echo "<model>" >> ${name}/infos.xml
    echo "<title>$file</title>" >> ${name}/infos.xml
    echo "<summary>$file</summary>" >> ${name}/infos.xml
    echo "<file type=\"geo\">$file</file>" >> ${name}/infos.xml
    echo "</model>" >> ${name}/infos.xml
    cat <<EOT > ${name}/${file%.geo}.pro
DefineConstant[
  R_ = {"", Name "GetDP/1ResolutionChoices", Visible 0},
  C_ = {"", Name "GetDP/9ComputeCommand", Visible 0},
  P_ = {"", Name "GetDP/2PostOperationChoices", Visible 0}
];
EOT
done

cat <<EOT >> ${name}/infos.xml
</models>
EOT

zip -r ${name}.zip ${name}
