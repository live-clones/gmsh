// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdio.h>
#include <string.h>
#include "openglWindow.h"
#include "drawContextFltkEmbedded.h"
#include "graphicWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "visibilityWindow.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "onelabGroup.h"
#include "onelabContextWindow.h"
#include "drawContext.h"
#include "OS.h"
#include "VertexArray.h"
#include "glMatrix.h"
#include "glShader.h"
#include "Context.h"
#include <cstring>
#include "GamePad.h"

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
  if(glShader::wanted()) mode |= FL_OPENGL3;
  return mode;
}

void resetOpenglMode()
{
  if(!FlGui::available()) return;
  int mode = openglWindowMode();
  for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
    for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
      FlGui::instance()->graph[i]->gl[j]->mode(mode);
  if(FlGui::instance()->fullscreen) FlGui::instance()->fullscreen->mode(mode);
}

openglWindow::openglWindow(int x, int y, int w, int h)
  : Fl_Gl_Window(x, y, w, h, "gl"), sceneView(new drawContext()), _lock(false),
    _drawn(false), Nautilus(nullptr)
{
  _studioAsked = _studioTimer = false;
  _studioW = _studioH = 0;
  _printW = _printH = 0;
  _printScale = 1.;

  if(CTX::instance()->gamepad)
    Fl::add_timeout(.5, navigator_handler, (void *)this);
}

