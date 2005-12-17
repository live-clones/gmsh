// $Id: Opengl_Window.cpp,v 1.54 2005-12-17 23:13:20 geuzaine Exp $
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

extern GUI *WID;
extern Mesh M;
extern Context_T CTX;

void MousePosition::set()
{
  for(int i = 0; i < 3; i++){
    s[i] = CTX.s[i];
    t[i] = CTX.t[i];
  }

  win[0] = (double)Fl::event_x();
  win[1] = (double)Fl::event_y();
  win[2] = 0.;

  wnr[0] = (CTX.vxmin + win[0] / (double)CTX.viewport[2] * 
	    (CTX.vxmax - CTX.vxmin)) / CTX.s[0] - CTX.t[0];
  wnr[1] = (CTX.vymax - win[1] / (double)CTX.viewport[3] * 
	    (CTX.vymax - CTX.vymin)) / CTX.s[1] - CTX.t[1];
  wnr[2] = 0.;

  // might need this later
  // Viewport2World(win, world);
}

void MousePosition::recenter()
{
  // this computes the equivalent translation to apply after the
  // scaling so that the scaling is done around the point which was
  // clicked. FIXME: needs to be generalized to the case where an
  // initial translation is done BEFORE the scaling (necessary for the
  // general perspective case, with the line of sight in the middle of
  // the screen, and not just the z-axis).
  CTX.t[0] = t[0] * (s[0] / CTX.s[0]) - wnr[0] * (1. - (s[0] / CTX.s[0]));
  CTX.t[1] = t[1] * (s[1] / CTX.s[1]) - wnr[1] * (1. - (s[1] / CTX.s[1]));

  /*
  double sx, sy;
  double tx0, ty0;
  double tx, ty;
  double model_new[16];

  glPushMatrix();
  glLoadMatrix(CTX.model_init);
  glTranslated(tx0, ty0, 0.);
  glScaled(sx, sy, sz);
  glTranslated(-tx0, -ty0, 0.);
  glTranslated(tx, ty, 0.);
  glGetDoublev(GL_MODELVIEW_MATRIX, model_new);
  glPopMatrix();

  CTX.s[0] = model_new[0][0];
  CTX.s[1] = model_new[1][1];
  CTX.s[2] = model_new[2][2];

  CTX.t[0] = model_new[0][3];
  CTX.t[1] = model_new[1][3];
  CTX.t[2] = model_new[2][3];
  */
}
  
