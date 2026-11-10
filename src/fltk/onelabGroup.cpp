// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <FL/Fl.H>
#include "GmshConfig.h"
#include <cstdint>
#include <ctype.h>
#include "GmshMessage.h"
#include "onelab.h"
#include "gmshLocalNetworkClient.h"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Return_Button.H>
#include <FL/fl_ask.H>
#include "inputRange.h"
#include "outputRange.h"
#include "solverButton.h"
#include "viewButton.h"
#include "graphicWindow.h"
#include "fileDialogs.h"
#include "editorWindow.h"
#include "onelabGroup.h"
#include "FlGui.h"
#include "gmshScheme.h"
#include "icons.h"
#include "Context.h"
#include "GModel.h"
#include "Options.h"
#include "OS.h"
#include "StringUtils.h"
#include "onelabUtils.h"
#include "Actions.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "drawContext.h"
#include "PView.h"
#include "PViewOptions.h"
#include "treeIcons.h"

// This file contains the Gmsh/FLTK specific parts of the ONELAB
// interface. You'll need to reimplement this if you plan to build a different
// ONELAB server.

// the graphs of the parameters made again, and the views they changed shown
static void updateGraphs()
{
  if(onelabUtils::updateGraphs() && FlGui::available()) {
    FlGui::instance()->updateViews(true);
    drawContext::global()->draw();
  }
}

// the loops over parameters started, or their next step taken (false when
// they are over), with the values they set shown in the tree
static void initializeLoops()
{
  onelabUtils::initializeLoops();
  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree();
}

static bool incrementLoops()
{
  bool more = onelabUtils::incrementLoops();
  if(FlGui::available() && onelab::server::instance()->getChanged())
    FlGui::instance()->rebuildTree();
  return more;
}

bool solverBusy()
{
  if(!FlGui::available() || !FlGui::instance()->onelab ||
     !FlGui::instance()->onelab->isBusy())
    return false;
  Msg::Info("I'm busy! Ask me that later...");
  return true;
}

void solver_cb(Fl_Widget *w, void *data)
{
  if(!FlGui::available() || !FlGui::instance()->onelab) return;
  // choosing a solver deletes the clients, among which the one running; one
  // asked for by a file opened meanwhile is not launched by a later one
  if(solverBusy()) {
    CTX::instance()->launchSolverAtStartup = -1;
    return;
  }

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
    std::string db = onelabUtils::dbFileName();
    if(!StatFile(db)) {
      onelabUtils::loadDb(db);
      CTX::instance()->launchSolverAtStartup = -1;
    }
  }

  if(CTX::instance()->launchSolverAtStartup >= 0) {
    onelab_cb(nullptr, (void *)"reset");
    onelabUtils::setFirstComputationFlag(true);
  }
  else if(num >= 0)
    onelab_cb(nullptr, (void *)"check");
  else
    onelab_cb(nullptr, (void *)"refresh");
  // (the GUI may have been closed meanwhile)
  if(FlGui::available()) FlGui::instance()->onelab->updateGearMenu();

  CTX::instance()->launchSolverAtStartup = -1;
}

void onelab_cb(Fl_Widget *w, void *data)
{
  // not once the GUI is closed (by the events processed during a run that
  // called this one), which FlGui::instance() would build again
  if(!data || !FlGui::available()) return;

  std::string action((const char *)data);

  onelab::string o("ONELAB/Action", action);
  o.setVisible(false);
  o.setNeverChanged(true);
  o.setAttribute("Persistent", "1");
  onelab::server::instance()->set(o);

  if(action == "reload") {
    // for outside code that will want to rebuild the geometry
    return;
  }

  if(action == "refresh") {
    updateGraphs();
    FlGui::instance()->rebuildTree();
    return;
  }

  if(action == "stop") {
    FlGui::instance()->onelab->stop(true);
    FlGui::instance()->onelab->setRunState(onelabGroup::Stopping);
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
  }

  if(solverBusy()) return;
  // the rest reads the project again or meshes it: not during another
  // operation on the model
  if(modelBusy()) return;

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

  FlGui::instance()->onelab->setRunState(onelabGroup::Running);

  if(action == "compute") initializeLoops();

  do { // enter loop

    // run Gmsh client for non-metamodels
    if(onelabUtils::runGmshClient(action, CTX::instance()->solver.autoMesh))
      drawContext::global()->draw();
    // the GUI may have been closed while the events were processed (not
    // FlGui::instance(), which would build it again)
    if(!FlGui::available()) return;

    if(action == "compute") FlGui::instance()->onelab->checkForErrors("Gmsh");
    if(FlGui::instance()->onelab->stop()) break;

    // iterate over the solvers (there should normally only be one)
    for(auto it = onelab::server::instance()->firstClient();
        it != onelab::server::instance()->lastClient(); it++) {
      onelab::client *c = *it;
      if(!onelabUtils::isAutoRunSolver(c)) continue;
      onelabUtils::runSolver(c, action);
      if(!FlGui::available()) return;
      if(action == "compute")
        FlGui::instance()->onelab->checkForErrors(c->getName());
      if(FlGui::instance()->onelab->stop()) break;
    }

    if(action != "initialize") {
      updateGraphs();
      FlGui::instance()->rebuildTree();
      if(!FlGui::available()) return;
    }

  } while(action == "compute" && !FlGui::instance()->onelab->stop() &&
          incrementLoops());

  if(action == "compute" && onelabUtils::afterCompute()) {
    // (the archived files renamed in the tree)
    if(!FlGui::available()) return;
    FlGui::instance()->rebuildTree();
    if(!FlGui::available()) return;
  }

  FlGui::instance()->onelab->stop(false);
  FlGui::instance()->onelab->setRunState(onelabGroup::Idle);

  Msg::StatusBar(true, "Done");

  if(action != "initialize") FlGui::instance()->onelab->show();
}

