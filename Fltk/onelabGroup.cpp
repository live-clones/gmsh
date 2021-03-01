// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl.H>
#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <fstream>
#include <streambuf>
#include <ctype.h>
#include "GmshMessage.h"
#include "onelab.h"
#include "gmshLocalNetworkClient.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_ask.H>
#include "inputRange.h"
#include "outputRange.h"
#include "solverButton.h"
#include "viewButton.h"
#include "paletteWindow.h"
#include "graphicWindow.h"
#include "fileDialogs.h"
#include "onelabGroup.h"
#include "GmshGlobal.h"
#include "FlGui.h"
#include "Context.h"
#include "GModel.h"
#include "GmshDefines.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "onelabUtils.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "treeIcons.h"

// This file contains the Gmsh/FLTK specific parts of the ONELAB
// interface. You'll need to reimplement this if you plan to build a different
// ONELAB server.

void solver_cb(Fl_Widget *w, void *data)
{
  if(!FlGui::instance()->onelab) return;

  int num = (intptr_t)data;
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
    std::vector<std::string> split =
      SplitFileName(GModel::current()->getFileName());
    std::string db = split[0] + split[1] + ".db";
    if(!StatFile(db)) {
      onelabUtils::loadDb(db);
      CTX::instance()->launchSolverAtStartup = -1;
    }
  }

  if(FlGui::instance()->onelab->isBusy())
    FlGui::instance()->onelab->show();
  else {
    if(CTX::instance()->launchSolverAtStartup >= 0) {
      onelab_cb(nullptr, (void *)"reset");
      onelabUtils::setFirstComputationFlag(true);
    }
    else if(num >= 0)
      onelab_cb(nullptr, (void *)"check");
    else
      onelab_cb(nullptr, (void *)"refresh");
    FlGui::instance()->onelab->updateGearMenu();
  }

  CTX::instance()->launchSolverAtStartup = -1;
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;

  std::string action((const char *)data);

  onelab::string o("ONELAB/Action", action);
  o.setVisible(false);
  o.setNeverChanged(true);
  o.setAttribute("Persistent", "1");
  onelab::server::instance()->set(o);

  if(action == "refresh") {
    onelabUtils::updateGraphs();
    FlGui::instance()->rebuildTree(true);
    return;
  }

  if(action == "stop") {
    FlGui::instance()->onelab->stop(true);
    FlGui::instance()->onelab->setButtonMode("", "kill");
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::string o((*it)->getName() + "/Action", "stop");
      o.setVisible(false);
      o.setNeverChanged(true);
      onelab::server::instance()->set(o);
    }
    return;
  }

  if(action == "kill") {
    FlGui::instance()->onelab->stop(true);
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++)
      (*it)->kill();
    return;
  }

  if(action == "save") {
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
    action = "check";
    // return;
  }

  if(FlGui::instance()->onelab->isBusy()) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }

  if(action == "load") {
    std::string db =
      SplitFileName(GModel::current()->getFileName())[0] + "onelab.db";
    if(fileChooser(FILE_CHOOSER_SINGLE, "Load", "*.db", db.c_str()))
      onelabUtils::loadDb(fileChooserGetName(1));
    action = "check";
  }

  if(action == "reset") {
    onelabUtils::resetDb(true);
    action = "check";
  }

  // custom button behavior
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "ONELAB/Button");
  if(ps.size() && ps[0].getValues().size() == 2) {
    // we have a custom onelab "Run" button, we're done
    return;
  }

  Msg::ResetErrorCounter();

  FlGui::instance()->onelab->setButtonMode("", "stop");

  if(action == "compute") onelabUtils::initializeLoops();

  do { // enter loop

    // run Gmsh client for non-metamodels
    if(onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh))
      drawContext::global()->draw();

    if(action == "compute") FlGui::instance()->onelab->checkForErrors("Gmsh");
    if(FlGui::instance()->onelab->stop()) break;

    // iterate over all other clients (there should normally only be one)
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::client *c = *it;
      if(c->getName() == "Gmsh" || // local Gmsh client
         c->getName() ==
           "Listen" || // unknown client connecting through "-listen"
         c->getName() == "GmshRemote" || // distant post-processing Gmsh client
         c->getName().find("NoAutoRun") !=
           std::string::npos) // client name contains "NoAutoRun"
        continue;
      if(action != "initialize") onelabUtils::guessModelName(c);
      onelab::string o(c->getName() + "/Action", action);
      o.setVisible(false);
      o.setNeverChanged(true);
      onelab::server::instance()->set(o);
      // we should skip the computation here if no parameter has changed for the
      // solver:
      //
      // if(action != "compute" ||
      // onelab::server::instance()->getChanged(c->getName()))
      c->run();
      if(action == "compute") {
        // after computing with this solver, mark the parameters as unchanged
        // for this solver
        onelab::server::instance()->setChanged(0, c->getName());
        FlGui::instance()->onelab->checkForErrors(c->getName());
      }
      if(FlGui::instance()->onelab->stop()) break;
    }

    if(action != "initialize") {
      onelabUtils::updateGraphs();
      FlGui::instance()->rebuildTree(action == "compute");
    }

  } while(action == "compute" && !FlGui::instance()->onelab->stop() &&
          onelabUtils::incrementLoops());

  if(action == "compute" && (CTX::instance()->solver.autoSaveDatabase ||
                             CTX::instance()->solver.autoArchiveOutputFiles)) {
    std::vector<std::string> split =
      SplitFileName(GModel::current()->getFileName());
    std::string db = split[0] + split[1] + ".db";
    if(CTX::instance()->solver.autoArchiveOutputFiles)
      onelabUtils::archiveOutputFiles(db);
    if(CTX::instance()->solver.autoSaveDatabase) onelabUtils::saveDb(db);
  }

  FlGui::instance()->onelab->stop(false);
  FlGui::instance()->onelab->setButtonMode("check", "compute");

  Msg::StatusBar(true, "Done");

  if(action != "initialize") FlGui::instance()->onelab->show();
}

void onelab_option_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string what((const char *)data);
  double val = ((Fl_Menu_ *)w)->mvalue()->value() ? 1. : 0.;
  if(what == "save")
    CTX::instance()->solver.autoSaveDatabase = val;
  else if(what == "load")
    CTX::instance()->solver.autoLoadDatabase = val;
  else if(what == "archive")
    CTX::instance()->solver.autoArchiveOutputFiles = val;
  else if(what == "check") {
    CTX::instance()->solver.autoCheck = val;
    FlGui::instance()->onelab->setButtonVisibility();
  }
  else if(what == "mesh")
    CTX::instance()->solver.autoMesh = val ? 2 : 0;
  else if(what == "merge")
    CTX::instance()->solver.autoMergeFile = val;
  else if(what == "show")
    CTX::instance()->solver.autoShowViews = val ? 2 : 0;
  else if(what == "step")
    CTX::instance()->solver.autoShowLastStep = val;
  else if(what == "invisible") {
    CTX::instance()->solver.showInvisibleParameters = val;
    FlGui::instance()->onelab->rebuildTree(true);
  }
}

