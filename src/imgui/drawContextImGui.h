// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_IMGUI_H
#define DRAW_CONTEXT_IMGUI_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <string>
#include "drawContext.h"

// Dear ImGui implementation of the global drawing functions. Strings drawn in
// the 3D scene are rendered as textured quads taken from the Dear ImGui font
// atlas, at the current OpenGL raster position, which is what glRasterPos() +
// gl_draw() does in the FLTK backend.

class drawContextImGui : public drawContextGlobal {
private:
  int _fontIndex;
  int _fontSize;

public:
  drawContextImGui();
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
