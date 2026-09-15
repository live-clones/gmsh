// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <deque>
#include <string>
#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>

#include "onelabGroup.h"
#include "treeFltk.h"
#include "menuFltk.h"
#include "paletteWindow.h"
#include "uiSources.h"
#include "FlGui.h"
#include "treeIcons.h"

// This file reads the modules tree from its description, which is all it
// knows: what is under a path, what a node holds, whether it is folded,
// and what the buttons under the tree are.

namespace {

  // what a line's widget calls back with: FLTK hands a widget a void*, and
  // a deque keeps the addresses steady as lines are added
  std::deque<std::function<void()> > _pressed;
  std::deque<Ui::Button> _buttons;

  // copied before it is called: what it does may build the tree, or the
  // row of buttons, again -- and with it the list this one is in
  void _press(Fl_Widget *w, void *data)
  {
    std::function<void()> what = *(std::function<void()> *)data;
    if(what) what();
  }

  void _pressButton(Fl_Widget *w, void *data)
  {
    std::function<void()> what = ((Ui::Button *)data)->action;
    if(what) what();
  }

#if !defined(__APPLE__)
#define gear_width 16
#define gear_height 16
  unsigned char gear_bits[] = {
    0x80, 0x01, 0x80, 0x01, 0x8c, 0x31, 0xfc, 0x3f, 0xf8, 0x1f, 0xf8,
    0x1f, 0x38, 0x1c, 0x3f, 0xfc, 0x3f, 0xfc, 0x38, 0x1c, 0xf8, 0x1f,
    0xf8, 0x1f, 0xfc, 0x3f, 0x8c, 0x31, 0x80, 0x01, 0x80, 0x01};
#endif

} // namespace

// folding a branch by hand is the tree's to remember, not this widget's
void onelabGroup::_treeCallback(Fl_Widget *w, void *data)
{
  onelabGroup *self = (onelabGroup *)data;
  Fl_Tree *tree = (Fl_Tree *)w;
  Fl_Tree_Item *item = (Fl_Tree_Item *)tree->callback_item();
  if(!item) return;
  int reason = tree->callback_reason();
  if(reason != FL_TREE_REASON_OPENED && reason != FL_TREE_REASON_CLOSED)
    return;
  const Ui::Tree &said = fltkSources().tree;
  if(said.setClosed)
    said.setClosed(self->getPath(item), reason == FL_TREE_REASON_CLOSED);
}

void onelabGroup::_computeWidths()
{
  // "- 1.1 * FL_NORMAL_SIZE" to have space for a scrollbar to the right
  _baseWidth = _tree->w() - _tree->marginleft() - 1.1 * FL_NORMAL_SIZE;
  // not sure why we need the "-2" correction at the end, but this is what is
  // needed to make things pixel-correct.
  _indent = _tree->connectorwidth() / 2. + _tree->openicon()->w() / 2. - 2.;
}

onelabGroup::onelabGroup(int x, int y, int w, int h, const char *l)
  : Fl_Group(x, y, w, h, l), _enableTreeWidgetResize(false), _firstBuild(true)
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
  _tree->callback(_treeCallback, this);
  _tree->connectorstyle(FL_TREE_CONNECTOR_SOLID);
  _tree->showroot(0);
  _tree->box(FL_FLAT_BOX);
  _tree->end();

  _widgetLabelRatio = 0.5;

  // dummy values for now; will be updated with _computeWidths()
  _baseWidth = _tree->w() - _tree->marginleft();
  _indent = _tree->connectorwidth();

  int BB2 = BB / 2 + 4;
  _minWindowWidth = 3 * BB2 + 4 * WB;
  _minWindowHeight = 2 * BH + 3 * WB;

  end();

  Fl_Box *resbox = new Fl_Box(x + WB, y + WB, WB, WB);
  resizable(resbox);

  rebuildTree(true);
}