static void onelab_choose_executable_cb(Fl_Widget *w, void *data)
{
  onelab::localNetworkClient *c = (onelab::localNetworkClient *)data;
  std::string pattern = "*";
#if defined(WIN32)
  pattern += ".exe";
#endif

  std::string exe = "";

  if(!w) { // we entered here automatically because no executable is given

    // try to find an executable automatically (this is really useful for
    // beginners)
    std::string gmshPath = SplitFileName(CTX::instance()->exeFileName)[0];
    if(gmshPath.size()) {
      std::string name = c->getName();
      for(std::size_t i = 0; i < name.size(); i++) name[i] = tolower(name[i]);
      std::string path1 = gmshPath + name;
      std::string path2 = gmshPath + "data/" + name;
#if defined(WIN32)
      path1 += ".exe";
      path2 += ".exe";
#endif
      if(!StatFile(path1))
        exe = path1;
      else if(!StatFile(path2))
        exe = path2;
      if(exe.size())
        Msg::Info("Automatically found %s executable: %s", c->getName().c_str(),
                  exe.c_str());
    }

    if(exe.empty()) {
      const char *o = fl_close;
      fl_close = "OK";
      fl_message(
        "This appears to be the first time you are trying to run %s.\n\n"
        "Please select the path to the executable.",
        c->getName().c_str());
      fl_close = o;
    }
  }

  if(exe.empty()) {
    const char *old = nullptr;
    if(c->getExecutable().size()) old = c->getExecutable().c_str();
    std::string title = "Choose location of " + c->getName() + " executable";
    if(fileChooser(FILE_CHOOSER_SINGLE, title.c_str(), pattern.c_str(), old))
      exe = fileChooserGetName(1);
  }

  if(exe.size()) {
    c->setExecutable(exe);
    opt_solver_executable(c->getIndex(), GMSH_SET, exe);
  }
}

static void onelab_add_solver_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < NUM_SOLVERS; i++) {
    if(opt_solver_name(i, GMSH_GET, "").empty() || i == (NUM_SOLVERS - 1)) {
      const char *name = fl_input("Solver name:", "");
      if(name) { FlGui::instance()->onelab->addSolver(name, "", "", i); }
      return;
    }
  }
}

template <class T>
static void setClosed(const std::string &path, std::vector<T> &ps,
                      const std::string &value)
{
  onelab::server::instance()->get(ps);
  for(std::size_t i = 0; i < ps.size(); i++) {
    if(ps[i].getPath() == path) {
      ps[i].setAttribute("Closed", value);
      onelab::server::instance()->set(ps[i]);
    }
  }
}

static std::string getViewPathName(int num)
{
  if(num < 0 || num >= (int)PView::list.size()) return "";
  PViewOptions *opt = PView::list[num]->getOptions();
  std::ostringstream path;
  path << "0Modules/Post-processing/";
  if(opt->group.size()) path << opt->group << "/";
  path << "View" << num;
  return path.str();
}

static std::string getViewPath(int num)
{
  std::string s = getViewPathName(num);
  std::string::size_type last = s.find_last_of('/');
  return s.substr(0, last);
}

static void setOpenedClosed(Fl_Tree_Item *item, int reason)
{
  std::vector<onelab::number> numbers;
  std::vector<onelab::string> strings;
  std::string path = FlGui::instance()->onelab->getPath(item);
  switch(reason) {
  case FL_TREE_REASON_OPENED:
    FlGui::instance()->onelab->removeFromManuallyClosed(path);
    setClosed(path, numbers, "0");
    setClosed(path, strings, "0");
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(getViewPath(i) == path) PView::list[i]->getOptions()->closed = 0;
    }
    break;
  case FL_TREE_REASON_CLOSED:
    FlGui::instance()->onelab->insertInManuallyClosed(path);
    setClosed(path, numbers, "1");
    setClosed(path, strings, "1");
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      if(getViewPath(i) == path) PView::list[i]->getOptions()->closed = 1;
    }
    break;
  default: break;
  }
}

static void onelab_tree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree *tree = (Fl_Tree *)w;
  Fl_Tree_Item *item = (Fl_Tree_Item *)tree->callback_item();
  setOpenedClosed(item, tree->callback_reason());
}

#if 0 // FIXME until the FLTK bug with widgets is solved
static void onelab_subtree_cb(Fl_Widget *w, void *data)
{
  Fl_Tree_Item *n = (Fl_Tree_Item*)data;
  int reason;
  if(n->is_open()){
    reason = FL_TREE_REASON_CLOSED;
    n->close();
  }
  else{
    reason = FL_TREE_REASON_OPENED;
    n->open();
  }
  setOpenedClosed(n, reason);
  FlGui::instance()->onelab->redrawTree();
}
#endif

void onelabGroup::_computeWidths()
{
  // "-FL_NORMAL_SIZE" to have space for a scrollbar to the right
  _baseWidth = _tree->w() - _tree->marginleft() - 1.1 * FL_NORMAL_SIZE;
  // not sure why we have the "-2" correction at the end, but this is what is
  // needed to make things pixel-correct.
  _indent = _tree->connectorwidth() / 2. + _tree->openicon()->w() / 2. - 2.;
}

#if !defined(__APPLE__)
#define gear_width 16
#define gear_height 16
static unsigned char gear_bits[] = {
  0x80, 0x01, 0x80, 0x01, 0x8c, 0x31, 0xfc, 0x3f, 0xf8, 0x1f, 0xf8,
  0x1f, 0x38, 0x1c, 0x3f, 0xfc, 0x3f, 0xfc, 0x38, 0x1c, 0xf8, 0x1f,
  0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x31, 0x80, 0x01, 0x80, 0x01};
