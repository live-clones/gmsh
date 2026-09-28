// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <cmath>
#include <cstdlib>
#include <algorithm>


#include "sceneView.h"
#include "sceneHost.h"
#include "Gui.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Numeric.h"
#include "Camera.h"
#include "OpenFile.h"
#include "OS.h"
#include "StringUtils.h"
#include "VertexArray.h"
#include "glApi.h"
#include "glImmediate.h"
#include "glMatrix.h"
#include "glShader.h"
#include "GModel.h"
#include "GEntity.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "GRegion.h"
#include "MElement.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

std::vector<sceneView *> sceneView::_all;

sceneView::sceneView()
  : _x(0), _y(0), _w(1), _h(1), _lassoMode(false), _trySelection(0),
    _addQuery(false), _selection(ENT_NONE), _hoverBehind(false),
    selectionMode(false), endSelection(0), undoSelection(0),
    invertSelection(0), quitSelection(0), changeSelection(0)
{
  _all.push_back(this);
  _originX = _originY = 0.;
  _pixelFactor = 1.;
  _windowHeight = 0;
  _drawn = false;
  addPointMode = false;
  _point[0] = _point[1] = _point[2] = 0.;
  _ctx = new drawContext();
  _lassoXY[0] = _lassoXY[1] = 0.;
  for(int i = 0; i < 4; i++) _trySelectionXYWH[i] = 0;
  _highlighted = nullptr;
  _highlightModel = nullptr;
  _highlightDim = _highlightTag = 0;
  _highlightAsked = false;
  _pickStepTime = 0.;
  _stepping = false;
  _stepAnchor[0] = _stepAnchor[1] = 0.;
  _studioAsked = _studioTimer = _accumulating = false;
  _studioArmed = 0;
  _studioX = _studioY = _studioW = _studioH = 0;
  _studioPrinted = 0;
  _again = false;
  _printW = _printH = 0;
  _printScale = 1.;
  _spin = _spinFrom = _spinPath = _spinHot = _fire = _fireTime = 0.;
  _buttonHeld = false;
  for(int i = 0; i < 16; i++) _frameView[i] = _studioModel[i] = 0.;
  _hoverAnchor[0] = _hoverAnchor[1] = 0.;
  for(int i = 0; i < 4; i++) _hoverBox[i] = 0.;
}

sceneView::~sceneView()
{
  _all.erase(std::remove(_all.begin(), _all.end(), this), _all.end());
  delete _ctx;
}

void sceneView::setRect(int x, int y, int w, int h)
{
  _x = x;
  _y = y;
  _w = (w > 1) ? w : 1;
  _h = (h > 1) ? h : 1;
}

void sceneView::setOrigin(double x, double y, int height, double pixelFactor)
{
  _originX = x;
  _originY = y;
  _windowHeight = height;
  _pixelFactor = pixelFactor;
}

// the messages of a selection (Msg::StatusGl) at the top of the view, and what
// the cursor is over by the cursor, both in boxes over the picture and neither
// in a print
void sceneView::_drawScreenMessage()
{
  if(CTX::instance()->printing) return;
  std::string msg = screenMessage[0];
  if(screenMessage[1].size()) msg += "\n" + screenMessage[1];
  double a[3], b[3];
  bool measured = _ctx->segment(a, b);
  if(msg.empty() && _hoverText.empty() && _pinned.empty() && !measured)
    return;

  // in the pixel coordinates of draw2d, over everything
  gmshMatrixMode(GMSH_PROJECTION);
  double px[16];
  glMatrix::ortho(_ctx->viewport[0], _ctx->viewport[2], _ctx->viewport[1],
                  _ctx->viewport[3], -100., 100., px);
  gmshLoadMatrix(px);
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshLoadIdentity();
  glImmediate::flush();
  glDisable(GL_DEPTH_TEST);

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
  // that they travel with the model: each is kept whole in the view while its
  // point is in it, and leaves the view with that point
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
  if(measured) {
    double mid[3] = {0.5 * (a[0] + b[0]), 0.5 * (a[1] + b[1]),
                     0.5 * (a[2] + b[2])}, win[2];
    if(_ctx->world2Window(mid, win)) {
      drawContext::global()->setFont(CTX::instance()->glFontEnum,
                                     drawContext::global()->getFontSize());
      double h = drawContext::global()->getStringHeight();
      // just above the line: a box of one line is two heights tall
      _ctx->drawTextBox(measurePoints(a, b)[0], win[0], win[1] + 2. * h + 4.,
                        1, nullptr, false, tint);
    }
  }
  glImmediate::flush();
  glEnable(GL_DEPTH_TEST);
}

// a border inverting what it crosses, a faint wash of the foreground inside
void sceneView::_drawLasso()
{
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
  glBlendFunc(GL_ONE_MINUS_DST_COLOR, GL_ZERO);
  gmshColor3d(1., 1., 1.);
  if(selectionMode && CTX::instance()->mouseSelection)
    gmshLineStipple(1, 0x0F0F);
  // the width is in display pixels, the coordinates in window pixels
  double hw = 1.;
  gmshLineWidth(2. * hw * _ctx->highResolutionPixelFactor());
  // the horizontal segments stretched by half the width, the vertical ones
  // shortened, so that each corner is inverted once
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
  _lassoXY[0] = _curr.win[0];
  _lassoXY[1] = _curr.win[1];
  glDisable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
}

