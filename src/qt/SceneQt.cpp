// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Qt interface, see GuiScene.h: each view in a QOpenGLWidget
// of its own, the views of the main window split with QSplitter, a new
// graphic window a top-level widget holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#include "glApi.h"
#include "qtCommon.h"

#include "Gui.h"
#include "GuiScene.h"
#include "GuiActions.h"
#include "sceneView.h"
#include "sceneHost.h"
#include "sceneGamepad.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"
#include "PixelBuffer.h"
#include "OS.h"

#include <QApplication>
#include <QClipboard>
#include <QImage>
#include <QKeyEvent>
#include <QMainWindow>
#include <QMouseEvent>
#include <QOpenGLContext>
#include <QOpenGLWidget>
#include <QScreen>
#include <QSplitter>
#include <QTimer>
#include <QVBoxLayout>
#include <QWheelEvent>

namespace {

  class pane;
  std::vector<pane *> _panes;
  pane *_current = nullptr;
  QWidget *_root = nullptr;
  int _captureW = 0, _captureH = 0;
  bool _animating = false, _drawing = false;
  QTimer *_animation = nullptr, *_gamepad = nullptr;

  std::vector<GVertex *> _vertices;
  std::vector<GEdge *> _edges;
  std::vector<GFace *> _faces;
  std::vector<GRegion *> _regions;
  std::vector<MElement *> _elements;
  std::vector<SPoint2> _points;
  std::vector<PView *> _views;

  void _clearSelected()
  {
    _vertices.clear();
    _edges.clear();
    _faces.clear();
    _regions.clear();
    _elements.clear();
    _points.clear();
    _views.clear();
  }

  // what the scene leaves set is put back as Qt expects it: Qt composes the
  // widget's framebuffer in this context
  void _putBack()
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

  class pane : public QOpenGLWidget {
  public:
    sceneView *view;
    // a graphic window of its own, not tiled in the main one
    QWidget *window = nullptr;
    paneInput input;
    double lastX = 0., lastY = 0., lastPress = 0.;
    bool moved = false;
    bool ready = false;

