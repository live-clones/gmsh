// $Id: Opengl_Window.cpp,v 1.34 2004-05-17 17:40:03 geuzaine Exp $
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

static int ZOOM = 0;
static double ZOOM_X0, ZOOM_Y0, ZOOM_X1, ZOOM_Y1;

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

  if(!ZOOM) {
    Orthogonalize(0, 0);
    ClearOpengl();
    Draw3d();
    Draw2d();
  }
  else {
    glPopMatrix();
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(CTX.vxmin, CTX.vxmax, CTX.vymin, CTX.vymax);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glColor3f(1., 1., 1.);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    glEnable(GL_BLEND);
    glLineWidth(0.2);
    glBegin(GL_LINE_STRIP);
    glVertex2d(ZOOM_X0, ZOOM_Y0);
    glVertex2d(ZOOM_X1, ZOOM_Y0);
    glVertex2d(ZOOM_X1, ZOOM_Y1);
    glVertex2d(ZOOM_X0, ZOOM_Y1);
    glVertex2d(ZOOM_X0, ZOOM_Y0);
    glEnd();
    ZOOM_X1 =
      CTX.vxmin + ((double)Fl::event_x() / (double)w()) * (CTX.vxmax -
                                                           CTX.vxmin);
    ZOOM_Y1 =
      CTX.vymax - ((double)Fl::event_y() / (double)h()) * (CTX.vymax -
                                                           CTX.vymin);
    glBegin(GL_LINE_STRIP);
    glVertex2d(ZOOM_X0, ZOOM_Y0);
    glVertex2d(ZOOM_X1, ZOOM_Y0);
    glVertex2d(ZOOM_X1, ZOOM_Y1);
    glVertex2d(ZOOM_X0, ZOOM_Y1);
    glVertex2d(ZOOM_X0, ZOOM_Y0);
    glEnd();
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    ZOOM = 0;
  }
  locked = 0;
}

void Opengl_Window::draw_overlay()
{
}

void Opengl_Window::clear_overlay()
{
}


// The event model in FLTK is pretty different from other toolkits:
// the events are passed to the widget handle of the widget that has
// the focus. If this handle returns 1, then the event is considered
// as treated, and is suppressed. If the handle returns 0, the event
// is passed to the parent.

int Opengl_Window::handle(int event)
{
  static int xpos, ypos, xmov, ymov, ibut, hits;
  static int ZoomClick = 0, FirstClick = 0;
  static GLdouble xc, yc, xc1, yc1, xc2, yc2, xt1, yt1, xscale1, yscale1;
  static Vertex *v = NULL, *ov;
  static Curve *c = NULL, *oc;
  static Surface *s = NULL, *os;

  GLuint ii[SELECTION_BUFFER_SIZE], jj[SELECTION_BUFFER_SIZE];

  switch (event) {

  case FL_ENTER:
    take_focus();       //force keyboard focus on the Opengl_Window
    return 1;

  case FL_LEAVE:
    return 1;

  case FL_FOCUS:
    return 1;

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
    FirstClick = 1;
    ibut = Fl::event_button();
    xpos = Fl::event_x();
    ypos = Fl::event_y();

    if(ibut == 1 && !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!ZoomClick && Fl::event_state(FL_CTRL)) {
        ZOOM_X0 = ZOOM_X1 =
          CTX.vxmin + ((double)xpos / (double)w()) * (CTX.vxmax - CTX.vxmin);
        ZOOM_Y0 = ZOOM_Y1 =
          CTX.vymax - ((double)ypos / (double)h()) * (CTX.vymax - CTX.vymin);
        xc1 = ZOOM_X0 / CTX.s[0] - CTX.t[0];
        yc1 = ZOOM_Y0 / CTX.s[1] - CTX.t[1];
        ZoomClick = 1;
      }
      else if(ZoomClick) {
        xc2 = ZOOM_X1 / CTX.s[0] - CTX.t[0];
        yc2 = ZOOM_Y1 / CTX.s[1] - CTX.t[1];
        ZoomClick = 0;
        clear_overlay();
        if(ZOOM_X0 != ZOOM_X1 && ZOOM_Y0 != ZOOM_Y1)
          myZoom(ZOOM_X0, ZOOM_X1, ZOOM_Y0, ZOOM_Y1, xc1, xc2, yc1, yc2);
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
        ZoomClick = 0;
        clear_overlay();
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
        ZoomClick = 0;
        clear_overlay();
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
      ZOOM = 1;
      redraw();
    }
    else {
      clear_overlay();

      if(FirstClick) {
        xc1 =
          (((double)xpos / (double)w()) * (CTX.vxmax - CTX.vxmin) + CTX.vxmin)
          / CTX.s[0] - CTX.t[0];
        yc1 =
          (CTX.vymax - ((double)ypos / (double)h()) * (CTX.vymax - CTX.vymin))
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
          set_r(1,
                CTX.r[1] +
                ((abs(xmov) >
                  abs(ymov)) ? 180 * (float)xmov / (float)w() : 0));
          set_r(0,
                CTX.r[0] +
                ((abs(xmov) >
                  abs(ymov)) ? 0 : 180 * (float)ymov / (float)h()));
        }
      }
      else if(ibut == 2 || (ibut == 1 && Fl::event_state(FL_SHIFT))) {
        if(!CTX.useTrackball)
          set_r(2,
                CTX.r[2] +
                ((abs(ymov) >
                  abs(xmov)) ? 0 : -180 * (float)xmov / (float)w()));
        set_s(0,
              CTX.s[0] *
              ((abs(ymov) >
                abs(xmov)) ? ((ymov >
                               0) ? (float)(CTX.zoom_factor * (abs(ymov) +
                                                               h())) /
                              (float)h()
                              : (float)(h()) / (float)(CTX.zoom_factor *
                                                       (abs(ymov) + h())))
               : 1.));
        set_s(1, CTX.s[0]);
        set_s(2, CTX.s[0]);
        if(abs(ymov) > abs(xmov)) {
          set_t(0,
                xt1 * (xscale1 / CTX.s[0]) - xc1 * (1. -
                                                    (xscale1 / CTX.s[0])));
          set_t(1,
                yt1 * (yscale1 / CTX.s[1]) - yc1 * (1. -
                                                    (yscale1 / CTX.s[1])));
        }
      }
      else {
        xc =
          (((double)xpos / (double)w()) * (CTX.vxmax - CTX.vxmin) + CTX.vxmin)
          / CTX.s[0];
        yc =
          (CTX.vymax - ((double)ypos / (double)h()) * (CTX.vymax - CTX.vymin))
          / CTX.s[1];
        set_t(0, xc - xc1);
        set_t(1, yc - yc1);
        set_t(2, 0.);
      }

      if(CTX.fast) {
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

    if(ZoomClick) {
      ZOOM = 1;
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
