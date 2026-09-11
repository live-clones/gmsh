stb_image.h v2.30 from https://github.com/nothings/stb, used by Gmsh to read
JPEG/PNG/BMP/PNM images (background images, image-to-post-processing-view
conversion, PDF page rendering) without depending on a widget toolkit.

The implementation is compiled once, in src/common/ImageIO.cpp, which defines
STB_IMAGE_IMPLEMENTATION.

stb_image.h is dual-licensed: MIT License or public domain (see the end of the
header for the exact terms).