    pane(pane *from) : view(new sceneView())
    {
      if(from)
        view->getDrawContext()->copyViewAttributes(from->view->getDrawContext());
      setFocusPolicy(Qt::StrongFocus);
      setMouseTracking(true);
      setMinimumSize(100, 100);
      setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    ~pane() override { delete view; }

    double factor() const { return devicePixelRatioF(); }

    // the context current, the widget's framebuffer bound and made the
    // window's; false before it has one
    bool prepare()
    {
      if(!ready) return false;
      makeCurrent();
      glShader::setWindowFramebuffer(defaultFramebufferObject());
      return true;
    }

    void place()
    {
      view->setRect(0, 0, width(), height());
      view->setOrigin(0., 0., height(), factor());
    }

    void drawNow()
    {
      int w = width(), h = height();
      if(w < 1 || h < 1) return;
      double f = factor();
      if(_captureW > 0 && _captureH > 0) {
        // in the bottom-left corner, where PixelBuffer::fill() reads, the
        // rest cleared
        int lw = (int)(_captureW / f + 0.5), lh = (int)(_captureH / f + 0.5);
        glDisable(GL_SCISSOR_TEST);
        glViewport(0, 0, (int)(w * f + .5), (int)(h * f + .5));
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        view->setRect(0, h - lh, lw, lh);
        view->setOrigin(0., 0., h, f);
        view->draw(f, h);
        place();
      }
      else {
        place();
        view->draw(f, h);
      }
      glShader::release();
      _putBack();
    }

    void initializeGL() override
    {
      ready = true;
      // what is kept per context is this one's before anything is built in it
      glShader::setContext(context());
      glShader::setWindowFramebuffer(defaultFramebufferObject());
      view->contextChanged();
    }

    void paintGL() override
    {
      glShader::setWindowFramebuffer(defaultFramebufferObject());
      _drawing = true;
      drawNow();
      _drawing = false;
    }

    void handle()
    {
      if(!prepare()) return;
      place();
      view->handleMouse(input);
      for(int b = 0; b < 3; b++) input.clicked[b] = input.released[b] = false;
      input.doubleClicked = false;
      input.wheel = 0.;
      input.dx = input.dy = 0.;
      doneCurrent();
      update();
    }

    void modifiers(Qt::KeyboardModifiers m)
    {
      input.shift = (m & Qt::ShiftModifier) != 0;
      input.ctrl = (m & Qt::ControlModifier) != 0;
      input.alt = (m & Qt::AltModifier) != 0;
      input.super = (m & Qt::MetaModifier) != 0;
    }

    void at(QPointF p)
    {
      input.dx = moved ? p.x() - lastX : 0.;
      input.dy = moved ? p.y() - lastY : 0.;
      lastX = input.x = p.x();
      lastY = input.y = p.y();
      moved = true;
    }

    static int button(Qt::MouseButton b)
    {
      return b == Qt::LeftButton ? 0 : b == Qt::RightButton ? 1 :
             b == Qt::MiddleButton ? 2 : -1;
    }

    void mouseMoveEvent(QMouseEvent *e) override
    {
      modifiers(e->modifiers());
      at(e->position());
      handle();
    }

    void mousePressEvent(QMouseEvent *e) override
    {
      int b = button(e->button());
      if(b < 0) return;
      _current = this;
      setFocus();
      modifiers(e->modifiers());
      at(e->position());
      input.clicked[b] = input.dragging[b] = true;
      double now = TimeOfDay();
      input.doubleClicked =
        b == 0 && now - lastPress < QApplication::doubleClickInterval() / 1000.;
      if(b == 0) lastPress = input.doubleClicked ? 0. : now;
      handle();
    }

    void mouseReleaseEvent(QMouseEvent *e) override
    {
      int b = button(e->button());
      if(b < 0) return;
      modifiers(e->modifiers());
      at(e->position());
      input.released[b] = true;
      input.dragging[b] = false;
      handle();
    }

    // a double click is two presses: the scene counts them itself
    void mouseDoubleClickEvent(QMouseEvent *e) override { mousePressEvent(e); }

    void wheelEvent(QWheelEvent *e) override
    {
      modifiers(e->modifiers());
      double dy = e->angleDelta().y() / 120.;
      if(dy == 0.) return;
      input.wheel = dy;
      handle();
      e->accept();
    }

    void enterEvent(QEnterEvent *) override { _current = this; }

    void leaveEvent(QEvent *) override
    {
      moved = false;
      view->pointerLeft();
      update();
    }

    // Alt and the arrows step through what is stacked under the pointer; the
    // other keys go on to the window
    void keyPressEvent(QKeyEvent *e) override
    {
      if((e->modifiers() & Qt::AltModifier) &&
         (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down) &&
         CTX::instance()->mouseSelection && !view->lasso() && !view->addPointMode) {
        if(prepare()) view->stepPick(e->key() == Qt::Key_Down ? 1 : -1);
        update();
        return;
      }
      e->ignore();
    }
  };

  // a window of its own: the keys the view does not take are Gmsh's, and its
  // view goes with it
  class paneWindow : public QWidget {
  public:
    pane *held = nullptr;
    void keyPressEvent(QKeyEvent *e) override
    {
      if(!qtMainKey(e->key(), e->modifiers(), e->text())) QWidget::keyPressEvent(e);
    }
    void closeEvent(QCloseEvent *e) override
    {
      QWidget::closeEvent(e);
      pane *p = held;
      held = nullptr;
      if(!p) return;
      _panes.erase(std::find(_panes.begin(), _panes.end(), p));
      if(_current == p) _current = _panes.empty() ? nullptr : _panes[0];
      deleteLater();
    }
  };

  pane *_paneOf(sceneView *view)
  {
    for(pane *p : _panes)
      if(p->view == view) return p;
    return nullptr;
  }

  pane *_newPane(pane *from)
  {
    pane *p = new pane(from);
    _panes.push_back(p);
    return p;
  }

  void _redrawAll()
  {
    for(pane *p : _panes) p->update();
  }

