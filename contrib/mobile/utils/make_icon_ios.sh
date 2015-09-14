#!/bin/sh

source=../../../utils/icons/gmsh_mobile_master.png
#source=../../../utils/icons/bbemg-twitter.png

mkdir -p ios.iconset
# App icons (iPad)
convert -scale 152 ${source} ios.iconset/icon_app_ipad_retina.png
convert -scale 76 ${source} ios.iconset/icon_app_ipad.png

# App icon (iPhone)
convert -scale 120 ${source} ios.iconset/icon_app_iphone_retina.png
