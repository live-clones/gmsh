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

typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo cairo_t;

// the strings rasterised by Cairo
class drawContextFltkCairo : public drawContextFltkQueued {
  cairo_surface_t *_surface;
  cairo_t *_cr;

protected:
  char engine() { return 'C'; }
  extent measure(const element &e, double f);
  void rasterise(const std::vector<slot> &slots, double f, int w, int h,
                 unsigned char *image);

public:
  drawContextFltkCairo();
  ~drawContextFltkCairo();
  double getStringWidth(const char *str);
  void setFont(int fontid, int fontsize);
  std::string getName() { return "Cairo"; }
};

#endif

#endif
