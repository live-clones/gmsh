// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_GL_H
#define DRAW_CONTEXT_GL_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE) && defined(HAVE_GLFW)

#include <string>
#include "drawContext.h"

// the drawing functions of the scene in plain OpenGL, except the strings:
// textured quads from the Dear ImGui font atlas, so a Dear ImGui context has to
// exist, even one holding no window

class drawContextGL : public drawContextGlobal {
private:
  int _fontIndex;
  int _fontSize;

public:
  drawContextGL();
  void draw(bool rateLimited = true);
  void drawCurrentOpenglWindow(bool make_current, bool again = false);
  int getFontSize();
  void setFont(int fontid, int fontsize);
  double getStringWidth(const char *str);
  int getStringHeight();
  int getStringDescent();
  void drawString(const char *str);
  void drawString(const char *str, const double win[3]);
  void resetFontTextures();
  std::string getName() { return "ImGui"; }
};

#endif

#endif