#endif

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x, y, w, h, l), _stop(false), _enableTreeWidgetResize(false),
    _firstBuild(true)
{
  int col = FL_BACKGROUND2_COLOR;
  color(col);

  box(GMSH_SIMPLE_RIGHT_BOX);
  int dx = Fl::box_dx(box());
  int dy = Fl::box_dy(box());
  int dw = Fl::box_dw(box());
  int dh = Fl::box_dh(box());

  _tree = new Fl_Tree(x + dx, y + dy, w - dw, h - dh - BH - 2 * WB);
  _tree->color(col);
  _tree->callback(onelab_tree_cb);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  // _tree->marginleft(0);
  // _tree->usericonmarginleft(0);
  // _tree->labelmarginleft(0);
  // _tree->connectorwidth(15);
  _tree->showroot(0);
  _tree->box(FL_FLAT_BOX);
  // _tree->resizable(0);
  _tree->end();

  _computeWidths();
  _widgetLabelRatio = 0.5;

  int BB2 = BB / 2 + 4;

  _butt[0] =
    new Fl_Button(x + w - 3 * WB - 3 * BB2, y + h - WB - BH, BB2, BH, "Check");
  _butt[0]->callback(onelab_cb, (void *)"check");

  _butt[1] =
    new Fl_Button(x + w - 2 * WB - 2 * BB2, y + h - WB - BH, BB2, BH, "Run");
  _butt[1]->callback(onelab_cb, (void *)"compute");

  _gear = new Fl_Menu_Button(x + w - WB - BB2, y + h - WB - BH, BB2, BH);
#if defined(__APPLE__)
  _gear->label("@-1gmsh_gear");
#else
  _gear->image(new Fl_Bitmap(gear_bits, gear_width, gear_height));
#endif
  _gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _gear->add("Reset database", 0, onelab_cb, (void *)"reset");
  _gear->add("Save database...", 0, onelab_cb, (void *)"save");
  _gear->add("_Load database...", 0, onelab_cb, (void *)"load");

  _minWindowWidth = 3 * BB2 + 4 * WB;
  _minWindowHeight = 2 * BH + 3 * WB;

  _gearOptionsStart = _gear->menu()->size();

  _gear->add("Save database automatically", 0, onelab_option_cb, (void *)"save",
             FL_MENU_TOGGLE);
  _gear->add("Load database automatically", 0, onelab_option_cb, (void *)"load",
             FL_MENU_TOGGLE);
  _gear->add("Archive output files automatically", 0, onelab_option_cb,
             (void *)"archive", FL_MENU_TOGGLE);
  _gear->add("Check model after each change", 0, onelab_option_cb,
             (void *)"check", FL_MENU_TOGGLE);
  _gear->add("Remesh automatically", 0, onelab_option_cb, (void *)"mesh",
             FL_MENU_TOGGLE);
  _gear->add("Merge results automatically", 0, onelab_option_cb,
             (void *)"merge", FL_MENU_TOGGLE);
  _gear->add("Show new views", 0, onelab_option_cb, (void *)"show",
             FL_MENU_TOGGLE);
  _gear->add("Always show last step", 0, onelab_option_cb, (void *)"step",
             FL_MENU_TOGGLE);
  _gear->add("_Show hidden parameters", 0, onelab_option_cb,
             (void *)"invisible", FL_MENU_TOGGLE);

  _gearOptionsEnd = _gear->menu()->size();

  _gear->add("Add new solver...", 0, onelab_add_solver_cb);

  end();

  Fl_Box *resbox = new Fl_Box(x + WB, y + WB, WB, WB);
  resizable(resbox);

  rebuildSolverList();
}

bool getParameterColor(const std::string &str, Fl_Color &c)
{
  if(str == "1") {
    c = FL_YELLOW;
    return true;
  }
  int r, g, b;
  if(str.size() && GetRGBForString(str.c_str(), r, g, b)) {
    c = fl_color_cube(r * (FL_NUM_RED - 1) / 255, g * (FL_NUM_GREEN - 1) / 255,
                      b * (FL_NUM_BLUE - 1) / 255);
    return true;
  }
  c = FL_BLACK;
  return false;
}

template <class T>
static void autoCheck(const T &pold, const T &pnew, bool force = false)
{
  if(onelabUtils::getFirstComputationFlag()) {
    if(pold.getValue() != pnew.getValue())
      onelabUtils::setFirstComputationFlag(false);
  }

  if((CTX::instance()->solver.autoCheck &&
      pnew.getAttribute("AutoCheck") != "0") ||
     pnew.getAttribute("AutoCheck") == "1") {
    if(force || pold.getValue() != pnew.getValue())
      onelab_cb(nullptr, (void *)"check");
  }
}