// which pane the keyboard and the .geo commands act on
void sceneView::_drawBorder()
{
  if(Scene::host().numViews && Scene::host().numViews() < 2) return;
  bool current = ((Scene::host().current ? Scene::host().current() : nullptr) == this);

  gmshMatrixMode(GMSH_PROJECTION);
  double px[16];
  glMatrix::ortho(_ctx->viewport[0], _ctx->viewport[2], _ctx->viewport[1],
                  _ctx->viewport[3], -1., 1., px);
  gmshLoadMatrix(px);
  gmshMatrixMode(GMSH_MODELVIEW);
  gmshLoadIdentity();
  glImmediate::flush();
  glDisable(GL_DEPTH_TEST);
  if(current)
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.text);
  else
    gmshColor4ubv((GLubyte *)&CTX::instance()->color.fg);
  gmshLineWidth(current ? 2.f : 1.f);
  gmshBegin(GL_LINE_LOOP);
  gmshVertex2d(_ctx->viewport[0] + 1, _ctx->viewport[1] + 1);
  gmshVertex2d(_ctx->viewport[2] - 1, _ctx->viewport[1] + 1);
  gmshVertex2d(_ctx->viewport[2] - 1, _ctx->viewport[3] - 1);
  gmshVertex2d(_ctx->viewport[0] + 1, _ctx->viewport[3] - 1);
  gmshEnd();
  glImmediate::flush();
  gmshLineWidth(1.f);
  glEnable(GL_DEPTH_TEST);
}

// both moved by the same offset: the half eye separation of a stereo pair
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

void sceneView::contextChanged()
{
  // the buffer objects and entry points belonged to the previous context
  VertexArray::invalidateBuffers();
  glApi::reset();
  glShader::reset();
  glImmediate::resetMatrices();
  glApi::describe();
  if(CTX::instance()->shaders) glShader::available();
}

