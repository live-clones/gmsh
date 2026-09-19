// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_FLTK_QUEUED_H
#define DRAW_CONTEXT_FLTK_QUEUED_H

#include <string>
#include <vector>
#include "drawContextFltk.h"

// The font engines that draw strings as textured quads: the strings of a
// frame are queued, and drawn at its end from an atlas of the strings already
// rasterised, which is kept from frame to frame; only the strings not in it
// are rasterised, by the engine, into one image of a single channel.
class drawContextFltkQueued : public drawContextFltk {
public:
  struct element {
    std::string text;
    float x, y, z; // the anchor, in the window's true pixels
    float r, g, b, a;
    int fontId, fontSize;
    bool halo;
    // was the depth test on when this string was queued? It then belongs to
    // the scene and is drawn depth tested; the 2D overlay is not
    bool depth;
  };
  // what the engine says of a string it is to rasterise at the pixel factor
  // f: the size of the image it takes, how far below the anchor the bottom of
  // that image goes, and where the pen starts in it (from its top left)
  struct extent {
    int w, h, below;
    double penX, penY;
  };
  // a string to rasterise, with its extent, in the rectangle of the image at
  // (x, y) of size w x h: the part of it starting shift pixels in
  struct slot {
    const element *e;
    extent ext;
    int x, y, w, h, shift;
  };

protected:
  std::vector<element> _queue;
  int _currentFontId = -1, _currentFontSize = 0;
  virtual char engine() = 0;
  virtual extent measure(const element &e, double f) = 0;
  // draw the slots in an image of w x h pixels of one channel, its first row
  // at the top, each clipped to its rectangle
  virtual void rasterise(const std::vector<slot> &slots, double f, int w,
                         int h, unsigned char *image) = 0;

private:
  void _upload(double f);

public:
  void flushString();
  void drawString(const char *str);
  void drawString(const char *str, const double win[3]);
  void setFont(int fontid, int fontsize);
};

#endif
