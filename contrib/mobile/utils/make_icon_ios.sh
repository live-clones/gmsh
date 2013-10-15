#!/bin/sh

mkdir ios.iconset
# App icons (iPad)
convert -scale 152 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_ipad_retina.png
convert -scale 144 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_ipad_retina_61.png
convert -scale 76 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_ipad.png
convert -scale 72 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_ipad_61.png

# App icons (iPhone)
convert -scale 120 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_iphone_retina.png
convert -scale 114 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_iphone_retina_61.png
convert -scale 57 ../../../utils/icons/gmsh_1024x1024.png ios.iconset/icon_app_iphone_61.png
