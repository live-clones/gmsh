// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Jonathan Lambrechts

#ifndef _DRAW_CONTEXT_FLTK_CAIRO_H_
#define _DRAW_CONTEXT_FLTK_CAIRO_H_

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
  void draw();
  drawContextFltkCairo();
  ~drawContextFltkCairo();
  double getStringWidth(const char *str);
  //int getStringHeight();
  //int getStringDescent();
  void flushString();
  void drawString(const char *str);
  void setFont(int fontid, int fontsize);
  std::string getName(){ return "Cairo"; }
};

#endif

#endif
