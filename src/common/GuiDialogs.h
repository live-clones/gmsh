// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DIALOGS_H
#define GMSH_GUI_DIALOGS_H

#include <functional>
#include <string>
#include <vector>

#include "GmshConfig.h"
#include "Form.h"

// The dialogs of the graphical user interface, declared once and built by both
// interfaces, in the same spirit as the menus of GuiMenus.h. This one describes
// forms rather than menus: a dialog is a set of panes, a pane a list of
// labelled fields.
//
// The important difference with the menus is that the description *owns the
// values*. A field says where its value lives, both interfaces bind their
// widget to that same variable, and nothing has to be read back afterwards --
// which is what the interactive actions of GuiActionsGeo.cpp want, since they
// read their parameters again at every application.

namespace Dialog {

  // The vocabulary a form, a menu and a bar are said in belongs to
  // src/gui and to neither side; what is left here is the catalogue of
  // the ones Gmsh has.
  using namespace Ui;




  // which dialog: the numbering Gui::showDialog() uses
  enum {
    Elementary = 0,
    Physical,
    Transform,
    Mesh,
    Partition,
    HighOrder,
    Manipulator,
    Statistics,
    Clipping,
    Options,
    Gamepad,
    Visibility,
    Plugins,
    Fields,
    Classify,
    Shortcuts,
    CurrentOptions,
    About,
    OnelabContext,
    OptionValue,
    Arrow,
    History,
    NumDialogs
  };

  // The four context dialogs, the counterparts of src/fltk/contextWindow.cpp.
  Form elementaryContext();
  Form physicalContext();
  Form transformContext();
  Form meshContext();
  // the mesh partitioner, which is all options
  Form partition();
  // the high order tools, two sections one under the other
  Form highOrder();
  // the rotation, translation and scale of the view
  Form manipulator();
  // what the model is made of, and how good the mesh is
  Form statistics();
  // every option there is, laid out by hand in GuiOptions.cpp
  Form options();
  // which category it is showing, so that a menu can open it on the one it is
  // about rather than on whichever was last looked at
  int &optionsCategory();
  // and which post-processing view its View options are editing
  int &optionsView();
  // Show it on a view: the one given, or the one it is already on when that
  // is -1. The categories before the views are not for anyone else to count.
  // `pane` names the tab to open it on -- "Map" for the colour map of a view
  // -- and shows whichever was last looked at when it is empty.
  void showOptionsForView(int view, const std::string &pane = "");
  // the six planes that cut what is drawn
  Form clipping();
  // what of the model is drawn: the list of entities, by number, by picking,
  // and per graphic window
  Form visibility();
  // the plugins, what each of them takes, and what it is run on
  Form plugins();
  // the mesh size fields, what each of them takes, and which is the background
  Form fields();
  // turning a triangulation into a model: what to detect the edges on, which
  // of them to keep, and the reclassification itself
  Form classify();
  // show it, with the lines drawn: it is what one is about to work on
  void startClassify();
  // what the keyboard and the mouse do, and what the command line takes
  Form shortcuts();
  // what every option is worth right now, and what one may change it to
  Form currentOptions();
  // what this Gmsh is
  Form about();
  // The parameters a solver attached to one entity, instantiated from the
  // "ONELAB Context/<Dim> Template/..." parameters: what a double-click on an
  // entity opens when its double-click command is "ONELAB".
  Form onelabContext();
  // show it on that entity, highlighting what it is about
  void showOnelabContext(int dim, int tag);

  // One option, asked for on its own: the quick access menu of the status bar
  // opens it on the entries that take a value rather than a switch -- the
  // clipping factor, the mesh size factor, the number of intervals of a view.
  Form optionValue();
  // Show it on that option, between those bounds. `title` is what the window
  // is called; the value applies as it is typed, and `applyTo` "view" copies
  // it to every visible view, which is what the menu entries that act on the
  // views mean.
  void showOptionValue(const std::string &category, int index,
                       const std::string &name, const std::string &title,
                       double minimum, double maximum, double step,
                       const std::string &applyTo = "");
  // the shape of the arrows a vector view is drawn with
  Form arrow();
  // A command, with the ones given before it: the remote solver to start and
  // the pattern of the files to watch are both asked for that way. Which of
  // the two it is showing is set by the two calls below.
  Form history();
  void showRemoteCommand();
  void showWatchPattern();
  // show that window with a view picked, as the button of a view does
  void showPluginsForView(int view);
  // what the gamepad is doing and what each of its buttons and axes is for
  Form gamepad();

  // the one of the given index
  Form panel(int dialog);

  // The pane each dialog shows, shared so that the description and both
  // interfaces agree on it without anyone having to be told.
  int &currentPane(int dialog);
  // the transform dialog offers the mesh extrusion fields only when the action
  // that opened it extrudes
  bool &extrudeMode();
  // the physical dialog names the kind of entity and says whether the group is
  // being added to or removed from
  std::string &physicalType();
  bool &physicalRemove();

  // Show one of them on the given pane. This is what the modules tree calls;
  // the interface only has to raise the window, through Gui::showDialog().
  void show(int dialog, int pane);
  void showTransform(int pane, bool extrude);
  void showPhysical(const std::string &type, bool remove);

} // namespace Dialog

#endif
