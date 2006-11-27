#ifndef _POPUP_BUTTON_H
#define _POPUP_BUTTON_H

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

// Update Sat Apr 29 21:39:00 2006: this bug is now fixed in FLTK.

class Popup_Button : public Fl_Menu_Button {
 public:
  Popup_Button(int x, int y, int w, int h, char *label=0) 
    : Fl_Menu_Button(x, y, w, h, label) {}
  void draw(){ Fl_Menu_Button::draw(); }
  int handle(int e)
  {
    if (!menu() || !menu()->text) return 0;
    switch (e) {
    case FL_ENTER:
    case FL_LEAVE:
      return (box() && !type()) ? 1 : 0;
    case FL_PUSH:
      if (!box()) {
	if (Fl::event_button() != 3) return 0;
      } else if (type()) {
	if (!(type() & (1 << (Fl::event_button()-1)))) return 0;
      }
      if (Fl::visible_focus()) Fl::focus(this);
      popup();
      return 1;
    case FL_KEYBOARD:
      if (!box()) return 0;
      if (Fl::event_key() == ' ' &&
	  !(Fl::event_state() & (FL_SHIFT | FL_CTRL | FL_ALT | FL_META))) {
	popup();
	return 1;
      } else return 0;
    case FL_SHORTCUT:
      if (Fl_Widget::test_shortcut()) {popup(); return 1;}
      return test_shortcut() != 0;
    case FL_FOCUS:
    case FL_UNFOCUS:
      if (box() && Fl::visible_focus()) {
	redraw();
	return 1;
      }
    default:
      return 0;
    }
  }
  const Fl_Menu_Item* popup()
  {
    const Fl_Menu_Item* m;
    redraw();
    m = menu()->popup(Fl::event_x(), Fl::event_y(), label(), mvalue(), this);
    picked(m);
    return m;
  }
};

#endif
