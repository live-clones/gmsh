#!/bin/sh

# create a macOS icon from a 1024x1024 png master

if [ $# -lt 2 ]; then
  echo "Usage: $0 pngfile iconname" 1>&2;
  echo "Example: $0 gmsh-no-text.png MacIcons" 1>&2;
  exit 1;
fi

mkdir $2.iconset
cp $1 $2.iconset/icon_512x512\@2x.png
convert -scale 512 $1 $2.iconset/icon_512x512.png
convert -scale 512 $1 $2.iconset/icon_256x256\@2x.png
convert -scale 256 $1 $2.iconset/icon_256x256.png
convert -scale 256 $1 $2.iconset/icon_128x128\@2x.png
convert -scale 128 $1 $2.iconset/icon_128x128.png
convert -scale 64 $1 $2.iconset/icon_32x32\@2x.png
convert -scale 32 $1 $2.iconset/icon_32x32.png
convert -scale 32 $1 $2.iconset/icon_16x16\@2x.png
convert -scale 16 $1 $2.iconset/icon_16x16.png
iconutil -c icns $2.iconset