void sceneView::draw(double pixelFactor, int windowHeight)
{
  double start = TimeOfDay();
  _drawn = true;
  // a draw the studio timer did not ask for, or that anyone else asked for
  // as well, starts the accumulation over; one the highlight asked for keeps
  // what was accumulated, which this frame -- the same as the last -- is not
  // added to. The sample the timer asked for in the same frame is not drawn
  // either.
  bool highlightOnly = _highlightAsked;
  if(_studioAsked && _highlightAsked) _ctx->studioSample--;
  _studioTimer = _studioAsked && !_highlightAsked;
  _studioAsked = _highlightAsked = false;
  if(!_studioTimer && !highlightOnly) _ctx->studioSample = 0;
  _ctx->invalidatePickCache();
  glShader::setContext(Scene::host().context ? Scene::host().context() :
                                                 nullptr);

  // the scissor box keeps glClear() inside the pane: several panes share one
  // framebuffer
  int px, py, pw, ph;
  if(_printW) {
    // at its own scale: what is sized in pixels follows
    px = py = 0;
    pw = _printW;
    ph = _printH;
    _ctx->viewport[2] = (int)(_printW / _printScale + 0.5);
    _ctx->viewport[3] = (int)(_printH / _printScale + 0.5);
    _ctx->setHighResolutionPixelFactor(_printScale);
  }
  else {
    px = (int)(_x * pixelFactor + 0.5);
    py = (int)((windowHeight - _y - _h) * pixelFactor + 0.5);
    pw = (int)(_w * pixelFactor + 0.5);
    ph = (int)(_h * pixelFactor + 0.5);
    _ctx->viewport[2] = _w;
    _ctx->viewport[3] = _h;
    _ctx->setHighResolutionPixelFactor(pixelFactor);
  }
  if(pw < 1) pw = 1;
  if(ph < 1) ph = 1;
  _ctx->viewport[0] = 0;
  _ctx->viewport[1] = 0;
  _ctx->viewportOrigin[0] = px;
  _ctx->viewportOrigin[1] = py;
  drawContext::global()->setPixelFactor(_ctx->highResolutionPixelFactor());

  glViewport(px, py, pw, ph);
  glEnable(GL_SCISSOR_TEST);
  glScissor(px, py, pw, ph);

  bool rough = _lassoMode && CTX::instance()->fastRedraw;
  if(rough) {
    CTX::instance()->mesh.draw = 0;
    CTX::instance()->post.draw = 0;
  }

  if(CTX::instance()->printing && !CTX::instance()->print.background)
    glClearColor(1.0F, 1.0F, 1.0F, 0.0F);
  else
    glClearColor(
      (GLclampf)(CTX::instance()->unpackRed(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackGreen(CTX::instance()->color.bg) / 255.),
      (GLclampf)(CTX::instance()->unpackBlue(CTX::instance()->color.bg) / 255.),
      0.0F);
  glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

  if(CTX::instance()->camera && !CTX::instance()->stereo) {
    // both eyes' buffers may be left selected by stereo
    if(!_printW) glDrawBuffer(GL_BACK);
    _cameraMatrices();
    _ctx->draw3d();
    _burn();
    _drawPointBeingPlaced();
    _ctx->draw2d();
    _studioFrame(highlightOnly);
    _drawHighlight();
  }
  else if(CTX::instance()->camera && CTX::instance()->stereo) {
    Camera *cam = &(_ctx->camera);
    if(!cam->on) cam->init();
    cam->giveViewportDimension(_ctx->viewport[2], _ctx->viewport[3]);
    XYZ eye = cam->eyesep / 2.0 * cam->right;
    double frustum[16], view[16];
    // right eye
    gmshMatrixMode(GMSH_PROJECTION);
    double left = -cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
    double right = cam->screenratio * cam->wd2 - 0.5 * cam->eyesep * cam->ndfl;
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
    _drawHighlight();
    _drawScreenMessage();
    _drawBorder();
    // left eye
    gmshMatrixMode(GMSH_PROJECTION);
    left = -cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
    right = cam->screenratio * cam->wd2 + 0.5 * cam->eyesep * cam->ndfl;
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
    _drawHighlight();
  }
  else {
    _ctx->draw3d();
    memcpy(_frameView, _ctx->model, sizeof(_frameView));
    _burn();
    _drawPointBeingPlaced();
    _ctx->draw2d();
    _studioFrame(highlightOnly);
    _drawHighlight();
  }
  _drawScreenMessage();
  _drawBorder();
  if(_lassoMode) _drawLasso();
  glImmediate::flush();
  drawContext::global()->flushString();
  if(rough) {
    CTX::instance()->mesh.draw = 1;
    CTX::instance()->post.draw = 1;
  }
  _studioTimer = false;

  glDisable(GL_SCISSOR_TEST);

  // FIXME: this should not be done here
  _ctx->camera.update();
  // (read by the graphics tests, benchmarks/graphics)
  Msg::Debug("sceneView::draw() done in %g s", TimeOfDay() - start);
}

void sceneView::_drawPointBeingPlaced()
{
  if(!addPointMode) return;
  gmshColor4ubv((GLubyte *)&CTX::instance()->color.geom.highlight[0]);
  gmshPointSize(CTX::instance()->geom.pointSize *
                _ctx->highResolutionPixelFactor());
  gmshBegin(GL_POINTS);
  gmshVertex3d(_point[0], _point[1], _point[2]);
  gmshEnd();
}

void sceneView::_cameraMatrices() { _ctx->initCameraMatrices(_frameView); }

// the studio frames, with the light, the dome and the projection jittered, each
// added to the average put on the window; a print draws them all at once
void sceneView::_studioFrame(bool highlightOnly)
{
  CTX *ctx = CTX::instance();
  _accumulating = false;
  int n = ctx->studioSamples;
  int printed = _studioPrinted;
  _studioPrinted = 0;
  if(!glShader::enabled() || ctx->shading < 1 || n < 2 || ctx->stereo) {
    _ctx->studioSample = 0;
    return;
  }
  int k = _ctx->studioSample;
  int x = _ctx->viewportOrigin[0], y = _ctx->viewportOrigin[1];
  int w = _printW ? _printW : (int)(_w * _pixelFactor + 0.5);
  int h = _printW ? _printH : (int)(_h * _pixelFactor + 0.5);
  bool same = x == _studioX && y == _studioY && w == _studioW &&
              h == _studioH &&
              !memcmp(_studioModel, _frameView, sizeof(_studioModel));
  // the second draw of a print: the average is put back
  if(ctx->printing && _again && printed == n && k == 0 && same) {
    glImmediate::flush();
    drawContext::global()->flushString();
    if(glShader::showAccumulation(x, y, w, h, n - 1)) return;
  }
  if(k > 0) {
    // the view changed since the last frame: start over
    if(!same) {
      Msg::Debug("Studio frames: the view changed, starting over");
      k = _ctx->studioSample = 0;
    }
    // the same frame as the last, not added: the average is put back
    else if(highlightOnly) {
      glImmediate::flush();
      drawContext::global()->flushString();
      if(!glShader::showAccumulation(x, y, w, h, k)) {
        _ctx->studioSample = 0;
        return;
      }
    }
    else {
      // what the overlay collected is still pending
      glImmediate::flush();
      drawContext::global()->flushString();
      if(!glShader::accumulate(x, y, w, h, k == 1, k)) {
        _ctx->studioSample = 0;
        return;
      }
      Msg::Debug("Studio frame %d of %d accumulated", k, n);
    }
  }
  memcpy(_studioModel, _frameView, sizeof(_studioModel));
  _studioX = x;
  _studioY = y;
  _studioW = w;
  _studioH = h;

  // all of them for a print; for the window, as many as fit in a fiftieth of
  // a second, since one draw is shown once a refresh at most. A plain frame
  // (k = 0) only starts the timer, and a mouse button held stops it.
  bool live = !ctx->printing;
  bool held = Scene::host().buttonDown ? Scene::host().buttonDown() :
                                         _buttonHeld;
  if(!live || (k > 0 && !held)) {
    if(!_ctx->drawStudioFrames(k + 1, w, h, _frameView, live ? 0.02 : 0.))
      return;
  }
  if(!live) {
    _studioPrinted = (_ctx->studioSample == n - 1) ? n : 0;
    _ctx->studioSample = 0;
    return;
  }
  k = _ctx->studioSample;
  if(k + 1 < n) {
    _armStudio(k ? 0. : 0.03);
    _accumulating = _studioTimer;
  }
}

void sceneView::_armStudio(double seconds)
{
  if(!Scene::host().later) return;
  int armed = ++_studioArmed;
  Scene::host().later(seconds, [this, armed]() {
    if(armed == _studioArmed) _studioSample();
  });
}

void sceneView::_studioSample()
{
  // not while a mouse button is down: each step redraws the plain frame
  bool held = Scene::host().buttonDown ? Scene::host().buttonDown() :
                                         _buttonHeld;
  if(held) {
    _armStudio(0.05);
    return;
  }
  _ctx->studioSample++;
  // asked for last: an ordinary request clears the flag
  if(Scene::host().redrawView)
    Scene::host().redrawView(this);
  else if(Scene::host().redraw)
    Scene::host().redraw();
  _studioAsked = true;
}

bool sceneView::printTo(int width, int height, int supersampling,
                        unsigned int format, unsigned int type, void *pixels)
{
  if(Scene::host().makeCurrent) Scene::host().makeCurrent(this);
  // the buffers of this view, not of the one that drew last
  glShader::setContext(Scene::host().context ? Scene::host().context() :
                                               nullptr);
  if(!glShader::beginPrintTarget(width, height)) return false;
  _printW = width;
  _printH = height;
  // what is in the units of the window follows the pixel factor, the widths
  // given in pixels follow the pixel scale
  int ss = std::max(1, supersampling);
  int pixelW = (int)(_w * _pixelFactor + 0.5);
  double ratio = 1.;
  if(CTX::instance()->print.scalePixelSizes && pixelW > 0)
    ratio = (double)width / (ss * pixelW);
  _printScale = ss * _pixelFactor * ratio;
  glImmediate::pixelScale(ss * ratio);
  drawContextGlobal *kept = nullptr;
  if(Scene::host().printFonts) {
    if(drawContextGlobal *fonts = Scene::host().printFonts()) {
      kept = drawContext::global();
      drawContext::setGlobal(fonts);
    }
  }
  draw(_pixelFactor, _windowHeight);
  if(kept) {
    delete drawContext::global();
    drawContext::setGlobal(kept);
  }
  glShader::readPrintTarget(width, height, format, type, pixels);
  glShader::endPrintTarget();
  glImmediate::pixelScale(1.);
  _printW = _printH = 0;
  _printScale = 1.;
  if(Scene::host().redraw) Scene::host().redraw();
  return true;
}

// dies down in a couple of seconds once the spinning stops; not accumulated
void sceneView::_burn(bool sameFrame)
{
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
  int w = _printW ? _printW : (int)(_w * _pixelFactor + 0.5);
  int h = _printW ? _printH : (int)(_h * _pixelFactor + 0.5);
  if(!glShader::fire(_ctx->viewportOrigin[0], _ctx->viewportOrigin[1], w, h,
                     _fire, now)) {
    _fire = 0.;
    return;
  }
  _ctx->studioSample = 0;
  if(!_printW && !sameFrame && Scene::host().later)
    Scene::host().later(0.03, [this]() {
      if(Scene::host().redraw) Scene::host().redraw();
    });
}

bool sceneView::_select(int type, bool multiple, bool mesh, bool post, int x,
                        int y, int w, int h, std::vector<GVertex *> &vertices,
                        std::vector<GEdge *> &edges,
                        std::vector<GFace *> &faces,
                        std::vector<GRegion *> &regions,
                        std::vector<MElement *> &elements,
                        std::vector<SPoint2> &points,
                        std::vector<PView *> &views)
{
  if(!CTX::instance()->mouseSelection) return false;
  glShader::setContext(Scene::host().context ? Scene::host().context() :
                                                 nullptr);
  return _ctx->select(type, multiple, mesh, post, x, y, w, h, vertices, edges,
                      faces, regions, elements, points, views);
}

// rate limited: a trackpad gives a burst of wheel events for one swipe, and one
// key press can reach the view more than once
void sceneView::_stepPick(int direction, bool rateLimited)
{
  if(_stepping) return;
  double now = TimeOfDay();
  // a short guard tells the two deliveries of one press from a held key
  // repeating
  if(now - _pickStepTime < (rateLimited ? 0.2 : 0.03)) return;
  _pickStepTime = now;
  _stepAnchor[0] = _curr.win[0];
  _stepAnchor[1] = _curr.win[1];
  _stepping = true;
  _ctx->stepPick(direction);
  _hover();
  _stepping = false;
}

// the identifier image a pick reads from does not change with the highlight
void sceneView::_highlight(GEntity *e)
{
  if(!CTX::instance()->mouseHoverHighlight) e = nullptr;
  if(e == _highlightEntity()) return;
  _highlighted = e;
  _highlightModel = e ? e->model() : nullptr;
  _highlightDim = e ? e->dim() : 0;
  _highlightTag = e ? e->tag() : 0;
  _overlayChanged();
}

GEntity *sceneView::_highlightEntity()
{
  if(!_highlighted) return nullptr;
  if(std::find(GModel::list.begin(), GModel::list.end(), _highlightModel) ==
       GModel::list.end() ||
     _highlightModel->getEntityByTag(_highlightDim, _highlightTag) !=
       _highlighted)
    _highlighted = nullptr;
  return _highlighted;
}

// over the frame, with the matrices and the depth of the frame drawn last: what
// is in front stays so, and the mesh the polygon offset draws nearer stays
// visible
void sceneView::_drawHighlight()
{
  GEntity *e = _highlightEntity();
  if(!e) return;
  glImmediate::flush();
  drawContext::global()->flushString();
  if(CTX::instance()->camera)
    _cameraMatrices();
  else {
    gmshMatrixMode(GMSH_PROJECTION);
    gmshLoadMatrix(_ctx->proj);
    gmshMatrixMode(GMSH_MODELVIEW);
    gmshLoadMatrix(_ctx->model);
  }
  for(int i = 0; i < 6; i++) gmshClipPlane(i, CTX::instance()->clipPlane[i]);
  gmshDepthTest(true);
  glDepthFunc(GL_LEQUAL);
  // drawn wider than in the frame: the pixels gained do not have quite the
  // depth of those covered
  if(e->dim() < 2) glDepthRange(0., 1. - 1e-5);
  char was = e->getSelection();
  e->setSelection(GEntity::SelectHover);
  _ctx->drawEntity(e);
  e->setSelection(was);
  glImmediate::flush();
  glDepthRange(0., 1.);
  glDepthFunc(GL_LESS);
}

void sceneView::_lassoZoom()
{
  if(_click.win[0] == _curr.win[0] || _click.win[1] == _curr.win[1]) return;

  _ctx->s[0] *= (double)_ctx->viewport[2] / (_curr.win[0] - _click.win[0]);
  _ctx->s[1] *= (double)_ctx->viewport[3] / (_curr.win[1] - _click.win[1]);
  _ctx->s[2] = std::min(_ctx->s[0], _ctx->s[1]);

  // recenter around the center of the lasso rectangle
  mousePosition tmp(_click);
  tmp.wnr[0] = 0.5 * (_click.wnr[0] + _curr.wnr[0]);
  tmp.wnr[1] = 0.5 * (_click.wnr[1] + _curr.wnr[1]);
  tmp.recenter(_ctx);

  _ctx->initPosition(false);
  drawContext::global()->draw();
  Gui::instance().manipulator.reload();
}

// the pass of drawContext::pickBehind()
bool sceneView::_probeBehind()
{
  if(!CTX::instance()->mouseSelection) return false;
  glShader::setContext(Scene::host().context ? Scene::host().context() :
                                               nullptr);
  return _ctx->pickBehind(_selection, CTX::instance()->mouseHoverMeshes,
                          CTX::instance()->mouseHoverMeshes,
                          (int)_curr.win[0], (int)_curr.win[1], 5, 5);
}

// What the pointer is over: a box by the pointer or the status bar, as
// General.Tooltips says, says what a click would pick, and the cursor says
// whether there is anything. When several entities are under it, Alt and the
// wheel step through them, and this says which one is current.
void sceneView::_hover()
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;

  // during a selection the meshes and the views are picked whether or not the
  // hover looks at them otherwise: what is highlighted is what a click would
  // take
  bool all = selectionMode || CTX::instance()->mouseHoverMeshes;
  // the mesh element under the cursor is looked for in the octree of the
  // model: a query asks for it on a click, a hover would ask on every move
  int elems = CTX::instance()->pickElements;
  CTX::instance()->pickElements = 0;
  bool res = _select(_selection, false, all, all, (int)_curr.win[0],
                     (int)_curr.win[1], 5, 5, vertices, edges, faces, regions,
                     elements, points, views);
  CTX::instance()->pickElements = elems;

  // said both ways round: a holder that keeps the cursor it was given would be
  // left holding a hand
  bool pickable = (_selection == ENT_ALL && res) ||
                  (_selection == ENT_POINT && vertices.size()) ||
                  (_selection == ENT_CURVE && edges.size()) ||
                  (_selection == ENT_SURFACE && faces.size()) ||
                  (_selection == ENT_VOLUME && regions.size());
  if(Scene::host().cursor)
    Scene::host().cursor(pickable ? Scene::Picking : Scene::Ordinary);

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
    snprintf(tmp, sizeof(tmp), "Point (%g, %g)", points[0].x(), points[0].y());
    text = tmp;
    cmd = CTX::instance()->post.doubleClickedGraphPointCommand;
  }
