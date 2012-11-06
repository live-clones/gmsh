// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ONELAB_WINDOW_H_
#define _ONELAB_WINDOW_H_

#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Input.H>
#include "onelab.h"

class viewButton;

class onelabGroup : public Fl_Group{
 private:
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  int _gearOptionsStart, _gearOptionsEnd;
  std::vector<Fl_Widget*> _treeWidgets;
  std::vector<char*> _treeStrings;
  std::string _title;
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
  void _addMenu(const std::string &path, Fl_Callback *callback, void *data);
  void _addViewMenu(int num);
  std::set<std::string> _getClosedGmshMenus();
  void _addGmshMenus();
 public:
  onelabGroup(int x, int y, int w, int h, const char *l=0);
  void rebuildSolverList();
  void rebuildTree();
  void redrawTree(){ _tree->redraw(); }
  void openTreeItem(const std::string &name);
  void setButtonVisibility();
  void setButtonMode(const std::string &butt0, const std::string &butt1);
  bool isBusy();
  std::string getPath(Fl_Tree_Item *item)
  {
    char path[1024];
    _tree->item_pathname(path, 1024, item);
    return std::string(path);
  }
  viewButton *getViewButton(int num);
  void addSolver(const std::string &name, const std::string &exe,
                 const std::string &hostName, int index);
  void removeSolver(const std::string &name);
  void checkForErrors(const std::string &client);
  bool stop(){ return _stop; }
  void stop(bool val){ _stop = val; }
};

void onelab_cb(Fl_Widget *w, void *data);
void solver_cb(Fl_Widget *w, void *data);
int metamodel_cb(const std::string &name, const std::string &action="");

#endif
