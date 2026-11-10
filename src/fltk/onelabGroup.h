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

bool getParameterColor(const std::string &str, Fl_Color &c);
Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);
Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);
// The ONELAB actions, as the Check and Run buttons and the gear menu do them
// (the clients read the one under way in ONELAB/Action): the model checked
// (the script read again with the parameters; always, even if nothing
// changed, when asked), computed (the loops over the parameters run, then the
// solvers), the database reset then checked, the solvers initialized (at
// startup), the tree and the graphs refreshed, the run stopped or the solvers
// killed, the database saved or loaded, and a reload asked by an outside code
void onelabCheck(bool always = false);
void onelabCompute();
void onelabReset();
void onelabInitialize();
void onelabRefresh();
void onelabStop();
void onelabKill();
void onelabSaveDatabase();
void onelabLoadDatabase();
void onelabReload();
// an action by its name ("check", "compute", ...), as the custom Run button
// of a model asks for it
void onelabAction(const std::string &action);
// the solver of index num added to the tree (or the list made again if num is
// negative), then the model checked, or reset when a solver is to be launched
// at startup
void selectSolver(int num);

// whether a solver runs (then said in the messages): what changes the
// solvers or the model must wait
bool solverBusy();

#endif
