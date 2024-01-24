// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by Jonathan Lambrechts

#ifndef DRAW_CONTEXT_FLTK_STRING_TEXTURE_H
#define DRAW_CONTEXT_FLTK_STRING_TEXTURE_H

#include "drawContextFltk.h"

class drawContextFltkStringTexture : public drawContextFltk {
  class queueString;
  queueString *_queue;
  int _currentFontId;
  int _currentFontSize;

public:
  drawContextFltkStringTexture();
  ~drawContextFltkStringTexture();
  void flushString();
  void drawString(const char *str);
  void setFont(int fontid, int fontsize);
  std::string getName() { return "StringTexture"; }
};

#endif
