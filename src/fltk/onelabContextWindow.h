// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_CONTEXT_WINDOW_H
#define ONELAB_CONTEXT_WINDOW_H

#include <list>
#include <memory>
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
  contextWindow(int w, int h, bool nonModal, const char *l = nullptr,
                int *offset = nullptr)
    : paletteWindow(w, h, nonModal, l, offset), _redraw(false)
  {
  }
  virtual int handle(int event);
  void enableRedraw() { _redraw = true; }
  void disableRedraw() { _redraw = false; }
};

class onelabContextWindow {
private:
  int _width, _height;
  // the widgets and the strings they show, and those retired, kept hidden
  // until the events are handled (see onelabGroup::_rebuildTree())
  std::list<std::string> _strings, _retiredStrings;
  // the labels of the menu of the entity and its physical groups
  std::list<std::string> _labels;
  std::vector<Fl_Widget *> _onelabWidgets, _retiredWidgets;
  // a rebuild asked for during a rebuild (hiding an edited input runs its
  // callback): done once the current one is over
  bool _rebuilding, _rebuildAgain;
  // false once this window is deleted, which the code still running after
  // events were processed (e.g. the GUI closed) reads
  std::shared_ptr<bool> _alive;
  void _rebuild();
  template <class T>
  void
  _addOnelabWidget(T &p, const std::string &pattern,
                   std::set<std::pair<std::string, Fl_Widget *> > &widgets);
  Fl_Choice *_choice;
  // the entity, and its physical groups, by their tags: the model may change
  // while the window is shown (a script reloaded, gmsh.model.occ.fragment)
  int _dim, _tag;
  std::string _name;
  std::vector<std::pair<int, std::string>> _physicalGroups;
  // the widgets of the parameters, with the codes of where they go
  struct placed {
    Fl_Widget *widget;
    int x, y;
  };
  std::vector<placed> _placed;

public:
  contextWindow *win;
  // places the widgets for a window w wide; returns its height
  int place(int w);

public:
  onelabContextWindow(int deltaFontSize = 0);
  ~onelabContextWindow();
  void show(int dim, int tag);
  void hide();
  void rebuild();
  // once the events are handled (see FlGui::_dispatch())
  void deleteRetiredWidgets();
  void highlightSelection();
  void disableRedraw();
};

#endif