template <class T> void onelabGroup::_addParameter(T &p)
{
  bool highlight = false;
  Fl_Color c;
  if(getParameterColor(p.getAttribute("Highlight"), c)) highlight = true;
  Fl_Tree_Item *n = _tree->add(p.getName().c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", p.getName().c_str());
    return;
  }
  n->labelsize(FL_NORMAL_SIZE + 4);
  _tree->begin();
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Widget *widget =
    addParameterWidget(p, 1, 1, ww * _widgetLabelRatio, hh, _widgetLabelRatio,
                       getPath(n), highlight, c, _tree->color(), _treeStrings);
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  _treeWidgets.push_back(grp);
  widget->copy_label(p.getShortName().c_str());
  std::string help = p.getHelp();
  if(help.empty()) help = p.getLabel();
  if(help.empty()) help = p.getShortName();
  widget->copy_tooltip(help.c_str());
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addMenu(const std::string &path, Fl_Callback *callback,
                           void *data)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", path.c_str());
    return;
  }
  _tree->begin();
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  Fl_Button *but = new Fl_Button(1, 1, ww, hh);
  but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  but->callback(callback, data);
  but->box(FL_FLAT_BOX);
  but->color(_tree->color());
  but->selection_color(_tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  _treeWidgets.push_back(grp);
  std::string label = path;
  std::string::size_type last = path.find_last_of('/');
  if(last != std::string::npos) label = path.substr(last + 1);
  but->copy_label(label.c_str());
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addSolverMenu(int num)
{
  std::ostringstream path;
  path << "0Modules/Solver/Solver" << num;
  Fl_Tree_Item *n = _tree->add(path.str().c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", path.str().c_str());
    return;
  }
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new solverButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

void onelabGroup::_addViewMenu(int num)
{
  std::string path = getViewPathName(num);
  if(path.empty()) return;
  Fl_Tree_Item *n = _tree->add(path.c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", path.c_str());
    return;
  }
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  new viewButton(1, 1, ww, hh, num, _tree->color());
  grp->end();
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
  if(PView::list[num]->getOptions()->closed) n->parent()->close();
}

viewButton *onelabGroup::getViewButton(int num)
{
  std::string path = getViewPathName(num);
  if(path.empty()) return nullptr;
  Fl_Tree_Item *n = _tree->find_item(path.c_str());
  if(n) {
    Fl_Group *grp = (Fl_Group *)n->widget();
    return (viewButton *)grp->child(0);
  }
  return nullptr;
}

void onelabGroup::openCloseViewButton(int num)
{
  std::string path = getViewPathName(num);
  if(path.empty()) return;
  Fl_Tree_Item *n = _tree->find_item(path.c_str());
  if(n) {
    if(PView::list[num]->getOptions()->closed)
      n->parent()->close();
    else
      n->parent()->open();
    _tree->redraw();
  }
}

static bool serverAction(const std::string &action)
{
  if(action == "ResetDatabase") {
    // reset the onelab db
    onelabUtils::resetDb(false);
    FlGui::instance()->rebuildTree(false);
    return true;
  }
  else if(action == "Reset") {
    // reset the onelab db + views + models (except the current model)
    onelabUtils::resetDb(false);
    for(int i = PView::list.size() - 1; i >= 0; i--) delete PView::list[i];
    for(int i = GModel::list.size() - 1; i >= 0; i--)
      if(GModel::list[i] != GModel::current()) delete GModel::list[i];
    FlGui::instance()->rebuildTree(false);
    return true;
  }
  else if(!action.compare(0, 5, "Reset")) {
    // reset some variables
    std::vector<std::string> what =
      onelab::parameter::split(action.substr(5), ',');
    for(std::size_t i = 0; i < what.size(); i++) {
      std::string var = onelab::parameter::trim(what[i]);
      Msg::Debug("Clearing variable '%s'", var.c_str());
      onelab::server::instance()->clear(var);
    }
    FlGui::instance()->rebuildTree(false);
    return true;
  }
  return false;
}

static bool serverActionMatch(const std::string &action,
                              const std::string &match)
{
  std::vector<std::string> names;
  onelab::server::instance()->getParameterNames(names, match);

  for(auto &var : names) {
    Msg::Debug("Performing action '%s' on variable '%s'", action.c_str(),
               var.c_str());
    if(action == "ResetMatch") { onelab::server::instance()->clear(var); }
    else {
      std::vector<onelab::string> ps;
      onelab::server::instance()->get(ps, var);
      if(ps.size()) {
        if(action == "HideMatch")
          ps[0].setVisible(false);
        else if(action == "ShowMatch")
          ps[0].setVisible(true);
        else if(action == "ReadOnlyMatch")
          ps[0].setReadOnly(true);
        else if(action == "ReadWriteMatch")
          ps[0].setReadOnly(false);
      }
      std::vector<onelab::number> pn;
      onelab::server::instance()->get(pn, var);
      if(pn.size()) {
        if(action == "HideMatch")
          pn[0].setVisible(false);
        else if(action == "ShowMatch")
          pn[0].setVisible(true);
        else if(action == "ReadOnlyMatch")
          pn[0].setReadOnly(true);
        else if(action == "ReadWriteMatch")
          pn[0].setReadOnly(false);
        onelab::server::instance()->set(pn[0]);
      }
    }
  }

  // don't rebuild the tree here: we should leave it to the normal event loop to
  // perform a "check" if necessary, after all modifications have been performed
  return !names.empty();
}

static bool serverActionList(const std::string &path, const std::string &action,
                             const std::string &data)
{
  std::vector<std::string> what = onelab::parameter::split(data, ',');

  if(action == "Set" && (what.size() < 2 || what.size() % 2)) {
    Msg::Warning("Bad data for ServerActionSet");
    return false;
  }

  for(std::size_t i = 0; i < what.size(); i++) {
    std::string var = onelab::parameter::trim(what[i]);
    // replace starting '%' with path of variable with the attributes
    if(var.size() && var[0] == '%') {
      var.erase(0, 1);
      var = path + "/" + var;
    }
    Msg::Debug("Performing action '%s' on variable '%s'", action.c_str(),
               var.c_str());
    if(action == "Reset") { onelab::server::instance()->clear(var); }
    else {
      std::string val;
      if(action == "Set") {
        val = onelab::parameter::trim(what[i + 1]);
        i++;
      }
      std::vector<onelab::string> ps;
      onelab::server::instance()->get(ps, var);
      if(ps.size()) {
        if(action == "Set")
          ps[0].setValue(val);
        else if(action == "Show")
          ps[0].setVisible(true);
        else if(action == "Hide")
          ps[0].setVisible(false);
        else if(action == "ReadOnly")
          ps[0].setReadOnly(true);
        else if(action == "ReadWrite")
          ps[0].setReadOnly(false);
        onelab::server::instance()->set(ps[0]);
      }
      std::vector<onelab::number> pn;
      onelab::server::instance()->get(pn, var);
      if(pn.size()) {
        if(action == "Set")
          pn[0].setValue(atof(val.c_str()));
        else if(action == "Show")
          pn[0].setVisible(true);
        else if(action == "Hide")
          pn[0].setVisible(false);
        else if(action == "ReadOnly")
          pn[0].setReadOnly(true);
        else if(action == "ReadWrite")
          pn[0].setReadOnly(false);
        onelab::server::instance()->set(pn[0]);
      }
    }
  }

  return true;
}

template <class T> static void performServerAction(T &n)
{
  if(n.getAttributes().empty()) return;

  // global unconditional actions, triggering a tree rebuild
  std::string action = n.getAttribute("ServerAction");
  if(action.size()) serverAction(action);

  // actions not triggering a tree rebuild (it should happen after all
  // parameters have been changed on the server-side):

  // * actions using one variable or a list of variables
  std::vector<std::string> list = {"Reset", "Hide",     "Show",
                                   "Set",   "ReadOnly", "ReadWrite"};
  for(auto &a : list) {
    // global
    std::string data = n.getAttribute("ServerAction" + a);
    if(data.size()) serverActionList(n.getPath(), a, data);
    // only for a given value
    data = n.getAttribute("ServerAction" + a + " " + n.getValueAsString());
    if(data.size()) serverActionList(n.getPath(), a, data);
  }

  // * actions using a regex
  std::vector<std::string> regex = {"ResetMatch", "HideMatch", "ShowMatch",
                                    "ReadOnlyMatch", "ReadWriteMatch"};
  for(auto &a : regex) {
    // global
    std::string data = n.getAttribute("ServerAction" + a);
    if(data.size()) serverActionMatch(a, data);
    // only for a given value
    data = n.getAttribute("ServerAction" + a + " " + n.getValueAsString());
    if(data.size()) serverActionMatch(a, data);
  }
}

template <class T> static void setGmshOption(T &n)
{
  std::string opt = n.getAttribute("GmshOption");
  if(opt.empty()) return;
  if(serverAction(opt)) return; // for backward compatibility:
  std::string::size_type dot = opt.find('.');
  if(dot == std::string::npos) return;
  GmshSetOption(opt.substr(0, dot), opt.substr(dot + 1), n.getValue());
  drawContext::global()->draw();
}

static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    Fl_Check_Button *o = (Fl_Check_Button *)w;
    onelab::number old = numbers[0];
    numbers[0].setValue(o->value());
    setGmshOption(numbers[0]);
    performServerAction(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    Fl_Choice *o = (Fl_Choice *)w;
    std::vector<double> choices = numbers[0].getChoices();
    onelab::number old = numbers[0];
    if(o->value() < (int)choices.size())
      numbers[0].setValue(choices[o->value()]);
    setGmshOption(numbers[0]);
    performServerAction(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_input_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    inputRange *o = (inputRange *)w;
    onelab::number old = numbers[0];
    if(o->doCallbackOnValues()) {
      numbers[0].setValue(o->value());
      numbers[0].setMin(o->minimum());
      numbers[0].setMax(o->maximum());
      numbers[0].setStep(o->step());
      numbers[0].setChoices(o->choices());
    }
    o->doCallbackOnValues(true);
    numbers[0].setAttribute("Loop", o->loop());
    numbers[0].setAttribute("Graph", o->graph());
    setGmshOption(numbers[0]);
    performServerAction(numbers[0]);
    onelab::server::instance()->set(numbers[0]);
    onelabUtils::updateGraphs();
    autoCheck(old, numbers[0]);
  }
}

static void onelab_number_output_range_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    outputRange *o = (outputRange *)w;
    numbers[0].setAttribute("Graph", o->graph());
    onelab::server::instance()->set(numbers[0]);
    onelabUtils::updateGraphs();
  }
}

Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::vector<char *> &stringsToFree)
{
  char *path = strdup(ppath.c_str());
  stringsToFree.push_back(path);

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()) {
    Fl_Choice *but = new Fl_Choice(xx, yy, ww, hh);
    std::vector<Fl_Menu_Item> menu;
    std::vector<double> choices = p.getChoices();
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::size_t i = 0; i < choices.size(); i++) {
      char *str = strdup(labels[choices[i]].c_str());
      stringsToFree.push_back(str);
      Fl_Menu_Item menuItem = {str, 0, nullptr, nullptr, 0};
      if(highlight) menuItem.labelcolor(c);
      menu.push_back(menuItem);
    }
    Fl_Menu_Item it = {nullptr};
    menu.push_back(it);
    but->copy(&menu[0]);
    for(std::size_t i = 0; i < choices.size(); i++) {
      if(p.getValue() == choices[i]) {
        but->value(i);
        break;
      }
    }
    but->callback(onelab_number_choice_cb, (void *)path);
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // check box (boolean choice)
  if(p.getChoices().size() == 2 && p.getChoices()[0] == 0 &&
     p.getChoices()[1] == 1) {
    // n->labelsize(FL_NORMAL_SIZE + 2);
    Fl_Check_Button *but = new Fl_Check_Button(xx, yy, ww / labelRatio, hh);
    but->box(FL_FLAT_BOX);
    but->color(bgc);
    but->value(p.getValue());
    but->callback(onelab_number_check_button_cb, (void *)path);
    but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(c);
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, c));
    }
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // non-editable value
  if(p.getReadOnly()) {
    outputRange *but = new outputRange(xx, yy, ww, hh);
    but->callback(onelab_number_output_range_cb, (void *)path);
    but->numberFormat(p.getAttribute("NumberFormat"));
    but->value(p.getValue());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    but->graph(p.getAttribute("Graph"));
    if(highlight) but->color(c);
    return but;
  }

  // general number input
  inputRange *but =
    new inputRange(xx, yy, ww, hh, onelab::parameter::maxNumber(),
                   p.getAttribute("ReadOnlyRange") == "1");
  but->numberFormat(p.getAttribute("NumberFormat"));
  but->value(p.getValue());
  but->minimum(p.getMin());
  but->maximum(p.getMax());
  if(CTX::instance()->inputScrolling) but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void *)path);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) but->color(c);
  return but;
}

