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

// The FLTK side of a described form: one widget per declared field, each
// bound to the variable the description points at. It knows the forms
// only as Form.h says them.

class dialogFltk {
public:
  dialogFltk() : _which(nullptr), _pane(0), _win(nullptr), _forcePane(false) {}
  ~dialogFltk();
  // build the window of the given dialog, or build it again when what it
  // shows depends on the model
  void build(const Ui::Form &form);
  // show it on the pane it is on, bringing the widgets up to date
  void show();
  void hide();
  bool shown() const;
  Fl_Window *window() { return _win; }
  // push the values and the enabling into the widgets
  void refresh();
  // the same for the fields that edit that option
  void optionChanged(const std::string &name);
  // the same, but building the window again first when what it offers has
  // changed shape rather than only value
  void reshape();
  // which pane is showing, by its label; a pane named before the window is
  // built is kept for it
  std::string pane() const;
  void setPane(const std::string &pane);

private:
  const Ui::Form *_which;
  Ui::Form _panel;
  int _pane;
  std::string _paneWanted;
  // the rank of a pane of the form being shown, or -1
  int _paneNamed(const std::string &label) const;
  // the shape the window was built for; see _signature()
  std::string _signatureBuilt;
  // the panes of this one are not tabbed and are longer than the window: they
  // are laid out inside a box that scrolls
  bool _formScrolls = false;
  // one of them holds a field that takes whatever is left of the form
  bool _formFills = false;
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
    Ui::Field field;
    Fl_Widget *widget;
    // the box its name is written on when it has buttons after it, and
    // those buttons: moved with it
    Fl_Widget *labelBox = nullptr;
    std::vector<Fl_Widget *> trailing;
    int pane; // -1 for the footer
    int index; // which field of its list
    int row; // within its pane
    // where the solver put it, in pixels from the top of its list: what
    // _relayout() moves it by when the lists above it fold away
    int top = 0;
    // the colour map widget sets this when it has been drawn on, which is
    // how it says the view has to be drawn again
    bool changed = false;
    // what a tree was last built from, so that it is only built again when
    // its lines really changed
    std::string was;
  };
  std::vector<bound> _fields;
  // which of them edit an option, by its name
  std::multimap<std::string, std::size_t> _byOption;
  void _refreshField(bound &b);
  // the title of each section of a form that is not tabbed
  std::vector<Fl_Widget *> _sections;
  // the rule under each section, when the description asks for one
  std::vector<Fl_Widget *> _separators;
  std::vector<Fl_Widget *> _buttons;
  std::vector<std::function<bool()> > _buttonsEnabled;
  // how wide the column of side fields is, 0 when there is none
  int _sideWidth = 0;
  // whether the buttons share the last line of the footer, see build()
  bool _mergedButtons = false;
  // how tall the column of side fields may be, for the list that fills it
  int _sideHeight = 0;
  // the bottom of the pane being laid out, for a field that fills it
  int _paneBottom = 0;
  // the widest this dialog has ever needed to be, see build()
  int _widestSeen = 0;
  // the button a section of a long form carries, and where it sits
  struct paneButton {
    Fl_Widget *widget;
    int pane;
    int top; // in pixels from the top of the pane, as for a bound field
  };
  // what each pane of a form that is not tabbed came to, in pixels, once
  // its fields were placed: what _relayout() stacks
  std::vector<int> _paneHeights;
  // where each pane's list was placed from, and how wide it may reach: what
  // _relayout() places it again with when a field of it is folded away
  struct paneRoom {
    int x, w, grid;
  };
  std::vector<paneRoom> _paneRooms;
  std::vector<paneButton> _paneButtons;
  // put the visible parts back where they belong and resize the window: a
  // pane that folds away must not cost a rebuild, which makes the window
  // blink and is unsafe from inside a widget's callback
  void _relayout();

  // the pane must only be forced when it has just been asked for: forcing it
  // at every refresh would undo the tab the user just clicked
  bool _forcePane;
  // `folded` makes a widget for every field, hidden or not, so that
  // _relayout() can show one later without building again
  void _addFields(const std::vector<Ui::Field> &fields, int x, int &y,
                  int w, int pane, int grid = 0, bool folded = false);
  // what the last list _addFields() placed came to, in pixels
  int _placedHeight = 0;
  // and what the footer came to, for _relayout()
  int _footerHeight = 0;
  static void _tabCallback(Fl_Widget *w, void *data);
  static void _fieldCallback(Fl_Widget *w, void *data);
  static void _buttonCallback(Fl_Widget *w, void *data);
  // for a dialog that watches something and has to be refreshed on a timer
  static void _tick(void *data);
};

// The dialogs, by name. A dialog is built the first time it is asked for;
// `create` false asks for it only if it already exists -- building a
// window while a group is open would make it a child of that group.
// `pane` is the one to open on when the dialog is built here and now.
dialogFltk *fltkDialog(const Ui::Form &which, bool create = true,
                       const std::string &pane = "");
// the dialog is gone: so is its window
void fltkDropDialog(const Ui::Form &which);
// every dialog that has been built, whatever it shows
void fltkEachDialog(const std::function<void(dialogFltk *)> &what);

// the interface is being taken down: from now on, hiding a dialog is not
// the user closing it, and whatever it undoes when it closes is not to be
// undone
void fltkDialogsClosingDown();

#endif
