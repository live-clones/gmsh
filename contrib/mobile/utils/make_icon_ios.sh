#!/bin/sh

icon_source=../../../utils/icons/gmsh_mobile_1024x1024.png
launch_source=../../../utils/icons/gmsh_128x128.png
launch_source2=../../../utils/icons/gmsh_256x256.png
bg=black

#icon_source=$HOME/tex/proposals/bbemg/icons/bbemg-logo-white.png
#launch_source=$HOME/tex/proposals/bbemg/icons/bbemg-logo-text.png
#launch_source2=${launch_source}
#bg=white

mkdir -p AppIcon.appiconset
# App icons (iPad)
convert -scale 152 ${icon_source} AppIcon.appiconset/icon_app_ipad_retina.png
convert -scale 76 ${icon_source} AppIcon.appiconset/icon_app_ipad.png
# App icon (iPhone)
convert -scale 120 ${icon_source} AppIcon.appiconset/icon_app_iphone_retina.png

mkdir -p LaunchImage.launchimage
# iphone 4 scale 2x (retina)
convert ${launch_source} -gravity Center -crop 640x960+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash640x960.png

# iphone 5 scale 2x (retina)
convert ${launch_source} -gravity Center -crop 640x1136+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash640x1136.png

# iphone 6 scale 2x (retina)
convert ${launch_source} -gravity Center -crop 750x1334+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash750x1334.png
convert ${launch_source} -gravity Center -crop 1334x750+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash1334x750.png

# iphone 6 plus scale 3x (retina HD)
convert ${launch_source2} -gravity Center -crop 1242x2208+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash1242x2208.png
convert ${launch_source2} -gravity Center -crop 2208x1242+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash2208x1242.png

# ipad scale 1x
convert ${launch_source} -gravity Center -crop 768x1024+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash768x1024.png
convert ${launch_source} -gravity Center -crop 1024x768+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash1024x768.png

# ipad scale 2x (retina)
convert ${launch_source2} -gravity Center -crop 1536x2048+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash1536x2048.png
convert ${launch_source2} -gravity Center -crop 2048x1536+0+0\! -background ${bg} -flatten LaunchImage.launchimage/splash2048x1536.png