static void onelab_string_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    if(strings[0].getAttribute("Macro") == "GmshParseString") {
      // parse string directly
      ParseString(strings[0].getValue());
    }
    else if(strings[0].getAttribute("Macro") == "Action") {
      // set onelab Action for custom GUIs
      onelab::string o("ONELAB/Action", strings[0].getValue());
      o.setVisible(false);
      o.setNeverChanged(true);
      o.setAttribute("Persistent", "1");
      onelab::server::instance()->set(o);
      return; // otherwise autoCheck will set Action to "check"
    }
    else {
      // merge file
      std::string tmp = FixRelativePath(GModel::current()->getFileName(),
                                        strings[0].getValue());
      MergeFile(tmp);
    }
    setGmshOption(strings[0]);
    performServerAction(strings[0]);
    autoCheck(strings[0], strings[0], true);
    drawContext::global()->draw();
  }
}

static void onelab_string_input_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    Fl_Input *o = (Fl_Input *)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
    setGmshOption(strings[0]);
    performServerAction(strings[0]);
    onelab::server::instance()->set(strings[0]);
    autoCheck(old, strings[0]);
  }
}

static void onelab_string_input_choice_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    Fl_Input_Choice *o = (Fl_Input_Choice *)w;
    onelab::string old = strings[0];
    strings[0].setValue(o->value());
    std::string choices;
    for(int i = 0; i < o->menubutton()->menu()->size(); i++) {
      if(o->menubutton()->menu()[i].flags & FL_MENU_TOGGLE) {
        if(o->menubutton()->menu()[i].flags & FL_MENU_VALUE)
          choices += "1";
        else
          choices += "0";
      }
    }
    if(choices.size()) strings[0].setAttribute("MultipleSelection", choices);
    setGmshOption(strings[0]);
    performServerAction(strings[0]);
    onelab::server::instance()->set(strings[0]);
    autoCheck(old, strings[0]);
  }
}

static void onelab_input_choice_file_chooser_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  if(fileChooser(FILE_CHOOSER_SINGLE, "Choose", "", but->value())) {
    but->value(fileChooserGetName(1).c_str());
    but->do_callback();
  }
}

static void onelab_input_choice_file_edit_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  std::string prog = FixWindowsPath(CTX::instance()->editor);
  std::string file = FixWindowsPath(but->value());
  SystemCall(ReplaceSubString("%s", file, prog));
}

static void onelab_input_choice_file_merge_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)w->parent();
  std::string file = FixWindowsPath(but->value());
  MergeFile(file);
  drawContext::global()->draw();
}

static void multiple_selection_menu_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_Button *menu = (Fl_Menu_Button *)w;
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    const Fl_Menu_Item &item = menu->menu()[i];
    if(item.value() && item.label()) {
      if(val.size()) val += ", ";
      val += item.label();
    }
  }
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  but->value(val.c_str());
  but->do_callback();
}