openglWindow::~openglWindow()
{
  Fl::remove_timeout(_studioSampleCb, this);
  Fl::remove_timeout(_fireCb, this);
  delete _ctx;
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

// the messages of a selection (Msg::StatusGl) at the top of the window, and
// what the cursor is over by the cursor, both in boxes over the picture and
// neither in a print
void openglWindow::_drawScreenMessage()
{
  if(CTX::instance()->printing) return;
  std::string msg = screenMessage[0];
  if(screenMessage[1].size()) msg += "\n" + screenMessage[1];
  if(msg.size()) {
    drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                   drawContext::global()->getFontSize());
    double h = drawContext::global()->getStringHeight();
    _ctx->drawTextBox(msg, _ctx->viewport[2] / 2., _ctx->viewport[3] - 0.5 * h,
                      1);
  }
  // what the cursor is over, under what a query found: the query answered a
  // click and stays, the hover follows the cursor and gives way to it
  if(_hoverText.size())
    _ctx->drawTextBox(_hoverText, _hoverAnchor[0],
                      _ctx->viewport[3] - _hoverAnchor[1], 2, _hoverBox);
  // on paper of its own: the colour of the mark it hangs from
  // (General.Color.Query, which the mark wears at full strength), lightened
  // to the paper of a note over a light picture and darkened to the same
  // note over a dark one, where the full colour would glare
  CTX *c = CTX::instance();
  unsigned int q = c->color.query, bg = c->color.bg;
  double lum = 0.299 * c->unpackRed(bg) + 0.587 * c->unpackGreen(bg) +
               0.114 * c->unpackBlue(bg);
  bool dark = (lum < 110.);
  double paper = dark ? 0. : 255., mix = dark ? 0.32 : 0.45;
  unsigned int tint =
    c->packColor((int)(paper * (1. - mix) + mix * c->unpackRed(q)),
                 (int)(paper * (1. - mix) + mix * c->unpackGreen(q)),
                 (int)(paper * (1. - mix) + mix * c->unpackBlue(q)), 255);
  // the boxes the queries pin are drawn by the points they asked about, so
  // that they travel with the model: each is kept whole in the window while
  // its point is in it, and leaves the window with that point
  for(std::size_t i = 0; i < _pinned.size(); i++) {
    double win[2];
    if(!_ctx->world2Window(_pinned[i].xyz, win)) continue;
    bool in = (win[0] >= _ctx->viewport[0] && win[0] <= _ctx->viewport[2] &&
               win[1] >= _ctx->viewport[1] && win[1] <= _ctx->viewport[3]);
    _ctx->drawTextBox(_pinned[i].text, win[0], win[1], 2, nullptr, in, tint);
  }
  // the length of a measurement, on the same paper, over the middle of the
  // line it measures: it follows the line while the second point is chosen,
  // and stays there once it is taken
  double a[3], b[3], win[2];
  if(_ctx->segment(a, b)) {
    double mid[3] = {0.5 * (a[0] + b[0]), 0.5 * (a[1] + b[1]),
                     0.5 * (a[2] + b[2])};
    if(_ctx->world2Window(mid, win)) {
      drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                     drawContext::global()->getFontSize());
      double h = drawContext::global()->getStringHeight();
      // just above the line: a box of one line is two heights tall
      _ctx->drawTextBox(measurePoints(a, b)[0], win[0], win[1] + 2. * h + 4.,
                        1, nullptr, false, tint);
    }
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
  _studioTimer = _studioAsked;
  _studioAsked = false;
  if(!_studioTimer) _ctx->studioSample = 0;
  // some drawing routines can create data (STL triangulations, etc.): make sure
  // that we don't fire draw() while we are already drawing, e.g. due to an
  // impromptu Fl::check(). The same lock is also used in _select to guarantee
  // that we don't mix GL_RENDER and GL_SELECT rendering passes.
  _drawn = true;
  if(_lock) return;
  _lock = true;

  Msg::Debug("openglWindow::draw()");
  double start = TimeOfDay();

  // the picking image is out of date
  _ctx->invalidatePickCache();

  if(!context_valid()) {
    // the buffer objects and entry points belonged to the previous context
    VertexArray::invalidateBuffers();
    glApi::reset();
    glShader::reset();
    glImmediate::resetMatrices();
    // report what the new context can do
    glApi::describe();
    // report now if the shader pipeline cannot be had; if the program failed
    // to build, the fixed function pipeline cannot draw in this context
    // either: the windows get a context of their own for it, and are drawn
    // again then
    if(CTX::instance()->shaders && !glShader::available() &&
       (mode() & FL_OPENGL3) && !glShader::wanted()) {
      Fl::add_timeout(0., [](void *) { resetOpenglMode(); });
      _lock = false;
      return;
    }
  }
  glShader::setContext(context());

  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  if(_printW) {
    // a picture of its own size, drawn at its own scale: what is sized in
    // pixels (fonts, lines, points, the scales) follows
    _ctx->viewport[2] = (int)(_printW / _printScale + 0.5);
    _ctx->viewport[3] = (int)(_printH / _printScale + 0.5);
    _ctx->setHighResolutionPixelFactor(_printScale);
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
  drawContext::global()->setPixelFactor(_ctx->highResolutionPixelFactor());

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
    glImmediate::flush();
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
    glImmediate::flush();
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
    glImmediate::flush();
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
    gmshPointSize(CTX::instance()->geom.pointSize);
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
      // both eyes' buffers may be left selected by stereo (a print target
      // has no such buffer)
      if(!_printW) glDrawBuffer(GL_BACK);
      _cameraMatrices();
      _ctx->draw3d();
      _burn();
      _ctx->draw2d();
      _studioFrame();
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
      _burn();
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
      _burn(true); // the same frame as the other eye
      _ctx->draw2d();
      _drawScreenMessage();
      _drawBorder();
    }
    else {
      _ctx->draw3d();
      memcpy(_frameView, _ctx->model, sizeof(_frameView));
      _burn();
      _ctx->draw2d();
      _studioFrame();
      _drawScreenMessage();
      _drawBorder();
    }
  }
  glImmediate::flush();
  drawContext::global()->flushString();
  _lock = false;
  _studioTimer = false;
  // (read by the graphics tests, benchmarks/graphics)
  Msg::Debug("openglWindow::draw() done in %g s", TimeOfDay() - start);
}

