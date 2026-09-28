// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <cmath>

#include "ImageIO.h"
#include "GmshMessage.h"

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_STDIO_WRITE
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

namespace ImageIO {

  bool read(const std::string &fileName, int &width, int &height, int &comp,
            std::vector<unsigned char> &pixels, int forceComp)
  {
    width = height = comp = 0;
    pixels.clear();

    int fileComp = 0;
    unsigned char *data =
      stbi_load(fileName.c_str(), &width, &height, &fileComp, forceComp);
    if(!data) {
      Msg::Error("Could not read image '%s': %s", fileName.c_str(),
                 stbi_failure_reason() ? stbi_failure_reason() : "unknown error");
      width = height = comp = 0;
      return false;
    }
    comp = forceComp ? forceComp : fileComp;
    pixels.assign(data, data + (std::size_t)width * height * comp);
    stbi_image_free(data);
    return true;
  }

  bool resize(const std::vector<unsigned char> &in, int width, int height,
              int comp, std::vector<unsigned char> &out, int newWidth,
              int newHeight)
  {
    if(width <= 0 || height <= 0 || comp <= 0 || newWidth <= 0 ||
       newHeight <= 0 ||
       in.size() < (std::size_t)width * height * comp) {
      Msg::Error("Invalid image passed to ImageIO::resize()");
      return false;
    }

    out.assign((std::size_t)newWidth * newHeight * comp, 0);

    // map the center of each destination pixel back into the source image
    double sx = (double)width / (double)newWidth;
    double sy = (double)height / (double)newHeight;

    for(int j = 0; j < newHeight; j++) {
      double y = (j + 0.5) * sy - 0.5;
      int j0 = (int)std::floor(y);
      double fy = y - j0;
      int j1 = j0 + 1;
      if(j0 < 0) { j0 = 0; fy = 0.; }
      if(j1 > height - 1) j1 = height - 1;
      if(j0 > height - 1) j0 = height - 1;
      for(int i = 0; i < newWidth; i++) {
        double x = (i + 0.5) * sx - 0.5;
        int i0 = (int)std::floor(x);
        double fx = x - i0;
        int i1 = i0 + 1;
        if(i0 < 0) { i0 = 0; fx = 0.; }
        if(i1 > width - 1) i1 = width - 1;
        if(i0 > width - 1) i0 = width - 1;
        const unsigned char *p00 = &in[((std::size_t)j0 * width + i0) * comp];
        const unsigned char *p01 = &in[((std::size_t)j0 * width + i1) * comp];
        const unsigned char *p10 = &in[((std::size_t)j1 * width + i0) * comp];
        const unsigned char *p11 = &in[((std::size_t)j1 * width + i1) * comp];
        unsigned char *dst = &out[((std::size_t)j * newWidth + i) * comp];
        for(int c = 0; c < comp; c++) {
          double top = p00[c] * (1. - fx) + p01[c] * fx;
          double bot = p10[c] * (1. - fx) + p11[c] * fx;
          double v = top * (1. - fy) + bot * fy;
          dst[c] = (unsigned char)(v < 0. ? 0. : (v > 255. ? 255. : v + 0.5));
        }
      }
    }
    return true;
  }

  std::string extensions()
  {
    return ".jpg, .jpeg, .png, .bmp, .pnm, .pgm, .ppm, .tga, .gif, .psd, .hdr, .pic";
  }

} // namespace ImageIO
