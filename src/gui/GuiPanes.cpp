// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <algorithm>
#include <climits>
#include <cstring>

#include "GuiPanes.h"
#include "Gui.h"
#include "GuiScene.h"
#include "GuiActions.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContext.h"
#include "glApi.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

// --- a pane: its view, and the events of its surface

GuiPanes::Pane::Pane() : view(new sceneView()) {}

GuiPanes::Pane::~Pane() { delete view; }

void GuiPanes::Pane::modifiers(bool shift, bool ctrl, bool alt, bool super)
{
  _input.shift = shift;
  _input.ctrl = ctrl;
  _input.alt = alt;
  _input.super = super;
}

void GuiPanes::Pane::_at(double x, double y)
{
  _input.dx = _moved ? x - _lastX : 0.;
  _input.dy = _moved ? y - _lastY : 0.;
  _lastX = _input.x = x;
  _lastY = _input.y = y;
  _moved = true;
}

void GuiPanes::Pane::_handle()
{
  GuiPanes &all = GuiPanes::instance();
  // the view asks for the draws it needs: one it did not ask for would start
  // the studio frames over
  if(all._tk.prepare && all._tk.prepare(this)) {
    all.place(this);
    view->handleMouse(_input);
  }
  for(int b = 0; b < 3; b++) _input.clicked[b] = _input.released[b] = false;
  _input.doubleClicked = false;
  _input.wheel = 0.;
  _input.dx = _input.dy = 0.;
}

void GuiPanes::Pane::moved(double x, double y)
{
  _at(x, y);
  _handle();
}

void GuiPanes::Pane::pressed(int button, double x, double y,
                             double doubleClick)
{
  if(button < 0 || button > 2) return;
  GuiPanes::instance()._current = this;
  _at(x, y);
  _input.clicked[button] = _input.dragging[button] = true;
  double now = TimeOfDay();
  _input.doubleClicked = button == 0 && now - _lastPress < doubleClick;
  if(button == 0) _lastPress = _input.doubleClicked ? 0. : now;
  _handle();
}

void GuiPanes::Pane::released(int button, double x, double y)
{
  if(button < 0 || button > 2) return;
  _at(x, y);
  _input.released[button] = true;
  _input.dragging[button] = false;
  _handle();
}

void GuiPanes::Pane::wheel(double dy, double x, double y)
{
  if(dy == 0.) return;
  _at(x, y);
  _input.wheel = dy;
  _handle();
}

void GuiPanes::Pane::left()
{
  _moved = false;
  view->pointerLeft();
}

// --- the set of panes

GuiPanes &GuiPanes::instance()
{
  static GuiPanes it;
  return it;
}

GuiPanes::Pane *GuiPanes::_make(Pane *from)
{
  if(!_tk.makePane) return nullptr;
  Pane *p = _tk.makePane(from);
  if(!p) return nullptr;
  if(from)
    p->view->getDrawContext()->copyViewAttributes(from->view->getDrawContext());
  _panes.push_back(p);
  return p;
}

GuiPanes::Pane *GuiPanes::start(const Toolkit &toolkit)
{
  _tk = toolkit;
  _setHost();
  _current = _make(nullptr);
  startTimers();
  return _current;
}

void GuiPanes::stop()
{
  _panes.clear();
  _current = nullptr;
  _animating = false;
  _tk = Toolkit();
}

GuiPanes::Pane *GuiPanes::paneOf(sceneView *view) const
{
  for(Pane *p : _panes)
    if(p->view == view) return p;
  return nullptr;
}

void GuiPanes::dropped(Pane *p)
{
  auto it = std::find(_panes.begin(), _panes.end(), p);
  if(it == _panes.end()) return;
  _panes.erase(it);
  if(_current == p) _current = _panes.empty() ? nullptr : _panes[0];
}

void GuiPanes::redrawAll()
{
  if(!_tk.redraw) return;
  for(Pane *p : _panes) _tk.redraw(p);
}

void GuiPanes::place(Pane *p)
{
  int w = 0, h = 0;
  double f = 1.;
  if(_tk.size) _tk.size(p, w, h, f);
  p->view->setRect(0, 0, w, h);
  p->view->setOrigin(0., 0., h, f);
}

