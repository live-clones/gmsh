// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "treeFltk.h"
#include "GuiModules.h"
#include <functional>
#include "GuiActions.h"
#include "GuiOnelab.h"
#include "GuiMenus.h"
#include "menuFltk.h"
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
  solverStart(num); // compacts the solver list itself
  if(solverIsRunning()) FlGui::instance()->onelab->show();
}

void onelab_cb(Fl_Widget *w, void *data)
{
  if(!data) return;
  // the whole logic lives in GuiActions.cpp, shared with the other interfaces
  onelabRun(std::string((const char *)data));
  if(std::string((const char *)data) != "initialize")
    FlGui::instance()->onelab->show();
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
  // "- 1.1 * FL_NORMAL_SIZE" to have space for a scrollbar to the right
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

  _widgetLabelRatio = 0.5;

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

  // What it drops is described once in src/common/GuiMenus.cpp: the thirteen
  // entries used to be written out here, with the places of the nine that are
  // switches kept in two indices so that their check marks could be set again
  // by hand at every rebuild.
  _gear = new popupButtonFltk(x + w - WB - BB2, y + h - WB - BH, BB2, BH);
#if defined(__APPLE__)
  _gear->label("@-1gmsh_gear");
#else
  _gear->image(new Fl_Bitmap(gear_bits, gear_width, gear_height));
#endif
  _gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _gear->key = "gear";
  _gear->what = Menu::solverOptions;

  _minWindowWidth = 3 * BB2 + 4 * WB;
  _minWindowHeight = 2 * BH + 3 * WB;

  end();

  Fl_Box *resbox = new Fl_Box(x + WB, y + WB, WB, WB);
  resizable(resbox);

  rebuildSolverList();
}


// One line the description gives a widget to: a parameter a solver has
// published, a view, whatever it is. What the widget is and what it is bound
// to are the description's; all this does is put it on the line.
void onelabGroup::_addField(const std::string &path, const Ui::Node &node)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  if(!n) {
    Msg::Debug("Could not add item '%s' in tree", path.c_str());
    return;
  }
  n->labelsize(FL_NORMAL_SIZE + 4);
  _tree->begin();
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  Fl_Group *grp = fltkTreeField(node.field, 1, 1, ww, hh, _widgetLabelRatio,
                                node.highlight, _tree->color());
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  _treeWidgets.push_back(grp);
  if(node.tooltip.size()) {
    std::string help = node.tooltip;
    ReplaceSubStringInPlace("\r", "", help);
    grp->copy_tooltip(help.c_str());
  }
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
  _computeWidths();

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

  // What the description holds beside the commands: every root of the tree
  // that is not the commands themselves, and everything under it. The lines
  // that carry a widget are the parameters a solver has published; which they
  // are, what each is worth and what changing one does is all said in
  // src/common/GuiModules.cpp.
  {
    Ui::Tree tree = Modules::tree();
    std::function<void(const std::string &)> walk =
      [&](const std::string &path) {
        for(const auto &child : tree.children(path)) {
          Ui::Node node = tree.node(child);
          if(node.hasField) {
            if(node.closed) closed.insert(child);
            _addField(child, node);
          }
          walk(child);
        }
      };
    for(const auto &root : tree.children("")) {
      if(root == "0Modules") continue;
      walk(root);
    }
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

bool onelabGroup::isTreeItemOpen(const std::string &name) {
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  if (n != NULL) {
    if(n->is_open()){
      return true;
    }
  }
  return false;
}

bool onelabGroup::stop() { return solverStopRequested(); }
void onelabGroup::stop(bool val) { solverRequestStop(val); }

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
  }
  else if(butt1 == "stop") {
    _butt[1]->activate();
    _butt[1]->label("Stop");
    _butt[1]->callback(onelab_cb, (void *)"stop");
  }
  else if(butt1 == "kill") {
    _butt[1]->activate();
    _butt[1]->label("Kill");
    _butt[1]->callback(onelab_cb, (void *)"kill");
  }
  else {
    _butt[1]->deactivate();
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

void onelabGroup::rebuildSolverList()
{
  // the option bookkeeping is shared with the other interfaces
  solverListCompact();
  rebuildTree(true);
}


void onelabGroup::addSolver(const std::string &name,
                            const std::string &executable,
                            const std::string &remoteLogin, int index)
{
  solverAdd(name, executable, remoteLogin, index);
  rebuildSolverList();
}
