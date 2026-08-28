// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The mesh size fields, what each of them takes and which of them the mesh is
// built from: the counterpart of src/fltk/fieldWindow.cpp, described once and
// built by both interfaces. A field carries its own options, so the fields of
// the pane are not written here at all -- they are made from whatever the size
// field one has picked says it takes.
//
// The window this replaces does not write what one types straight into the
// field: it holds it until Apply, and then says what changed in the language
// of the .geo file, so that the change is in the script as well as in the
// model. That is what the boxes below are for.

#include "GmshConfig.h"

#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "GuiDialogs.h"
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

namespace {

  // Which field the window is editing, and what one has typed into it so far.
  // The window this replaces kept both in its widgets: the browser said which,
  // and the inputs held what had not been applied yet.
  struct sizeFieldState {
    int selected = -1; // the field being edited, -1 for none
    int loaded = -1; // the one the boxes below were filled from
    bool background = false; // whether it is the one the mesh is built from
    std::map<std::string, std::string> words;
    std::map<std::string, double> numbers;
  };

  sizeFieldState &_state()
  {
    static sizeFieldState state;
    return state;
  }

#if defined(HAVE_MESH)

  FieldManager *_manager()
  {
    GModel *m = GModel::current();
    return m ? m->getFields() : nullptr;
  }

  ::Field *_current()
  {
    FieldManager *m = _manager();
    if(!m || _state().selected < 0) return nullptr;
    return m->get(_state().selected);
  }

  // the options of a field, in the order it keeps them, leaving out the ones
  // it no longer wants anybody to use
  std::vector<std::pair<std::string, FieldOption *> > _options(::Field *f)
  {
    std::vector<std::pair<std::string, FieldOption *> > out;
    if(!f) return out;
    for(auto &kv : f->options) {
      if(!kv.second || kv.second->isDeprecated()) continue;
      out.push_back(std::make_pair(kv.first, kv.second));
    }
    return out;
  }

  // A list of numbers as one types it: what the window this replaces shows,
  // which is the numbers separated by commas and no braces around them.
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

  // what the field says an option holds, as one would type it
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

  // Fill the boxes from the field. It is done when the field one is editing
  // changes, and again once Apply has been through: until then what one has
  // typed is what they hold, whatever the field says.
  void _load(bool force)
  {
    ::Field *f = _current();
    if(!f) {
      _state().loaded = -1;
      _state().words.clear();
      _state().numbers.clear();
      return;
    }
    if(!force && _state().loaded == f->id) return;
    _state().loaded = f->id;
    _state().words.clear();
    _state().numbers.clear();
    for(const auto &kv : _options(f)) {
      FieldOption *o = kv.second;
      switch(o->getType()) {
      case FIELD_OPTION_INT:
      case FIELD_OPTION_DOUBLE:
      case FIELD_OPTION_BOOL:
        _state().numbers[kv.first] = o->numericalValue();
        break;
      default: _state().words[kv.first] = _asTyped(o); break;
      }
    }
    FieldManager *m = _manager();
    _state().background = m && m->getBackgroundField() == f->id;
  }

  // one option, in the language of the .geo file
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
      // a list of numbers, however one has separated them
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

  // Write down what one has typed, as the window this replaces does: through
  // the script, so that the field is changed in the file as well as in the
  // model, and only for what really changed.
  void _apply()
  {
    ::Field *f = _current();
    FieldManager *m = _manager();
    if(!f || !m) return;
    std::string file = GModel::current()->getFileName();
    for(const auto &kv : _options(f)) {
      FieldOption *o = kv.second;
      bool numeric = o->getType() == FIELD_OPTION_INT ||
                     o->getType() == FIELD_OPTION_DOUBLE ||
                     o->getType() == FIELD_OPTION_BOOL;
      std::string typed = numeric ? "" : _state().words[kv.first];
      double value = numeric ? _state().numbers[kv.first] : 0.;
      if(numeric ? (value == o->numericalValue()) : (typed == _asTyped(o)))
        continue;
      scriptAddFieldOption(f->id, kv.first, _written(o, typed, value),
                           o->getType(), file);
    }
    if(_state().background && m->getBackgroundField() != f->id)
      scriptSetBackgroundField(f->id, file);
    if(!_state().background && m->getBackgroundField() == f->id)
      scriptSetBackgroundField(-1, file);
    _load(true);
    Gui::updateFields();
    drawContext::global()->draw();
  }

