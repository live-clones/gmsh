// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <list>
#include <map>
#include <FL/Fl.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/fl_draw.H>
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "FlGui.h"
#include "accentTabs.h"
#include "inputValue.h"
#include "optionWindow.h"
#include "hintInput.h"
#include "gamepadWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "paletteWindow.h"
#include "manipWindow.h"
#include "extraDialogs.h"
#include "drawContext.h"
#include "Options.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "OS.h"
#include "Context.h"
#include "StringUtils.h"
#include "gmshLocalNetworkClient.h"
extern StringXColor GeneralOptions_Color[];
extern StringXColor GeometryOptions_Color[];
extern StringXColor MeshOptions_Color[];
extern StringXColor ViewOptions_Color[];

double checkValue(Fl_Button *b, double value)
{ return ((b->value() != 0) == (value != 0)) ? value : b->value(); }

void optionRange(Fl_Valuator *v, const std::string &option)
{
  const OptionRange *r = GetOptionRange(option);
  if(!r) return;
  v->minimum(r->min);
  v->maximum(r->max);
  if(CTX::instance()->inputScrolling) v->step(r->step);
}

std::vector<double> choiceItems(Fl_Choice *c, const std::string &option)
{
  // (the labels kept here, for the items, which point to them)
  static std::list<std::string> labels;
  std::vector<Fl_Menu_Item> items;
  std::vector<double> values;
  for(auto &ch : GetOptionChoices(option)) {
    labels.push_back(ch.second);
    items.push_back({labels.back().c_str(), 0, nullptr, nullptr, 0});
    values.push_back(ch.first);
  }
  if(values.empty()) return values;
  items.push_back({nullptr});
  c->copy(&items[0]);
  return values;
}

// The option each widget of the window sets, by its name (see bind()): the
// category ("Geometry") and the name ("Points") of the option, what is added
// to the index of a choice to give the value of the option, or the value of
// each index (of a choice, or 0 and 1 of a check button) if they are not in
// order
struct optionBinding {
  std::string category, name;
  int offset;
  std::vector<double> values;
};

static std::map<Fl_Widget *, optionBinding> &bindings()
{
  static std::map<Fl_Widget *, optionBinding> b;
  return b;
}

// Bind a widget to the option its tooltip starts with ("Geometry.Points", or
// "Geometry.Points (Alt+p)" with the key that toggles it)
static void bind(Fl_Widget *w, const char *option, int offset = 0)
{
  if(!option) return;
  std::string s(option);
  s = s.substr(0, s.find(' '));
  std::size_t dot = s.find('.');
  if(dot == std::string::npos) return;
  bindings()[w] = {s.substr(0, dot), s.substr(dot + 1), offset};
}

// the values of the indices of a widget bound to an option (see
// optionBinding), or what is added to them
static void bindValues(Fl_Widget *w, const std::vector<double> &values)
{
  if(!bindings().count(w)) bind(w, w->tooltip());
  bindings()[w].values = values;
}

// the items of the bound choices whose options take one of a few values, and
// their values, from the table of these options (see GetOptionChoices())
static void choicesFromTable()
{
  for(auto &b : bindings()) {
    Fl_Choice *c = dynamic_cast<Fl_Choice *>(b.first);
    if(!c) continue;
    auto values = choiceItems(c, b.second.category + "." + b.second.name);
    if(!values.empty()) bindValues(c, values);
  }
}

// The views an option of the view page is set for: the view shown, then the
// views selected in the list; none if no view is shown
static std::vector<int> viewTargets()
{
  std::vector<int> nums;
  optionWindow *o = FlGui::instance()->options;
  int current = o->view.index;
  if(current < 0 || current >= (int)PView::list.size()) return nums;
  nums.push_back(current);
  for(int i = 0; i < (int)PView::list.size(); i++)
    if(i != current && o->viewList->browser->selected(i + 1)) nums.push_back(i);
  return nums;
}

// the color map of a view given to another
static void copyColorTable(int from, int to)
{
  ColorTable_Copy(&PView::list[from]->getOptions()->colorTable);
  ColorTable_Paste(&PView::list[to]->getOptions()->colorTable);
  PView::list[to]->setChanged(true);
}

// the names of the options listed by the tooltip of a menu of toggles
// ("View.DrawScalars, View.DrawVectors, View.DrawTensors"), without their
// category
static std::vector<std::string> menuOptions(Fl_Widget *menu)
{
  std::vector<std::string> names;
  for(std::string s :
      SplitString(menu->tooltip() ? menu->tooltip() : "", ',')) {
    s.erase(0, s.find_first_not_of(' '));
    names.push_back(s.substr(s.find('.') + 1));
  }
  return names;
}

// the category of the options of a menu of toggles ("View")
static std::string menuCategory(Fl_Widget *menu)
{
  std::string s = menu->tooltip() ? menu->tooltip() : "";
  return s.substr(0, s.find('.'));
}

// The menus of toggles, and the colour buttons with the option each shows
// (its function in the colour tables of DefaultOptions.h): refreshed with the
// bound widgets (see showOptions())
static std::vector<Fl_Menu_Button *> &toggleMenus()
{
  static std::vector<Fl_Menu_Button *> m;
  return m;
}

struct colorBinding {
  std::string category, name;
  unsigned int (*fct)(int, int, unsigned int);
};

static std::map<Fl_Widget *, colorBinding> &colorBindings()
{
  static std::map<Fl_Widget *, colorBinding> b;
  return b;
}

// With PostProcessing.Link, the selected views get all the options the view
// page shows of the view shown, its colors and its color map
static void linkViews(const std::vector<int> &nums)
{
  if(!opt_post_link(0, GMSH_GET, 0) || nums.size() < 2) return;
  std::vector<std::string> names;
  for(auto &b : bindings())
    if(b.second.category == "View") names.push_back(b.second.name);
  for(Fl_Menu_Button *m : toggleMenus())
    if(menuCategory(m) == "View")
      for(const std::string &n : menuOptions(m)) names.push_back(n);
  int from = nums[0];
  for(std::size_t k = 1; k < nums.size(); k++) {
    for(const std::string &n : names) {
      double v;
      std::string str;
      if(NumberOption(GMSH_GET, "View", from, n.c_str(), v, false))
        NumberOption(GMSH_SET, "View", nums[k], n.c_str(), v);
      else if(StringOption(GMSH_GET, "View", from, n.c_str(), str, false))
        StringOption(GMSH_SET, "View", nums[k], n.c_str(), str);
    }
    for(const std::string &n : GetOptionNames("View")) {
      if(n.compare(0, 6, "Color.")) continue;
      unsigned int c;
      if(ColorOption(GMSH_GET, "View", from, n.substr(6).c_str(), c, false))
        ColorOption(GMSH_SET, "View", nums[k], n.substr(6).c_str(), c);
    }
    copyColorTable(from, nums[k]);
  }
}

// The callback of a widget bound to an option: the option takes the value of
// the widget (and the widgets that show it are updated), and nothing else
// changes. An option of the views is set for the view shown and the views
// selected in the list (see viewTargets() and linkViews()). data is what
// activate() is told, if anything.
static void option_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  auto it = bindings().find(w);
  if(it != bindings().end()) {
    const optionBinding &b = it->second;
    const char *category = b.category.c_str(), *name = b.name.c_str();
    std::vector<int> nums =
      (b.category == "View") ? viewTargets() : std::vector<int>{0};
    if(nums.empty()) return;
    std::string text;
    Fl_Input *in = dynamic_cast<Fl_Input *>(w);
    Fl_Choice *c = dynamic_cast<Fl_Choice *>(w);
    if(in ||
       (c && StringOption(GMSH_GET, category, nums[0], name, text, false))) {
      // a text, or the name of the item chosen (a font)
      text = in ? in->value() : (c->text() ? c->text() : "");
      for(int n : nums)
        StringOption(GMSH_SET | (n == nums[0] ? GMSH_GUI : 0), category, n,
                     name, text);
    }
    else {
      double value = 0., current = 0.;
      NumberOption(GMSH_GET, category, nums[0], name, current);
      int i = -1;
      if(Fl_Button *button = dynamic_cast<Fl_Button *>(w)) {
        i = button->value() ? 1 : 0;
        value = checkValue(button, current);
      }
      else if(Fl_Valuator *v = dynamic_cast<Fl_Valuator *>(w))
        value = v->value();
      else if(c) {
        i = c->value();
        value = i + b.offset;
      }
      if(i >= 0 && i < (int)b.values.size()) value = b.values[i];
      for(int n : nums)
        NumberOption(GMSH_SET | (n == nums[0] ? GMSH_GUI : 0), category, n,
                     name, value);
    }
    if(b.category == "View") linkViews(nums);
  }
  o->updateActive();
  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

// the colour options of a table that get a button: a new one in the table
// needs no code here
static int colorOptions(StringXColor *table)
{
  int n = 0;
  for(int i = 0; table[i].str; i++)
    if(!(table[i].level & GMSH_DEPRECATED)) n++;
  return n;
}

Fl_Menu_Item menu_font_names[] = {
  {"Times-Roman", 0, nullptr, (void *)FL_TIMES},
  {"Times-Bold", 0, nullptr, (void *)FL_TIMES_BOLD},
  {"Times-Italic", 0, nullptr, (void *)FL_TIMES_ITALIC},
  {"Times-BoldItalic", 0, nullptr, (void *)FL_TIMES_BOLD_ITALIC},
  {"Helvetica", 0, nullptr, (void *)FL_HELVETICA},
  {"Helvetica-Bold", 0, nullptr, (void *)FL_HELVETICA_BOLD},
  {"Helvetica-Oblique", 0, nullptr, (void *)FL_HELVETICA_ITALIC},
  {"Helvetica-BoldOblique", 0, nullptr, (void *)FL_HELVETICA_BOLD_ITALIC},
  {"Courier", 0, nullptr, (void *)FL_COURIER},
  {"Courier-Bold", 0, nullptr, (void *)FL_COURIER_BOLD},
  {"Courier-Oblique", 0, nullptr, (void *)FL_COURIER_ITALIC},
  {"Courier-BoldOblique", 0, nullptr, (void *)FL_COURIER_BOLD_ITALIC},
  {"Symbol", 0, nullptr, (void *)FL_SYMBOL},
  {"Screen", 0, nullptr, (void *)FL_SCREEN},
  {nullptr}};

static void color_cb(Fl_Widget *w, void *data)
{
  unsigned int (*fct)(int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX::instance()->unpackRed(fct(0, GMSH_GET, 0));
  uchar g = CTX::instance()->unpackGreen(fct(0, GMSH_GET, 0));
  uchar b = CTX::instance()->unpackBlue(fct(0, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(0, GMSH_SET | GMSH_GUI, CTX::instance()->packColor(r, g, b, 255));
  drawContext::global()->draw();
}

// the colour of the shown view, given to the selected views as well
static void view_color_cb(Fl_Widget *w, void *data)
{
  unsigned int (*fct)(int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  std::vector<int> nums = viewTargets();
  if(nums.empty()) return;
  unsigned int color = fct(nums[0], GMSH_GET, 0);
  uchar r = CTX::instance()->unpackRed(color);
  uchar g = CTX::instance()->unpackGreen(color);
  uchar b = CTX::instance()->unpackBlue(color);
  if(!fl_color_chooser("Color Chooser", r, g, b)) return;
  color = CTX::instance()->packColor(r, g, b, 255);
  for(int i : nums)
    fct(i, GMSH_SET | (i == nums[0] ? GMSH_GUI : 0), color);
  drawContext::global()->draw();
}

void general_gmpdcf_cb(Fl_Widget *w, void *data)
{
  // built once there is a gamepad, which may be connected later
  optionWindow *o = FlGui::instance()->options;
  if(!o->gmpdoption || !o->gmpdoption->win) {
    delete o->gmpdoption;
    o->gmpdoption = new gamepadWindow;
  }
  o->gmpdoption->show();
}

void options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->win->show();
}

static void options_browser_cb(Fl_Widget *w, void *data)
{
  // the view clicked is shown; the others selected change with it
  int line = FlGui::instance()->options->viewList->browser->value();
  if(line > 0) FlGui::instance()->options->showGroup(line + 5, true, true);
}

static void options_category_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->categoryChosen(); }

static void options_section_cb(Fl_Widget *w, void *data)
{
  int i = (intptr_t)data;
  FlGui::instance()->options->toggleSection(i / 100, i % 100);
}

static void options_search_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->layout(false); }

static void options_resized_cb(void *data)
{ FlGui::instance()->options->layout(true); }

static void options_select_views_cb(Fl_Widget *w, void *data)
{ FlGui::instance()->options->selectViews((const char *)data); }

static void options_show_file_cb(Fl_Widget *w, void *data)
{
  std::string what((const char *)data);
  std::string file = CTX::instance()->homeDir;
  if(what == "session")
    file += CTX::instance()->sessionFileName;
  else
    file += CTX::instance()->optionsFileName;
  fl_message("File path: %s", file.c_str());
}

void options_restore_defaults_cb(Fl_Widget *w, void *data)
{
  if(fl_choice(
       "Do you really want to reset all options to their default values?",
       "Cancel", "Restore", nullptr)) {
    UnlinkFile(CTX::instance()->homeDir + CTX::instance()->sessionFileName);
    UnlinkFile(CTX::instance()->homeDir + CTX::instance()->optionsFileName);
    ReInitOptions(0);
    InitOptionsGUI(0);
    FlGui::instance()->rebuildTree();
    drawContext::global()->draw();
  }
}

void general_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(1);
}

