#ifndef _POPUP_BUTTON_H
#define _POPUP_BUTTON_H

// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include <FL/Fl_Menu_Button.H>

// We need to define our own popup button to fix a bug in FLTK 1.1.7
// (popup() in 1.1.7 calls redraw() after picked(), which can cause a
// crash if the button was deleted by the callback)

class Popup_Button : public Fl_Menu_Button {
 public:
  Popup_Button(int x, int y, int w, int h, char *label=0) 
    : Fl_Menu_Button(x, y, w, h, label) {}
  void draw(){ Fl_Menu_Button::draw(); }
  int handle(int e);
  const Fl_Menu_Item* popup();
};

#endif
