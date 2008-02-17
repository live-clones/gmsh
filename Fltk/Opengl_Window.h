#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Box.H>

class MousePosition {
 public:
  double win[3]; // window coordinates
  double wnr[3]; // world coordinates BEFORE rotation
  double s[3]; // scaling state when the event was recorded
  double t[3];  // translation state when the event was recorded
  MousePosition(){
    for(int i = 0; i < 3; i++)
      win[i] = wnr[i] = s[i] = t[i] = 0.;
  }
  MousePosition(const MousePosition &instance){
    for(int i = 0; i < 3; i++){
      win[i] = instance.win[i];
      wnr[i] = instance.wnr[i];
      s[i] = instance.s[i];
      t[i] = instance.t[i];
    }
  }
  void set();
  void recenter();
};

class Opengl_Window : public Fl_Gl_Window {
 public:
  bool AddPointMode, LassoMode, SelectionMode;
 private:
  MousePosition click, curr, prev, lasso;
  double point[3];
  void draw();
  int handle(int);
 public:
  Opengl_Window(int x,int y,int w,int h,const char *l=0)
    : Fl_Gl_Window(x, y, w, h, l) {
    AddPointMode = LassoMode = SelectionMode = false;
    point[0] = point[1] = point[2] = 0.;
  }
};

// This dummy box class permits to define a box widget that will not
// eat the FL_ENTER/FL_LEAVE events (the new Box widget in fltk >1.1
// does that, so that our Opengl_Window->handle() was not called each
// time the mouse moved...)
//
// There is probably a better solution...

class Dummy_Box : public Fl_Box {
  int handle(int){ return 0; }; // always!
public:
  Dummy_Box(int x,int y,int w,int h,const char *l=0)
    : Fl_Box(x, y, w, h, l) {}
};

#endif
