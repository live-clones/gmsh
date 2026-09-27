// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_OFFSCREEN_H
#define DRAW_CONTEXT_OFFSCREEN_H

#include "drawContext.h"

class stbStrings;

// The pictures drawn without a window (see offscreenContext): the scene of
// a window of General.GraphicsWidth x General.GraphicsHeight pixels, drawn
// as a window draws it, into a picture of its own size. It stands in for
// the global drawing context between begin() and end(), and draws its
// strings with the fonts compiled into Gmsh (see stbStrings).
class drawContextOffscreen : public drawContextGlobal {
private:
  drawContext *_ctx;
  stbStrings *_strings;
  int _fontId, _fontSize;
  int _width, _height;
  double _scale;
  double _frameView[16];
  drawContextGlobal *_previous;

public:
  drawContextOffscreen();
  ~drawContextOffscreen();
  // a picture of width x height pixels, of the scene of a window scaled by
  // scale (what is sized in pixels follows): the context is made current,
  // the picture bound to be drawn into, and this is the global drawing
  // context until end()
  bool begin(int width, int height, double scale);
  // read the picture back
  void read(GLenum format, GLenum type, void *pixels);
  void end();
  // draw the scene into the picture
  void drawCurrentOpenglWindow(bool make_current, bool again = false);
  drawContext *getDrawContext() { return _ctx; }
  int getFontSize();
  void setFont(int fontid, int fontsize);
  double getStringWidth(const char *str);
  int getStringHeight();
  int getStringDescent();
  void drawString(const char *str);
  void drawString(const char *str, const double win[3]);
  void flushString();
  std::string getName() { return "Offscreen"; }
};

#endif