// one line of the tree: a branch is its name, pressed when the
// description says pressing it does something; a leaf is the field the
// description gives it, or a button that presses it; either may drop a
// menu, on the little arrow at the right end of the line
void onelabGroup::_addLine(const std::string &path, const Ui::Node &node,
                           bool branch)
{
  Fl_Tree_Item *n = _tree->add(path.c_str());
  if(!n) return;
  std::string label = node.label.size() ?
                        node.label :
                        path.substr(path.find_last_of('/') + 1);
  if(node.hasField) n->labelsize(FL_NORMAL_SIZE + 4);
  int ww = (int)(_baseWidth - (n->depth() + 1) * _indent);
  int hh = n->labelsize() + 4;
  int popw = node.menu ? FL_NORMAL_SIZE + 2 : 0;
  _tree->begin();
  Fl_Group *grp = nullptr;
  if(node.hasField) {
    // the value takes the line; a switch that says nothing itself is named
    // by the line
    Ui::Field f = node.field;
    if(f.label.empty() && (f.kind == Ui::Check || f.kind == Ui::Action))
      f.label = label;
    grp = fltkTreeField(f, 1, 1, ww - popw, hh, _widgetLabelRatio,
                        node.highlight, _tree->color());
  }
  else {
    grp = new Fl_Group(1, 1, ww, hh);
    Fl_Widget *say;
    if(node.pressed) {
      _pressed.push_back(node.pressed);
      Fl_Button *but = new Fl_Button(1, 1, ww - popw, hh);
      but->box(FL_FLAT_BOX);
      but->color(_tree->color());
      but->selection_color(_tree->color());
      but->callback(_press, &_pressed.back());
      say = but;
    }
    else
      say = new Fl_Box(1, 1, ww - popw, hh);
    say->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    say->copy_label(label.c_str());
    if(node.enabled && !node.enabled()) say->deactivate();
    grp->end();
  }
  if(node.menu) {
    grp->begin();
    Fl_Button *arrow = new Fl_Button(1 + ww - popw, 1, popw, hh, "@>");
    arrow->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    arrow->box(FL_FLAT_BOX);
    arrow->color(_tree->color());
    arrow->selection_color(_tree->color());
    popupButtonFltk *popup = new popupButtonFltk(1 + ww - popw, 1, popw, hh);
    popup->box(FL_NO_BOX);
    popup->key = branch ? "branch" : "line";
    popup->what = node.menu;
    grp->end();
    grp->resize(grp->x(), grp->y(), ww, hh);
  }
  if(!_enableTreeWidgetResize) grp->resizable(nullptr);
  if(node.tooltip.size()) {
    std::string help;
    for(char c : node.tooltip)
      if(c != '\r') help += c;
    grp->copy_tooltip(help.c_str());
  }
  _treeWidgets.push_back(grp);
  n->widget(grp);
  _tree->end();
}

// the row under the tree, as the description says it
void onelabGroup::_addFooter()
{
  for(Fl_Widget *w : _footer) Fl::delete_widget(w);
  _footer.clear();
  _buttons.clear();
  const Ui::Tree &said = fltkSources().tree;
  std::vector<Ui::Button> row =
    said.footer ? said.footer() : std::vector<Ui::Button>();
  int BB2 = BB / 2 + 4;
  begin();
  int at = x() + w() - WB;
  // laid from the right, the gear last
  for(std::size_t k = row.size(); k-- > 0;) {
    _buttons.push_back(row[k]);
    Ui::Button *b = &_buttons.back();
    int wide = BB2;
    if(!b->menu && b->label.size()) {
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int tw = 0, th = 0;
      fl_measure(b->label.c_str(), tw, th);
      if(tw + 2 * WB > wide) wide = tw + 2 * WB;
    }
    at -= wide;
    Fl_Widget *made;
    if(b->menu) {
      popupButtonFltk *gear =
        new popupButtonFltk(at, y() + h() - WB - BH, wide, BH);
#if defined(__APPLE__)
      gear->label("@-1gmsh_gear");
#else
      gear->image(new Fl_Bitmap(gear_bits, gear_width, gear_height));
#endif
      gear->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      gear->key = "gear";
      gear->what = b->menu;
      made = gear;
    }
    else {
      Fl_Button *but = new Fl_Button(at, y() + h() - WB - BH, wide, BH);
      but->copy_label(b->label.c_str());
      but->callback(_pressButton, b);
      made = but;
    }
    if(b->tooltip.size()) made->copy_tooltip(b->tooltip.c_str());
    _footer.push_back(made);
    at -= WB;
  }
  end();
}

