// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#ifndef DRAW_CONTEXT_FLTK_STRING_TEXTURE_H
#define DRAW_CONTEXT_FLTK_STRING_TEXTURE_H

#include "drawContextFltkQueued.h"

// the strings rasterised by FLTK in an offscreen image
class fltkStrings : public stringQueue {
protected:
  char engine() { return 'T'; }
  extent measure(const element &e, double f);
  void rasterise(const std::vector<slot> &slots, double f, int w, int h,
                 unsigned char *image);
};

class drawContextFltkStringTexture : public drawContextFltkQueued {
public:
  drawContextFltkStringTexture() : drawContextFltkQueued(new fltkStrings) {}
  std::string getName() { return "StringTexture"; }
};

#endif
