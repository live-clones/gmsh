// $Id: Opengl_Window.cpp,v 1.46 2005-03-09 02:18:40 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Numeric.h"
#include "GmshUI.h"
#include "Context.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "Opengl_Window.h"

// This file defines the Opengl_Window class (subclass of Fl_GL_Window)

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

void Process_SelectionBuffer(int x, int y, int *n, GLuint * ii, GLuint * jj);
void Filter_SelectionBuffer(int n, GLuint * typ, GLuint * ient,
                            Vertex ** thev, Curve ** thec, Surface ** thes,
                            Mesh * m);
void myZoom(GLdouble X1, GLdouble X2, GLdouble Y1, GLdouble Y2, GLdouble Xc1,
            GLdouble Xc2, GLdouble Yc1, GLdouble Yc2);
int check_type(int type, Vertex * v, Curve * c, Surface * s);

void Opengl_Window::draw()
{
  static int locked = 0;
  if(locked)
    return;
  else
    locked = 1;
  Msg(DEBUG, "Opengl_Window->draw()");
  if(!valid()) {
    valid(1);
    CTX.viewport[0] = 0;
    CTX.viewport[1] = 0;
    CTX.viewport[2] = w();
    CTX.viewport[3] = h();
    glViewport(CTX.viewport[0], CTX.viewport[1],
               CTX.viewport[2], CTX.viewport[3]);
  }
  else {
    if((w() != CTX.viewport[2] - CTX.viewport[0]) ||
       (h() != CTX.viewport[3] - CTX.viewport[1])) {
      WID->set_size(CTX.viewport[2] - CTX.viewport[0],
                    CTX.viewport[3] - CTX.viewport[1]);
      glViewport(CTX.viewport[0], CTX.viewport[1],
                 CTX.viewport[2], CTX.viewport[3]);
    }
  }

  if(!ZoomMode) {
    Orthogonalize(0, 0);
    ClearOpengl();
    Draw3d();
    Draw2d();
  }
  else {
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glColor3f(1., 1., 1.);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO); // glBlendEquation(GL_FUNC_ADD);
    glEnable(GL_BLEND);
    glLineWidth(0.2);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xzoom0, yzoom0);
    glVertex2d(xzoom1, yzoom0);
    glVertex2d(xzoom1, yzoom1);
    glVertex2d(xzoom0, yzoom1);
    glVertex2d(xzoom0, yzoom0);
    glEnd();
    xzoom1 = CTX.vxmin + ((double)Fl::event_x() / (double)w()) * 
      (CTX.vxmax - CTX.vxmin);
    yzoom1 = CTX.vymax - ((double)Fl::event_y() / (double)h()) *
      (CTX.vymax - CTX.vymin);
    glBegin(GL_LINE_STRIP);
    glVertex2d(xzoom0, yzoom0);
    glVertex2d(xzoom1, yzoom0);
    glVertex2d(xzoom1, yzoom1);
    glVertex2d(xzoom0, yzoom1);
    glVertex2d(xzoom0, yzoom0);
    glEnd();
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    ZoomMode = false;
  }
  locked = 0;
}

// The event model in FLTK is pretty different from other toolkits:
// the events are passed to the widget handle of the widget that has
// the focus. If this handle returns 1, then the event is considered
// as treated, and is suppressed. If the handle returns 0, the event
// is passed to the parent.

