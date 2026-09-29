// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DECLARE_H
#define GMSH_GUI_DECLARE_H

// the builders the dialog descriptions are written in

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Form.h"
#include "Tree.h"

namespace Declare {

  using namespace Ui;

  inline Field &bind(Field &f, std::string *v)
  {
    f.readText = [v]() { return *v; };
    f.writeText = [v](const std::string &s) { *v = s; };
    return f;
  }
  inline Field &bind(Field &f, int *v)
  {
    f.readNumber = [v]() { return (double)*v; };
    f.writeNumber = [v](double x) { *v = (int)x; };
    return f;
  }
  inline Field &bind(Field &f, double *v)
  {
    f.readNumber = [v]() { return *v; };
    f.writeNumber = [v](double x) { *v = x; };
    return f;
  }
  inline Field &bind(Field &f, bool *v)
  {
    f.readNumber = [v]() { return *v ? 1. : 0.; };
    f.writeNumber = [v](double x) { *v = (x != 0.); };
    return f;
  }
  // A value noun takes its label first, then what it is bound to: a
  // variable, an option by its full name ("Mesh.Algorithm",
  // "View[2].Visible", "General.Color.Text"), or a pair of functions.
  Field &bindOption(Field &f, const std::string &name);
  Field &bindOption(Field &f, const std::string &category,
                    const std::string &name, int index);
  // of the kind the option table says: text, number or colour
  Field option(const std::string &label, const std::string &name);

  inline Field _value(FieldKind kind, const std::string &label)
  {
    Field f;
    f.kind = kind;
    f.label = label;
    return f;
  }

  inline Field text(const std::string &label, std::string *value)
  {
    Field f = _value(Text, label);
    return bind(f, value);
  }
  inline Field text(const std::string &label, const std::string &name)
  {
    Field f = _value(Text, label);
    return bindOption(f, name);
  }
  inline Field text(const std::string &label, std::function<std::string()> read,
                    std::function<void(const std::string &)> write)
  {
    Field f = _value(Text, label);
    f.readText = read;
    f.writeText = write;
    return f;
  }

  inline Field check(const std::string &label, bool *value)
  {
    Field f = _value(Check, label);
    return bind(f, value);
  }
  inline Field check(const std::string &label, const std::string &name)
  {
    Field f = _value(Check, label);
    return bindOption(f, name);
  }
  // without write, a light
  inline Field check(const std::string &label, std::function<bool()> read)
  {
    Field f = _value(Check, label);
    f.readNumber = [read]() { return read() ? 1. : 0.; };
    return f;
  }
  inline Field check(const std::string &label, std::function<bool()> read,
                     std::function<void(bool)> write)
  {
    Field f = check(label, read);
    f.writeNumber = [write](double v) { write(v != 0.); };
    return f;
  }

  inline Field number(const std::string &label, double *value)
  {
    Field f = _value(Number, label);
    return bind(f, value);
  }
  inline Field number(const std::string &label, const std::string &name)
  {
    Field f = _value(Number, label);
    return bindOption(f, name);
  }
  inline Field number(const std::string &label, std::function<double()> read,
                      std::function<void(double)> write)
  {
    Field f = _value(Number, label);
    f.readNumber = read;
    f.writeNumber = write;
    return f;
  }

  inline Field integer(const std::string &label, int *value)
  {
    Field f = _value(Integer, label);
    return bind(f, value);
  }
  inline Field integer(const std::string &label, const std::string &name)
  {
    Field f = _value(Integer, label);
    return bindOption(f, name);
  }
  inline Field integer(const std::string &label, std::function<double()> read,
                       std::function<void(double)> write)
  {
    Field f = number(label, read, write);
    f.kind = Integer;
    return f;
  }

  // a choice stands for its text, or for the number of the entry picked;
  // without a list, offering() gives one
  inline Field choice(const std::string &label, std::string *value,
                      const std::vector<std::string> &choices = {})
  {
    Field f = _value(Choice, label);
    f.choices = choices;
    return bind(f, value);
  }
  inline Field choice(const std::string &label, int *value,
                      const std::vector<std::string> &choices = {},
                      const std::vector<int> &values = {})
  {
    Field f = _value(Choice, label);
    f.choices = choices;
    f.values = values;
    return bind(f, value);
  }
  inline Field choice(const std::string &label, const std::string &name,
                      const std::vector<std::string> &choices = {})
  {
    Field f = _value(Choice, label);
    f.choices = choices;
    return bindOption(f, name);
  }
  // what each entry writes, when it is not its place in the list
  typedef std::vector<std::pair<std::string, int>> Pairs;
  inline Field choice(const std::string &label, const std::string &name,
                      const Pairs &choices)
  {
    Field f = _value(Choice, label);
    for(const auto &c : choices) {
      f.choices.push_back(c.first);
      f.values.push_back(c.second);
    }
    return bindOption(f, name);
  }
  inline Field choice(const std::string &label, std::function<double()> read,
                      std::function<void(double)> write)
  {
    Field f = number(label, read, write);
    f.kind = Choice;
    return f;
  }

  inline Field colour(const std::string &label, const std::string &name)
  {
    Field f = _value(Color, label);
    return bindOption(f, name);
  }

  // `what` fills the list when it is opened; picking the line of index i runs
  // `pick(i)`
  inline Field menu(const std::string &label,
                    std::function<void(std::vector<std::string> &,
                                       std::vector<int> &)> what,
                    std::function<void(int)> pick)
  {
    Field f;
    f.kind = Ui::Menu;
    f.label = label;
    f.dynamicChoices = what;
    f.choose = [pick](int i, bool) { pick(i); };
    return f;
  }

