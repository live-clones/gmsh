#ifndef _FILE_PICKER_H_
#define _FILE_PICKER_H_

// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include <FL/Fl_File_Chooser.H>

// The FLTK team doesn't want to add a position() method to the file
// chooser, so we have to derive our own. To make things worse, the 
// original file chooser doesn't expose its window to the world, so
// we need to use a cheap hack to get to it. Even worse, there is no
// way we can call get_focus() on the file input widget, which is also
// private. Sigh...

class File_Picker : public Fl_File_Chooser {
private:
  Fl_Double_Window *_win;
public:
  File_Picker(const char *d, const char *p, int t, const char *title)
    : Fl_File_Chooser(d, p, t, title) { 
    _win = (Fl_Double_Window*)newButton->parent()->parent(); 
  }
  void show(){ _win->show(); }
  void position(int x, int y){ _win->position(x,y);}
  int x(){ return _win->x();}
  int y(){ return _win->y();}
};

#endif
