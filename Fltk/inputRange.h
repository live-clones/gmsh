// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Toggle_Button.H>

class inputRange : public Fl_Group {
 private:
  Fl_Value_Input *_input;
  Fl_Input *_range;
  Fl_Toggle_Button *_range_butt, *_loop_butt;
  double _min, _max, _step, _max_number;
  void _values2string()
  {
    // construct range string from min/max/step
    std::ostringstream tmp;
    if(_min != -_max_number){
      tmp << _min;
      _input->minimum(_min);
    }
    tmp << ":";
    if(_max != _max_number){
      tmp << _max;
      _input->maximum(_max);
    }
    if(_step){
      if(_step != 1.) tmp << ":" << _step;
      _input->step(_step);
    }
    _range->value(tmp.str().c_str());
  }
  void _string2values()
  {
    // parse range string and affect min/max/step
    std::string str(_range->value()), min, max, step;
    std::string::size_type first = 0, last;
    last = str.find_first_of(':', first);
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
    if(max.size()){
      _max = atof(max.c_str());
      _input->maximum(_max);
    }
    if(step.size()){
      _step = atof(step.c_str());
      _input->step(_step);
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
  static void _input_cb(Fl_Widget *w, void *data)
  {
    ((inputRange*)data)->do_callback();
  }
  static void _range_cb(Fl_Widget *w, void *data)
  {
    ((inputRange*)data)->_string2values();
    ((inputRange*)data)->do_callback();
  }
  static void _range_butt_cb(Fl_Widget *w, void *data)
  {
    ((inputRange*)data)->_show_range(); 
  }
  static void _loop_butt_cb(Fl_Widget *w, void *data)
  {
    ((inputRange*)data)->do_callback(); 
  }
 public:
  inputRange(int x, int y, int w, int h, double max_number, const char *l=0) 
    : Fl_Group(x,y,w,h,l), _min(-max_number), _max(max_number), _step(1.),
      _max_number(max_number)
  {
    int dot_w = FL_NORMAL_SIZE - 2, loop_w = FL_NORMAL_SIZE + 6;
    int input_w = w - dot_w - loop_w;
    int range_w = input_w / 2;

    _input = new Fl_Value_Input(x, y, input_w, h);
    _input->callback(_input_cb, this);
    _input->when(FL_WHEN_ENTER_KEY|FL_WHEN_RELEASE);
    
    _range = new Fl_Input(x + input_w - range_w, y, range_w, h);
    _range->callback(_range_cb, this);
    _range->when(FL_WHEN_ENTER_KEY|FL_WHEN_RELEASE);
    _range->hide();

    _range_butt = new Fl_Toggle_Button(x + input_w, y, dot_w, h, ":");
    _range_butt->callback(_range_butt_cb, this);

    _loop_butt = new Fl_Toggle_Button(x + input_w + dot_w, y, loop_w, h);
    _loop_butt->label("@-1gmsh_rotate");
    _loop_butt->selection_color(FL_GREEN);
    _loop_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _loop_butt->callback(_loop_butt_cb, this);

    end(); // close the group
    resizable(_input);
  }
  double value() { return _input->value(); }
  void value(double val) { _input->value(val); }
  void minimum(double val) { _min = val; _values2string(); }
  double minimum() { return _min; }
  void maximum(double val) { _max = val; _values2string(); }
  double maximum() { return _max; }
  void step(double val) { _step = val; _values2string(); }
  double step() { return _step; }
  void loop(int val) { _loop_butt->value(val); }
  int loop() { return _loop_butt->value(); }
};
