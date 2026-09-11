// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMAGE_IO_H
#define IMAGE_IO_H

#include <string>
#include <vector>

// Toolkit-independent image loading, used for background images, for the
// conversion of images into post-processing views and for PDF page rendering.
// Backed by stb_image (contrib/stb), so that Gmsh does not need a widget
// toolkit to read JPEG, PNG, BMP, PNM, TGA or GIF files.

namespace ImageIO {

  // Read an image file. On success pixels contains width * height * comp bytes,
  // stored row by row from the top-left corner. If forceComp is 1, 2, 3 or 4 the
  // image is converted to that number of components (1 = grey, 2 = grey+alpha,
  // 3 = RGB, 4 = RGBA); if it is 0, the number of components of the file is
  // kept. Returns false and issues an error message if the file cannot be read.
  bool read(const std::string &fileName, int &width, int &height, int &comp,
            std::vector<unsigned char> &pixels, int forceComp = 0);

  // Bilinear resampling of an 8-bit-per-channel image.
  bool resize(const std::vector<unsigned char> &in, int width, int height,
              int comp, std::vector<unsigned char> &out, int newWidth,
              int newHeight);

  // List of the file extensions understood by read(), for error messages and
  // file dialogs
  std::string extensions();

} // namespace ImageIO

#endif
