// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <FL/Fl_Box.H>
#include "GModel.h"
#include "Context.h"
#include "StringUtils.h"
#include "FlGui.h"
#include "paletteWindow.h"
#include "onelab.h"
#include "onelabGroup.h"
#include "onelabContextWindow.h"
#include "drawContext.h"

static std::string getDimName(int dim)
{
  switch(dim) {
  case 0: return "Point"; break;
  case 1: return "Curve"; break;
  case 2: return "Surface"; break;
  case 3: return "Volume"; break;
  }
  return "";
}

template <typename T>
void onelabContextWindow::_addOnelabWidget(
  T &p, const std::string &pattern,
  std::set<std::pair<std::string, Fl_Widget *>> &widgets)
{
  if(p.getName().find(pattern) == std::string::npos)
    return;
  // does the parameter exist?
  std::string in = getDimName(_dim) + " Template";
  std::string out;
  if(_choice->value() == 0)  // elementary
    out = getDimName(_dim) + " " + std::to_string(_tag);
  else // physical
    out = "Physical " + getDimName(_dim) + " " +
      std::to_string(_physicals[_choice->value() - 1].first);
  std::string name = ReplaceSubString(in, out, p.getName());
  std::vector<T> pn;
  onelab::server::instance()->get(pn, name);
  T n;
  if(pn.empty()) {
    n = p;
    n.setName(name);
    auto attr = n.getAttributes();
    for(auto &a : attr) {
      ReplaceSubStringInPlace(in, out, a.second);
    }
    n.setAttributes(attr);
    onelab::server::instance()->set(n);
  }
  else
    n = pn[0];

  if(n.getVisible()) {
    bool highlight = false;
    Fl_Color c;
    if(getParameterColor(n.getAttribute("Highlight"), c)) highlight = true;
    Fl_Widget *w =
      addParameterWidget(n, WB, 1, _width / 2, BH, 1., n.getName(), highlight,
                         c, win->color(), _toFree);
    w->copy_label(n.getShortName().c_str());
    std::string help = n.getHelp();
    if(help.empty()) help = n.getLabel();
    if(help.empty()) help = n.getShortName();
    w->copy_tooltip(help.c_str());
    widgets.insert(std::make_pair(n.getName(), w));
    _onelabWidgets.push_back(w);
  }
}

static void choice_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->onelabContext->rebuild(false);
}

class contextWindow : public paletteWindow {
public:
  contextWindow(int w, int h, bool nonModal, const char *l = 0)
    : paletteWindow(w, h, nonModal, l) { }
  virtual int handle(int event)
  {
    if(event == FL_HIDE) {
      GModel::current()->setSelection(0);
      drawContext::global()->draw();
    }
    return paletteWindow::handle(event);
  }
};

onelabContextWindow::onelabContextWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  _width = 26 * FL_NORMAL_SIZE;
  _height = 2 * WB + 1 * BH;

  win = new contextWindow(_width, _height,
                          CTX::instance()->nonModalWindows ? true : false,
                          "Parameters");
  win->box(GMSH_WINDOW_BOX);

  _choice = new Fl_Choice(WB, WB, _width - 2 * WB, BH);
  _choice->callback(choice_cb);

  win->position(CTX::instance()->ctxPosition[0],
                CTX::instance()->ctxPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void onelabContextWindow::show(int dim, int tag)
{
  FlGui::instance()->lastContextWindow = 4;

  _dim = dim;
  _tag = tag;
  _name = GModel::current()->getElementaryName(dim, tag);
  _entity = GModel::current()->getEntityByTag(dim, tag);
  _physicals.clear();
  _physicalGroupEntities.clear();
  if(_entity) {
    std::map<int, std::vector<GEntity *> > groups;
    GModel::current()->getPhysicalGroups(_dim, groups);
    for(auto &p : _entity->physicals) {
      _physicals.push_back
        (std::make_pair(p, GModel::current()->getPhysicalName(dim, p)));
      _physicalGroupEntities.push_back(groups[p]);
    }
  }

  // create menu with possible entities (elementary and all associated
  // physicals)
  std::vector<Fl_Menu_Item> menu;
  static std::vector<char *> toFree;
  for(std::size_t i = 0; i < toFree.size(); i++) free(toFree[i]);
  toFree.clear();
  {
    std::string label = getDimName(_dim) + " " +
      std::to_string(_tag);
    if(_name.size()) label += ": " + _name;
    char *str = strdup(label.c_str());
    Fl_Menu_Item item = {str, 0, 0, 0, 0};
    toFree.push_back(str);
    menu.push_back(item);
  }
  for(auto &p : _physicals) {
    std::string label = "Physical " + getDimName(_dim) + " " +
      std::to_string(p.first);
    if(p.second.size()) label += ": " + p.second;
    char *str = strdup(label.c_str());
    Fl_Menu_Item item = {str, 0, 0, 0, 0};
    toFree.push_back(str);
    menu.push_back(item);
  }
  Fl_Menu_Item item = {0};
  menu.push_back(item);
  _choice->copy(&menu[0]);

  if(menu.size() > 1)
    _choice->value(menu.size() - 2); // last physical

  rebuild(true);

  if(!win->shown()) win->show();
}

void onelabContextWindow::rebuild(bool deleteWidgets)
{
  // hide old widgets and record if one had the focus
  std::string focus;
  for(auto &w : _onelabWidgets) {
    if(w == Fl::focus()) focus = w->label();
    w->hide();
  }

  // delete widgets if requested (as this is called every time the main ONELAB
  // tree is rebuilt)
  if(deleteWidgets) {
    for(auto &w : _onelabWidgets) Fl::delete_widget(w);
    _onelabWidgets.clear();
    for(std::size_t i = 0; i < _toFree.size(); i++) free(_toFree[i]);
    _toFree.clear();
  }

  // get all ONELAB parameters
  std::vector<onelab::number> pn, fpn;
  onelab::server::instance()->get(pn);
  std::vector<onelab::string> ps, fps;
  onelab::server::instance()->get(ps);

  // for parameters with names containing "ONELAB Context/... Template/", check
  // if the corresponding parameter exists; if not, create it and add it to the
  // server; then create the widget
  std::string pat = "ONELAB Context/" + getDimName(_dim) + " Template/";
  std::set<std::pair<std::string, Fl_Widget *>> widgets;
  for(auto &p : pn) _addOnelabWidget(p, pat, widgets);
  for(auto &p : ps) _addOnelabWidget(p, pat, widgets);
  int h = _height;
  if(widgets.empty()) {
    Fl_Box *b = new Fl_Box(WB, h, _width - 2 * WB, BH, "No parameters");
    _onelabWidgets.push_back(b);
    win->add(b);
    h += BH;
  }
  else {
    for(auto &w : widgets) {
      w.second->position(WB, h);
      win->add(w.second);
      h += BH;
    }
  }
  h += WB;

  // resize the window and restore the focus
  win->resize(win->x(), win->y(), win->w(), h);
  for(auto w: _onelabWidgets) {
    if(focus == std::string(w->label())) {
      w->take_focus();
    }
  }

  // highlight selected entities
  GModel::current()->setSelection(0);
  if(_choice->value() == 0) {  // elementary
    if(_entity)
      _entity->setSelection(1);
  }
  else { // physical
    if(_choice->value() - 1 < _physicalGroupEntities.size()) {
      for(auto e : _physicalGroupEntities[_choice->value() - 1])
        e->setSelection(1);
    }
  }
  drawContext::global()->draw();

  // we should add a "Check" button if Solver.AutoCheck is not set (as in the
  // main ONELAB tree)
}
