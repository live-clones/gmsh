// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_GROUP_H
#define ONELAB_GROUP_H

#include <vector>
#include <FL/Fl.H>
#include <FL/Fl_Tree.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Input.H>
#include "onelab.h"

class viewButton;

class onelabGroup : public Fl_Group {
private:
  Fl_Tree *_tree;
  Fl_Button *_butt[2];
  Fl_Menu_Button *_gear;
  int _gearOptionsStart, _gearOptionsEnd;
  std::vector<Fl_Widget *> _treeWidgets;
  std::vector<char *> _treeStrings;
  bool _stop;
  double _baseWidth, _indent;
  int _minWindowWidth, _minWindowHeight;
  double _widgetLabelRatio;
  std::set<std::string> _manuallyClosed;
  bool _enableTreeWidgetResize;
  bool _firstBuild;
  void _computeWidths();
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
  void rebuildTree(bool deleteWidgets);
  void enableTreeWidgetResize(bool value) { _enableTreeWidgetResize = value; }
  void redrawTree() { _tree->redraw(); }
  void openTreeItem(const std::string &name);
  void closeTreeItem(const std::string &name);
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
  void removeSolver(const std::string &name);
  void checkForErrors(const std::string &client);
  bool stop() { return _stop; }
  void stop(bool val) { _stop = val; }
};

bool getParameterColor(const std::string &str, Fl_Color &c);
Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::vector<char *> &stringsToFree);
Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::vector<char *> &stringsToFree);
void solver_cb(Fl_Widget *w, void *data);
void onelab_cb(Fl_Widget *w, void *data);

#endif
