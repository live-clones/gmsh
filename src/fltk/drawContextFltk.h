// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
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
#include "FlGui.h"
#include "drawContext.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "openglWindow.h"
#include "Context.h"

class drawContextFltk : public drawContextGlobal {
public:
  void draw(bool rateLimited = true)
  {
    if(!FlGui::available()) return;
    if(FlGui::instance()->fullscreen->shown()) {
      FlGui::instance()->fullscreen->make_current();
      FlGui::instance()->fullscreen->redraw();
    }
    else {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++) {
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size();
            j++) {
          FlGui::instance()->graph[i]->gl[j]->make_current();
          FlGui::instance()->graph[i]->gl[j]->redraw();
          glFlush();
          // FIXME: I don't think this should be done here
          drawContext *ctx =
            FlGui::instance()->graph[i]->gl[j]->getDrawContext();
          ctx->camera.update();
        }
      }
    }
    FlGui::check(rateLimited);
  }
  void drawCurrentOpenglWindow(bool make_current)
  {
    if(!FlGui::available()) return;
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(make_current) gl->make_current();
    gl->redraw();
    glFlush();
    FlGui::check();
  }
  int getFontIndex(const char *fontname)
  {
    if(fontname) {
      for(int i = 0; i < NUM_FONTS; i++)
        if(!strcmp(menu_font_names[i].label(), fontname)) return i;
    }
    Msg::Error("Unknown font \"%s\" (using \"Helvetica\" instead)", fontname);
    Msg::Info("Available fonts:");
    for(int i = 0; i < NUM_FONTS; i++)
      Msg::Info("  \"%s\"", menu_font_names[i].label());
    return 4;
  }
  int getFontEnum(int index)
  {
    if(index >= 0 && index < NUM_FONTS)
      return (intptr_t)menu_font_names[index].user_data();
    return FL_HELVETICA;
  }
  const char *getFontName(int index)
  {
    if(index >= 0 && index < NUM_FONTS) return menu_font_names[index].label();
    return "Helvetica";
  }
  int getFontAlign(const char *alignstr)
  {
    if(alignstr) {
      if(!strcmp(alignstr, "BottomLeft") || !strcmp(alignstr, "Left") ||
         !strcmp(alignstr, "left"))
        return 0;
      else if(!strcmp(alignstr, "BottomCenter") ||
              !strcmp(alignstr, "Center") || !strcmp(alignstr, "center"))
        return 1;
      else if(!strcmp(alignstr, "BottomRight") || !strcmp(alignstr, "Right") ||
              !strcmp(alignstr, "right"))
        return 2;
      else if(!strcmp(alignstr, "TopLeft"))
        return 3;
      else if(!strcmp(alignstr, "TopCenter"))
        return 4;
      else if(!strcmp(alignstr, "TopRight"))
        return 5;
      else if(!strcmp(alignstr, "CenterLeft"))
        return 6;
      else if(!strcmp(alignstr, "CenterCenter"))
        return 7;
      else if(!strcmp(alignstr, "CenterRight"))
        return 8;
    }
    Msg::Error("Unknown font alignment \"%s\" (using \"Left\" instead)",
               alignstr);
    Msg::Info("Available font alignments:");
    Msg::Info("  \"Left\" (or \"BottomLeft\")");
    Msg::Info("  \"Center\" (or \"BottomCenter\")");
    Msg::Info("  \"Right\" (or \"BottomRight\")");
    Msg::Info("  \"TopLeft\"");
    Msg::Info("  \"TopCenter\"");
    Msg::Info("  \"TopRight\"");
    Msg::Info("  \"CenterLeft\"");
    Msg::Info("  \"CenterCenter\"");
    Msg::Info("  \"CenterRight\"");
    return 0;
  }
  int getFontSize()
  {
    if(CTX::instance()->fontSize > 0) { return CTX::instance()->fontSize; }
    else {
      int h = Fl::h(); // main (first) screen
      if(h < 800)
        return 11;
      else if(h < 1000)
        return 12;
      else if(h < 1200)
        return 13;
      else if(h < 1400)
        return 14;
      else if(h < 1600)
        return 15;
      else if(h < 1800)
        return 16;
      float dpih, dpiv;
      Fl::screen_dpi(dpih, dpiv); // main (first) screen
      int s = std::max(16, (int)(dpih / 10.));
      return s;
    }
  }
  void setFont(int fontid, int fontsize) { gl_font(fontid, fontsize); }
  double getStringWidth(const char *str) { return gl_width(str); }
  int getStringHeight() { return gl_height(); }
  int getStringDescent() { return gl_descent(); }
  void drawString(const char *str) { gl_draw(str); }
  void resetFontTextures()
  {
#if((FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)) || defined(__APPLE__)
    // force font texture recomputation
    gl_texture_pile_height(gl_texture_pile_height());
#endif
  }
  std::string getName() { return "Fltk"; }
};

#endif
