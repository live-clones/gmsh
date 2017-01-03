// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributed by Jonathan Lambrechts

#ifndef _DRAW_CONTEXT_FLTK_STRING_TEXTURE_H_
#define _DRAW_CONTEXT_FLTK_STRING_TEXTURE_H_

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
  std::string getName(){ return "StringTexture"; }
};

#endif
