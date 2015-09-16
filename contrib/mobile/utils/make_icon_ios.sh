#!/bin/sh

icon_source=../../../utils/icons/gmsh_mobile_master.png
launch_source=../../../utils/icons/gmsh_mobile_master.png

icon_source=../../../utils/icons/bbemg-logo-twitter-white.png
launch_source=../../../utils/icons/bbemg-logo-color-rgb.png

mkdir -p AppIcon.appiconset
# App icons (iPad)
convert -scale 152 ${icon_source} AppIcon.appiconset/icon_app_ipad_retina.png
convert -scale 76 ${icon_source} AppIcon.appiconset/icon_app_ipad.png
# App icon (iPhone)
convert -scale 120 ${icon_source} AppIcon.appiconset/icon_app_iphone_retina.png

mkdir -p LaunchImage.launchimage
convert ${launch_source} -gravity Center -crop 1024x768+0+0\! -background white -flatten LaunchImage.launchimage/splash1024x768.png
convert ${launch_source} -gravity Center -crop 1536x2048+0+0\! -background white -flatten LaunchImage.launchimage/splash1536x2048.png
convert ${launch_source} -gravity Center -crop 2048x1536+0+0\! -background white -flatten LaunchImage.launchimage/splash2048x1536.png
convert ${launch_source} -gravity Center -crop 640x1136+0+0\! -background white -flatten LaunchImage.launchimage/splash640x1136.png
convert ${launch_source} -gravity Center -crop 640x960+0+0\! -background white -flatten LaunchImage.launchimage/splash640x960.png
convert ${launch_source} -gravity Center -crop 768x1024+0+0\! -background white -flatten LaunchImage.launchimage/splash768x1024.png
