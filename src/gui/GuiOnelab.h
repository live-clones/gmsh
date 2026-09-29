// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_ONELAB_H
#define GMSH_GUI_ONELAB_H

#include "GmshConfig.h"
#include "GuiDialog.h"

#include <functional>
#include <string>
#include <utility>
#include <vector>

class GEntity;

#if defined(HAVE_ONELAB)

#include <string>

#include "onelab.h"

// what a ONELAB parameter does when someone changes it: its attributes may set
// a Gmsh option, ask the server to hide, reset or rewrite others, and have the
// solver run again

namespace GuiOnelab {

  // takes a way of fetching the parameter rather than knowing where it lives:
  // the per-entity window holds its parameters by place, the tree by name
  typedef std::function<bool(onelab::number &)> getNumber;
  typedef std::function<bool(onelab::string &)> getString;
  Ui::Field numberField(const getNumber &get, const onelab::number &p);
  Ui::Field stringField(const getString &get, const onelab::string &p);


  // a "ServerAction" attribute; whether the action was one it knows
  bool serverAction(const std::string &action);

  // everything that follows a change: the option, the server actions, the
  // graphs, the check the solver wants
  void changed(const onelab::number &before, onelab::number &after,
               bool graphs = false);
  void changed(const onelab::string &before, onelab::string &after,
               bool graphs = false);

  // the macro a button names: a script to parse, a file to merge, or the ONELAB
  // action to set
  void runMacro(onelab::string &p);

} // namespace GuiOnelab

#endif

// what a double-click on an entity opens when its double-click command is
// "ONELAB"
class GuiOnelabContext : public GuiDialog {
  // the entity, or one of the physical groups it belongs to
  int dim = -1, tag = 0;
  int which = 0; // 0 for the entity itself, then one per physical group
  std::vector<std::pair<int, std::string> > groups;
  std::vector<std::vector<GEntity *> > groupEntities;
  // the fields are bound to a place in this list rather than to a name: a
  // second entity made from the same template does not rebuild the window
  std::vector<std::string> names;
  void look();
  void entries(std::vector<std::string> &labels, std::vector<int> &values);
  void highlight();
  void instantiate();
#if defined(HAVE_ONELAB)
  bool number(int i, onelab::number &p);
  bool string(int i, onelab::string &p);
#endif

public:
  using GuiDialog::show;
  void show(int dim, int tag);

protected:
  Ui::Form build() override;
};

#endif
