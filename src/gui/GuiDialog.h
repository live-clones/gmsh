// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DIALOG_H
#define GMSH_GUI_DIALOG_H

#include <string>

#include "Form.h"

// A window of the application, described once and shown by whichever
// interface is up. What the interface sees of it is its Ui::Form, built by
// build() and kept until the structure changes; what the rest of Gmsh sees
// is this.
class GuiDialog {
public:
  explicit GuiDialog(bool tabbed = false) : _tabbed(tabbed) {}
  virtual ~GuiDialog();
  // load(), build(), then the interface raises it
  void show();
  void hide();
  bool visible() const;
  // load(), then the interface reads the values again
  void reload();
  // load(), build(), then the interface makes its widgets again
  void rebuild();

protected:
  // the description: the panes, the fields, what they are bound to
  virtual Ui::Form build() = 0;
  // what it reads from the model before it is looked at: a copy of the
  // options it edits, counts it shows
  virtual void load() {}
  const Ui::Form &form() const { return _form; }
  void refill();

private:
  Ui::Form _form;
  // the one before: a callback of it may be what asked for the new one, and
  // it must outlive that call
  Ui::Form _retired;
  bool _tabbed;
};

// one pane at a time, under a row of tabs; a pane is named by its label
class GuiTabbed : public GuiDialog {
public:
  GuiTabbed() : GuiDialog(true) {}
  // on that pane, or on the one it was left on when none is named
  void show(const std::string &pane = "");
  // which pane is showing, which the interface keeps since a click on a tab
  // is what changes it
  std::string pane() const;

protected:
  void setPane(const std::string &pane);
};

#endif
