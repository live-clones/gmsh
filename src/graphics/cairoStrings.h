// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#ifndef CAIRO_STRINGS_H
#define CAIRO_STRINGS_H

#include "GmshConfig.h"

#if defined(HAVE_CAIRO)
#include "stringQueue.h"

typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo cairo_t;

// the strings rasterised by Cairo, which also measures them
class cairoStrings : public stringQueue {
  cairo_surface_t *_surface;
  cairo_t *_cr;
  int _fontId = -1;

protected:
  char engine() { return 'C'; }
  extent measure(const element &e, double f);
  void rasterise(const std::vector<slot> &slots, double f, int w, int h,
                 unsigned char *image);

public:
  cairoStrings();
  ~cairoStrings();
  void setFont(int fontid, int fontsize);
  // the width the current font lays the string out with
  double width(const char *str);
  // the height of a line of the current font, and how far below the baseline
  // it goes
  double height();
  double descent();
};

#endif

#endif