  // the kinds of field one may make, as the manager knows them
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

  void _create(int which)
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
      _state().selected = id;
      _load(true);
    }
    Gui::updateFields();
  }

  void _remove()
  {
    ::Field *f = _current();
    if(!f) return;
    scriptDeleteField(f->id, GModel::current()->getFileName());
    _state().selected = -1;
    _load(true);
    Gui::updateFields();
    drawContext::global()->draw();
  }

  // where a field may be drawn: a view of its own, or one that is already
  // there
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

  void _visualize(int which)
  {
    ::Field *f = _current();
    if(!f) return;
    f->update();
    if(which <= 0)
      f->putOnNewView();
#if defined(HAVE_POST)
    else if(which - 1 < (int)PView::list.size())
      f->putOnView(PView::list[which - 1]);
#endif
    Gui::updateViews(which == 0, true);
    drawContext::global()->draw();
  }

  // What the Help tab says: what the field is for, then every option and every
  // action it offers. The window this replaces writes it as a page of HTML;
  // here it is the same words, plainly.
  std::string _help()
  {
    ::Field *f = _current();
    if(!f) return "";
    std::string out = f->getDescription();
    std::vector<std::pair<std::string, FieldOption *> > options = _options(f);
    if(options.size()) out += "\n\nOptions\n";
    for(const auto &kv : options)
      out += "\n" + kv.first + " (" + kv.second->getTypeName() +
             "): " + kv.second->getDescription() + "\n";
    if(f->callbacks.size()) out += "\nActions\n";
    for(auto &kv : f->callbacks)
      out += "\n" + kv.first + ": " +
             (kv.second ? kv.second->getDescription() : "") + "\n";
    return out;
  }

#endif

} // namespace

namespace Dialog {

  Panel fields()
  {
    Panel p;
    p.title = "Size fields";
    p.tabbed = true;
    // the list of fields, and the two buttons under it, want more room than a
    // column of names
    p.sideEm = 13.;
    // the name of the field takes a line over the panes, and the window this
    // reproduces is not taller for it
    p.leastRows = 10;

#if defined(HAVE_MESH)
    FieldManager *manager = _manager();
    // a field that has gone -- the model was closed, or it was deleted from
    // the script -- is no longer the one being edited
    if(manager && _state().selected >= 0 && !manager->get(_state().selected))
      _state().selected = -1;
    _load(false);
    ::Field *field = _current();

    // --- which field, with what one does to it: as the window this replaces
    // has them, the list between the button that makes one and the two that
    // act on the one that is picked
    {
      p.side.push_back(menu("New", _types, _create));

      Field which = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          FieldManager *m = _manager();
          if(!m) return;
          for(auto &kv : *m) {
            if(!kv.second) continue;
            labels.push_back(std::to_string(kv.first) + " " +
                             kv.second->getName() +
                             (m->getBackgroundField() == kv.first ?
                                " (background)" : ""));
            values.push_back(kv.first);
          }
        },
        [](int i) {
          FieldManager *m = _manager();
          if(!m) return false;
          int k = 0;
          for(auto &kv : *m)
            if(kv.second && k++ == i) return kv.first == _state().selected;
          return false;
        },
        [](int i, bool on) {
          FieldManager *m = _manager();
          if(!m || !on) return;
          int k = 0;
          for(auto &kv : *m)
            if(kv.second && k++ == i) {
              _state().selected = kv.first;
              _load(true);
              return;
            }
        },
        false);
      which.rows = 0;
      p.side.push_back(which);

