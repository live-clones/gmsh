// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_OPTIONS_H
#define GMSH_GUI_OPTIONS_H

#include <map>
#include <string>
#include <vector>

#include "GuiDialog.h"

// laid out by hand in GuiOptions.cpp
class GuiOptions : public GuiTabbed {
public:
  int category = 0;
  int view = 0;
  using GuiTabbed::show;
  // -1 is the view it is already on; pane names the tab, "Map" for the colour
  // map
  void showForView(int view, const std::string &pane = "");
  // the view shown, and the others chosen with it in the list: what is done to
  // the one is done to them all
  std::vector<int> editedViews() const;
  // after `option` of view `from` was written -- a number 'n', a text 't', a
  // colour 'c', or 'm' its colour map -- the views chosen with it follow, as
  // far as PostProcessing.Link says
  void passOn(int from, char kind, const std::string &option = "");

protected:
  Ui::Form build() override;

private:
  // the other views chosen, beside the one shown
  std::vector<int> _alsoViews;
  // what the lines of the list were just said to be, until the list says it
  // has done
  std::map<int, bool> _picked;
  void _pickingDone();
};

#endif
