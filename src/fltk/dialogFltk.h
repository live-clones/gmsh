// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DIALOG_FLTK_H
#define DIALOG_FLTK_H

#include <functional>
#include <map>
#include <string>
#include <vector>

#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>

#include "Form.h"
#include "Layout.h"

// the FLTK side of a described form: one widget per field, bound to the
// variable the description points at

class dialogFltk {
public:
  dialogFltk() : _which(nullptr), _win(nullptr), _forcePane(false) {}
  ~dialogFltk();
  void build(const Ui::Form &form);
  void show();
  void hide();
  bool shown() const;
  Fl_Window *window() { return _win; }
  void refresh();
  void optionChanged(const std::string &name);
  // building the window again first: the shape changed
  void reshape();
  // a pane named before the window is built is kept for it
  std::string pane() const;
  void setPane(const std::string &pane);

private:
  const Ui::Form *_which;
  Ui::Form _panel;
  // the pane showing, by its label
  std::string _pane;
  std::string _paneWanted;
  std::string _signatureBuilt;
  Fl_Window *_win;
  struct paneGroup {
    std::string label;
    Fl_Group *group;
    Fl_Tabs *tabs;
    // the placed item the tabs are, by index: a reload moves the items
    std::size_t index;
  };
  std::vector<paneGroup> _panes;
  // where the solver put everything, in em from the top left of the window's
  // margin; the group or rule made for an item, by its index
  std::vector<Ui::PlacedItem> _placed;
  // the list beside the rest is alone in its column, see Ui::aloneInColumn
  bool _aloneInColumn = false;
  std::vector<Fl_Widget *> _groups;
  // what was folded away when the widgets were last placed
  std::string _folding;
  Ui::Placement _placement(const Ui::Form &p);
  bool _relayout(bool always);
  // the windows inside a group shown as their panes are
  void _showWindows(Fl_Group *group);
  struct bound {
    Ui::Field field;
    Fl_Widget *widget;
    // the box its name is written on when it has buttons after it, moved with
    // it
    Fl_Widget *labelBox = nullptr;
    std::vector<Fl_Widget *> trailing;
    // which placed item, so that a reload reads the field again from a form
    // of the same shape
    std::size_t index = 0;
    // set by the colour map widget when it has been drawn on
    bool changed = false;
    // so that a tree is only built again when its lines changed
    std::string was;
  };
  std::vector<bound> _fields;
  std::multimap<std::string, std::size_t> _byOption;
  void _refreshField(bound &b);
  // keeps the widest width asked for, so that it sits still
  int _widestSeen = 0;
  // forced only when just asked for, or it would undo the tab the user clicked
  bool _forcePane;
  void _addItem(std::size_t index, Fl_Group *into);
  void _place(bound &b, const Ui::PlacedItem &p);
  static void _tabCallback(Fl_Widget *w, void *data);
  static void _fieldCallback(Fl_Widget *w, void *data);
  static void _buttonCallback(Fl_Widget *w, void *data);
  static void _tick(void *data);
};

// create false asks for a dialog only if it exists: a window built while a
// group is open would be a child of it
dialogFltk *fltkDialog(const Ui::Form &which, bool create = true,
                       const std::string &pane = "");
void fltkDropDialog(const Ui::Form &which);
void fltkEachDialog(const std::function<void(dialogFltk *)> &what);

// taken down: hiding a dialog is not the user closing it, and nothing is undone
void fltkDialogsClosingDown();

#endif
