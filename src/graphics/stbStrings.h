// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef STB_STRINGS_H
#define STB_STRINGS_H

#include "stringQueue.h"

// The strings rasterised by stb_truetype from fonts compiled into Gmsh (see
// contrib/fonts): the same everywhere, and nothing to install - what the
// pictures drawn without a window use.
class stbStrings : public stringQueue {
  int _fontId = 0, _fontSize = 12;

protected:
  char engine() { return 'S'; }
  extent measure(const element &e, double f);
  void rasterise(const std::vector<slot> &slots, double f, int w, int h,
                 unsigned char *image);

public:
  void setFont(int fontid, int fontsize);
  // the width the current font lays the string out with
  double width(const char *str);
  // the height of a line of the current font, and how far below the baseline
  // it goes
  double height();
  double descent();
};

#endif