void general_options_rotation_center_select_cb(Fl_Widget *w, void *data)
{
  Msg::StatusGl("Select point on geometry, mesh or post-processing view\n"
                "[Press 'q' to abort]");

  // the point clicked, from the depth of the pick: no need to pick mesh
  // elements for it, which rebuilt the arrays of the mesh twice (a freeze of
  // seconds on a large mesh) to give the barycentre of an element
  char ib = FlGui::instance()->selectEntity(ENT_ALL);
  if(ib == 'l') {
    SPoint3 pc(0., 0., 0.);
    drawContext *ctx =
      FlGui::instance()->getCurrentOpenglWindow()->getDrawContext();
    double xyz[3];
    if(FlGui::instance()->selectedVertices.size())
      pc.setPosition(FlGui::instance()->selectedVertices[0]->x(),
                     FlGui::instance()->selectedVertices[0]->y(),
                     FlGui::instance()->selectedVertices[0]->z());
    else if(ctx->pickPoint(xyz)) {
      pc.setPosition(xyz[0], xyz[1], xyz[2]);
      // on the curve or surface itself, not on the polyline or the
      // triangulation it is drawn as
      double t, uv[2] = {0., 0.};
      if(FlGui::instance()->selectedEdges.size()) {
        GPoint gp = FlGui::instance()->selectedEdges[0]->closestPoint(pc, t);
        if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
      }
      else if(FlGui::instance()->selectedFaces.size()) {
        GPoint gp = FlGui::instance()->selectedFaces[0]->closestPoint(pc, uv);
        if(gp.succeeded()) pc.setPosition(gp.x(), gp.y(), gp.z());
      }
    }
    else if(FlGui::instance()->selectedElements.size())
      pc = FlGui::instance()->selectedElements[0]->barycenter();
    else if(FlGui::instance()->selectedEdges.size())
      pc = FlGui::instance()->selectedEdges[0]->bounds().center();
    else if(FlGui::instance()->selectedFaces.size())
      pc = FlGui::instance()->selectedFaces[0]->bounds().center();
    else if(FlGui::instance()->selectedRegions.size())
      pc = FlGui::instance()->selectedRegions[0]->bounds().center();
    else if(FlGui::instance()->selectedViews.size() &&
            FlGui::instance()->selectedViews[0]->getData())
      pc = FlGui::instance()
             ->selectedViews[0]
             ->getData()
             ->getBoundingBox()
             .center();
    opt_general_rotation_center0(0, GMSH_SET | GMSH_GUI, pc.x());
    opt_general_rotation_center1(0, GMSH_SET | GMSH_GUI, pc.y());
    opt_general_rotation_center2(0, GMSH_SET | GMSH_GUI, pc.z());
    ctx->recenterForRotationCenterChange(pc);
    FlGui::instance()->manip->update();
  }
  GModel::current()->setSelection(0);
  drawContext::global()->draw();
  Msg::StatusGl("");
}

void general_options_axes_fit_cb(Fl_Widget *w, void *data)
{
  SBoundingBox3d bbox = GModel::current()->bounds(true);
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    if(PView::list[i]->getOptions()->visible &&
       !PView::list[i]->getData()->getBoundingBox().empty())
      bbox += PView::list[i]->getData()->getBoundingBox();
  }
  if(bbox.empty())
    bbox = SBoundingBox3d(CTX::instance()->min[0], CTX::instance()->min[1],
                          CTX::instance()->min[2], CTX::instance()->max[0],
                          CTX::instance()->max[1], CTX::instance()->max[2]);
  opt_general_axes_xmin(0, GMSH_SET | GMSH_GUI, bbox.min().x());
  opt_general_axes_ymin(0, GMSH_SET | GMSH_GUI, bbox.min().y());
  opt_general_axes_zmin(0, GMSH_SET | GMSH_GUI, bbox.min().z());
  opt_general_axes_xmax(0, GMSH_SET | GMSH_GUI, bbox.max().x());
  opt_general_axes_ymax(0, GMSH_SET | GMSH_GUI, bbox.max().y());
  opt_general_axes_zmax(0, GMSH_SET | GMSH_GUI, bbox.max().z());
  drawContext::global()->draw();
}

// The other way: a widget shows the value of its option, through its binding
// as option_cb() reads it (the options of the views: those of the view shown)
static void showValue(Fl_Widget *w, const optionBinding &b)
{
  int num = 0;
  if(b.category == "View") {
    num = FlGui::instance()->options->view.index;
    if(num < 0 || num >= (int)PView::list.size()) return;
  }
  const char *category = b.category.c_str(), *name = b.name.c_str();
  double v;
  std::string text;
  if(Fl_Input *in = dynamic_cast<Fl_Input *>(w)) {
    if(StringOption(GMSH_GET, category, num, name, text, false) &&
       text != in->value())
      in->value(text.c_str());
  }
  else if(NumberOption(GMSH_GET, category, num, name, v, false)) {
    if(Fl_Button *button = dynamic_cast<Fl_Button *>(w)) {
      int on = (b.values.size() == 2) ? (v == b.values[1]) : (v != 0);
      if(button->value() != on) button->value(on);
    }
    else if(Fl_Valuator *val = dynamic_cast<Fl_Valuator *>(w)) {
      if(val->value() != v) val->value(v);
    }
    else if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(w)) {
      if(c->size() < 2) return; // an empty menu
      int i = (int)v - b.offset;
      if(b.values.size()) {
        auto it = std::find(b.values.begin(), b.values.end(), v);
        if(it == b.values.end()) return; // a value the menu does not list
        i = (int)(it - b.values.begin());
      }
      // (a value past the last item shows as the last one)
      i = std::max(0, std::min(i, c->size() - 2));
      if(c->value() != i) c->value(i);
    }
  }
  else if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(w)) {
    // the name of an item (a font)
    if(StringOption(GMSH_GET, category, num, name, text, false)) {
      int i = c->find_index(text.c_str());
      if(i >= 0 && c->value() != i) c->value(i);
    }
  }
}

// the items of a menu of toggles as their options are
static void showToggles(Fl_Menu_Button *m)
{
  std::string category = menuCategory(m);
  int num = 0;
  if(category == "View") {
    num = FlGui::instance()->options->view.index;
    if(num < 0 || num >= (int)PView::list.size()) return;
  }
  std::vector<std::string> names = menuOptions(m);
  Fl_Menu_Item *items = (Fl_Menu_Item *)m->menu();
  for(std::size_t i = 0; i < names.size() && items[i].text; i++) {
    double v;
    if(!NumberOption(GMSH_GET, category.c_str(), num, names[i].c_str(), v,
                     false))
      continue;
    if(v)
      items[i].set();
    else
      items[i].clear();
  }
}

// a colour button in the colour of its option
static void showColor(Fl_Widget *w, const colorBinding &b)
{
  int num = 0;
  if(b.category == "View") {
    num = FlGui::instance()->options->view.index;
    if(num < 0 || num >= (int)PView::list.size()) return;
  }
  unsigned int col = b.fct(num, GMSH_GET, 0);
  Fl_Color c =
    fl_color_cube(CTX::instance()->unpackRed(col) * FL_NUM_RED / 256,
                  CTX::instance()->unpackGreen(col) * FL_NUM_GREEN / 256,
                  CTX::instance()->unpackBlue(col) * FL_NUM_BLUE / 256);
  if(w->color() == c) return;
  w->color(c);
  w->labelcolor(fl_contrast(FL_BLACK, c));
  w->redraw();
}

void optionWindow::showOption(const std::string &category, int num,
                              const std::string &name)
{
  if(category == "View" && num != view.index) return;
  for(auto &b : bindings())
    if(b.second.name == name && b.second.category == category)
      showValue(b.first, b.second);
  for(Fl_Menu_Button *m : toggleMenus()) {
    std::vector<std::string> names = menuOptions(m);
    if(menuCategory(m) == category &&
       std::find(names.begin(), names.end(), name) != names.end())
      showToggles(m);
  }
  for(auto &b : colorBindings())
    if(b.second.name == name && b.second.category == category)
      showColor(b.first, b.second);
  updateActive();
}

void optionWindow::showOptions(bool shownOnly)
{
  Fl_Widget *focus = Fl::focus();
  Fl_Group *shown =
    (_current >= 0 && _current < 6) ? _category[_current] : nullptr;
  for(auto &b : bindings()) {
    if(shownOnly && ((shown && !shown->contains(b.first)) ||
                     (focus && b.first->contains(focus))))
      continue;
    showValue(b.first, b.second);
  }
  for(Fl_Menu_Button *m : toggleMenus())
    if(!shownOnly || !shown || shown->contains(m)) showToggles(m);
  for(auto &b : colorBindings())
    if(!shownOnly || !shown || shown->contains(b.first))
      showColor(b.first, b.second);
  updateActive();
}

// The widgets of the General page set their options with option_cb(); these
// do more.

// the rotation center typed in: drawn while it moves
static void general_rotation_center_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  CTX::instance()->drawRotationCenter = 1;
  SPoint3 p(o->general.value[8]->value(), o->general.value[9]->value(),
            o->general.value[10]->value());
  FlGui::instance()
    ->getCurrentOpenglWindow()
    ->getDrawContext()
    ->recenterForRotationCenterChange(p);
  FlGui::instance()->manip->update();
  option_cb(w, nullptr);
  CTX::instance()->drawRotationCenter = 0;
}

void general_rotation_center_cg_cb(Fl_Widget *w, void *data)
{
  // the rotation center at the pseudo center of mass, its fields filled with
  // it
  SPoint3 p(CTX::instance()->cg[0], CTX::instance()->cg[1],
            CTX::instance()->cg[2]);
  opt_general_rotation_center0(0, GMSH_SET | GMSH_GUI, p.x());
  opt_general_rotation_center1(0, GMSH_SET | GMSH_GUI, p.y());
  opt_general_rotation_center2(0, GMSH_SET | GMSH_GUI, p.z());
  FlGui::instance()
    ->getCurrentOpenglWindow()
    ->getDrawContext()
    ->recenterForRotationCenterChange(p);
  FlGui::instance()->manip->update();
  option_cb(w, nullptr);
}

// a coordinate of the light typed in: the ball follows
static void general_light_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  option_cb(w, nullptr);
  o->general.sphere->setValue(o->general.value[2]->value(),
                              o->general.value[3]->value(),
                              o->general.value[4]->value());
}

// the light placed on the ball: its coordinates follow
static void general_light_sphere_cb(Fl_Widget *w, void *data)
{
  double x, y, z;
  FlGui::instance()->options->general.sphere->getValue(x, y, z);
  opt_general_light00(0, GMSH_SET | GMSH_GUI, x);
  opt_general_light01(0, GMSH_SET | GMSH_GUI, y);
  opt_general_light02(0, GMSH_SET | GMSH_GUI, z);
  option_cb(nullptr, nullptr);
}

// saving the session turned off: the session file saved one last time, as
// it is
static void general_session_save_cb(Fl_Widget *w, void *data)
{
  double was = opt_general_session_save(0, GMSH_GET, 0);
  option_cb(w, data);
  if(was && !opt_general_session_save(0, GMSH_GET, 0))
    PrintOptions(
      0, GMSH_SESSIONRC, 1, 1,
      (CTX::instance()->homeDir + CTX::instance()->sessionFileName).c_str());
}

// the camera or the gamepad, which moves the camera: the gamepad goes off
// with the camera, the camera on with the gamepad
static void general_camera_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  Fl_Button *camera = o->general.butt[18], *gamepad = o->general.butt[19];
  if(w == camera && !camera->value() && gamepad->value())
    opt_general_gamepad(0, GMSH_SET | GMSH_GUI, 0);
  if(w == gamepad && gamepad->value() && !camera->value())
    opt_general_camera_mode(0, GMSH_SET | GMSH_GUI, 1);
  option_cb(w, data);
}

static void general_arrow_param_cb(Fl_Widget *w, void *data)
{
  double a = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  double b = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  double c = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
  while(arrowEditor("Arrow Editor", a, b, c)) {
    opt_general_arrow_head_radius(0, GMSH_SET, a);
    opt_general_arrow_stem_length(0, GMSH_SET, b);
    opt_general_arrow_stem_radius(0, GMSH_SET, c);
    drawContext::global()->draw();
  }
}

void geometry_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(2);
}

void mesh_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(3);
}

// the element types shown, in a menu whose items are named as their options
// ("Triangles" for Mesh.Triangles)

void solver_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(4);
}

// listening to the solvers turned on: the listening client started
static void solver_listen_cb(Fl_Widget *w, void *data)
{
  int was = (int)opt_solver_listen(0, GMSH_GET, 0);
  option_cb(w, data);
#if defined(HAVE_ONELAB)
  if(!was && opt_solver_listen(0, GMSH_GET, 0)) {
    auto it = onelab::server::instance()->findClient("Listen");
    if(it == onelab::server::instance()->lastClient()) {
      onelab::localNetworkClient *c = new gmshLocalNetworkClient("Listen", "");
      c->run();
    }
    else
      (*it)->run();
  }
#endif
}

void post_options_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->options->showGroup(5);
}

void view_options_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  if(num < 0) { // automatic
    int current = FlGui::instance()->options->view.index;
    if(current >= 0 && current < (int)PView::list.size())
      num = current;
    else
      num = 0;
  }
  if(num >= 0 && num < (int)PView::list.size())
    FlGui::instance()->options->showGroup(num + 6);
}

static void view_options_timestep_cb(Fl_Widget *w, void *data)
{
  std::string str((const char *)data);
  for(int i : viewTargets()) {
    if(str == "=")
      opt_view_timestep(i, GMSH_SET, ((Fl_Value_Input *)w)->value());
    else
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) +
                          (str == "-" ? -1 : 1));
  }
  drawContext::global()->draw();
}

// The widgets of the view page set their options with option_cb(); these do
// more.

// the custom range from the smallest or the largest value of the views
// (visible, and as their tensors are drawn)
static void view_range_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  bool min = !strcmp((const char *)data, "range_min");
  double v = min ? 1e200 : -1e200;
  for(int i : viewTargets())
    v = min ? std::min(v, opt_view_min_visible(i, GMSH_GET, 0)) :
              std::max(v, opt_view_max_visible(i, GMSH_GET, 0));
  Fl_Value_Input *field = min ? o->view.value[31] : o->view.value[32];
  field->value(v);
  option_cb(field, nullptr);
}

// a map picked by its name: the map drawn again
static void view_colormap_cb(Fl_Widget *w, void *data)
{
  option_cb(w, data);
  FlGui::instance()->options->view.colorbar->redraw();
}

