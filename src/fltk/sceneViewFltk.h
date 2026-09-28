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

#include "sceneHost.h"
#include "sceneView.h"

class drawContext;

// an Fl_Gl_Window holding one sceneView: the context, the translation of FLTK
// events into paneInput, the guard against drawing while drawing and the
// cursor

class sceneViewFltk : public Fl_Gl_Window {
  bool _again = false;

public:
  sceneViewFltk(int x, int y, int w, int h);
  ~sceneViewFltk();

  sceneView *scene() { return _view; }
  drawContext *getDrawContext();

  // a core profile for the shader pipeline cannot share a context with the
  // fixed function one
  static int glMode();
  void redraw();

  // in device pixels, not the logical ones w() and h() are in
  int pixel_w();
  int pixel_h();
  double pixelFactor();

  void setAgain(bool again) { _again = again; }
  bool again() const { return _again; }
  // not cursor(): Fl_Window has three, which an overload would hide
  void setCursor(Scene::Cursor kind);

  void show();

  // the view the pointer was last in: a click changes it
  static sceneViewFltk *lastHandled() { return _lastHandled; }
  static void setLastHandled(sceneViewFltk *v) { _lastHandled = v; }
  static sceneViewFltk *holding(sceneView *view);

protected:
  void draw();
  int handle(int event);

private:
  static sceneViewFltk *_lastHandled;
  sceneView *_view;
  // making an STL triangulation or a display list can pump the loop, which
  // would draw inside a draw
  bool _drawing;
  double _lastX, _lastY;
  bool _everMoved;
  Scene::Cursor _cursorKind;
  paneInput _input(int event) const;
  void _place();
};

#endif

#endif
