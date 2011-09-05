// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdio.h>
#include "openglWindow.h"
#include "graphicWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "Numeric.h"
#include "FlGui.h"
#include "drawContext.h"
#include "Context.h"
 
static void lassoZoom(drawContext *ctx, mousePosition &click1, mousePosition &click2)
{
  if(click1.win[0] == click2.win[0] || click1.win[1] == click2.win[1]) return;

  ctx->s[0] *= (double)ctx->viewport[2] / (click2.win[0] - click1.win[0]);
  ctx->s[1] *= (double)ctx->viewport[3] / (click2.win[1] - click1.win[1]);
  ctx->s[2] = std::min(ctx->s[0], ctx->s[1]); // bof...
  
  // recenter around the center of the lasso rectangle
  mousePosition tmp(click1);
  tmp.wnr[0] = 0.5 * (click1.wnr[0] + click2.wnr[0]);
  tmp.wnr[1] = 0.5 * (click1.wnr[1] + click2.wnr[1]);
  tmp.recenter(ctx);

  ctx->initPosition();
  drawContext::global()->draw();
  FlGui::instance()->manip->update();  
}

openglWindow::openglWindow(int x, int y, int w, int h, const char *l)
  : Fl_Gl_Window(x, y, w, h, l), _lock(false),
    _selection(ENT_NONE), _trySelection(0)
{
  _ctx = new drawContext();
  for(int i = 0; i < 3; i++) _point[i] = 0.;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;
  _lassoXY[0] = _lassoXY[1] = 0;

  addPointMode = lassoMode = selectionMode = false;
  endSelection = undoSelection = invertSelection = quitSelection = 0;
}

openglWindow::~openglWindow()
{ 
  delete _ctx;
}

void openglWindow::_drawScreenMessage()
{
  if(screenMessage[0].empty() && screenMessage[1].empty()) 
    return;

  glColor4ubv((GLubyte *) & CTX::instance()->color.text);
  drawContext::global()->setFont(CTX::instance()->glFontEnum, 
                                 CTX::instance()->glFontSize);
  double h = drawContext::global()->getStringHeight();
  
  if(screenMessage[0].size()){
    const char *txt = screenMessage[0].c_str();
    double w = drawContext::global()->getStringWidth(txt);
    glRasterPos2d(_ctx->viewport[2] / 2. - w / 2., 
                  _ctx->viewport[3] - 1.2 * h);
    drawContext::global()->drawString(txt);
  }
  if(screenMessage[1].size()){
    const char *txt = screenMessage[1].c_str();
    double w = drawContext::global()->getStringWidth(txt);
    glRasterPos2d(_ctx->viewport[2] / 2. - w / 2.,
                  _ctx->viewport[3] - 2.4 * h);
    drawContext::global()->drawString(txt);
  }
}

void openglWindow::_drawBorder()
{
  // draw thin border if the parent group has several children
  if(parent()->children() > 1){
    unsigned char r, g, b;
    Fl::get_color(color(), r, g, b);
    /* would need to redraw all gl's when _lastHandled is changed
    if(_lastHandled == this)
      Fl::get_color(FL_SELECTION_COLOR, r, g, b);
    else
      Fl::get_color(FL_BACKGROUND_COLOR, r, g, b);
    */
    glColor3ub(r, g, b);
    glLineWidth(1.0F);
    glBegin(GL_LINE_LOOP);
    glVertex2d(_ctx->viewport[0], _ctx->viewport[1]);
    glVertex2d(_ctx->viewport[2], _ctx->viewport[1]);
    glVertex2d(_ctx->viewport[2], _ctx->viewport[3]);
    glVertex2d(_ctx->viewport[0], _ctx->viewport[3]);
    glEnd();
  }
}