// the map edited (or picked) in the map widget: the chooser shows it, and the
// selected views get it
static void view_colorbar_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  std::vector<int> nums = viewTargets();
  if(nums.empty()) return;
  o->view.choice[17]->value(
    (int)opt_view_colormap_number(nums[0], GMSH_GET, 0));
  for(std::size_t k = 1; k < nums.size(); k++) copyColorTable(nums[0], nums[k]);
  option_cb(nullptr, nullptr);
}

// an item of a menu of toggles, whose tooltip lists their options in order:
// its option set (on the view page, for the view shown and the selected ones)
static void toggles_cb(Fl_Widget *w, void *data)
{
  Fl_Menu_ *m = (Fl_Menu_ *)w;
  int i = m->value();
  std::vector<std::string> names = menuOptions(w);
  if(!m->mvalue() || i < 0 || i >= (int)names.size()) return;
  double value = m->mvalue()->value() ? 1. : 0.;
  std::string category = menuCategory(w);
  std::vector<int> nums =
    (category == "View") ? viewTargets() : std::vector<int>{0};
  for(int n : nums)
    NumberOption(GMSH_SET | (n == nums[0] ? GMSH_GUI : 0), category.c_str(), n,
                 names[i].c_str(), value);
  if(category == "View") linkViews(nums);
  option_cb(nullptr, nullptr);
}

// a menu of toggles: its items set the options its tooltip lists, in order
static Fl_Menu_Button *toggleMenu(int x, int y, int w, int h, const char *label,
                                  const char *options, Fl_Menu_Item *items)
{
  Fl_Menu_Button *m = new Fl_Menu_Button(x, y, w, h, label);
  m->tooltip(options);
  m->menu(items);
  m->callback(toggles_cb);
  toggleMenus().push_back(m);
  return m;
}

// the colour buttons of a table of colour options (but the deprecated ones),
// one per row from y; cb chooses the colour
static void colorButtons(const char *category, StringXColor *table, int x,
                         int y, int w, Fl_Callback *cb,
                         std::vector<Fl_Button *> &buttons)
{
  for(int i = 0, j = 0; table[j].str; j++) {
    if(table[j].level & GMSH_DEPRECATED) continue;
    Fl_Button *b = new Fl_Button(x, y + i * BH, w, BH, table[j].str);
    b->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    b->callback(cb, (void *)table[j].function);
    colorBindings()[b] = {category, table[j].str, table[j].function};
    buttons[i++] = b;
  }
}

// one level of refinement more or less
static void view_options_max_recursion_cb(Fl_Widget *w, void *data)
{
  Fl_Value_Input *v = FlGui::instance()->options->view.value[33];
  int val = (int)v->value();
  if(!strcmp((const char *)data, "-") && val > 0)
    v->value(val - 1);
  else if(!strcmp((const char *)data, "+"))
    v->value(val + 1);
  option_cb(v, nullptr);
}

// The widgets of the window. Each one is bound to the option it sets, whose
// name is its tooltip (see bind()); cb is its callback (option_cb() sets the
// option, and only it), called with data.

// a check button
static Fl_Check_Button *checkButton(int x, int y, int w, int h,
                                    const char *label, const char *option,
                                    Fl_Callback *cb = nullptr,
                                    void *data = nullptr)
{
  Fl_Check_Button *b = new Fl_Check_Button(x, y, w, h, label);
  b->tooltip(option);
  bind(b, option);
  if(cb) b->callback(cb, data);
  return b;
}

// a value input (an Fl_Value_Input, or a class derived from it)
template <class T = Fl_Value_Input>
static T *valueInput(int x, int y, int w, int h, const char *label,
                     const char *option, Fl_Callback *cb = nullptr,
                     void *data = nullptr)
{
  T *v = new T(x, y, w, h, label);
  v->tooltip(option);
  v->align(FL_ALIGN_RIGHT);
  bind(v, option);
  if(option)
    optionRange(v, std::string(option).substr(0, std::string(option).find(' ')));
  if(cb) v->callback(cb, data);
  return v;
}

// a value input with a range of its own (one that depends on the model, say)
// and the step of its scrolling
static Fl_Value_Input *valueInput(int x, int y, int w, int h, const char *label,
                                  const char *option, double min, double max,
                                  double step, Fl_Callback *cb,
                                  void *data = nullptr)
{
  Fl_Value_Input *v = valueInput(x, y, w, h, label, option, cb, data);
  v->minimum(min);
  v->maximum(max);
  if(CTX::instance()->inputScrolling) v->step(step);
  return v;
}

// a choice from a menu, its label on the right; the value of the option is
// the index of the item plus offset
static Fl_Choice *choice(int x, int y, int w, int h, const char *label,
                         const char *option, Fl_Menu_Item *menu,
                         Fl_Callback *cb, void *data = nullptr, int offset = 0)
{
  Fl_Choice *c = new Fl_Choice(x, y, w, h, label);
  c->tooltip(option);
  bind(c, option, offset);
  c->menu(menu);
  c->align(FL_ALIGN_RIGHT);
  c->callback(cb, data);
  return c;
}

// a text input, its label on the right
static Fl_Input *input(int x, int y, int w, int h, const char *label,
                       const char *option, Fl_Callback *cb,
                       void *data = nullptr)
{
  Fl_Input *in = new Fl_Input(x, y, w, h, label);
  in->tooltip(option);
  bind(in, option);
  in->align(FL_ALIGN_RIGHT);
  in->callback(cb, data);
  return in;
}

optionWindow::optionWindow(int deltaFontSize) : gmpdoption(nullptr)
{
  // (the widgets of a window built before are gone)
  bindings().clear();
  toggleMenus().clear();
  colorBindings().clear();
  general.butt.resize(50, nullptr);
  general.push.resize(50, nullptr);
  general.value.resize(50, nullptr);
  general.color.resize(colorOptions(GeneralOptions_Color), nullptr);
  general.input.resize(50, nullptr);
  general.choice.resize(50, nullptr);
  geo.butt.resize(50, nullptr);
  geo.value.resize(50, nullptr);
  geo.color.resize(colorOptions(GeometryOptions_Color), nullptr);
  geo.choice.resize(50, nullptr);
  mesh.butt.resize(50, nullptr);
  mesh.value.resize(50, nullptr);
  mesh.color.resize(colorOptions(MeshOptions_Color), nullptr);
  mesh.choice.resize(50, nullptr);
  solver.butt.resize(50, nullptr);
  solver.value.resize(50, nullptr);
  solver.input.resize(50, nullptr);
  post.butt.resize(50, nullptr);
  post.value.resize(50, nullptr);
  post.choice.resize(50, nullptr);
  view.butt.resize(50, nullptr);
  view.value.resize(100, nullptr);
  view.input.resize(50, nullptr);
  view.push.resize(50, nullptr);
  view.choice.resize(50, nullptr);
  view.color.resize(colorOptions(ViewOptions_Color), nullptr);
  view.label.resize(50, nullptr);
  view.menu.resize(50, nullptr);

  FL_NORMAL_SIZE -= deltaFontSize;

  // the widgets of each section are built at their place in a tab of at most
  // 11 rows of this width; layout() then stacks the sections in the scroll
  // the sections lie in a scroll inside the frame of the tabs
  int L = WB + Fl::box_dx(FL_THIN_UP_BOX);
  int width = TW - 2 * L - Fl::scrollbar_size();
  int height = 12 * BH + 4 * WB;
  _rowHeight = BH;
  _buttonWidth = BB;
  _width = width;
  _current = 0;

  // the scrollbar, shown when needed, ends where the search and the category
  // bar end, so that everything is aligned on the right
  int winWidth = TW;
  int winHeight = CTX::instance()->optHeight;
  {
    int sx, sy, sw, sh;
    Fl::screen_work_area(sx, sy, sw, sh);
    winHeight = std::min(winHeight, sh - 2 * BH);
  }
  winHeight = std::max(winHeight, 12 * BH);

  win = new paletteWindow(winWidth, winHeight,
                          CTX::instance()->nonModalWindows ? true : false,
                          nullptr, CTX::instance()->optOffset);
  win->box(GMSH_WINDOW_BOX);
  // the tabs show the category, the view list the views
  win->label("Options");

  // the search goes through all the categories, hence above them
  search =
    searchBox(WB, WB, winWidth - 2 * WB, BH, "Search options",
              "Show only the options whose label, name or choices match the\n"
              "regular expression, whatever the case",
              options_search_cb);

  // the categories as tabs, empty: what they show is placed by layout()
  {
    static const char *names[6] = {"General", "Geometry", "Mesh",
                                   "Solver",  "Post-pro", "Views"};
    _tabs = new accentTabs(WB, 2 * WB + BH, winWidth - 2 * WB,
                           winHeight - 3 * WB - BH);
    for(int i = 0; i < 6; i++) {
      _categoryTab[i] = new Fl_Group(WB, 2 * WB + 2 * BH, winWidth - 2 * WB,
                                     winHeight - 3 * WB - 2 * BH, names[i]);
      _categoryTab[i]->end();
    }
    _tabs->end();
    _tabs->callback(options_category_cb);
  }

  // the views whose options change together: the one shown and the selected
  viewList =
    new targetList(L + WB, 2 * WB + 2 * BH, winWidth - 2 * L - 2 * WB, BH,
                   {"All", "Visible", "Only this"}, options_select_views_cb);
  viewList->browser->callback(options_browser_cb);
  viewList->hide();

  scroll = new Fl_Scroll(L, 3 * WB + 2 * BH, winWidth - 2 * L,
                         winHeight - 4 * WB - 2 * BH);
  scroll->type(Fl_Scroll::VERTICAL);

  int BW = width - 4 * WB;
  // the second column of a row: after the field and a label of 7 em, to the
  // right margin
  int C2 = L + 2 * WB + IW + 7 * FL_NORMAL_SIZE;
  int RW = width - 4 * WB - IW - 7 * FL_NORMAL_SIZE;

  // General options
  general.group = new Fl_Group(L, 0, width, height, "General Options");
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      general.choice[9] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Interface",
               "General.FltkColorScheme", nullptr, option_cb);

      general.choice[3] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Graphics",
               "General.ColorScheme (Alt+c)", nullptr, option_cb);

      general.butt[13] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                     "Show tooltips and hover information box",
                                     "General.Tooltips", option_cb);

      general.butt[23] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB,
                                     BH, "Highlight hovered entity",
                                     "General.MouseHoverHighlight", option_cb);

      general.butt[11] = checkButton(L + 2 * WB + BW / 2, 2 * WB + 4 * BH,
                                     BW - BW / 2, BH, "Hover mesh and views",
                                     "General.MouseHoverMeshes", option_cb);

      general.butt[6] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Show bounding boxes",
                    "General.DrawBoundingBoxes (Alt+b)", option_cb);

      general.butt[2] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                    "Draw simplified model during user interaction",
                    "General.FastRedraw (Alt+f)", option_cb);

      general.butt[3] = checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                    "Draw with the shader pipeline",
                                    "General.Shaders", option_cb);

      general.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Enable antialiasing",
                    "General.Antialiasing", option_cb);

      general.butt[5] =
        checkButton(L + 2 * WB, 2 * WB + 9 * BH, BW, BH,
                    "Use trackball rotation instead of Euler angles",
                    "General.Trackball", option_cb);

      general.butt[15] = checkButton(L + 2 * WB, 2 * WB + 10 * BH, BW, BH,
                                     "Rotate around pseudo center of mass",
                                     "General.RotationCenterGravity",
                                     general_rotation_center_cg_cb);

      general.push[0] =
        new Fl_Button(L + 2 * IW - 2 * WB, 2 * WB + 11 * BH, BB, BH, "Select");
      general.push[0]->callback(general_options_rotation_center_select_cb);

      general.value[8] =
        valueInput(L + 2 * WB, 2 * WB + 11 * BH, IW / 3, BH, nullptr,
                   "General.RotationCenterX", general_rotation_center_cb);
      general.value[9] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 11 * BH, IW / 3, BH, nullptr,
                   "General.RotationCenterY", general_rotation_center_cb);
      general.value[10] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 11 * BH, IW / 3, BH,
                   "Rotation center", "General.RotationCenterZ",
                   general_rotation_center_cb);

      general.butt[22] = checkButton(L + 2 * WB, 2 * WB + 12 * BH, BW, BH,
                                     "Invert mouse wheel zoom direction",
                                     "General.MouseInvertZoom", option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");

      general.butt[7] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                    "Print messages on terminal",
                                    "General.Terminal", option_cb);

      general.value[5] =
        valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Message verbosity",
                   "General.Verbosity", option_cb);

      general.input[1] =
        input(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Text editor command",
              "General.TextEditor", option_cb);

      general.input[0] =
        input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Default file name",
              "General.DefaultFileName", option_cb);

      general.butt[14] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Ask confirmation before overwriting files",
                    "General.ConfirmOverwrite", option_cb);

      general.butt[8] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW - BW / 3 - WB, BH,
                    "Save session information on exit", "General.SaveSession",
                    general_session_save_cb);

      Fl_Button *b0 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 6 * BH, BW / 3, BH,
                      "Show file path");
      b0->callback(options_show_file_cb, (void *)"session");

      general.butt[9] =
        checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW / 2 - WB, BH,
                    "Save options on exit", "General.SaveOptions", option_cb);

      Fl_Button *b1 =
        new Fl_Button(L + width - 2 * WB - BW / 3, 2 * WB + 7 * BH, BW / 3, BH,
                      "Show file path");
      b1->callback(options_show_file_cb, (void *)"option");

      general.butt[10] =
        checkButton(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Enable expert mode",
                    "General.ExpertMode", option_cb);

      general.value[32] = valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW, BH,
                                     "Maximum number of threads",
                                     "General.NumThreads", option_cb);
#if !defined(_OPENMP)
      general.value[32]->deactivate();
#endif

      general.butt[20] = checkButton(L + 2 * WB, 2 * WB + 10 * BH, BW, BH,
                                     "Enable heavy visualization capabilities",
                                     "General.HeavyVisualization", option_cb);

#if !defined(HAVE_VISUDEV)
      general.butt[20]->deactivate();
