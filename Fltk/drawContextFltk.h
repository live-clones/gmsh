// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _DRAW_CONTEXT_FLTK_H_
#define _DRAW_CONTEXT_FLTK_H_

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <FL/x.H>
#include <FL/gl.h>
#include "FlGui.h"
#include "drawContext.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "openglWindow.h"
#include "Context.h"

class drawContextFltk : public drawContextGlobal{
 public:
  void draw()
  {
    if(!FlGui::available()) return;
    if(FlGui::instance()->fullscreen->shown()){
      FlGui::instance()->fullscreen->make_current();
      FlGui::instance()->fullscreen->redraw();
    }
    else{
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++){
        for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++){
          FlGui::instance()->graph[i]->gl[j]->make_current();
          FlGui::instance()->graph[i]->gl[j]->redraw();
          glFlush();
          // FIXME: I don't think this should be done here
          drawContext *ctx = FlGui::instance()->graph[i]->gl[j]->getDrawContext();
          ctx->camera.update();
        }
      }
    }
    FlGui::instance()->check();
  }
  void drawCurrentOpenglWindow(bool make_current)
  {
    if(!FlGui::available()) return;
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(make_current) gl->make_current();
    gl->redraw();
    glFlush();
    FlGui::instance()->check();
  }
  int getFontIndex(const char *fontname)
  {
    if(fontname){
      for(int i = 0; i < NUM_FONTS; i++)
        if(!strcmp(menu_font_names[i].label(), fontname))
          return i;
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
    if(index >= 0 && index < NUM_FONTS)
      return menu_font_names[index].label();
    return "Helvetica";
  }
  int getFontAlign(const char *alignstr)
  {
    if(alignstr){
      if(!strcmp(alignstr, "BottomLeft") || !strcmp(alignstr, "Left") ||
         !strcmp(alignstr, "left"))
        return 0;
      else if(!strcmp(alignstr, "BottomCenter") || !strcmp(alignstr, "Center") ||
              !strcmp(alignstr, "center"))
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
    Msg::Error("Unknown font alignment \"%s\" (using \"Left\" instead)", alignstr);
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
    if(CTX::instance()->fontSize > 0){
      return CTX::instance()->fontSize;
    }
    else{
      int w = Fl::w();
      if(w <= 1024)      return 11;
      else if(w <= 1440) return 12;
      else if(w <= 1680) return 13;
      else if(w <= 1920) return 14;
      return (w - 1920) / 160 + 15;
      /*
      float dpih, dpiv;
      Fl::screen_dpi(dpih, dpiv);
      return (int)(dpih / 8.);
      */
    }
  }
  void setFont(int fontid, int fontsize)
  {
    gl_font(fontid, fontsize);
  }
  double getStringWidth(const char *str)
  {
    return gl_width(str);
  }
  int getStringHeight()
  {
    return gl_height();
  }
  int getStringDescent()
  {
    return gl_descent();
  }
  void drawString(const char *str)
  {
    gl_draw(str);
  }
  void resetFontTextures()
  {
#if defined(__APPLE__)
    gl_texture_pile_height(gl_texture_pile_height()); // force font texture recomputation
#endif
  }
  std::string getName(){ return "Fltk"; }
};

#endif
