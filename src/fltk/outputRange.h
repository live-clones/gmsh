// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OUTPUT_RANGE_H
#define OUTPUT_RANGE_H

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
  std::string _graph_val, _number_format;
  void _set_graph_value(const std::string &val, bool update_menu = true)
  {
    _graph_val = val;
    _graph_val.resize(36, '0');
    if(update_menu) {
      int index[36] = {1,  2,  3,  4,  7,  8,  9,  10, 13, 14, 15, 16,
                       19, 20, 21, 22, 25, 26, 27, 28, 31, 32, 33, 34,
                       37, 38, 39, 40, 43, 44, 45, 46, 49, 50, 51, 52};
      for(int i = 0; i < 36; i++) {
        if(_graph_val[i] != '0')
          ((Fl_Menu_Item *)_graph_menu->menu())[index[i]].set();
        else
          ((Fl_Menu_Item *)_graph_menu->menu())[index[i]].clear();
      }
    }
    bool yellow = false;
    for(int i = 0; i < 36; i++)
      if(_graph_val[i] != '0') yellow = true;
    if(yellow) {
      _graph_butt->value(1);
      _graph_butt->selection_color(FL_YELLOW);
    }
    else {
      _graph_butt->value(0);
      _graph_butt->selection_color(_graph_butt->color());
    }
    _graph_butt->redraw();
  }
  static void _graph_menu_cb(Fl_Widget *w, void *data)
  {
    outputRange *b = (outputRange *)data;
    std::string v;
    v.resize(36, '0');
    int index[36] = {1,  2,  3,  4,  7,  8,  9,  10, 13, 14, 15, 16,
                     19, 20, 21, 22, 25, 26, 27, 28, 31, 32, 33, 34,
                     37, 38, 39, 40, 43, 44, 45, 46, 49, 50, 51, 52};
    for(int i = 0; i < 36; i++) {
      // 1=iso, 2=continuous, 3=discrete, 4=numeric
      v[i] = b->_graph_menu->menu()[index[i]].value() ? '3' : '0';
    }
    b->_set_graph_value(v, false);
    b->do_callback();
  }
  static void _graph_menu_reset_cb(Fl_Widget *w, void *data)
  {
    outputRange *b = (outputRange *)data;
    std::string v;
    v.resize(36, '0');
    b->_set_graph_value(v.c_str());
    b->do_callback();
  }

public:
  outputRange(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Group(x, y, w, h, l)
  {
    _graph_val.resize(36, '0');

    int graph_w = FL_NORMAL_SIZE + 6;
    int output_w = w - graph_w;

    _output = new Fl_Output(x, y, output_w, h);

    _graph_butt = new Fl_Button(x + output_w, y, graph_w, h);
    _graph_butt->label("@-1gmsh_graph");
    _graph_butt->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    _graph_butt->tooltip("Draw range on X-Y graph(s)");

    _graph_menu = new Fl_Menu_Button(x + output_w, y, graph_w, h);
    _graph_menu->type(Fl_Menu_Button::POPUP123);
    _graph_menu->add("Top Left/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Left/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Left/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Left/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Right/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Right/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Right/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top Right/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Left/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Left/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Left/X ' ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Left/Y ' ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Right/X ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Right/Y ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Right/X ' ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Bottom Right/Y ' ", 0, _graph_menu_cb, this,
                     FL_MENU_TOGGLE);
    _graph_menu->add("Top/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Top/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Bottom/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Left/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Left/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Left/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Left/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Right/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Right/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Right/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Right/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Full/X ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Full/Y ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Full/X ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("Full/Y ' ", 0, _graph_menu_cb, this, FL_MENU_TOGGLE);
    _graph_menu->add("None", 0, _graph_menu_reset_cb, this);

    end(); // close the group
    resizable(_output);
  }
  void value(double val)
  {
    char buffer[256];
    if(_number_format.empty()) { sprintf(buffer, "%g", val); }
    else {
      if(_number_format.find("d") != std::string::npos ||
         _number_format.find("u") != std::string::npos)
        sprintf(buffer, _number_format.c_str(), (int)val);
      else
        sprintf(buffer, _number_format.c_str(), val);
    }
    _output->value(buffer);
  }
  void graph(const std::string &val) { _set_graph_value(val); }
  std::string graph() { return _graph_val; }
  void color(int col)
  {
    _output->color(col);
    _output->textcolor(fl_contrast(FL_FOREGROUND_COLOR, col));
  }
  void numberFormat(const std::string &fmt) { _number_format = fmt; }
};

#endif
