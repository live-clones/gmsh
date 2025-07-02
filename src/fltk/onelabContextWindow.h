// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_CONTEXT_WINDOW_H
#define ONELAB_CONTEXT_WINDOW_H

#include <vector>
#include <string>
#include <set>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>
#include "paletteWindow.h"

class GEntity;

class contextWindow : public paletteWindow {
private:
  bool _redraw;

public:
  contextWindow(int w, int h, bool nonModal, const char *l = nullptr)
    : paletteWindow(w, h, nonModal, l), _redraw(false)
  {
  }
  virtual int handle(int event);
  void enableRedraw() { _redraw = true; }
  void disableRedraw() { _redraw = false; }
};

class onelabContextWindow {
private:
  int _width, _height;
  std::vector<char *> _toFree;
  std::vector<Fl_Widget *> _onelabWidgets;
  template <class T>
  void
  _addOnelabWidget(T &p, const std::string &pattern,
                   std::set<std::pair<std::string, Fl_Widget *> > &widgets);
  Fl_Choice *_choice;
  int _dim, _tag;
  GEntity *_entity;
  std::string _name;
  std::vector<std::pair<int, std::string> > _physicalGroups;
  std::vector<std::vector<GEntity *> > _physicalGroupEntities;

public:
  contextWindow *win;

public:
  onelabContextWindow(int deltaFontSize = 0);
  ~onelabContextWindow();
  void show(int dim, int tag);
  void hide();
  void rebuild(bool deleteWidgets);
  void highlightSelection();
  void disableRedraw();
};

#endif
