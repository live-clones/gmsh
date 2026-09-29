// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <FL/Fl.H>

#include "sceneViewFltk.h"
#include "FlGui.h"
#include "drawContext.h"
#include "glShader.h"
#include "Context.h"
#include "GmshMessage.h"

sceneViewFltk::sceneViewFltk(int x, int y, int w, int h)
  : Fl_Gl_Window(x, y, w, h, "gl"), _drawing(false),
    _cursorKind(Scene::Ordinary)
{
}

sceneViewFltk::~sceneViewFltk() { GuiPanes::instance().dropped(this); }

drawContext *sceneViewFltk::getDrawContext() { return view->getDrawContext(); }

int sceneViewFltk::pixel_w() { return Fl_Gl_Window::pixel_w(); }
int sceneViewFltk::pixel_h() { return Fl_Gl_Window::pixel_h(); }

double sceneViewFltk::pixelFactor()
{
  return w() ? (double)pixel_w() / (double)w() : 1.;
}

void sceneViewFltk::setCursor(Scene::Cursor kind)
{
  if(kind == _cursorKind) return;
  _cursorKind = kind;
  // the hand says "this can be clicked"
  Fl_Gl_Window::cursor(kind == Scene::Picking ? FL_CURSOR_HAND :
                                                FL_CURSOR_DEFAULT);
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
  view->redrawAsked();
  Fl_Gl_Window::redraw();
}

bool sceneViewFltk::prepare()
{
  if(!shown()) return false;
  make_current();
  glShader::setWindowFramebuffer(0);
  return true;
}

void sceneViewFltk::draw()
{
  // making an STL triangulation or a display list can pump the loop; the same
  // guard keeps GL_RENDER and GL_SELECT apart
  if(_drawing) return;
  _drawing = true;

  Msg::Debug("sceneViewFltk::draw()");
  if(!context_valid()) view->contextChanged();
  GuiPanes::instance().draw(this);

  _drawing = false;
}

void sceneViewFltk::_modifiers()
{
  modifiers(Fl::event_state(FL_SHIFT) ? true : false,
            Fl::event_state(FL_CTRL) ? true : false,
            Fl::event_state(FL_ALT) ? true : false,
            Fl::event_state(FL_META) ? true : false);
}

int sceneViewFltk::handle(int event)
{
  // the scene numbers 0 left, 1 right, 2 middle; FLTK 1 left, 2 middle, 3 right
  auto which = [](int button) {
    return button == 1 ? 0 : (button == 3 ? 1 : 2);
  };

  switch(event) {
  case FL_FOCUS: // accept the focus when asked whether it is wanted
  case FL_UNFOCUS: return 1;

  case FL_SHORTCUT:
  case FL_KEYBOARD:
    // as Alt and the wheel do: a trackpad has no notches
    if(Fl::event_state(FL_ALT) && CTX::instance()->mouseSelection &&
       !view->lasso() && !view->addPointMode &&
       (Fl::event_key() == FL_Up || Fl::event_key() == FL_Down)) {
      view->stepPick((Fl::event_key() == FL_Down) ? 1 : -1);
      return 1;
    }
    // before the widget navigation FLTK would do with the arrows
    if(FlGui::instance()->runKeys()) return 1;
    return Fl_Gl_Window::handle(event);

  case FL_LEAVE:
    left();
    return Fl_Gl_Window::handle(event);

  case FL_PUSH:
    take_focus(); // the keyboard follows the click
    _modifiers();
    pressed(which(Fl::event_button()), Fl::event_x(), Fl::event_y(), 0.3);
    return 1;

  case FL_RELEASE:
    _modifiers();
    released(which(Fl::event_button()), Fl::event_x(), Fl::event_y());
    return 1;

  case FL_DRAG:
  case FL_MOVE:
    _modifiers();
    moved(Fl::event_x(), Fl::event_y());
    return 1;

  case FL_MOUSEWHEEL:
    _modifiers();
    wheel(-Fl::event_dy(), Fl::event_x(), Fl::event_y());
    return 1;

  default: break;
  }
  return Fl_Gl_Window::handle(event);
}
