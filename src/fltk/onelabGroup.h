// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_GROUP_H
#define ONELAB_GROUP_H

#include <list>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include <FL/Fl.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>
#include "onelab.h"

class viewButton;

class onelabGroup : public Fl_Group {
private:
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  int _gearOptionsStart, _gearOptionsEnd;
  // the widgets of the tree and the strings they show, and those retired by
  // a rebuild while an event sent to them was handled, kept hidden until the
  // events are handled (see _rebuildTree()); a list, so that the strings stay
  // where they are
  std::vector<Fl_Widget *> _treeWidgets, _retiredWidgets;
  std::list<std::string> _treeStrings, _retiredStrings;
  // a rebuild asked for during a rebuild (hiding an edited input runs its
  // callback, which may rebuild the tree): done once the current one is over
  bool _rebuilding, _rebuildAgain, _rebuildAgainDelete;
  void _rebuildTree(bool deleteWidgets);
  bool _stop;
  double _baseWidth, _indent;
  int _minWindowWidth, _minWindowHeight;
  std::set<std::string> _manuallyClosed;
  // the submenus of the modules are closed when the tree is first built
  bool _firstBuild;
  bool _hasContext;
  void _computeWidths();
  // the width left for the widget of an item at its depth
  int _rowWidth(Fl_Tree_Item *n);
  // the widget of an item, built by make() in a group of the width left at
  // its depth and the height of a row, which the tree places; the groups are
  // deleted after the next rebuild (see _rebuildTree())
  void _addRow(Fl_Tree_Item *n,
               const std::function<void(int ww, int hh)> &make);
  template <class T> void _addParameter(T &p);
  void _addMenu(const std::string &path, Fl_Callback *callback, void *data);
  void _addSolverMenu(int num);
  void _addViewMenu(int num);
  std::set<std::string> _getClosedGmshMenus();
  void _addGmshMenus();

public:
  onelabGroup(int x, int y, int w, int h, const char *l = nullptr);
  void updateGearMenu();
  void rebuildSolverList();
  // once the events are handled (see FlGui::_dispatch())
  void deleteRetiredWidgets();
  void rebuildTree(bool deleteWidgets);
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  bool isTreeItemOpen(const std::string &name);
  void setButtonVisibility();
  void setButtonMode(const std::string &butt0, const std::string &butt1);
  bool isBusy();
  int getMinWindowWidth() { return _minWindowWidth; }
  int getMinWindowHeight() { return _minWindowHeight; }
  std::string getPath(Fl_Tree_Item *item);
  void insertInManuallyClosed(const std::string &path)
  {
    _manuallyClosed.insert(path);
  }
  void removeFromManuallyClosed(const std::string &path)
  {
    _manuallyClosed.erase(path);
  }
  bool isManuallyClosed(const std::string &path)
  {
    return _manuallyClosed.find(path) != _manuallyClosed.end();
  }
  viewButton *getViewButton(int num);
  void openCloseViewButton(int num);
  void addSolver(const std::string &name, const std::string &exe,
                 const std::string &hostName, int index);
  void checkForErrors(const std::string &client);
  bool stop() { return _stop; }
  void stop(bool val) { _stop = val; }
  void setContext(bool val){ _hasContext = val; }
  bool hasContext(){ return _hasContext; }
};

bool getParameterColor(const std::string &str, Fl_Color &c);
Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);
Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);
void solver_cb(Fl_Widget *w, void *data);
void onelab_cb(Fl_Widget *w, void *data);

#endif