#endif

      Fl_Button *b2 = new Fl_Button(L + 2 * WB, 2 * WB + 11 * BH, BW, BH,
                                    "Restore all options to default settings");
      b2->callback(options_restore_defaults_cb);
      if(CTX::instance()->guiDark)
        b2->color(FL_DARK_RED);
      else
        b2->labelcolor(FL_DARK_RED);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Axes");

      general.choice[4] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode",
               "General.Axes (Alt+a)", nullptr, option_cb);

      general.butt[16] =
        checkButton(C2, 2 * WB + 1 * BH, RW, BH, "Mikado style",
                    "General.AxesMikado", option_cb);

      general.value[17] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH,
                                     nullptr, "General.AxesTicksX", option_cb);
      general.value[18] =
        valueInput(L + 2 * WB + 1 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH,
                   nullptr, "General.AxesTicksY", option_cb);
      general.value[19] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH,
                   "Axes ticks", "General.AxesTicksZ", option_cb);

      general.input[3] = input(L + 2 * WB, 2 * WB + 3 * BH, IW / 3, BH, nullptr,
                               "General.AxesFormatX", option_cb);
      general.input[4] = input(L + 2 * WB + 1 * IW / 3, 2 * WB + 3 * BH, IW / 3,
                               BH, nullptr, "General.AxesFormatY", option_cb);
      general.input[5] =
        input(L + 2 * WB + 2 * IW / 3, 2 * WB + 3 * BH, IW / 3, BH,
              "Axes format", "General.AxesFormatZ", option_cb);

      general.input[6] = input(L + 2 * WB, 2 * WB + 4 * BH, IW / 3, BH, nullptr,
                               "General.AxesLabelX", option_cb);
      general.input[7] = input(L + 2 * WB + 1 * IW / 3, 2 * WB + 4 * BH, IW / 3,
                               BH, nullptr, "General.AxesLabelY", option_cb);
      general.input[8] =
        input(L + 2 * WB + 2 * IW / 3, 2 * WB + 4 * BH, IW / 3, BH,
              "Axes labels", "General.AxesLabelZ", option_cb);

      general.butt[0] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Set position and size of axes automatically",
                    "General.AxesAutoPosition", option_cb);

      general.value[20] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH,
                                     nullptr, "General.AxesMinX", option_cb);
      general.value[21] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3, BH, nullptr,
                   "General.AxesMinY", option_cb);
      general.value[22] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH,
                   "Axes minimum", "General.AxesMinZ", option_cb);

      general.value[23] = valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH,
                                     nullptr, "General.AxesMaxX", option_cb);
      general.value[24] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3, BH, nullptr,
                   "General.AxesMaxY", option_cb);
      general.value[25] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH,
                   "Axes maximum", "General.AxesMaxZ", option_cb);

      general.push[1] =
        new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Fit to visible");
      general.push[1]->callback(general_options_axes_fit_cb);

      general.butt[1] =
        checkButton(L + 2 * WB, 2 * WB + 9 * BH, BW, BH, "Show small axes",
                    "General.SmallAxes (Alt+Shift+a)", option_cb);

      general.value[26] =
        valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH, nullptr,
                   "General.SmallAxesPositionX", option_cb);
      general.value[27] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH,
                                     IW / 2, BH, "Small axes position",
                                     "General.SmallAxesPositionY", option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();
      general.choice[2] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Projection mode",
               "General.Orthographic (Alt+o)", nullptr, option_cb);

      general.value[14] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                     "Z-clipping distance factor",
                                     "General.ClipFactor", option_cb);

      general.value[15] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH, nullptr,
                   "General.PolygonOffsetFactor", option_cb);

      general.value[16] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 3 * BH,
                                     IW / 2, BH, "Polygon offset factor/units",
                                     "General.PolygonOffsetUnits", option_cb);

      general.butt[4] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                    "Always apply polygon offset",
                                    "General.PolygonOffsetAlwaysOn", option_cb);

      general.value[11] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadric subdivisions",
                   "General.QuadricSubdivisions", option_cb);

      general.value[6] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Point size",
                   "General.PointSize", option_cb);

      general.value[7] =
        valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Line width",
                   "General.LineWidth", option_cb);
      general.choice[0] =
        choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Vector display",
               "General.VectorType", nullptr, option_cb);

      Fl_Button *b = new Fl_Button(L + 2 * IW - 2 * WB, 2 * WB + 8 * BH, BB, BH,
                                   "Edit arrow");
      b->callback(general_arrow_param_cb);

      static Fl_Menu_Item menu_font_engine[] = {
        {"Native", 0, nullptr, nullptr},
        {"StringTexture", 0, nullptr, nullptr},
        {"Embedded", 0, nullptr, nullptr},
        {nullptr}};
      general.choice[7] =
        choice(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Font rendering engine",
               "General.GraphicsFontEngine", menu_font_engine, option_cb);

      int w1 = (int)(4. * IW / 5.), w2 = IW - w1;
      general.choice[1] =
        choice(L + 2 * WB, 2 * WB + 10 * BH, w1, BH, nullptr,
               "General.GraphicsFont", menu_font_names, option_cb);
      general.value[12] =
        valueInput(L + 2 * WB + w1, 2 * WB + 10 * BH, w2, BH, "Default font",
                   "General.GraphicsFontSize", option_cb);

      general.choice[6] =
        choice(L + 2 * WB, 2 * WB + 11 * BH, w1, BH, nullptr,
               "General.GraphicsFontTitle", menu_font_names, option_cb);
      general.value[28] =
        valueInput(L + 2 * WB + w1, 2 * WB + 11 * BH, w2, BH, "Title font",
                   "General.GraphicsFontSizeTitle", option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      general.value[2] =
        valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW / 3, BH, nullptr,
                   "General.Light0X", general_light_cb);

      general.value[3] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 1 * BH, IW / 3, BH, nullptr,
                   "General.Light0Y", general_light_cb);

      general.value[4] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 1 * BH, IW / 3, BH,
                   "Light position", "General.Light0Z", general_light_cb);

      general.value[13] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 2, BH,
                                     nullptr, "General.Light0W", option_cb);
      general.value[36] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 2 * BH, IW / 2, BH,
                   "Proximity and brightness", "General.Brightness", option_cb);

      // the ball beside the two rows, after the longer of their labels
      fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
      int xs = L + 2 * WB + IW + WB +
               (int)std::max(fl_width(general.value[4]->label()),
                             fl_width(general.value[36]->label()));
      int ws = std::min(2 * BH, L + width - 2 * WB - xs);
      general.sphere =
        new spherePositionWidget(L + width - 2 * WB - ws, 2 * WB + 1 * BH, ws);
      general.sphere->callback(general_light_sphere_cb);

      general.value[1] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH,
                                    nullptr, "General.Shininess", option_cb);
      general.value[0] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 3 * BH, IW / 2, BH,
                   "Material shininess and exponent",
                   "General.ShininessExponent", option_cb);

      general.choice[8] =
        choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Shading mode",
               "General.Shading", nullptr, option_cb);

      general.value[33] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW / 3, BH, nullptr,
                   "General.StudioSamples", option_cb);

      general.value[35] =
        valueInput(L + 2 * WB + IW / 3, 2 * WB + 5 * BH, IW / 3, BH, nullptr,
                   "General.StudioLightSpread", option_cb);

      general.value[34] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 5 * BH, IW / 3, BH,
                   "Studio samples, spread, floor offset",
                   "General.StudioFloorOffset", -10, 10, 0.01, option_cb);

      general.choice[5] =
        choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Background gradient",
               "General.BackgroundGradient", nullptr, option_cb);

      colorButtons("General", GeneralOptions_Color, L + 2 * WB, 3 * WB + 7 * BH,
                   IW, color_cb, general.color);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Camera");
      o->hide();

      general.butt[18] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable camera",
                    "General.Camera", general_camera_cb);
      general.butt[18]->value(opt_general_camera_mode(0, GMSH_GET, 0));

      general.butt[17] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Enable stereo rendering", "General.Stereo", option_cb);
      general.butt[17]->value(opt_general_stereo_mode(0, GMSH_GET, 0));

      general.value[29] = valueInput(
        L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Eye separation ratio (%)",
        "General.CameraEyeSeparationRatio", option_cb);
      general.value[29]->value(CTX::instance()->eye_sep_ratio);

      general.value[30] = valueInput(
        L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Focal length ratio (%)",
        "General.CameraFocalLengthRatio", option_cb);
      general.value[30]->value(CTX::instance()->focallength_ratio);

      general.value[31] = valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                     "Camera Aperture (degrees)",
                                     "General.CameraAperture", option_cb);
      general.value[31]->value(CTX::instance()->camera_aperture);

      general.butt[19] = checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                     "Enable gamepad (experimental)",
                                     "General.Gamepad", general_camera_cb);
      general.butt[19]->value(opt_general_gamepad(0, GMSH_GET, 0));

      general.gamepadconfig =
        new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, BW, BH, "Configure Gamepad");
      general.gamepadconfig->callback(general_gmpdcf_cb);

      if(opt_general_camera_mode(0, GMSH_GET, 0) == 0) {
        general.value[30]->deactivate();
        general.value[31]->deactivate();
      }

      if(opt_general_stereo_mode(0, GMSH_GET, 0) == 0)
        general.value[29]->deactivate();

      // (the camera is on with an active gamepad: opt_general_gamepad())
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active)
        general.gamepadconfig->activate();
      else
        general.gamepadconfig->deactivate();
      o->end();
    }
  }

  general.group->end();

  // Geometry options
  geo.group = new Fl_Group(L, 0, width, height, "Geometry Options");
  geo.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      geo.value[2] =
        valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Geometry tolerance",
                   "Geometry.Tolerance", option_cb);

      geo.butt[8] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Remove duplicate entities in GEO model transforms",
                    "Geometry.AutoCoherence", option_cb);

      Fl_Box *b = new Fl_Box(L + 2 * WB, 2 * WB + 3 * BH, BW, 2);
      b->box(FL_ENGRAVED_FRAME);
      b->labeltype(FL_NO_LABEL);

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 3 * BH + 1, IW,
                              BH, "Open CASCADE model healing options:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      geo.butt[16] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                 "Remove degenerated edges and faces",
                                 "Geometry.OCCFixDegenerated", option_cb);

      geo.butt[11] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH, "Remove small edges",
                    "Geometry.OCCFixSmallEdges", option_cb);

      geo.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH, "Remove small faces",
                    "Geometry.OCCFixSmallFaces", option_cb);

      geo.butt[13] =
        checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH, "Sew faces",
                    "Geometry.OCCSewFaces", option_cb);

      geo.butt[14] = checkButton(L + 2 * WB, 2 * WB + 8 * BH, BW, BH,
                                 "Fix shells and make solids",
                                 "Geometry.OCCMakeSolids", option_cb);

      geo.value[20] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Global model scaling",
                   "Geometry.OCCScaling", option_cb);

#if !defined(HAVE_OCC)
      b2->deactivate();
      geo.butt[16]->deactivate();
      geo.butt[11]->deactivate();
      geo.butt[12]->deactivate();
      geo.butt[13]->deactivate();
      geo.butt[14]->deactivate();
      geo.value[20]->deactivate();