static void multiple_selection_menu_all_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  Fl_Menu_Button *menu = but->menubutton();
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    int mode = menu->mode(i);
    if(mode & FL_MENU_TOGGLE) {
      if(mode & FL_MENU_DIVIDER)
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_VALUE | FL_MENU_DIVIDER);
      else
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_VALUE);
      const Fl_Menu_Item &item = menu->menu()[i];
      if(item.label()) {
        if(val.size()) val += ", ";
        val += item.label();
      }
    }
  }
  but->value(val.c_str());
  but->do_callback();
}

static void multiple_selection_menu_none_cb(Fl_Widget *w, void *data)
{
  Fl_Input_Choice *but = (Fl_Input_Choice *)data;
  Fl_Menu_Button *menu = but->menubutton();
  std::string val;
  for(int i = 0; i < menu->size() - 1; i++) {
    int mode = menu->mode(i);
    if(mode & FL_MENU_TOGGLE) {
      if(mode & FL_MENU_DIVIDER)
        menu->mode(i, FL_MENU_TOGGLE | FL_MENU_DIVIDER);
      else
        menu->mode(i, FL_MENU_TOGGLE);
    }
  }
  but->value("");
  but->do_callback();
}

Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::vector<char *> &stringsToFree)
{
  char *path = strdup(ppath.c_str());
  stringsToFree.push_back(path);

  // macro button
  if(p.getAttribute("Macro") == "Gmsh" ||
     p.getAttribute("Macro") == "GmshMergeFile" ||
     p.getAttribute("Macro") == "GmshParseString" ||
     p.getAttribute("Macro") == "Action") {
    Fl_Button *but;
    if(p.getAttribute("Aspect") == "Button" ||
       p.getAttribute("Aspect") == "LeftButton" ||
       p.getAttribute("Aspect") == "MiddleButton" ||
       p.getAttribute("Aspect") == "RightButton") {
      but = new Fl_Button(xx, yy, ww, hh);
      but->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    else if(p.getAttribute("Aspect") == "ReturnButton" ||
            p.getAttribute("Aspect") == "LeftReturnButton" ||
            p.getAttribute("Aspect") == "MiddleReturnButton" ||
            p.getAttribute("Aspect") == "RightReturnButton") {
      but = new Fl_Return_Button(xx, yy, ww, hh);
      but->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    else {
      but = new Fl_Button(xx, yy, ww / labelRatio, hh);
      but->box(FL_FLAT_BOX);
      but->color(bgc);
      but->selection_color(bgc);
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    }
    but->callback(onelab_string_button_cb, (void *)path);
    if(highlight) {
      but->color(c);
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, c));
    }
    return but;
  }

  // non-editable value
  if(p.getReadOnly() && p.getKind() != "file") {
    Fl_Output *but = new Fl_Output(xx, yy, ww, hh);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(c);
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, c));
    }
    return but;
  }

  // simple string (no menu)
  if(p.getChoices().empty() && p.getKind() != "file") {
    Fl_Input *but = new Fl_Input(xx, yy, ww, hh);
    but->value(p.getValue().c_str());
    but->callback(onelab_string_input_cb, (void *)path);
    but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(c);
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, c));
    }
    return but;
  }

  // general string input
  Fl_Input_Choice *but = new Fl_Input_Choice(xx, yy, ww, hh);
  std::string multipleSelection = p.getAttribute("MultipleSelection");
  if(multipleSelection.size())
    but->menubutton()->callback(multiple_selection_menu_cb, but);
  std::vector<Fl_Menu_Item> menu;
  for(std::size_t j = 0; j < p.getChoices().size(); j++) {
    char *str = strdup(p.getChoices()[j].c_str());
    stringsToFree.push_back(str);
    bool divider = ((p.getKind() == "file" || multipleSelection.size()) &&
                    j == p.getChoices().size() - 1);
    int choice = multipleSelection.size() ? FL_MENU_TOGGLE : 0;
    if(multipleSelection.size() > j && multipleSelection[j] == '1')
      choice |= FL_MENU_VALUE;
    Fl_Menu_Item it = {str, 0, nullptr, nullptr,
                       choice | (divider ? FL_MENU_DIVIDER : 0)};
    menu.push_back(it);
  }
  if(multipleSelection.size()) {
    Fl_Menu_Item it = {"Select All", 0, multiple_selection_menu_all_cb, but};
    menu.push_back(it);
    Fl_Menu_Item it2 = {"Select None", 0, multiple_selection_menu_none_cb, but};
    menu.push_back(it2);
  }
  if(p.getKind() == "file") {
    if(!p.getReadOnly()) {
      Fl_Menu_Item it = {"Choose File...", 0,
                         onelab_input_choice_file_chooser_cb};
      menu.push_back(it);
    }
    Fl_Menu_Item it2 = {"Edit Selected File...", 0,
                        onelab_input_choice_file_edit_cb};
    menu.push_back(it2);
    if(GuessFileFormatFromFileName(p.getValue()) >= 0) {
      Fl_Menu_Item it3 = {"Merge Selected File...", 0,
                          onelab_input_choice_file_merge_cb};
      menu.push_back(it3);
    }
  }
  Fl_Menu_Item it = {nullptr};
  menu.push_back(it);
  but->menubutton()->copy(&menu[0]);
  but->value(p.getValue().c_str());
  but->callback(onelab_string_input_choice_cb, (void *)path);
  but->input()->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) {
    but->input()->color(c);
    but->input()->textcolor(fl_contrast(FL_FOREGROUND_COLOR, c));
  }
  return but;
}

static void view_group_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string group((char *)data);
  while(group.size() && group[0] == '/') group = group.substr(1);
  while(group.size() && group[group.size() - 1] == '/')
    group = group.substr(0, group.size() - 1);
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewOptions *opt = PView::list[i]->getOptions();
    if(opt->group.find(group) == 0)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, !opt->visible);
  }
  drawContext::global()->draw();
}

static void highlight_physical_group_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string group((char *)data);
  if(group.empty()) return;

  GModel *m = GModel::current();
  int dim = -1, num = -1;
  if(group.find("Physical Point") != std::string::npos) {
    dim = 0;
    num = atoi(group.substr(15).c_str());
  }
  else if(group.find("Physical Curve") != std::string::npos) {
    dim = 1;
    num = atoi(group.substr(15).c_str());
  }
  else if(group.find("Physical Surface") != std::string::npos) {
    dim = 2;
    num = atoi(group.substr(17).c_str());
  }
  else if(group.find("Physical Volume") != std::string::npos) {
    dim = 3;
    num = atoi(group.substr(16).c_str());
  }
  else {
    for(dim = 3; dim >= 0; dim--) {
      num = m->getPhysicalNumber(dim, group);
      if(num > 0) break;
    }
  }
  if(dim < 0 || num < 0) return; // not found

  std::map<int, std::vector<GEntity *> > groups;
  m->getPhysicalGroups(dim, groups);
  std::vector<GEntity *> entities = groups[num];

  for(std::size_t i = 0; i < entities.size(); i++) {
    entities[i]->setVisibility(1);
    if(!entities[i]->getSelection()) { entities[i]->setSelection(2); }
    else
      entities[i]->setSelection(0);
  }

  drawContext::global()->draw();
}

