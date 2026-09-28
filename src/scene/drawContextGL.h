// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_GL_H
#define DRAW_CONTEXT_GL_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE) && (defined(HAVE_GLFW) || defined(HAVE_GTK) || defined(HAVE_QT))

#include <string>
#include "drawContext.h"

class stbStrings;

// the drawing functions of a scene held by OpenGL alone (the Dear ImGui
// interface, the window of its own of the browser interface, a canvas of a
// page, the GtkGLArea of the GTK interface): what is
// drawn goes to the scene host, and the strings are written by the fonts
// compiled into Gmsh, the Embedded engine of the FLTK interface
// (drawContextFltkEmbedded)

class drawContextGL : public drawContextGlobal {
private:
  stbStrings *_strings;
  int _fontId, _fontSize;

public:
  drawContextGL();
  ~drawContextGL();
  void draw(bool rateLimited = true);
  void drawCurrentOpenglWindow(bool make_current, bool again = false);
  int getFontSize();
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

#endif
