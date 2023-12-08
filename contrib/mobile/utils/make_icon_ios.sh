#!/bin/sh

icon_source=./gmsh_mobile_1024x1024.png
bg=black

#icon_source=$HOME/tex/proposals/bbemg/icons/bbemg-logo-white.png
#bg=white

mkdir -p AppIcon.appiconset
# App icons (iPad)
convert -scale 152 ${icon_source} AppIcon.appiconset/icon_app_ipad_retina.png
convert -scale 76 ${icon_source} AppIcon.appiconset/icon_app_ipad.png
# App icons (iPad Pro)
convert -scale 167 ${icon_source} AppIcon.appiconset/icon_app_ipad_pro.png
# App icon (iPhone)
convert -scale 120 ${icon_source} AppIcon.appiconset/icon_app_iphone_retina.png
# App icon (iOS marketing)
cp ${icon_source} AppIcon.appiconset/icon_app_ios_marketing.png