#if defined(HAVE_POST)
  else if(views.size()) {
    // named as a query names it
    char tmp[256];
    snprintf(tmp, sizeof(tmp), "View[%d]", views[0]->getIndex());
    text = tmp;
    if(views[0]->getData() && views[0]->getData()->getName().size())
      text += " \"" + views[0]->getData()->getName() + "\"";
    cmd = views[0]->getOptions()->doubleClickedCommand;
  }
#endif

  // what a double-click and the wheel would do, after the information, in as
  // few words as will do: the box is read at a glance
  std::vector<std::string> hints;
  if(cmd.size()) {
    if(cmd == "ONELAB") {
      if(onelabHasContext()) hints.push_back("Double-click to edit parameters");
    }
    else {
      std::replace(cmd.begin(), cmd.end(), '\r', ' ');
      hints.push_back("Double-click to execute: " + cmd);
    }
  }

  GEntity *over = nullptr;
  if(vertices.size())
    over = vertices[0];
  else if(edges.size())
    over = edges[0];
  else if(faces.size())
    over = faces[0];
  else if(regions.size())
    over = regions[0];
  _highlight(over);

  // while a measurement waits for its second point, the line follows the
  // cursor over the model, so that its length is seen as it is chosen
  if(measureMode() && _ctx->numMarks() == 1) {
    double a[3], p[3];
    if(_ctx->mark(0, a) && _ctx->pickPoint(p))
      _ctx->setSegment(a, p);
    else
      _ctx->clearSegment();
    _overlayChanged();
  }

  // how far under the cursor this one is and whether there is more, whenever
  // there is something to step to. The image of the pick shows only what is
  // in front, so when nothing else is seen around the cursor the pass is run
  // once more without this entity, once per entity as it costs a redraw.
  if(text.size()) {
    char tmp[256];
    int d = _ctx->pickDepth(), more = _ctx->pickCandidates() - 1;
    bool behind = more > 0;
    if(!behind) {
      if(text != _hoverBehindFor) {
        _hoverBehindFor = text;
        _hoverBehind = _probeBehind();
      }
      behind = _hoverBehind;
    }
    // what was stepped past is in front, what a step would reach is behind
    const char *keys = "(Alt+wheel or Alt+Up/Down)";
    if(d && more > 0)
      snprintf(tmp, sizeof(tmp), "%d in front, %d more behind %s", d, more,
               keys);
    else if(d && behind)
      snprintf(tmp, sizeof(tmp), "%d in front, more behind %s", d, keys);
    else if(d)
      snprintf(tmp, sizeof(tmp), "%d in front, nothing behind %s", d, keys);
    else if(more > 0)
      snprintf(tmp, sizeof(tmp), "%d more behind %s", more, keys);
    else if(behind)
      snprintf(tmp, sizeof(tmp), "More behind %s", keys);
    else
      tmp[0] = '\0';
    if(tmp[0]) hints.push_back(tmp);
  }
  for(std::size_t i = 0; i < hints.size(); i++)
    text += (multiline ? (i ? "\n" : "\n\n") : " ") + hints[i];

  if(CTX::instance()->tooltips)
    drawTooltip(text);
  else
    Msg::StatusBar(false, "%s", text.c_str());
  if(Msg::GetVerbosity() == 99)
    Msg::Debug("%s", ReplaceSubString("\n", " ", text).c_str());
}

