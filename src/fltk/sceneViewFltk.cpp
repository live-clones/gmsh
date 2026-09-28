// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_FLTK) && defined(HAVE_GL_SCENE)

#include <algorithm>
#include <vector>

#include <FL/Fl.H>

#include "sceneViewFltk.h"
#include "FlGui.h"
#include "sceneGamepad.h"
#include "drawContext.h"
#include "Context.h"
#include "GmshMessage.h"

sceneViewFltk *sceneViewFltk::_lastHandled = nullptr;

namespace {

  // so that a call arriving with a sceneView can find the window holding it
  std::vector<sceneViewFltk *> &_all()
  {
    static std::vector<sceneViewFltk *> all;
    return all;
  }

  // asked on a timer: there is no event; only the view the pointer was last in
  // moves
  void _gamepad(void *data)
  {
    sceneViewFltk *view = (sceneViewFltk *)data;
    if(sceneViewFltk::lastHandled() == view ||
       sceneViewFltk::lastHandled() == nullptr) {
      if(Scene::gamepadTurn(view->scene())) view->flush();
    }
    Fl::add_timeout(Scene::gamepadPeriod(), _gamepad, data);
  }

} // namespace

sceneViewFltk::sceneViewFltk(int x, int y, int w, int h)
  : Fl_Gl_Window(x, y, w, h, "gl"), _drawing(false),
    _lastX(0.), _lastY(0.), _everMoved(false), _cursorKind(Scene::Ordinary)
{
  _view = new sceneView();
  _all().push_back(this);
  if(Scene::gamepadPeriod() > 0.) Fl::add_timeout(.5, _gamepad, (void *)this);
}

sceneViewFltk::~sceneViewFltk()
{
  Fl::remove_timeout(_gamepad, (void *)this);
  std::vector<sceneViewFltk *> &all = _all();
  all.erase(std::remove(all.begin(), all.end(), this), all.end());
  if(_lastHandled == this) _lastHandled = nullptr;
  delete _view;
}

drawContext *sceneViewFltk::getDrawContext() { return _view->getDrawContext(); }

sceneViewFltk *sceneViewFltk::holding(sceneView *view)
{
  for(auto *one : _all())
    if(one->scene() == view) return one;
  return nullptr;
}

int sceneViewFltk::pixel_w() { return Fl_Gl_Window::pixel_w(); }
int sceneViewFltk::pixel_h() { return Fl_Gl_Window::pixel_h(); }

double sceneViewFltk::pixelFactor()
{
  return w() ? (double)pixel_w() / (double)w() : 1.;
}

void sceneViewFltk::show() { Fl_Gl_Window::show(); }

void sceneViewFltk::setCursor(Scene::Cursor kind)
{
  if(kind == _cursorKind) return;
  _cursorKind = kind;
  // the hand says "this can be clicked"
  Fl_Gl_Window::cursor(kind == Scene::Picking ? FL_CURSOR_HAND :
                                                FL_CURSOR_DEFAULT);
}

// the rectangle is the widget and the origin its corner
void sceneViewFltk::_place()
{
  _view->setRect(0, 0, w(), h());
  _view->setOrigin(0., 0., h(), pixelFactor());
}

int sceneViewFltk::glMode()
{
  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  if(CTX::instance()->stereo) {
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  if(CTX::instance()->shaders) mode |= FL_OPENGL3;
  return mode;
}

void sceneViewFltk::redraw()
{
  _view->redrawAsked();
  Fl_Gl_Window::redraw();
}

void sceneViewFltk::draw()
{
  // making an STL triangulation or a display list can pump the loop; the same
  // guard keeps GL_RENDER and GL_SELECT apart
  if(_drawing) return;
  _drawing = true;

  Msg::Debug("sceneViewFltk::draw()");
  if(!context_valid()) _view->contextChanged();

  _place();
  _view->draw(pixelFactor(), h());

  _drawing = false;
}

// the scene is written for a snapshot of the pointer: each event fills in the
// part it is about
paneInput sceneViewFltk::_input(int event) const
{
  paneInput in;
  in.x = Fl::event_x();
  in.y = Fl::event_y();
  if(_everMoved) {
    in.dx = in.x - _lastX;
    in.dy = in.y - _lastY;
  }
  in.shift = Fl::event_state(FL_SHIFT) ? true : false;
  in.ctrl = Fl::event_state(FL_CTRL) ? true : false;
  in.alt = Fl::event_state(FL_ALT) ? true : false;
  in.super = Fl::event_state(FL_META) ? true : false;

  // the scene numbers 0 left, 1 right, 2 middle; FLTK 1 left, 2 middle, 3 right
  auto which = [](int button) {
    return button == 1 ? 0 : (button == 3 ? 1 : 2);
  };

  switch(event) {
  case FL_PUSH:
    in.clicked[which(Fl::event_button())] = true;
    in.doubleClicked = (Fl::event_clicks() == 1);
    break;
  case FL_RELEASE: in.released[which(Fl::event_button())] = true; break;
  case FL_DRAG:
    // during a drag what is held down matters, not event_button()
    if(Fl::event_state(FL_BUTTON1)) in.dragging[0] = true;
    if(Fl::event_state(FL_BUTTON3)) in.dragging[1] = true;
    if(Fl::event_state(FL_BUTTON2)) in.dragging[2] = true;
    break;
  case FL_MOUSEWHEEL:
    in.wheel = -Fl::event_dy();
    break;
  default: break;
  }
  return in;
}

int sceneViewFltk::handle(int event)
{
  switch(event) {
  case FL_FOCUS: // accept the focus when asked whether it is wanted
  case FL_UNFOCUS: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // as Alt and the wheel do: a trackpad has no notches
    if(Fl::event_state(FL_ALT) && CTX::instance()->mouseSelection &&
       !_view->lasso() && !_view->addPointMode &&
       (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down)) {
      _view->stepPick((Fl::event_key() == FL_Down) ? 1 : -1);
      return 1;
    }
    // before the widget navigation FLTK would do with the arrows
    if(FlGui::instance()->runKeys()) return 1;
    return Fl_Gl_Window::handle(event);

  case FL_LEAVE:
    _view->pointerLeft();
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
    setLastHandled(this);
    take_focus(); // the keyboard follows the click
    // fall through
  case FL_RELEASE:
  case FL_DRAG:
  case FL_MOVE:
  case FL_MOUSEWHEEL: {
    _place();
    paneInput in = _input(event);
    _view->handleMouse(in);
    _lastX = in.x;
    _lastY = in.y;
    _everMoved = true;
    return 1;
  }

  default: break;
  }
  return Fl_Gl_Window::handle(event);
}

#endif
