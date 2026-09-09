// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string.h>
#include <FL/Fl_Tooltip.H>
#include "openglWindow.h"
#include "graphicWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Numeric.h"
#include "FlGui.h"
#include "onelabContextWindow.h"
#include "OpenFile.h"
#include "drawContext.h"
#include "VertexArray.h"
#include "glMatrix.h"
#include "glShader.h"
#include "Context.h"
#include "Trackball.h"
#include <cstring>
#include "GamePad.h"
#include "StringUtils.h"

// the modelview matrix looking at the camera target from the camera position,
// both moved by the same offset (the half eye separation of a stereo pair)
static void cameraView(Camera *cam, double dx, double dy, double dz,
                       double view[16])
{
  double eye[3] = {cam->position.x + dx, cam->position.y + dy,
                   cam->position.z + dz};
  double target[3] = {cam->target.x + dx, cam->target.y + dy,
                      cam->target.z + dz};
  double up[3] = {cam->up.x, cam->up.y, cam->up.z};
  glMatrix::lookAt(eye, target, up, view);
}

// read the gamepad events, if there is a gamepad
static void navigator_handler(void *data)
{
  openglWindow *gl_win = (openglWindow *)data;
  if(CTX::instance()->gamepad && CTX::instance()->gamepad->active) {
    if(gl_win->Nautilus == nullptr) {
      gl_win->Nautilus = new Navigator(CTX::instance()->gamepad->frequency,
                                       gl_win->getDrawContext());
    }
    gl_win->moveWithGamepad();
    Fl::add_timeout(CTX::instance()->gamepad->frequency, navigator_handler,
                    data);
  }
  else {
    if(gl_win->Nautilus) {
      delete gl_win->Nautilus;
      gl_win->Nautilus = nullptr;
    }
    Fl::add_timeout(3., navigator_handler, data);
  }
}

static void lassoZoom(drawContext *ctx, mousePosition &click1,
                      mousePosition &click2)
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

  ctx->initPosition(false);
  drawContext::global()->draw();
  FlGui::instance()->manip->update();
}

int openglWindowMode()
{
  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  if(CTX::instance()->stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  // the shader pipeline needs a core profile on macOS, which cannot do fixed
  // function: the two pipelines cannot share a context
  if(CTX::instance()->shaders) mode |= FL_OPENGL3;
  return mode;
}

openglWindow::openglWindow(int x, int y, int w, int h)
  : Fl_Gl_Window(x, y, w, h, "gl"), _lock(false), _drawn(false),
    _selection(ENT_NONE), _trySelection(0), Nautilus(nullptr)
{
  _studioTimer = false;
  _studioW = _studioH = 0;
  _printW = _printH = 0;
  _ctx = new drawContext();

  for(int i = 0; i < 3; i++) _point[i] = 0.;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;

  addPointMode = 0;
  lassoMode = selectionMode = false;
  endSelection = undoSelection = invertSelection = quitSelection = 0;
  changeSelection = 0;

  if(CTX::instance()->gamepad)
    Fl::add_timeout(.5, navigator_handler, (void *)this);

#if defined(NEW_TOOLTIPS)
  _tooltip = new tooltipWindow();
  _tooltip->hide();
#endif
}

openglWindow::~openglWindow()
{
  Fl::remove_timeout(_studioSampleCb, this);
  delete _ctx;
#if defined(NEW_TOOLTIPS)
  delete _tooltip;
#endif
  if(Nautilus) delete Nautilus;
}

void openglWindow::show()
{
  Fl_Gl_Window::show();
  /* You can uncomment this if you cannot use the very latest FLTK 1.4 version
     patched for macOS mojave

#if defined(__APPLE__) && (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_14)
  Msg::Info("OpenGL hack for macOS 10.14: see http://www.fltk.org/str.php?L3496");
  resize(x(), y(), w()+1, h());
  resize(x(), y(), w()-1, h());
#endif

  */
}

void openglWindow::_drawScreenMessage()
{
  if(screenMessage[0].empty() && screenMessage[1].empty()) return;

  gmshColor4ubv((GLubyte *)&CTX::instance()->color.text);
  drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                 CTX::instance()->glFontSize);
  double h = drawContext::global()->getStringHeight();

  if(screenMessage[0].size()) {
    const char *txt = screenMessage[0].c_str();
    double w = drawContext::global()->getStringWidth(txt);
    glRasterPos2d(_ctx->viewport[2] / 2. - w / 2., _ctx->viewport[3] - 1.2 * h);
    drawContext::global()->drawString(txt);
  }
  if(screenMessage[1].size()) {
    const char *txt = screenMessage[1].c_str();
    double w = drawContext::global()->getStringWidth(txt);
    glRasterPos2d(_ctx->viewport[2] / 2. - w / 2., _ctx->viewport[3] - 2.4 * h);
    drawContext::global()->drawString(txt);
  }
}