// the automatic behaviours of the gear menu: the label, the field of
// CTX::instance()->solver toggled, its value when checked, and what to update
// after a change
struct gearOption {
  const char *label;
  int &(*field)();
  int on;
  void (*changed)();
};

static const std::vector<gearOption> &gearOptions()
{
  static const std::vector<gearOption> options = {
    {"Save database automatically",
     []() -> int & { return CTX::instance()->solver.autoSaveDatabase; }, 1},
    {"Load database automatically",
     []() -> int & { return CTX::instance()->solver.autoLoadDatabase; }, 1},
    {"Archive output files automatically",
     []() -> int & { return CTX::instance()->solver.autoArchiveOutputFiles; },
     1},
    {"Check model after each change",
     []() -> int & { return CTX::instance()->solver.autoCheck; }, 1,
     [] { FlGui::instance()->onelab->setButtonVisibility(); }},
    {"Remesh automatically",
     []() -> int & { return CTX::instance()->solver.autoMesh; }, 2},
    {"Merge results automatically",
     []() -> int & { return CTX::instance()->solver.autoMergeFile; }, 1},
    {"Show new views",
     []() -> int & { return CTX::instance()->solver.autoShowViews; }, 2},
    {"Always show last step",
     []() -> int & { return CTX::instance()->solver.autoShowLastStep; }, 1},
    {"Show hidden parameters",
     []() -> int & { return CTX::instance()->solver.showInvisibleParameters; },
     1, [] { FlGui::instance()->onelab->rebuildTree(); }},
  };
  return options;
}