// what is drawn over the frame changed, not the frame: the studio frames
// accumulated so far are kept
void sceneView::_overlayChanged()
{
  // asked for last, as the timer does; redraw() may draw at once where
  // redrawView() waits
  if(Scene::host().redrawView)
    Scene::host().redrawView(this);
  else if(Scene::host().redraw)
    Scene::host().redraw();
  _highlightAsked = true;
}

void sceneView::drawTooltip(const std::string &text)
{
  if(text.empty()) {
    if(_hoverText.empty()) return;
    _hoverText.clear();
    _overlayChanged();
    return;
  }
  // it follows the cursor, moving once the cursor has strayed sixty pixels
  // from where it hangs (or when it is under it, or says something else):
  // every move of it is a redraw
  double cx = _curr.win[0], cy = _curr.win[1];
  if(text == _hoverText) {
    // the box, from the top left of the view as the cursor is measured
    double left = _hoverBox[0], right = _hoverBox[0] + _hoverBox[2];
    double top = _ctx->viewport[3] - (_hoverBox[1] + _hoverBox[3]);
    double bottom = _ctx->viewport[3] - _hoverBox[1];
    bool over = (cx > left - 4. && cx < right + 4. && cy > top - 4. &&
                 cy < bottom + 4.);
    if(!over && fabs(cx - _hoverAnchor[0]) < 60. &&
       fabs(cy - _hoverAnchor[1]) < 60.)
      return;
  }
  _hoverText = text;
  _hoverAnchor[0] = cx;
  _hoverAnchor[1] = cy;
  _overlayChanged();
}

