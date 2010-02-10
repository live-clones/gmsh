// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _POPUP_BUTTON_H
#define _POPUP_BUTTON_H

#include <FL/Fl.H>
#include <FL/Fl_Menu_Button.H>

// This is needed for FLTK < 1.1.8 (popup() in 1.1.7 calls redraw()
// after picked(), which can cause a crash if the button was deleted
// by the callback)
class popupButton : public Fl_Menu_Button {
 public:
  popupButton(int x, int y, int w, int h, char *label=0) 
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
