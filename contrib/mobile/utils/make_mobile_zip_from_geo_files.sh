#!/bin/sh

if [ $# -lt 1 ]; then
  echo "Usage: $0 file1.geo file2.geo ..." 1>&2;
  exit 1;
fi

name=demos_boolean

files=$*
rm -rf ${name}
mkdir ${name}
cd $name

cp ../*.step .
cat <<EOT >> infos.xml
<?xml version="1.0" encoding="utf-8"?>
<models>
EOT

cat <<EOT >> screenshot.geo
Print.Width = 1014;
Print.Height = 1014;
Print.Background = 1;
General.TrackballQuaternion0 = -0.09134439936266693;
General.TrackballQuaternion1 = 0.09382793879350552;
General.TrackballQuaternion2 = 0.02293507983466721;
General.TrackballQuaternion3 = 0.9911238574062343;
General.Orthographic = 0;
Mesh 2;
Draw;
Save StrCat("screenshot_", StrPrefix(StrRelative(General.FileName)), ".png") ;
SystemCall StrCat("convert -scale 128 screenshot_", StrPrefix(StrRelative(General.FileName)),
  ".png screenshot_", StrPrefix(StrRelative(General.FileName)), "_128.png");
Exit;
EOT

for file in $files ; do
    cp ../$file .
    /Applications/Gmsh.app/Contents/MacOS/gmsh ${file} screenshot.geo
    echo "<model>" >> infos.xml
    echo "<title>OpenCASCADE demo: ${file%.geo}</title>" >> infos.xml
    echo "<summary>gmsh/demos/boolean/${file}</summary>" >> infos.xml
    echo "<file type=\"geo\">$file</file>" >> infos.xml
    echo "<preview type=\"png\">screenshot_${file%.geo}_128.png</preview>" >> infos.xml
    echo "</model>" >> infos.xml
    rm -f screenshot_${file%.geo}.png
    cat <<EOT > ${file%.geo}.pro
DefineConstant[
  R_ = {"", Name "GetDP/1ResolutionChoices", Visible 0},
  C_ = {"", Name "GetDP/9ComputeCommand", Visible 0},
  P_ = {"", Name "GetDP/2PostOperationChoices", Visible 0}
];
EOT
done

cat <<EOT >> infos.xml
</models>
EOT

cd ..
rm ${name}.zip 
zip -r ${name}.zip ${name}