void sceneView::pinTooltip(const std::string &text, const double *xyz,
                           bool add)
{
  if(!add) {
    if(_pinned.empty() && text.empty()) return;
    _pinned.clear();
  }
  if(text.size() && xyz) {
    pinnedNote n;
    n.text = text;
    for(int i = 0; i < 3; i++) n.xyz[i] = xyz[i];
    _pinned.push_back(n);
  }
  if(Scene::host().redrawView)
    Scene::host().redrawView(this);
  else if(Scene::host().redraw)
    Scene::host().redraw();
}

void Scene::plainPipeline()
{
  glShader::release();
  if(glApi::ActiveTexture) glApi::ActiveTexture(GL_TEXTURE0);
}

void Scene::orientViews(const std::vector<sceneView *> &views,
                        const std::string &what, bool reverse, bool sync)
{
  for(std::size_t i = 0; i < views.size(); i++) {
    drawContext *ctx = views[i]->getDrawContext();
    if(!ctx) continue;
    if(sync && (what == "r" || what == "1:1")) {
      if(i == 0) continue;
      drawContext *first = views[0]->getDrawContext();
      if(!first) continue;
      if(what == "r")
        ctx->setQuaternion(first->quaternion[0], first->quaternion[1],
                           first->quaternion[2], first->quaternion[3]);
      else if(!CTX::instance()->camera) {
        for(int j = 0; j < 3; j++) {
          ctx->t[j] = first->t[j];
          ctx->s[j] = first->s[j];
        }
      }
      continue;
    }
    viewSetOrientation(ctx, what, reverse);
  }
  drawContext::global()->draw();
}

bool sceneView::key(char what)
{
  if(what == 'q' && _lassoMode) {
    _lassoMode = false;
    Scene::host().redraw();
    return true;
  }
  if(!selectionMode) return false;
  switch(what) {
  case 'e': endSelection = 1; break;
  case 'u': undoSelection = 1; break;
  case 'i': invertSelection = 1; break;
  case 'q': quitSelection = 1; break;
  default: return false;
  }
  return true;
}

