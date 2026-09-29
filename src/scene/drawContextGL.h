// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_GL_H
#define DRAW_CONTEXT_GL_H

#include "GmshConfig.h"

#include <string>
#include "drawContext.h"

class stbStrings;

// the drawing functions of a scene whose holder answers the scene host (see
// sceneHost.h): what is drawn is asked of the host, the size of the fonts is
// that of the screen it says; the strings are the engine's

class drawContextHosted : public drawContextGlobal {
public:
  void draw(bool rateLimited = true);
  void drawCurrentOpenglWindow(bool make_current, bool again = false);
  int getFontSize();
  bool mouseIsPressed();
};

// the strings written by the fonts compiled into Gmsh, the Embedded engine:
// the same in every interface, and in a picture drawn without a window

class drawContextGL : public drawContextHosted {
private:
  stbStrings *_strings;
  int _fontId, _fontSize;

public:
  drawContextGL();
  ~drawContextGL();
  void setFont(int fontid, int fontsize);
  double getStringWidth(const char *str);
  int getStringHeight();
  int getStringDescent();
  void drawString(const char *str);
  void drawString(const char *str, const double win[3]);
  void flushString();
  std::string getName() { return "Embedded"; }
};

#endif
