// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// a field carries its own options; what one types is held until Apply, then
// said in the language of the .geo file

#include "GmshConfig.h"

#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "GuiFields.h"
#include "GuiDeclare.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "Context.h"
#include "StringUtils.h"
#include "drawContext.h"
#include "scriptStringInterface.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#endif

using namespace Ui;
using namespace Declare;

namespace {

#if defined(HAVE_MESH)

  FieldManager *_manager()
  {
    GModel *m = GModel::current();
    return m ? m->getFields() : nullptr;
  }

  // leaving out the deprecated ones
  std::vector<std::pair<std::string, FieldOption *>> _options(::Field *f)
  {
    std::vector<std::pair<std::string, FieldOption *>> out;
    if(!f) return out;
    for(auto &kv : f->options) {
      if(!kv.second || kv.second->isDeprecated()) continue;
      out.push_back(std::make_pair(kv.first, kv.second));
    }
    return out;
  }

  std::string _spelled(FieldOption *o)
  {
    std::ostringstream out;
    out.precision(16);
    if(o->getType() == FIELD_OPTION_LIST) {
      const std::list<int> &l = o->list();
      for(auto it = l.begin(); it != l.end(); ++it)
        out << (it == l.begin() ? "" : ", ") << *it;
    }
    else {
      const std::list<double> &l = o->listdouble();
      for(auto it = l.begin(); it != l.end(); ++it)
        out << (it == l.begin() ? "" : ", ") << *it;
    }
    return out.str();
  }

  std::string _asTyped(FieldOption *o)
  {
    switch(o->getType()) {
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH: return o->string();
    case FIELD_OPTION_LIST:
    case FIELD_OPTION_LIST_DOUBLE: return _spelled(o);
    default: return "";
    }
  }

  std::string _written(FieldOption *o, const std::string &typed, double value)
  {
    std::ostringstream out;
    out.precision(16);
    switch(o->getType()) {
    case FIELD_OPTION_STRING:
    case FIELD_OPTION_PATH: out << "\"" << typed << "\""; break;
    case FIELD_OPTION_INT: out << (int)value; break;
    case FIELD_OPTION_DOUBLE: out << value; break;
    case FIELD_OPTION_BOOL: out << (value != 0.); break;
    default: {
      std::string t = typed;
      for(auto &c : t)
        if(c == ',' || c == '{' || c == '}') c = ' ';
      std::istringstream in(t);
      out << "{";
      bool first = true;
      if(o->getType() == FIELD_OPTION_LIST) {
        int v;
        while(in >> v) {
          out << (first ? "" : ", ") << v;
          first = false;
        }
      }
      else {
        double v;
        while(in >> v) {
          out << (first ? "" : ", ") << v;
          first = false;
        }
      }
      out << "}";
    } break;
    }
    return out.str();
  }

  void _types(std::vector<std::string> &labels, std::vector<int> &values)
  {
    FieldManager *m = _manager();
    if(!m) return;
    int i = 0;
    for(auto &kv : m->mapTypeName) {
      labels.push_back(kv.first);
      values.push_back(i++);
    }
  }

  void _views(std::vector<std::string> &labels, std::vector<int> &values)
  {
    labels.push_back("Create new view");
    values.push_back(0);
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      labels.push_back("Put on View [" + std::to_string(i) + "]");
      values.push_back((int)i + 1);
    }
#endif
  }

#endif

} // namespace

#if defined(HAVE_MESH)

static ::Field *_field(int selected)
{
  FieldManager *m = _manager();
  if(!m || selected < 0) return nullptr;
  return m->get(selected);
}

