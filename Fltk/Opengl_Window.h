#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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
#include "Mesh.h"

class Opengl_Window : public Fl_Gl_Window {
 public:
  bool AddPointMode;
 private:
  bool ZoomMode, ZoomClick, FirstClick;
  int xpos, ypos, xmov, ymov, ibut, hits;
  double xzoom0, yzoom0, xzoom1, yzoom1;
  GLdouble xc, yc, xc1, yc1, xc2, yc2, xt1, yt1, xscale1, yscale1;
  Vertex *v, *ov;
  Curve *c, *oc;
  Surface *s, *os;

  void draw();
  int handle(int);

 public:
  Opengl_Window(int x,int y,int w,int h,const char *l=0)
    : Fl_Gl_Window(x, y, w, h, l) {
    xpos = ypos = xmov = ymov = ibut = hits = 0;
    xzoom0 = yzoom0 = xzoom1 = yzoom1 = 0.;
    AddPointMode = ZoomMode = ZoomClick = FirstClick = false;
    v = ov = NULL;
    c = oc = NULL;
    s = os = NULL;
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
