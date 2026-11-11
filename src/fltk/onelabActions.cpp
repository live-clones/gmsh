// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/fl_ask.H>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "graphicWindow.h"
#include "fileDialogs.h"
#include "onelabGroup.h"
#include "onelabActions.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "OS.h"
#include "StringUtils.h"
#include "onelabUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"
#include "gmshLocalNetworkClient.h"

// What the Check and Run buttons and the gear menu of the FLTK graphical user
// interface do (see onelabActions.h): the loop of an action on the model, on
// onelabUtils::onelabLoop, with what the interface shows between its steps.

void onelabUpdateGraphs()
{
  if(onelabUtils::updateGraphs() && FlGui::available()) {
    FlGui::instance()->updateViews(true);
    drawContext::global()->draw();
  }
}

bool solverBusy()
{
  if(!FlGui::available() || !FlGui::instance()->onelab ||
     !FlGui::instance()->onelab->isBusy())
    return false;
  Msg::Info("I'm busy! Ask me that later...");
  return true;
}

void selectSolver(int num)
{
  if(!FlGui::available() || !FlGui::instance()->onelab) return;
  // choosing a solver deletes the clients, among which the one running; one
  // asked for by a file opened meanwhile is not launched by a later one
  if(solverBusy()) {
    CTX::instance()->launchSolverAtStartup = -1;
    return;
  }

  if(num >= 0) {
    std::string name = opt_solver_name(num, GMSH_GET, "");
    std::string exe = opt_solver_executable(num, GMSH_GET, "");
    std::string host = opt_solver_remote_login(num, GMSH_GET, "");
    FlGui::instance()->onelab->addSolver(name, exe, host, num);
  }
  else {
    FlGui::instance()->onelab->rebuildSolverList();
  }

  if(CTX::instance()->solver.autoLoadDatabase) {
    std::string db = onelabUtils::dbFileName();
    if(!StatFile(db)) {
      onelabUtils::loadDb(db);
      CTX::instance()->launchSolverAtStartup = -1;
    }
  }

  if(CTX::instance()->launchSolverAtStartup >= 0) {
    onelabReset();
    onelabUtils::setFirstComputationFlag(true);
  }
  else if(num >= 0)
    onelabCheck();
  else
    onelabRefresh();
  // (the GUI may have been closed meanwhile)
  if(FlGui::available()) FlGui::instance()->onelab->updateGearMenu();

  CTX::instance()->launchSolverAtStartup = -1;
}

// the action under way, told to the clients (ONELAB/Action); false once the
// GUI is closed (by the events processed during a run that called this one),
// which FlGui::instance() would build again
static bool onelabStart(const std::string &action)
{
  if(!FlGui::available()) return false;
  onelab::string o("ONELAB/Action", action);
  o.setVisible(false);
  o.setNeverChanged(true);
  o.setAttribute("Persistent", "1");
  onelab::server::instance()->set(o);
  return true;
}

// The loop of an action on the model (see onelabUtils::onelabLoop), with what
// the FLTK interface shows between its steps, and the Stop button, which ends
// it after the step under way
static void onelabRun(const std::string &action)
{
  if(solverBusy()) return;
  // the rest reads the project again or meshes it: not during another
  // operation on the model
  if(modelBusy()) return;

  // custom button behavior
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "ONELAB/Button");
  if(ps.size() && ps[0].getValues().size() == 2) {
    // we have a custom onelab "Run" button, we're done
    return;
  }

  onelabGroup *g = FlGui::instance()->onelab;
  g->setRunState(onelabGroup::Running);
  bool compute = (action == "compute");
  onelabUtils::onelabLoop loop(action);
  while(true) {
    if(loop.runGmsh()) drawContext::global()->draw();
    // the GUI may have been closed while the events were processed (not
    // FlGui::instance(), which would build it again)
    if(!FlGui::available()) return;
    if(compute) g->checkForErrors("Gmsh");
    if(g->stop()) break;
    for(onelab::client *c : loop.solvers()) {
      loop.runSolver(c);
      if(!FlGui::available()) return;
      if(compute) g->checkForErrors(c->getName());
      if(g->stop()) break;
    }
    bool more = loop.nextPass(!g->stop());
    if(loop.graphsChanged()) {
      FlGui::instance()->updateViews(true);
      if(!FlGui::available()) return;
      drawContext::global()->draw();
    }
    if(action != "initialize") {
      FlGui::instance()->rebuildTree();
      if(!FlGui::available()) return;
    }
    if(!more) break;
  }
  if(loop.finish()) {
    // (the archived files renamed in the tree)
    if(!FlGui::available()) return;
    FlGui::instance()->rebuildTree();
    if(!FlGui::available()) return;
  }

  g->stop(false);
  g->setRunState(onelabGroup::Idle);

  Msg::StatusBar(true, "Done");

  if(action != "initialize") g->show();
}