// when the field being edited changes, and once Apply has been through
void GuiFields::fill(bool force)
{
  ::Field *f = _field(selected);
  if(!f) {
    loaded = -1;
    words.clear();
    numbers.clear();
    return;
  }
  if(!force && loaded == f->id) return;
  loaded = f->id;
  words.clear();
  numbers.clear();
  for(const auto &kv : _options(f)) {
    FieldOption *o = kv.second;
    switch(o->getType()) {
    case FIELD_OPTION_INT:
    case FIELD_OPTION_DOUBLE:
    case FIELD_OPTION_BOOL: numbers[kv.first] = o->numericalValue(); break;
    default: words[kv.first] = _asTyped(o); break;
    }
  }
  FieldManager *m = _manager();
  background = m && m->getBackgroundField() == f->id;
}

// through the script, only for what really changed
void GuiFields::apply()
{
  ::Field *f = _field(selected);
  FieldManager *m = _manager();
  if(!f || !m) return;
  std::string file = GModel::current()->getFileName();
  for(const auto &kv : _options(f)) {
    FieldOption *o = kv.second;
    bool numeric = o->getType() == FIELD_OPTION_INT ||
                   o->getType() == FIELD_OPTION_DOUBLE ||
                   o->getType() == FIELD_OPTION_BOOL;
    std::string typed = numeric ? "" : words[kv.first];
    double value = numeric ? numbers[kv.first] : 0.;
    if(numeric ? (value == o->numericalValue()) : (typed == _asTyped(o)))
      continue;
    scriptAddFieldOption(f->id, kv.first, _written(o, typed, value),
                         o->getType(), file);
  }
  if(background && m->getBackgroundField() != f->id)
    scriptSetBackgroundField(f->id, file);
  if(!background && m->getBackgroundField() == f->id)
    scriptSetBackgroundField(-1, file);
  fill(true);
  Gui::instance().updateFields();
  drawContext::global()->draw();
}

void GuiFields::create(int which)
{
  FieldManager *m = _manager();
  if(!m) return;
  std::vector<std::string> labels;
  std::vector<int> values;
  _types(labels, values);
  if(which < 0 || which >= (int)labels.size()) return;
  int id = m->newId();
  scriptAddField(id, labels[which], GModel::current()->getFileName());
  if(m->get(id)) {
    selected = id;
    fill(true);
  }
  Gui::instance().updateFields();
}

void GuiFields::remove()
{
  ::Field *f = _field(selected);
  if(!f) return;
  scriptDeleteField(f->id, GModel::current()->getFileName());
  selected = -1;
  fill(true);
  Gui::instance().updateFields();
  drawContext::global()->draw();
}

void GuiFields::visualize(int which)
{
  ::Field *f = _field(selected);
  if(!f) return;
  f->update();
  if(which <= 0) f->putOnNewView();
#if defined(HAVE_POST)
  else if(which - 1 < (int)PView::list.size())
    f->putOnView(PView::list[which - 1]);
#endif
  Gui::instance().updateViews(which == 0, true);
  drawContext::global()->draw();
}

std::vector<Ui::Line> GuiFields::help()
{
  ::Field *f = _field(selected);
  if(!f) return std::vector<Ui::Line>();
  std::vector<Ui::Line> page = paragraphs(f->getDescription());
  std::vector<std::pair<std::string, FieldOption *>> options = _options(f);
  if(options.size()) page.push_back(middled(said("Options")));
  for(const auto &kv : options)
    page.push_back(item(kv.first, "(" + kv.second->getTypeName() + ") " +
                                    kv.second->getDescription()));
  if(f->callbacks.size()) page.push_back(middled(said("Actions")));
  for(auto &kv : f->callbacks)
    page.push_back(
      item(kv.first, kv.second ? kv.second->getDescription() : ""));
  return page;
}

#endif

