#ifndef _SHORTCUT_WINDOW_H
#define _SHORTCUT_WINDOW_H

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

#include "GmshUI.h"

#include <FL/Fl_Double_Window.H>
#include <FL/fl_ask.H>

// Derive special windows from Fl_Double_Window to correctly process
// the OS-specific shorcuts (Cmd-w on Mac, Alt+F4 on Windows)

class Dialog_Window : public Fl_Double_Window {
  int  handle(int event){
    switch (event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META+'w')){
	do_callback();
	return 1;
      }
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT+FL_F+4)){
	do_callback();
	return 1;
      }
#endif
      break;
    }
    return Fl_Double_Window::handle(event);
  }
 public:
  Dialog_Window(int x,int y,int w,int h,const char *l=0) :
    Fl_Double_Window(x, y, w, h, l) {}
  Dialog_Window(int w,int h,const char *l=0) :
    Fl_Double_Window(w, h, l) {}
};

class Main_Window : public Fl_Double_Window {
  int  handle(int event){
    switch (event) {
    case FL_SHORTCUT:
    case FL_KEYBOARD:
#if defined(__APPLE__)
      if(Fl::test_shortcut(FL_META+'w')){
	if(fl_ask("Do you really want to quit?"))
	  do_callback();
	return 1;
      }
#elif defined(WIN32)
      if(Fl::test_shortcut(FL_ALT+FL_F+4)){
	if(fl_ask("Do you really want to quit?"))
	  do_callback();
	return 1;
      }
#endif
      break;
    }
    return Fl_Double_Window::handle(event);
  }
 public:
  Main_Window(int x,int y,int w,int h,const char *l=0) :
    Fl_Double_Window(x, y, w, h, l) {}
  Main_Window(int w,int h,const char *l=0) :
    Fl_Double_Window(w, h, l) {}
};

#endif