#endif
      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");

      geo.butt[0] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH,
                                "Points", "Geometry.Points (Alt+p)", option_cb);

      geo.butt[1] = checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH,
                                "Curves", "Geometry.Curves (Alt+l)", option_cb);

      geo.butt[2] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH, "Surfaces",
                    "Geometry.Surfaces (Alt+s)", option_cb);

      geo.butt[3] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH, "Volumes",
                    "Geometry.Volumes (Alt+v)", option_cb);

      geo.butt[4] =
        checkButton(L + width / 2, 2 * WB + 1 * BH, width - width / 2 - 2 * WB,
                    BH, "Point labels", "Geometry.PointLabels", option_cb);

      geo.butt[5] =
        checkButton(L + width / 2, 2 * WB + 2 * BH, width - width / 2 - 2 * WB,
                    BH, "Curve labels", "Geometry.CurveLabels", option_cb);

      geo.butt[6] =
        checkButton(L + width / 2, 2 * WB + 3 * BH, width - width / 2 - 2 * WB,
                    BH, "Surface labels", "Geometry.SurfaceLabels", option_cb);

      geo.butt[7] =
        checkButton(L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB,
                    BH, "Volume labels", "Geometry.VolumeLabels", option_cb);
      geo.choice[4] = choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Label type",
                             "Geometry.LabelType", nullptr, option_cb);

      geo.value[0] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 2, BH,
                                nullptr, "Geometry.Normals", option_cb);
      geo.value[0]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      geo.value[1] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 6 * BH, IW / 2, BH,
                   "Normals and tangents", "Geometry.Tangents", option_cb);
      geo.value[1]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Transfo");
      o->hide();
      geo.choice[3] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Main window transform",
               "Geometry.Transform", nullptr, option_cb);

      int ss = 2 * IW / 3 / 3 + 4;
      geo.value[7] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, ss, BH, nullptr,
                                "Geometry.TransformXX");
      geo.value[8] = valueInput(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH,
                                nullptr, "Geometry.TransformXY");
      geo.value[9] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH,
                                " X", "Geometry.TransformXZ");
      geo.value[10] = valueInput(L + 2 * WB + IW, 2 * WB + 2 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetX");

      geo.value[11] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, ss, BH, nullptr,
                                 "Geometry.TransformYX");
      geo.value[12] = valueInput(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH,
                                 nullptr, "Geometry.TransformYY");
      geo.value[13] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH, ss, BH,
                                 " Y +", "Geometry.TransformYZ");
      geo.value[14] = valueInput(L + 2 * WB + IW, 2 * WB + 3 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetY");

      geo.value[15] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, ss, BH, nullptr,
                                 "Geometry.TransformZX");
      geo.value[16] = valueInput(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH,
                                 nullptr, "Geometry.TransformZY");
      geo.value[17] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH,
                                 " Z", "Geometry.TransformZZ");
      geo.value[18] = valueInput(L + 2 * WB + IW, 2 * WB + 4 * BH, 7 * IW / 10,
                                 BH, nullptr, "Geometry.OffsetZ");

      for(int i = 7; i <= 18; i++) {
        geo.value[i]->minimum(-1.);
        geo.value[i]->maximum(1.);
        if(CTX::instance()->inputScrolling) geo.value[i]->step(0.1);
        geo.value[i]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        geo.value[i]->callback(option_cb);
      }

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      geo.choice[0] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Point display",
               "Geometry.PointType", nullptr, option_cb);

      geo.value[3] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                "Point size", "Geometry.PointSize", option_cb);

      geo.value[5] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "Selected point size",
                   "Geometry.PointSelectSize", option_cb);

      geo.choice[1] =
        choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Curve display",
               "Geometry.CurveType", nullptr, option_cb);

      geo.value[4] =
        valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Curve width",
                   "Geometry.CurveWidth", option_cb);

      geo.value[6] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Selected curve width",
                   "Geometry.CurveSelectWidth", option_cb);

      geo.value[19] =
        valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Curve subdivisions",
                   "Geometry.NumSubEdges", option_cb);

      geo.choice[2] =
        choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Surface display",
               "Geometry.SurfaceType (Alt+d)", nullptr, option_cb);

      geo.choice[5] =
        choice(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Volume display",
               "Geometry.VolumeType", nullptr, option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      geo.butt[9] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting",
                    "Geometry.Light (Alt+w)", option_cb);

      geo.butt[15] = checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                                 "Use two-side lighting",
                                 "Geometry.LightTwoSide", option_cb);

      geo.butt[10] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                                 "Highlight orphan and boundary entities",
                                 "Geometry.HighlightOrphans", option_cb);

      int w1 = (int)(3. * IW / 4.), w2 = IW - w1;
      geo.value[21] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, w2, BH, nullptr,
                                 "Geometry.Opacity", option_cb);
      geo.value[21]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      geo.choice[6] =
        choice(L + 2 * WB + w2, 2 * WB + 4 * BH, w1, BH, "Opacity",
               "Geometry.OpacityMode", nullptr, option_cb);

      colorButtons("Geometry", GeometryOptions_Color, L + 2 * WB,
                   3 * WB + 5 * BH, IW, color_cb, geo.color);

      o->end();
    }
  }
  geo.group->end();

  // Mesh options
  mesh.group = new Fl_Group(L, 0, width, height, "Mesh Options");
  mesh.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      o->hide();

      mesh.choice[2] =
        choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "2D algorithm",
               "Mesh.Algorithm", nullptr, option_cb);

      mesh.choice[3] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "3D algorithm",
               "Mesh.Algorithm3D", nullptr, option_cb);

      mesh.choice[1] = choice(
        L + 2 * WB, 2 * WB + 3 * BH, IW, BH, "2D recombination algorithm",
        "Mesh.RecombinationAlgorithm", nullptr, option_cb);

      mesh.butt[21] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                  "Recombine all triangular meshes",
                                  "Mesh.RecombineAll", option_cb);

      mesh.choice[5] =
        choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Subdivision algorithm",
               "Mesh.SubdivisionAlgorithm", nullptr, option_cb);

      mesh.value[0] =
        valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Smoothing steps",
                   "Mesh.Smoothing", option_cb);

      mesh.value[2] = valueInput<inputValueFloat>(L + 2 * WB, 2 * WB + 7 * BH,
                                                  IW, BH, "Element size factor",
                                                  "Mesh.MeshSizeFactor");
      mesh.value[2]->minimum(0.001);
      mesh.value[2]->maximum(1000);
      if(CTX::instance()->inputScrolling) mesh.value[2]->step(0.01);
      mesh.value[2]->align(FL_ALIGN_RIGHT);
      mesh.value[2]->callback(option_cb);

      mesh.value[25] = valueInput(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH,
                                  nullptr, "Mesh.MeshSizeMin", option_cb);

      mesh.value[26] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 8 * BH, IW / 2, BH,
                   "Min/Max element size", "Mesh.MeshSizeMax", option_cb);

      mesh.value[3] =
        valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 3, BH, "Element order",
                   "Mesh.ElementOrder", option_cb);

      mesh.butt[4] = checkButton(
        L + width / 2, 2 * WB + 9 * BH, width - width / 2 - 2 * WB, BH,
        "Incomplete elements", "Mesh.SecondOrderIncomplete", option_cb);

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Advanced");
      o->hide();

      mesh.butt[5] = checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH,
                                 "Compute element sizes using point values",
                                 "Mesh.MeshSizeFromPoints", option_cb);

      mesh.butt[26] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Compute element sizes using parametric point values",
                    "Mesh.MeshSizeFromParametricPoints", option_cb);

      mesh.value[1] =
        valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW / 2, BH,
                   "Compute element sizes from curvature",
                   "Mesh.MeshSizeFromCurvature (number of elements "
                   "per 2 * Pi radians)",
                   option_cb);

      mesh.butt[16] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                  "Extend element sizes from boundary",
                                  "Mesh.MeshSizeExtendFromBoundary", option_cb);

      mesh.butt[2] = checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                 "Optimize quality of tetrahedra",
                                 "Mesh.Optimize", option_cb);

      mesh.butt[24] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                  "Optimize quality of tetrahedra with Netgen",
                                  "Mesh.OptimizeNetgen");
#if !defined(HAVE_NETGEN)
      mesh.butt[24]->deactivate();