// data: the index of the option in gearOptions()
static void onelab_option_cb(Fl_Widget *w, void *data)
{
  const gearOption &o = gearOptions()[(intptr_t)data];
  o.field() = ((Fl_Menu_ *)w)->mvalue()->value() ? o.on : 0;
  if(o.changed) o.changed();
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

void onelabGroup::_computeWidths()
{
  // "- 1.1 * FL_NORMAL_SIZE" to have space for a scrollbar to the right
  _baseWidth = _tree->w() - _tree->marginleft() - 1.1 * FL_NORMAL_SIZE;
  // not sure why we have the "-2" correction at the end, but this is what is
  // needed to make things pixel-correct.
  _indent = _tree->connectorwidth() / 2. + _tree->openicon()->w() / 2. - 2.;
}

// the background of the tree: under the gmsh theme between the one of the
// window, as the tools, and the one of the lists, which it is otherwise,
// closer to the latter
static Fl_Color treeColor()
{
  if(!gmshScheme()) return FL_BACKGROUND2_COLOR;
  return fl_color_average(FL_BACKGROUND2_COLOR, FL_BACKGROUND_COLOR, 0.55f);
}

// the lines joining the items: under the gmsh theme fainter than the
// triangles, which carry the structure
static Fl_Color connectorColor()
{
  if(!gmshScheme()) return FL_INACTIVE_COLOR;
  return fl_color_average(treeColor(), FL_FOREGROUND_COLOR, 0.76f);
}

// every row of the tree is this tall, whether it holds a label, a button or
// the field of a parameter: the rows take their height from their widgets
// (see FL_TREE_ITEM_HEIGHT_FROM_WIDGET), which all get it; 22 pixels at the
// default size, between the 18 of a label alone and the 23 the fields had
static int rowHeight() { return FL_NORMAL_SIZE + 8 + gmshAir(); }

// a click on the row of a branch, not only on its triangle, opens or closes
// it, and the row is tinted under the pointer as the other controls are; the
// names of the view groups and of the physical groups are buttons with an
// action of their own
class onelabTree : public Fl_Tree {
private:
  // the depth of the events passed on to all the rows, see broadcasting()
  int _broadcasting = 0;
  // the branch under the pointer, highlighted (compared only: a rebuild of
  // the tree deletes the items)
  Fl_Tree_Item *_hovered = nullptr;
  // the branch on the row of the last event, if any
  Fl_Tree_Item *_branchAtEvent()
  {
    Fl_Tree_Item *item = find_clicked(0);
    if(item && item->has_children() &&
       !dynamic_cast<Fl_Button *>(item->widget()))
      return item;
    return nullptr;
  }
  // the branch under the pointer, if the pointer is in the tree and not on
  // a button of the row, which tints itself (the switch of a group of views)
  Fl_Tree_Item *_branchBelowMouse()
  {
    Fl_Widget *b = Fl::belowmouse();
    if(!b || !contains(b)) return nullptr;
    if(b != this && dynamic_cast<Fl_Button *>(b)) return nullptr;
    return _branchAtEvent();
  }
  void draw() override
  {
    // the background, with the row of the hovered branch tinted under the
    // items: from its label to where the widgets of the items end, all on
    // one line leaving room for the scrollbar (see
    // onelabGroup::_computeWidths())
    if(damage() & ~FL_DAMAGE_CHILD) {
      fl_rectf(x(), y(), w(), h(), color());
      if(Fl_Tree_Item *item = _branchBelowMouse()) {
        Fl_Widget *box = item->widget();
        int right =
          box ? box->x() + box->w() : x() + w() - 1.1 * FL_NORMAL_SIZE;
        // up to the switch of a group of views, which tints on its own
        if(Fl_Group *g = box ? box->as_group() : nullptr)
          if(g->children() > 1) right = g->child(g->children() - 1)->x();
        fl_color(hoverHighlight(color()));
        fl_rectf(item->label_x(), item->y(), right - item->label_x(),
                 item->h());
      }
    }
    Fl_Tree::draw();
  }

public:
  onelabTree(int x, int y, int w, int h) : Fl_Tree(x, y, w, h)
  {
    box(FL_NO_BOX); // drawn in draw()
    item_draw_mode(FL_TREE_ITEM_HEIGHT_FROM_WIDGET);
  }
  // whether an event is being passed along the rows (the window hidden or
  // shown, a shortcut offered to each, a key moving the focus to the next):
  // FLTK goes through the array of the rows meanwhile, which a rebuild would
  // replace, e.g. asked by an edited value that the event commits (see
  // onelabGroup::rebuildTree())
  bool broadcasting() const { return _broadcasting > 0; }
  int handle(int event) override
  {
    if(event == FL_HIDE || event == FL_SHOW || event == FL_ACTIVATE ||
       event == FL_DEACTIVATE || event == FL_KEYBOARD || event == FL_SHORTCUT ||
       event == FL_FOCUS) {
      Fl_Widget_Tracker alive(this);
      _broadcasting++;
      int ret = Fl_Tree::handle(event);
      if(alive.exists()) _broadcasting--;
      return ret;
    }
    Fl_Widget_Tracker alive(this);
    int rootX = Fl::event_x_root(), rootY = Fl::event_y_root();
    int ret = Fl_Tree::handle(event);
    if(!alive.exists()) return ret;
    switch(event) {
    case FL_PUSH:
      // not after a popup menu of a row (the choices of a field) took the
      // click: its events were handled meanwhile, the last one (the choice)
      // in place of the click, at the place of the choice in the menu
      if(Fl::event() != FL_PUSH || Fl::event_x_root() != rootX ||
         Fl::event_y_root() != rootY)
        break;
      if(Fl::event_button() == FL_LEFT_MOUSE) {
        // not when a widget of the row took the click (the switch of a group
        // of views): FLTK has noted it as pushed
        Fl_Widget *p = Fl::pushed();
        bool onWidget = p && p != this && contains(p);
        Fl_Tree_Item *item = _branchAtEvent();
        if(item && !onWidget && !item->event_on_collapse_icon(prefs()))
          open_toggle(item);
      }
      break;
    case FL_ENTER:
    case FL_MOVE:
    case FL_LEAVE:
      if(_branchBelowMouse() != _hovered) {
        _hovered = _branchBelowMouse();
        redraw();
      }
      break;
    }
    return ret;
  }
};

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x, y, w, h, l), _firstGearOption(0), _state(Idle), _stop(false), _firstBuild(true), _hasContext(false)
{
  Fl_Color col = treeColor();
  color(col);

  box(GMSH_SIMPLE_RIGHT_BOX);
  int dx = Fl::box_dx(box());
  int dy = Fl::box_dy(box());
  int dw = Fl::box_dw(box());
  int dh = Fl::box_dh(box());

  _tree = new onelabTree(x + dx, y + dy, w - dw, h - dh - BH - 2 * WB);
  _tree->color(col);
  _tree->callback(onelab_tree_cb);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->connectorcolor(connectorColor());
  _tree->showroot(0);
  // under the gmsh theme the items are spaced out more than its widgets
  _tree->linespacing(2 * gmshAir());
  _tree->end();

  // dummy values for now; will be updated with _computeWidths()
  _baseWidth = _tree->w() - _tree->marginleft();
  _indent = _tree->connectorwidth();

  int BB2 = BB / 2 + 4;

  _butt[0] =
    new Fl_Button(x + w - 3 * WB - 3 * BB2, y + h - WB - BH, BB2, BH, "Check");
  _butt[0]->callback(onelab_cb, (void *)"check");

  _butt[1] =
    new Fl_Button(x + w - 2 * WB - 2 * BB2, y + h - WB - BH, BB2, BH, "Run");
  _butt[1]->callback(onelab_cb, (void *)"compute");

  _gear = new Fl_Menu_Button(x + w - WB - BB2, y + h - WB - BH, BB2, BH);
  gmshIcon(_gear, "gear", FL_NORMAL_SIZE + 2);
  _gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _gear->add("Reset database", 0, onelab_cb, (void *)"reset");
  _gear->add("Save database...", 0, onelab_cb, (void *)"save");
  _gear->add("_Load database...", 0, onelab_cb, (void *)"load");

  _minWindowWidth = 3 * BB2 + 4 * WB;
  _minWindowHeight = 2 * BH + 3 * WB;

  // the automatic behaviours, the items _firstGearOption on
  for(std::size_t i = 0; i < gearOptions().size(); i++) {
    bool last = (i == gearOptions().size() - 1);
    int item = _gear->add(gearOptions()[i].label, 0, onelab_option_cb,
                          (void *)(intptr_t)i,
                          FL_MENU_TOGGLE | (last ? FL_MENU_DIVIDER : 0));
    if(!i) _firstGearOption = item;
  }

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
    c = fl_rgb_color(r, g, b);
    return true;
  }
  c = FL_BLACK;
  return false;
}