  void _setHost()
  {
    Scene::Host held;
    held.redraw = []() { _redrawAll(); };
    held.redrawView = [](sceneView *view) {
      if(pane *p = _paneOf(view)) p->update();
    };
    held.check = [](bool rateLimited) { Gui::instance().check(rateLimited); };
    held.wait = [](double seconds, bool force) {
      if(seconds < 0.)
        Gui::instance().wait(force);
      else
        Gui::instance().wait(seconds, force);
    };
    held.drawCurrent = []() {
      if(_current && _current->prepare()) {
        _current->drawNow();
        glFlush();
      }
    };
    held.uiScale = []() { return _current ? (float)_current->factor() : 1.f; };
    held.numViews = []() { return (int)_panes.size(); };
    held.cursor = [](Scene::Cursor kind) {
      for(pane *p : _panes) {
        if(kind == Scene::Picking)
          p->setCursor(Qt::PointingHandCursor);
        else
          p->unsetCursor();
      }
    };
    held.current = []() -> sceneView * {
      return _current ? _current->view : nullptr;
    };
    held.setCurrent = [](sceneView *view) {
      if(pane *p = _paneOf(view)) _current = p;
    };
    held.later = [](double seconds, std::function<void()> what) {
      QTimer::singleShot((int)std::max(0., seconds * 1000.), [what]() {
        if(what) what();
      });
    };
    held.buttonDown = []() { return qtButtonDown(); };
    held.context = []() -> void * { return QOpenGLContext::currentContext(); };
    held.makeCurrent = [](sceneView *view) {
      if(pane *p = _paneOf(view)) p->prepare();
    };
    held.screen = [](int &height, float &scale) {
      QScreen *s = qtMainWindow() ? qtMainWindow()->screen() :
                                    QGuiApplication::primaryScreen();
      height = 0;
      scale = 1.f;
      if(!s) return;
      scale = (float)s->devicePixelRatio();
      height = (int)(s->geometry().height() * scale);
    };
    Scene::setHost(held);
  }

} // namespace

QWidget *qtSceneWidget()
{
  if(_root) return _root;
  _setHost();
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = new QWidget;
  QVBoxLayout *v = new QVBoxLayout(_root);
  v->setContentsMargins(0, 0, 0, 0);
  _current = _newPane(nullptr);
  v->addWidget(_current);
  return _root;
}

void qtSceneRedraw() { _redrawAll(); }

bool qtSceneDrawing() { return _drawing; }

void qtSceneSize(int &width, int &height)
{
  width = _root ? _root->width() : 0;
  height = _root ? _root->height() : 0;
}

void qtSceneSplit(char how, double ratio)
{
  if(!_current) return;
  if(how == 'u') {
    pane *keep = (_current && !_current->window) ? _current : nullptr;
    for(pane *p : _panes)
      if(!keep && !p->window) keep = p;
    if(!keep) return;
    std::vector<pane *> gone;
    for(pane *p : _panes)
      if(p != keep && !p->window) gone.push_back(p);
    for(pane *p : gone) _panes.erase(std::find(_panes.begin(), _panes.end(), p));
    QLayout *layout = _root->layout();
    keep->setParent(nullptr);
    while(QLayoutItem *it = layout->takeAt(0)) {
      if(it->widget()) it->widget()->deleteLater();
      delete it;
    }
    // the other views, in the splitters just taken away, go with them
    for(pane *p : gone) p->deleteLater();
    layout->addWidget(keep);
    keep->show();
    _current = keep;
    _redrawAll();
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
  pane *was = _current;
  pane *fresh = _newPane(was);
  QSplitter *split =
    new QSplitter(how == 'h' ? Qt::Horizontal : Qt::Vertical);
  QWidget *parent = was->parentWidget();
  if(QSplitter *up = dynamic_cast<QSplitter *>(parent)) {
    int at = up->indexOf(was);
    up->replaceWidget(at, split);
  }
  else {
    QLayout *layout = _root->layout();
    layout->replaceWidget(was, split);
  }
  split->addWidget(was);
  split->addWidget(fresh);
  if(ratio <= 0. || ratio >= 1.) ratio = .5;
  int size = how == 'h' ? split->width() : split->height();
  if(size < 2) size = 1000;
  split->setSizes({(int)(size * ratio), (int)(size * (1. - ratio))});
  _current = fresh;
  _redrawAll();
}

void qtSceneNewWindow()
{
  pane *fresh = _newPane(_current);
  paneWindow *w = new paneWindow;
  w->held = fresh;
  fresh->window = w;
  w->setWindowTitle(QString("Gmsh - Graphic window %1").arg(_panes.size()));
  QVBoxLayout *v = new QVBoxLayout(w);
  v->setContentsMargins(0, 0, 0, 0);
  v->addWidget(fresh);
  w->resize(600, 500);
  _current = fresh;
  w->show();
}

void qtSceneDestroy()
{
  delete _animation;
  delete _gamepad;
  _animation = _gamepad = nullptr;
  for(pane *p : _panes)
    if(p->window) {
      paneWindow *w = (paneWindow *)p->window;
      w->held = nullptr;
      delete w;
    }
  _panes.clear();
  _current = nullptr;
  // the tiled views are in the main window, which goes with them
  _root = nullptr;
}

void qtSceneStartTimers()
{
  if(!_animation) {
    _animation = new QTimer;
    QObject::connect(_animation, &QTimer::timeout, []() {
      if(_animating)
        animationTick();
      else
        _animation->stop();
    });
  }
  if(_animating && !_animation->isActive()) _animation->start(10);
  if(!_gamepad) {
    _gamepad = new QTimer;
    _gamepad->setSingleShot(true);
    QObject::connect(_gamepad, &QTimer::timeout, []() {
      if(_current && Scene::gamepadTurn(_current->view)) _current->update();
      qtSceneStartTimers();
    });
  }
  if(!_gamepad->isActive()) {
    double period = Scene::gamepadPeriod();
    // the option may be switched on: looked at again now and then
    _gamepad->start(period > 0. ? (int)(period * 1000.) : 3000);
  }
}

namespace QtScene {

  void pumpScene(bool rateLimited) {}
  void sceneShownElsewhere() {}
  std::string scenePicture(int &width, int &height, bool always) { return ""; }
  bool sceneMoved() { return false; }
  void sceneResize(int width, int height) {}
  void scenePointer(double x, double y, int button, int what, double wheel,
                    bool shift, bool ctrl, bool alt)
  {
  }

  bool sceneKey(char key)
  {
    bool taken = false;
    for(pane *p : _panes)
      if(p->view->key(key)) {
        taken = true;
        p->update();
      }
    return taken;
  }

  void sceneMessage(const std::string &first, const std::string &second)
  {
    if(!_current) return;
    _current->view->screenMessage[0] = first;
    _current->view->screenMessage[1] = second;
    _current->update();
  }

  drawContext *getCurrentDrawContext()
  {
    return _current ? _current->view->getDrawContext() : nullptr;
  }

  void getCurrentPixelSize(int &width, int &height)
  {
    width = height = 0;
    if(!_current) return;
    double f = _current->factor();
    width = (int)(_current->width() * f + 0.5);
    height = (int)(_current->height() * f + 0.5);
  }

  void setCurrentOpenglWindow(int which)
  {
    if(which >= 0 && which < (int)_panes.size()) _current = _panes[which];
  }

  void showAllInEveryWindow()
  {
    for(pane *p : _panes)
      if(drawContext *ctx = p->view->getDrawContext()) ctx->showAll();
    _redrawAll();
  }

  void splitCurrentOpenglWindow(char how, double ratio)
  {
    qtSceneSplit(how, ratio);
  }

  void copyCurrentOpenglWindowToClipboard()
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(w < 1 || h < 1 || !_current || !_current->prepare()) return;
    _current->drawNow();
    QImage image(w, h, QImage::Format_RGBA8888);
    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadPixels(0, 0, w, h, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    _current->doneCurrent();
    QApplication::clipboard()->setImage(
      image.flipped(Qt::Vertical).convertToFormat(QImage::Format_RGB32));
    _current->update();
  }

  void beginGraphicCapture(int &width, int &height, bool composite)
  {
    int w = 0, h = 0;
    getCurrentPixelSize(w, h);
    if(width > w || height > h) {
      Msg::Warning("The Qt interface cannot render a picture larger than the "
                   "graphic window (%d x %d): clamping", w, h);
      width = std::min(width, w);
      height = std::min(height, h);
    }
    if(width < 1) width = 1;
    if(height < 1) height = 1;
    _captureW = width;
    _captureH = height;
  }

  void endGraphicCapture()
  {
    _captureW = _captureH = 0;
    _redrawAll();
  }

  PixelBuffer *createCompositePixelBuffer(unsigned int format,
                                          unsigned int type)
  {
    int width = 0, height = 0;
    getCurrentPixelSize(width, height);
    if(width < 1 || height < 1) return nullptr;
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
    beginGraphicCapture(width, height, c->print.compositeWindows ? true : false);
    PixelBuffer *buffer =
      new PixelBuffer(width, height, (GLenum)format, (GLenum)type);
    buffer->fill();
    endGraphicCapture();
    return buffer;
  }

  void orientViews(const std::string &what, bool reverse, bool sync)
  {
    std::vector<sceneView *> views;
    for(pane *p : _panes)
      if(!p->window) views.push_back(p->view);
    if(views.empty() && _current) views.push_back(_current->view);
    Scene::orientViews(views, what, reverse, sync);
    _redrawAll();
  }

  void setMouseSelection(bool on) {}

  void toggleAnimation()
  {
    _animating = !_animating;
    qtSceneStartTimers();
  }

  bool animating() { return _animating; }

  void abortSelection()
  {
    if(!_current) return;
    _current->view->quitSelection = 1;
    _current->view->selectionMode = false;
  }

  void setAddPointMode(bool on)
  {
    for(pane *p : _panes) p->view->addPointMode = on;
  }

  void sceneSettingChanged(const std::string &what)
  {
    if(what == "background_image")
      for(pane *p : _panes)
        if(p->view->getDrawContext())
          p->view->getDrawContext()->invalidateBgImageTexture();
    _redrawAll();
  }

  char selectEntity(int type)
  {
    _clearSelected();
    if(!_current) return 'q';
    return _current->view->selectEntity(type, _vertices, _edges, _faces,
                                        _regions, _elements, _points, _views);
  }

  bool pickAt(int type, bool mesh, bool post, int x, int y, int w, int h)
  {
    _clearSelected();
    if(!_current || !_current->prepare()) return false;
    _current->place();
    return _current->view->pick(type, mesh, post, x, y, w, h, _vertices,
                                _edges, _faces, _regions, _elements, _points,
                                _views);
  }

  bool printView(int width, int height, int supersampling, unsigned int format,
                 unsigned int type, void *pixels)
  {
    if(!_current || !_current->prepare()) return false;
    bool ok = _current->view->printTo(width, height, supersampling, format,
                                      type, pixels);
    _current->update();
    return ok;
  }

  const std::vector<GVertex *> &selectedVertices() { return _vertices; }
  const std::vector<GEdge *> &selectedEdges() { return _edges; }
  const std::vector<GFace *> &selectedFaces() { return _faces; }
  const std::vector<GRegion *> &selectedRegions() { return _regions; }
  const std::vector<MElement *> &selectedElements() { return _elements; }
  const std::vector<SPoint2> &selectedPoints() { return _points; }
  const std::vector<PView *> &selectedViews() { return _views; }

  // filled from the list in GuiSceneOps.h
  namespace {
    struct offering {
      offering()
      {
        GuiSceneOps ops;
#define GUI_SCENE_TAKE(name, args, call) ops.name = name;
        GUI_SCENE_VOID(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(ret, name, args, call, none) ops.name = name;
        GUI_SCENE_VALUE(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
#define GUI_SCENE_TAKE(type, name) ops.name = name;
        GUI_SCENE_LIST(GUI_SCENE_TAKE)
#undef GUI_SCENE_TAKE
        Gui::offerScene("qt", ops);
      }
    };
    offering _offering;
  } // namespace

} // namespace QtScene

void qtSceneCopy() { QtScene::copyCurrentOpenglWindowToClipboard(); }
