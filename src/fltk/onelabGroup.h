// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_GROUP_H
#define ONELAB_GROUP_H

#include "rebuildLoop.h"
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
public:
  // a solver running or not, and asked to stop (see setRunState())
  enum runState { Idle, Running, Stopping };

private:
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  // the index of the first item of the automatic behaviours in the gear menu
  int _firstGearOption;
  runState _state;
  // all the items of the gear menu active, or only the automatic behaviours
  void _activateGearMenu(bool all);
  // the widgets of the tree and the strings they show (a list, so that the
  // strings stay where they are)
  std::vector<Fl_Widget *> _treeWidgets;
  std::list<std::string> _treeStrings;
  // the rebuilds of the tree (see rebuildTree())
  rebuildLoop _rebuilds;
  void _rebuildTree();
  // a rebuild asked for while a mouse button is held down over the tree: done
  // once it is released (see rebuildTree())
  static void _rebuildAfterPress(void *data);
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
  // deleted at the next rebuild (see _rebuildTree())
  void _addRow(Fl_Tree_Item *n,
               const std::function<void(int ww, int hh)> &make);
  template <class T> void _addParameter(T &p);
  void _addMenu(const std::string &path, Fl_Callback *callback, void *data,
                const std::string &help = "");
  void _addSolverMenu(int num);
  void _addViewMenu(int num);
  void _addModuleButtons(const std::string &module);
  std::set<std::string> _getClosedGmshMenus();
  void _addGmshMenus();

public:
  onelabGroup(int x, int y, int w, int h, const char *l = nullptr);
  ~onelabGroup() override;
  void updateGearMenu();
  void rebuildSolverList();
  // the tree made again from the ONELAB parameters, once a click on it is over
  // (see onelabGroup.cpp)
  void rebuildTree();
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
  bool isTreeItemOpen(const std::string &name);
  void setButtonVisibility();
  // whether a solver runs: the Run button becomes Stop, and Kill once asked to
  // stop
  void setRunState(runState state);
  bool isBusy() { return _state != Idle; }
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

#endif