int onelabGroup::_rowWidth(Fl_Tree_Item *n)
{ return (int)(_baseWidth - (n->depth() + 1) * _indent); }

void onelabGroup::_addRow(Fl_Tree_Item *n,
                          const std::function<void(int ww, int hh)> &make)
{
  int ww = _rowWidth(n), hh = rowHeight();
  _tree->begin();
  Fl_Group *grp = new Fl_Group(1, 1, ww, hh);
  make(ww, hh);
  grp->end();
  grp->resizable(nullptr); // the widgets keep their size
  _tree->end();
  _treeWidgets.push_back(grp);
  n->widget(grp);
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
  _addRow(n, [&](int ww, int hh) {
    const double labelRatio = 0.5; // the field, then its label
    // (the callbacks find the parameter by its name, not by the item's path,
    // which FLTK escapes and splits differently)
    Fl_Widget *widget =
      addParameterWidget(p, 1, 1, ww * labelRatio, hh, labelRatio, p.getName(),
                         highlight, c, _tree->color(), _treeStrings);
    widget->copy_label(p.getShortName().c_str());
    std::string help = p.getHelp();
    if(help.empty()) help = p.getLabel();
    if(help.empty()) help = p.getShortName();
    ReplaceSubStringInPlace("\r", "",
                            help); // remove carriage return characters
    widget->copy_tooltip(help.c_str());
  });
}

void onelabGroup::_addMenu(const std::string &path, Fl_Callback *callback,
                           void *data, const std::string &help)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", path.c_str());
    return;
  }
  _addRow(n, [&](int ww, int hh) {
    Fl_Button *but = new Fl_Button(1, 1, ww, hh);
    but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    but->callback(callback, data);
    but->box(FL_FLAT_BOX);
    but->color(_tree->color());
    but->selection_color(_tree->color());
    std::string label = path;
    std::string::size_type last = path.find_last_of('/');
    if(last != std::string::npos) label = path.substr(last + 1);
    but->copy_label(label.c_str());
    if(help.size()) but->copy_tooltip(help.c_str());
  });
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
  _addRow(n, [&](int ww, int hh) {
    new solverButton(1, 1, ww, hh, num, _tree->color());
  });
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
  _addRow(n, [&](int ww, int hh) {
    new viewButton(1, 1, ww, hh, num, _tree->color());
  });
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

