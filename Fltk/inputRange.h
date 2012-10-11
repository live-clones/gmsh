// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _INPUT_RANGE_H_
#define _INPUT_RANGE_H_

#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Menu_Button.H>

class inputValue : public Fl_Value_Input
{
 public:
  inputValue(int x, int y, int w, int h, const char *l=0) :
    Fl_Value_Input(x, y, w, h, l) {}
  virtual int format(char *buffer){ return sprintf(buffer, "%g", value()); }
};

class inputRange : public Fl_Group {
 private:
  inputValue *_input;
  Fl_Input *_range;
  Fl_Toggle_Button *_range_butt, *_loop_butt;
  Fl_Button *_graph_butt;
  Fl_Menu_Button *_graph_menu;
  std::string _loop_val, _graph_val;
  double _min, _max, _step, _max_number;
  std::vector<double> _choices;
  bool _do_callback_on_values;
  double _fixStep(double step)
  {
    // workaround annoying behaviour of Fl_Value_Input: if step is a nonzero
    // integer, one can only enter integer values in the widget; se we force
    // nonzero steps to be noninteger
    if(step && step - floor(step) <= 0) step *= (1. - 1e-7);
    return step;
  }
  void _values2string()
  {
    std::ostringstream tmp;
    if(_choices.size()){
      // construct range string using choices
      for(unsigned int i = 0; i < _choices.size(); i++){
        if(i) tmp << ", ";
        tmp << _choices[i];
      }
      if(_choices.size() > 1){
        _input->minimum(_choices[0]);
        _input->maximum(_choices[_choices.size() - 1]);
        _input->step(_fixStep(_choices[1] - _choices[0]));
      }
      _step = 0.;
    }
    else{
      // construct range string from min/max/step
      if(_min != -_max_number){
        tmp << _min;
        _input->minimum(_min);
      }
      tmp << ":";
      if(_max != _max_number){
        tmp << _max;
        _input->maximum(_max);
      }
      if(_step == 0.) _step = 1.;
      if(_step != 1.) tmp << ":" << _step;
      _input->step(_fixStep(_step));
      _choices.clear();
    }
    _range->value(tmp.str().c_str());
  }
  void _string2values()
  {
    std::string str(_range->value());
    if(str.find_first_of(',') != std::string::npos){
      // parse list of values
      std::string::size_type first = 0;
      _choices.clear();
      while(1){
        std::string::size_type last = str.find_first_of(',', first);
        std::string val = str.substr(first, last - first);
        _choices.push_back(atof(val.c_str()));
        if(last == std::string::npos)
          break;
        else
          first = last + 1;
      }
      if(_choices.size() > 1){
        _input->minimum(_choices[0]);
        _input->maximum(_choices[_choices.size() - 1]);
        _input->step(_fixStep(_choices[1] - _choices[0]));
      }
      _step = 0.;
    }
    else{
      // parse min/max/step
      std::string min, max, step;
      std::string::size_type first = 0;
      std::string::size_type last = str.find_first_of(':', first);
      min = str.substr(first, last - first);
      if(last != std::string::npos){
        first = last + 1;
        last = str.find_first_of(':', first);
        max = str.substr(first, last - first);
        if(last != std::string::npos)
          step = str.substr(last + 1, str.size());
      }
      if(min.size()){
        _min = atof(min.c_str());
        _input->minimum(_min);
      }
      else
        _min = -_max_number;
      if(max.size()){
        _max = atof(max.c_str());
        _input->maximum(_max);
      }
      else
        _max = _max_number;
      if(step.size())
        _step = atof(step.c_str());
      else
        _step = 1.;
      _input->step(_fixStep(_step));
      _choices.clear();
    }
  }
  void _show_range()
  {
    if(_range_butt->value()){
      _input->size(_input->w() - _range->w(), _input->h());
      _input->redraw();
      _range->show();
    }
    else{
      _input->size(_input->w() + _range->w(), _input->h());
      _input->redraw();
      _range->hide();
    }
  }
  void _set_loop_value(const std::string &val)
  {
    _loop_val = val;
    if(val == "1"){
      _loop_butt->label("1");
      _loop_butt->selection_color(FL_GREEN);
      _loop_butt->value(1);
    }
    else if(val == "2"){
      _loop_butt->label("2");
      _loop_butt->selection_color(FL_BLUE);
      _loop_butt->value(1);
    }
    else if(val == "3"){
      _loop_butt->label("3");
      _loop_butt->selection_color(FL_RED);
      _loop_butt->value(1);
    }
    else{
      _loop_butt->label("@-1gmsh_rotate");
      _loop_butt->selection_color(_loop_butt->color());
      _loop_butt->value(0);
    }
    _loop_butt->redraw();
  }
  void _set_graph_value(const std::string &val, bool update_menu=true)
  {
    _graph_val = val;
    _graph_val.resize(8, '0');
    if(update_menu){
      int index[8] = {1, 2, 5, 6, 9, 10, 13, 14};
      for(int i = 0; i < 8; i++){
        if(_graph_val[i] == '1')
          ((Fl_Menu_Item*)_graph_menu->menu())[index[i]].set();
        else
          ((Fl_Menu_Item*)_graph_menu->menu())[index[i]].clear();
      }
    }
    bool yellow = false;
    for(int i = 0; i < 8; i++) if(_graph_val[i] == '1') yellow = true;
    if(yellow){
      _graph_butt->value(1);
      _graph_butt->selection_color(FL_YELLOW);
    }
    else{
      _graph_butt->value(0);
      _graph_butt->selection_color(_graph_butt->color());
    }
    _graph_butt->redraw();
  }
  static void _input_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    b->doCallbackOnValues(true);
    b->do_callback();
  }
  static void _range_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    b->_string2values();
    b->doCallbackOnValues(true);
    b->do_callback();
  }
  static void _range_butt_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    b->_show_range();
  }
  static void _loop_butt_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    if(b->_loop_val == "1")      b->_set_loop_value("2");
    else if(b->_loop_val == "2") b->_set_loop_value("3");
    else if(b->_loop_val == "3") b->_set_loop_value("0");
    else                         b->_set_loop_value("1");
    b->doCallbackOnValues(false);
    b->do_callback();
  }
  static void _graph_menu_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    std::string v;
    v.resize(8);
    v[0] = b->_graph_menu->menu()[1].value() ? '1' : '0';
    v[1] = b->_graph_menu->menu()[2].value() ? '1' : '0';
    v[2] = b->_graph_menu->menu()[5].value() ? '1' : '0';
    v[3] = b->_graph_menu->menu()[6].value() ? '1' : '0';
    v[4] = b->_graph_menu->menu()[9].value() ? '1' : '0';
    v[5] = b->_graph_menu->menu()[10].value() ? '1' : '0';
    v[6] = b->_graph_menu->menu()[13].value() ? '1' : '0';
    v[7] = b->_graph_menu->menu()[14].value() ? '1' : '0';
    b->_set_graph_value(v, false);
    b->doCallbackOnValues(false);
    b->do_callback();
  }
  static void _graph_menu_reset_cb(Fl_Widget *w, void *data)
  {
    inputRange *b = (inputRange*)data;
    b->_set_graph_value("00000000");
    b->doCallbackOnValues(false);
    b->do_callback();
  }
 public:
  inputRange(int x, int y, int w, int h, double max_number, const char *l=0)
    : Fl_Group(x,y,w,h,l), _min(-max_number), _max(max_number), _step(1.),
      _max_number(max_number), _do_callback_on_values(true)
  {
    _graph_val.resize(8, '0');

    int dot_w = FL_NORMAL_SIZE - 2, loop_w = FL_NORMAL_SIZE + 6, graph_w = loop_w;
    int input_w = w - dot_w - loop_w - graph_w;
    int range_w = input_w / 2;

    _input = new inputValue(x, y, input_w, h);
    _input->callback(_input_cb, this);
    _input->when(FL_WHEN_ENTER_KEY|FL_WHEN_RELEASE);

    _range = new Fl_Input(x + input_w - range_w, y, range_w, h);
    _range->callback(_range_cb, this);
    _range->when(FL_WHEN_ENTER_KEY|FL_WHEN_RELEASE);
    _range->hide();

    _range_butt = new Fl_Toggle_Button(x + input_w, y, dot_w, h, ":");
    _range_butt->callback(_range_butt_cb, this);
    _range_butt->tooltip("Show range");

    _loop_butt = new Fl_Toggle_Button(x + input_w + dot_w, y, loop_w, h);
    _loop_butt->label("@-1gmsh_rotate");
    _loop_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _loop_butt->callback(_loop_butt_cb, this);
    _loop_butt->tooltip("Loop over range when computing");

    _graph_butt = new Fl_Button(x + input_w + dot_w + loop_w, y, graph_w, h);
    _graph_butt->label("@-1gmsh_graph");
    _graph_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _graph_butt->tooltip("Draw range on X-Y graph(s)");

    _graph_menu = new Fl_Menu_Button(x + input_w + dot_w + loop_w, y, graph_w, h);
    _graph_menu->type(Fl_Menu_Button::POPUP123);
    _graph_menu->add("Graph 1/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 1/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 2/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 2/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 3/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 3/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 4/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Graph 4/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("None", 0, _graph_menu_reset_cb, this);

    end(); // close the group
    resizable(_input);
  }
  bool doCallbackOnValues(){ return _do_callback_on_values; }
  void doCallbackOnValues(bool val){ _do_callback_on_values = val; }
  double value() { return _input->value(); }
  void value(double val) { _input->value(val); }
  void choices(const std::vector<double> &val) { _choices = val; _values2string(); }
  std::vector<double> choices() { return _choices; }
  void minimum(double val) { _min = val; _values2string(); }
  double minimum() { return _min; }
  void maximum(double val) { _max = val; _values2string(); }
  double maximum() { return _max; }
  void step(double val) { _step = val; _values2string(); }
  double step() { return _step; }
  void loop(const std::string &val){ _set_loop_value(val); }
  std::string loop(){ return _loop_val; }
  void graph(const std::string &val){ _set_graph_value(val); }
  std::string graph(){ return _graph_val; }
  void color(int col){ _input->color(col); }
  int color(){ return _input->color(); }
  Fl_Value_Input *input(){ return _input; }
};

#endif
