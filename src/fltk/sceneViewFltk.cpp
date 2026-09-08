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
#include "GmshMessage.h"

sceneViewFltk *sceneViewFltk::_lastHandled = nullptr;

namespace {

  // Every view there is, so that a call arriving with a sceneView and no
  // window can find the one holding it.
  std::vector<sceneViewFltk *> &_all()
  {
    static std::vector<sceneViewFltk *> all;
    return all;
  }

  // The gamepad, asked on a timer rather than as an event: there is none to
  // wait for. The scene says how often, and does the rest; what is the
  // window's is that only the view the pointer was last in moves, as it
  // always has.
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
  _tooltip = new tooltipWindow();
  _tooltip->hide();
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

void sceneViewFltk::drawTooltip(const std::string &text)
{
  if(text.empty()) {
    _tooltip->hide();
    return;
  }
  _tooltip->position(Fl::event_x_root(), Fl::event_y_root() + 20);
  _tooltip->value(text);
  _tooltip->show();
}

void sceneViewFltk::setCursor(Scene::Cursor kind)
{
  if(kind == _cursorKind) return;
  _cursorKind = kind;
  // there is no crosshair among the cursors every toolkit has; the hand is
  // what says "this can be clicked"
  Fl_Gl_Window::cursor(kind == Scene::Picking ? FL_CURSOR_HAND :
                                                FL_CURSOR_DEFAULT);
}

// The rectangle and the scale the scene draws itself in. A window holding one
// view is the whole of it, so the rectangle is the widget and the origin is
// its corner; the panes of the other interface share a window and say
// otherwise.
void sceneViewFltk::_place()
{
  _view->setRect(0, 0, w(), h());
  _view->setOrigin(0., 0., h(), pixelFactor());
}

void sceneViewFltk::draw()
{
  // Some drawing routines make data as they go -- an STL triangulation, a
  // display list -- and making it can pump the loop, which would draw again
  // inside this draw. The same guard keeps GL_RENDER and GL_SELECT passes
  // from being mixed.
  if(_drawing) return;
  _drawing = true;

  Msg::Debug("sceneViewFltk::draw()");
  if(!context_valid())
    _view->getDrawContext()->invalidateQuadricsAndDisplayLists();

  _place();
  _view->draw(pixelFactor(), h());

  _drawing = false;
}

// What one turn of the scene is told, from one FLTK event. The scene is
// written for a snapshot of the pointer -- which is what an immediate mode
// frame has -- so each event fills in the part of the snapshot it is about
// and leaves the rest alone.
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

  // The buttons are numbered as the scene numbers them, which is how Dear
  // ImGui does: 0 left, 1 right, 2 middle. FLTK numbers them 1 left, 2
  // middle, 3 right.
  auto which = [](int button) {
    return button == 1 ? 0 : (button == 3 ? 1 : 2);
  };

  switch(event) {
  case FL_PUSH:
    in.clicked[which(Fl::event_button())] = true;
    // FLTK counts the clicks of a run rather than saying which one this is
    in.doubleClicked = (Fl::event_clicks() == 1);
    break;
  case FL_RELEASE: in.released[which(Fl::event_button())] = true; break;
  case FL_DRAG:
    // during a drag it is what is held down that matters, and event_button()
    // is not it
    if(Fl::event_state(FL_BUTTON1)) in.dragging[0] = true;
    if(Fl::event_state(FL_BUTTON3)) in.dragging[1] = true;
    if(Fl::event_state(FL_BUTTON2)) in.dragging[2] = true;
    break;
  case FL_MOUSEWHEEL:
    // FLTK counts down as positive and the scene counts up, as Dear ImGui
    // reports it
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
    // the arrows of the view rather than the widget navigation FLTK would do
    if(FlGui::instance()->testArrowShortcuts()) return 1;
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
    setLastHandled(this);
    take_focus(); // the keyboard follows the click, as it always has
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