  inline Field picked(const std::string &label, const std::vector<int> *what,
                      std::function<std::string(int)> name,
                      std::function<void(int)> drop)
  {
    Field f;
    f.kind = List;
    f.label = label;
    f.list = what;
    f.itemLabel = name;
    f.removeItem = drop;
    return f;
  }

  // a disc `lines` lines tall, hanging over what follows it
  inline Field direction(std::function<void(double &, double &, double &)> read,
                         std::function<void(double, double, double)> write,
                         int lines = 2)
  {
    Field f;
    f.kind = Direction;
    f.readVector = read;
    f.writeVector = write;
    f.rows = lines;
    return f;
  }

  inline Field tree(const Ui::Tree &what)
  {
    Field f;
    f.kind = Hierarchy;
    f.hierarchy = std::make_shared<Ui::Tree>(what);
    return f;
  }

  inline Field chooseFrom(std::function<void(std::vector<std::string> &,
                          std::vector<int> &)> what,
                          std::function<bool(int)> isChosen,
                          std::function<void(int, bool)> setChosen, bool several)
  {
    Field f;
    f.kind = List;
    f.dynamicChoices = what;
    f.chosen = isChosen;
    f.choose = setChosen;
    f.multiple = several;
    return f;
  }

  inline Field label(const std::string &text, Align align = Left)
  {
    Field f;
    f.kind = Label;
    f.readText = [text]() { return text; };
    f.align = align;
    return f;
  }
  inline Field label(std::function<std::string()> what, Align align = Left)
  {
    Field f;
    f.kind = Label;
    f.readText = what;
    f.align = align;
    return f;
  }

  inline Field output(const std::string &label,
                      std::function<std::string()> what)
  {
    Field f = _value(Output, label);
    f.readText = what;
    return f;
  }

  inline Field button(const std::string &text, std::function<void()> action)
  {
    Field f;
    f.kind = Action;
    f.label = text;
    f.changed = action;
    return f;
  }

  inline Field prose(std::function<std::vector<Ui::Line>()> page)
  {
    Field f;
    f.kind = Prose;
    f.prose = page;
    return f;
  }

  inline Ui::Line said(const std::string &text)
  {
    Ui::Line l;
    l.words.push_back(Ui::Words(text));
    return l;
  }
  // a line of prose per line of the text, one with no words for an empty one
  inline std::vector<Ui::Line> paragraphs(const std::string &text)
  {
    std::vector<Ui::Line> page;
    for(std::size_t at = 0; at <= text.size();) {
      std::size_t end = text.find('\n', at);
      if(end == std::string::npos) end = text.size();
      page.push_back(end > at ? said(text.substr(at, end - at)) : Ui::Line());
      at = end + 1;
    }
    return page;
  }
  inline Ui::Line middled(Ui::Line l)
  {
    l.centred = true;
    return l;
  }
  inline Ui::Line item(const std::string &name, const std::string &value)
  {
    Ui::Line l;
    l.bullet = true;
    l.words.push_back(Ui::Words(name + ":", true));
    l.words.push_back(Ui::Words(" " + value));
    return l;
  }
  inline Ui::Line titled(const std::string &text)
  {
    Ui::Line l = middled(said(text));
    l.heading = true;
    return l;
  }
  inline Ui::Line &following(Ui::Line &l, const std::string &text,
                             std::function<void()> go)
  {
    Ui::Words w(text);
    w.follow = go;
    l.words.push_back(w);
    return l;
  }

  inline Field disclosure(const std::string &label, bool *value)
  {
    Field f = check(label, value);
    f.disclosure = true;
    f.packed = true;
    return f;
  }

  // --- what a form is made of

  inline Box vbox(const std::vector<Item> &items)
  {
    Box b;
    b.items = items;
    return b;
  }
  inline Box vbox(std::initializer_list<Item> items)
  {
    return vbox(std::vector<Item>(items));
  }

  inline Box grid(const std::vector<Item> &items)
  {
    Box b = vbox(items);
    b.grid = true;
    return b;
  }
  inline Box grid(std::initializer_list<Item> items)
  {
    return grid(std::vector<Item>(items));
  }

  // `padding` em apart: the interface's usual gap when not said, none when zero
  inline Box hbox(const std::vector<Item> &items, double padding = -1.)
  {
    Box b = vbox(items);
    b.direction = Box::Across;
    b.padding = padding;
    return b;
  }
  inline Box hbox(std::initializer_list<Item> items, double padding = -1.)
  {
    return hbox(std::vector<Item>(items), padding);
  }

  inline Tabs tabs(std::initializer_list<std::pair<std::string, Item>> tabs,
                   std::function<void(const std::string &)> chosen = nullptr)
  {
    Tabs t;
    t.tabs = tabs;
    t.chosen = chosen;
    return t;
  }

  inline Item rule()
  {
    Item it;
    it.kind = Item::ARule;
    return it;
  }

  inline Item heading(const std::string &text)
  {
    Item it;
    it.kind = Item::AHeading;
    it.text = text;
    return it;
  }

  // never less than `least` em
  inline Field gap(double least = 2.)
  {
    Field f;
    f.kind = Spacer;
    f.widthEm = least;
    return f;
  }

} // namespace Declare

#endif
