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

// The drawing functions of the 3D scene, in plain OpenGL.
//
// One exception to plain OpenGL: the strings drawn in the scene are
// textured quads taken from the Dear ImGui font atlas, at the current
// OpenGL raster position. So this directory needs a Dear ImGui context to
// exist, even one holding no window at all, and an interface that pairs
// with this scene drags that in behind it.

class drawContextGL : public drawContextGlobal {
private:
  int _fontIndex;
  int _fontSize;

public:
  drawContextGL();
  void draw(bool rateLimited = true);
  void drawCurrentOpenglWindow(bool make_current);
  int getFontIndex(const char *fontname);
  int getFontEnum(int index);
  const char *getFontName(int index);
  int getNumFonts();
  int getFontSize();
  void setFont(int fontid, int fontsize);
  double getStringWidth(const char *str);
  int getStringHeight();
  int getStringDescent();
  void drawString(const char *str);
  void resetFontTextures();
  std::string getName() { return "ImGui"; }
};

#endif

#endif