void openglWindow::_drawBorder()
{
  if(!parent()) return;
  // draw thin border if the parent group has more than 2 opengl windows
  int numgl = 0;
  for(int i = 0; i < parent()->children(); i++) {
    if(parent()->child(i)->label() &&
       !strcmp(parent()->child(i)->label(), label()))
      numgl++;
  }
  if(numgl < 2) return;

  unsigned char r, g, b;
  Fl::get_color(color(), r, g, b);
  /* would need to redraw all gl's when _lastHandled is changed
   if(_lastHandled == this)
     Fl::get_color(FL_SELECTION_COLOR, r, g, b);
   else
     Fl::get_color(FL_BACKGROUND_COLOR, r, g, b);
  */
  gmshColor3ub(r, g, b);
  gmshLineWidth(1.0F);
  gmshBegin(GL_LINE_LOOP);
  gmshVertex2d(_ctx->viewport[0], _ctx->viewport[1]);
  gmshVertex2d(_ctx->viewport[2], _ctx->viewport[1]);
  gmshVertex2d(_ctx->viewport[2], _ctx->viewport[3]);
  gmshVertex2d(_ctx->viewport[0], _ctx->viewport[3]);
  gmshEnd();
}

void openglWindow::draw()
{
  // a draw the studio timer did not ask for, or that anyone else asked for
  // as well, starts the accumulation over
  _studioTimer = (damage() & FL_DAMAGE_USER1) && !(damage() & FL_DAMAGE_ALL);
  if(!_studioTimer) _ctx->studioSample = 0;
  // some drawing routines can create data (STL triangulations, etc.): make sure
  // that we don't fire draw() while we are already drawing, e.g. due to an
  // impromptu Fl::check(). The same lock is also used in _select to guarantee
  // that we don't mix GL_RENDER and GL_SELECT rendering passes.
  _drawn = true;
  if(_lock) return;
  _lock = true;

  Msg::Debug("openglWindow::draw()");

  // the picking image is out of date
  _ctx->invalidatePickCache();

  if(!context_valid()) {
    _ctx->invalidateQuadricsAndDisplayLists();
    // the buffer objects and entry points belonged to the previous context
    VertexArray::invalidateBuffers();
    glApi::reset();
    glShader::reset();
    gmshResetMatrices();
    // report what the new context can do
    glApi::describe();
    // report now if the shader pipeline cannot be had
    if(CTX::instance()->shaders) glShader::available();
  }

  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  if(_printW) {
    // a picture of its own size, in plain pixels
    _ctx->viewport[2] = _printW;
    _ctx->viewport[3] = _printH;
    _ctx->setHighResolutionPixelFactor(1.);
    glViewport(0, 0, _printW, _printH);
  }
  else {
    _ctx->viewport[2] = w();
    _ctx->viewport[3] = h();
    // the factor changes when the window moves across displays
    _ctx->setHighResolutionPixelFactor(w() ? (double)pixel_w() / (double)w() :
                                             1.);
    glViewport(0, 0, pixel_w(), pixel_h());
  }

  if(lassoMode) {
    // draw the scene again with the lasso rectangle on top (drawing into the
    // front buffer, as was done before, left the frame black on current
    // implementations)
    if(CTX::instance()->fastRedraw) {
      CTX::instance()->mesh.draw = 0;
      CTX::instance()->post.draw = 0;
    }

    glClearColor(
      (GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) /
                 255.),
      (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.),
      0.0F);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    _ctx->draw3d();
    _ctx->draw2d();

    // the rectangle, in pixel coordinates: a border inverting whatever it
    // crosses, and a faint wash of the foreground colour inside
    gmshMatrixMode(GMSH_PROJECTION);
    double px[16];
    glMatrix::ortho(_ctx->viewport[0], _ctx->viewport[2], _ctx->viewport[1],
                    _ctx->viewport[3], -1., 1., px);
    gmshLoadMatrix(px);
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshLoadIdentity();
    double x0 = _click.win[0], y0 = _ctx->viewport[3] - _click.win[1];
    double x1 = _curr.win[0], y1 = _ctx->viewport[3] - _curr.win[1];
    // flush before changing the blending, which the collector does not track
    gmshFlushImmediate();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    unsigned int fg = CTX::instance()->color.fg;
    gmshColor4ub((unsigned char)CTX::instance()->unpackRed(fg),
                 (unsigned char)CTX::instance()->unpackGreen(fg),
                 (unsigned char)CTX::instance()->unpackBlue(fg), 40);
    gmshBegin(GL_QUADS);
    gmshVertex2d(x0, y0);
    gmshVertex2d(x1, y0);
    gmshVertex2d(x1, y1);
    gmshVertex2d(x0, y1);
    gmshEnd();
    gmshFlushImmediate();
    // white blended to one minus the destination: an inversion
    glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
    gmshColor3d(1., 1., 1.);
    if(selectionMode && CTX::instance()->mouseSelection)
      gmshLineStipple(1, 0x0F0F);
    // two window pixels wide (the width is in display pixels, the
    // coordinates in window pixels)
    double hw = 1.;
    gmshLineWidth(2. * hw * _ctx->highResolutionPixelFactor());
    // four segments, the horizontal ones stretched by half the width and the
    // vertical ones shortened by it, so that each corner is inverted once
    double sx = (x1 > x0) ? hw : (x1 < x0) ? -hw : 0.;
    double sy = (y1 > y0) ? hw : (y1 < y0) ? -hw : 0.;
    gmshBegin(GL_LINES);
    gmshVertex2d(x0 - sx, y0);
    gmshVertex2d(x1 + sx, y0);
    gmshVertex2d(x0 - sx, y1);
    gmshVertex2d(x1 + sx, y1);
    gmshVertex2d(x0, y0 + sy);
    gmshVertex2d(x0, y1 - sy);
    gmshVertex2d(x1, y0 + sy);
    gmshVertex2d(x1, y1 - sy);
    gmshEnd();
    gmshFlushImmediate();
    gmshLineStippleOff();
    gmshLineWidth(1.);
    glDisable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);

    _drawScreenMessage();
    _drawBorder();
    CTX::instance()->mesh.draw = 1;
    CTX::instance()->post.draw = 1;
  }
  else if(addPointMode) {
    // draw the whole scene and the point to add
    if(CTX::instance()->fastRedraw) {
      CTX::instance()->mesh.draw = 0;
      CTX::instance()->post.draw = 0;
    }

    glClearColor(
      (GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) /
                 255.),
      (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.),
      0.0F);

    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    _ctx->draw3d();
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
    float ps =
      CTX::instance()->geom.pointSize * _ctx->highResolutionPixelFactor();
    gmshPointSize(ps);
    gmshBegin(GL_POINTS);
    gmshVertex3d(_point[0], _point[1], _point[2]);
    gmshEnd();
    _ctx->draw2d();
    _drawScreenMessage();
    _drawBorder();
    CTX::instance()->mesh.draw = 1;
    CTX::instance()->post.draw = 1;
  }
  else {
    // draw the whole scene
    if(CTX::instance()->printing && !CTX::instance()->print.background)
      glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
    else
      glClearColor(
        (GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) /
                   255.),
        (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) /
                   255.),
        (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) /
                   255.),
        0.0F);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

    if(CTX::instance()->camera && !CTX::instance()->stereo) {
      Camera *cam = &(_ctx->camera);
      if(!cam->on) cam->init();
      cam->giveViewportDimension(_ctx->viewport[2], _ctx->viewport[3]);
      gmshMatrixMode(GMSH_PROJECTION);
      double frustum[16], view[16];
      glMatrix::frustum(cam->glFleft, cam->glFright, cam->glFbottom,
                        cam->glFtop, cam->glFnear, cam->glFfar * cam->Lc,
                        frustum);
      gmshLoadMatrix(frustum);

      gmshMatrixMode(GMSH_MODELVIEW);
      glDrawBuffer(GL_BACK);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      cameraView(cam, 0., 0., 0., view);
      gmshLoadMatrix(view);
      _ctx->draw3d();
      _ctx->draw2d();
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active &&
         Nautilus)
        Nautilus->drawIcons();
      _drawScreenMessage();
      _drawBorder();
    }
    else if(CTX::instance()->stereo) {
      Camera *cam = &(_ctx->camera);
      if(!cam->on) cam->init();
      cam->giveViewportDimension(_ctx->viewport[2], _ctx->viewport[3]);
      XYZ eye = cam->eyesep / 2.0 * cam->right;
      // right eye
      gmshMatrixMode(GMSH_PROJECTION);
      double frustum[16], view[16];
      double left =
        -cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
      double right =
        cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
      double top = cam->wd2;
      double bottom = -cam->wd2;
      glMatrix::frustum(left, right, bottom, top, cam->glFnear,
                        cam->glFfar * cam->Lc, frustum);
      gmshLoadMatrix(frustum);
      gmshMatrixMode(GMSH_MODELVIEW);
      glDrawBuffer(GL_BACK_RIGHT);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      cameraView(cam, eye.x, eye.y, eye.z, view);
      gmshLoadMatrix(view);
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
      // left eye
      gmshMatrixMode(GMSH_PROJECTION);
      left = -cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
      right = cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
      top = cam->wd2;
      bottom = -cam->wd2;
      glMatrix::frustum(left, right, bottom, top, cam->glFnear,
                        cam->glFfar * cam->Lc, frustum);
      gmshLoadMatrix(frustum);

      gmshMatrixMode(GMSH_MODELVIEW);
      glDrawBuffer(GL_BACK_LEFT);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      cameraView(cam, -eye.x, -eye.y, -eye.z, view);
      gmshLoadMatrix(view);
      _ctx->draw3d();
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
    }
    else {
      _ctx->draw3d();
      _ctx->draw2d();
      _studioFrame();
      _drawScreenMessage();
      _drawBorder();
    }
  }
  gmshFlushImmediate();
  drawContext::global()->flushString();
  _lock = false;
  _studioTimer = false;

}

