// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DIALOG_H
#define GMSH_GUI_DIALOG_H

#include <string>

#include "Form.h"

// a window described once and shown by whichever interface is up: its Ui::Form
// is built by build() and kept until the structure changes
class GuiDialog {
public:
  GuiDialog() {}
  virtual ~GuiDialog();
  void show();
  void hide();
  bool visible() const;
  // the interface reads the values again: what a field is worth, its bounds,
  // its list
  void reload();
  // the interface makes its widgets again: the shape changed
  void rebuild();

protected:
  virtual Ui::Form build() = 0;
  // read from the model before it is looked at
  virtual void load() {}
  const Ui::Form &form() const { return _form; }
  void refill();

private:
  Ui::Form _form;
  // a callback of the one before may be what asked for the new one
  Ui::Form _retired;
};

// a pane is named by its label
class GuiTabbed : public GuiDialog {
public:
  void show(const std::string &pane = "");
  // kept by the interface: a click on a tab changes it
  std::string pane() const;

protected:
  void setPane(const std::string &pane);
};

#endif
