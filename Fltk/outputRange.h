// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _OUTPUT_RANGE_H_
#define _OUTPUT_RANGE_H_

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>

class outputRange : public Fl_Group {
 private:
  Fl_Output *_output;
  Fl_Button *_graph_butt;
  Fl_Menu_Button *_graph_menu;
  std::string _graph_val;
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
  static void _graph_menu_cb(Fl_Widget *w, void *data)
  {
    outputRange *b = (outputRange*)data;
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
    b->do_callback();
  }
  static void _graph_menu_reset_cb(Fl_Widget *w, void *data)
  {
    outputRange *b = (outputRange*)data;
    b->_set_graph_value("00000000");
    b->do_callback();
  }
 public:
  outputRange(int x, int y, int w, int h, const char *l=0)
    : Fl_Group(x,y,w,h,l)
  {
    _graph_val.resize(8, '0');

    int graph_w = FL_NORMAL_SIZE + 6;
    int output_w = w - graph_w;

    _output = new Fl_Output(x, y, output_w, h);

    _graph_butt = new Fl_Button(x + output_w, y, graph_w, h);
    _graph_butt->label("@-1gmsh_graph");
    _graph_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _graph_butt->tooltip("Draw range on X-Y graph(s)");

    _graph_menu = new Fl_Menu_Button(x + output_w, y, graph_w, h);
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
    resizable(_output);
  }
  void value(double val)
  { 
    char tmp[128];
    sprintf(tmp, "%g", val);
    _output->value(tmp); 
  }
  void graph(const std::string &val){ _set_graph_value(val); }
  std::string graph(){ return _graph_val; }
  void color(int col){ _output->color(col); }
};

#endif
