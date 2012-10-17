// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _INPUT_REGION_H_
#define _INPUT_REGION_H_

#include <string>
#include <stdio.h>
#include <set>
#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include "FlGui.h"
#include "GEntity.h"
#include "Options.h"
#include "GmshDefines.h"

class inputRegion : public Fl_Group {
 private:
  Fl_Input *_input;
  Fl_Button *_add_butt;
  static void _input_cb(Fl_Widget *w, void *data)
  {
    inputRegion *b = (inputRegion*)data;
    b->do_callback();
  }
  static void _add_butt_cb(Fl_Widget *w, void *data);
  std::string _set2string(const std::set<std::string> &s)
  {
    std::string out;
    for(std::set<std::string>::const_iterator it = s.begin(); it != s.end(); it++){
      if(it != s.begin()) out += ", ";
      out += *it;
    }
    return out;
  }
  std::string _trim(const std::string &str, const std::string& white=" ")
  {
    size_t beg = str.find_first_not_of(white);
    if(beg == std::string::npos) return "";
    size_t end = str.find_last_not_of(white);
    return str.substr(beg, end - beg + 1);
  }
  std::set<std::string> _string2set(const std::string &s)
  {
    std::set<std::string> out;
    std::string::size_type first = 0;
    while(1){
      std::string str = _trim(onelab::parameter::getNextToken(s, first, ','));
      //str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
      if(str.empty()) break;
      out.insert(str);
    }
    return out;
  }
 public:
  inputRegion(int x, int y, int w, int h, bool readOnly, const char *l=0)
    : Fl_Group(x,y,w,h,l)
  {
    int butt_w = FL_NORMAL_SIZE + 6;
    int input_w = w - butt_w;

    if(readOnly)
      _input = new Fl_Output(x, y, input_w, h);
    else
      _input = new Fl_Input(x, y, input_w, h);
    _input->callback(_input_cb, this);
    _input->when(FL_WHEN_ENTER_KEY|FL_WHEN_RELEASE);

    _add_butt = new Fl_Button(x + input_w, y, butt_w, h, "+");
    _add_butt->callback(_add_butt_cb, this);
    _add_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _add_butt->tooltip("Add region interactively");

    if(readOnly) _add_butt->deactivate();

    end(); // close the group
    resizable(_input);
  }
  std::set<std::string> value() { return _string2set(_input->value()); }
  void value(const std::set<std::string> &val)
  {
    _input->value(_set2string(val).c_str());
  }
};

#endif
