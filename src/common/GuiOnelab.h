// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_ONELAB_H
#define GMSH_GUI_ONELAB_H

#include "GmshConfig.h"
#include "Form.h"

#include <functional>

#if defined(HAVE_ONELAB)

#include <string>

#include "onelab.h"

// What a ONELAB parameter does when someone changes it, shared by everything
// that shows one. A parameter is not only a value: its attributes may set a
// Gmsh option, ask the server to hide, reset or rewrite other parameters, and
// have the solver run again. All of that used to live in the widget callbacks
// of the FLTK module tree, where the per-entity dialog could not reach it --
// so the Dear ImGui interface only wrote the value back, and quietly did none
// of the rest.

namespace GuiOnelab {

  // What a ONELAB parameter comes out as: an enumeration when it names its
  // values, a switch when it is a yes or no, a button when it is a macro,
  // something one reads when it is read-only, and a value one types otherwise.
  //
  // It is said once and used twice, which is why it takes a way of fetching
  // the parameter rather than knowing where it lives: the per-entity window
  // holds its parameters by place, since a second entity of the same template
  // wants the same fields against other values, and the tree holds them by
  // name.
  typedef std::function<bool(onelab::number &)> getNumber;
  typedef std::function<bool(onelab::string &)> getString;
  Ui::Field numberField(const getNumber &get, const onelab::number &p);
  Ui::Field stringField(const getString &get, const onelab::string &p);


  // A "ServerAction" attribute: reset the database, the models and the views,
  // or a list of parameters. Returns whether the action was one it knows.
  bool serverAction(const std::string &action);

  // Everything that has to follow a change the user made: the Gmsh option the
  // parameter may stand for, the server actions its attributes ask for, the
  // parameter itself, the graphs if it may have changed one, and the check
  // the solver wants when it is set to follow.
  void changed(const onelab::number &before, onelab::number &after,
               bool graphs = false);
  void changed(const onelab::string &before, onelab::string &after,
               bool graphs = false);

  // What a string parameter drawn as a button does when it is pressed: the
  // macro it names -- a script to parse, a file to merge, or the ONELAB
  // action to set -- and then the same as above.
  void runMacro(onelab::string &p);

} // namespace GuiOnelab

#endif

#endif
