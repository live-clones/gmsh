// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DRAW_CONTEXT_FLTK_H
#define DRAW_CONTEXT_FLTK_H

#include "GmshConfig.h"
#include <algorithm>
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <FL/x.H>
#include <FL/gl.h>
#include "GmshMessage.h"
#include "drawContext.h"
#include "drawContextGL.h"
#include "Context.h"

// the Native engine: the strings drawn by FLTK at the raster position, which
// only the fixed function pipeline has; what is drawn is the scene host's
class drawContextFltk : public drawContextHosted {
public:
  void setFont(int fontid, int fontsize) { gl_font(fontid, fontsize); }
  double getStringWidth(const char *str) { return gl_width(str); }
  int getStringHeight() { return gl_height(); }
  int getStringDescent() { return gl_descent(); }
  void drawString(const char *str)
  {
    if(!stringHalo()) {
      gl_draw(str);
      return;
    }
    // eight copies around it in the background colour first, the raster
    // position moved by a pixel each time (an empty bitmap moves it) and
    // brought back after each, as drawing advances it
    GLfloat pos[4], color[4];
    glGetFloatv(GL_CURRENT_RASTER_POSITION, pos);
    glGetFloatv(GL_CURRENT_COLOR, color);
    unsigned int bg = CTX::instance()->color.bg;
    glColor4ub(CTX::instance()->unpackRed(bg), CTX::instance()->unpackGreen(bg),
               CTX::instance()->unpackBlue(bg), 255);
    for(int i = -1; i <= 1; i++)
      for(int j = -1; j <= 1; j++) {
        if(!i && !j) continue;
        glBitmap(0, 0, 0.f, 0.f, (GLfloat)i, (GLfloat)j, nullptr);
        gl_draw(str);
        GLfloat now[4];
        glGetFloatv(GL_CURRENT_RASTER_POSITION, now);
        glBitmap(0, 0, 0.f, 0.f, pos[0] - now[0], pos[1] - now[1], nullptr);
      }
    glColor4fv(color);
    gl_draw(str);
  }
// FLTK draws a string as a texture, kept in a pile of a fixed height, from
// 1.4 on and on macOS before that; the pile is where the three calls below
// go, and where they do nothing at all otherwise
#if((FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)) || defined(__APPLE__)
#define GMSH_FLTK_STRING_TEXTURES 1
#endif

  bool keepsStringTextures()
  {
#if defined(GMSH_FLTK_STRING_TEXTURES)
    return true;
#else
    return false;
#endif
  }
  void resetFontTextures()
  {
#if defined(GMSH_FLTK_STRING_TEXTURES)
    // the strings are drawn again: their textures are made again with them
    gl_texture_pile_height(gl_texture_pile_height());
#endif
  }
  void reserveStringTextures(std::size_t n)
  {
#if defined(GMSH_FLTK_STRING_TEXTURES)
    if(gl_texture_pile_height() < (int)n) gl_texture_pile_height((int)n);
#else
    (void)n;
#endif
  }
  std::string getName() { return "Fltk"; }
};

#endif