void openglWindow::_cameraMatrices() { _ctx->initCameraMatrices(_frameView); }

// The accumulation of the studio shading: after a frame, while the view is
// still, the timer asks for more frames with the light, the dome and the
// projection jittered, and each is added to the average put on the window.
// A print does not wait: it draws them all at once.
void openglWindow::_studioFrame()
{
  Fl::remove_timeout(_studioSampleCb, this);
  CTX *ctx = CTX::instance();
  int n = ctx->studioSamples;
  int printed = _studioPrinted;
  _studioPrinted = 0;
  if(!glShader::enabled() || ctx->shading < 1 || n < 2 || ctx->stereo) {
    _ctx->studioSample = 0;
    return;
  }
  int k = _ctx->studioSample;
  int w = _printW ? _printW : pixel_w(), h = _printW ? _printH : pixel_h();
  // a print drawn again right after accumulating all its frames, of the same
  // view: the average is put back instead of being drawn a second time
  if(ctx->printing && _again && printed == n && k == 0 && w == _studioW &&
     h == _studioH &&
     !memcmp(_studioModel, _frameView, sizeof(_studioModel))) {
    glImmediate::flush();
    drawContext::global()->flushString();
    if(glShader::showAccumulation(w, h, n - 1)) return;
  }
  if(k > 0) {
    // the view changed since the last frame: start over
    if(w != _studioW || h != _studioH ||
       memcmp(_studioModel, _frameView, sizeof(_studioModel))) {
      Msg::Debug("Studio frames: the view changed, starting over");
      k = _ctx->studioSample = 0;
    }
    else {
      // the frame has to be complete before it is added: what the overlay
      // collected is still pending
      glImmediate::flush();
      drawContext::global()->flushString();
      if(!glShader::accumulate(w, h, k == 1, k)) {
        _ctx->studioSample = 0;
        return;
      }
      Msg::Debug("Studio frame %d of %d accumulated", k, n);
    }
  }
  memcpy(_studioModel, _frameView, sizeof(_studioModel));
  _studioW = w;
  _studioH = h;

  // The frames still to come, drawn here rather than one per draw of the
  // window: all of them for a print, which is the converged picture; for the
  // window, as many as fit in a fiftieth of a second, as one draw is shown
  // once a refresh of the display at most, which held a light model to a
  // frame per refresh however fast it drew. A plain frame (k = 0), which is
  // what every rotation, zoom or option change draws, only starts the timer:
  // accumulating there would slow the interaction down, and a mouse button
  // held anywhere stops it too.
  bool live = !ctx->printing;
  if(!live || (k > 0 && !Fl::pushed())) {
    if(!_ctx->drawStudioFrames(k + 1, w, h, _frameView, live ? 0.02 : 0.))
      return;
  }
  if(!live) {
    // all of them, for the view and the size recorded above
    _studioPrinted = (_ctx->studioSample == n - 1) ? n : 0;
    _ctx->studioSample = 0;
    return;
  }
  // after a plain frame, the view has to stay still a moment first
  k = _ctx->studioSample;
  if(k + 1 < n) Fl::add_timeout(k ? 0. : 0.03, _studioSampleCb, this);
}

