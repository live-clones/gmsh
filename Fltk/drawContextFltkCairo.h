// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#ifndef DRAW_CONTEXT_FLTK_CAIRO_H
#define DRAW_CONTEXT_FLTK_CAIRO_H

#include "GmshConfig.h"

#if defined(HAVE_CAIRO)
#include "drawContextFltk.h"

typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo cairo_t;

class drawContextFltkCairo : public drawContextFltk {
  class queueString;
  queueString *_queue;
  cairo_surface_t *_surface;
  cairo_t *_cr;
  int _currentFontId;
  int _currentFontSize;

public:
  drawContextFltkCairo();
  ~drawContextFltkCairo();
  double getStringWidth(const char *str);
  void flushString();
  void drawString(const char *str);
  void setFont(int fontid, int fontsize);
  std::string getName() { return "Cairo"; }
};

#endif

#endif
