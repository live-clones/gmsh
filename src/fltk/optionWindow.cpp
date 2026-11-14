// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <cstdint>
#include <string.h>
#include <algorithm>
#include <list>
#include <set>
#include <map>
#include <functional>
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
#include "sceneTool.h"
#include "hintInput.h"
#include "gamepadWindow.h"
#include "graphicWindow.h"
#include "openglWindow.h"
#include "paletteWindow.h"
#include "manipWindow.h"
#include "extraDialogs.h"
#include "drawContext.h"
#include "Actions.h"
#include "Options.h"
#include "OptionPages.h"
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
  // (the labels kept here, for the items, which point to them: each once,
  // however often the choices are made again)
  static std::set<std::string> labels;
  std::vector<Fl_Menu_Item> items;
  std::vector<double> values;
  for(auto &ch : GetOptionChoices(option)) {
    const std::string &label = *labels.insert(ch.second).first;
    items.push_back({label.c_str(), 0, nullptr, nullptr, 0});
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
// the first widget bound to each option, by its full name (see boundWidget())
static std::map<std::string, Fl_Widget *> &boundByName()
{
  static std::map<std::string, Fl_Widget *> m;
  return m;
}

static void bind(Fl_Widget *w, const char *option, int offset = 0)
{
  if(!option) return;
  std::string s(option);
  s = s.substr(0, s.find(' '));
  std::size_t dot = s.find('.');
  if(dot == std::string::npos) return;
  bindings()[w] = {s.substr(0, dot), s.substr(dot + 1), offset};
  boundByName().insert({s, w});
}

// the values of the indices of a widget bound to an option (see
// optionBinding), or what is added to them
static void bindValues(Fl_Widget *w, const std::vector<double> &values)
{
  if(!bindings().count(w)) bind(w, w->tooltip());
  bindings()[w].values = values;
}

// the widget bound to an option (the first, if several), or null; as the
// valuator, choice or button it is
static Fl_Widget *boundWidget(const std::string &option)
{
  auto it = boundByName().find(option);
  return it == boundByName().end() ? nullptr : it->second;
}
static Fl_Valuator *boundValue(const std::string &option)
{
  return dynamic_cast<Fl_Valuator *>(boundWidget(option));
}
static Fl_Choice *boundChoice(const std::string &option)
{
  return dynamic_cast<Fl_Choice *>(boundWidget(option));
}
static Fl_Button *boundButton(const std::string &option)
{
  return dynamic_cast<Fl_Button *>(boundWidget(option));
}

// the titles of the headings of the sections (see EntryHeading), and the
// groups of the numbers with - and + buttons (see EntryStepper), by option
static std::map<std::string, Fl_Widget *> &headings()
{
  static std::map<std::string, Fl_Widget *> h;
  return h;
}
static std::map<std::string, Fl_Group *> &steppers()
{
  static std::map<std::string, Fl_Group *> g;
  return g;
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
// page shows of the view shown, its colors and its color map, but those that
// say what each view is (its name, its data, its time step, the view it
// refers to)
static void linkViews(const std::vector<int> &nums)
{
  if(!opt_post_link(0, GMSH_GET, 0) || nums.size() < 2) return;
  const std::string own = ",Name,FileName,Group,Attributes,AxesLabelX,"
                          "AxesLabelY,AxesLabelZ,TimeStep,Time,ExternalView,"
                          "GeneralizedRaiseView,";
  auto linked = [&own](const std::string &n) {
    return own.find("," + n + ",") == std::string::npos;
  };
  std::vector<std::string> names;
  for(auto &b : bindings())
    if(b.second.category == "View" && linked(b.second.name))
      names.push_back(b.second.name);
  for(Fl_Menu_Button *m : toggleMenus())
    if(menuCategory(m) == "View")
      for(const std::string &n : menuOptions(m))
        if(linked(n)) names.push_back(n);
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
// selected in the list (see viewTargets() and linkViews()); data is unused
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

void general_options_rotation_center_select_cb(Fl_Widget *w, void *data)
{
  // one click, as a tool of the current window (see sceneTool)
  sceneTool::start(newRotationCenterTool(),
                   FlGui::instance()->getCurrentOpenglWindow(),
                   (Fl_Window *)FlGui::instance()->options->win);
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

Fl_Widget *optionWindow::widget(const std::string &option) const
{
  return boundWidget(option);
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
  CTX::instance()->drawRotationCenter = 1;
  SPoint3 p(boundValue("General.RotationCenterX")->value(),
            boundValue("General.RotationCenterY")->value(),
            boundValue("General.RotationCenterZ")->value());
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
  // the rotation about the pseudo center of mass, or back about the center
  // given (General.RotationCenter, kept as the user set it)
  option_cb(w, nullptr);
  CTX *c = CTX::instance();
  const double *rc = c->rotationCenterCg ? c->cg : c->rotationCenter;
  SPoint3 p(rc[0], rc[1], rc[2]);
  FlGui::instance()
    ->getCurrentOpenglWindow()
    ->getDrawContext()
    ->recenterForRotationCenterChange(p);
  FlGui::instance()->manip->update();
}

// a coordinate of the light typed in: the ball follows
static void general_light_cb(Fl_Widget *w, void *data)
{
  optionWindow *o = FlGui::instance()->options;
  option_cb(w, nullptr);
  o->general.sphere->setValue(boundValue("General.Light0X")->value(),
                              boundValue("General.Light0Y")->value(),
                              boundValue("General.Light0Z")->value());
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
  Fl_Button *camera = boundButton("General.Camera"),
            *gamepad = boundButton("General.Gamepad");
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

void showViewOptions(int num)
{
  if(num < 0) { // the view shown last, or the first
    int current = FlGui::instance()->options->view.index;
    if(current >= 0 && current < (int)PView::list.size())
      num = current;
    else
      num = 0;
  }
  if(num >= 0 && num < (int)PView::list.size())
    FlGui::instance()->options->showGroup(num + 6);
}

// the time step typed in (or stepped), for the view shown and the selected
// ones, and the scene drawn again
static void view_options_timestep_cb(Fl_Widget *w, void *data)
{
  for(int i : viewTargets())
    opt_view_timestep(i, GMSH_SET, ((Fl_Value_Input *)w)->value());
  drawContext::global()->draw();
}

// The widgets of the view page set their options with option_cb(); these do
// more.

// the custom range from the smallest or the largest value of the views
// (visible, and as their tensors are drawn)
static void view_range_cb(Fl_Widget *w, void *data)
{
  bool min = !strcmp((const char *)data, "range_min");
  double v = min ? 1e200 : -1e200;
  for(int i : viewTargets())
    v = min ? std::min(v, opt_view_min_visible(i, GMSH_GET, 0)) :
              std::max(v, opt_view_max_visible(i, GMSH_GET, 0));
  Fl_Valuator *field = boundValue(min ? "View.CustomMin" : "View.CustomMax");
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
  o->view.colormap->value((int)opt_view_colormap_number(nums[0], GMSH_GET, 0));
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
                         int y, int w, Fl_Callback *cb)
{
  for(int i = 0, j = 0; table[j].str; j++) {
    if(table[j].level & GMSH_DEPRECATED) continue;
    Fl_Button *b = new Fl_Button(x, y + i++ * BH, w, BH, table[j].str);
    b->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
    b->callback(cb, (void *)table[j].function);
    colorBindings()[b] = {category, table[j].str, table[j].function};
  }
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

// The pages of the window come from the table of OptionPages.h (see there);
// the rows are laid out here. What the interface adds: the custom rows by
// name, built by a function given the left edge, the top and the width of
// their place (a custom row alone in its row returns the rows it takes), and
// the callbacks of the entries that do more than set their option
struct pageBuilders {
  std::map<std::string, std::function<int(int x, int y, int w)>> custom;
  std::map<std::string, Fl_Callback *> hooks;
};

// the option of a entry, with the key of the action that sets it (see
// GetOptionShortcuts()), as the tooltip of its widget (kept: FLTK keeps the
// pointer)
static const char *entryTooltip(const std::string &option)
{
  static std::set<std::string> kept;
  std::string tip = option;
  std::vector<Shortcut> keys = GetOptionShortcuts(option);
  if(!keys.empty()) tip += " (" + keys[0].label() + ")";
  return kept.insert(tip).first->c_str();
}

// the - or + button of a stepper: the value stepped, and set
static void step_cb(Fl_Widget *w, void *data)
{
  Fl_Valuator *v = (Fl_Valuator *)data;
  v->value(v->clamp(v->value() + (strcmp(w->label(), "-") ? 1 : -1)));
  v->do_callback();
}

// a number with its - and + buttons, and its label after them, in a group
// (de)activated together (see steppers()); width is that of the section
static Fl_Widget *stepperEntry(const optionEntry &f, int x, int y, int w,
                               int width, const char *option, Fl_Callback *cb)
{
  int sw = (int)(1.5 * FL_NORMAL_SIZE);
  Fl_Group *g = new Fl_Group(x, y, w + width / 2, BH);
  Fl_Value_Input *v =
    valueInput(x + sw, y, w - 2 * sw, BH, nullptr, option, cb);
  if(f.flags & EntryOnRelease) v->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
  if(CTX::instance()->inputScrolling && !GetOptionRange(f.option)) v->step(1);
  Fl_Button *minus = new Fl_Button(x, y, sw, BH, "-");
  minus->callback(step_cb, v);
  Fl_Button *plus = new Fl_Button(x + w - sw, y, sw, BH, "+");
  plus->callback(step_cb, v);
  Fl_Box *l = new Fl_Box(x + w, y, width / 2, BH, f.label.c_str());
  l->box(FL_NO_BOX);
  l->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  g->end();
  steppers()[f.option] = g;
  return v;
}

// the widget of a entry, bound to its option; width is that of the section
static Fl_Widget *entryWidget(const optionEntry &f, int x, int y, int w,
                              int width, const pageBuilders &b)
{
  const char *label = f.label.empty() ? nullptr : f.label.c_str();
  const char *option = entryTooltip(f.option);
  auto h = b.hooks.find(f.option);
  Fl_Callback *cb = (h != b.hooks.end()) ? h->second : option_cb;
  switch(f.kind) {
  case EntryCheck: return checkButton(x, y, w, BH, label, option, cb);
  case EntryNumber: {
    if(f.flags & EntryStepper)
      return stepperEntry(f, x, y, w, width, option, cb);
    Fl_Value_Input *v =
      (f.flags & EntryFloat) ?
        valueInput<inputValueFloat>(x, y, w, BH, label, option, cb) :
        valueInput(x, y, w, BH, label, option, cb);
    if(f.flags & EntryOnRelease) v->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
    return v;
  }
  case EntryChoice: return choice(x, y, w, BH, label, option, nullptr, cb);
  case EntryText: return input(x, y, w, BH, label, option, cb);
  default: return nullptr;
  }
}

// a custom entry: built by its name (none for a space)
static int customEntry(const optionEntry &f, int x, int y, int w,
                       const pageBuilders &b)
{
  if(f.option.empty()) return 0;
  auto it = b.custom.find(f.option);
  if(it == b.custom.end()) {
    Msg::Error("Unknown row '%s' in the option window", f.option.c_str());
    return 1;
  }
  return it->second(x, y, w);
}

// a section of a page: its group, with its rows (the first one row below the
// top of the section)
static Fl_Group *buildSection(const optionSection &s, int L, int width,
                              int height, const pageBuilders &b)
{
  Fl_Group *o = new Fl_Group(L + WB, WB + BH, width - 2 * WB,
                             height - 2 * WB - BH, s.name.c_str());
  if(!s.open) o->hide();
  int BW = width - 4 * WB, x = L + 2 * WB, r = 1;
  // the second column: after the entry of the first and a label of 7 em
  int C2 = x + IW + 7 * FL_NORMAL_SIZE, RW = BW - IW - 7 * FL_NORMAL_SIZE;
  for(const optionRow &row : s.rows) {
    int y = 2 * WB + r * BH;
    r++;
    if(row.empty()) continue;
    const optionEntry &f = row[0];
    if(f.kind == EntryHeading) {
      Fl_Box *line = new Fl_Box(x, y, BW, 2);
      line->box(FL_ENGRAVED_FRAME);
      line->labeltype(FL_NO_LABEL);
      Fl_Box *title = new Fl_Box(FL_NO_BOX, x, y + 1, IW, BH, f.option.c_str());
      title->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
      headings()[f.option] = title;
      continue;
    }
    if(row.size() == 1 && f.kind == EntryCustom) {
      r += customEntry(f, x, y, width, b) - 1;
      continue;
    }
    // the entries in columns: check buttons share the row, the other entries
    // the width of one, by weight; a entry of the second column, or a custom
    // entry without weight, is placed apart (a check button alone before the
    // second column runs up to it)
    bool columns = false, apart = false;
    int total = 0;
    for(const optionEntry &g : row) {
      if(g.kind == EntryCheck) columns = true;
      if(g.flags & (EntryColumn2 | EntryColumn2Half)) apart = true;
      else if(g.weight > 0) total += g.weight;
    }
    if(apart) columns = false;
    int span = columns ? BW : IW, cum = 0;
    for(const optionEntry &g : row) {
      if(g.flags & (EntryColumn2 | EntryColumn2Half)) {
        entryWidget(g, C2, y, (g.flags & EntryColumn2Half) ? RW / 2 : RW,
                    width, b);
        continue;
      }
      if(g.weight <= 0) {
        customEntry(g, x, y, width, b);
        continue;
      }
      int x0 = x + span * cum / total;
      cum += g.weight;
      int w = x + span * cum / total - x0 - (columns && cum < total ? WB : 0);
      if(apart && g.kind == EntryCheck && total == g.weight) w = C2 - x - WB;
      if(g.kind == EntryCustom)
        customEntry(g, x0, y, w, b);
      else
        entryWidget(g, x0, y, w, width, b);
    }
  }
  o->end();
  return o;
}

optionWindow::optionWindow(int deltaFontSize) : gmpdoption(nullptr)
{
  // (the widgets of a window built before are gone)
  bindings().clear();
  boundByName().clear();
  headings().clear();
  steppers().clear();
  toggleMenus().clear();
  colorBindings().clear();
  view.index = -1;
  view.hasElements = true;

  FL_NORMAL_SIZE -= deltaFontSize;

  // the widgets of each section are built at their place in a tab of at most
  // 11 rows of this width; layout() then stacks the sections in the scroll,
  // which lies inside the frame of the tabs
  int L = WB + Fl::box_dx(FL_THIN_UP_BOX);
  int width = TW - 2 * L - Fl::scrollbar_size();
  int height = 12 * BH + 4 * WB;
  _rowHeight = BH;
  _buttonWidth = BB;
  _width = width;
  _current = 0;

  // the scroll ends L inside the frame of the tabs: its scrollbar, shown when
  // needed, lines up with the right edge of the search field and the tabs
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
                          nullptr, CTX::instance()->optOffset, nullptr,
                          &CTX::instance()->optHeight);
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

  // The pages, from the table of OptionPages.h; what the table cannot say is
  // built here by name (see pageBuilders), and the entries that do more than
  // set their option get their callback
  pageBuilders b;
  for(const char *o : {"General.RotationCenterX", "General.RotationCenterY",
                       "General.RotationCenterZ"})
    b.hooks[o] = general_rotation_center_cb;
  b.hooks["General.RotationCenterGravity"] = general_rotation_center_cg_cb;
  b.hooks["General.SaveSession"] = general_session_save_cb;
  for(const char *o : {"General.Light0X", "General.Light0Y", "General.Light0Z"})
    b.hooks[o] = general_light_cb;
  b.hooks["General.Camera"] = b.hooks["General.Gamepad"] = general_camera_cb;
  b.hooks["Solver.AlwaysListen"] = solver_listen_cb;
  b.hooks["View.TimeStep"] = view_options_timestep_cb;

  // a button beside the entries of a row, at the right of their label
  auto button = [](int x, int y, const char *label, Fl_Callback *cb) {
    Fl_Button *p = new Fl_Button(x + 2 * IW - 4 * WB, y, BB, BH, label);
    p->callback(cb);
    return p;
  };
  // the button that shows the path of a file (the session or option file)
  auto showFile = [](const char *which) {
    return [which](int x, int y, int w) {
      Fl_Button *p = new Fl_Button(x, y, w, BH, "Show file path");
      p->callback(options_show_file_cb, (void *)which);
      return 0;
    };
  };
  // the colour buttons of a category, one row down
  auto colors = [](const char *category, StringXColor *table, Fl_Callback *cb) {
    return [=](int x, int y, int) {
      colorButtons(category, table, x, y + WB, IW, cb);
      return 1;
    };
  };
  // a menu of toggles, one per option of the list
  auto toggles = [](const char *label, const char *options,
                    Fl_Menu_Item *items) {
    return [=](int x, int y, int) {
      toggleMenu(x, y, IW, BH, label, options, items);
      return 1;
    };
  };
  // a choice of the views, listed as they come (see resetExternalViewList())
  auto viewChoice = [](Fl_Choice **choiceOf, const char *label,
                       const char *option) {
    return [=](int x, int y, int) {
      *choiceOf = choice(x, y, IW, BH, label, entryTooltip(option), nullptr,
                         option_cb, nullptr, -1);
      (*choiceOf)->add("Self");
      return 1;
    };
  };
  // the matrix of a transformation, with the offsets (and the raise of a view)
  auto transformation = [](const char *category, bool raise) {
    return [=](int x, int y, int) {
      int ss = 2 * IW / 3 / 3 + 4, rows = raise ? 4 : 3;
      std::string c(category);
      if(raise) {
        // the matrix, the offsets and the raise move together, as one table
        new Fl_Group(x, y, 2 * IW - 3 * WB + 7 * IW / 10, 4 * BH);
        Fl_Box *t = new Fl_Box(FL_NO_BOX, x, y, IW, BH,
                               "Coordinate transformation:");
        t->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
        Fl_Box *t2 =
          new Fl_Box(FL_NO_BOX, x + 2 * IW - 3 * WB, y, 7 * IW / 10, BH,
                     "Raise:");
        t2->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);
        y += BH;
      }
      const char *axes[3] = {"X", "Y", "Z"}, *labels[3] = {" X", " Y +", " Z"};
      for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
          Fl_Value_Input *v =
            valueInput(x + j * ss, y + i * BH, ss, BH,
                       j == 2 ? labels[i] : nullptr,
                       entryTooltip(c + ".Transform" + axes[i] + axes[j]));
          v->minimum(-1.);
          v->maximum(1.);
          if(CTX::instance()->inputScrolling) v->step(0.1);
          v->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
          v->callback(option_cb);
        }
        // (the offsets and the raise of a view follow the view shown, see
        // updateViewGroup())
        const char *offset = entryTooltip(c + ".Offset" + axes[i]);
        Fl_Value_Input *off =
          raise ? valueInput<inputValueFloat>(x + IW, y + i * BH, 7 * IW / 10,
                                              BH, nullptr, offset) :
                  valueInput(x + IW, y + i * BH, 7 * IW / 10, BH, nullptr,
                             offset);
        if(!raise) {
          off->minimum(-1.);
          off->maximum(1.);
          if(CTX::instance()->inputScrolling) off->step(0.1);
        }
        off->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
        off->callback(option_cb);
        if(raise) {
          Fl_Value_Input *r = valueInput<inputValueFloat>(
            x + 2 * IW - 3 * WB, y + i * BH, 7 * IW / 10, BH, nullptr,
            entryTooltip(c + ".Raise" + axes[i]));
          r->when(FL_WHEN_RELEASE | FL_WHEN_ENTER_KEY);
          r->callback(option_cb);
        }
      }
      if(raise) Fl_Group::current()->end();
      return rows;
    };
  };

  // General
  b.custom["Select rotation center"] = [this, button](int x, int y, int) {
    general.selectRotationCenter =
      button(x, y, "Select", general_options_rotation_center_select_cb);
    return 0;
  };
  b.custom["Show session file"] = showFile("session");
  b.custom["Show option file"] = showFile("option");
  b.custom["Restore default options"] = [](int x, int y, int width) {
    Fl_Button *p = new Fl_Button(x, y, width - 4 * WB, BH,
                                 "Restore all options to default settings");
    p->callback(options_restore_defaults_cb);
    if(CTX::instance()->guiDark)
      p->color(FL_DARK_RED);
    else
      p->labelcolor(FL_DARK_RED);
    return 1;
  };
  b.custom["Fit axes to visible"] = [this](int x, int y, int) {
    general.fitAxes = new Fl_Button(x, y, IW, BH, "Fit to visible");
    general.fitAxes->callback(general_options_axes_fit_cb);
    return 1;
  };
  b.custom["Edit arrow"] = [button](int x, int y, int) {
    button(x, y, "Edit arrow", general_arrow_param_cb);
    return 0;
  };
  b.custom["Font engine"] = [](int x, int y, int) {
    static Fl_Menu_Item engines[] = {{"Native", 0, nullptr, nullptr},
                                     {"StringTexture", 0, nullptr, nullptr},
                                     {"Embedded", 0, nullptr, nullptr},
                                     {nullptr}};
    choice(x, y, IW, BH, "Font rendering engine",
           "General.GraphicsFontEngine", engines, option_cb);
    return 1;
  };
  b.custom["Graphics font"] = [](int x, int y, int w) {
    choice(x, y, w, BH, nullptr, "General.GraphicsFont", menu_font_names,
           option_cb);
    return 0;
  };
  b.custom["Graphics font of titles"] = [](int x, int y, int w) {
    choice(x, y, w, BH, nullptr, "General.GraphicsFontTitle", menu_font_names,
           option_cb);
    return 0;
  };
  b.custom["Light sphere"] = [this, L, width](int x, int y, int) {
    // the ball beside the two rows of the light, after the longer of their
    // labels
    fl_font(FL_HELVETICA, FL_NORMAL_SIZE);
    double l1 = fl_width(boundWidget("General.Light0Z")->label());
    double l2 = fl_width(boundWidget("General.Brightness")->label());
    int xs = x + IW + WB + (int)std::max(l1, l2);
    int ws = std::min(2 * BH, L + width - 2 * WB - xs);
    general.sphere =
      new spherePositionWidget(L + width - 2 * WB - ws, y - BH, ws);
    general.sphere->callback(general_light_sphere_cb);
    return 0;
  };
  b.custom["General colors"] =
    colors("General", GeneralOptions_Color, color_cb);
  b.custom["Configure gamepad"] = [this](int x, int y, int width) {
    general.gamepadconfig =
      new Fl_Button(x, y, width - 4 * WB, BH, "Configure Gamepad");
    general.gamepadconfig->callback(general_gmpdcf_cb);
    return 1;
  };
  // Geometry
  b.custom["Geometry transformation"] = transformation("Geometry", false);
  b.custom["Geometry colors"] =
    colors("Geometry", GeometryOptions_Color, color_cb);
  // Mesh
  static Fl_Menu_Item meshElementTypes[] = {
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
  b.custom["Mesh element types"] =
    toggles("Elements",
            "Mesh.Triangles, Mesh.Quadrangles, Mesh.Tetrahedra, "
            "Mesh.Hexahedra, Mesh.Prisms, Mesh.Pyramids, Mesh.Trihedra, "
            "Mesh.Polygons, Mesh.Polyhedra",
            meshElementTypes);
  b.custom["Mesh colors"] = colors("Mesh", MeshOptions_Color, color_cb);
  // View
  b.custom["Range minimum"] = [this](int x, int y, int w) {
    view.rangeMin = new Fl_Button(x, y, w, BH, "Min");
    view.rangeMin->callback(view_range_cb, (void *)"range_min");
    return 0;
  };
  b.custom["Range maximum"] = [this](int x, int y, int w) {
    view.rangeMax = new Fl_Button(x, y, w, BH, "Max");
    view.rangeMax->callback(view_range_cb, (void *)"range_max");
    return 0;
  };
  static Fl_Menu_Item viewElementTypes[] = {
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
  b.custom["View element types"] =
    toggles("Elements",
            "View.DrawPoints, View.DrawLines, View.DrawTriangles, "
            "View.DrawQuadrangles, View.DrawTetrahedra, View.DrawHexahedra, "
            "View.DrawPrisms, View.DrawPyramids, View.DrawTrihedra, "
            "View.DrawPolygons, View.DrawPolyhedra",
            viewElementTypes);
  static Fl_Menu_Item viewFieldTypes[] = {
    {"Scalar", 0, nullptr, nullptr, FL_MENU_TOGGLE},
    {"Vector", 0, nullptr, nullptr, FL_MENU_TOGGLE},
    {"Tensor", 0, nullptr, nullptr, FL_MENU_TOGGLE},
    {nullptr}};
  b.custom["View field types"] =
    toggles("Fields", "View.DrawScalars, View.DrawVectors, View.DrawTensors",
            viewFieldTypes);
  b.custom["Component map"] = [width](int x, int y, int) {
    // the 9 fields of the map widen together
    int W = width - 5 * WB - IW, w = W / 9;
    Fl_Group *row = new Fl_Group(x + WB + IW, y, W, BH);
    for(int i = 0; i < 9; i++)
      valueInput(x + WB + IW + i * w, y, (i < 8) ? w : W - 8 * w, BH, nullptr,
                 entryTooltip("View.ComponentMap" + std::to_string(i)), -1, 9,
                 1, option_cb);
    row->end();
    return 0;
  };
  b.custom["View transformation"] = transformation("View", true);
  b.custom["Generalized raise view"] = viewChoice(
    &view.generalizedRaiseView, "Data source", "View.GeneralizedRaiseView");
  b.custom["External view"] = viewChoice(
    &view.externalView, "Data source for vector fields", "View.ExternalView");
  b.custom["View colors"] = colors("View", ViewOptions_Color, view_color_cb);
  b.custom["Colormap"] = [this](int x, int y, int) {
    // the predefined maps by name, above the map itself
    static std::vector<Fl_Menu_Item> maps;
    if(maps.empty()) {
      for(int i = 0; i < ColorTable_NumPredefined(); i++) {
        Fl_Menu_Item item = {ColorTable_Name(i), 0, nullptr, nullptr};
        maps.push_back(item);
      }
      Fl_Menu_Item last = {nullptr};
      maps.push_back(last);
    }
    view.colormap = choice(x, y, IW, BH, "Predefined colormap",
                           entryTooltip("View.ColormapNumber"), &maps[0],
                           view_colormap_cb);
    // the keys go to the map widget below
    view.colormap->clear_visible_focus();
    return 1;
  };
  b.custom["Colorbar"] = [this](int x, int y, int width) {
    // 16:9, but tall enough for its help
    int cw = width - 4 * WB;
    view.colorbar = new colorbarWindow(x, y + WB, cw, 9 * cw / 16);
    view.colorbar->size(cw,
                        std::max(9 * cw / 16, view.colorbar->helpHeight()));
    view.colorbar->callback(view_colorbar_cb);
    return 1;
  };

  // the pages, each a group of its sections, the first one shown
  Fl_Group **groups[6] = {&general.group, &geo.group,  &mesh.group,
                          &solver.group,  &post.group, &view.group};
  int c = 0;
  for(const optionPage &page : OptionPages()) {
    Fl_Group *g = new Fl_Group(L, 0, width, height);
    g->copy_label((page.name + " Options").c_str());
    if(c) g->hide();
    for(const optionSection &sec : page.sections)
      buildSection(sec, L, width, height, b);
    g->end();
    *groups[c++] = g;
  }

  // what this build cannot do
#if !defined(_OPENMP)
  boundWidget("General.NumThreads")->deactivate();
#endif
#if !defined(HAVE_VISUDEV)
  boundWidget("General.HeavyVisualization")->deactivate();
#endif
#if !defined(HAVE_OCC)
  headings()["Open CASCADE model healing options:"]->deactivate();
  for(const char *o :
      {"Geometry.OCCFixDegenerated", "Geometry.OCCFixSmallEdges",
       "Geometry.OCCFixSmallFaces", "Geometry.OCCSewFaces",
       "Geometry.OCCMakeSolids", "Geometry.OCCScaling"})
    boundWidget(o)->deactivate();
#endif
#if !defined(HAVE_NETGEN)
  boundWidget("Mesh.OptimizeNetgen")->deactivate();
#endif

  scroll->end();

  redraw = new Fl_Return_Button(winWidth - BB - WB, winHeight - BH - WB, BB, BH,
                                "Redraw");
  redraw->callback(redraw_cb);
  redraw->hide();

  win->end();

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
  // placed even when hidden: resizing the window scales all its children with
  // the scroll, its resizable
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
  for(Fl_Choice *c : {view.externalView, view.generalizedRaiseView}) {
    c->clear();
    c->add("Self");
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      sprintf(str, "View [%zu]", i);
      c->add(str, 0, nullptr);
    }
  }
  // (cleared, the choices show the sources of the view shown again)
  if(view.index >= 0 && view.index < (int)PView::list.size()) {
    showOption("View", view.index, "ExternalView");
    showOption("View", view.index, "GeneralizedRaiseView");
  }
}

// the state the widget of an option shows (a check button, or the index of
// a choice); 0, said, for an option the table of OptionPages.cpp does not
// have
static int shown(const char *option)
{
  Fl_Widget *w = boundWidget(option);
  if(Fl_Choice *c = dynamic_cast<Fl_Choice *>(w)) return c->value();
  if(Fl_Button *b = dynamic_cast<Fl_Button *>(w)) return b->value();
  Msg::Error("No entry for option '%s' in the option window", option);
  return 0;
}

// the widgets enabled or greyed out together, given or by their options
static void setActive(bool on, std::initializer_list<Fl_Widget *> widgets)
{
  for(Fl_Widget *w : widgets) on ? w->activate() : w->deactivate();
}
static void setActive(bool on, std::initializer_list<const char *> options)
{
  for(const char *o : options) {
    auto it = steppers().find(o);
    Fl_Widget *w = (it != steppers().end()) ? it->second : boundWidget(o);
    // (an option the table of OptionPages.cpp does not have)
    if(!w) {
      Msg::Error("No entry for option '%s' in the option window", o);
      continue;
    }
    setActive(on, {w});
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
  double lc = CTX::instance()->lc, val1 = 10. * lc, val2 = 2. * lc / maxval;

  // a range that follows the view, and the step of its scrolling
  auto range = [](const char *option, double min, double max, double step) {
    Fl_Valuator *v = boundValue(option);
    if(CTX::instance()->inputScrolling) v->step(step, 1);
    v->minimum(min);
    v->maximum(max);
  };

  // the plot types the data allows: the 2D plots need points or lines, the 3D
  // plot elements
  Fl_Menu_Item *types = (Fl_Menu_Item *)boundChoice("View.Type")->menu();
  for(int i : {1, 2}) {
    if(data->getNumPoints() || data->getNumLines())
      types[i].activate();
    else
      types[i].deactivate();
  }
  view.hasElements = data->hasElements();
  if(view.hasElements)
    types[0].activate();
  else
    types[0].deactivate();
  // the range, the intervals and the adaptation apply to elements (see also
  // updateActive())
  setActive(view.hasElements,
            {"View.NbIso", "View.NumberFormat", "View.IntervalsType",
             "View.ScaleType", "View.RangeType", "View.SaturateValues",
             "View.CustomMin", "View.ScaleThreshold", "View.CustomMax",
             "View.AdaptVisualizationGrid", "View.AdaptSkinOnly",
             "View.MaxRecursionLevel", "View.TargetError"});
  setActive(view.hasElements, {view.rangeMin, view.rangeMax});

  opt_view_colormap_number(index, GMSH_GUI, 0);
  for(const char *o : {"View.AxesMinX", "View.AxesMinY", "View.AxesMinZ",
                       "View.AxesMaxX", "View.AxesMaxY", "View.AxesMaxZ"})
    range(o, -lc, lc, lc / 200.);
  for(const char *o : {"View.OffsetX", "View.OffsetY", "View.OffsetZ"})
    range(o, -val1, val1, val1 / 200.);
  for(const char *o : {"View.RaiseX", "View.RaiseY", "View.RaiseZ",
                       "View.NormalRaise", "View.GeneralizedRaiseFactor"})
    range(o, -val2, val2, val2 / 200.);
  range("View.DisplacementFactor", 0., val2, val2 / 100.);

  setActive(data->getNumTimeSteps() != 1, {"View.TimeStep"});
  boundValue("View.TimeStep")->maximum(data->getNumTimeSteps() - 1);

  // (the widgets bound to the options of the view shown by showGroup())
  view.colorbar->update(v->getTag(), data->getMin(), data->getMax());
}


void optionWindow::updateActive()
{
  // the parts of the window that only apply with other options, made active
  // or not as those are shown (activate() and deactivate() do nothing when the
  // state does not change)
  // (no drawing here: this is also called by the option setters; laid out
  // again only when the button shows or hides)
  bool fastRedraw = shown("General.FastRedraw");
  if(fastRedraw != (redraw->visible() != 0)) {
    if(fastRedraw)
      redraw->show();
    else
      redraw->hide();
    layout(true);
  }
  {
    // studio shading takes the direction of light 0 alone
    bool shaders = shown("General.Shaders");
    setActive(!(shaders && shown("General.Shading")),
              {"General.Light0W"});
    setActive(shaders,
              {"General.Shading", "General.StudioSamples",
               "General.StudioFloorOffset", "General.StudioLightSpread",
               "Geometry.Opacity", "Geometry.OpacityMode", "Mesh.Opacity",
               "Mesh.OpacityMode", "View.Opacity"});
  }
  {
    bool given = !shown("General.RotationCenterGravity");
    setActive(given, {"General.RotationCenterX", "General.RotationCenterY",
                      "General.RotationCenterZ"});
    setActive(given, {general.selectRotationCenter});
  }
  setActive(shown("General.Axes"),
            {"General.AxesTicksX", "General.AxesTicksY", "General.AxesTicksZ",
             "General.AxesFormatX", "General.AxesFormatY",
             "General.AxesFormatZ", "General.AxesLabelX", "General.AxesLabelY",
             "General.AxesLabelZ"});
  {
    bool given = !shown("General.AxesAutoPosition");
    setActive(given, {"General.AxesMinX", "General.AxesMinY",
                      "General.AxesMinZ", "General.AxesMaxX",
                      "General.AxesMaxY", "General.AxesMaxZ"});
    setActive(given, {general.fitAxes});
  }
  setActive(shown("General.SmallAxes"),
            {"General.SmallAxesPositionX", "General.SmallAxesPositionY"});
  {
    if(shown("General.Gamepad")) {
      if(CTX::instance()->gamepad && CTX::instance()->gamepad->active)
        general.gamepadconfig->activate();
    }
    else {
      general.gamepadconfig->deactivate();
    }
    setActive(shown("General.Stereo"),
              {"General.CameraEyeSeparationRatio"});
    setActive(shown("General.Camera"),
              {"General.CameraFocalLengthRatio", "General.CameraAperture"});
  }
  {
    bool on = shown("Geometry.Transform") == 1;
    for(const char *a : {"X", "Y", "Z"}) {
      for(const char *b : {"X", "Y", "Z"})
        setActive(on, {boundWidget(std::string("Geometry.Transform") + a + b)});
      setActive(on, {boundWidget(std::string("Geometry.Offset") + a)});
    }
  }
  setActive(shown("Mesh.Light"),
            {"Mesh.LightTwoSide", "Mesh.SmoothNormals", "Mesh.LightLines",
             "Mesh.AngleSmoothNormals"});
  {
    // (the range and the adaptation only apply to a view with elements)
    bool custom =
      view.hasElements && shown("View.RangeType") == 1;
    setActive(custom,
              {"View.CustomMin", "View.CustomMax", "View.SaturateValues"});
    setActive(custom, {view.rangeMin, view.rangeMax});
    bool adapt = view.hasElements &&
                 shown("View.AdaptVisualizationGrid");
    setActive(adapt, {"View.TargetError", "View.MaxRecursionLevel"});
  }
  {
    bool on = shown("View.UseGeneralizedRaise");
    setActive(on, {"View.GeneralizedRaiseFactor", "View.GeneralizedRaiseX",
                   "View.GeneralizedRaiseY", "View.GeneralizedRaiseZ"});
    setActive(on, {view.generalizedRaiseView});
  }
  setActive(shown("View.Light"),
            {"View.LightLines", "View.LightTwoSide", "View.SmoothNormals",
             "View.AngleSmoothNormals"});
  setActive(shown("View.Axes"),
            {"View.AxesTicksX", "View.AxesTicksY", "View.AxesTicksZ",
             "View.AxesFormatX", "View.AxesFormatY", "View.AxesFormatZ",
             "View.AxesLabelX", "View.AxesLabelY", "View.AxesLabelZ"});
  setActive(!shown("View.AxesAutoPosition"),
            {"View.AxesMinX", "View.AxesMinY", "View.AxesMinZ", "View.AxesMaxX",
             "View.AxesMaxY", "View.AxesMaxZ"});
  int position = shown("View.AutoPosition");
  setActive(position == 0 || position == 12,
            {"View.PositionX", "View.PositionY", "View.Width", "View.Height"});
}