// The accumulation of the studio shading: after a frame, while the view is
// still, the timer asks for more frames with the light, the dome and the
// projection jittered, and each is added to the average put on the window.
// A print does not wait: it draws them all at once.
void openglWindow::_studioFrame()
{
  Fl::remove_timeout(_studioSampleCb, this);
  CTX *ctx = CTX::instance();
  int n = ctx->studioSamples;
  if(!gmshUseShaders() || ctx->shading < 1 || n < 2) {
    _ctx->studioSample = 0;
    return;
  }
  int k = _ctx->studioSample;
  int w = _printW ? _printW : pixel_w(), h = _printW ? _printH : pixel_h();
  if(k > 0) {
    // the view changed since the last frame: start over
    if(w != _studioW || h != _studioH ||
       memcmp(_studioModel, _ctx->model, sizeof(_studioModel))) {
      Msg::Debug("Studio frames: the view changed, starting over");
      k = _ctx->studioSample = 0;
    }
    else {
      // the frame has to be complete before it is added: what the overlay
      // collected is still pending
      gmshFlushImmediate();
      drawContext::global()->flushString();
      if(!glShader::accumulate(w, h, k == 1, k)) {
        _ctx->studioSample = 0;
        return;
      }
      Msg::Debug("Studio frame %d of %d accumulated", k, n);
    }
  }
  memcpy(_studioModel, _ctx->model, sizeof(_studioModel));
  _studioW = w;
  _studioH = h;
  if(ctx->printing) {
    for(int j = k + 1; j < n; j++) {
      _ctx->studioSample = j;
      glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
      _ctx->draw3d();
      _ctx->draw2d();
      gmshFlushImmediate();
      drawContext::global()->flushString();
      if(!glShader::accumulate(w, h, j == 1, j)) break;
    }
    _ctx->studioSample = 0;
    return;
  }
  if(k + 1 < n) Fl::add_timeout(0.01, _studioSampleCb, this);
}

