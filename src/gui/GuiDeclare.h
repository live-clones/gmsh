// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DECLARE_H
#define GMSH_GUI_DECLARE_H

// The little builders the dialog descriptions are written in, so that a
// description reads as description and not as structure filling.

#include <functional>
#include <string>
#include <utility>
#include <vector>

#include "Form.h"

namespace Declare {

  using namespace Ui;

  // a field bound to a variable of ours
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
  // A field bound to a Gmsh option, the pairs that go with its kind: by its
  // full name, "Mesh.Algorithm", "View[2].Visible", "General.Color.Text", or
  // by its parts.
  Field &bindOption(Field &f, const std::string &name);
  Field &bindOption(Field &f, const std::string &category,
                    const std::string &name, int index);
  // the same, with the kind the option table gives: text, number or colour
  Field option(const std::string &label, const std::string &name);

  inline Field text(const std::string &label, std::string *value,
                    const std::string &tooltip = "")
  {
    Field f;
    f.kind = Text;
    f.label = label;
    f.tooltip = tooltip;
    return bind(f, value);
  }
  inline Field text(const std::string &name)
  {
    Field f;
    f.kind = Text;
    return bindOption(f, name);
  }

  inline Field check(const std::string &label, bool *value)
  {
    Field f;
    f.kind = Check;
    f.label = label;
    return bind(f, value);
  }
  inline Field check(const std::string &name)
  {
    Field f;
    f.kind = Check;
    return bindOption(f, name);
  }

  inline Field integer(const std::string &label, int *value)
  {
    Field f;
    f.kind = Integer;
    f.label = label;
    return bind(f, value);
  }
  inline Field integer(const std::string &name)
  {
    Field f;
    f.kind = Integer;
    return bindOption(f, name);
  }

  inline Field choice(const std::string &label, std::string *value,
                      const std::vector<std::string> &choices)
  {
    Field f;
    f.kind = Choice;
    f.label = label;
    f.choices = choices;
    return bind(f, value);
  }

  // a choice that stands for something other than its own text
  inline Field choice(const std::string &label, int *value,
                      const std::vector<std::string> &choices,
                      const std::vector<int> &values)
  {
    Field f;
    f.kind = Choice;
    f.label = label;
    f.choices = choices;
    f.values = values;
    return bind(f, value);
  }

  inline Field number(const std::string &label, double *value,
                      const std::string &tooltip = "")
  {
    Field f;
    f.kind = Number;
    f.label = label;
    f.tooltip = tooltip;
    return bind(f, value);
  }
  inline Field number(const std::string &name)
  {
    Field f;
    f.kind = Number;
    return bindOption(f, name);
  }
  inline Field colour(const std::string &name)
  {
    Field f;
    f.kind = Color;
    return bindOption(f, name);
  }

  // what a field is called, written after it or before it
  inline Field labeled(Field f, const std::string &text)
  {
    f.label = text;
    return f;
  }
  inline Field labeled(const std::string &text, Field f)
  {
    f.label = text;
    f.labelBefore = true;
    return f;
  }

  // an option chosen among words, each standing for one of its numbers
  inline Field
  option(const std::string &name,
         const std::vector<std::pair<std::string, int>> &choices)
  {
    Field f;
    f.kind = Choice;
    for(const auto &c : choices) {
      f.choices.push_back(c.first);
      f.values.push_back(c.second);
    }
    return bindOption(f, name);
  }

  // the same field, bounded
  inline Field within(Field f, double lo, double hi, double step = 0.)
  {
    f.minimum = lo;
    f.maximum = hi;
    f.step = step;
    return f;
  }

  // a value one reads and cannot edit
  inline Field reads(const std::string &label, std::function<std::string()> what)
  {
    Field f;
    f.kind = Output;
    f.label = label;
    f.readText = what;
    return f;
  }

  // words that live somewhere the description cannot point at: what the
  // field shows and what changing it does are given as a pair of functions
  inline Field edits(const std::string &label,
                     std::function<std::string()> read,
                     std::function<void(const std::string &)> write)
  {
    Field f;
    f.kind = Text;
    f.label = label;
    f.readText = read;
    f.writeText = write;
    return f;
  }

  // A button that drops a list of things to do: `what` fills the list when it
  // is opened, and picking the line of index i runs `pick(i)`.
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

  // a button in the flow of the fields
  inline Field does(const std::string &label, std::function<void()> what)
  {
    Field f;
    f.kind = Action;
    f.label = label;
    f.changed = what;
    return f;
  }

  // A direction one gives by dragging a point over a disc, `lines` lines
  // tall. It hangs over what follows it rather than making its own line that
  // tall.
  inline Field direction(std::function<void(double &, double &, double &)> read,
                         std::function<void(double, double, double)> write,
                         int lines = 2)
  {
    Field f;
    f.kind = Direction;
    f.readVector = read;
    f.writeVector = write;
    f.rows = lines;
    f.packed = true;
    return f;
  }

  // the same field, to be looked at twice: what it does cannot be taken back
  inline Field warns(Field f)
  {
    f.alert = true;
    return f;
  }

  // what has been picked so far, which one may correct
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

