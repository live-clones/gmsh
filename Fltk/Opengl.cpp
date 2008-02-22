// $Id: Opengl.cpp,v 1.77 2008-02-22 07:59:00 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include "GmshUI.h"
#include "GmshDefines.h"
#include "Numeric.h"
#include "Context.h"
#include "Draw.h"
#include "SelectBuffer.h"
#include "GUI.h"
#include "gl2ps.h"

extern GUI *WID;
extern Context_T CTX;

// Draw specialization

void SetOpenglContext(void)
{
  if(!WID) return;
  WID->make_opengl_current();
}

void Draw(void)
{
  if(!WID) return;
  WID->redraw_opengl();
}

void SanitizeTeXString(char *in, char *out)
{
  // if there is a '$' or a '\' in the string, assume the author knows
  // what he's doing:
  if(strstr(in, "$") || strstr(in, "\\")){
    strcpy(out, in);
    return;
  }

  if(CTX.print.tex_as_equation) *out++ = '$';

  // otherwise, escape the following special characters:
  char bad[8] = { '%', '^', '#', '%', '&', '_', '{', '}' };
  while(*in){
    for(unsigned int i = 0; i < sizeof(bad); i++){
      if(*in == bad[i]){
	*out++ = '\\';
	break;
      }
    }
    *out++ = *in++;
  }

  if(CTX.print.tex_as_equation) *out++ = '$';

  *out = '\0';
}

void Draw_String(char *s, char *font_name, int font_enum, int font_size, int align)
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
      float width = gl_width(s);
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
    gl_draw(s);
  }
  else{
    if(CTX.print.format == FORMAT_TEX){
      char tmp[1024];
      SanitizeTeXString(s, tmp);
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
      gl2psTextOpt(tmp, font_name, font_size, opt, 0.);
    }
    else if(CTX.print.eps_quality && (CTX.print.format == FORMAT_PS ||
				      CTX.print.format == FORMAT_EPS ||
				      CTX.print.format == FORMAT_PDF ||
				      CTX.print.format == FORMAT_SVG)){
      gl2psText(s, font_name, font_size);
    }
    else{
      gl_font(font_enum, font_size);
      gl_draw(s);
    }
  }
}

void Draw_String(char *s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 0);
}

void Draw_String_Center(char *s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 1);
}

void Draw_String_Right(char *s)
{
  Draw_String(s, CTX.gl_font, CTX.gl_font_enum, CTX.gl_fontsize, 2);
}

void Draw_String(char *s, double style)
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
    char *font_name = GetFontName(font);
    if(!size) size = CTX.gl_fontsize;
    Draw_String(s, font_name, font_enum, size, align);
  }
}

void Draw_OnScreenMessages()
{
  if(!WID) return;

  glColor4ubv((GLubyte *) & CTX.color.text);
  gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
  double h = gl_height();
  
  if(strlen(WID->onscreen_buffer[0])){
    double w = gl_width(WID->onscreen_buffer[0]);
    glRasterPos2d(CTX.viewport[2]/2.-w/2., CTX.viewport[3] - 1.2*h);
    gl_draw(WID->onscreen_buffer[0]);
  }
  if(strlen(WID->onscreen_buffer[1])){
    double w = gl_width(WID->onscreen_buffer[1]);
    glRasterPos2d(CTX.viewport[2]/2.-w/2., CTX.viewport[3] - 2.4*h);
    gl_draw(WID->onscreen_buffer[1]);
  }
}

// Select entity routine

char SelectEntity(int type, 
		  std::vector<GVertex*> &vertices,
		  std::vector<GEdge*> &edges,
		  std::vector<GFace*> &faces,
		  std::vector<GRegion*> &regions,
		  std::vector<MElement*> &elements)
{
  if(!WID) return 'q';

  WID->g_opengl_window->take_focus(); // force keyboard focus in GL window 
  WID->g_opengl_window->SelectionMode = true; // enable lasso selection

  WID->selection = type;
  WID->try_selection = 0;
  WID->quit_selection = 0;
  WID->end_selection = 0;
  WID->undo_selection = 0;
  WID->invert_selection = 0;

  while(1) {
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    WID->wait();
    if(WID->quit_selection) {
      WID->selection = ENT_NONE;
      WID->g_opengl_window->SelectionMode = false;
      WID->g_opengl_window->LassoMode = false;
      WID->g_opengl_window->AddPointMode = false;
      WID->g_opengl_window->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
      return 'q';
    }
    if(WID->end_selection) {
      WID->end_selection = 0;
      WID->selection = ENT_NONE;
      return 'e';
    }
    if(WID->undo_selection) {
      WID->undo_selection = 0;
      return 'u';
    }
    if(WID->invert_selection) {
      WID->invert_selection = 0;
      return 'i';
    }
    if(WID->try_selection) {
      bool add = (WID->try_selection > 0) ? true : false;
      bool multi = (abs(WID->try_selection) > 1) ? true : false;
      WID->try_selection = 0;
      if(WID->selection == ENT_NONE){ // just report the mouse click
	WID->g_opengl_window->SelectionMode = false;
	return 'c';
      }
      else if(ProcessSelectionBuffer(WID->selection, multi, true,
				     WID->try_selection_xywh[0],
				     WID->try_selection_xywh[1], 
				     WID->try_selection_xywh[2],
				     WID->try_selection_xywh[3], 
				     vertices, edges, faces, regions,
				     elements)){
	WID->selection = ENT_NONE;
	WID->g_opengl_window->SelectionMode = false;
	if(add)
	  return 'l';
	else
	  return 'r';
      }
    }
  }
}
