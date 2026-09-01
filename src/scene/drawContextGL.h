// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_GL_H
#define DRAW_CONTEXT_GL_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <string>
#include "drawContext.h"

// The drawing functions of the 3D scene, in plain OpenGL.
//
// Everything here is the scene's rather than a chrome's, with one exception,
// and it is a wooden leg: the strings drawn in the scene are textured quads
// taken from the Dear ImGui font atlas, at the current OpenGL raster position
// -- what glRasterPos() + gl_draw() does in the FLTK backend. So this
// directory needs a Dear ImGui context to exist, even one holding no window
// at all, and a chrome that pairs with this scene drags that in behind it.
//
// It is left as it is on purpose. Text in the scene is the worst part of the
// drawing and it will not be improved a piece at a time; the scene is a
// chantier of its own, to be rewritten rather than patched, and until someone
// does that this is what there is.

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
