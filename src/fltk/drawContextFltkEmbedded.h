// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_FLTK_EMBEDDED_H
#define DRAW_CONTEXT_FLTK_EMBEDDED_H

#include <cmath>
#include "drawContextFltkQueued.h"
#include "stbStrings.h"

// the strings rasterised from the fonts compiled into Gmsh, and measured with
// them: the text of a window is then the text of a picture drawn without one
class drawContextFltkEmbedded : public drawContextFltkQueued {
  stbStrings *_stb() { return static_cast<stbStrings *>(_strings); }

public:
  drawContextFltkEmbedded() : drawContextFltkQueued(new stbStrings) {}
  void setFont(int fontid, int fontsize)
  {
    drawContextFltkQueued::setFont(fontid, fontsize);
    _stb()->setFont(fontid, fontsize);
  }
  double getStringWidth(const char *str) { return _stb()->width(str); }
  int getStringHeight() { return (int)std::ceil(_stb()->height()); }
  int getStringDescent() { return (int)std::ceil(_stb()->descent()); }
  std::string getName() { return "Embedded"; }
};

#endif
