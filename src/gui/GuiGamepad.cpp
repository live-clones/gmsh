// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <string>
#include <vector>

#include "GuiGamepad.h"
#include "GuiDeclare.h"
#include "Context.h"
#include "GamePad.h"

// a light per button and per axis, which the panel watches rather than holds,
// and what each is made to do

using namespace Ui;
using namespace Declare;

Form GuiGamepad::build()
{
  GamePad *pad = CTX::instance()->gamepad;
  Form f = {"gamepad", "Gamepad Configuration Tool (in work)", Item()};
  if(!pad) return f;
  f.refreshEvery = pad->frequency > 0. ? pad->frequency : .1;

  auto dead = []() { return false; };
  std::vector<Item> buttons, axes;
  for(int i = 0; i < 13 && i < GP_BUTTONS; i++)
    buttons.push_back(
      check(std::to_string(i), [pad, i]() { return pad->button[i] != 0; })
        .enabledWhen(dead)
        .tight());
  for(int i = 0; i < 9 && i < GP_AXES; i++)
    axes.push_back(
      check(std::to_string(i), [pad, i]() { return pad->axe[i] != 0.; })
        .enabledWhen(dead)
        .tight());

  const char *const axis[] = {"head right/left with button (*)",
                              "head up/down with button (*)",
                              "turn left/right",
                              "for/backward or up/down ",
                              "move aside left/right",
                              "move up/down",
                              "speed up/slow down"};
  const char *const button[] = {"1:1",
                                "permute axes",
                                "reset/invers up axis",
                                "change nav-mode",
                                "(*) move head",
                                " ",
                                "walk / swimm",
                                " ",
                                "1:1 ; reset speed"};
  std::vector<Item> lines = {label("Gamepad buttons:"), hbox(buttons),
                             label("Gamepad axes:"), hbox(axes),
                             label("Preferences:"),
                             hbox({label("Action Axes:"), label("Action buttons:")})};
  for(int i = 0; i < 9; i++)
    lines.push_back(hbox(
      {i < 7 ? Item(integer(axis[i], &pad->axe_map[i]).sized(2.5)) :
               Item(label("")),
       integer(button[i], &pad->button_map[i]).sized(2.5)}));
  f.content = grid(lines);
  return f;
}

#endif