void sceneView::handleMouse(const paneInput &in)
{
  double mx = in.x, my = in.y;

  // mx and my come in the space of the pane origin, not of the pane rectangle
  double lx = mx - _originX - _x, ly = my - _originY - _y;

  bool shift = in.shift, ctrl = in.ctrl, alt = in.alt;
  bool meta = in.super;

  // --- wheel: zoom
  if(in.wheel != 0. && contains(mx, my)) {
    double dy = -in.wheel;
    // the sign depends on the mouse, the trackpad and the system: the gesture
    // that brings the model closer steps to the entity in front
    bool direction = (CTX::instance()->mouseInvertZoom) ? (dy <= 0) : (dy > 0);
    // with Alt, the wheel steps through the entities under the pointer
    if(alt && CTX::instance()->mouseSelection && !_lassoMode && !addPointMode) {
      // _prev is what a move is measured against, and nothing has moved
      _stepPick(direction ? -1 : 1, true);
      return;
    }
    _prev.set(_ctx, (int)lx, (int)ly);
    double fact = (5. * CTX::instance()->zoomFactor * fabs(dy) + _h) / (double)_h;
    if(CTX::instance()->camera) {
      fact = (direction ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
    }
    else {
      _ctx->s[0] *= (direction ? fact : 1. / fact);
      _ctx->s[1] = _ctx->s[0];
      _ctx->s[2] = _ctx->s[0];
      _prev.recenter(_ctx);
    }
    if(Scene::host().redraw) Scene::host().redraw();
    Gui::instance().manipulator.reload();
  }

  // --- placing a new entity: Shift holds the coordinates
  if(addPointMode && contains(mx, my)) {
    if(!shift && (in.dx != 0. || in.dy != 0.)) {
      _curr.set(_ctx, (int)lx, (int)ly);
      GuiElementary &dialog = Gui::instance().elementary;
      geometryPointUnderCursor(_ctx, (int)_curr.win[0], (int)_curr.win[1],
                               dialog.frozen, _point);
      for(int i = 0; i < 3; i++) {
        if(dialog.frozen[i]) continue;
        char str[32];
        snprintf(str, sizeof(str), "%g", _point[i]);
        if(dialog.shape >= 1 && dialog.shape <= 11)
          dialog.value[dialog.shape][i] = str;
      }
      if(Scene::host().redraw) Scene::host().redraw();
    }
    return;
  }

  bool busy = _lassoMode;
  for(int b = 0; b < 3; b++)
    if(in.clicked[b] || in.released[b] || in.dragging[b]) busy = true;
  if(!busy && contains(mx, my) && (in.dx != 0. || in.dy != 0.)) {
    _curr.set(_ctx, (int)lx, (int)ly);
    // a pixel or two is not somewhere else: a trackpad nudges the pointer while
    // it is dragged over for the stepping
    if(fabs(_curr.win[0] - _stepAnchor[0]) > 3. ||
       fabs(_curr.win[1] - _stepAnchor[1]) > 3.) {
      _ctx->resetPick();
      _stepAnchor[0] = _curr.win[0];
      _stepAnchor[1] = _curr.win[1];
    }
    _hover();
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  // --- button press
  int button = -1;
  for(int b = 0; b < 3; b++)
    if(in.clicked[b]) button = b;

  if(button >= 0 && contains(mx, my)) {
    if(Scene::host().setCurrent) Scene::host().setCurrent(this);
    _curr.set(_ctx, (int)lx, (int)ly);
    // what the click does with the pick is not the hover's business
    _highlight(nullptr);
    drawTooltip("");
    _buttonHeld = true;
    _spin = _spinPath = _spinHot = 0.;
    _spinFrom = TimeOfDay();

    if(in.doubleClicked && !selectionMode &&
       CTX::instance()->mouseSelection) {
      _handleDoubleClick(lx, ly);
      _click.set(_ctx, (int)lx, (int)ly);
      _prev.set(_ctx, (int)lx, (int)ly);
      return;
    }

    if(button == 0 && !shift && !alt) {
      // Ctrl+click adds a query in query mode (when the clicks select), and
      // starts a lasso otherwise
      _addQuery = queryMode() && CTX::instance()->mouseSelection && ctrl;
      if(!_lassoMode && ctrl && !_addQuery) {
        _lassoMode = true;
        _lassoXY[0] = _curr.win[0];
        _lassoXY[1] = _curr.win[1];
      }
      else if(_lassoMode) {
        _lassoMode = false;
        if(selectionMode && CTX::instance()->mouseSelection) {
          _trySelection = 2;
          _trySelectionXYWH[0] = (int)(_click.win[0] + _curr.win[0]) / 2;
          _trySelectionXYWH[1] = (int)(_click.win[1] + _curr.win[1]) / 2;
          _trySelectionXYWH[2] = (int)fabs(_click.win[0] - _curr.win[0]);
          _trySelectionXYWH[3] = (int)fabs(_click.win[1] - _curr.win[1]);
        }
        else {
          _lassoZoom();
        }
      }
      else if(CTX::instance()->mouseSelection) {
        // will try to select an entity
        _trySelection = shift ? -1 : 1;
        _trySelectionXYWH[0] = (int)_curr.win[0];
        _trySelectionXYWH[1] = (int)_curr.win[1];
        _trySelectionXYWH[2] = 5;
        _trySelectionXYWH[3] = 5;
      }
    }
    else if(button == 1 && !selectionMode) {
      if(!CTX::instance()->camera) {
        _ctx->t[0] = _ctx->t[1] = _ctx->t[2] = 0.;
        _ctx->s[0] = _ctx->s[1] = _ctx->s[2] = 1.;
        if(Scene::host().redraw) Scene::host().redraw();
      }
      _lassoMode = false;
    }

    _click.set(_ctx, (int)lx, (int)ly);
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  // --- release
  if(in.released[0] || in.released[1] || in.released[2]) {
    _buttonHeld = false;
    if((Scene::host().current ? Scene::host().current() : nullptr) != this) return;
    _curr.set(_ctx, (int)lx, (int)ly);
    CTX::instance()->drawRotationCenter = 0;
    if(!_lassoMode) {
      CTX::instance()->mesh.draw = 1;
      CTX::instance()->post.draw = 1;
      if(Scene::host().redraw) Scene::host().redraw();
    }
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  // --- drag
  int dragButton = -1;
  for(int b = 0; b < 3; b++)
    if(in.dragging[b]) dragButton = b;
  if(dragButton < 0) return;
  if((Scene::host().current ? Scene::host().current() : nullptr) != this) return;

  _curr.set(_ctx, (int)lx, (int)ly);
  double dx = _curr.win[0] - _prev.win[0];
  double dy = _curr.win[1] - _prev.win[1];

  if(_lassoMode) {
    if(Scene::host().redraw) Scene::host().redraw();
    _prev.set(_ctx, (int)lx, (int)ly);
    return;
  }

  if(meta) {
    // select or unselect entities on the fly
    _trySelection = shift ? -1 : 1;
    _trySelectionXYWH[0] = (int)_curr.win[0];
    _trySelectionXYWH[1] = (int)_curr.win[1];
    _trySelectionXYWH[2] = 5;
    _trySelectionXYWH[3] = 5;
  }
  // (m1) and (!shift) and (!alt) => rotation
  else if(dragButton == 0 && !shift && !alt) {
    // the speed is the path drawn over a few hundredths of a second, not one
    // event's step: events arrive in clumps; a step counts for half a window at
    // most
    double now = TimeOfDay(), dt = now - _spinFrom;
    _spinPath += std::min(0.5, sqrt(dx * dx / (_w * (double)_w) +
                                    dy * dy / (_h * (double)_h)));
    if(dt > 0.25) { // the drag stopped for a while
      _spin = _spinPath = _spinHot = 0.;
      _spinFrom = now;
    }
    else if(dt >= 0.03) {
      _spin = 0.7 * _spin + 0.3 * std::min(40., _spinPath / dt);
      const double catches = 8.;
      _spinHot = (_spin > catches) ? _spinHot + dt : 0.;
      if(_spinHot > 0.25 && CTX::instance()->phlogiston) {
        if(_fire <= 0.) _fireTime = now;
        _fire = std::min(1.5, _fire + 1.5 * (_spin / catches - 1.) * dt);
      }
      _spinPath = 0.;
      _spinFrom = now;
    }
    if(CTX::instance()->useTrackball)
      _ctx->addQuaternion((2. * _prev.win[0] - _w) / _w,
                          (_h - 2. * _prev.win[1]) / _h,
                          (2. * _curr.win[0] - _w) / _w,
                          (_h - 2. * _curr.win[1]) / _h);
    else {
      _ctx->r[1] += ((fabs(dx) > fabs(dy)) ? 180. * dx / (double)_w : 0.);
      _ctx->r[0] += ((fabs(dx) > fabs(dy)) ? 0. : 180. * dy / (double)_h);
    }
  }
  // m2 or (m1 and shift) => zoom around the point that was clicked
  else if(dragButton == 2 ||
          (dragButton == 0 && shift)) {
    if(CTX::instance()->camera) {
      double fact =
        (CTX::instance()->zoomFactor * fabs(dy) + (double)_h) / (double)_h;
      fact = ((dy > 0) ? fact : 1. / fact);
      _ctx->camera.zoom(fact);
      _ctx->camera.update();
    }
    else {
      if(fabs(dy) > fabs(dx)) {
        double fact =
          (CTX::instance()->zoomFactor * fabs(dy) + _h) / (double)_h;
        _ctx->s[0] *= ((dy > 0) ? fact : 1. / fact);
        _ctx->s[1] = _ctx->s[0];
        _ctx->s[2] = _ctx->s[0];
        _click.recenter(_ctx);
      }
      else if(!CTX::instance()->useTrackball)
        _ctx->r[2] += -180. * dx / (double)_w;
    }
  }
  // other case => translation
  else {
    if(CTX::instance()->camera) {
      Camera *cam = &(_ctx->camera);
      double theta_x =
        cam->radians * (-(double)_prev.win[0] + (double)_curr.win[0]) * 2. / _h;
      double theta_y =
        cam->radians * (-(double)_prev.win[1] + (double)_curr.win[1]) * 2. / _h;
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
  if(Scene::host().redraw) Scene::host().redraw();
  Gui::instance().manipulator.reload();
  _prev.set(_ctx, (int)lx, (int)ly);
}

void sceneView::_handleDoubleClick(double lx, double ly)
{
  std::vector<GVertex *> vertices;
  std::vector<GEdge *> edges;
  std::vector<GFace *> faces;
  std::vector<GRegion *> regions;
  std::vector<MElement *> elements;
  std::vector<SPoint2> points;
  std::vector<PView *> views;
  _select(ENT_ALL, false, CTX::instance()->mouseHoverMeshes, true, (int)lx,
          (int)ly, 5, 5, vertices, edges, faces, regions, elements, points,
          views);

  struct {
    bool hit;
    int dim, tag;
    const std::string *command;
  } hits[4] = {
    {!vertices.empty(), 0, vertices.empty() ? 0 : vertices[0]->tag(),
     &CTX::instance()->geom.doubleClickedPointCommand},
    {!edges.empty(), 1, edges.empty() ? 0 : edges[0]->tag(),
     &CTX::instance()->geom.doubleClickedCurveCommand},
    {!faces.empty(), 2, faces.empty() ? 0 : faces[0]->tag(),
     &CTX::instance()->geom.doubleClickedSurfaceCommand},
    {!regions.empty(), 3, regions.empty() ? 0 : regions[0]->tag(),
     &CTX::instance()->geom.doubleClickedVolumeCommand}};

  for(int i = 0; i < 4; i++) {
    if(!_processDoubleClick(hits[i].hit ? 1 : 0, *hits[i].command)) continue;
    CTX::instance()->geom.doubleClickedEntityTag = hits[i].tag;
    if(*hits[i].command == "ONELAB")
      Gui::instance().onelabContext.show(hits[i].dim, hits[i].tag);
    else
      ParseString(*hits[i].command, true);
    return;
  }

  if(views.size() && views[0]->getOptions()->doubleClickedCommand.size()) {
    CTX::instance()->post.doubleClickedView = views[0]->getIndex();
    ParseString(views[0]->getOptions()->doubleClickedCommand, true);
    return;
  }
  if(points.size() &&
     CTX::instance()->post.doubleClickedGraphPointCommand.size()) {
    CTX::instance()->post.doubleClickedGraphPointX = points[0].x();
    CTX::instance()->post.doubleClickedGraphPointY = points[0].y();
    ParseString(CTX::instance()->post.doubleClickedGraphPointCommand, true);
  }
}

bool sceneView::_processDoubleClick(std::size_t num, const std::string &what)
{
  if(!num || what.empty()) return false;
  // the parameters of an entity, when there are some
  if(what == "ONELAB" && !onelabHasContext()) return false;
  return true;
}

char sceneView::selectEntity(int type, std::vector<GVertex *> &vertices,
                             std::vector<GEdge *> &edges,
                             std::vector<GFace *> &faces,
                             std::vector<GRegion *> &regions,
                             std::vector<MElement *> &elements,
                             std::vector<SPoint2> &points,
                             std::vector<PView *> &views)
{
  

  _selection = type;
  _trySelection = 0;
  selectionMode = true;
  quitSelection = 0;
  changeSelection = 0;
  endSelection = 0;
  undoSelection = 0;
  invertSelection = 0;

  while(1) {
    
    vertices.clear();
    edges.clear();
    faces.clear();
    regions.clear();
    elements.clear();
    if(Scene::host().wait) Scene::host().wait(-1., false);
    
    if(changeSelection) {
      Msg::Debug("Changing selection mode to %d", changeSelection);
      _selection = changeSelection;
      changeSelection = 0;
    }
    if(quitSelection) {
      _selection = ENT_NONE;
      selectionMode = false;
      _lassoMode = false;
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
      bool add = (_trySelection > 0);
      bool multi = (abs(_trySelection) > 1);
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
        return add ? 'l' : 'r';
      }
    }
  }
}

#endif