  // a list one chooses from, rather than one that only shows
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

  // a line the dialog says, rather than a value it holds
  inline Field says(std::function<std::string()> what)
  {
    Field f;
    f.kind = Label;
    f.readText = what;
    return f;
  }

  // the same line, written in the middle of its cell
  inline Field centred(Field f)
  {
    f.centred = true;
    return f;
  }

  // a line that names what is under it, rather than saying something about it
  inline Field names(std::function<std::string()> what)
  {
    Field f = says(what);
    f.heading = true;
    return f;
  }

  // the same line, with a rule over it: what follows is a group of its own
  inline Field ruledOver(Field f)
  {
    f.rule = true;
    return f;
  }

  // a page of written text rather than a row of fields
  inline Field prose(std::function<std::vector<Ui::Line>()> page)
  {
    Field f;
    f.kind = Prose;
    f.prose = page;
    return f;
  }

  // the pieces a line of prose is made of, said briefly enough to write a
  // page with them
  inline Ui::Line said(const std::string &text)
  {
    Ui::Line l;
    l.words.push_back(Ui::Words(text));
    return l;
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
  // a word one may follow, added to a line
  inline Ui::Line &following(Ui::Line &l, const std::string &text,
                             std::function<void()> go)
  {
    Ui::Words w(text);
    w.follow = go;
    l.words.push_back(w);
    return l;
  }

  // the same value, draggable along a scale as well as typed; it wants
  // bounds, which within() gives
  inline Field slid(Field f)
  {
    f.slider = true;
    return f;
  }

  // a check that folds a part of the dialog away
  inline Field disclosure(const std::string &label, bool *value)
  {
    Field f = check(label, value);
    f.disclosure = true;
    f.packed = true;
    return f;
  }

  // the same field, taking only the width it needs rather than a share of
  // the line
  inline Field tight(Field f)
  {
    f.packed = true;
    return f;
  }

  // the same field, whose value is taken once one has finished typing it
  // rather than at every letter
  inline Field whenDone(Field f)
  {
    f.commitsWhenDone = true;
    return f;
  }

  // the same field, that wide, in multiples of the font size
  inline Field sized(Field f, double em)
  {
    f.widthEm = em;
    return f;
  }

  // the same field, taking that fraction of the room one field is given:
  // two halves fill exactly one
  inline Field shared(Field f, double part)
  {
    f.widthShare = part;
    f.packed = true;
    return f;
  }

  // nothing: it eats what is left of the line, so that what follows it ends
  // up against the right edge
  inline Field stretch(double least = 2.)
  {
    Field f;
    f.kind = Spacer;
    f.widthEm = least;
    f.sameRow = true;
    return f;
  }

  // a pane with a rule under it
  inline Pane ruled(Pane q)
  {
    q.separatorAfter = true;
    return q;
  }

  // the same field, but sharing the line of the one before it
  inline Field beside(Field f)
  {
    f.sameRow = true;
    return f;
  }

  inline Pane pane(const std::vector<Field> &fields,
                   const std::string &label = "")
  {
    Pane p;
    p.label = label;
    p.fields = fields;
    return p;
  }

  // --- what a form is made of

  // items one under another
  inline Box vbox(std::initializer_list<Item> items)
  {
    Box b;
    b.items = items;
    return b;
  }

  // lines whose cells line up in columns, each as wide as its widest cell
  inline Box grid(std::initializer_list<Item> items)
  {
    Box b = vbox(items);
    b.grid = true;
    return b;
  }

  // items across one line, `padding` em apart: the interface's usual gap
  // when it is not said, none when it is zero
  inline Box hbox(std::initializer_list<Item> items, double padding = -1.)
  {
    Box b = vbox(items);
    b.direction = Box::Across;
    b.padding = padding;
    return b;
  }

  // the same box, shown only when; a flag is read where it lives, so it
  // has to outlive the form
  inline Box visibleWhen(std::function<bool()> when, Box b)
  {
    b.visible = when;
    return b;
  }
  inline Box visibleWhen(const bool &flag, Box b)
  {
    b.visible = [&flag]() { return flag; };
    return b;
  }
  Box visibleWhen(bool &&flag, Box b) = delete;

  inline Box scrolling(Box b)
  {
    b.scrolling = true;
    return b;
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

  // what is left of the line, and never less than `least` em; in a split,
  // an empty cell
  inline Field gap(double least = 2.)
  {
    Field f;
    f.kind = Spacer;
    f.widthEm = least;
    return f;
  }

  // a button at the bottom of the form
  inline Button button(const std::string &label, std::function<void()> action)
  {
    Button b;
    b.label = label;
    b.action = action;
    return b;
  }
  // the one Return presses
  inline Button byDefault(Button b)
  {
    b.isDefault = true;
    return b;
  }
  inline Button enabledWhen(std::function<bool()> when, Button b)
  {
    b.enabled = when;
    return b;
  }
  inline Button enabledWhen(const bool &flag, Button b)
  {
    b.enabled = [&flag]() { return flag; };
    return b;
  }
  Button enabledWhen(bool &&flag, Button b) = delete;

} // namespace Declare

#endif
