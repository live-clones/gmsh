// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the scene of the Qt interface, see GuiPanes.h: each view in a QOpenGLWidget
// of its own, the views of the main window split with QSplitter, a new
// graphic window a top-level widget holding one more

#include "GmshConfig.h"

#include <algorithm>
#include <string>
#include <vector>

#include "qtCommon.h"

#include "Gui.h"
#include "GuiPanes.h"
#include "drawContextGL.h"
#include "glShader.h"
#include "Context.h"

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

  QWidget *_root = nullptr;

  GuiPanes &_all() { return GuiPanes::instance(); }

  class pane : public QOpenGLWidget, public GuiPanes::Pane {
  public:
    // the top-level widget of a graphic window of its own
    QWidget *top = nullptr;
    bool ready = false;

    pane()
    {
      setFocusPolicy(Qt::StrongFocus);
      setMouseTracking(true);
      setMinimumSize(100, 100);
      setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    // the context current, the widget's framebuffer bound and made the
    // window's; false before it has one
    bool prepare()
    {
      if(!ready) return false;
      makeCurrent();
      glShader::setWindowFramebuffer(defaultFramebufferObject());
      return true;
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
      _all().draw(this);
    }

    void modifiersOf(Qt::KeyboardModifiers m)
    {
      modifiers((m & Qt::ShiftModifier) != 0, (m & Qt::ControlModifier) != 0,
                (m & Qt::AltModifier) != 0, (m & Qt::MetaModifier) != 0);
    }

    static int button(Qt::MouseButton b)
    {
      return b == Qt::LeftButton ? 0 : b == Qt::RightButton ? 1 :
             b == Qt::MiddleButton ? 2 : -1;
    }

    void mouseMoveEvent(QMouseEvent *e) override
    {
      modifiersOf(e->modifiers());
      moved(e->position().x(), e->position().y());
    }

    void mousePressEvent(QMouseEvent *e) override
    {
      setFocus();
      modifiersOf(e->modifiers());
      pressed(button(e->button()), e->position().x(), e->position().y(),
              QApplication::doubleClickInterval() / 1000.);
    }

    void mouseReleaseEvent(QMouseEvent *e) override
    {
      modifiersOf(e->modifiers());
      released(button(e->button()), e->position().x(), e->position().y());
    }

    // a double click is two presses: the scene counts them itself
    void mouseDoubleClickEvent(QMouseEvent *e) override { mousePressEvent(e); }

    void wheelEvent(QWheelEvent *e) override
    {
      modifiersOf(e->modifiers());
      wheel(e->angleDelta().y() / 120., e->position().x(), e->position().y());
      e->accept();
    }

    void enterEvent(QEnterEvent *) override { _all().setCurrent(this); }

    void leaveEvent(QEvent *) override { left(); }

    // Alt and the arrows step through what is stacked under the pointer; the
    // other keys go on to the window
    void keyPressEvent(QKeyEvent *e) override
    {
      if((e->modifiers() & Qt::AltModifier) &&
         (e->key() == Qt::Key_Up || e->key() == Qt::Key_Down) &&
         CTX::instance()->mouseSelection && !view->lasso() && !view->addPointMode) {
        if(prepare()) view->stepPick(e->key() == Qt::Key_Down ? 1 : -1);
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
      _all().dropped(p);
      deleteLater();
    }
  };

  pane *_pane(GuiPanes::Pane *p) { return static_cast<pane *>(p); }

  GuiPanes::Toolkit _toolkit()
  {
    GuiPanes::Toolkit t;
    t.makePane = [](GuiPanes::Pane *) -> GuiPanes::Pane * { return new pane; };
    t.redraw = [](GuiPanes::Pane *p) { _pane(p)->update(); };
    t.prepare = [](GuiPanes::Pane *p) { return _pane(p)->prepare(); };
    t.size = [](GuiPanes::Pane *p, int &w, int &h, double &f) {
      w = _pane(p)->width();
      h = _pane(p)->height();
      f = _pane(p)->devicePixelRatioF();
    };
    t.drawNow = [](GuiPanes::Pane *p) {
      if(!_pane(p)->prepare()) return;
      _all().draw(p);
      glFlush();
    };
    t.split = [](GuiPanes::Pane *was, GuiPanes::Pane *fresh, char how,
                 double ratio) {
      QSplitter *split =
        new QSplitter(how == 'h' ? Qt::Horizontal : Qt::Vertical);
      QWidget *parent = _pane(was)->parentWidget();
      if(QSplitter *up = dynamic_cast<QSplitter *>(parent))
        up->replaceWidget(up->indexOf(_pane(was)), split);
      else
        _root->layout()->replaceWidget(_pane(was), split);
      split->addWidget(_pane(was));
      split->addWidget(_pane(fresh));
      int size = how == 'h' ? split->width() : split->height();
      if(size < 2) size = 1000;
      split->setSizes({(int)(size * ratio), (int)(size * (1. - ratio))});
    };
    t.unsplit = [](GuiPanes::Pane *keep,
                   const std::vector<GuiPanes::Pane *> &gone) {
      QLayout *layout = _root->layout();
      _pane(keep)->setParent(nullptr);
      while(QLayoutItem *it = layout->takeAt(0)) {
        if(it->widget()) it->widget()->deleteLater();
        delete it;
      }
      // the other views, in the splitters just taken away, go with them
      for(GuiPanes::Pane *p : gone) _pane(p)->deleteLater();
      layout->addWidget(_pane(keep));
      _pane(keep)->show();
    };
    t.newWindow = [](GuiPanes::Pane *fresh) {
      paneWindow *w = new paneWindow;
      w->held = _pane(fresh);
      _pane(fresh)->top = w;
      w->setWindowTitle(
        QString("Gmsh - Graphic window %1").arg(_all().panes().size()));
      QVBoxLayout *v = new QVBoxLayout(w);
      v->setContentsMargins(0, 0, 0, 0);
      v->addWidget(_pane(fresh));
      w->resize(600, 500);
      w->show();
    };
    t.cursor = [](bool picking) {
      for(GuiPanes::Pane *p : _all().panes()) {
        if(picking)
          _pane(p)->setCursor(Qt::PointingHandCursor);
        else
          _pane(p)->unsetCursor();
      }
    };
    t.clipboard = [](int w, int h, const std::vector<unsigned char> &rgba) {
      QImage image(rgba.data(), w, h, 4 * w, QImage::Format_RGBA8888);
      QApplication::clipboard()->setImage(
        image.flipped(Qt::Vertical).convertToFormat(QImage::Format_RGB32));
    };
    t.later = [](double seconds, std::function<void()> what) {
      QTimer::singleShot((int)std::max(0., seconds * 1000.), [what]() {
        if(what) what();
      });
    };
    t.buttonDown = []() { return qtButtonDown(); };
    t.context = []() -> void * { return QOpenGLContext::currentContext(); };
    t.screen = [](int &height, float &scale) {
      QScreen *s = qtMainWindow() ? qtMainWindow()->screen() :
                                    QGuiApplication::primaryScreen();
      height = 0;
      scale = 1.f;
      if(!s) return;
      scale = (float)s->devicePixelRatio();
      height = (int)(s->geometry().height() * scale);
    };
    return t;
  }

  struct offering {
    offering() { GuiPanes::offer("qt"); }
  };
  offering _offering;

} // namespace

QWidget *qtSceneWidget()
{
  if(_root) return _root;
  if(!dynamic_cast<drawContextGL *>(drawContext::global()))
    drawContext::setGlobal(new drawContextGL);
  _root = new QWidget;
  QVBoxLayout *v = new QVBoxLayout(_root);
  v->setContentsMargins(0, 0, 0, 0);
  v->addWidget(_pane(_all().start(_toolkit())));
  return _root;
}

void qtSceneRedraw() { _all().redrawAll(); }

bool qtSceneDrawing() { return _all().drawing(); }

void qtSceneSize(int &width, int &height)
{
  width = _root ? _root->width() : 0;
  height = _root ? _root->height() : 0;
}

void qtSceneSplit(char how, double ratio) { _all().split(how, ratio); }

void qtSceneNewWindow() { _all().newWindow(); }

void qtSceneDestroy()
{
  for(GuiPanes::Pane *p : _all().panes())
    if(_pane(p)->top) {
      paneWindow *w = (paneWindow *)_pane(p)->top;
      w->held = nullptr;
      delete w;
    }
  _all().stop();
  // the tiled views are in the main window, which goes with them
  _root = nullptr;
}

void qtSceneStartTimers() { _all().startTimers(); }

void qtSceneCopy() { Gui::instance().copyCurrentOpenglWindowToClipboard(); }