void myZoom(MousePosition &click1, MousePosition &click2)
{
  if(click1.win[0] == click2.win[0] || click1.win[1] == click2.win[1])
    return;

  CTX.s[0] *= (double)CTX.viewport[2] / (click2.win[0] - click1.win[0]);
  CTX.s[1] *= (double)CTX.viewport[3] / (click2.win[1] - click1.win[1]);
  CTX.s[2] = MIN(CTX.s[0], CTX.s[1]); // bof...
  
  MousePosition tmp(click1);
  tmp.wnr[0] = 0.5 * (click1.wnr[0] + click2.wnr[0]);
  tmp.wnr[1] = 0.5 * (click1.wnr[1] + click2.wnr[1]);
  tmp.t[0] = CTX.t[0];
  tmp.t[1] = CTX.t[1]; 
  tmp.recenter();

  InitPosition();
  Draw();
  WID->update_manip_window();
}

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
    ClearOpengl();
    Draw3d();
    Draw2d();
  }
  else {
    glDisable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
	    (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glColor3d(1., 1., 1.);
    // glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    glEnable(GL_BLEND);
    glLineWidth(0.2);
    for(int i = 0; i < 2; i++){
      glBegin(GL_LINE_STRIP);
      glVertex2d(click.win[0], CTX.viewport[3] - click.win[1]);
      glVertex2d(zoom.win[0], CTX.viewport[3] - click.win[1]);
      glVertex2d(zoom.win[0], CTX.viewport[3] - zoom.win[1]);
      glVertex2d(click.win[0], CTX.viewport[3] - zoom.win[1]);
      glVertex2d(click.win[0], CTX.viewport[3] - click.win[1]);
      glEnd();
      if(!i) zoom.set();
    }
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
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
  double dx, dy;
  int numhits;
  hit hits[SELECTION_BUFFER_SIZE];

  switch (event) {

  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // override the default widget navigation
    if(WID->arrow_shortcuts())
      return 1;
    return Fl_Gl_Window::handle(event);
    
  case FL_PUSH:
    take_focus(); // force keyboard focus when we click in the window
    curr.set();
    
    if(Fl::event_button() == 1 && 
       !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!ZoomMode && Fl::event_state(FL_CTRL)) {
        ZoomMode = true;
	zoom.set();
      }
      else if(ZoomMode) {
        ZoomMode = false;
	myZoom(click, curr);
      }
      else {
        WID->try_selection = 1;
      }
    }
    else if(Fl::event_button() == 2 || 
	    (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
      if(Fl::event_state(FL_CTRL) && !ZoomMode) {
        CTX.s[1] = CTX.s[0];
        CTX.s[2] = CTX.s[0];
        redraw();
      }
      else {
        ZoomMode = false;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !ZoomMode) {
        if(CTX.useTrackball)
          CTX.setQuaternion(0., 0., 0., 1.);
        else
          CTX.r[0] = CTX.r[1] = CTX.r[2] = 0.;
	CTX.t[0] = CTX.t[1] = CTX.t[2] = 0.;
	CTX.s[0] = CTX.s[1] = CTX.s[2] = 1.;
        redraw();
      }
      else {
        ZoomMode = false;
      }
    }

    click.set();
    prev.set();
    WID->update_manip_window();
    return 1;

  case FL_RELEASE:
    curr.set();
    if(!ZoomMode) {
      CTX.mesh.draw = 1;
      CTX.post.draw = 1;
      redraw();
    }
    prev.set();
    return 1;

  case FL_DRAG:
    curr.set();
    dx = curr.win[0] - prev.win[0];
    dy = curr.win[1] - prev.win[1];

    if(ZoomMode) {
      redraw();
    }
    else {
      if(Fl::event_button() == 1 && 
	 !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
        if(CTX.useTrackball)
          CTX.addQuaternion((2. * prev.win[0] - w()) / w(),
                            (h() - 2. * prev.win[1]) / h(),
                            (2. * curr.win[0] - w()) / w(),
                            (h() - 2. * curr.win[1]) / h());
        else {
          CTX.r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)w() : 0.);
	  CTX.r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)h());
        }
      }
      else if(Fl::event_button() == 2 ||
	      (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
        if(fabs(dy) > fabs(dx)) {
	  double fact = (CTX.zoom_factor * fabs(dy) + h()) / (double)h();
	  CTX.s[0] *= ((dy > 0) ? fact : 1./fact);
	  CTX.s[1] = CTX.s[0];
	  CTX.s[2] = CTX.s[0];
	  click.recenter();
	}
	else if(!CTX.useTrackball)
          CTX.r[2] += -180. * dx / (double)w();
      }
      else {
        CTX.t[0] += (curr.wnr[0] - click.wnr[0]);
	CTX.t[1] += (curr.wnr[1] - click.wnr[1]);
        CTX.t[2] = 0.;
      }
      if(CTX.fast_redraw) {
        CTX.mesh.draw = 0;
        CTX.post.draw = 0;
      }
      redraw();
    }

    prev.set();
    WID->update_manip_window();
    return 1;

  case FL_MOVE:
    curr.set();

    if(AddPointMode && !Fl::event_state(FL_SHIFT)){
      WID->g_opengl_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3],d[3];
      unproject(curr.win[0], curr.win[1], p, d);
      // fin closest point to the center of gravity
      double r[3] = {CTX.cg[0] - p[0], CTX.cg[1] - p[1], CTX.cg[2] - p[2]}, t;
      prosca(r,d,&t);
      double sol[3] = {p[0] + t * d[0], p[1] + t * d[1], p[2] + t * d[2]};
      char str[32];
      sprintf(str, "%g", sol[0]);        
      WID->context_geometry_input[2]->value(str);
      sprintf(str, "%g", sol[1]);
      WID->context_geometry_input[3]->value(str);
      sprintf(str, "%g", sol[2]);
      WID->context_geometry_input[4]->value(str);
    }
    else if(ZoomMode) {
      redraw();
    }
    else {
      WID->make_opengl_current();
      Process_SelectionBuffer((int)curr.win[0], (int)curr.win[1], &numhits, hits);
      ov = v; v = NULL;
      oc = c; c = NULL;
      os = s; s = NULL;
      Filter_SelectionBuffer(WID->selection, numhits, hits, &v, &c, &s, &M);
      if(ov != v || oc != c || os != s) {
        if((WID->selection == ENT_POINT && v) ||
	   (WID->selection == ENT_LINE && c) || 
	   (WID->selection == ENT_SURFACE && s))
          WID->g_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
        else
          WID->g_window->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
        HighlightEntity(v, c, s, 0);
      }
    }
    prev.set();
    return 1;

  default:
    return Fl_Gl_Window::handle(event);
  }
}