void GuiPanes::draw(Pane *p)
{
  int w = 0, h = 0;
  double f = 1.;
  if(_tk.size) _tk.size(p, w, h, f);
  if(w < 1 || h < 1) return;
  _drawing = true;
  if(_captureW > 0 && _captureH > 0) {
    // in the bottom-left corner, where PixelBuffer::fill() reads, the rest
    // cleared
    int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
    glDisable(GL_SCISSOR_TEST);
    glViewport(0, 0, (int)(w * f + .5), (int)(h * f + .5));
    glClearColor(0.f, 0.f, 0.f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    p->view->setRect(0, h - lh, lw, lh);
    p->view->setOrigin(0., 0., h, f);
    p->view->draw(f, h);
    place(p);
  }
  else {
    place(p);
    p->view->draw(f, h);
  }
  glShader::release();
  putBackState();
  _drawing = false;
}

void GuiPanes::putBackState()
{
  glPixelStorei(GL_PACK_ALIGNMENT, 4);
  glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
  glPixelStorei(GL_PACK_ROW_LENGTH, 0);
  glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
  if(glApi::BindBuffer) {
    glApi::BindBuffer(0x88EB /* GL_PIXEL_PACK_BUFFER */, 0);
    glApi::BindBuffer(0x88EC /* GL_PIXEL_UNPACK_BUFFER */, 0);
    glApi::BindBuffer(0x8892 /* GL_ARRAY_BUFFER */, 0);
  }
  if(glApi::BindVertexArray) glApi::BindVertexArray(0);
  if(glApi::UseProgram) glApi::UseProgram(0);
  if(glApi::ActiveTexture) glApi::ActiveTexture(0x84C0 /* GL_TEXTURE0 */);
  glBindTexture(GL_TEXTURE_2D, 0);
  glDisable(GL_SCISSOR_TEST);
  glDisable(GL_BLEND);
  glDisable(GL_DEPTH_TEST);
  glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
}

void GuiPanes::split(char how, double ratio)
{
  if(!_current) return;
  if(how == 'u') {
    Pane *keep = !_current->window ? _current : nullptr;
    for(Pane *p : _panes)
      if(!keep && !p->window) keep = p;
    if(!keep) return;
    std::vector<Pane *> gone;
    for(Pane *p : _panes)
      if(p != keep && !p->window) gone.push_back(p);
    for(Pane *p : gone) _panes.erase(std::find(_panes.begin(), _panes.end(), p));
    _current = keep;
    if(_tk.unsplit) _tk.unsplit(keep, gone);
    redrawAll();
    return;
  }
  if(how != 'h' && how != 'v') {
    Msg::Error("Unknown window splitting method '%c'", how);
    return;
  }
  if(_current->window) {
    Msg::Error("Only the graphic windows of the main window can be split");
    return;
  }
  if(!_tk.split) return;
  Pane *was = _current;
  Pane *fresh = _make(was);
  if(!fresh) return;
  if(ratio <= 0. || ratio >= 1.) ratio = .5;
  _tk.split(was, fresh, how, ratio);
  _current = fresh;
  redrawAll();
}

void GuiPanes::newWindow()
{
  if(!_tk.newWindow) return;
  Pane *fresh = _make(_current);
  if(!fresh) return;
  fresh->window = true;
  _current = fresh;
  _tk.newWindow(fresh);
}

void GuiPanes::startTimers()
{
  if(!_tk.later) return;
  if(_animating && !_animationArmed) {
    _animationArmed = true;
    _tk.later(0.01, [this]() {
      _animationArmed = false;
      if(!_animating) return;
      animationTick();
      startTimers();
    });
  }
  if(!_gamepadArmed) {
    _gamepadArmed = true;
    // the option may be switched on: looked at again now and then
    double period = Scene::gamepadPeriod();
    _tk.later(period > 0. ? period : 3., [this]() {
      _gamepadArmed = false;
      if(_tk.later == nullptr) return;
      if(_current && Scene::gamepadTurn(_current->view) && _tk.redraw)
        _tk.redraw(_current);
      startTimers();
    });
  }
}

void GuiPanes::_clearSelected()
{
  _vertices.clear();
  _edges.clear();
  _faces.clear();
  _regions.clear();
  _elements.clear();
  _points.clear();
  _views.clear();
}

void GuiPanes::_pixelSize(Pane *p, int &width, int &height)
{
  width = height = 0;
  if(!p || !_tk.size) return;
  int w = 0, h = 0;
  double f = 1.;
  _tk.size(p, w, h, f);
  width = (int)(w * f + 0.5);
  height = (int)(h * f + 0.5);
}

// the picture of the current view, or all the tiled ones as they sit in the
// main window: each drawn by its view at its share of the size, in its own
// context, whatever the size of its surface
bool GuiPanes::_print(int width, int height, int supersampling,
                      unsigned int format, unsigned int type, void *pixels,
                      bool composite)
{
  if(!_current || width < 1 || height < 1 || !_tk.prepare || !_tk.size)
    return false;
  std::vector<Pane *> tiled;
  if(composite && _tk.origin)
    for(Pane *p : _panes)
      if(!p->window) tiled.push_back(p);
  if(tiled.size() < 2) {
    if(!_tk.prepare(_current)) return false;
    place(_current);
    bool ok = _current->view->printTo(width, height, supersampling, format,
                                      type, pixels);
    if(_tk.redraw) _tk.redraw(_current);
    return ok;
  }

  // the room the views share, in logical pixels
  struct box {
    Pane *p;
    int x, y, w, h;
  };
  std::vector<box> boxes;
  int x0 = INT_MAX, y0 = INT_MAX, x1 = INT_MIN, y1 = INT_MIN;
  for(Pane *p : tiled) {
    box b = {p, 0, 0, 0, 0};
    double f = 1.;
    _tk.origin(p, b.x, b.y);
    _tk.size(p, b.w, b.h, f);
    if(b.w < 1 || b.h < 1) continue;
    boxes.push_back(b);
    x0 = std::min(x0, b.x);
    y0 = std::min(y0, b.y);
    x1 = std::max(x1, b.x + b.w);
    y1 = std::max(y1, b.y + b.h);
  }
  if(boxes.empty()) return false;
  double sx = width / (double)(x1 - x0), sy = height / (double)(y1 - y0);
  PixelBuffer all(width, height, (GLenum)format, (GLenum)type);
  for(const box &b : boxes) {
    // rows from the bottom
    int px0 = (int)((b.x - x0) * sx + 0.5);
    int px1 = std::min(width, (int)((b.x + b.w - x0) * sx + 0.5));
    int py0 = (int)((y1 - b.y - b.h) * sy + 0.5);
    int py1 = std::min(height, (int)((y1 - b.y) * sy + 0.5));
    if(px1 - px0 < 1 || py1 - py0 < 1 || !_tk.prepare(b.p)) continue;
    place(b.p);
    PixelBuffer one(px1 - px0, py1 - py0, (GLenum)format, (GLenum)type);
    if(b.p->view->printTo(px1 - px0, py1 - py0, supersampling, format, type,
                          one.getPixels()))
      all.copyPixels(px0, py0, &one);
    if(_tk.redraw) _tk.redraw(b.p);
  }
  std::memcpy(pixels, all.getPixels(),
              (std::size_t)width * height * all.getNumComp() *
                all.getDataSize());
  return true;
}

void GuiPanes::_setHost()
{
  Scene::Host held;
  held.redraw = []() { instance().redrawAll(); };
  held.redrawView = [](sceneView *view) {
    GuiPanes &all = instance();
    if(Pane *p = all.paneOf(view))
      if(all._tk.redraw) all._tk.redraw(p);
  };
  held.check = [](bool rateLimited) { Gui::instance().check(rateLimited); };
  held.wait = [](double seconds, bool force) {
    if(seconds < 0.)
      Gui::instance().wait(force);
    else
      Gui::instance().wait(seconds, force);
  };
  held.drawCurrent = []() {
    GuiPanes &all = instance();
    if(all._current && all._tk.drawNow) all._tk.drawNow(all._current);
  };
  held.uiScale = []() {
    GuiPanes &all = instance();
    int w = 0, h = 0;
    double f = 1.;
    if(all._current && all._tk.size) all._tk.size(all._current, w, h, f);
    return (float)f;
  };
  held.numViews = []() { return (int)instance()._panes.size(); };
  held.cursor = [](Scene::Cursor kind) {
    GuiPanes &all = instance();
    if(all._tk.cursor) all._tk.cursor(kind == Scene::Picking);
  };
  held.current = []() -> sceneView * {
    GuiPanes &all = instance();
    return all._current ? all._current->view : nullptr;
  };
  held.setCurrent = [](sceneView *view) {
    GuiPanes &all = instance();
    if(Pane *p = all.paneOf(view)) all._current = p;
  };
  held.later = _tk.later;
  held.buttonDown = _tk.buttonDown;
  held.context = _tk.context;
  held.makeCurrent = [](sceneView *view) {
    GuiPanes &all = instance();
    if(Pane *p = all.paneOf(view))
      if(all._tk.prepare) all._tk.prepare(p);
  };
  held.screen = _tk.screen;
  Scene::setHost(held);
}

// --- the scene operations, the same for every interface of panes

struct GuiPanesOps {
  static GuiPanes &all() { return GuiPanes::instance(); }

  static void pumpScene(bool rateLimited) {}
  static void sceneShownElsewhere() {}
  static std::string scenePicture(int &width, int &height, bool always)
  {
    return "";
  }
  static bool sceneMoved() { return false; }
  static void sceneResize(int width, int height) {}
  static void scenePointer(double x, double y, int button, int what,
                           double wheel, bool shift, bool ctrl, bool alt)
  {
  }

  static bool sceneKey(char key)
  {
    bool taken = false;
    for(GuiPanes::Pane *p : all()._panes)
      if(p->view->key(key)) {
        taken = true;
        if(all()._tk.redraw) all()._tk.redraw(p);
      }
    return taken;
  }

  static void sceneMessage(const std::string &first, const std::string &second)
  {
    GuiPanes::Pane *p = all()._current;
    if(!p) return;
    p->view->screenMessage[0] = first;
    p->view->screenMessage[1] = second;
    if(all()._tk.redraw) all()._tk.redraw(p);
  }

  static drawContext *getCurrentDrawContext()
  {
    GuiPanes::Pane *p = all()._current;
    return p ? p->view->getDrawContext() : nullptr;
  }

  static void getCurrentPixelSize(int &width, int &height)
  {
    all()._pixelSize(all()._current, width, height);
  }

  static void setCurrentOpenglWindow(int which)
  {
    if(which >= 0 && which < (int)all()._panes.size())
      all()._current = all()._panes[(std::size_t)which];
  }

  static void showAllInEveryWindow()
  {
    for(GuiPanes::Pane *p : all()._panes)
      if(drawContext *ctx = p->view->getDrawContext()) ctx->showAll();
    all().redrawAll();
  }

  static void splitCurrentOpenglWindow(char how, double ratio)
  {
    all().split(how, ratio);
  }

  static void copyCurrentOpenglWindowToClipboard()
  {
    GuiPanes &a = all();
    GuiPanes::Pane *p = a._current;
    int w = 0, h = 0;
    a._pixelSize(p, w, h);
    if(w < 1 || h < 1 || !a._tk.clipboard || !a._tk.prepare ||
       !a._tk.prepare(p))
      return;
    a.draw(p);
    glFinish();
    std::vector<unsigned char> rgba((std::size_t)w * h * 4);
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, rgba.data());
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    a._tk.clipboard(w, h, rgba);
    if(a._tk.redraw) a._tk.redraw(p);
  }

  // a vector output (gl2ps), from the draw of the surface
  static void beginGraphicCapture(int &width, int &height, bool composite)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(width > w || height > h) {
      Msg::Warning("This interface cannot render a picture larger than the "
                   "graphic window (%d x %d): clamping", w, h);
      width = std::min(width, w);
      height = std::min(height, h);
    }
    if(width < 1) width = 1;
    if(height < 1) height = 1;
    all()._captureW = width;
    all()._captureH = height;
  }

  static void endGraphicCapture()
  {
    all()._captureW = all()._captureH = 0;
    all().redrawAll();
  }

  static PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                                 unsigned int type)
  {
    int width = 0, height = 0;
    getCurrentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;
    // the aspect ratio is kept when only one of General.PrintWidth and
    // PrintHeight is given
    CTX *c = CTX::instance();
    if(c->print.width > 0 || c->print.height > 0) {
      if(c->print.width <= 0) {
        width = (int)(width * c->print.height / (double)height);
        height = c->print.height;
      }
      else if(c->print.height <= 0) {
        height = (int)(height * c->print.width / (double)width);
        width = c->print.width;
      }
      else {
        width = c->print.width;
        height = c->print.height;
      }
    }
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    if(all()._print(width, height, 1, format, type, buffer->getPixels(),
                    c->print.compositeWindows ? true : false))
      return buffer;
    // without framebuffer objects: what the surface shows, which may be
    // smaller
    delete buffer;
    beginGraphicCapture(width, height, false);
    buffer = new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    endGraphicCapture();
    return buffer;
  }

  static void orientViews(const std::string &what, bool reverse, bool sync)
  {
    std::vector<sceneView *> views;
    for(GuiPanes::Pane *p : all()._panes)
      if(!p->window) views.push_back(p->view);
    if(views.empty() && all()._current) views.push_back(all()._current->view);
    Scene::orientViews(views, what, reverse, sync);
    all().redrawAll();
  }

  static void setMouseSelection(bool on) {}

  static void toggleAnimation()
  {
    all()._animating = !all()._animating;
    all().startTimers();
  }

  static bool animating() { return all()._animating; }

  static void abortSelection()
  {
    GuiPanes::Pane *p = all()._current;
    if(!p) return;
    p->view->quitSelection = 1;
    p->view->selectionMode = false;
  }

  static void setAddPointMode(bool on)
  {
    for(GuiPanes::Pane *p : all()._panes) p->view->addPointMode = on;
  }

  static void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image")
      for(GuiPanes::Pane *p : all()._panes)
        if(p->view->getDrawContext())
          p->view->getDrawContext()->invalidateBgImageTexture();
    all().redrawAll();
  }

  static char selectEntity(int type)
  {
    GuiPanes &a = all();
    a._clearSelected();
    if(!a._current) return 'q';
    return a._current->view->selectEntity(type, a._vertices, a._edges,
                                          a._faces, a._regions, a._elements,
                                          a._points, a._views);
  }

  static bool pickAt(int type, bool mesh, bool post, int x, int y, int w,
                     int h)
  {
    GuiPanes &a = all();
    a._clearSelected();
    if(!a._current || !a._tk.prepare || !a._tk.prepare(a._current))
      return false;
    a.place(a._current);
    return a._current->view->pick(type, mesh, post, x, y, w, h, a._vertices,
                                  a._edges, a._faces, a._regions,
                                  a._elements, a._points, a._views);
  }

  static bool printView(int width, int height, int supersampling,
                        unsigned int format, unsigned int type, void *pixels)
  {
    return all()._print(width, height, supersampling, format, type, pixels,
                        CTX::instance()->print.compositeWindows ? true : false);
  }

  static const std::vector<GVertex *> &selectedVertices()
  {
    return all()._vertices;
  }
  static const std::vector<GEdge *> &selectedEdges() { return all()._edges; }
  static const std::vector<GFace *> &selectedFaces() { return all()._faces; }
  static const std::vector<GRegion *> &selectedRegions()
  {
    return all()._regions;
  }
  static const std::vector<MElement *> &selectedElements()
  {
    return all()._elements;
  }
  static const std::vector<SPoint2> &selectedPoints() { return all()._points; }
  static const std::vector<PView *> &selectedViews() { return all()._views; }
};

void GuiPanes::offer(const char *name)
{
  GuiSceneOps ops;
#define GUI_SCENE_TAKE(fn, args, call) ops.fn = GuiPanesOps::fn;
  GUI_SCENE_VOID(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(ret, fn, args, call, none) ops.fn = GuiPanesOps::fn;
  GUI_SCENE_VALUE(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(type, fn) ops.fn = GuiPanesOps::fn;
  GUI_SCENE_LIST(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
  Gui::offerScene(name, ops);
}

#endif
