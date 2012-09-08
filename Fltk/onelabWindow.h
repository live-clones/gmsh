// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
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
  std::vector<char*> _treeStrings;
  std::string _title;
  int _deltaFontSize;
  bool _stop;
  int _itemWidth;
  template <class T> void _addParameter(T &p);
  Fl_Widget *_addParameterWidget(onelab::number &p, Fl_Tree_Item *n,
                                 bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::string &p, Fl_Tree_Item *n,
                                 bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::region &p, Fl_Tree_Item *n,
                                 bool highlight, Fl_Color c);
  Fl_Widget *_addParameterWidget(onelab::function &p, Fl_Tree_Item *n,
                                 bool highlight, Fl_Color c);
 public:
  onelabWindow(int deltaFontSize=0);
  int x(){ return _win->x(); }
  int y(){ return _win->y(); }
  int w(){ return _win->w(); }
  int h(){ return _win->h(); }
  void rebuildSolverList();
  void rebuildTree();
  void setButtonMode(const std::string &butt0, const std::string &butt1);
  bool isBusy();
  void show(){ _win->show(); }
  int shown(){ return _win->shown(); }
  int saveAuto();
  int meshAuto();
  int mergeAuto();
  int hideNewViews();
  int showLastStep();
  std::string getPath(Fl_Tree_Item *item)
  {
    char path[1024];
    _tree->item_pathname(path, 1024, item);
    return std::string(path);
  }
  void addSolver(const std::string &name, const std::string &exe,
                 const std::string &hostName, int index);
  void removeSolver(const std::string &name);
  void checkForErrors(const std::string &client);
  bool stop(){ return _stop; }
  void stop(bool val){ _stop = val; }
};

void onelab_cb(Fl_Widget *w, void *data);

#endif

void solver_cb(Fl_Widget *w, void *data);

#endif
