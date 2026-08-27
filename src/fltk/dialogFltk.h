// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DIALOG_FLTK_H
#define DIALOG_FLTK_H

#include <string>
#include <vector>

#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>

#include "GuiDialogs.h"

// The FLTK side of the dialog description of src/common/GuiDialogs.h: it builds
// the window that contextWindow.cpp used to build by hand, one widget per
// declared field, each bound to the variable the description points at.

class dialogFltk {
public:
  dialogFltk() : _which(-1), _win(nullptr), _forcePane(false) {}
  ~dialogFltk();
  // build the window of the given dialog, or build it again when what it shows
  // depends on the model
  void build(int dialog);
  // show it on the pane the description says, bringing the widgets up to date
  void show();
  void hide();
  bool shown() const;
  Fl_Window *window() { return _win; }
  // push the values and the enabling into the widgets
  void refresh();

private:
  int _which;
  Dialog::Panel _panel;
  // the shape the window was built for; see _signature()
  std::string _signatureBuilt;
  Fl_Window *_win;
  // the row of tabs, one per group of panes when the dialog has groups
  std::vector<Fl_Tabs *> _tabs;
  std::vector<Fl_Group *> _groups;
  // the outer row, when there is one, and what each of its tabs holds
  Fl_Tabs *_outerTabs = nullptr;
  std::vector<Fl_Group *> _outerGroups;
  std::vector<int> _firstOfGroup;
  // a widget, the field it edits, and where it sits in the form
  struct bound {
    Dialog::Field field;
    Fl_Widget *widget;
    int pane; // -1 for the footer
    int row; // within its pane
  };
  std::vector<bound> _fields;
  // the title of each section of a form that is not tabbed
  std::vector<Fl_Widget *> _sections;
  // the rule under each section, when the description asks for one
  std::vector<Fl_Widget *> _separators;
  std::vector<Fl_Widget *> _buttons;
  // how wide the column of side fields is, 0 when there is none
  int _sideWidth = 0;
  // whether the buttons share the last line of the footer, see build()
  bool _mergedButtons = false;
  // how tall the column of side fields may be, for the list that fills it
  int _sideHeight = 0;
  // the button a section of a long form carries, and where it sits
  struct paneButton {
    Fl_Widget *widget;
    int pane;
    int row;
  };
  std::vector<paneButton> _paneButtons;
  // Put the visible parts back where they belong and resize the window. A pane
  // that folds away must not cost a rebuild: destroying the window makes it
  // blink and come back somewhere else, and deleting widgets from inside the
  // callback of one of them is how FLTK crashes.
  void _relayout();

  // the pane must only be forced when it has just been asked for: forcing it
  // at every refresh would undo the tab the user just clicked
  bool _forcePane;
  void _addFields(const std::vector<Dialog::Field> &fields, int x, int &y,
                  int w, int pane, int grid = 0);
  static void _tabCallback(Fl_Widget *w, void *data);
  static void _fieldCallback(Fl_Widget *w, void *data);
  static void _buttonCallback(Fl_Widget *w, void *data);
};

// The dialogs, indexed as Dialog::Elementary and friends. A dialog is built the
// first time it is asked for; `create` false asks for it only if it already
// exists, which is what the callers that merely want to know whether it is up
// need -- building a window while a group is open would make it a child of that
// group.
dialogFltk *fltkDialog(int which, bool create = true);

#endif