// after a parameter changed in the tree (onelabUtils::setParameter(), which
// says what to do next)
static void parameterChanged(int what)
{
  if(!FlGui::available()) return;
  if(what & onelabUtils::ParameterRebuild) FlGui::instance()->rebuildTree();
  if(what & onelabUtils::ParameterOption) drawContext::global()->draw();
  if(what & onelabUtils::ParameterCheck) onelab_cb(nullptr, (void *)"check");
}

static void onelab_number_check_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::number> numbers;
  onelab::server::instance()->get(numbers, name);
  if(numbers.size()) {
    Fl_Check_Button *o = (Fl_Check_Button *)w;
    numbers[0].setValue(o->value());
    parameterChanged(onelabUtils::setParameter(numbers[0]));
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
    if(o->value() < (int)choices.size())
      numbers[0].setValue(choices[o->value()]);
    parameterChanged(onelabUtils::setParameter(numbers[0]));
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
    int what = onelabUtils::setParameter(numbers[0]);
    updateGraphs();
    parameterChanged(what);
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
    updateGraphs();
  }
}

Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings)
{
  strings.push_back(ppath);
  const char *path = strings.back().c_str();

  // enumeration (display choices as value labels, not numbers)
  if(p.getChoices().size() &&
     p.getChoices().size() == p.getValueLabels().size()) {
    Fl_Choice *but = new Fl_Choice(xx, yy, ww, hh);
    std::vector<Fl_Menu_Item> menu;
    std::vector<double> choices = p.getChoices();
    std::map<double, std::string> labels(p.getValueLabels());
    for(std::size_t i = 0; i < choices.size(); i++) {
      strings.push_back(labels[choices[i]]);
      Fl_Menu_Item menuItem = {strings.back().c_str(), 0, nullptr, nullptr, 0};
      if(highlight) menuItem.labelcolor(adaptedText(c));
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
      but->color(adaptedFill(c));
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    if(p.getReadOnly()) but->deactivate();
    return but;
  }

  // non-editable value
  if(p.getReadOnly()) {
    outputRange *but = new outputRange(xx, yy, ww, hh,
                                       onelab::parameter::maxNumber());
    but->callback(onelab_number_output_range_cb, (void *)path);
    but->numberFormat(p.getAttribute("NumberFormat"));
    but->value(p.getValue());
    but->minimum(p.getMin());
    but->maximum(p.getMax());
    but->step(p.getStep());
    but->choices(p.getChoices());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    but->graph(p.getAttribute("Graph"));
    if(highlight) but->color(adaptedFill(c));
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
  // (the step is kept even when the input does not scroll: see inputRange)
  but->step(p.getStep());
  but->choices(p.getChoices());
  but->loop(p.getAttribute("Loop"));
  but->graph(p.getAttribute("Graph"));
  but->callback(onelab_number_input_range_cb, (void *)path);
  but->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) but->color(adaptedFill(c));
  return but;
}

static void onelab_string_button_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  std::string name((char *)data);
  std::vector<onelab::string> strings;
  onelab::server::instance()->get(strings, name);
  if(strings.size()) {
    // a script parsed or a file merged change the model: not during another
    // operation on it
    if(strings[0].getAttribute("Macro") != "Action" && modelBusy()) return;
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
    // as the script or the file left it
    onelab::server::instance()->get(strings, name);
    if(strings.size())
      parameterChanged(onelabUtils::setParameter(strings[0], true));
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
    strings[0].setValue(o->value());
    parameterChanged(onelabUtils::setParameter(strings[0]));
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
    parameterChanged(onelabUtils::setParameter(strings[0]));
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
  editFile(but->value());
}

static void onelab_input_choice_file_merge_cb(Fl_Widget *w, void *data)
{
  if(modelBusy()) return;
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
                              std::list<std::string> &strings)
{
  strings.push_back(ppath);
  const char *path = strings.back().c_str();

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
      but->color(adaptedFill(c));
      but->labelcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
    }
    return but;
  }

  // non-editable value
  if(p.getReadOnly() && p.getKind() != "file") {
    Fl_Output *but = new Fl_Output(xx, yy, ww, hh);
    but->value(p.getValue().c_str());
    but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
    if(highlight) {
      but->color(adaptedFill(c));
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
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
      but->color(adaptedFill(c));
      but->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
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
    strings.push_back(p.getChoices()[j]);
    const char *str = strings.back().c_str();
    bool divider = ((p.getKind() == "file" || multipleSelection.size()) &&
                    j == p.getChoices().size() - 1);
    int choice = multipleSelection.size() ? FL_MENU_TOGGLE : 0;
    if(multipleSelection.size() > j && multipleSelection[j] == '1')
      choice |= FL_MENU_VALUE;
    Fl_Menu_Item it = {str, 0, nullptr, nullptr,
                       (int)(choice | (divider ? FL_MENU_DIVIDER : 0))};
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
  // and the widget calls back on both: FLTK 1.5 passes on an Enter only with
  // FL_WHEN_CHANGED (on the menu, its choices call back as before)
  but->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);
  but->align(FL_ALIGN_RIGHT | FL_ALIGN_CLIP);
  if(highlight) {
    but->input()->color(adaptedFill(c));
    but->input()->textcolor(fl_contrast(FL_FOREGROUND_COLOR, adaptedFill(c)));
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
  // the views of the group and of its subgroups ("Res" and "Res/a", not
  // "Results")
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    PViewOptions *opt = PView::list[i]->getOptions();
    std::string g = opt->group;
    while(g.size() && g[0] == '/') g = g.substr(1);
    if(g == group || g.compare(0, group.size() + 1, group + "/") == 0)
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

onelabGroup::~onelabGroup() { Fl::remove_timeout(_rebuildAfterPress, this); }

void onelabGroup::_rebuildAfterPress(void *data)
{
  onelabGroup *g = (onelabGroup *)data;
  if((Fl::pushed() && g->_tree->contains(Fl::pushed())) ||
     ((onelabTree *)g->_tree)->broadcasting())
    Fl::repeat_timeout(0.05, _rebuildAfterPress, data);
  else
    g->rebuildTree();
}

void onelabGroup::rebuildTree()
{
  // only in the thread of the GUI (e.g. not from a thread of an API program
  // that holds the lock)
  if(!FlGui::onMainThread()) return;

  // not while a mouse button is held down over the tree: the press and the
  // release of a click go to the same widget, and the click is lost if a
  // rebuild replaces it in between (a computation rebuilds the tree several
  // times a second); done once the button is released
  // nor while an event goes through all the rows (see
  // onelabTree::broadcasting())
  if((Fl::pushed() && _tree->contains(Fl::pushed())) ||
     ((onelabTree *)_tree)->broadcasting()) {
    if(!Fl::has_timeout(_rebuildAfterPress, this))
      Fl::add_timeout(0.05, _rebuildAfterPress, this);
    return;
  }

  // asked for while the tree is emptied and built (see _rebuildTree()): done
  // once this rebuild is over; this tree may be gone after the events
  // processed (the GUI closed; not FlGui::available(), false while the GUI is
  // built, with its tree)
  Fl_Widget_Tracker alive(this);
  _rebuilds.run([&] {
    _rebuildTree();
    return alive.exists();
  });
}

void onelabGroup::_rebuildTree()
{
  // The rows are deleted after FlGui::check() below, but a row an event being
  // handled was sent to (e.g. an edited value, whose autoCheck may rebuild the
  // tree more than once) is retired (see FlGui::retireInEvent()); the strings
  // of the others are freed when the rebuild is over
  std::vector<Fl_Widget *> old = _treeWidgets;
  std::list<std::string> delStrings;
  delStrings.swap(_treeStrings);
  std::vector<Fl_Widget *> delWidgets = FlGui::retireInEvent(old, delStrings);
  _treeWidgets.clear();

  // hide all the widgets we have added in the tree to make sure they don't get
  // spurious events (until they are deleted); hiding an edited input runs its
  // callback, which may ask for a rebuild (see rebuildTree()) or close the GUI,
  // and may run a computation meanwhile: the tree still has its items then
  Fl_Widget_Tracker alive(this);
  for(auto w : old) {
    w->hide();
    if(!alive.exists()) return;
  }

  setButtonVisibility();

  std::set<std::string> closed = _getClosedGmshMenus();

  _tree->clear();

  // the colours follow the colour scheme, which may have changed
  color(treeColor());
  _tree->color(treeColor());
  _tree->connectorcolor(connectorColor());
  if(CTX::instance()->guiDark) {
    _tree->openicon(&open_pixmap_dark);
    _tree->closeicon(&close_pixmap_dark);
  }
  else {
    _tree->openicon(&open_pixmap_light);
    _tree->closeicon(&close_pixmap_light);
  }
  _tree->sortorder(FL_TREE_SORT_ASCENDING);
  _tree->selectmode(FL_TREE_SELECT_NONE);

  FL_NORMAL_SIZE -= CTX::instance()->deltaFontSize;
  _computeWidths(); // at the font size of the tree

  if(CTX::instance()->showModuleMenu) _addGmshMenus();

  // the parameters, numbers then strings, but the invisible ones and those of
  // the context window (unless asked for)
  auto addParameters = [&](auto &parameters) {
    onelab::server::instance()->get(parameters);
    for(auto &p : parameters) {
      if(p.getAttribute("Closed") == "1") closed.insert(p.getPath());
      if((!p.getVisible() ||
          p.getName().find("ONELAB Context/") != std::string::npos) &&
         !CTX::instance()->solver.showInvisibleParameters)
        continue;
      _addParameter(p);
    }
  };
  std::vector<onelab::number> numbers;
  addParameters(numbers);
  std::vector<onelab::string> strings;
  addParameters(strings);

  // check if there are some "ONELAB Context" variables, in which case
  // double-clicking on an entity opens the ONELAB context window to edit the
  // parameters linked to the entity
  std::vector<std::string> names;
  onelab::server::instance()->getParameterNames(names, "ONELAB Context");
  setContext(!names.empty());

  // the label of a branch, without the digits that sort it, in a box; a
  // group of views has a switch of their visibility beside it, where the
  // views have their menu arrow; a physical group is a button
  const std::string views = "0Modules/Post-processing",
                    physical = "Physical group: ";
  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next()) {
    if(n->has_children()) {
      int ww = _rowWidth(n), hh = rowHeight();
      _tree->begin();
      Fl_Widget *but, *row = nullptr;
      std::string path = getPath(n);
      std::string::size_type pos;
      if((pos = path.find(views)) != std::string::npos) {
        int bw = FL_NORMAL_SIZE + 2;
        row = new Fl_Group(1, 1, ww, hh);
        but = new Fl_Box(1, 1, ww - bw, hh);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        Fl_Button *sw = new Fl_Button(1 + ww - bw, 1, bw, hh);
        sw->box(FL_NO_BOX);
        sw->color(_tree->color());
        sw->selection_color(_tree->color());
        sw->tooltip("Toggle visibility of child views");
        gmshIcon(sw, "eye", FL_NORMAL_SIZE);
        // (the path of the group under the module)
        _treeStrings.push_back(path.substr(pos + views.size()));
        sw->callback(view_group_cb, (void *)_treeStrings.back().c_str());
        ((Fl_Group *)row)->end();
      }
      else if((pos = path.find(physical)) != std::string::npos) {
        but = new Fl_Button(1, 1, ww, hh);
        but->box(FL_NO_BOX);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        but->tooltip("Toggle highlight of physical group");
        // (the name of the group)
        _treeStrings.push_back(path.substr(pos + physical.size()));
        but->callback(highlight_physical_group_cb,
                      (void *)_treeStrings.back().c_str());
      }
      else {
        but = new Fl_Box(1, 1, ww, hh);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      }
      if(!row) row = but;
      _treeWidgets.push_back(row);
      onelab::string o(n->label());
      but->copy_label(o.getShortName().c_str());
      n->widget(row);
      _tree->end();
    }
  }

  for(auto it = closed.begin(); it != closed.end(); it++) {
    if(it->size()) _tree->close(it->c_str(), 0);
  }

  _tree->redraw();

  FL_NORMAL_SIZE += CTX::instance()->deltaFontSize;

  // built: a rebuild asked for by the events processed below is done at once
  // (e.g. while a computation started by one of them runs)
  _rebuilds.made();
  FlGui::check(true); // necessary e.g. on windows to avoid "ghosting"

  // the GUI may have been closed during the check, its widgets with it
  if(!alive.exists()) return;

  // this needs to be performed after FlGui::check()
  Msg::Debug("Deleting onelabGroup widgets (%d)", (int)delWidgets.size());
  for(Fl_Widget *w : delWidgets) Fl::delete_widget(w);
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

bool onelabGroup::isTreeItemOpen(const std::string &name) {
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if (n != NULL) {
    if(n->is_open()){
      return true;
    }
  }
  return false;
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
    // (the tree is rebuilt while a solver runs too, which keeps its Stop)
    setRunState(_state);
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

void onelabGroup::setRunState(runState state)
{
  _state = state;
  // custom button behavior, while idle
  std::vector<onelab::string> ps;
  onelab::server::instance()->get(ps, "ONELAB/Button");
  if(state == Idle && ps.size() && ps[0].getValues().size() == 2) {
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

  // Check and Run while idle; while a solver runs, Stop (and Kill once asked
  // to stop), and only the automatic behaviours of the gear menu can change
  if(state == Idle) {
    _butt[0]->activate();
    _butt[0]->label("Check");
    _butt[0]->callback(onelab_cb, (void *)"check");
    _butt[1]->activate();
    _butt[1]->label("Run");
    _butt[1]->callback(onelab_cb, (void *)"compute");
    _activateGearMenu(true);
  }
  else {
    _butt[0]->deactivate();
    _butt[1]->activate();
    _butt[1]->label(state == Running ? "Stop" : "Kill");
    _butt[1]->callback(onelab_cb,
                       state == Running ? (void *)"stop" : (void *)"kill");
    _activateGearMenu(false);
  }
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
  for(std::size_t i = 0; i < gearOptions().size(); i++) {
    if(gearOptions()[i].field())
      menu[_firstGearOption + i].set();
    else
      menu[_firstGearOption + i].clear();
  }
}

void onelabGroup::_activateGearMenu(bool all)
{
  Fl_Menu_Item *menu = (Fl_Menu_Item *)_gear->menu();
  int n = (int)gearOptions().size();
  for(int i = 0; i < _gear->size() - 1; i++) {
    if(all || (i >= _firstGearOption && i < _firstGearOption + n))
      menu[i].activate();
    else
      menu[i].deactivate();
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

  rebuildTree();
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

// The rows of the modules of the tree (Geometry, Mesh) from the action
// registry (see Actions.h and actionMenus.cpp)

static void item_button_cb(Fl_Widget *w, void *data)
{ runItem(*(const actionItem *)data, -1); }

// the buttons of a module (see Actions.cpp) as rows of the tree, a menu as a
// row that pops it up, its submenus as submenus
void onelabGroup::_addModuleButtons(const std::string &module)
{
  for(const actionItem &row : GetActionMenu(module).items) {
    for(const actionItem &b : row.items) {
      std::string path = "0Modules/" + module + "/" + b.label;
      if(b.kind != ItemMenu) {
        if(canRunItem(b)) _addMenu(path, item_button_cb, (void *)&b, b.help);
        continue;
      }
      if(!canRunAnyItem(b)) continue;
      Fl_Tree_Item *n = _tree->add(path.c_str());
      if(!n) {
        Msg::Debug("Could not add item '%s' in tree", path.c_str());
        continue;
      }
      _addRow(n, [&](int ww, int hh) {
        // (its label where a button has it, 3 pixels in)
        Fl_Menu_Button *but = new Fl_Menu_Button(4, 1, ww - 3, hh);
        but->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
        but->box(FL_FLAT_BOX);
        but->color(_tree->color());
        but->selection_color(_tree->color());
        but->copy_label(b.label.c_str());
        but->copy_tooltip(b.help.c_str());
        addMenuItems(but, b, -1);
      });
    }
  }
}

void onelabGroup::_addGmshMenus()
{
  _tree->sortorder(FL_TREE_SORT_NONE);

  _addModuleButtons("Geometry");
#if defined(HAVE_MESH)
  _addModuleButtons("Mesh");
#endif

  // add dynamic solver module items
  for(int i = 0; i < NUM_SOLVERS; i++) {
    std::string name = opt_solver_name(i, GMSH_GET, "");
    if(name.size()) _addSolverMenu(i);
  }

  // add dynamic post-processing module items
  for(std::size_t i = 0; i < PView::list.size(); i++) _addViewMenu(i);

  _tree->sortorder(FL_TREE_SORT_ASCENDING);

  if(_firstBuild) {
    _firstBuild = false;
    Fl_Tree_Item *n0 = _tree->find_item("0Modules");
    for(Fl_Tree_Item *n = n0; n; n = n->next()) {
      if(!n->is_root() && n->has_children() && n->depth() > 1) n->close();
    }
  }
}

std::set<std::string> onelabGroup::_getClosedGmshMenus()
{
  std::set<std::string> closed;
  Fl_Tree_Item *n0 = _tree->find_item("0Modules");
  for(Fl_Tree_Item *n = n0; n; n = n->next()) {
    if(!n->is_root() && n->has_children() && n->is_close()) {
      char path[1024];
      _tree->item_pathname(path, sizeof(path), n);
      closed.insert(path);
    }
  }
  return closed;
}
