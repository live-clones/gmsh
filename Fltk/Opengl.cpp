// $Id: Opengl.cpp,v 1.37 2004-05-17 17:56:37 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "Context.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "gl2ps.h"

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

void Process_SelectionBuffer(int x, int y, int *n, GLuint * ii, GLuint * jj);
void Filter_SelectionBuffer(int n, GLuint * typ, GLuint * ient,
                            Vertex ** thev, Curve ** thec, Surface ** thes,
                            Mesh * m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2, GLdouble Xc1,
            GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);

// Draw specialization

void InitOpengl(void)
{
  WID->make_opengl_current();
  Orthogonalize(0, 0);
}

void SetOpenglContext(void)
{
  WID->make_opengl_current();
}

void InitOverlay(void)
{
  WID->make_overlay_current();
  Orthogonalize(0, 0);
}

void ClearOpengl(void)
{
  glClearColor(UNPACK_RED(CTX.color.bg) / 255.,
               UNPACK_GREEN(CTX.color.bg) / 255.,
               UNPACK_BLUE(CTX.color.bg) / 255., 0.);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void Draw(void)
{
  WID->redraw_opengl();
}

void DrawUI(void)
{
  WID->check();
}

void Draw_String(char *s)
{

  if(CTX.print.gl_fonts) {
    gl_font(CTX.gl_font_enum, CTX.gl_fontsize);
    gl_draw(s);
  }
  else {        // ps or *tex output
    if(CTX.print.format == FORMAT_JPEGTEX ||
       CTX.print.format == FORMAT_PNGTEX)
      return;
    gl2psText(s, CTX.gl_font, CTX.gl_fontsize);
  }
}

// Euler angles set_XXX

void set_r(int i, double val)
{
  if(!CTX.useTrackball) {
    if(!CTX.rlock[i]) {
      CTX.r[i] = val;
    }
  }
}

void set_t(int i, double val)
{
  if(!CTX.tlock[i]) {
    CTX.t[i] = val;
  }
}

void set_s(int i, double val)
{
  if(!CTX.slock[i]) {
    CTX.s[i] = val;
  }
}

// Select entity routines

int check_type(int type, Vertex * v, Curve * c, Surface * s)
{
  return ((type == ENT_POINT && v) ||
          (type == ENT_LINE && c) || 
	  (type == ENT_SURFACE && s));
}

int SelectEntity(int type, Vertex ** v, Curve ** c, Surface ** s)
{
  int hits;
  GLuint ii[SELECTION_BUFFER_SIZE], jj[SELECTION_BUFFER_SIZE];

  WID->selection = type;
  WID->try_selection = 0;
  WID->quit_selection = 0;
  WID->end_selection = 0;

  while(1) {
    *v = NULL;
    *c = NULL;
    *s = NULL;

    WID->wait();
    if(WID->quit_selection) {
      WID->quit_selection = 0;
      WID->selection = 0;
      return 0;
    }
    if(WID->end_selection) {
      WID->end_selection = 0;
      WID->selection = 0;
      return -1;
    }
    if(WID->try_selection) {
      WID->try_selection = 0;
      Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
      Filter_SelectionBuffer(hits, ii, jj, v, c, s, &M);
      if(check_type(type, *v, *c, *s)) {
        HighlightEntity(*v, *c, *s, 1);
        WID->selection = 0;
        return 1;
      }
    }
  }

}