      Field remove = does("Delete", _remove);
      remove.enabled = []() { return _current() != nullptr; };
      p.side.push_back(remove);

      Field draw = menu("Visualize", _views, _visualize);
      draw.enabled = []() { return _current() != nullptr; };
      p.side.push_back(draw);
    }

    // --- what it is, over the panes: the window this replaces writes the name
    // of the field over the row of tabs, not inside one of them
    {
      std::string name = field ? field->getName() : "";
      p.header.push_back(names([name]() { return name; }));
    }

    // --- what it takes
    {
      Pane options;
      options.label = "Options";
      if(!field) {
        // the window this replaces says as much, in the room the editor would
        // have taken
        options.fields.push_back(
          says([]() { return "Create a new field"; }));
        options.fields.push_back(says([]() { return "- or -"; }));
        options.fields.push_back(
          says([]() { return "Select a field in the list"; }));
      }
      for(const auto &kv : _options(field)) {
        FieldOption *o = kv.second;
        std::string name = kv.first;
        Field f;
        switch(o->getType()) {
        case FIELD_OPTION_BOOL:
          f = check(name, nullptr);
          f.readNumber = [name]() { return _state().numbers[name]; };
          f.writeNumber = [name](double v) { _state().numbers[name] = v; };
          break;
        case FIELD_OPTION_INT:
        case FIELD_OPTION_DOUBLE:
          f = number(name, nullptr);
          if(o->getType() == FIELD_OPTION_INT) f.kind = Integer;
          f.readNumber = [name]() { return _state().numbers[name]; };
          f.writeNumber = [name](double v) { _state().numbers[name] = v; };
          break;
        default:
          f = edits(name, [name]() { return _state().words[name]; },
                    [name](const std::string &v) { _state().words[name] = v; });
          break;
        }
        f.tooltip = o->getDescription();
        options.fields.push_back(f);
        // a path is chosen rather than typed, as it is there
        if(o->getType() == FIELD_OPTION_PATH) {
          Field choose = does("Choose", [name]() {
            std::string file = _state().words[name];
            if(Gui::fileDialog(0, "Choose", "", file))
              _state().words[name] = file;
          });
          choose.sameRow = true;
          choose.packed = true;
          options.fields.push_back(choose);
        }
      }
      // and what it can do, which is not an option but a thing to run
      if(field)
        for(auto &kv : field->callbacks) {
          FieldCallback *cb = kv.second;
          if(!cb) continue;
          Field act = does(kv.first, [cb]() {
            cb->run();
            Gui::updateFields();
            drawContext::global()->draw();
          });
          act.tooltip = cb->getDescription();
          options.fields.push_back(act);
        }
      // the one field the mesh is really built from
      if(field) {
        Field background = check("Set as background field", &_state().background);
        // the boundary layer fields are not assigned that way, and the window
        // this replaces says so rather than letting one try
        bool layer = field->getName() &&
                     std::string(field->getName()) == "BoundaryLayer";
        background.enabled = [layer]() { return !layer; };
        background.tooltip =
          layer ? "Boundary layer fields cannot be assigned in the graphical "
                  "user interface: edit the file directly."
                : "Only a single field can be set as background field.\n"
                  "To combine multiple fields use the Min or Max fields.";
        // on the line of Apply, as the window this replaces has it
        options.beside.push_back(background);
      }
      options.scrolling = true;
      if(field) {
        options.buttonLabel = "Apply";
        options.button = _apply;
      }
      p.panes.push_back(options);
    }

    // --- and what it is for
    {
      Pane help;
      help.label = "Help";
      std::string text = _help();
      Field says_ = says([text]() { return text; });
      says_.wraps = true;
      says_.rows = 10;
      help.fields.push_back(says_);
      help.scrolling = true;
      p.panes.push_back(help);
    }
#endif
    return p;
  }

} // namespace Dialog
