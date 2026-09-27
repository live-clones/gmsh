// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_FLTK_QUEUED_H
#define DRAW_CONTEXT_FLTK_QUEUED_H

#include "drawContextFltk.h"
#include "stringQueue.h"

// The font engines that draw strings as textured quads, from the atlas of a
// stringQueue given by the engine
class drawContextFltkQueued : public drawContextFltk {
protected:
  stringQueue *_strings;
  int _currentFontId = -1, _currentFontSize = 0;

public:
  drawContextFltkQueued(stringQueue *strings) : _strings(strings) {}
  ~drawContextFltkQueued() { delete _strings; }
  void flushString()
  {
    // measuring the strings sets their fonts: the caller's comes back
    int fontId = _currentFontId, fontSize = _currentFontSize;
    _strings->flush(pixelFactor());
    if(fontId >= 0) {
      _currentFontId = -1;
      setFont(fontId, fontSize);
    }
  }
  void drawString(const char *str)
  {
    GLfloat pos[4];
    glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
    double win[3] = {pos[0], pos[1], pos[2]};
    drawString(str, win);
  }
  void drawString(const char *str, const double win[3])
  {
    _strings->add(str, win, _currentFontId, _currentFontSize, stringHalo());
  }
  void setFont(int fontid, int fontsize)
  {
    drawContextFltk::setFont(fontid, fontsize);
    _currentFontId = fontid;
    _currentFontSize = fontsize;
  }
  // The strings of this engine live in its own atlas, which grows as it
  // needs to: FLTK's pile of one texture per string is never used (they are
  // rasterised into an image), so there is nothing to size for the frame.
  // The atlas holds one channel and the colour is the quad's, so a colour
  // change costs it nothing either.
  bool keepsStringTextures() { return false; }
  void resetFontTextures() {}
  void reserveStringTextures(std::size_t n) {}
};

#endif
