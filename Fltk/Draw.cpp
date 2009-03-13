// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GUI.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Draw.h"
#include "StringUtils.h"
#include "gl2ps.h"
#include "Context.h"

void Draw()
{
  if(!GUI::available()) return;
  for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++){
    for(unsigned int j = 0; j < GUI::instance()->graph[i]->gl.size(); j++){
      GUI::instance()->graph[i]->gl[j]->make_current();
      GUI::instance()->graph[i]->gl[j]->redraw();
    }
  }
  GUI::instance()->check();
}

void DrawCurrentOpenglWindow(bool make_current)
{
  if(!GUI::available()) return;
  openglWindow *gl = GUI::instance()->getCurrentOpenglWindow();
  if(make_current) gl->make_current();
  gl->redraw();
}

void DrawPlugin(void (*draw)(void *context))
{
  CTX::instance()->post.pluginDrawFunction = draw;
  int old = CTX::instance()->drawBBox;
  CTX::instance()->drawBBox = 1;
  if(CTX::instance()->fastRedraw){
    CTX::instance()->post.draw = 0;
    CTX::instance()->mesh.draw = 0;
  }
  Draw();
  // this is reset in each plugin run/cancel callback:
  // CTX::instance()->post.pluginDrawFunction = NULL;
  CTX::instance()->drawBBox = old;
  CTX::instance()->post.draw = 1;
  CTX::instance()->mesh.draw = 1;
}

int GetFontIndex(const char *fontname)
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

int GetFontEnum(int index)
{
  if(index >= 0 && index < NUM_FONTS)
    return (long)menu_font_names[index].user_data();
  return FL_HELVETICA;
}

const char *GetFontName(int index)
{
  if(index >= 0 && index < NUM_FONTS)
    return menu_font_names[index].label();
  return "Helvetica";
}

int GetFontAlign(const char *alignstr)
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

int GetFontSize()
{
  if(CTX::instance()->fontSize > 0){
    return CTX::instance()->fontSize;
  }
  else{
    int w = Fl::w();
    if(w <= 1024)      return 11;
    else if(w <= 1280) return 12;
    else if(w <= 1680) return 13;
    else if(w <= 1920) return 14;
    else               return 15;
  }
}