bool openglWindow::printTo(int width, int height, unsigned int format,
                           unsigned int type, void *pixels)
{
  make_current();
  if(!gmshUseShaders() || !glShader::beginPrintTarget(width, height))
    return false;
  _printW = width;
  _printH = height;
  draw();
  glShader::readPrintTarget(width, height, format, type, pixels);
  glShader::endPrintTarget();
  _printW = _printH = 0;
  // the window itself is drawn again at its own size
  redraw();
  return true;
}

void openglWindow::_studioSampleCb(void *data)
{
  openglWindow *w = (openglWindow *)data;
  // not while a mouse button is down: the view, or an option dragged in the
  // options window, is changing, and each step redraws the plain frame;
  // look again once it is up
  if(Fl::pushed()) {
    Fl::repeat_timeout(0.05, _studioSampleCb, data);
    return;
  }
  // asked for with a damage bit of its own: a redraw() asked for by anyone
  // else before the frame is drawn (an option changed, say) marks the
  // window fully damaged, and draw() knows the frame is a plain one then
  w->_ctx->studioSample++;
  w->damage(FL_DAMAGE_USER1);
}

openglWindow *openglWindow::_lastHandled = nullptr;

void openglWindow::_setLastHandled(openglWindow *w)
{
  _lastHandled = w;
  FlGui::instance()->visibility->updatePerWindow();
}