#endif
      mesh.butt[24]->callback(option_cb);

      mesh.butt[3] = checkButton(L + 2 * WB, 2 * WB + 7 * BH, BW, BH,
                                 "Optimize high-order meshes",
                                 "Mesh.HighOrderOptimize", option_cb);
      // (a check box for one of its values)
      bindValues(mesh.butt[3], {0, 2});

      o->end();
    }

    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");

      mesh.butt[6] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW / 2 - WB, BH, "Nodes",
                    "Mesh.Nodes (Alt+Shift+p)", option_cb);

      mesh.butt[7] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW / 2 - WB, BH, "1D elements",
                    "Mesh.Lines (Alt+Shift+l)", option_cb);

      mesh.butt[8] = checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW / 2 - WB, BH,
                                 "2D element edges",
                                 "Mesh.SurfaceEdges (Alt+Shift+s)", option_cb);

      mesh.butt[9] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH,
                                 "2D element faces",
                                 "Mesh.SurfaceFaces (Alt+Shift+d)", option_cb);

      mesh.butt[10] = checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW / 2 - WB, BH,
                                  "3D element edges",
                                  "Mesh.VolumeEdges (Alt+Shift+v)", option_cb);

      mesh.butt[11] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW / 2 - WB, BH,
                                  "3D element faces",
                                  "Mesh.VolumeFaces (Alt+Shift+b)", option_cb);

      mesh.butt[1] = checkButton(
        L + width / 2, 2 * WB + 5 * BH, width - width / 2 - 2 * WB, BH,
        "Hide interior edges", "Mesh.DrawSkinEdgesOnly", option_cb);
      mesh.choice[12] =
        choice(L + width / 2, 2 * WB + 6 * BH, width - width / 2 - 2 * WB, BH,
               nullptr, "Mesh.DrawSkinOnly", nullptr, option_cb);

      mesh.butt[12] =
        checkButton(L + width / 2, 2 * WB + 1 * BH, width - width / 2 - 2 * WB,
                    BH, "Node labels", "Mesh.NodeLabels", option_cb);

      mesh.butt[13] =
        checkButton(L + width / 2, 2 * WB + 2 * BH, width - width / 2 - 2 * WB,
                    BH, "1D element labels", "Mesh.LineLabels", option_cb);

      mesh.butt[14] =
        checkButton(L + width / 2, 2 * WB + 3 * BH, width - width / 2 - 2 * WB,
                    BH, "2D element labels", "Mesh.SurfaceLabels", option_cb);

      mesh.butt[15] =
        checkButton(L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB,
                    BH, "3D element labels", "Mesh.VolumeLabels", option_cb);
      mesh.choice[7] = choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Label",
                              "Mesh.LabelType", nullptr, option_cb);

      mesh.value[12] = valueInput(L + width / 2, 2 * WB + 7 * BH, IW / 2, BH,
                                  "Sampling", "Mesh.LabelSampling", option_cb);
      mesh.value[12]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      static Fl_Menu_Item menu_mesh_element_types[] = {
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Trihedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polygons", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polyhedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      mesh.menu =
        toggleMenu(L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Elements",
                   "Mesh.Triangles, Mesh.Quadrangles, Mesh.Tetrahedra, "
                   "Mesh.Hexahedra, Mesh.Prisms, Mesh.Pyramids, Mesh.Trihedra, "
                   "Mesh.Polygons, Mesh.Polyhedra",
                   menu_mesh_element_types);

      mesh.value[4] = valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 4, BH,
                                 nullptr, "Mesh.QualityInf", option_cb);
      mesh.value[4]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      mesh.value[5] =
        valueInput(L + 2 * WB + IW / 4, 2 * WB + 9 * BH, IW / 2 - IW / 4, BH,
                   nullptr, "Mesh.QualitySup", option_cb);
      mesh.value[5]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      mesh.choice[6] =
        choice(L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH,
               "Quality range", "Mesh.QualityType", nullptr, option_cb);

      mesh.value[6] = valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH,
                                 nullptr, "Mesh.RadiusInf", option_cb);
      mesh.value[6]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      mesh.value[7] = valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2,
                                 BH, "Size range", "Mesh.RadiusSup", option_cb);
      mesh.value[7]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      mesh.value[8] = valueInput(L + 2 * WB, 2 * WB + 11 * BH, IW / 2, BH,
                                 nullptr, "Mesh.Normals", option_cb);
      mesh.value[8]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      mesh.value[13] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 11 * BH, IW / 2, BH,
                   "Normals and tangents", "Mesh.Tangents", option_cb);
      mesh.value[13]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      mesh.value[9] =
        valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                   "Element shrinking factor", "Mesh.Explode", option_cb);
      mesh.value[9]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      mesh.choice[0] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display",
               "Mesh.NodeType", nullptr, option_cb);

      mesh.value[10] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                  "Point size", "Mesh.PointSize", option_cb);

      mesh.value[11] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, IW, BH,
                                  "Line width", "Mesh.LineWidth", option_cb);

      mesh.value[14] = valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                  "High-order element subdivisions",
                                  "Mesh.NumSubEdges", option_cb);
      mesh.value[14]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      mesh.butt[17] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting",
                    "Mesh.Light (Alt+w)", option_cb);
      mesh.choice[10] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Edge lighting",
               "Mesh.LightLines", nullptr, option_cb);

      mesh.butt[18] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                    "Use two-side lighting", "Mesh.LightTwoSide", option_cb);

      mesh.butt[19] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Smooth normals",
                    "Mesh.SmoothNormals", option_cb);

      mesh.value[18] = valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                  "Smoothing threshold angle",
                                  "Mesh.AngleSmoothNormals", option_cb);
      mesh.value[18]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      int w1 = (int)(3. * IW / 4.), w2 = IW - w1;
      mesh.value[27] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, w2, BH, nullptr,
                                  "Mesh.Opacity", option_cb);
      mesh.value[27]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      mesh.choice[11] =
        choice(L + 2 * WB + w2, 2 * WB + 6 * BH, w1, BH, "Opacity",
               "Mesh.OpacityMode", nullptr, option_cb);
      mesh.choice[4] =
        choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Coloring mode",
               "Mesh.ColorCarousel", nullptr, option_cb);

      colorButtons("Mesh", MeshOptions_Color, L + 2 * WB, 3 * WB + 8 * BH, IW,
                   color_cb, mesh.color);

      o->end();
    }
  }
  mesh.group->end();

  // Solver options
  solver.group = new Fl_Group(L, 0, width, height, "Solver Options");
  solver.group->hide();
  {
    {
      {
        Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                   height - 2 * WB - BH, "General");

        solver.input[0] =
          input(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Base socket name",
                "Solver.SocketName", option_cb);

        solver.value[0] =
          valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                     "Timeout (in seconds)", "Solver.Timeout", option_cb);

        solver.butt[0] =
          checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                      "Always listen to incoming connection requests",
                      "Solver.AlwaysListen", solver_listen_cb);

        solver.input[1] =
          input(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Python interpreter",
                "Solver.PythonInterpreter", option_cb);

        solver.input[2] =
          input(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Octave interpreter",
                "Solver.OctaveInterpreter", option_cb);

        o->end();
      }
    }
  }
  solver.group->end();

  // Post-processing options
  post.group = new Fl_Group(L, 0, width, height, "Post-processing Options");
  post.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");

      post.choice[0] = choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "View links",
                              "PostProcessing.Link", nullptr, option_cb);

      post.value[0] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW, BH,
                                 "Frame duration (in seconds)",
                                 "PostProcessing.AnimationDelay", option_cb);

      post.value[1] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                 "Animation increment step",
                                 "PostProcessing.AnimationStep", option_cb);

      post.butt[0] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH,
                                 "Cycle through views instead of steps",
                                 "PostProcessing.AnimationCycle", option_cb);

      post.butt[1] =
        checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                    "Remove original views after combination",
                    "PostProcessing.CombineRemoveOriginal", option_cb);

      post.butt[2] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                 "Draw value scales horizontally",
                                 "PostProcessing.HorizontalScales", option_cb);

      o->end();
    }
  }
  post.group->end();

  // View options
  view.index = -1;
  view.group = new Fl_Group(L, 0, width, height, "View Options");
  view.group->hide();
  {
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "General");
      view.choice[13] = choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Plot type",
                               "View.Type", nullptr, option_cb);

      view.input[0] = input(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "View name",
                            "View.Name", option_cb);

      int sw = (int)(1.5 * FL_NORMAL_SIZE);
      view.push[3] = new Fl_Button(L + 2 * WB, 2 * WB + 3 * BH, sw, BH, "-");
      view.push[3]->callback(view_options_timestep_cb, (void *)"-");
      view.push[4] =
        new Fl_Button(L + 2 * WB + IW - sw, 2 * WB + 3 * BH, sw, BH, "+");
      view.push[4]->callback(view_options_timestep_cb, (void *)"+");
      view.value[50] = valueInput(L + 2 * WB + sw, 2 * WB + 3 * BH, IW - 2 * sw,
                                  BH, nullptr, "View.TimeStep", 0, 0, 1,
                                  view_options_timestep_cb, (void *)"=");
      view.label[0] =
        new Fl_Box(L + 2 * WB + IW, 2 * WB + 3 * BH, width / 2, BH, "Step");
      view.label[0]->box(FL_NO_BOX);
      view.label[0]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      view.range =
        new Fl_Group(L + 2 * WB, 2 * WB + 4 * BH, width - 4 * WB, 8 * BH);

      view.value[30] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, IW, BH,
                                  "Intervals", "View.NbIso", option_cb);
      view.value[30]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.input[1] = input(C2, 2 * WB + 4 * BH, RW / 2, BH, "Format",
                            "View.NumberFormat", option_cb);
      view.choice[0] =
        choice(L + 2 * WB, 2 * WB + 5 * BH, IW, BH, "Intervals type",
               "View.IntervalsType (Alt+t)", nullptr, option_cb);
      view.choice[1] = choice(C2, 2 * WB + 5 * BH, RW, BH, nullptr,
                              "View.ScaleType", nullptr, option_cb);
      view.choice[7] = choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Range mode",
                              "View.RangeType (Alt+r)", nullptr, option_cb);

      view.butt[38] = checkButton(C2, 2 * WB + 6 * BH, RW, BH, "Saturate",
                                  "View.SaturateValues", option_cb);

      int sw2 = (int)(2.5 * FL_NORMAL_SIZE);
      view.push[1] = new Fl_Button(L + 2 * WB, 2 * WB + 7 * BH, sw2, BH, "Min");
      view.push[1]->callback(view_range_cb, (void *)"range_min");
      view.value[31] =
        valueInput(L + 2 * WB + sw2, 2 * WB + 7 * BH, IW - sw2, BH,
                   "Custom min", "View.CustomMin", option_cb);
      view.value[31]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.value[35] = valueInput(C2, 2 * WB + 7 * BH, RW / 2, BH, "Threshold",
                                  "View.ScaleThreshold", option_cb);
      view.value[35]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.push[2] = new Fl_Button(L + 2 * WB, 2 * WB + 8 * BH, sw2, BH, "Max");
      view.push[2]->callback(view_range_cb, (void *)"range_max");
      view.value[32] =
        valueInput(L + 2 * WB + sw2, 2 * WB + 8 * BH, IW - sw2, BH,
                   "Custom max", "View.CustomMax", option_cb);
      view.value[32]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.butt[0] = checkButton(L + 2 * WB, 2 * WB + 9 * BH, C2 - L - 3 * WB,
                                 BH, "Adapt visualization grid",
                                 "View.AdaptVisualizationGrid", option_cb);
      view.choice[18] = choice(C2, 2 * WB + 9 * BH, RW, BH, nullptr,
                               "View.AdaptSkinOnly", nullptr, option_cb);

      view.push[5] = new Fl_Button(L + 2 * WB, 2 * WB + 10 * BH, sw, BH, "-");
      view.push[5]->callback(view_options_max_recursion_cb, (void *)"-");
      view.push[6] =
        new Fl_Button(L + 2 * WB + IW - sw, 2 * WB + 10 * BH, sw, BH, "+");
      view.push[6]->callback(view_options_max_recursion_cb, (void *)"+");
      view.value[33] =
        valueInput(L + 2 * WB + sw, 2 * WB + 10 * BH, IW - 2 * sw, BH, nullptr,
                   "View.MaxRecursionLevel", option_cb);
      view.value[33]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      view.label[1] = new Fl_Box(L + 2 * WB + IW, 2 * WB + 10 * BH, width / 2,
                                 BH, "Maximum recursion level");
      view.label[1]->box(FL_NO_BOX);
      view.label[1]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);

      // (shown as it is set, e.g. 1e-6, whatever the step of the scrolling)
      view.value[34] = valueInput<inputValueFloat>(
        L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Target visualization error",
        "View.TargetError");
      view.value[34]->align(FL_ALIGN_RIGHT);
      // (a fraction of the range of the view; negative: refine everything)
      view.value[34]->minimum(-1.e-4);
      view.value[34]->maximum(1e-1);
      if(CTX::instance()->inputScrolling) view.value[34]->step(1.e-4);
      view.value[34]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      view.value[34]->callback(option_cb);

      view.range->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Axes");
      o->hide();

      view.choice[8] = choice(L + 2 * WB, 2 * WB + 1 * BH, IW, BH, "Axes mode",
                              "View.Axes (Alt+a)", nullptr, option_cb);

      view.butt[3] = checkButton(C2, 2 * WB + 1 * BH, RW, BH, "Mikado style",
                                 "View.AxesMikado", option_cb);

      view.value[3] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, IW / 3, BH,
                                 nullptr, "View.AxesTicksX", option_cb);
      view.value[4] =
        valueInput(L + 2 * WB + 1 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH,
                   nullptr, "View.AxesTicksY", option_cb);
      view.value[5] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 2 * BH, IW / 3, BH,
                   "Axes ticks", "View.AxesTicksZ", option_cb);

      view.input[7] = input(L + 2 * WB, 2 * WB + 3 * BH, IW / 3, BH, nullptr,
                            "View.AxesFormatX", option_cb);
      view.input[8] = input(L + 2 * WB + 1 * IW / 3, 2 * WB + 3 * BH, IW / 3,
                            BH, nullptr, "View.AxesFormatY", option_cb);
      view.input[9] = input(L + 2 * WB + 2 * IW / 3, 2 * WB + 3 * BH, IW / 3,
                            BH, "Axes format", "View.AxesFormatZ", option_cb);

      view.input[10] = input(L + 2 * WB, 2 * WB + 4 * BH, IW / 3, BH, nullptr,
                             "View.AxesLabelX", option_cb);
      view.input[11] = input(L + 2 * WB + 1 * IW / 3, 2 * WB + 4 * BH, IW / 3,
                             BH, nullptr, "View.AxesLabelY", option_cb);
      view.input[12] = input(L + 2 * WB + 2 * IW / 3, 2 * WB + 4 * BH, IW / 3,
                             BH, "Axes labels", "View.AxesLabelZ", option_cb);

      view.butt[25] = checkButton(L + 2 * WB, 2 * WB + 5 * BH, BW, BH,
                                  "Position 3D axes automatically",
                                  "View.AxesAutoPosition", option_cb);

      view.value[13] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW / 3, BH,
                                  nullptr, "View.AxesMinX", option_cb);
      view.value[14] = valueInput(L + 2 * WB + IW / 3, 2 * WB + 6 * BH, IW / 3,
                                  BH, nullptr, "View.AxesMinY", option_cb);
      view.value[15] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 6 * BH, IW / 3, BH,
                   "3D axes minimum", "View.AxesMinZ", option_cb);

      view.value[16] = valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 3, BH,
                                  nullptr, "View.AxesMaxX", option_cb);
      view.value[17] = valueInput(L + 2 * WB + IW / 3, 2 * WB + 7 * BH, IW / 3,
                                  BH, nullptr, "View.AxesMaxY", option_cb);
      view.value[18] =
        valueInput(L + 2 * WB + 2 * IW / 3, 2 * WB + 7 * BH, IW / 3, BH,
                   "3D axes maximum", "View.AxesMaxZ", option_cb);

      view.choice[16] = choice(L + 2 * WB, 2 * WB + 8 * BH, IW, BH,
                               "2D axes/value scale position",
                               "View.AutoPosition", nullptr, option_cb);

      view.value[20] = valueInput(L + 2 * WB, 2 * WB + 9 * BH, IW / 2, BH,
                                  nullptr, "View.PositionX", option_cb);
      view.value[21] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 9 * BH, IW / 2, BH,
                   "2D axes/value scale position", "View.PositionY", option_cb);

      view.value[22] = valueInput(L + 2 * WB, 2 * WB + 10 * BH, IW / 2, BH,
                                  nullptr, "View.Width", option_cb);
      view.value[23] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 10 * BH, IW / 2, BH,
                   "2D axes/value scale size", "View.Height", option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Visibility");
      o->hide();

      view.butt[4] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Show value scale",
                    "View.ShowScale (Alt+i)", option_cb);
      view.choice[12] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Time display",
               "View.ShowTime", nullptr, option_cb);

      view.butt[5] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Show annotations",
                    "View.DrawStrings (Alt+n)", option_cb);

      view.butt[10] = checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW / 2 - WB, BH,
                                  "Draw element outlines",
                                  "View.ShowElement (Alt+e)", option_cb);

      view.butt[1] = checkButton(
        L + width / 2, 2 * WB + 4 * BH, width - width / 2 - 2 * WB, BH,
        "Hide interior edges", "View.DrawSkinEdgesOnly", option_cb);

      view.butt[2] =
        checkButton(L + width / 2, 2 * WB + 5 * BH, width - width / 2 - 2 * WB,
                    BH, "Hide interior faces", "View.DrawSkinOnly", option_cb);

      static Fl_Menu_Item menu_view_element_types[] = {
        {"Points", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Lines", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Triangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Quadrangles", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tetrahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Hexahedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Prisms", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Pyramids", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Trihedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polygons", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Polyhedra", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};

      view.menu[1] = toggleMenu(
        L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Elements",
        "View.DrawPoints, View.DrawLines, View.DrawTriangles, "
        "View.DrawQuadrangles, View.DrawTetrahedra, View.DrawHexahedra, "
        "View.DrawPrisms, View.DrawPyramids, View.DrawTrihedra, "
        "View.DrawPolygons, View.DrawPolyhedra",
        menu_view_element_types);

      view.value[6] = valueInput(L + 3 * WB + IW, 2 * WB + 6 * BH, IW / 3, BH,
                                 "Sampling", "View.Sampling", option_cb);
      view.value[6]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      view.choice[9] =
        choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Element boundary mode",
               "View.Boundary", nullptr, option_cb);

      view.value[0] = valueInput(L + 2 * WB, 2 * WB + 8 * BH, IW / 2, BH,
                                 nullptr, "View.Normals", option_cb);
      view.value[0]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.value[1] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 8 * BH, IW / 2, BH,
                   "Normals and tangents", "View.Tangents", option_cb);
      view.value[1]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      static Fl_Menu_Item menu_view_field_types[] = {
        {"Scalar", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Vector", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {"Tensor", 0, nullptr, nullptr, FL_MENU_TOGGLE},
        {nullptr}};
      view.menu[0] =
        toggleMenu(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Fields",
                   "View.DrawScalars, View.DrawVectors, View.DrawTensors",
                   menu_view_field_types);
      view.choice[14] = choice(L + 2 * WB, 2 * WB + 10 * BH, IW, BH, nullptr,
                               "View.ForceNumComponents", nullptr, option_cb);

      // the 9 fields of the map widen together
      int W = width - 5 * WB - IW;
      static const char *maps[9] = {
        "View.ComponentMap0", "View.ComponentMap1", "View.ComponentMap2",
        "View.ComponentMap3", "View.ComponentMap4", "View.ComponentMap5",
        "View.ComponentMap6", "View.ComponentMap7", "View.ComponentMap8"};
      Fl_Group *row = new Fl_Group(L + 3 * WB + IW, 2 * WB + 10 * BH, W, BH);
      for(int i = 0; i < 9; i++) {
        int w = W / 9;
        view.value[70 + i] = valueInput(
          L + 3 * WB + IW + i * w, 2 * WB + 10 * BH, (i < 8) ? w : W - 8 * w,
          BH, nullptr, maps[i], -1, 9, 1, option_cb);
      }
      row->end();

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Transfo");
      o->hide();

      // the matrix, the offsets and the raise move together, as one table
      Fl_Group *table = new Fl_Group(L + 2 * WB, 2 * WB + 1 * BH,
                                     2 * IW - 3 * WB + 7 * IW / 10, 4 * BH);
      Fl_Box *b = new Fl_Box(FL_NO_BOX, L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                             "Coordinate transformation:");
      b->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      int ss = 2 * IW / 3 / 3 + 4;
      view.value[51] = valueInput(L + 2 * WB, 2 * WB + 2 * BH, ss, BH, nullptr,
                                  "View.TransformXX");
      view.value[52] = valueInput(L + 2 * WB + ss, 2 * WB + 2 * BH, ss, BH,
                                  nullptr, "View.TransformXY");
      view.value[53] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 2 * BH, ss, BH,
                                  " X", "View.TransformXZ");
      view.value[40] =
        valueInput<inputValueFloat>(L + 2 * WB + IW, 2 * WB + 2 * BH,
                                    7 * IW / 10, BH, nullptr, "View.OffsetX");

      view.value[54] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, ss, BH, nullptr,
                                  "View.TransformYX");
      view.value[55] = valueInput(L + 2 * WB + ss, 2 * WB + 3 * BH, ss, BH,
                                  nullptr, "View.TransformYY");
      view.value[56] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 3 * BH, ss, BH,
                                  " Y +", "View.TransformYZ");
      view.value[41] =
        valueInput<inputValueFloat>(L + 2 * WB + IW, 2 * WB + 3 * BH,
                                    7 * IW / 10, BH, nullptr, "View.OffsetY");

      view.value[57] = valueInput(L + 2 * WB, 2 * WB + 4 * BH, ss, BH, nullptr,
                                  "View.TransformZX");
      view.value[58] = valueInput(L + 2 * WB + ss, 2 * WB + 4 * BH, ss, BH,
                                  nullptr, "View.TransformZY");
      view.value[59] = valueInput(L + 2 * WB + 2 * ss, 2 * WB + 4 * BH, ss, BH,
                                  " Z", "View.TransformZZ");
      view.value[42] =
        valueInput<inputValueFloat>(L + 2 * WB + IW, 2 * WB + 4 * BH,
                                    7 * IW / 10, BH, nullptr, "View.OffsetZ");

      Fl_Box *b2 = new Fl_Box(FL_NO_BOX, L + 2 * WB + 2 * IW - 3 * WB,
                              2 * WB + 1 * BH, 7 * IW / 10, BH, "Raise:");
      b2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

      view.value[43] = valueInput<inputValueFloat>(L + 2 * WB + 2 * IW - 3 * WB,
                                                   2 * WB + 2 * BH, 7 * IW / 10,
                                                   BH, nullptr, "View.RaiseX");
      view.value[44] = valueInput<inputValueFloat>(L + 2 * WB + 2 * IW - 3 * WB,
                                                   2 * WB + 3 * BH, 7 * IW / 10,
                                                   BH, nullptr, "View.RaiseY");
      view.value[45] = valueInput<inputValueFloat>(L + 2 * WB + 2 * IW - 3 * WB,
                                                   2 * WB + 4 * BH, 7 * IW / 10,
                                                   BH, nullptr, "View.RaiseZ");
      table->end();
      view.value[46] =
        valueInput<inputValueFloat>(L + 2 * WB, 2 * WB + 5 * BH, 3 * ss, BH,
                                    "Normal raise", "View.NormalRaise");

      for(int i = 40; i <= 46; i++) {
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        view.value[i]->callback(option_cb);
      }
      for(int i = 51; i <= 59; i++) {
        view.value[i]->minimum(-1.);
        view.value[i]->maximum(1.);
        if(CTX::instance()->inputScrolling) view.value[i]->step(0.1);
        view.value[i]->align(FL_ALIGN_RIGHT);
        view.value[i]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        view.value[i]->callback(option_cb);
      }

      view.butt[6] = checkButton(L + 2 * WB, 2 * WB + 6 * BH, BW, BH,
                                 "Use general transformation expressions",
                                 "View.UseGeneralizedRaise", option_cb);

      view.choice[11] =
        choice(L + 2 * WB, 2 * WB + 7 * BH, IW, BH, "Data source",
               "View.GeneralizedRaiseView", nullptr, option_cb, nullptr, -1);
      view.choice[11]->add("Self");

      view.value[2] =
        valueInput<inputValueFloat>(L + 2 * WB, 2 * WB + 8 * BH, IW, BH,
                                    "Factor", "View.GeneralizedRaiseFactor");
      view.value[2]->align(FL_ALIGN_RIGHT);
      view.value[2]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
      view.value[2]->callback(option_cb);

      view.input[4] = input(L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "X expression",
                            "View.GeneralizedRaiseX", option_cb);

      view.input[5] =
        input(L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Y expression",
              "View.GeneralizedRaiseY", option_cb);

      view.input[6] =
        input(L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Z expression",
              "View.GeneralizedRaiseZ", option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Aspect");
      o->hide();

      view.value[12] =
        valueInput(L + 2 * WB, 2 * WB + 1 * BH, IW, BH,
                   "Element shrinking factor", "View.Explode", option_cb);
      view.value[12]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.choice[5] =
        choice(L + 2 * WB, 2 * WB + 2 * BH, IW, BH, "Point display",
               "View.PointType", nullptr, option_cb);

      view.value[61] = valueInput(L + 2 * WB, 2 * WB + 3 * BH, IW, BH,
                                  "Point size", "View.PointSize", option_cb);

      view.choice[6] =
        choice(L + 2 * WB, 2 * WB + 4 * BH, IW, BH, "Line display",
               "View.LineType", nullptr, option_cb);

      view.butt[26] = checkButton(C2, 2 * WB + 4 * BH, RW, BH, "Stipple",
                                  "View.Stipple", option_cb);

      view.value[62] = valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW / 2, BH,
                                  nullptr, "View.LineWidth", option_cb);
      view.value[80] =
        valueInput(L + 2 * WB + IW / 2, 2 * WB + 5 * BH, IW - IW / 2, BH,
                   "Line / outline width", "View.OutlineWidth", option_cb);

      {
        view.choice[2] =
          choice(L + 2 * WB, 2 * WB + 6 * BH, IW, BH, "Vector display",
                 "View.VectorType", nullptr, option_cb);

        view.value[64] = valueInput(L + 2 * WB, 2 * WB + 7 * BH, IW / 2, BH,
                                    nullptr, "View.ArrowSizeMin", option_cb);
        view.value[60] =
          valueInput(L + 2 * WB + IW / 2, 2 * WB + 7 * BH, IW / 2, BH,
                     "Arrow size", "View.ArrowSizeMax", option_cb);

        view.value[63] = valueInput<inputValueFloat>(
          L + 2 * WB, 2 * WB + 8 * BH, IW, BH, "Displacement factor",
          "View.DisplacementFactor");
        view.value[63]->minimum(0.);
        view.value[63]->maximum(1.);
        if(CTX::instance()->inputScrolling) view.value[63]->step(0.01);
        view.value[63]->align(FL_ALIGN_RIGHT);
        view.value[63]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        view.value[63]->callback(option_cb);

        view.choice[10] = choice(
          L + 2 * WB, 2 * WB + 9 * BH, IW, BH, "Data source for vector fields",
          "View.ExternalView", nullptr, option_cb, nullptr, -1);
        view.choice[10]->add("Self");
      }
      view.choice[3] =
        choice(L + 2 * WB, 2 * WB + 10 * BH, IW, BH, "Glyph location",
               "View.GlyphLocation", nullptr, option_cb);
      view.choice[15] = choice(C2, 2 * WB + 10 * BH, RW, BH, nullptr,
                               "View.CenterGlyphs", nullptr, option_cb);
      view.choice[4] =
        choice(L + 2 * WB, 2 * WB + 11 * BH, IW, BH, "Tensor display",
               "View.TensorType", nullptr, option_cb);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Color");
      o->hide();

      view.butt[11] =
        checkButton(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Enable lighting",
                    "View.Light (Alt+w)", option_cb);

      view.butt[8] =
        checkButton(L + 2 * WB, 2 * WB + 2 * BH, BW, BH,
                    "Enable lighting of lines", "View.LightLines", option_cb);

      view.butt[9] =
        checkButton(L + 2 * WB, 2 * WB + 3 * BH, BW, BH,
                    "Use two-side lighting", "View.LightTwoSide", option_cb);

      view.butt[12] =
        checkButton(L + 2 * WB, 2 * WB + 4 * BH, BW, BH, "Smooth normals",
                    "View.SmoothNormals", option_cb);

      view.value[10] = valueInput(L + 2 * WB, 2 * WB + 5 * BH, IW, BH,
                                  "Smoothing threshold angle",
                                  "View.AngleSmoothNormals", option_cb);
      view.value[10]->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);

      view.value[79] = valueInput(L + 2 * WB, 2 * WB + 6 * BH, IW, BH,
                                  "Opacity", "View.Opacity", option_cb);
      view.value[79]->when(FL_WHEN_CHANGED | FL_WHEN_RELEASE);

      colorButtons("View", ViewOptions_Color, L + 2 * WB, 3 * WB + 7 * BH, IW,
                   view_color_cb, view.color);

      o->end();
    }
    {
      Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                                 height - 2 * WB - BH, "Map");
      o->hide();

      // the predefined maps by name, above the map itself
      static std::vector<Fl_Menu_Item> menu_colormap;
      if(menu_colormap.empty()) {
        for(int i = 0; i < ColorTable_NumPredefined(); i++) {
          Fl_Menu_Item item = {ColorTable_Name(i), 0, nullptr, nullptr};
          menu_colormap.push_back(item);
        }
        Fl_Menu_Item last = {nullptr};
        menu_colormap.push_back(last);
      }
      view.choice[17] =
        choice(L + 2 * WB, 2 * WB + BH, IW, BH, "Predefined colormap",
               "View.ColormapNumber", &menu_colormap[0], view_colormap_cb);
      // the keys go to the map widget below
      view.choice[17]->clear_visible_focus();

      // 16:9, but tall enough for its help
      int cw = width - 4 * WB;
      view.colorbar =
        new colorbarWindow(L + 2 * WB, 3 * WB + 2 * BH, cw, 9 * cw / 16);
      view.colorbar->size(cw,
                          std::max(9 * cw / 16, view.colorbar->helpHeight()));
      view.colorbar->callback(view_colorbar_cb);

      o->end();
    }
  }
  view.group->end();

  scroll->end();

  redraw = new Fl_Return_Button(winWidth - BB - WB, winHeight - BH - WB, BB, BH,
                                "Redraw");
  redraw->callback(redraw_cb);
  redraw->hide();

  win->end();

  // every widget that sets an option bound to it, and the values of the
  // choices of the view page that are not their indices
  choicesFromTable();

  _category[0] = general.group;
  _category[1] = geo.group;
  _category[2] = mesh.group;
  _category[3] = solver.group;
  _category[4] = post.group;
  _category[5] = view.group;
  for(int c = 0; c < 6; c++) _makeSections(c);
  win->resizable(scroll);
  ((paletteWindow *)win)->sizeRange(winWidth, 12 * BH); // height: layout()
  ((paletteWindow *)win)->whenResized(options_resized_cb, nullptr);
  layout(false);

  FL_NORMAL_SIZE += deltaFontSize;
}