bool openglWindow::printTo(int width, int height, int supersampling,
                           unsigned int format, unsigned int type,
                           void *pixels)
{
  make_current();
  // the buffers of this window, not of the one that drew last
  glShader::setContext(context());
  if(!glShader::beginPrintTarget(width, height)) return false;
  _printW = width;
  _printH = height;
  // the picture is the window scaled: by the supersampling, and by its size
  // relative to the window's unless the sizes given in pixels are to keep
  // their screen size; the fonts and everything else in the units of the
  // window follow the pixel factor, the line widths and point sizes given in
  // pixels of the window follow the pixel scale
  int ss = std::max(1, supersampling);
  double hr = w() ? (double)pixel_w() / (double)w() : 1.;
  double ratio = 1.;
  if(CTX::instance()->print.scalePixelSizes && pixel_w() > 0)
    ratio = (double)width / (ss * pixel_w());
  _printScale = ss * hr * ratio;
  glImmediate::pixelScale(ss * ratio);
  // the native font engine places its strings from the window's size and
  // scale, which the picture has neither of: the embedded fonts meanwhile
  drawContextGlobal *native = nullptr;
  if(drawContext::global()->getName() == "Fltk") {
    static bool warned = false;
    if(!warned)
      Msg::Warning("Font engine 'Native' cannot draw pictures of another size "
                   "than the window: using 'Embedded' for them");
    warned = true;
    native = drawContext::global();
    drawContext::setGlobal(new drawContextFltkEmbedded);
  }
  draw();
  if(native) {
    delete drawContext::global();
    drawContext::setGlobal(native);
  }
  glShader::readPrintTarget(width, height, format, type, pixels);
  glShader::endPrintTarget();
  glImmediate::pixelScale(1.);
  _printW = _printH = 0;
  _printScale = 1.;
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
  // a redraw already asked for by anyone else (an option changed, say) is a
  // plain frame, which starts the timer again itself; and one asked for
  // between now and the draw clears the flag set here
  if(w->damage()) return;
  w->_ctx->studioSample++;
  w->_studioAsked = true;
  w->Fl_Gl_Window::redraw();
}

// The fire lit by spinning the model: drawn over the scene at its current
// level, which dies down in a couple of seconds once the spinning stops,
// with a frame every 30 ms in the meantime. Not accumulated: the studio
// frames start over as long as it burns.
void openglWindow::_burn(bool sameFrame)
{
  if(!sameFrame) Fl::remove_timeout(_fireCb, this);
  if(!CTX::instance()->phlogiston) _fire = 0.;
  if(_fire <= 0.) return;
  double now = TimeOfDay();
  if(!_printW && !sameFrame) {
    _fire *= exp(-(now - _fireTime) / 1.5);
    _fireTime = now;
  }
  if(_fire < 0.02) {
    _fire = 0.;
    return;
  }
  glImmediate::flush();
  int w = _printW ? _printW : pixel_w(), h = _printW ? _printH : pixel_h();
  if(!glShader::fire(w, h, _fire, now)) {
    _fire = 0.;
    return;
  }
  _ctx->studioSample = 0;
  if(!_printW && !sameFrame) Fl::add_timeout(0.03, _fireCb, this);
}

void openglWindow::_fireCb(void *data) { ((openglWindow *)data)->redraw(); }

openglWindow *openglWindow::_lastHandled = nullptr;

void openglWindow::_setLastHandled(openglWindow *w)
{
  _lastHandled = w;
  FlGui::instance()->visibility->updatePerWindow();
}