void onelabGroup::rebuildFooter()
{
  if(FlGui::locked()) return;
  _addFooter();
  redraw();
}

void onelabGroup::rebuildTree(bool deleteWidgets)
{
  // rebuilding the tree does not work in a child thread (it should, as we
  // don't show/hide windows, but it crashes - at least on macOS)
  if(FlGui::locked()) return;

  FL_NORMAL_SIZE -= fltkSources().settings().deltaFontSize;

  // what was folded stays folded: a tree built again from nothing opens
  // every branch
  std::vector<std::string> wasClosed;
  for(Fl_Tree_Item *n = _tree->first(); n; n = n->next())
    if(!n->is_root() && n->has_children() && n->is_close())
      wasClosed.push_back(getPath(n));

  _tree->clear();

  if(fltkSources().settings().darkScheme) {
    _tree->openicon(&open_pixmap_dark);
    _tree->closeicon(&close_pixmap_dark);
  }
  else {
    _tree->openicon(&open_pixmap_light);
    _tree->closeicon(&close_pixmap_light);
  }
  // the description says the order; nothing here sorts
  _tree->sortorder(FL_TREE_SORT_NONE);
  _tree->selectmode(FL_TREE_SELECT_NONE);
  _computeWidths();

  // hide all the widgets we have added in the tree to make sure they don't
  // get spurious events (until they are deleted)
  for(std::size_t i = 0; i < _treeWidgets.size(); i++) _treeWidgets[i]->hide();

  // we don't delete widgets everytime the tree is rebuilt to minimize
  // potential race conditions (e.g. during heavy user interaction with
  // autoCheck, with risks to call handle() or focus() on deleted widgets)
  std::vector<Fl_Widget *> delWidgets;
  if(deleteWidgets) {
    delWidgets = _treeWidgets;
    _treeWidgets.clear();
    _pressed.clear();
  }

  // down the description; what is folded is asked of it once its children
  // are there to fold
  const Ui::Tree &said = fltkSources().tree;
  std::vector<std::string> fold;
  std::function<void(const std::string &)> walk =
    [&](const std::string &path) {
      for(const auto &child : said.children(path)) {
        Ui::Node node = said.node(child);
        bool branch = !said.children(child).empty();
        _addLine(child, node, branch);
        if(!branch) continue;
        walk(child);
        if(node.closed || (said.closed && said.closed(child)))
          fold.push_back(child);
      }
    };
  bool commands = fltkSources().settings().showModuleMenu;
  for(const auto &root : said.children("")) {
    if(root == "0Modules" && !commands) continue;
    Ui::Node node = said.node(root);
    _addLine(root, node, true);
    walk(root);
  }

  if(_firstBuild) {
    // everything below the modules folded
    _firstBuild = false;
    Fl_Tree_Item *n0 = _tree->find_item("0Modules");
    for(Fl_Tree_Item *n = n0; n; n = n->next()) {
      if(!n->is_root() && n->has_children() && n->depth() > 1) n->close();
    }
  }
  for(const auto &path : wasClosed) _tree->close(path.c_str(), 0);
  for(const auto &path : fold) _tree->close(path.c_str(), 0);

  _addFooter();

  _tree->redraw();

  FL_NORMAL_SIZE += fltkSources().settings().deltaFontSize;

  FlGui::check(true); // necessary e.g. on windows to avoid "ghosting"

  if(deleteWidgets) {
    // this needs to be performed after FlGui::check()
    for(std::size_t i = 0; i < delWidgets.size(); i++)
      Fl::delete_widget(delWidgets[i]);
  }
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

bool onelabGroup::isTreeItemOpen(const std::string &name)
{
  Fl_Tree_Item *n = _tree->find_item(name.c_str());
  return n && n->is_open();
}

std::string onelabGroup::getPath(Fl_Tree_Item *item)
{
  if(!item) return "";
  char path[1024];
  if(_tree->item_pathname(path, sizeof(path), item)) return "";
  return std::string(path);
}
