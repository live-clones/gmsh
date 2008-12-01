// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/gl.h>
#include <FL/glu.h>
#include "GUI.h"
#include "graphicWindow.h"
#include "GmshDefines.h"
#include "Draw.h"
#include "StringUtils.h"
#include "gl2ps.h"
#include "Context.h"

extern Context_T CTX;

void SetOpenglContext()
{
  if(!GUI::available()) return;
  GUI::instance()->graph[0]->gl->make_current();
}

void ClearOpengl()
{
  glClearColor(CTX.UNPACK_RED(CTX.color.bg) / 255.,
               CTX.UNPACK_GREEN(CTX.color.bg) / 255.,
               CTX.UNPACK_BLUE(CTX.color.bg) / 255., 0.);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Draw()
{
  if(!GUI::available()) return;
  GUI::instance()->graph[0]->gl->make_current();
  GUI::instance()->graph[0]->gl->redraw();
  GUI::instance()->check();
}

void Draw2d3d()
{
  if(!GUI::available()) return;
  GUI::instance()->graph[0]->gl->getDrawContext()->draw3d();
  GUI::instance()->graph[0]->gl->getDrawContext()->draw2d();
}

void DrawPlugin(void (*draw)(void *context))
{
  CTX.post.plugin_draw_function = draw;
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  Draw();
  // this is reset in each plugin run/cancel callback:
  // CTX.post.plugin_draw_function = NULL;
  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
}

void Draw_String(std::string s, const char *font_name, int font_enum, 
                 int font_size, int align)
{
  if(CTX.printing && !CTX.print.text) return;

  // change the raster position only if not creating TeX files
  if(align > 0 && (!CTX.printing || CTX.print.format != FORMAT_TEX)){
    GLboolean valid;
    glGetBooleanv(GL_CURRENT_RASTER_POSITION_VALID, &valid);
    if(valid == GL_TRUE){
      GLdouble pos[4];
      glGetDoublev(GL_CURRENT_RASTER_POSITION, pos);
      double x[3], w[3] = {pos[0], pos[1], pos[2]};
      gl_font(font_enum, font_size);
      float width = gl_width(s.c_str());
      float height = gl_height();
      switch(align){
      case 1: w[0] -= width/2.;                     break; // bottom center
      case 2: w[0] -= width;                        break; // bottom right
      case 3:                    w[1] -= height;    break; // top left
      case 4: w[0] -= width/2.;  w[1] -= height;    break; // top center
      case 5: w[0] -= width;     w[1] -= height;    break; // top right
      case 6:                    w[1] -= height/2.; break; // center left
      case 7: w[0] -= width/2.;  w[1] -= height/2.; break; // center center
      case 8: w[0] -= width;     w[1] -= height/2.; break; // center right
      default: break;
      }
      Viewport2World(w, x);
      glRasterPos3d(x[0], x[1], x[2]);
    }
  }
  
  if(!CTX.printing){
    gl_font(font_enum, font_size);
    gl_draw(s.c_str());
  }
  else{
    if(CTX.print.format == FORMAT_TEX){
      std::string tmp = SanitizeTeXString(s.c_str(), CTX.print.tex_as_equation);
      int opt;
      switch(align){
      case 1: opt = GL2PS_TEXT_B;   break; // bottom center
      case 2: opt = GL2PS_TEXT_BR;  break; // bottom right
      case 3: opt = GL2PS_TEXT_TL;  break; // top left
      case 4: opt = GL2PS_TEXT_T;   break; // top center
      case 5: opt = GL2PS_TEXT_TR;  break; // top right
      case 6: opt = GL2PS_TEXT_CL;  break; // center left
      case 7: opt = GL2PS_TEXT_C;   break; // center center
      case 8: opt = GL2PS_TEXT_CR;  break; // center right
      default: opt = GL2PS_TEXT_BL; break; // bottom left
      }
      gl2psTextOpt(tmp.c_str(), font_name, font_size, opt, 0.);
    }
    else if(CTX.print.eps_quality && (CTX.print.format == FORMAT_PS ||
                                      CTX.print.format == FORMAT_EPS ||
                                      CTX.print.format == FORMAT_PDF ||
                                      CTX.print.format == FORMAT_SVG)){
      gl2psText(s.c_str(), font_name, font_size);
    }
    else{
      gl_font(font_enum, font_size);
      gl_draw(s.c_str());
    }
  }
}

void Draw_String(std::string s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 0);
}

void Draw_String_Center(std::string s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 1);
}

void Draw_String_Right(std::string s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 2);
}

void Draw_String(std::string s, double style)
{
  unsigned int bits = (unsigned int)style;

  if(!bits){ // use defaults
    Draw_String(s);
  }
  else{
    int size = (bits & 0xff);
    int font = (bits>>8 & 0xff);
    int align = (bits>>16 & 0xff);
    int font_enum = GetFontEnum(font);
    const char *font_name = GetFontName(font);
    if(!size) size = CTX.gl_fontsize;
    Draw_String(s, font_name, font_enum, size, align);
  }
}

void Draw_OnScreenMessages()
{
  if(!GUI::available()) return;

  glColor4ubv((GLubyte *) & CTX.color.text);
  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  double h = gl_height();
  
  drawContext *ctx = GUI::instance()->graph[0]->gl->getDrawContext();
  
  if(strlen(GUI::instance()->onscreen_buffer[0])){
    double w = gl_width(GUI::instance()->onscreen_buffer[0]);
    glRasterPos2d(ctx->viewport[2] / 2. - w / 2., 
                  ctx->viewport[3] - 1.2 * h);
    gl_draw(GUI::instance()->onscreen_buffer[0]);
  }
  if(strlen(GUI::instance()->onscreen_buffer[1])){
    double w = gl_width(GUI::instance()->onscreen_buffer[1]);
    glRasterPos2d(ctx->viewport[2] / 2. - w / 2.,
                  ctx->viewport[3] - 2.4 * h);
    gl_draw(GUI::instance()->onscreen_buffer[1]);
  }
}

void GetStoredViewport(int viewport[4])
{
  if(!GUI::available()) return;
  for(int i = 0; i < 4; i++)
    viewport[i] = GUI::instance()->graph[0]->gl->getDrawContext()->viewport[i];
}

void Viewport2World(double win[3], double xyz[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluUnProject(win[0], win[1], win[2], model, proj, viewport, &xyz[0], &xyz[1], &xyz[2]);
}

void World2Viewport(double xyz[3], double win[3])
{
  GLint viewport[4];
  GLdouble model[16], proj[16];
  glGetIntegerv(GL_VIEWPORT, viewport);
  glGetDoublev(GL_PROJECTION_MATRIX, proj);
  glGetDoublev(GL_MODELVIEW_MATRIX, model);
  gluProject(xyz[0], xyz[1], xyz[2], model, proj, viewport, &win[0], &win[1], &win[2]);
}
