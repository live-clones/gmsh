// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshUI.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "Draw.h"
#include "Numeric.h"
#include "Context.h"
#include "SelectBuffer.h"
#include "GUI.h"
#include "Opengl_Window.h"
#include "MElement.h"

extern GUI *WID;
extern Context_T CTX;

void MousePosition::set(drawContext *ctx)
{
  for(int i = 0; i < 3; i++){
    s[i] = ctx->s[i];
    t[i] = ctx->t[i];
  }

  win[0] = (double)Fl::event_x();
  win[1] = (double)Fl::event_y();
  win[2] = 0.;

  wnr[0] = 
    (ctx->vxmin + win[0] / (double)ctx->viewport[2] * (ctx->vxmax - ctx->vxmin)) 
    / ctx->s[0] - ctx->t[0] + ctx->t_init[0] / ctx->s[0];
  wnr[1] = 
    (ctx->vymax - win[1] / (double)ctx->viewport[3] * (ctx->vymax - ctx->vymin))
    / ctx->s[1] - ctx->t[1] + ctx->t_init[1] / ctx->s[1];
  wnr[2] = 0.;
}

void MousePosition::recenter(drawContext *ctx)
{
  // compute the equivalent translation to apply *after* the scaling
  // so that the scaling is done around the point which was clicked:
  ctx->t[0] = t[0] * (s[0] / ctx->s[0]) - wnr[0] * (1. - (s[0] / ctx->s[0]));
  ctx->t[1] = t[1] * (s[1] / ctx->s[1]) - wnr[1] * (1. - (s[1] / ctx->s[1]));
}
  
static void lassoZoom(drawContext *ctx, MousePosition &click1, MousePosition &click2)
{
  if(click1.win[0] == click2.win[0] || click1.win[1] == click2.win[1])
    return;

  ctx->s[0] *= (double)ctx->viewport[2] / (click2.win[0] - click1.win[0]);
  ctx->s[1] *= (double)ctx->viewport[3] / (click2.win[1] - click1.win[1]);
  ctx->s[2] = std::min(ctx->s[0], ctx->s[1]); // bof...
  
  // recenter around the center of the lasso rectangle
  MousePosition tmp(click1);
  tmp.wnr[0] = 0.5 * (click1.wnr[0] + click2.wnr[0]);
  tmp.wnr[1] = 0.5 * (click1.wnr[1] + click2.wnr[1]);
  tmp.recenter(ctx);

  ctx->initPosition();
  Draw();
  WID->update_manip_window();
}

Opengl_Window::Opengl_Window(int x, int y, int w, int h, const char *l)
  : Fl_Gl_Window(x, y, w, h, l)
{
  AddPointMode = LassoMode = SelectionMode = false;
  _point[0] = _point[1] = _point[2] = 0.;
  _ctx = new drawContext();
}

Opengl_Window::~Opengl_Window()
{ 
  delete _ctx; 
}