Form GuiFields::build()
{
  Form f = {"fields", "Size fields", Item()};
  f.leastRows = 10;
#if defined(HAVE_MESH)
  FieldManager *manager = _manager();
  // a field that has gone is no longer the one being edited
  if(manager && selected >= 0 && !manager->get(selected)) selected = -1;
  fill(false);
  ::Field *field = _field(selected);
  auto some = [this]() { return _field(selected) != nullptr; };

  // the list wants more room than a column of names
  Ui::Field which =
    chooseFrom(
      [](std::vector<std::string> &labels, std::vector<int> &values) {
        FieldManager *m = _manager();
        if(!m) return;
        for(auto &kv : *m) {
          if(!kv.second) continue;
          labels.push_back(
            std::to_string(kv.first) + " " + kv.second->getName() +
            (m->getBackgroundField() == kv.first ? " (background)" : ""));
          values.push_back(kv.first);
        }
      },
      [this](int i) {
        FieldManager *m = _manager();
        if(!m) return false;
        int k = 0;
        for(auto &kv : *m)
          if(kv.second && k++ == i) return kv.first == selected;
        return false;
      },
      [this](int i, bool on) {
        FieldManager *m = _manager();
        if(!m || !on) return;
        int k = 0;
        for(auto &kv : *m)
          if(kv.second && k++ == i) {
            selected = kv.first;
            fill(true);
            rebuild();
            return;
          }
      },
      false)
      .fills()
      .sized(13.);
  Item side = vbox({menu("New", _types, [this](int i) { create(i); }), which,
                    button("Delete", [this]() { remove(); }).enabledWhen(some),
                    menu("Visualize", _views, [this](int i) {
                      visualize(i);
                    }).enabledWhen(some)});

  std::vector<Item> options;
  for(const auto &kv : _options(field)) {
    FieldOption *o = kv.second;
    std::string name = kv.first;
    auto held = [this, name]() { return numbers[name]; };
    auto hold = [this, name](double v) { numbers[name] = v; };
    Ui::Field one;
    switch(o->getType()) {
    case FIELD_OPTION_BOOL:
      one = check(
        name, [held]() { return held() != 0.; },
        [hold](bool on) { hold(on ? 1. : 0.); });
      break;
    case FIELD_OPTION_INT: one = integer(name, held, hold); break;
    case FIELD_OPTION_DOUBLE: one = number(name, held, hold); break;
    default:
      one = text(
        name, [this, name]() { return words[name]; },
        [this, name](const std::string &v) { words[name] = v; });
      break;
    }
    one.tip(o->getDescription());
    if(o->getType() == FIELD_OPTION_PATH)
      options.push_back(
        hbox({one, button("Choose", [this, name]() {
                     std::string file = words[name];
                     if(Gui::instance().fileDialog(0, "Choose", "", file))
                       words[name] = file;
                   }).tight()}));
    else
      options.push_back(one);
  }
  if(field)
    for(auto &kv : field->callbacks) {
      FieldCallback *cb = kv.second;
      if(!cb) continue;
      options.push_back(button(kv.first, [cb]() {
                          cb->run();
                          Gui::instance().updateFields();
                          drawContext::global()->draw();
                        }).tip(cb->getDescription()));
    }
  Item pane = vbox(options).scrolls();
  if(field) {
    // the boundary layer fields are not assigned that way
    bool layer =
      field->getName() && std::string(field->getName()) == "BoundaryLayer";
    pane =
      vbox({pane,
            hbox({check("Set as background field", &background)
                    .enabledWhen([layer]() { return !layer; })
                    .tip(layer ?
                           "Boundary layer fields cannot be assigned in the "
                           "graphical user interface: edit the file directly." :
                           "Only a single field can be set as background "
                           "field.\nTo combine multiple fields use the Min or "
                           "Max fields."),
                  gap(), button("Apply", [this]() { apply(); }).byDefault()})});
  }

  // nothing to edit: what to do, in the middle of the room
  Item edited =
    field ?
      vbox({heading(field->getName()),
            tabs({{"Options", pane},
                  {"Help",
                   vbox({prose([this]() { return help(); })}).scrolls()}})}) :
      vbox({gap(), label("Create a new field", Centre), label("- or -", Centre),
            label("Select a field in the list", Centre), gap()});
  f.content = hbox({side, edited});
#endif
  return f;
}
