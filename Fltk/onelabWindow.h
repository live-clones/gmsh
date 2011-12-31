// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ONELAB_WINDOW_H_
#define _ONELAB_WINDOW_H_

#include "GmshConfig.h"
#include <FL/Fl.H>

#if defined(HAVE_ONELAB) && (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 3)
#include <vector>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include "onelab.h"

class onelabWindow{
 private:
  Fl_Window *_win;
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  int _gearFrozenMenuSize;
  std::vector<Fl_Widget*> _treeWidgets;
  std::string _title;
  std::string _modelExtension;
  int _deltaFontSize;
  bool _stop;
 public:
  onelabWindow(int deltaFontSize=0);
  int x(){ return _win->x(); }
  int y(){ return _win->y(); }
  void rebuildSolverList();
  void rebuildTree();
  void redrawTree(){ _tree->redraw(); }
  void setButtonMode(const std::string &mode);
  void show(){ _win->show(); }
  int shown(){ return _win->shown(); }
  std::string getModelExtension(){ return _modelExtension; }
  void setModelExtension(const std::string &ext){ _modelExtension = ext; }
  int meshAuto(){ return _gear->menu()[2].value(); }
  int hideNewViews(){ return _gear->menu()[3].value(); }
  std::string getPath(Fl_Tree_Item *item)
  {
    char path[1024];
    _tree->item_pathname(path, 1024, item);
    return std::string(path);
  }
  void addSolver(const std::string &name, const std::string &commandLine,
                 int index);
  void removeSolver(const std::string &name);
  void checkForErrors(const std::string &client);
  bool stop(){ return _stop; }
  void stop(bool val){ _stop = val; }
};

void onelab_cb(Fl_Widget *w, void *data);

#endif

void solver_cb(Fl_Widget *w, void *data);

#endif
