// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_ACTIONS_H
#define ONELAB_ACTIONS_H

#include <string>

class Fl_Widget;

// The ONELAB actions of the FLTK graphical user interface, as the Check and
// Run buttons and the gear menu do them (the clients read the one under way in
// ONELAB/Action), on onelabUtils::onelabLoop, the stepper shared with the
// batch mode and the web page: the model checked (the script read again with
// the parameters; always, even if nothing changed, when asked), computed (the
// loops over the parameters run, then the solvers), the database reset then
// checked, the solvers initialized (when one is added), the tree and the
// graphs refreshed, the run stopped or the solvers killed, the database saved
// or loaded, and a reload asked by an outside code
void onelabCheck(bool always = false);
void onelabCompute();
void onelabReset();
void onelabInitialize();
void onelabRefresh();
void onelabStop();
void onelabKill();
void onelabSaveDatabase();
void onelabLoadDatabase();
void onelabReload();
// an action by its name ("check", "compute", ...), as the custom Run button
// of a model asks for it, and the callback of that button, whose data is the
// name
void onelabAction(const std::string &action);
void onelab_action_cb(Fl_Widget *w, void *data);
// the solver of index num added to the tree, then the model checked (or, if
// num is negative, the list made again and the tree refreshed); the database
// reset instead when a solver is to be launched at startup
void selectSolver(int num);
// whether a solver runs (then said in the messages): what changes the
// solvers or the model must wait
bool solverBusy();
// the graphs of the parameters made again, and the views they changed shown
void onelabUpdateGraphs();

#endif
