// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#ifndef DRAW_CONTEXT_FLTK_CAIRO_H
#define DRAW_CONTEXT_FLTK_CAIRO_H

#include "GmshConfig.h"

#if defined(HAVE_CAIRO)
#include "drawContextFltkQueued.h"
#include "cairoStrings.h"

// the strings rasterised by Cairo, their heights and descents asked of FLTK
// as the other engines do
class drawContextFltkCairo : public drawContextFltkQueued {
  cairoStrings *_cairo() { return static_cast<cairoStrings *>(_strings); }

public:
  drawContextFltkCairo() : drawContextFltkQueued(new cairoStrings) {}
  double getStringWidth(const char *str) { return _cairo()->width(str); }
  void setFont(int fontid, int fontsize)
  {
    drawContextFltkQueued::setFont(fontid, fontsize);
    _cairo()->setFont(fontid, fontsize);
  }
  std::string getName() { return "Cairo"; }
};

#endif

#endif
