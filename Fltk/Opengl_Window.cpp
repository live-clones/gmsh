// $Id: Opengl_Window.cpp,v 1.82 2008-02-17 08:47:57 geuzaine Exp $
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

#include "GmshUI.h"
#include "GmshDefines.h"
#include "Message.h"
#include "Numeric.h"
#include "Context.h"
#include "Draw.h"
#include "SelectBuffer.h"
#include "GUI.h"
#include "Opengl_Window.h"
#include "MElement.h"

extern GUI *WID;
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

  wnr[0] = 
    (CTX.vxmin + win[0] / (double)CTX.viewport[2] * (CTX.vxmax - CTX.vxmin)) 
    / CTX.s[0] - CTX.t[0] + CTX.t_init[0] / CTX.s[0];
  wnr[1] = 
    (CTX.vymax - win[1] / (double)CTX.viewport[3] * (CTX.vymax - CTX.vymin))
    / CTX.s[1] - CTX.t[1] + CTX.t_init[1] / CTX.s[1];
  wnr[2] = 0.;
}

void MousePosition::recenter()
{
  // compute the equivalent translation to apply *after* the scaling
  // so that the scaling is done around the point which was clicked:
  CTX.t[0] = t[0] * (s[0] / CTX.s[0]) - wnr[0] * (1. - (s[0] / CTX.s[0]));
  CTX.t[1] = t[1] * (s[1] / CTX.s[1]) - wnr[1] * (1. - (s[1] / CTX.s[1]));
}
  
