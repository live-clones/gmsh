// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ONELAB_WINDOW_H_
#define _ONELAB_WINDOW_H_

#include "onelab.h"
#include <FL/Fl.H>

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
#include <vector>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>

class onelabWindow{
 private:
  Fl_Window *_win;
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Input *_model;
  Fl_Menu_Button *_gear;
  std::vector<Fl_Widget*> _treeWidgets;
  std::string _title;
 public:
  onelabWindow(int deltaFontSize=0);
  int x(){ return _win->x(); }
  int y(){ return _win->y(); }
  void rebuildSolverList();
  void rebuildTree();
  void redrawTree(){ _tree->redraw(); }
  void activate(){ _butt[0]->activate(); _butt[1]->activate(); }
  void deactivate(){ _butt[0]->deactivate(); _butt[1]->deactivate(); }
  void show(){ _win->show(); }
  int shown(){ return _win->shown(); }
  std::string getModelName(){ return _model->value(); }
  void setModelName(const std::string &name){ _model->value(name.c_str()); }
  int meshAuto(){ return _gear->menu()[1].value(); }
  std::string getPath(Fl_Tree_Item *item)
  {
    char path[1024];
    _tree->item_pathname(path, 1024, item);
    return std::string(path);
  }
  void addSolver(const std::string &name, const std::string &commandLine);
  void removeSolver(const std::string &name);
};

void onelab_cb(Fl_Widget *w, void *data);

#endif

void solver_cb(Fl_Widget *w, void *data);

#endif