void Opengl_Window::draw()
{
  static int locked = 0;
  if(locked)
    return;
  else
    locked = 1;

  Msg::Debug("Opengl_Window->draw()");

  if(!valid()) {
    valid(1);
    _ctx->viewport[0] = 0;
    _ctx->viewport[1] = 0;
    _ctx->viewport[2] = w();
    _ctx->viewport[3] = h();
    glViewport(_ctx->viewport[0], _ctx->viewport[1],
               _ctx->viewport[2], _ctx->viewport[3]);
  }
  else {
    if((w() != _ctx->viewport[2] - _ctx->viewport[0]) ||
       (h() != _ctx->viewport[3] - _ctx->viewport[1])) {
      WID->set_size(_ctx->viewport[2] - _ctx->viewport[0],
                    _ctx->viewport[3] - _ctx->viewport[1]);
      glViewport(_ctx->viewport[0], _ctx->viewport[1],
                 _ctx->viewport[2], _ctx->viewport[3]);
    }
  }

  if(LassoMode) { 
    // draw the zoom or selection lasso on top of the current scene
    // (without using overlays!)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)_ctx->viewport[0], (double)_ctx->viewport[2],
            (double)_ctx->viewport[1], (double)_ctx->viewport[3], -1., 1.);
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
      glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
      glVertex2d(_lasso.win[0], _ctx->viewport[3] - _click.win[1]);
      glVertex2d(_lasso.win[0], _ctx->viewport[3] - _lasso.win[1]);
      glVertex2d(_click.win[0], _ctx->viewport[3] - _lasso.win[1]);
      glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
      glEnd();
      if(!i) _lasso.set(_ctx);
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
    _ctx->draw3d();
    glColor4ubv((GLubyte *) & CTX.color.fg);
    glPointSize(CTX.geom.point_size);
    glBegin(GL_POINTS);
    glVertex3d(_point[0], _point[1], _point[2]);
    glEnd();
    _ctx->draw2d();
    CTX.mesh.draw = 1;
    CTX.post.draw = 1;
  }
  else{
    // draw the whole scene
    ClearOpengl();
    _ctx->draw3d();
    _ctx->draw2d();
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
    _curr.set(_ctx);
    if(Fl::event_button() == 1 && 
       !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!LassoMode && Fl::event_state(FL_CTRL)) {
        LassoMode = true;
        _lasso.set(_ctx);
      }
      else if(LassoMode) {
        LassoMode = false;
        if(SelectionMode && CTX.mouse_selection){
          WID->try_selection = 2; // will try to select multiple entities
          WID->try_selection_xywh[0] = (int)(_click.win[0] + _curr.win[0])/2;
          WID->try_selection_xywh[1] = (int)(_click.win[1] + _curr.win[1])/2;
          WID->try_selection_xywh[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          WID->try_selection_xywh[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX.mouse_selection){
        WID->try_selection = 1; // will try to select clicked entity
        WID->try_selection_xywh[0] = (int)_curr.win[0];
        WID->try_selection_xywh[1] = (int)_curr.win[1];
        WID->try_selection_xywh[2] = 5;
        WID->try_selection_xywh[3] = 5;
      }
    }
    else if(Fl::event_button() == 2 || 
            (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
      if(!LassoMode && Fl::event_state(FL_CTRL)) {
        // make zoom isotropic
        _ctx->s[1] = _ctx->s[0];
        _ctx->s[2] = _ctx->s[0];
        redraw();
      }
      else if(LassoMode) {
        LassoMode = false;
        if(SelectionMode && CTX.mouse_selection){
          WID->try_selection = -2; // will try to unselect multiple entities
          WID->try_selection_xywh[0] = (int)(_click.win[0] + _curr.win[0])/2;
          WID->try_selection_xywh[1] = (int)(_click.win[1] + _curr.win[1])/2;
          WID->try_selection_xywh[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          WID->try_selection_xywh[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX.mouse_selection){
        WID->try_selection = -1; // will try to unselect clicked entity
        WID->try_selection_xywh[0] = (int)_curr.win[0];
        WID->try_selection_xywh[1] = (int)_curr.win[1];
        WID->try_selection_xywh[2] = 5;
        WID->try_selection_xywh[3] = 5;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !LassoMode) {
        if(CTX.useTrackball)
          _ctx->setQuaternion(0., 0., 0., 1.);
        else
          _ctx->r[0] = _ctx->r[1] = _ctx->r[2] = 0.;
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        redraw();
      }
      else {
        LassoMode = false;
      }
    }
    _click.set(_ctx);
    _prev.set(_ctx);
    WID->update_manip_window();
    return 1;

  case FL_RELEASE:
    _curr.set(_ctx);
    CTX.draw_rotation_center = 0;
    if(!LassoMode) {
      CTX.mesh.draw = 1;
      CTX.post.draw = 1;
      redraw();
    }
    _prev.set(_ctx);
    return 1;

  case FL_MOUSEWHEEL:
    {
      double dy = Fl::event_dy();
      double fact = (5. * CTX.zoom_factor * fabs(dy) + h()) / (double)h();
      _ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
      _ctx->s[1] = _ctx->s[0];
      _ctx->s[2] = _ctx->s[0];
      _prev.recenter(_ctx);
      redraw();
    }
    WID->update_manip_window();
    return 1;

  case FL_DRAG:
    _curr.set(_ctx);
    {
      double dx = _curr.win[0] - _prev.win[0];
      double dy = _curr.win[1] - _prev.win[1];
      if(LassoMode) {
        redraw();
      }
      else {
        if(Fl::event_state(FL_META)) {
          // will try to select or unselect entities on the fly
          WID->try_selection = Fl::event_state(FL_SHIFT) ? -1 : 1; 
          WID->try_selection_xywh[0] = (int)_curr.win[0];
          WID->try_selection_xywh[1] = (int)_curr.win[1];
          WID->try_selection_xywh[2] = 5;
          WID->try_selection_xywh[3] = 5;
        }
        else if(Fl::event_button() == 1 && 
                !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
          if(CTX.useTrackball)
            _ctx->addQuaternion((2. * _prev.win[0] - w()) / w(),
                              (h() - 2. * _prev.win[1]) / h(),
                              (2. * _curr.win[0] - w()) / w(),
                              (h() - 2. * _curr.win[1]) / h());
          else {
            _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)w() : 0.);
            _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)h());
          }
        }
        else if(Fl::event_button() == 2 ||
                (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
          if(fabs(dy) > fabs(dx)) {
            double fact = (CTX.zoom_factor * fabs(dy) + h()) / (double)h();
            _ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
            _ctx->s[1] = _ctx->s[0];
            _ctx->s[2] = _ctx->s[0];
            _click.recenter(_ctx);
          }
          else if(!CTX.useTrackball)
            _ctx->r[2] += -180. * dx / (double)w();
        }
        else {
          _ctx->t[0] += (_curr.wnr[0] - _click.wnr[0]);
          _ctx->t[1] += (_curr.wnr[1] - _click.wnr[1]);
          _ctx->t[2] = 0.;
        }
        CTX.draw_rotation_center = 1;
        if(CTX.fast_redraw) {
          CTX.mesh.draw = 0;
          CTX.post.draw = 0;
        }
        redraw();
      }
    }
    _prev.set(_ctx);
    WID->update_manip_window();
    return 1;

  case FL_MOVE:
    _curr.set(_ctx);
    if(LassoMode) {
      redraw();
    }
    else if(AddPointMode && !Fl::event_state(FL_SHIFT)){
      WID->g_opengl_window->cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3],d[3];
      _ctx->unproject(_curr.win[0], _curr.win[1], p, d);
      // fin closest point to the center of gravity
      double r[3] = {CTX.cg[0] - p[0], CTX.cg[1] - p[1], CTX.cg[2] - p[2]}, t;
      prosca(r, d, &t);
      for(int i = 0; i < 3; i++){
        _point[i] = p[i] + t * d[i];
        if(CTX.geom.snap[i]){
          double d = _point[i] / CTX.geom.snap[i];
          double f = floor(d);
          double c = ceil(d);
          double n = (d - f < c - d) ? f : c;
          _point[i] = n * CTX.geom.snap[i];
        }
      }
      char str[32];
      sprintf(str, "%g", _point[0]); WID->context_geometry_input[2]->value(str);
      sprintf(str, "%g", _point[1]); WID->context_geometry_input[3]->value(str);
      sprintf(str, "%g", _point[2]); WID->context_geometry_input[4]->value(str);
      redraw();
    }
    else{ // hover mode
      if(_curr.win[0] != _prev.win[0] || _curr.win[1] != _prev.win[1]){
        WID->make_opengl_current();
        std::vector<GVertex*> vertices;
        std::vector<GEdge*> edges;
        std::vector<GFace*> faces;
        std::vector<GRegion*> regions;
        std::vector<MElement*> elements;
        bool res = ProcessSelectionBuffer(_ctx, WID->selection, false, 
                                          CTX.mouse_hover_meshes, 
                                          (int)_curr.win[0], (int)_curr.win[1], 5, 5, 
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
        Msg::StatusBar(2, false, "%s %s",
		    ge ? ge->getInfoString().c_str() : "", 
		    me ? me->getInfoString().c_str() : "");
      }
    }
    _prev.set(_ctx);
    return 1;

  default:
    return Fl_Gl_Window::handle(event);
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
      else if(ProcessSelectionBuffer(WID->g_opengl_window->getDrawContext(),
                                     WID->selection, multi, true,
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