void lasso_zoom(MousePosition &click1, MousePosition &click2)
{
  if(click1.win[0] == click2.win[0] || click1.win[1] == click2.win[1])
    return;

  CTX.s[0] *= (double)CTX.viewport[2] / (click2.win[0] - click1.win[0]);
  CTX.s[1] *= (double)CTX.viewport[3] / (click2.win[1] - click1.win[1]);
  CTX.s[2] = MIN(CTX.s[0], CTX.s[1]); // bof...
  
  // recenter around the center of the lasso rectangle
  MousePosition tmp(click1);
  tmp.wnr[0] = 0.5 * (click1.wnr[0] + click2.wnr[0]);
  tmp.wnr[1] = 0.5 * (click1.wnr[1] + click2.wnr[1]);
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

  if(LassoMode) { 
    // draw the zoom or selection lasso on top of the current scene
    // (without using overlays!)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
	    (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3d(1., 1., 1.);
    glDisable(GL_DEPTH_TEST);
    if(SelectionMode && CTX.mouse_selection){
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x0F0F);
    }
    // glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    glEnable(GL_BLEND);
    glLineWidth(0.2);
    for(int i = 0; i < 2; i++){
      glBegin(GL_LINE_STRIP);
      glVertex2d(click.win[0], CTX.viewport[3] - click.win[1]);
      glVertex2d(lasso.win[0], CTX.viewport[3] - click.win[1]);
      glVertex2d(lasso.win[0], CTX.viewport[3] - lasso.win[1]);
      glVertex2d(click.win[0], CTX.viewport[3] - lasso.win[1]);
      glVertex2d(click.win[0], CTX.viewport[3] - click.win[1]);
      glEnd();
      if(!i) lasso.set();
    }
    glDisable(GL_BLEND);
    if(SelectionMode && CTX.mouse_selection)
      glDisable(GL_LINE_STIPPLE);
    glEnable(GL_DEPTH_TEST);
  }
  else if(AddPointMode) { 
    // draw the whole scene and the point to add
    if(CTX.fast_redraw) {
      CTX.mesh.draw = 0;
      CTX.post.draw = 0;
    }
    ClearOpengl();
    Draw3d();
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glPointSize(CTX.geom.point_size);
    glBegin(GL_POINTS);
    glVertex3d(point[0], point[1], point[2]);
    glEnd();
    Draw2d();
    CTX.mesh.draw = 1;
    CTX.post.draw = 1;
  }
  else{
    // draw the whole scene
    ClearOpengl();
    Draw3d();
    Draw2d();
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
  switch (event) {

  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // override the default widget arrow-key-navigation
    if(WID->arrow_shortcuts())
      return 1;
    return Fl_Gl_Window::handle(event);
    
  case FL_PUSH:
    take_focus(); // force keyboard focus when we click in the window
    curr.set();
    if(Fl::event_button() == 1 && 
       !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!LassoMode && Fl::event_state(FL_CTRL)) {
        LassoMode = true;
	lasso.set();
      }
      else if(LassoMode) {
        LassoMode = false;
	if(SelectionMode && CTX.mouse_selection){
	  WID->try_selection = 2; // will try to select multiple entities
	  WID->try_selection_xywh[0] = (int)(click.win[0] + curr.win[0])/2;
	  WID->try_selection_xywh[1] = (int)(click.win[1] + curr.win[1])/2;
	  WID->try_selection_xywh[2] = (int)fabs(click.win[0] - curr.win[0]);
	  WID->try_selection_xywh[3] = (int)fabs(click.win[1] - curr.win[1]);
	}
	else{
	  lasso_zoom(click, curr);
	}
      }
      else if(CTX.mouse_selection){
        WID->try_selection = 1; // will try to select clicked entity
	WID->try_selection_xywh[0] = (int)curr.win[0];
	WID->try_selection_xywh[1] = (int)curr.win[1];
	WID->try_selection_xywh[2] = 5;
	WID->try_selection_xywh[3] = 5;
      }
    }
    else if(Fl::event_button() == 2 || 
	    (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
      if(!LassoMode && Fl::event_state(FL_CTRL)) {
	// make zoom isotropic
        CTX.s[1] = CTX.s[0];
        CTX.s[2] = CTX.s[0];
        redraw();
      }
      else if(LassoMode) {
	LassoMode = false;
	if(SelectionMode && CTX.mouse_selection){
	  WID->try_selection = -2; // will try to unselect multiple entities
	  WID->try_selection_xywh[0] = (int)(click.win[0] + curr.win[0])/2;
	  WID->try_selection_xywh[1] = (int)(click.win[1] + curr.win[1])/2;
	  WID->try_selection_xywh[2] = (int)fabs(click.win[0] - curr.win[0]);
	  WID->try_selection_xywh[3] = (int)fabs(click.win[1] - curr.win[1]);
	}
	else{
	  lasso_zoom(click, curr);
	}
      }
      else if(CTX.mouse_selection){
        WID->try_selection = -1; // will try to unselect clicked entity
	WID->try_selection_xywh[0] = (int)curr.win[0];
	WID->try_selection_xywh[1] = (int)curr.win[1];
	WID->try_selection_xywh[2] = 5;
	WID->try_selection_xywh[3] = 5;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !LassoMode) {
        if(CTX.useTrackball)
          CTX.setQuaternion(0., 0., 0., 1.);
        else
          CTX.r[0] = CTX.r[1] = CTX.r[2] = 0.;
	CTX.t[0] = CTX.t[1] = CTX.t[2] = 0.;
	CTX.s[0] = CTX.s[1] = CTX.s[2] = 1.;
        redraw();
      }
      else {
        LassoMode = false;
      }
    }
    click.set();
    prev.set();
    WID->update_manip_window();
    return 1;

  case FL_RELEASE:
    curr.set();
    CTX.draw_rotation_center = 0;
    if(!LassoMode) {
      CTX.mesh.draw = 1;
      CTX.post.draw = 1;
      redraw();
    }
    prev.set();
    return 1;

  case FL_MOUSEWHEEL:
    {
      double dy = Fl::event_dy();
      double fact = (5. * CTX.zoom_factor * fabs(dy) + h()) / (double)h();
      CTX.s[0] *= ((dy > 0) ? fact : 1./fact);
      CTX.s[1] = CTX.s[0];
      CTX.s[2] = CTX.s[0];
      prev.recenter();
      redraw();
    }
    WID->update_manip_window();
    return 1;

  case FL_DRAG:
    curr.set();
    {
      double dx = curr.win[0] - prev.win[0];
      double dy = curr.win[1] - prev.win[1];
      if(LassoMode) {
	redraw();
      }
      else {
	if(Fl::event_state(FL_META)) {
	  // will try to select or unselect entities on the fly
	  WID->try_selection = Fl::event_state(FL_SHIFT) ? -1 : 1; 
	  WID->try_selection_xywh[0] = (int)curr.win[0];
	  WID->try_selection_xywh[1] = (int)curr.win[1];
	  WID->try_selection_xywh[2] = 5;
	  WID->try_selection_xywh[3] = 5;
	}
	else if(Fl::event_button() == 1 && 
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
	CTX.draw_rotation_center = 1;
	if(CTX.fast_redraw) {
	  CTX.mesh.draw = 0;
	  CTX.post.draw = 0;
	}
	redraw();
      }
    }
    prev.set();
    WID->update_manip_window();
    return 1;

  case FL_MOVE:
    curr.set();
    if(LassoMode) {
      redraw();
    }
    else if(AddPointMode && !Fl::event_state(FL_SHIFT)){
      WID->g_opengl_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3],d[3];
      Unproject(curr.win[0], curr.win[1], p, d);
      // fin closest point to the center of gravity
      double r[3] = {CTX.cg[0] - p[0], CTX.cg[1] - p[1], CTX.cg[2] - p[2]}, t;
      prosca(r, d, &t);
      for(int i = 0; i < 3; i++){
	point[i] = p[i] + t * d[i];
	if(CTX.geom.snap[i]){
	  double d = point[i]/CTX.geom.snap[i];
	  double f = floor(d);
	  double c = ceil(d);
	  double n = (d - f < c - d) ? f : c;
	  point[i] = n * CTX.geom.snap[i];
	}
      }
      char str[32];
      sprintf(str, "%g", point[0]); WID->context_geometry_input[2]->value(str);
      sprintf(str, "%g", point[1]); WID->context_geometry_input[3]->value(str);
      sprintf(str, "%g", point[2]); WID->context_geometry_input[4]->value(str);
      redraw();
    }
    else{ // hover mode
      if(curr.win[0] != prev.win[0] || curr.win[1] != prev.win[1]){
	WID->make_opengl_current();
	std::vector<GVertex*> vertices;
	std::vector<GEdge*> edges;
	std::vector<GFace*> faces;
	std::vector<GRegion*> regions;
	std::vector<MElement*> elements;
	bool res = ProcessSelectionBuffer(WID->selection, false, 
					  CTX.mouse_hover_meshes, 
					  (int)curr.win[0], (int)curr.win[1], 5, 5, 
					  vertices, edges, faces, regions,
					  elements);
	if((WID->selection == ENT_ALL && res) ||
	   (WID->selection == ENT_POINT && vertices.size()) ||
	   (WID->selection == ENT_LINE && edges.size()) || 
	   (WID->selection == ENT_SURFACE && faces.size()) ||
	   (WID->selection == ENT_VOLUME && regions.size()))
	  WID->g_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
	else
	  WID->g_window->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
	GEntity *ge = 0;
	if(vertices.size()) ge = vertices[0];
	else if(edges.size()) ge = edges[0];
	else if(faces.size()) ge = faces[0];
	else if(regions.size()) ge = regions[0];
	MElement *me = elements.size() ? elements[0] : 0;
	Msg(STATUS2N, "%s %s",
	    ge ? ge->getInfoString().c_str() : "", 
	    me ? me->getInfoString().c_str() : "");
      }
    }
    prev.set();
    return 1;

  default:
    return Fl_Gl_Window::handle(event);
  }
}