int Opengl_Window::handle(int event)
{
  GLuint ii[SELECTION_BUFFER_SIZE], jj[SELECTION_BUFFER_SIZE];

  switch (event) {

  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // this overrides the default navigation
    if(WID->arrow_shortcuts()) {
      return 1;
    }
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
    take_focus(); // force keyboard focus when we click in the window
    FirstClick = 1;
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    
    if(ibut == 1 && !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!ZoomClick && Fl::event_state(FL_CTRL)) {
        xzoom0 = xzoom1 = CTX.vxmin + ((double)xpos / (double)w()) *
	  (CTX.vxmax - CTX.vxmin);
        yzoom0 = yzoom1 = CTX.vymax - ((double)ypos / (double)h()) * 
	  (CTX.vymax - CTX.vymin);
        xc1 = xzoom0 / CTX.s[0] - CTX.t[0];
        yc1 = yzoom0 / CTX.s[1] - CTX.t[1];
        ZoomClick = true;
      }
      else if(ZoomClick) {
        xc2 = xzoom1 / CTX.s[0] - CTX.t[0];
        yc2 = yzoom1 / CTX.s[1] - CTX.t[1];
        ZoomClick = false;
        if(xzoom0 != xzoom1 && yzoom0 != yzoom1)
          myZoom(xzoom0, xzoom1, yzoom0, yzoom1, xc1, xc2, yc1, yc2);
      }
      else {
        WID->try_selection = 1;
      }
    }
    else if(ibut == 2 || (ibut == 1 && Fl::event_state(FL_SHIFT))) {
      if(Fl::event_state(FL_CTRL) && !ZoomClick) {
        set_s(1, CTX.s[0]);
        set_s(2, CTX.s[0]);
        redraw();
      }
      else {
        ZoomClick = false;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !ZoomClick) {
        if(CTX.useTrackball)
          CTX.setQuaternion(0., 0., 0., 1.);
        else {
          set_r(0, 0.);
          set_r(1, 0.);
          set_r(2, 0.);
        }
        set_t(0, 0.);
        set_t(1, 0.);
        set_t(2, 0.);
        set_s(0, 1.);
        set_s(1, 1.);
        set_s(2, 1.);
        redraw();
      }
      else {
        ZoomClick = false;
      }
    }
    return 1;

  case FL_RELEASE:
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();
    if(!ZoomClick) {
      CTX.mesh.draw = 1;
      CTX.post.draw = 1;
      redraw();
    }
    return 1;

  case FL_DRAG:
    xmov = Fl::event_x() - xpos;
    ymov = Fl::event_y() - ypos;

    if(ZoomClick) {
      ZoomMode = true;
      redraw();
    }
    else {
      if(FirstClick) {
        xc1 = (((double)xpos / (double)w()) * (CTX.vxmax - CTX.vxmin) + CTX.vxmin)
          / CTX.s[0] - CTX.t[0];
        yc1 = (CTX.vymax - ((double)ypos / (double)h()) * (CTX.vymax - CTX.vymin))
          / CTX.s[1] - CTX.t[1];
        xt1 = CTX.t[0];
        yt1 = CTX.t[1];
        xscale1 = CTX.s[0];
        yscale1 = CTX.s[1];
        FirstClick = 0;
      }

      if(ibut == 1 && !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
        if(CTX.useTrackball)
          CTX.addQuaternion((2.0 * xpos - w()) / w(),
                            (h() - 2.0 * ypos) / h(),
                            (2.0 * Fl::event_x() - w()) / w(),
                            (h() - 2.0 * Fl::event_y()) / h());
        else {
          set_r(1, CTX.r[1] + ((abs(xmov) > abs(ymov)) ?
			       180 * (double)xmov / (double)w() : 0));
          set_r(0, CTX.r[0] + ((abs(xmov) > abs(ymov)) ? 
			       0 : 180 * (double)ymov / (double)h()));
        }
      }
      else if(ibut == 2 || (ibut == 1 && Fl::event_state(FL_SHIFT))) {
	if(!CTX.useTrackball)
          set_r(2, CTX.r[2] + (abs(ymov) > abs(xmov) ? 
			       0 : -180 * (double)xmov / (double)w()));
	double zoomfact = (ymov > 0) ? 
	  (double)(CTX.zoom_factor * abs(ymov) + h()) / (double)h() : 
	  (double)(h()) / (double)(CTX.zoom_factor * abs(ymov) + h());
	set_s(0, CTX.s[0] * (abs(ymov) > abs(xmov) ? zoomfact : 1.));
        set_s(1, CTX.s[0]);
        set_s(2, CTX.s[0]);
        if(abs(ymov) > abs(xmov)) {
          set_t(0, xt1 * (xscale1 / CTX.s[0]) - xc1 * (1. - (xscale1 / CTX.s[0])));
          set_t(1, yt1 * (yscale1 / CTX.s[1]) - yc1 * (1. - (yscale1 / CTX.s[1])));
        }
      }
      else {
        xc = (((double)xpos / (double)w()) * (CTX.vxmax - CTX.vxmin) + CTX.vxmin)
          / CTX.s[0];
        yc = (CTX.vymax - ((double)ypos / (double)h()) * (CTX.vymax - CTX.vymin))
          / CTX.s[1];
        set_t(0, xc - xc1);
        set_t(1, yc - yc1);
        set_t(2, 0.);
      }

      if(CTX.fast_redraw) {
        CTX.mesh.draw = 0;
        CTX.post.draw = 0;
      }

      redraw();
    }

    xpos += xmov;
    ypos += ymov;
    return 1;

  case FL_MOVE:
    xmov = Fl::event_x() - xpos;
    ymov = Fl::event_y() - ypos;
    
    if(AddPointMode && !Fl::event_state(FL_SHIFT)){
      WID->g_opengl_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3],d[3];
      unproject(Fl::event_x(), Fl::event_y(), p, d);
      // fin closest point to the center of gravity
      double r[3] = {CTX.cg[0]-p[0], CTX.cg[1]-p[1], CTX.cg[2]-p[2]};
      double t;
      prosca(r,d,&t);
      double sol[3] = {p[0]+t*d[0], p[1]+t*d[1], p[2]+t*d[2]};
      char str[32];
      sprintf(str, "%g", sol[0]);        
      WID->context_geometry_input[2]->value(str);
      sprintf(str, "%g", sol[1]);
      WID->context_geometry_input[3]->value(str);
      sprintf(str, "%g", sol[2]);
      WID->context_geometry_input[4]->value(str);
    }

    if(ZoomClick) {
      ZoomMode = true;
      redraw();
    }
    else {
      WID->make_opengl_current();
      Process_SelectionBuffer(Fl::event_x(), Fl::event_y(), &hits, ii, jj);
      ov = v;
      oc = c;
      os = s;
      v = NULL;
      c = NULL;
      s = NULL;
      Filter_SelectionBuffer(hits, ii, jj, &v, &c, &s, &M);
      if(ov != v || oc != c || os != s) {
        if(check_type(WID->selection, v, c, s))
          WID->g_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
        else
          WID->g_window->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
        HighlightEntity(v, c, s, 0);
      }
    }

    xpos += xmov;
    ypos += ymov;
    return 1;

  default:
    return Fl_Gl_Window::handle(event);

  }

}