void optionWindow::_makeSections(int c)
{
  // the groups built as tabs become sections; the tab shown first is open
  Fl_Group *g = _category[c];
  bool first = true;
  g->label(nullptr);
  g->resizable(nullptr);
  std::vector<Fl_Group *> groups;
  for(int i = 0; i < g->children(); i++)
    if(g->child(i)->as_group()) groups.push_back(g->child(i)->as_group());
  for(std::size_t i = 0; i < groups.size(); i++) {
    section sec;
    sec.group = groups[i];
    sec.name = sec.group->label();
    sec.open = first && sec.group->visible();
    if(sec.open) first = false;
    sec.group->label(nullptr);
    sec.group->resizable(nullptr);
    sec.group->show();
    // the widgets top to bottom, grouped in blocks of those that overlap
    std::vector<Fl_Widget *> w(sec.group->array(),
                               sec.group->array() + sec.group->children());
    std::stable_sort(w.begin(), w.end(), [](Fl_Widget *a, Fl_Widget *b) {
      return a->y() < b->y();
    });
    for(Fl_Widget *o : w) {
      int y = o->y() - sec.group->y();
      if(sec.blocks.empty() || y >= sec.blocks.back().y + sec.blocks.back().h) {
        block b;
        b.y = y;
        b.h = 0;
        sec.blocks.push_back(b);
      }
      block &b = sec.blocks.back();
      b.h = std::max(b.h, y + o->h() - b.y);
      b.widgets.push_back(o);
      b.dy.push_back(y - b.y);
    }
    // the right column starts in the middle, the right margin is 2 * WB in
    int L = sec.group->x() - WB; // the left edge of the scroll
    sec.rules.record(sec.group, L + _width / 2 - 1, L + _width - 2 * WB);
    sec.header = new Fl_Button(0, 0, sec.group->w(), _rowHeight);
    sec.header->box(FL_FLAT_BOX);
    sec.header->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    sec.header->labelfont(FL_BOLD);
    sec.header->clear_visible_focus();
    sec.header->callback(options_section_cb, (void *)(intptr_t)(100 * c + i));
    g->add(sec.header);
    _sections[c].push_back(sec);
  }
}

static bool matches(Fl_Widget *w, const searchFilter &f)
{
  if(!w->visible()) return false;
  auto has = [&f](const char *text) { return text && f.matches(text); };
  // the tooltip holds the name of the option
  if(has(w->label()) || has(w->tooltip())) return true;
  if(Fl_Menu_ *m = dynamic_cast<Fl_Menu_ *>(w)) {
    for(int i = 0; i < m->size(); i++)
      if(has(m->text(i))) return true;
  }
  if(Fl_Group *g = w->as_group()) {
    for(int i = 0; i < g->children(); i++)
      if(matches(g->child(i), f)) return true;
  }
  return false;
}

bool optionWindow::_searching() { return !_filter.empty(); }

