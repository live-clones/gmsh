// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESSAGE_BROWSER_H
#define MESSAGE_BROWSER_H

#include "FlGui.h"
#include <algorithm>
#include <string>
#include <regex>

class messageBrowser : public Fl_Group {
private:
  Fl_Browser *_browser;
  Fl_Group *_box;
  Fl_Check_Button *_autoscroll;
  Fl_Button *_clear, *_save;
  Fl_Input *_search;

public:
  messageBrowser(int x, int y, int w, int h, const char *l = 0)
    : Fl_Group(x, y, w, h, l)
  {
    int bh = BH - 4; // button height
    int wb = WB / 2; // border
    int bb = BB - 3 * WB;
    int sw = 3 * BB; // search field width

    _box = new Fl_Group(x, y, w, bh + 2 * wb);
    _box->box(GMSH_SIMPLE_TOP_BOX);

    Fl_Group *o = new Fl_Group(x + wb, y + wb, sw, bh);
    o->tooltip("Filter messages using regular expression");
    o->box(FL_THIN_DOWN_BOX);
    o->color(FL_BACKGROUND2_COLOR);
    _search = new Fl_Input(x + wb + bh, y + wb + 2, sw - bh - 2, bh - 4,
                           "@-1gmsh_search");
    _search->box(FL_FLAT_BOX);
    _search->when(FL_WHEN_CHANGED);
    _search->textsize(FL_NORMAL_SIZE - 1);
    o->resizable(_search);
    o->end();

    _save = new Fl_Button(x + wb + sw + WB, y + wb, bb, bh, "Save");
    _save->labelsize(FL_NORMAL_SIZE - 1);
    _save->box(FL_THIN_UP_BOX);

    _clear = new Fl_Button(x + sw + bb + 2 * WB, y + wb, bb, bh, "Clear");
    _clear->labelsize(FL_NORMAL_SIZE - 1);
    _clear->box(FL_THIN_UP_BOX);

    _autoscroll = new Fl_Check_Button(x + sw + 2 * bb + 3 * WB, y + wb, 2 * bb,
                                      bh, "Autoscroll messages");
    _autoscroll->labelsize(FL_NORMAL_SIZE - 1);
    _autoscroll->type(FL_TOGGLE_BUTTON);
    _autoscroll->value(1);

    _box->end();
    _box->resizable(0);

    _browser = new Fl_Browser(x, y + bh + 2 * wb, w, h - bh - 2 * wb, l);
    _browser->box(GMSH_SIMPLE_TOP_BOX);
#if defined(WIN32) // FL_SCREEN seems to be too tiny on most Windows setups
    _browser->textfont(FL_COURIER);
#else
    _browser->textfont(FL_SCREEN);
#endif
    _browser->type(FL_MULTI_BROWSER);
    _browser->tooltip("Selected lines are copied to the clipboard");
    _browser->end();
    end();
    resizable(_browser);
  }
  void box(Fl_Boxtype new_box) { _browser->box(new_box); }
  void textfont(Fl_Font font) { _browser->textfont(font); }
  void textsize(Fl_Fontsize newSize) { _browser->textsize(newSize); }
  Fl_Fontsize textsize() const { return _browser->textsize(); }
  void callback(Fl_Callback *cb, void *p) { _browser->callback(cb, p); }
  void search_callback(Fl_Callback *cb, void *p) { _search->callback(cb, p); }
  void autoscroll_callback(Fl_Callback *cb, void *p)
  {
    _autoscroll->callback(cb, p);
  }
  void save_callback(Fl_Callback *cb, void *p) { _save->callback(cb, p); }
  void clear_callback(Fl_Callback *cb, void *p) { _clear->callback(cb, p); }
  void bottomline(int line) { _browser->bottomline(line); }
  int size() { return _browser->size(); }
  void add(const char *newtext)
  {
    std::string search = _search->value();
    if(search.empty()) { _browser->add(newtext); }
    else {
      std::string tmp(newtext);
      try {
        // icase for case-insensitive search
        if(std::regex_search(tmp,
                             std::regex(search, std::regex_constants::icase)))
          _browser->add(newtext);
      } catch(...) {
      }
    }
  }
  void clear() { _browser->clear(); }
  const char *text(int line) const { return _browser->text(line); }
  int selected(int line) const { return _browser->selected(line); }
};

#endif
