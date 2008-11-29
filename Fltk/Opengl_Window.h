// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>
#include "drawContext.h"

class MousePosition {
 public:
  double win[3]; // window coordinates
  double wnr[3]; // world coordinates BEFORE rotation
  double s[3]; // scaling state when the event was recorded
  double t[3]; // translation state when the event was recorded
  MousePosition()
  {
    for(int i = 0; i < 3; i++)
      win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  MousePosition(const MousePosition &instance)
  {
    for(int i = 0; i < 3; i++){
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set(drawContext *ctx);
  void recenter(drawContext *ctx);
};

class Opengl_Window : public Fl_Gl_Window {
 private:
  MousePosition _click, _curr, _prev, _lasso;
  double _point[3];
  drawContext *_ctx;
  void draw();
  int handle(int);
 public:
  bool AddPointMode, LassoMode, SelectionMode;
  Opengl_Window(int x, int y, int w, int h, const char *l=0);
  ~Opengl_Window();
  drawContext *getDrawContext(){ return _ctx; }
};

// This dummy box class permits to define a box widget that will not
// eat the FL_ENTER/FL_LEAVE events (the new Box widget in fltk >1.1
// does that, so that our Opengl_Window->handle() was not called each
// time the mouse moved)
class Dummy_Box : public Fl_Box {
 private:
  int handle(int){ return 0; } // always!
 public:
  Dummy_Box(int x,int y,int w,int h,const char *l=0) : Fl_Box(x, y, w, h, l) {}
};

#endif
