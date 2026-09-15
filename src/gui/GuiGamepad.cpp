// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "Gui.h"
#include "GuiDeclare.h"
#include "Context.h"
#include "GamePad.h"

// The gamepad: what the pad is doing -- a light per button and per axis,
// which the panel watches rather than holds -- and what each of its
// buttons and axes is made to do.

namespace {

  using namespace Ui;
  using namespace Declare;

  namespace {

    // a light that says whether a button or an axis is being used: read and
    // never set, drawn dead
    Field light(const std::string &label, std::function<double()> what)
    {
      Field f;
      f.kind = Check;
      f.label = label;
      f.readNumber = what;
      f.enabled = []() { return false; };
      f.packed = true;
      f.sameRow = true;
      return f;
    }

    // one of the numbers that say which button or axis does what
    Field mapped(const std::string &label, int *value)
    {
      Field f;
      f.kind = Integer;
      f.label = label;
      f.widthEm = 2.5;
      return bind(f, value);
    }

  } // namespace

  static Form describeGamepad()
  {
    Form p;
    p.title = "Gamepad Configuration Tool (in work)";
    p.tabbed = false;
    GamePad *pad = CTX::instance()->gamepad;
    if(!pad) return p;
    // the lights follow the pad, which nothing else tells us about
    p.refreshEvery = pad->frequency > 0. ? pad->frequency : .1;

    Pane pane;
    pane.columns = 2;
    pane.fields.push_back(says([]() { return std::string("Gamepad buttons:"); }));
    for(int i = 0; i < 13 && i < GP_BUTTONS; i++) {
      Field f = light(std::to_string(i),
                      [pad, i]() { return pad->button[i] ? 1. : 0.; });
      if(!i) f.sameRow = false;
      pane.fields.push_back(f);
    }
    pane.fields.push_back(says([]() { return std::string("Gamepad axes:"); }));
    for(int i = 0; i < 9 && i < GP_AXES; i++) {
      Field f = light(std::to_string(i),
                      [pad, i]() { return pad->axe[i] != 0. ? 1. : 0.; });
      if(!i) f.sameRow = false;
      pane.fields.push_back(f);
    }
    pane.fields.push_back(says([]() { return std::string("Preferences:"); }));

    // the axes on the left, the buttons on the right
    const char *const axes[] = {"head right/left with button (*)",
                                "head up/down with button (*)",
                                "turn left/right",
                                "for/backward or up/down ",
                                "move aside left/right",
                                "move up/down",
                                "speed up/slow down"};
    const char *const buttons[] = {"1:1",
                                   "permute axes",
                                   "reset/invers up axis",
                                   "change nav-mode",
                                   "(*) move head",
                                   " ",
                                   "walk / swimm",
                                   " ",
                                   "1:1 ; reset speed"};
    Field left = says([]() { return std::string("Action Axes:"); });
    Field right = says([]() { return std::string("Action buttons:"); });
    right.sameRow = true;
    pane.fields.push_back(left);
    pane.fields.push_back(right);
    for(int i = 0; i < 9; i++) {
      if(i < 7)
        pane.fields.push_back(mapped(axes[i], &pad->axe_map[i]));
      else
        // nothing on the left of these two: the buttons outnumber the axes
        pane.fields.push_back(says([]() { return std::string(""); }));
      Field f = mapped(buttons[i], &pad->button_map[i]);
      f.sameRow = true;
      pane.fields.push_back(f);
    }
    p.panes.push_back(pane);
    return p;
  }

} // namespace

Ui::Form GuiGamepad::build()
{
  Ui::Form f = describeGamepad();
  f.id = "gamepad";
  return f;
}


#endif