int openglWindow::handle(int event)
{
  switch(event) {
  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // override the default widget arrow-key-navigation
    if(FlGui::instance()->testArrowShortcuts()) return 1;
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
    if(Fl::event_clicks() == 1 && !selectionMode &&
       CTX::instance()->mouseSelection) {
      // double-click and not in selection mode, but with mouse selection enabled
      std::vector<GVertex *> vertices;
      std::vector<GEdge *> edges;
      std::vector<GFace *> faces;
      std::vector<GRegion *> regions;
      std::vector<MElement *> elements;
      std::vector<SPoint2> points;
      std::vector<PView *> views;
      _select(ENT_ALL, false, CTX::instance()->mouseHoverMeshes, true,
              Fl::event_x(), Fl::event_y(), 5, 5, vertices, edges, faces,
              regions, elements, points, views);
      if(vertices.size() &&
         CTX::instance()->geom.doubleClickedPointCommand.size()) {
        CTX::instance()->geom.doubleClickedEntityTag = vertices[0]->tag();
        if(CTX::instance()->geom.doubleClickedPointCommand == "ONELAB")
          FlGui::instance()->onelabContext->show(0, vertices[0]->tag());
        else
          ParseString(CTX::instance()->geom.doubleClickedPointCommand, true);
      }
      else if(edges.size() &&
              CTX::instance()->geom.doubleClickedCurveCommand.size()) {
        CTX::instance()->geom.doubleClickedEntityTag = edges[0]->tag();
        if(CTX::instance()->geom.doubleClickedCurveCommand == "ONELAB")
          FlGui::instance()->onelabContext->show(1, edges[0]->tag());
        else
          ParseString(CTX::instance()->geom.doubleClickedCurveCommand, true);
      }
      else if(faces.size() &&
              CTX::instance()->geom.doubleClickedSurfaceCommand.size()) {
        CTX::instance()->geom.doubleClickedEntityTag = faces[0]->tag();
        if(CTX::instance()->geom.doubleClickedSurfaceCommand == "ONELAB")
          FlGui::instance()->onelabContext->show(2, faces[0]->tag());
        else
          ParseString(CTX::instance()->geom.doubleClickedSurfaceCommand, true);
      }
      else if(regions.size() &&
              CTX::instance()->geom.doubleClickedVolumeCommand.size()) {
        CTX::instance()->geom.doubleClickedEntityTag = regions[0]->tag();
        if(CTX::instance()->geom.doubleClickedVolumeCommand == "ONELAB")
          FlGui::instance()->onelabContext->show(3, regions[0]->tag());
        else
          ParseString(CTX::instance()->geom.doubleClickedVolumeCommand, true);
      }
      else if(views.size() &&
              views[0]->getOptions()->doubleClickedCommand.size()) {
        CTX::instance()->post.doubleClickedView = views[0]->getIndex();
        ParseString(views[0]->getOptions()->doubleClickedCommand, true);
      }
      else if(points.size() &&
              CTX::instance()->post.doubleClickedGraphPointCommand.size()) {
        CTX::instance()->post.doubleClickedGraphPointX = points[0].x();
        CTX::instance()->post.doubleClickedGraphPointY = points[0].y();
        ParseString(CTX::instance()->post.doubleClickedGraphPointCommand, true);
      }
      else { // popup quick access menu
        status_options_cb(nullptr, (void *)"quick_access");
      }
      Fl::event_clicks(-1);
      return 1;
    }
    _setLastHandled(this);
    take_focus(); // force keyboard focus when we click in the window
    _curr.set(_ctx, Fl::event_x(), Fl::event_y());
    if(Fl::event_button() == 1 && !Fl::event_state(FL_SHIFT) &&
       !Fl::event_state(FL_ALT)) {
      if(!lassoMode && Fl::event_state(FL_CTRL)) { lassoMode = true; }
      else if(lassoMode) {
        lassoMode = false;
        if(selectionMode && CTX::instance()->mouseSelection) {
          // will try to select multiple entities
          _trySelection = 2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else {
          if(CTX::instance()->camera) {
            Camera *cam = &(_ctx->camera);
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
          else {
            lassoZoom(_ctx, _click, _curr);
          }
        }
      }
      else if(CTX::instance()->mouseSelection) {
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
        if(selectionMode && CTX::instance()->mouseSelection) {
          // will try to unselect multiple entities
          _trySelection = -2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else {
          lassoZoom(_ctx, _click, _curr);
        }
      }
      else if(CTX::instance()->mouseSelection) {
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

  case FL_MOUSEWHEEL: {
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    double dy = Fl::event_dy();
    double fact =
      (5. * CTX::instance()->zoomFactor * fabs(dy) + h()) / (double)h();
    bool direction = (CTX::instance()->mouseInvertZoom) ? (dy <= 0) : (dy > 0);
    if(CTX::instance()->camera) {
      fact = (direction ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
      redraw();
    }
    else {
      _ctx->s[0] *= (direction ? fact : 1. / fact);
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
      if(lassoMode) { redraw(); }
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
        else if(Fl::event_button() == 1 && !Fl::event_state(FL_SHIFT) &&
                !Fl::event_state(FL_ALT)) {
          if(CTX::instance()->useTrackball)
            _ctx->addQuaternion(
              (2. * _prev.win[0] - w()) / w(), (h() - 2. * _prev.win[1]) / h(),
              (2. * _curr.win[0] - w()) / w(), (h() - 2. * _curr.win[1]) / h());
          else {
            _ctx->r[1] +=
              ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)w() : 0.);
            _ctx->r[0] +=
              ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)h());
          }
        }
        // m2 or (m1 and shift) => zoom (only move in y is used)
        // but start point is the center of the homothety
        else if(Fl::event_button() == 2 ||
                (Fl::event_button() == 1 && Fl::event_state(FL_SHIFT))) {
          // isotrop zoom in camera mode
          if(CTX::instance()->camera) {
            double dy = (int)_curr.win[1] - (int)_prev.win[1];
            double fact =
              (CTX::instance()->zoomFactor * fabs(dy) + (double)h()) /
              (double)h();
            fact = ((dy > 0) ? fact : 1. / fact);
            _ctx->camera.zoom(fact);
            _ctx->camera.update();
            redraw();
          }
          else {
            // move in y greater than move in x
            if(fabs(dy) > fabs(dx)) {
              double fact =
                (CTX::instance()->zoomFactor * fabs(dy) + h()) / (double)h();
              _ctx->s[0] *= ((dy > 0) ? fact : 1. / fact);
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
          if(CTX::instance()->camera) {
            Camera *cam = &(_ctx->camera);
            double theta_x = cam->radians *
                             (-(double)_prev.win[0] + (double)_curr.win[0]) *
                             2. / h();
            double theta_y = cam->radians *
                             (-(double)_prev.win[1] + (double)_curr.win[1]) *
                             2. / h();
            cam->moveRight(theta_x);
            cam->moveUp(theta_y);
          }
          else {
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
    if(lassoMode) { redraw(); }
    else if(addPointMode && !Fl::event_state(FL_SHIFT)) {
      cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
      // find line in real space corresponding to current cursor position
      double p[3], d[3];
      _ctx->unproject(_curr.win[0], _curr.win[1], p, d);
      // find closest point to the center of gravity
      double r[3] = {CTX::instance()->cg[0] - p[0],
                     CTX::instance()->cg[1] - p[1],
                     CTX::instance()->cg[2] - p[2]},
             t;
      t = prosca(r, d);
      for(int i = 0; i < 3; i++) {
        if(!FlGui::instance()->elementaryContext->frozenPointCoord(i)) {
          _point[i] = p[i] + t * d[i];
          if(CTX::instance()->geom.snap[i]) {
            double d = _point[i] / CTX::instance()->geom.snap[i];
            double f = floor(d);
            double c = ceil(d);
            double n = (d - f < c - d) ? f : c;
            _point[i] = n * CTX::instance()->geom.snap[i];
          }
        }
      }
      FlGui::instance()->elementaryContext->updatePoint(_point, addPointMode);
      redraw();
    }
    else { // hover mode
      if(_curr.win[0] != _prev.win[0] || _curr.win[1] != _prev.win[1]) {
        std::vector<GVertex *> vertices;
        std::vector<GEdge *> edges;
        std::vector<GFace *> faces;
        std::vector<GRegion *> regions;
        std::vector<MElement *> elements;
        std::vector<SPoint2> points;
        std::vector<PView *> views;
        bool res = _select(_selection, false, CTX::instance()->mouseHoverMeshes,
                           CTX::instance()->mouseHoverMeshes, (int)_curr.win[0],
                           (int)_curr.win[1], 5, 5, vertices, edges, faces,
                           regions, elements, points, views);
        if((_selection == ENT_ALL && res) ||
           (_selection == ENT_POINT && vertices.size()) ||
           (_selection == ENT_CURVE && edges.size()) ||
           (_selection == ENT_SURFACE && faces.size()) ||
           (_selection == ENT_VOLUME && regions.size()))
          cursor(FL_CURSOR_CROSS, FL_BLACK, FL_WHITE);
        else
          cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
        std::string text, cmd;
        bool multiline = CTX::instance()->tooltips;
        if(vertices.size()) {
          text = vertices[0]->getInfoString(true, multiline);
          cmd = CTX::instance()->geom.doubleClickedPointCommand;
        }
        else if(edges.size()) {
          text = edges[0]->getInfoString(true, multiline);
          cmd = CTX::instance()->geom.doubleClickedCurveCommand;
        }
        else if(faces.size()) {
          text = faces[0]->getInfoString(true, multiline);
          cmd = CTX::instance()->geom.doubleClickedSurfaceCommand;
        }
        else if(regions.size()) {
          text = regions[0]->getInfoString(true, multiline);
          cmd = CTX::instance()->geom.doubleClickedVolumeCommand;
        }
        else if(elements.size()) {
          text = elements[0]->getInfoString(multiline);
        }
        else if(points.size()) {
          char tmp[256];
          sprintf(tmp, "Point (%g, %g)", points[0].x(), points[0].y());
          text = tmp;
          cmd = CTX::instance()->post.doubleClickedGraphPointCommand;
        }
        else if(views.size()) {
          char tmp[256];
          sprintf(tmp, "View[%d]", views[0]->getIndex());
          text = tmp;
          cmd = views[0]->getOptions()->doubleClickedCommand;
        }
        if(cmd.size()) {
          if(multiline) text += "\n\n";
          else text += " ";
          if(cmd == "ONELAB") {
            text += std::string("Double-click to edit parameters");
          }
          else {
            text += std::string("Double-click to execute\n\n");
            std::replace(cmd.begin(), cmd.end(), '\r', ' ');
            text += cmd;
          }
        }
        if(CTX::instance()->tooltips)
          drawTooltip(text);
        else
          Msg::StatusBar(false, text.c_str());
        if(Msg::GetVerbosity() == 99)
          Msg::Debug(ReplaceSubString("\n", " ", text).c_str());
      }
    }
    _prev.set(_ctx, Fl::event_x(), Fl::event_y());
    return 1;

  default: return Fl_Gl_Window::handle(event);
  }
}

int openglWindow::pixel_w()
{
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 4)
  return Fl_Gl_Window::pixel_w();
#elif(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
  return Fl_Gl_Window::pixel_w();
#else
  return w();
#endif
}

int openglWindow::pixel_h()
{
#if(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3) && (FL_PATCH_VERSION >= 4)
  return Fl_Gl_Window::pixel_h();
#elif(FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION >= 4)
  return Fl_Gl_Window::pixel_h();
#else
  return h();
#endif
}

bool openglWindow::_select(
  int type, bool multiple, bool mesh, bool post, int x, int y, int w, int h,
  std::vector<GVertex *> &vertices, std::vector<GEdge *> &edges,
  std::vector<GFace *> &faces, std::vector<GRegion *> &regions,
  std::vector<MElement *> &elements, std::vector<SPoint2> &points,
  std::vector<PView *> &views)
{
  // test: completely deactivate GL_SELECT passes when mouse selection is off,
  // to see if unaccelerated (pure CPU) selection buffer is the reason for slow
  // graphics performance on some Windows machines (cf. #2567, #2320, #2211,
  // #1358, #1313). The hypothesis is that some recent opengl drivers don't
  // support GL_SELECT mode on GPU anymore, and revert to the CPU for rendering
  // the selection buffer, which would kill interactive performance.
  if(!CTX::instance()->mouseSelection) return false;

  // same lock as in draw() to prevent firing up a GL_SELECT rendering pass
  // while a GL_RENDER pass is happening (due to the asynchronus nature of
  // Fl::check()s
  if(_lock) return false;
  _lock = true;
  make_current();
  bool ret = _ctx->select(type, multiple, mesh, post, x, y, w, h, vertices,
                          edges, faces, regions, elements, points, views);
  _lock = false;
  return ret;
}

char openglWindow::selectEntity(int type, std::vector<GVertex *> &vertices,
                                std::vector<GEdge *> &edges,
                                std::vector<GFace *> &faces,
                                std::vector<GRegion *> &regions,
                                std::vector<MElement *> &elements,
                                std::vector<SPoint2> &points,
                                std::vector<PView *> &views)
{
  if(!FlGui::available()) return 'q';

  // force keyboard focus in GL window
  take_focus();
  _selection = type;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  changeSelection = 0;
  endSelection = 0;
  undoSelection = 0;
  invertSelection = 0;

  while(1) {
    if(!FlGui::available()) return 'q';
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    FlGui::wait();
    if(!FlGui::available()) return 'q';
    if(changeSelection) {
      Msg::Debug("Changing selection mode to %d", changeSelection);
      _selection = changeSelection;
      changeSelection = 0;
    }
    if(quitSelection) {
      _selection = ENT_NONE;
      selectionMode = false;
      lassoMode = false;
      addPointMode = 0;
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
      if(_selection == ENT_NONE) { // just report the mouse click
        selectionMode = false;
        return 'c';
      }
      else if(_select(_selection, multi, true, true, _trySelectionXYWH[0],
                      _trySelectionXYWH[1], _trySelectionXYWH[2],
                      _trySelectionXYWH[3], vertices, edges, faces, regions,
                      elements, points, views)) {
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

void openglWindow::drawTooltip(const std::string &text)
{
#if defined(NEW_TOOLTIPS)
  if(text.empty()) { _tooltip->hide(); }
  else {
    _tooltip->position(Fl::event_x_root(), Fl::event_y_root() + 20);
    _tooltip->value(text);
    _tooltip->show();
  }
#else
  static char str[1024];
  strncpy(str, text.c_str(), sizeof(str) - 1);
  str[sizeof(str) - 1] = '\0';
  Fl_Tooltip::exit(nullptr);
  bool enabled = Fl_Tooltip::enabled();
  if(!enabled) Fl_Tooltip::enable();
  double d1 = Fl_Tooltip::delay();
  double d2 = Fl_Tooltip::hoverdelay();
  Fl_Tooltip::delay(0);
  Fl_Tooltip::hoverdelay(0);
  Fl_Tooltip::enter_area(this, _curr.win[0], _curr.win[1], 100, 50, str);
  Fl_Tooltip::delay(d1);
  Fl_Tooltip::hoverdelay(d2);
  if(!enabled) Fl_Tooltip::disable();
#endif
}

void openglWindow::moveWithGamepad()
{
  if(CTX::instance()->gamepad && CTX::instance()->gamepad->active && Nautilus) {
    if(!(_ctx->camera.on)) _ctx->camera.init();
    if(_drawn && (_lastHandled == this || _lastHandled == nullptr)) {
      Nautilus->move();
      this->flush();
    }
  }
}
