#ifndef _OPENGL_WINDOW_H_
#define _OPENGL_WINDOW_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

class Opengl_Window : public Fl_Gl_Window {
  void draw();
  void draw_overlay();
  int handle(int);

  // new
  void clear_overlay();

public:
  Opengl_Window(int x,int y,int w,int h,const char *l=0)
    : Fl_Gl_Window(x, y, w, h, l) {}
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
