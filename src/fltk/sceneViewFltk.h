// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_VIEW_FLTK_H
#define SCENE_VIEW_FLTK_H

#include "GmshConfig.h"

#if defined(HAVE_FLTK) && defined(HAVE_GL_SCENE)

#include <string>

#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Menu_Window.H>
#include <FL/Fl_Tooltip.H>
#include <FL/fl_draw.H>

#include "sceneHost.h"
#include "sceneView.h"

class drawContext;

// A 3D view of the model, held by FLTK: an Fl_Gl_Window that owns one
// sceneView of src/scene and does nothing to it but hold it.
//
// Which is the point. There used to be two scenes -- this one, written by
// hand as openglWindow, and the one in src/scene written for the Dear ImGui
// interface from it -- and two scenes mean the newer is exercised by whoever
// uses the newer interface and by nobody else. What draws the model, what
// picks in it, what the lasso does, what a double click runs, what the wheel
// zooms: all of it is said once now, and the interface that gets used every
// day is what proves it.
//
// So what is left here is what a window is for and a scene is not: the OpenGL
// context, the translation of FLTK events into the paneInput one turn of a
// scene expects, the guard against drawing while already drawing, the shape
// of the pointer, and the little window a tooltip is drawn in.

// The tooltip, which FLTK has no widget for over a GL window: a borderless
// window that follows the pointer. It came from openglWindow.h unchanged.
class tooltipWindow : public Fl_Menu_Window {
private:
  char _text[1024];

public:
  tooltipWindow() : Fl_Menu_Window(1, 1)
  {
    strcpy(_text, "");
    set_override();
    set_tooltip_window();
    end();
  }
  void draw()
  {
    draw_box(FL_BORDER_BOX, 0, 0, w(), h(), Fl_Tooltip::color());
    fl_color(Fl_Tooltip::textcolor());
    fl_font(Fl_Tooltip::font(), Fl_Tooltip::size());
    int X = Fl_Tooltip::margin_width();
    int Y = Fl_Tooltip::margin_height();
    int W = w() - (Fl_Tooltip::margin_width() * 2);
    int H = h() - (Fl_Tooltip::margin_height() * 2);
    fl_draw(_text, X, Y, W, H, Fl_Align(FL_ALIGN_LEFT | FL_ALIGN_WRAP), 0, 1);
  }
  int handle(int e)
  {
    if(e == FL_PUSH || e == FL_KEYDOWN) {
      hide();
      return 1;
    }
    return Fl_Menu_Window::handle(e);
  }
  void value(const std::string &s)
  {
    strncpy(_text, s.c_str(), 1023);
    _text[1023] = '\0';
    fl_font(Fl_Tooltip::font(), Fl_Tooltip::size());
    int ww = Fl_Tooltip::wrap_width();
    int hh = 0;
    fl_measure(_text, ww, hh, 1);
    ww += (Fl_Tooltip::margin_width() * 2);
    hh += (Fl_Tooltip::margin_height() * 2);
    size(ww, hh);
    redraw();
  }
};

class sceneViewFltk : public Fl_Gl_Window {
public:
  sceneViewFltk(int x, int y, int w, int h);
  ~sceneViewFltk();

  // the scene itself, which is what everything else asks of it
  sceneView *scene() { return _view; }
  drawContext *getDrawContext();

  // In device pixels rather than in the logical ones w() and h() are in: on a
  // display that scales, a framebuffer pixel is not a widget pixel, and
  // OpenGL is told about the first kind.
  int pixel_w();
  int pixel_h();
  // what one logical pixel is worth in device pixels
  double pixelFactor();

  // say something next to the pointer, over the view
  void drawTooltip(const std::string &text);
  // and what the pointer looks like while it is over something clickable.
  // Not cursor(): Fl_Window has three of those, and an overload here would
  // hide them from whoever sets a cursor the FLTK way.
  void setCursor(Scene::Cursor kind);

  void show();
  bool everDrawn() const { return _drawn; }

  // The view the pointer was last in, which is what the rest of Gmsh means by
  // "the current one": a click on a view is what changes it.
  static sceneViewFltk *lastHandled() { return _lastHandled; }
  static void setLastHandled(sceneViewFltk *v) { _lastHandled = v; }
  // and the one holding a given scene, for the calls that arrive with a
  // sceneView and no window
  static sceneViewFltk *holding(sceneView *view);

protected:
  void draw();
  int handle(int event);

private:
  static sceneViewFltk *_lastHandled;
  sceneView *_view;
  // Some drawing routines make data as they go -- an STL triangulation, a
  // display list -- and what they make can pump the loop, which would draw
  // again inside a draw. It is the window's guard and not the scene's: the
  // interface that draws afresh at every frame has its own.
  bool _drawing;
  // whether it has ever drawn: the gamepad has nothing to move around before
  // the first picture
  bool _drawn;
  // where the pointer was at the previous event, for the movement one turn of
  // a scene is given
  double _lastX, _lastY;
  bool _everMoved;
  tooltipWindow *_tooltip;
  Scene::Cursor _cursorKind;
  // what the scene is to be told of this event
  paneInput _input(int event) const;
  // the rectangle and the scale, which change with the window
  void _place();
};

#endif

#endif