void optionWindow::layout(bool keepPosition)
{
  static const char *names[6] = {"General", "Geometry", "Mesh",
                                 "Solver",  "Post-pro", "View"};
  int bh = _rowHeight, ww = win->w(), wh = win->h();
  _filter.set(search);
  bool searching = !_filter.empty();

  // widgets hidden by the previous search are shown again
  for(Fl_Widget *w : _hiddenBySearch) w->show();
  _hiddenBySearch.clear();

  // the blocks to show: all of them in the current category, or those that
  // match in every category while searching
  std::vector<std::vector<std::vector<bool>>> shown(6);
  bool any[6];
  for(int c = 0; c < 6; c++) {
    any[c] = false;
    bool active = searching ? (c < 5 || PView::list.size()) : (c == _current);
    shown[c].resize(_sections[c].size());
    for(std::size_t i = 0; i < _sections[c].size(); i++) {
      section &sec = _sections[c][i];
      bool all = !searching || _filter.matches(sec.name);
      for(block &b : sec.blocks) {
        bool show = active && all;
        if(active && !all)
          for(Fl_Widget *w : b.widgets)
            if(matches(w, _filter)) show = true;
        shown[c][i].push_back(show);
        if(show) any[c] = true;
      }
    }
  }

  // below the search field, the tabs down to the bottom (or the Redraw
  // button); in their frame the views, as many as there are but down to two
  // in a short window, then the options; the least height of the window
  // leaves three rows of options
  int ty = 2 * WB + bh;
  int tabsBottom = redraw->visible() ? wh - bh - 2 * WB : wh - WB;
  int L = scroll->x();
  int y = ty + bh + WB;
  int bottom = tabsBottom - WB;
  int least = y + 3 * bh + (wh - bottom);
  _tabs->Fl_Widget::resize(WB, ty, ww - 2 * WB, tabsBottom - ty);
  for(int c = 0; c < 6; c++)
    _categoryTab[c]->resize(WB, ty + bh, ww - 2 * WB, tabsBottom - ty - bh);
  // the tab of the category stays while searching in all of them
  _tabs->value(_categoryTab[std::max(0, _current)]);
  _tabs->redraw();
  if(any[5] && PView::list.size()) {
    int h = std::min(viewList->heightFor(PView::list.size()),
                     bottom - y - WB - 3 * bh);
    h = std::max(h, viewList->heightFor(2));
    viewList->resize(L + WB, y, ww - 2 * L - 2 * WB, h);
    viewList->show();
    y += h + WB;
    least += viewList->heightFor(2) + WB;
  }
  else
    viewList->hide();
  // taller if needed, laid out again then
  if(((paletteWindow *)win)->leastHeight(least)) {
    // laid out again by the resize, but scrolled to the top
    layout(keepPosition);
    return;
  }

  int ypos = keepPosition ? scroll->yposition() : 0;
  scroll->scroll_to(0, 0);
  scroll->resize(L, y, ww - 2 * L, std::max(0, bottom - y));
  // sized too: hidden, it is scaled with the window like the scroll it lies in
  redraw->resize(ww - _buttonWidth - WB, wh - bh - WB, _buttonWidth, bh);

  // the sections follow the width; the colormap keeps its shape
  int cw = scroll->w() - Fl::scrollbar_size(), extra = cw - _width;
  int sw = _width - 2 * WB + extra;
  for(int c = 0; c < 6; c++)
    for(section &sec : _sections[c]) sec.rules.apply(extra);
  int cbw = view.colorbar->w();
  view.colorbar->size(cbw, std::max(9 * cbw / 16, view.colorbar->helpHeight()));

  // the sections stacked down the scroll; a group is first moved, which moves
  // its children, then its children are placed and its height set. The
  // groups leave room for the scrollbar, or they could scroll sideways
  int yy = scroll->y();
  bool first = true;
  for(int c = 0; c < 6; c++) {
    Fl_Group *g = _category[c];
    if(!any[c]) {
      // hidden, and of zero height at the top, out of the way
      g->hide();
      g->resize(g->x(), scroll->y(), g->w(), 0);
      continue;
    }
    g->show();
    int y0 = yy;
    g->resize(L, y0, cw, g->h());
    for(std::size_t i = 0; i < _sections[c].size(); i++) {
      section &sec = _sections[c][i];
      std::vector<bool> &show = shown[c][i];
      if(std::find(show.begin(), show.end(), true) == show.end()) {
        sec.header->hide();
        sec.group->hide();
        continue;
      }
      bool open = searching || sec.open;
      std::string label = std::string(open ? "@-22> " : "@-2> ") +
                          (searching ? std::string(names[c]) + " - " : "") +
                          sec.name;
      sec.header->copy_label(label.c_str());
      // a line between sections
      sec.header->box(first ? FL_FLAT_BOX : GMSH_SIMPLE_TOP_BOX);
      sec.header->down_box(sec.header->box()); // no pressed look
      first = false;
      sec.header->resize(L + WB, yy, sw, bh);
      sec.header->show();
      yy += bh;
      if(!open) {
        sec.group->hide();
        continue;
      }
      sec.group->show();
      sec.group->resize(sec.group->x(), yy, sw, sec.group->h());
      int bottom = 0;
      for(std::size_t j = 0; j < sec.blocks.size(); j++) {
        block &b = sec.blocks[j];
        if(!show[j]) {
          for(Fl_Widget *w : b.widgets) {
            if(w->visible()) _hiddenBySearch.push_back(w);
            w->hide();
          }
          continue;
        }
        int gap = j ? b.y - sec.blocks[j - 1].y - sec.blocks[j - 1].h : b.y;
        int top = bottom + gap;
        int h = 0;
        for(std::size_t k = 0; k < b.widgets.size(); k++) {
          b.widgets[k]->position(b.widgets[k]->x(), yy + top + b.dy[k]);
          h = std::max(h, b.dy[k] + b.widgets[k]->h());
        }
        bottom = top + h;
      }
      sec.group->resize(sec.group->x(), yy, sw, bottom + WB);
      yy += bottom + WB;
    }
    g->resize(L, y0, cw, yy - y0);
  }
  int most = std::max(0, yy - scroll->y() - scroll->h());
  scroll->scroll_to(0, std::min(ypos, most));

  win->init_sizes();
  win->redraw();
}

void optionWindow::categoryChosen()
{
  int c = _tabs->find(_tabs->value());
  int n = PView::list.size();
  if(c == 5 && !n) { // no views: the tab is greyed out, and stays so
    layout(true);
    return;
  }
  search->value("");
  if(c < 5)
    showGroup(c + 1);
  else
    showGroup(6 + std::max(0, std::min(view.index, n - 1)), true, true);
}

void optionWindow::toggleSection(int c, int i)
{
  section &sec = _sections[c][i];
  if(_searching()) {
    // a result leads to its section, in full, scrolled to it
    sec.open = true;
    _current = -1;
    int n = PView::list.size();
    showGroup(c < 5 ? c + 1 : 6 + std::max(0, std::min(view.index, n - 1)),
              true, true);
    int bottom = scroll->y();
    for(int k = 0; k < 6; k++)
      if(_category[k]->visible())
        bottom = std::max(bottom, _category[k]->y() + _category[k]->h());
    int most = std::max(0, bottom - scroll->y() - scroll->h());
    scroll->scroll_to(0, std::min(sec.header->y() - scroll->y(), most));
    return;
  }
  sec.open = !sec.open;
  layout(true);
}

void optionWindow::updateViewTargets()
{
  // the view shown in bold ("@." stops the formatting of the name)
  int n = 0;
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if(i == view.index || viewList->browser->selected(i + 1)) n++;
    std::string str =
      (i == view.index ? "@b@." : "@.") + targetList::viewName(i);
    const char *text = viewList->browser->text(i + 1);
    if(!text || str != text) viewList->browser->text(i + 1, str.c_str());
  }
  std::string str = (n > 1) ? "Applies to " + std::to_string(n) + " views" :
                              "Applies to this view only";
  viewList->count->copy_label(str.c_str());
}

void optionWindow::selectViews(const std::string &which)
{
  viewList->selectViews(which, 0, view.index);
  updateViewTargets();
}

void optionWindow::showGroup(int num, bool showWindow,
                             bool allowMultipleSelections)
{
  // a category asked for: the search is left
  if(showWindow) search->value("");
  int c = (num <= 1) ? 0 : (num <= 5) ? num - 1 : 5;
  if(c == 5) {
    if(!allowMultipleSelections) viewList->browser->deselect();
    viewList->browser->select(num - 5, 1);
    updateViewGroup(num - 6);
  }
  updateViewTargets();
  showOptions();
  bool same = (c == _current);
  _current = c;
  layout(same);
  if(showWindow) win->show();
}

void optionWindow::resetBrowser()
{
  viewList->browser->clear();
  for(std::size_t i = 0; i < PView::list.size(); i++)
    viewList->browser->add(""); // the names set by updateViewTargets()
  int n = PView::list.size();
  // the options of a view are also searched in the other categories: those of
  // the view shown, kept or the nearest left
  if(n)
    updateViewGroup(std::max(0, std::min(view.index, n - 1)));
  else {
    view.index = -1;
    view.colorbar->update(-1, 0., 0.);
  }
  if(n)
    _categoryTab[5]->activate();
  else
    _categoryTab[5]->deactivate();
  int num = _current + 1;
  if(_current == 5) num = n ? 6 + std::max(0, std::min(view.index, n - 1)) : 5;
  showGroup(num, false);
}

void optionWindow::resetExternalViewList()
{
  char str[32];
  view.choice[10]->clear();
  view.choice[11]->clear();
  view.choice[10]->add("Self");
  view.choice[11]->add("Self");
  for(std::size_t i = 0; i < PView::list.size(); i++) {
    sprintf(str, "View [%zu]", i);
    view.choice[10]->add(str, 0, nullptr);
    view.choice[11]->add(str, 0, nullptr);
  }
  if(view.index >= 0 && view.index < (int)PView::list.size()) {
    opt_view_external_view(view.index, GMSH_GUI, 0);
    opt_view_gen_raise_view(view.index, GMSH_GUI, 0);
  }
}

void optionWindow::updateViewGroup(int index)
{
  if(index < 0 || index >= (int)PView::list.size()) return;

  view.index = index;

  PView *v = PView::list[index];
  PViewData *data = v->getData();

  double maxval = std::max(fabs(data->getMin()), fabs(data->getMax()));
  if(!maxval) maxval = 1.;
  double val1 = 10. * CTX::instance()->lc;
  double val2 = 2. * CTX::instance()->lc / maxval;

  if(data->getNumPoints() || data->getNumLines()) {
    ((Fl_Menu_Item *)view.choice[13]->menu())[1].activate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[2].activate();
  }
  else {
    ((Fl_Menu_Item *)view.choice[13]->menu())[1].deactivate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[2].deactivate();
  }

  opt_view_colormap_number(index, GMSH_GUI, 0);
  for(int i = 13; i <= 18; i++) {
    if(CTX::instance()->inputScrolling)
      view.value[i]->step(CTX::instance()->lc / 200., 1);
    view.value[i]->minimum(-CTX::instance()->lc);
    view.value[i]->maximum(CTX::instance()->lc);
  }

  if(data->hasElements()) {
    view.range->activate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].activate();
  }
  else {
    view.range->deactivate();
    ((Fl_Menu_Item *)view.choice[13]->menu())[0].deactivate();
  }

  for(int i = 40; i <= 42; i++) {
    if(CTX::instance()->inputScrolling) view.value[i]->step(val1 / 200., 1);
    view.value[i]->minimum(-val1);
    view.value[i]->maximum(val1);
  }
  for(int i = 43; i <= 46; i++) {
    if(CTX::instance()->inputScrolling) view.value[i]->step(val2 / 200., 1);
    view.value[i]->minimum(-val2);
    view.value[i]->maximum(val2);
  }
  if(CTX::instance()->inputScrolling) view.value[2]->step(val2 / 200., 1);
  view.value[2]->minimum(-val2);
  view.value[2]->maximum(val2);

  if(data->getNumTimeSteps() == 1) {
    view.value[50]->deactivate();
    view.push[3]->deactivate();
    view.push[4]->deactivate();
    view.label[0]->deactivate();
  }
  else {
    view.value[50]->activate();
    view.push[3]->activate();
    view.push[4]->activate();
    view.label[0]->activate();
  }
  view.value[50]->maximum(data->getNumTimeSteps() - 1);

  double val3 = 2. * CTX::instance()->lc / maxval;
  if(CTX::instance()->inputScrolling) view.value[63]->step(val3 / 100., 1);
  view.value[63]->maximum(val3);

  // (the widgets bound to the options of the view shown by showGroup())
  view.colorbar->update(v->getTag(), data->getMin(), data->getMax());
}

// the widgets enabled or greyed out together
static void setActive(bool on, std::initializer_list<Fl_Widget *> widgets)
{
  for(Fl_Widget *w : widgets) on ? w->activate() : w->deactivate();
}

void optionWindow::updateActive()
{
  // the parts of the window that only apply with other options, made active
  // or not as those are shown (activate() and deactivate() do nothing when the
  // state does not change)
  // (no drawing here: this is also called by the option setters; laid out
  // again only when the button shows or hides)
  if(general.butt[2]->value() != (redraw->visible() != 0)) {
    if(general.butt[2]->value())
      redraw->show();
    else
      redraw->hide();
    layout(true);
  }
  {
    // studio shading takes the direction of light 0 alone
    if(general.butt[3]->value() && general.choice[8]->value())
      general.value[13]->deactivate();
    else
      general.value[13]->activate();
    setActive(general.butt[3]->value(),
              {general.choice[8], general.value[33], general.value[34],
               general.value[35], geo.value[21], geo.choice[6], mesh.value[27],
               mesh.choice[11], view.value[79]});
  }
  {
    setActive(
      !(general.butt[15]->value()),
      {general.push[0], general.value[8], general.value[9], general.value[10]});
  }
  {
    setActive(general.choice[4]->value(),
              {general.value[17], general.value[18], general.value[19],
               general.input[3], general.input[4], general.input[5],
               general.input[6], general.input[7], general.input[8]});
  }
  {
    setActive(!(general.butt[0]->value()),
              {general.value[20], general.value[21], general.value[22],
               general.value[23], general.value[24], general.value[25],
               general.push[1]});
  }
  {
    setActive(general.butt[1]->value(), {general.value[26], general.value[27]});
  }
  {
    if(general.butt[19]->value()) {
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active)
        general.gamepadconfig->activate();
    }
    else {
      general.gamepadconfig->deactivate();
    }
    setActive(general.butt[17]->value(), {general.value[29]});
    setActive(general.butt[18]->value(),
              {general.value[30], general.value[31]});
  }
  {
    if(geo.choice[3]->value() == 1) {
      for(int i = 7; i <= 18; i++) geo.value[i]->activate();
    }
    else {
      for(int i = 7; i <= 18; i++) geo.value[i]->deactivate();
    }
  }
  {
    setActive(view.choice[7]->value() == 1,
              {view.value[31], view.value[32], view.push[1], view.push[2],
               view.butt[38]});
  }
  {
    setActive(view.butt[0]->value(),
              {view.push[5], view.push[6], view.value[33], view.value[34],
               view.label[1]});
  }
  {
    setActive(view.butt[6]->value(),
              {view.choice[11], view.value[2], view.input[4], view.input[5],
               view.input[6]});
  }
  {
    setActive(mesh.butt[17]->value(),
              {mesh.butt[18], mesh.butt[19], mesh.choice[10], mesh.value[18]});
  }
  {
    setActive(view.butt[11]->value(),
              {view.butt[8], view.butt[9], view.butt[12], view.value[10]});
  }
  {
    setActive(view.choice[8]->value(),
              {view.value[3], view.value[4], view.value[5], view.input[7],
               view.input[8], view.input[9], view.input[10], view.input[11],
               view.input[12]});
  }
  {
    setActive(!(view.butt[25]->value()),
              {view.value[13], view.value[14], view.value[15], view.value[16],
               view.value[17], view.value[18]});
  }
  {
    setActive(view.choice[16]->value() == 0 || view.choice[16]->value() == 12,
              {view.value[20], view.value[21], view.value[22], view.value[23]});
  }
}