void onelabGroup::rebuildTree(bool deleteWidgets)
{
  // rebuilding the tree does not work in a child thread (it should, as we don't
  // show/hide windows, but it crashes - at least on macOS)
  if(FlGui::locked()) return;

  setButtonVisibility();

  FL_NORMAL_SIZE -= CTX::instance()->deltaFontSize;
  _computeWidths();

  std::set<std::string> closed = _getClosedGmshMenus();

  _tree->clear();

  if(CTX::instance()->guiColorScheme) {
    _tree->openicon(&open_pixmap_dark);
    _tree->closeicon(&close_pixmap_dark);
  }
  else {
    _tree->openicon(&open_pixmap_light);
    _tree->closeicon(&close_pixmap_light);
  }
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  // hide all the widgets we have added in the tree to make sure they don't get
  // spurious events (until they are deleted)
  for(std::size_t i = 0; i < _treeWidgets.size(); i++) _treeWidgets[i]->hide();

  // we don't delete widgets everytime the tree is rebuilt to minimize potential
  // race conditions (e.g. during heavy user interaction with autoCheck, with
  // risks to call handle() or focus() on deleted widgets)
  std::vector<Fl_Widget *> delWidgets;
  std::vector<char *> delStrings;
  if(deleteWidgets) {
    delWidgets = _treeWidgets;
    delStrings = _treeStrings;
    _treeWidgets.clear();
    _treeStrings.clear();
  }

  if(CTX::instance()->showModuleMenu) _addGmshMenus();

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  for(std::size_t i = 0; i < numbers.size(); i++) {
    if(numbers[i].getAttribute("Closed") == "1")
      closed.insert(numbers[i].getPath());
    if((!numbers[i].getVisible() ||
        numbers[i].getName().find("ONELAB Context/") != std::string::npos) &&
       !CTX::instance()->solver.showInvisibleParameters)
      continue;
    _addParameter(numbers[i]);
  }

  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings);
  for(std::size_t i = 0; i < strings.size(); i++) {
    if(strings[i].getAttribute("Closed") == "1")
      closed.insert(strings[i].getPath());
    if((!strings[i].getVisible() ||
        strings[i].getName().find("ONELAB Context/") != std::string::npos) &&
       !CTX::instance()->solver.showInvisibleParameters)
      continue;
    _addParameter(strings[i]);
  }

  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()) {
    if(n->has_children()) {
      int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
      int hh = n->labelsize() + 4;
      _tree->begin();
      Fl_Widget *but;
#if 0 // FIXME this can crash FLTK when submenus are intially closed (somehow
      // the widget is badly positioned and overlaps the open icon, leading to
      // a corrupted Fl_Tree_Item)
      but = new Fl_Button(1, 1, ww, hh);
      but->box(FL_NO_BOX);
      but->clear_visible_focus();
      but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      but->callback(onelab_subtree_cb, (void*)n);
#else
      if(getPath(n).find("0Modules/Post-processing") != std::string::npos) {
        but = new Fl_Button(1, 1, ww, hh);
        but->box(FL_NO_BOX);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        but->tooltip("Toggle visibility of child views");
        char *group = strdup(getPath(n).substr(24).c_str());
        _treeStrings.push_back(group);
        but->callback(view_group_cb, (void *)group);
      }
      else if(getPath(n).find("Physical group: ") != std::string::npos) {
        but = new Fl_Button(1, 1, ww, hh);
        but->box(FL_NO_BOX);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        but->tooltip("Toggle highlight of physical group");
        std::string::size_type pos = getPath(n).find("Physical group: ");
        char *group = strdup(getPath(n).substr(pos + 16).c_str());
        _treeStrings.push_back(group);
        but->callback(highlight_physical_group_cb, (void *)group);
      }
      else {
        but = new Fl_Box(1, 1, ww, hh);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      }
#endif
      _treeWidgets.push_back(but);
      onelab::string o(n->label());
      but->copy_label(o.getShortName().c_str());
      n->widget(but);
      _tree->end();
    }
  }

  for(auto it = closed.begin(); it != closed.end(); it++) {
    if(it->size()) _tree->close(it->c_str(), 0);
  }

  _tree->redraw();

  FL_NORMAL_SIZE += CTX::instance()->deltaFontSize;

  FlGui::check(true); // necessary e.g. on windows to avoid "ghosting"

  if(deleteWidgets) {
    // this needs to be performed after FlGui::check()
    Msg::Debug("Deleting onelabGroup widgets (%d)", (int)_treeWidgets.size());
    // Fl::focus(0); // tentative fix for crash reported in #955
    for(std::size_t i = 0; i < delWidgets.size(); i++)
      Fl::delete_widget(delWidgets[i]);
    for(std::size_t i = 0; i < delStrings.size(); i++) free(delStrings[i]);
  }

#if 0 // test
  std::ifstream t("test.db.json");
  std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
  onelab::server::instance()->fromJSON(str);
#endif
}

void onelabGroup::openTreeItem(const std::string &name)
{
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if(n && n->has_children()) {
    n->open();
    _tree->redraw();
  }
}

void onelabGroup::closeTreeItem(const std::string &name)
{
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if(n && n->has_children()) {
    n->close();
    _tree->redraw();
  }
}

void onelabGroup::checkForErrors(const std::string &client)
{
  if(Msg::GetErrorCount() > 0 && !CTX::instance()->expertMode) {
    std::string msg(
      client +
      " reported an error: do you really want to continue?\n\n"
      "(To disable this warning in the future, select `Enable expert mode'\n"
      "in the option dialog.)");
    if(Msg::GetAnswer(msg.c_str(), 1, "Stop", "Continue") == 0) _stop = true;
  }
}

void onelabGroup::setButtonVisibility()
{
  // custom button behavior
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "ONELAB/Button");
  if(ps.size() && ps[0].getValues().size() == 2) {
    _butt[0]->hide();
    _butt[1]->show();
    setButtonMode("", "");
    return;
  }

  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers);
  bool visible = false;
  for(std::size_t i = 0; i < numbers.size(); i++) {
    if(numbers[i].getVisible()) {
      visible = true;
      break;
    }
  }
  bool showRun = (onelab::server::instance()->getNumClients() > 1) || visible;
  if(CTX::instance()->solver.autoCheck) {
    _butt[0]->hide();
    if(showRun)
      _butt[1]->show();
    else
      _butt[1]->hide();
  }
  else if(showRun) {
    _butt[0]->show();
    _butt[1]->show();
  }
  else {
    _butt[0]->hide();
    _butt[1]->hide();
  }
  redraw();
}