void openglWindow::draw()
{
  // some drawing routines can create data (STL triangulations, etc.):
  // make sure that we don't fire draw() while we are already drawing,
  // e.g. due to an impromptu Fl::check(). The same lock is also used
  // in _select to guarantee that we don't mix GL_RENDER and GL_SELECT
  // rendering passes.
  if(_lock) return;
  _lock = true;

  Msg::Debug("openglWindow::draw()");

  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  _ctx->viewport[2] = w();
  _ctx->viewport[3] = h();
  glViewport(_ctx->viewport[0], _ctx->viewport[1],
             _ctx->viewport[2], _ctx->viewport[3]);

  if(lassoMode) { 
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
    glDrawBuffer(GL_FRONT_AND_BACK);
    if(selectionMode && CTX::instance()->mouseSelection){
      glEnable(GL_LINE_STIPPLE);
      glLineStipple(1, 0x0F0F);
    }
    // glBlendEquation(GL_FUNC_ADD);
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    glEnable(GL_BLEND);
    glLineWidth(0.2F);
    glBegin(GL_LINE_LOOP);
    glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
    glVertex2d(_lassoXY[0], _ctx->viewport[3] - _click.win[1]);
    glVertex2d(_lassoXY[0], _ctx->viewport[3] - _lassoXY[1]);
    glVertex2d(_click.win[0], _ctx->viewport[3] - _lassoXY[1]);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2d(_click.win[0], _ctx->viewport[3] - _click.win[1]);
    glVertex2d(_curr.win[0], _ctx->viewport[3] - _click.win[1]);
    glVertex2d(_curr.win[0], _ctx->viewport[3] - _curr.win[1]);
    glVertex2d(_click.win[0], _ctx->viewport[3] - _curr.win[1]);
    glEnd();
    _lassoXY[0] = _curr.win[0];
    _lassoXY[1] = _curr.win[1];
    glDisable(GL_BLEND);
    glDisable(GL_LINE_STIPPLE);
    glEnable(GL_DEPTH_TEST);
    glDrawBuffer(GL_BACK);
  }
  else if(addPointMode) { 
    // draw the whole scene and the point to add
    if(CTX::instance()->fastRedraw) {
      CTX::instance()->mesh.draw = 0;
      CTX::instance()->post.draw = 0;
    }
    
    glClearColor
      ((GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
       (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) / 255.),
       (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.), 
       0.0F);
    
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    
    _ctx->draw3d();
    glColor4ubv((GLubyte *) & CTX::instance()->color.fg);
    glPointSize((float)CTX::instance()->geom.pointSize);
    glBegin(GL_POINTS);
    glVertex3d(_point[0], _point[1], _point[2]);
    glEnd();
    _ctx->draw2d();
    _drawScreenMessage();
    _drawBorder();
    CTX::instance()->mesh.draw = 1;
    CTX::instance()->post.draw = 1;
  }
  else{
    // draw the whole scene
    glClearColor
      ((GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
       (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) / 255.),
       (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.), 
       0.0F);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
   
    if(CTX::instance()->camera && !CTX::instance()->stereo){
      Camera *cam = &(_ctx->camera);
      if (!cam->on) cam->init();
      cam->giveViewportDimension(_ctx->viewport[2],_ctx->viewport[3]);  
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      glFrustum(cam->glFleft, cam->glFright, cam->glFbottom,
                cam->glFtop, cam->glFnear, cam->glFfar); 
      glMatrixMode(GL_MODELVIEW);
      glLoadIdentity();
      glDrawBuffer(GL_BACK);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      gluLookAt(cam->position.x,cam->position.y,cam->position.z,
		cam->target.x,cam->target.y,cam->target.z,
		cam->up.x,cam->up.y,cam->up.z);      
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
      //    glPushMatrix();
    }
    else if(CTX::instance()->stereo){
      Camera *cam = &(_ctx->camera);
      if(!cam->on) cam->init();
      cam->giveViewportDimension(_ctx->viewport[2], _ctx->viewport[3]);
      XYZ eye = cam->eyesep / 2.0 * cam->right;
      // right eye
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      double left   = - cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
      double right  =   cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
      double top    =   cam->wd2;
      double bottom = - cam->wd2;
      glFrustum(left, right, bottom, top, cam->glFnear, cam->glFfar);
      glMatrixMode(GL_MODELVIEW);
      glDrawBuffer(GL_BACK_RIGHT);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      gluLookAt(cam->position.x+eye.x, cam->position.y+eye.y, cam->position.z+eye.z,
                cam->target.x+eye.x, cam->target.y+eye.y, cam->target.z+eye.z,
                cam->up.x,  cam->up.y, cam->up.z); 
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
      // left eye
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      left   = - cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
      right  =   cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
      top    =   cam->wd2;
      bottom = - cam->wd2;
      glFrustum(left, right, bottom, top, cam->glFnear, cam->glFfar);
      
      glMatrixMode(GL_MODELVIEW);
      glDrawBuffer(GL_BACK_LEFT);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glLoadIdentity();
      gluLookAt(cam->position.x-eye.x, cam->position.y-eye.y, cam->position.z-eye.z,
                cam->target.x-eye.x, cam->target.y-eye.y, cam->target.z-eye.z,
                cam->up.x, cam->up.y, cam->up.z); 
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
    }
    else{
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
    }
  }
  _lock = false;
}

