// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_VIEW_FLTK_H
#define SCENE_VIEW_FLTK_H

#include "GmshConfig.h"

#include <string>

#include <FL/Fl_Gl_Window.H>

#include "sceneHost.h"
#include "sceneView.h"
#include "GuiPanes.h"

class drawContext;

// an Fl_Gl_Window holding one view of GuiPanes: the context, the FLTK events
// handed to the view, the guard against drawing while drawing and the cursor

class sceneViewFltk : public Fl_Gl_Window, public GuiPanes::Pane {
public:
  sceneViewFltk(int x, int y, int w, int h);
  ~sceneViewFltk();

  sceneView *scene() { return view; }
  drawContext *getDrawContext();

  // a core profile for the shader pipeline cannot share a context with the
  // fixed function one
  static int glMode();
  void redraw();

  // in device pixels, not the logical ones w() and h() are in
  int pixel_w();
  int pixel_h();
  double pixelFactor();

  // not cursor(): Fl_Window has three, which an overload would hide
  void setCursor(Scene::Cursor kind);

  // made or drawn outside a draw: its context current
  bool prepare();

protected:
  void draw();
  int handle(int event);

private:
  // making an STL triangulation or a display list can pump the loop, which
  // would draw inside a draw
  bool _drawing;
  Scene::Cursor _cursorKind;
  void _modifiers();
};

#endif