void onelabGroup::setButtonMode(const std::string &butt0,
                                const std::string &butt1)
{
  // custom button behavior
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "ONELAB/Button");
  if(ps.size() && ps[0].getValues().size() == 2) {
    static char label[256];
    strncpy(label, ps[0].getValues()[0].c_str(), sizeof(label) - 1);
    label[sizeof(label) - 1] = '\0';
    static char action[256];
    strncpy(action, ps[0].getValues()[1].c_str(), sizeof(action) - 1);
    action[sizeof(action) - 1] = '\0';
    _butt[0]->deactivate();
    _butt[1]->activate();
    _butt[1]->label(label);
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    int w = 0, h = 0;
    fl_measure(label, w, h);
    int diff = w - _butt[1]->w() + 2 * WB;
    if(diff > 0) {
      _butt[1]->resize(_butt[1]->x() - diff, _butt[1]->y(),
                       _butt[1]->w() + diff, _butt[1]->h());
      _butt[1]->redraw();
    }
    _butt[1]->callback(onelab_cb, (void *)action);
    return;
  }

  if(butt0 == "check") {
    _butt[0]->activate();
    _butt[0]->label("Check");
    _butt[0]->callback(onelab_cb, (void *)"check");
  }
  else {
    _butt[0]->deactivate();
  }

  if(butt1 == "compute") {
    _butt[1]->activate();
    _butt[1]->label("Run");
    _butt[1]->callback(onelab_cb, (void *)"compute");
    for(int i = 0; i < _gear->menu()->size(); i++)
      ((Fl_Menu_Item *)_gear->menu())[i].activate();
  }
  else if(butt1 == "stop") {
    _butt[1]->activate();
    _butt[1]->label("Stop");
    _butt[1]->callback(onelab_cb, (void *)"stop");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item *)_gear->menu())[i].deactivate();
  }
  else if(butt1 == "kill") {
    _butt[1]->activate();
    _butt[1]->label("Kill");
    _butt[1]->callback(onelab_cb, (void *)"kill");
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item *)_gear->menu())[i].deactivate();
  }
  else {
    _butt[1]->deactivate();
    for(int i = 0; i < _gear->menu()->size(); i++)
      if(i < _gearOptionsStart - 1 || i > _gearOptionsEnd - 2)
        ((Fl_Menu_Item *)_gear->menu())[i].deactivate();
  }
}

bool onelabGroup::isBusy()
{
  std::string s(_butt[1]->label());
  if(s == "Stop" || s == "Kill") return true;
  return false;
}

std::string onelabGroup::getPath(Fl_Tree_Item *item)
{
  if(!item) {
    Msg::Error("No item for path");
    return "";
  }
  char path[1024];
  if(_tree->item_pathname(path, sizeof(path), item)) {
    Msg::Error("Could not get path for item");
    return "";
  }
  return std::string(path);
}

void onelabGroup::updateGearMenu()
{
  Fl_Menu_Item *menu = (Fl_Menu_Item *)_gear->menu();
  int values[9] = {CTX::instance()->solver.autoSaveDatabase,
                   CTX::instance()->solver.autoLoadDatabase,
                   CTX::instance()->solver.autoArchiveOutputFiles,
                   CTX::instance()->solver.autoCheck,
                   CTX::instance()->solver.autoMesh,
                   CTX::instance()->solver.autoMergeFile,
                   CTX::instance()->solver.autoShowViews,
                   CTX::instance()->solver.autoShowLastStep,
                   CTX::instance()->solver.showInvisibleParameters};
  for(int i = 0; i < 9; i++) {
    int idx = _gearOptionsStart - 1 + i;
    if(values[i])
      menu[idx].set();
    else
      menu[idx].clear();
  }
}

void onelabGroup::rebuildSolverList()
{
  updateGearMenu();

  std::vector<std::string> names, exes, hosts;
  for(int i = 0; i < NUM_SOLVERS; i++) {
    if(opt_solver_name(i, GMSH_GET, "").size()) {
      names.push_back(opt_solver_name(i, GMSH_GET, ""));
      exes.push_back(opt_solver_executable(i, GMSH_GET, ""));
      hosts.push_back(opt_solver_remote_login(i, GMSH_GET, ""));
    }
  }
  for(std::size_t i = 0; i < NUM_SOLVERS; i++) {
    if(i < names.size()) {
      auto it = onelab::server::instance()->findClient(names[i]);
      if(it != onelab::server::instance()->lastClient()) (*it)->setIndex(i);
      opt_solver_name(i, GMSH_SET, names[i]);
      opt_solver_executable(i, GMSH_SET, exes[i]);
      opt_solver_remote_login(i, GMSH_SET, hosts[i]);
    }
    else {
      opt_solver_name(i, GMSH_SET, "");
      opt_solver_executable(i, GMSH_SET, "");
      opt_solver_remote_login(i, GMSH_SET, "");
    }
  }

  rebuildTree(true);
}

static bool needToChooseExe(const std::string &exe)
{
  // no exe given
  if(exe.empty()) return true;

  // exe is given with absolute path to non-existing file
  if(exe[0] == '/' || exe[0] == '\\' || (exe.size() > 2 && exe[1] == ':')) {
    if(StatFile(exe)) return true;
  }

  return false;
}

void onelabGroup::addSolver(const std::string &name,
                            const std::string &executable,
                            const std::string &remoteLogin, int index)
{
  auto it = onelab::server::instance()->findClient(name);
  if(it != onelab::server::instance()->lastClient()) {
    if(needToChooseExe(executable))
      onelab_choose_executable_cb(nullptr, (void *)(*it));
    return; // solver already exists
  }

  // delete the other non-local clients so we keep only the new one
  std::vector<onelab::client *> networkClients;
  for(auto it = onelab::server::instance()->firstClient();
      it != onelab::server::instance()->lastClient(); it++)
    if((*it)->isNetworkClient()) networkClients.push_back(*it);
  for(std::size_t i = 0; i < networkClients.size(); i++) {
    delete networkClients[i];
  }

  // create and register the new client
  onelab::localNetworkClient *c =
    new gmshLocalNetworkClient(name, executable, remoteLogin);
  c->setIndex(index);
  opt_solver_name(index, GMSH_SET, name);
  if(needToChooseExe(executable))
    onelab_choose_executable_cb(nullptr, (void *)c);
  else
    opt_solver_executable(index, GMSH_SET, executable);
  opt_solver_remote_login(index, GMSH_SET, remoteLogin);

  FlGui::instance()->onelab->rebuildSolverList();

  // initialize the client
  onelab_cb(nullptr, (void *)"initialize");
}