void onelabCheck(bool always)
{
  std::string action = always ? "check_always" : "check";
  if(onelabStart(action)) onelabRun(action);
}

void onelabCompute()
{
  if(onelabStart("compute")) onelabRun("compute");
}

void onelabInitialize()
{
  if(onelabStart("initialize")) onelabRun("initialize");
}

void onelabReset()
{
  if(!onelabStart("reset")) return;
  if(solverBusy() || modelBusy()) return;
  onelabUtils::resetDb(true);
  onelabRun("check");
}

// a reload recorded in ONELAB/Action, for the clients: the FLTK interface reads
// the script again itself (reloadScript() in fileActions.cpp)
void onelabReload() { onelabStart("reload"); }

void onelabRefresh()
{
  if(!onelabStart("refresh")) return;
  onelabUpdateGraphs();
  FlGui::instance()->rebuildTree();
}

void onelabStop()
{
  if(!onelabStart("stop")) return;
  FlGui::instance()->onelab->stop(true);
  FlGui::instance()->onelab->setRunState(onelabGroup::Stopping);
  for(auto it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++) {
    onelab::string o((*it)->getName() + "/Action", "stop");
    o.setVisible(false);
    o.setNeverChanged(true);
    onelab::server::instance()->set(o);
  }
}

void onelabKill()
{
  if(!onelabStart("kill")) return;
  FlGui::instance()->onelab->stop(true);
  for(auto it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++)
    (*it)->kill();
}

void onelabSaveDatabase()
{
  if(!onelabStart("save")) return;
  std::string fileName = "onelab.db";

  // special handling for metamodels: add user defined tag, if any
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "0Metamodel/9Tag");
  if(ps.size() && ps[0].getValue().size()) {
    fileName.assign("onelab_" + ps[0].getValue() + ".db");
  }

  // special handling for metamodels: save db in "restore" mode"
  double restoreMode = 0.;
  std::vector<onelab::number> pn;
  onelab::server::instance()->get(pn, "0Metamodel/9Use restored solution");
  if(pn.size()) {
    restoreMode = pn[0].getValue();
    pn[0].setValue(2); // special value
    onelab::server::instance()->set(pn[0]);
  }

  std::string db;
  db.assign(SplitFileName(GModel::current()->getFileName())[0] + fileName);
  if(fileChooser(FILE_CHOOSER_CREATE, "Save", "*.db", db.c_str())) {
    if(!restoreMode) onelabUtils::archiveSolutionFiles(fileChooserGetName(1));
    onelabUtils::saveDb(fileChooserGetName(1));
  }

  // special handling for metamodels: switch back to normal "run" mode"
  onelab::server::instance()->get(pn, "0Metamodel/9Use restored solution");
  if(pn.size()) {
    pn[0].setValue(0);
    onelab::server::instance()->set(pn[0]);
  }
  onelabRun("check");
}

void onelabLoadDatabase()
{
  if(!onelabStart("load")) return;
  if(solverBusy() || modelBusy()) return;
  std::string db =
    SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
  if(fileChooser(FILE_CHOOSER_SINGLE, "Load", "*.db", db.c_str()))
    onelabUtils::loadDb(fileChooserGetName(1));
  onelabRun("check");
}

void onelabAction(const std::string &action)
{
  if(action == "check")
    onelabCheck();
  else if(action == "check_always")
    onelabCheck(true);
  else if(action == "compute")
    onelabCompute();
  else if(action == "reset")
    onelabReset();
  else if(action == "initialize")
    onelabInitialize();
  else if(action == "reload")
    onelabReload();
  else if(action == "refresh")
    onelabRefresh();
  else if(action == "stop")
    onelabStop();
  else if(action == "kill")
    onelabKill();
  else if(action == "save")
    onelabSaveDatabase();
  else if(action == "load")
    onelabLoadDatabase();
  else if(onelabStart(action))
    onelabRun(action);
}

void onelab_action_cb(Fl_Widget *w, void *data)
{ onelabAction((const char *)data); }