openglWindow *openglWindow::_lastHandled = 0;

void openglWindow::_setLastHandled(openglWindow* w)
{
  _lastHandled = w;
  FlGui::instance()->visibility->updatePerWindow();
}

int openglWindow::handle(int event)
{
  switch (event) {

  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS:
    return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // override the default widget arrow-key-navigation
    if(FlGui::instance()->testArrowShortcuts())
      return 1;
    return Fl_Gl_Window::handle(event);
    
  case FL_PUSH:
    _setLastHandled(this);
    take_focus(); // force keyboard focus when we click in the window
    _curr.set(_ctx, Fl::event_x(), Fl::event_y());
    if(Fl::event_button() == 1 && 
       !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
      if(!lassoMode && Fl::event_state(FL_CTRL)) {
        lassoMode = true;
        _lassoXY[0] = _curr.win[0];
        _lassoXY[1] = _curr.win[1];
      }
      else if(lassoMode) {
        lassoMode = false;
        if(selectionMode && CTX::instance()->mouseSelection){
          // will try to select multiple entities
          _trySelection = 2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
	  if (CTX::instance()->camera){
	    Camera * cam = &(_ctx->camera);      
	    double dy = fabs(-_click.win[1] + _curr.win[1]);
	    double dx = fabs(-_click.win[0] + _curr.win[0]);
	    double factx = w() / fabs(dx);
	    double facty = h() / fabs(dy);
	    double fact = .8 * std::min(factx, facty);
	    double x_med = (_click.win[0] + _curr.win[0]) / 2.;
	    double y_med = (_click.win[1] + _curr.win[1]) / 2.;
	    double theta_x = .96 * cam->radians * (w() / 2 - x_med) * 2. / h();
	    double theta_y = .96 * cam->radians * (h() / 2 - y_med) * 2. / h();
	    cam->moveRight(theta_x); 
	    cam->moveUp(theta_y); 
	    _ctx->camera.zoom(fact);
	    _ctx->camera.update();
	    redraw();
	  }
	  else{
	    lassoZoom(_ctx, _click, _curr);
	  }
        }
      }
      else if(CTX::instance()->mouseSelection){
        // will try to select clicked entity
        _trySelection = 1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else if(Fl::event_button() == 2 || 
            (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
      if(!lassoMode && Fl::event_state(FL_CTRL)) {
        // make zoom isotropic
	_ctx->s[1] = _ctx->s[0];
	_ctx->s[2] = _ctx->s[0];
	redraw();
      }
      else if(lassoMode) {
        lassoMode = false;
        if(selectionMode && CTX::instance()->mouseSelection){
          // will try to unselect multiple entities
          _trySelection = -2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else{
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX::instance()->mouseSelection){
        // will try to unselect clicked entity
        _trySelection = -1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else {
      if(Fl::event_state(FL_CTRL) && !lassoMode) {
        if(CTX::instance()->useTrackball)
          _ctx->setQuaternion(0., 0., 0., 1.);
        else
          _ctx->r[0] = _ctx->r[1] = _ctx->r[2] = 0.;
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        redraw();
      }
      else {
        lassoMode = false;
      }
    }
    _click.set(_ctx, Fl::event_x(), Fl::event_y());
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    FlGui::instance()->manip->update();
    return 1;

  case FL_RELEASE:
    _curr.set(_ctx, Fl::event_x(), Fl::event_y());
    CTX::instance()->drawRotationCenter = 0;
    if(!lassoMode) {
      CTX::instance()->mesh.draw = 1;
      CTX::instance()->post.draw = 1;
      redraw();
    }
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    return 1;

  case FL_MOUSEWHEEL:
    {
      double dy = Fl::event_dy();
      double fact = (5. * CTX::instance()->zoomFactor * fabs(dy) + h()) / (double)h();
      if (CTX::instance()->camera){
	fact = ((dy > 0) ? fact : 1. / fact);
	_ctx->camera.zoom(fact);
       	_ctx->camera.update();
	redraw();	
      }
      else{
	_ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
	_ctx->s[1] = _ctx->s[0];
	_ctx->s[2] = _ctx->s[0];
	_prev.recenter(_ctx);
	redraw();	
      }
    }
    FlGui::instance()->manip->update();
    return 1;

  case FL_DRAG:
    _curr.set(_ctx, Fl::event_x(), Fl::event_y());
    {
      double dx = _curr.win[0] - _prev.win[0];
      double dy = _curr.win[1] - _prev.win[1];
      if(lassoMode) {
        redraw();
      }
      else {
        if(Fl::event_state(FL_META)) {
          // will try to select or unselect entities on the fly
          _trySelection = Fl::event_state(FL_SHIFT) ? -1 : 1; 
          _trySelectionXYWH[0] = (int)_curr.win[0];
          _trySelectionXYWH[1] = (int)_curr.win[1];
          _trySelectionXYWH[2] = 5;
          _trySelectionXYWH[3] = 5;
        }
	// (m1) and (!shift) and (!alt)  => rotation
        else if(Fl::event_button() == 1 && 
                !Fl::event_state(FL_SHIFT) && !Fl::event_state(FL_ALT)) {
          if(CTX::instance()->useTrackball)
            _ctx->addQuaternion((2. * _prev.win[0] - w()) / w(),
                                (h() - 2. * _prev.win[1]) / h(),
                                (2. * _curr.win[0] - w()) / w(),
                                (h() - 2. * _curr.win[1]) / h());
          else {
            _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)w() : 0.);
            _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)h());
          }
        }
	// m2 or (m1 and shift) => zoom (only move in y is used)
	// but start point is the center of the homothety
        else if(Fl::event_button() == 2 ||
                (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
	  // isotrop zoom in camera mode
	  if (CTX::instance()->camera){
	    double dy= (int)_curr.win[1] - (int)_prev.win[1];
	    double fact = (CTX::instance()->zoomFactor * fabs(dy) + (double)h()) /
              (double)h();
	    fact= ((dy > 0) ? fact : 1./fact);
	    _ctx->camera.zoom(fact);
	    _ctx->camera.update();
	    redraw();
	  }	
	  else{          
            // move in y greater than move in x
	    if(fabs(dy) > fabs(dx)) {
	      double fact = (CTX::instance()->zoomFactor * fabs(dy) + h()) / (double)h();
	      _ctx->s[0] *= ((dy > 0) ? fact : 1./fact);
	      _ctx->s[1] = _ctx->s[0];
	      _ctx->s[2] = _ctx->s[0];
	      _click.recenter(_ctx);
	    }
	    else if(!CTX::instance()->useTrackball)
	      _ctx->r[2] += -180. * dx / (double)w();
	  }
        }
        // other case => translation
	else {
	  if (CTX::instance()->camera){
	    Camera * cam= &(_ctx->camera);      
	    double theta_x = cam->radians * (-(double)_prev.win[0] + 
                                             (double)_curr.win[0]) * 2. / h();
	    double theta_y = cam->radians * (-(double)_prev.win[1] +
                                             (double)_curr.win[1]) * 2. / h();
	    cam->moveRight(theta_x); 
	    cam->moveUp(theta_y); 
	  }	
	  else{          
	    _ctx->t[0] += (_curr.wnr[0] - _click.wnr[0]);
	    _ctx->t[1] += (_curr.wnr[1] - _click.wnr[1]);
	    _ctx->t[2] = 0.;
	  }
        }
        CTX::instance()->drawRotationCenter = 1;
        if(CTX::instance()->fastRedraw) {
          CTX::instance()->mesh.draw = 0;
          CTX::instance()->post.draw = 0;
        }
        redraw();
      }
    }
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    FlGui::instance()->manip->update();
    return 1;

  case FL_MOVE:
    _curr.set(_ctx, Fl::event_x(), Fl::event_y());
    if(lassoMode){
      redraw();
    }
    else if(addPointMode && !Fl::event_state(FL_SHIFT)){
      cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3], d[3];
      _ctx->unproject(_curr.win[0], _curr.win[1], p, d);
      // find closest point to the center of gravity
      double r[3] = {CTX::instance()->cg[0] - p[0], CTX::instance()->cg[1] - p[1], 
                     CTX::instance()->cg[2] - p[2]}, t;
      prosca(r, d, &t);
      for(int i = 0; i < 3; i++){
        _point[i] = p[i] + t * d[i];
        if(CTX::instance()->geom.snap[i]){
          double d = _point[i] / CTX::instance()->geom.snap[i];
          double f = floor(d);
          double c = ceil(d);
          double n = (d - f < c - d) ? f : c;
          _point[i] = n * CTX::instance()->geom.snap[i];
        }
      }
      char str[32];
      sprintf(str, "%g", _point[0]); 
      FlGui::instance()->geoContext->input[2]->value(str);
      sprintf(str, "%g", _point[1]); 
      FlGui::instance()->geoContext->input[3]->value(str);
      sprintf(str, "%g", _point[2]); 
      FlGui::instance()->geoContext->input[4]->value(str);
      redraw();
    }
    else{ // hover mode
      if(_curr.win[0] != _prev.win[0] || _curr.win[1] != _prev.win[1]){
        std::vector<GVertex*> vertices;
        std::vector<GEdge*> edges;
        std::vector<GFace*> faces;
        std::vector<GRegion*> regions;
        std::vector<MElement*> elements;
        bool res = _select(_selection, false, CTX::instance()->mouseHoverMeshes, 
                           (int)_curr.win[0], (int)_curr.win[1], 5, 5,
                           vertices, edges, faces, regions, elements);
        if((_selection == ENT_ALL && res) ||
           (_selection == ENT_POINT && vertices.size()) ||
           (_selection == ENT_LINE && edges.size()) || 
           (_selection == ENT_SURFACE && faces.size()) ||
           (_selection == ENT_VOLUME && regions.size()))
          cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
        else
          cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
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
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    return 1;

  default:
    return Fl_Gl_Window::handle(event);
  }
}

bool openglWindow::_select(int type, bool multiple, bool mesh, 
                           int x, int y, int w, int h,
                           std::vector<GVertex*> &vertices,
                           std::vector<GEdge*> &edges,
                           std::vector<GFace*> &faces,
                           std::vector<GRegion*> &regions,
                           std::vector<MElement*> &elements)
{
  // same lock as in draw() to prevent firing up a GL_SELECT rendering pass
  // while a GL_RENDER pass is happening (due to the asynchronus nature of
  // Fl::check()s
  if(_lock) return false;
  _lock = true;
  make_current();
  bool ret = _ctx->select(type, multiple, mesh, x, y, w, h, 
                          vertices, edges, faces, regions, elements);
  _lock = false;
  return ret;
}

char openglWindow::selectEntity(int type, 
                                std::vector<GVertex*> &vertices,
                                std::vector<GEdge*> &edges,
                                std::vector<GFace*> &faces,
                                std::vector<GRegion*> &regions,
                                std::vector<MElement*> &elements)
{
  // force keyboard focus in GL window 
  take_focus();
  _selection = type;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  endSelection = 0;
  undoSelection = 0;
  invertSelection = 0;

  while(1) {
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    FlGui::instance()->wait();
    if(quitSelection) {
      _selection = ENT_NONE;
      selectionMode = false;
      lassoMode = false;
      addPointMode = false;
      cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
      return 'q';
    }
    if(endSelection) {
      _selection = ENT_NONE;
      endSelection = 0;
      return 'e';
    }
    if(undoSelection) {
      undoSelection = 0;
      return 'u';
    }
    if(invertSelection) {
      invertSelection = 0;
      return 'i';
    }
    if(_trySelection) {
      bool add = (_trySelection > 0) ? true : false;
      bool multi = (abs(_trySelection) > 1) ? true : false;
      _trySelection = 0;
      if(_selection == ENT_NONE){ // just report the mouse click
        selectionMode = false;
        return 'c';
      }
      else if(_select(_selection, multi, true, _trySelectionXYWH[0],
                      _trySelectionXYWH[1], _trySelectionXYWH[2],
                      _trySelectionXYWH[3], vertices, edges, faces, 
                      regions, elements)){
        _selection = ENT_NONE;
        selectionMode = false;
        if(add)
          return 'l';
        else
          return 'r';
      }
    }
  }
}