// One step through the entities under the cursor for one press or one notch,
// which takes some holding down. A wheel event is rate limited because a
// mouse gives one for each notch but a trackpad gives a burst of them for a
// single swipe of two fingers, with more coming while it glides. A key is
// rate limited too, and against being stepped again from inside this call,
// because one press of it can reach this window more than once: macOS sends
// an FL_KEYBOARD for the command an arrow key stands for and another for the
// the events of FLTK, turned into what sceneView::handleMouse() reads
int openglWindow::handle(int event)
{
  switch(event) {
  case FL_FOCUS: // accept the focus when I'm asked if I want it
  case FL_UNFOCUS: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // Alt and the up or down arrows step through what is under the cursor,
    // as Alt and the wheel do, one entity at a time: a trackpad has no
    // notches to count
    if(Fl::event_state(FL_ALT) && CTX::instance()->mouseSelection &&
       !lassoMode && !addPointMode &&
       (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down)) {
      stepPick((Fl::event_key() == FL_Down) ? 1 : -1);
      return 1;
    }
    // override the default widget arrow-key-navigation
    if(FlGui::instance()->testArrowShortcuts()) return 1;
    return Fl_Gl_Window::handle(event);

  case FL_LEAVE:
    pointerLeft();
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
  case FL_RELEASE:
  case FL_DRAG:
  case FL_MOVE:
  case FL_MOUSEWHEEL: {
    paneInput in;
    in.x = Fl::event_x();
    in.y = Fl::event_y();
    in.w = w();
    in.h = h();
    in.shift = Fl::event_state(FL_SHIFT) ? true : false;
    in.ctrl = Fl::event_state(FL_CTRL) ? true : false;
    in.alt = Fl::event_state(FL_ALT) ? true : false;
    in.meta = Fl::event_state(FL_META) ? true : false;
    // FLTK numbers the buttons 1 left, 2 middle, 3 right; a drag goes with
    // the button pushed last
    int b = Fl::event_button();
    in.button = (b == FL_RIGHT_MOUSE) ? 1 : (b == FL_MIDDLE_MOUSE) ? 2 : 0;
    switch(event) {
    case FL_PUSH:
      in.kind = paneInput::Push;
      in.doubleClick = (Fl::event_clicks() == 1) && acceptsDoubleClick();
      break;
    case FL_RELEASE: in.kind = paneInput::Release; break;
    case FL_DRAG: in.kind = paneInput::Drag; break;
    case FL_MOUSEWHEEL:
      in.kind = paneInput::Wheel;
      in.wheel = Fl::event_dy();
      break;
    default: in.kind = paneInput::Move; break;
    }
    handleMouse(in);
    // the clicks start over after a double click
    if(in.doubleClick) Fl::event_clicks(-1);
    return 1;
  }

  default: return Fl_Gl_Window::handle(event);
  }
}

void openglWindow::hostRedraw() { redraw(); }

void openglWindow::hostClicked()
{
  _setLastHandled(this);
  take_focus(); // force keyboard focus when we click in the window
}

void openglWindow::hostViewChanged() { FlGui::instance()->manip->update(); }

void openglWindow::hostCursor(bool cross)
{
  cursor(cross ? FL_CURSOR_CROSS : FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
}

// the same lock as in draw(): no picking pass in the middle of a frame (an
// impromptu Fl::check() can deliver the event there), and the pass reads the
// buffers of this window
bool openglWindow::hostBeginGL()
{
  if(_lock) return false;
  _lock = true;
  make_current();
  glShader::setContext(context());
  return true;
}

void openglWindow::hostEndGL() { _lock = false; }

bool openglWindow::hostQueryMode() { return queryMode(); }

bool openglWindow::hostMeasureMode() { return measureMode(); }

bool openglWindow::hostFrozenCoordinate(int coord)
{
  return FlGui::instance()->elementaryContext->frozenPointCoord(coord);
}

void openglWindow::hostPointMoved(const double p[3], int mode)
{
  double pt[3] = {p[0], p[1], p[2]};
  FlGui::instance()->elementaryContext->updatePoint(pt, mode);
}

bool openglWindow::hostHasOnelabContext()
{
  return FlGui::instance()->onelab->hasContext();
}

void openglWindow::hostShowOnelabContext(int dim, int tag)
{
  FlGui::instance()->onelabContext->show(dim, tag);
}

void openglWindow::hostQuickAccess()
{
  status_options_cb(nullptr, (void *)"quick_access");
}

int openglWindow::pixel_w() { return Fl_Gl_Window::pixel_w(); }

int openglWindow::pixel_h() { return Fl_Gl_Window::pixel_h(); }

// the clicks and keys of a selection are taken by the event loop: wait for
// them until the selection has something to say
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
  beginSelection(type);

  while(1) {
    if(!FlGui::available()) return 'q';
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    FlGui::wait();
    if(!FlGui::available()) return 'q';
    char ret = selectionStep(vertices, edges, faces, regions, elements, points,
                             views);
    if(ret) return ret;
  }
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