// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESSAGE_BROWSER_H
#define MESSAGE_BROWSER_H

#include "FlGui.h"
#include "hintInput.h"
#include <algorithm>
#include <string>
#include <vector>

class messageBrowser : public Fl_Group {
private:
  Fl_Browser *_browser;
  Fl_Group *_box;
  Fl_Check_Button *_autoscroll;
  Fl_Button *_copy, *_save, *_clear;
  Fl_Input *_search;
  searchFilter _filter;

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

    _search =
      searchBox(x + wb, y + wb, sw, bh, "Search messages",
                "Show only the messages matching the regular expression,\n"
                "whatever the case",
                nullptr);
    _search->textsize(FL_NORMAL_SIZE - 1);

    _copy = new Fl_Button(x + wb + sw + WB, y + wb, bb, bh, "Copy");
    _copy->labelsize(FL_NORMAL_SIZE - 1);
    _copy->box(FL_THIN_UP_BOX);
    _copy->tooltip("Copy the selected lines, or all of them, to the clipboard");

    _save = new Fl_Button(x + sw + bb + 2 * WB, y + wb, bb, bh, "Save");
    _save->labelsize(FL_NORMAL_SIZE - 1);
    _save->box(FL_THIN_UP_BOX);

    _clear = new Fl_Button(x + sw + 2 * bb + 3 * WB, y + wb, bb, bh, "Clear");
    _clear->labelsize(FL_NORMAL_SIZE - 1);
    _clear->box(FL_THIN_UP_BOX);

    _autoscroll = new Fl_Check_Button(x + sw + 3 * bb + 4 * WB, y + wb, 2 * bb,
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
  // the filter typed, compiled once for every line to come
  void filter() { _filter.set(_search); }
  // the lines again, through the filter typed
  void rebuild(const std::vector<std::string> &messages)
  {
    filter();
    _browser->clear();
    for(const std::string &m : messages) add(m.c_str());
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
  void copy_callback(Fl_Callback *cb, void *p) { _copy->callback(cb, p); }
  void save_callback(Fl_Callback *cb, void *p) { _save->callback(cb, p); }
  void clear_callback(Fl_Callback *cb, void *p) { _clear->callback(cb, p); }
  void bottomline(int line) { _browser->bottomline(line); }
  int size() { return _browser->size(); }
  void add(const char *newtext)
  {
    if(_filter.matches(newtext)) _browser->add(newtext);
  }
  void clear() { _browser->clear(); }
  const char *text(int line) const { return _browser->text(line); }
  int selected(int line) const { return _browser->selected(line); }
};

#endif
