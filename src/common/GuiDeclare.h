// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DECLARE_H
#define GMSH_GUI_DECLARE_H

// The little builders the dialog descriptions are written in, so that a
// description reads as description and not as structure filling. They are
// shared by every file that describes dialogs -- GuiDialogs.cpp for the
// dialogs proper, GuiOptions.cpp for the option window -- and are of no use
// anywhere else.

#include <functional>
#include <string>
#include <vector>

#include "GuiDialogs.h"

namespace Dialog {

  inline Field text(const std::string &label, std::string *value,
                    const std::string &tooltip = "")
  {
    Field f;
    f.kind = Text;
    f.label = label;
    f.tooltip = tooltip;
    f.text = value;
    return f;
  }

  inline Field check(const std::string &label, bool *value)
  {
    Field f;
    f.kind = Check;
    f.label = label;
    f.flag = value;
    return f;
  }

  inline Field integer(const std::string &label, int *value)
  {
    Field f;
    f.kind = Integer;
    f.label = label;
    f.integer = value;
    return f;
  }

  inline Field choice(const std::string &label, std::string *value,
                      const std::vector<std::string> &choices)
  {
    Field f;
    f.kind = Choice;
    f.label = label;
    f.text = value;
    f.choices = choices;
    return f;
  }

  // a choice that stands for something other than its own text
  inline Field choice(const std::string &label, int *value,
                      const std::vector<std::string> &choices,
                      const std::vector<int> &values)
  {
    Field f;
    f.kind = Choice;
    f.label = label;
    f.integer = value;
    f.choices = choices;
    f.values = values;
    return f;
  }

  inline Field number(const std::string &label, double *value,
                      const std::string &tooltip = "")
  {
    Field f;
    f.kind = Number;
    f.label = label;
    f.tooltip = tooltip;
    f.number = value;
    return f;
  }

  // a field that edits a Gmsh option rather than a variable of ours
  // The way in to the other half of the accessors: a field that stands for a
  // Gmsh option rather than for a variable of ours.
  inline Field option(FieldKind kind, const std::string &label,
                      const std::string &category, const std::string &name)
  {
    Field f;
    f.kind = kind;
    f.label = label;
    f.storeCategory = category;
    f.storeName = name;
    return f;
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

  // Words that live somewhere the description cannot point at: what the field
  // shows and what changing it does are given as a pair of functions, the way
  // a number can be.
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
    f.kind = Menu;
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

  // A page of written text rather than a row of fields: the lines are worked
  // out as the window shows, so that what a build has is read from the build.
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

  // The same value, draggable along a scale as well as typed: it is what the
  // windows this replaces offer for a number one looks for by eye. It wants
  // bounds, which within() gives.
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

  // The same field, whose value is taken once one has finished typing it
  // rather than at every letter: what it does is worth doing once.
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

  // the same field, taking that fraction of the room one field is given.
  // Two halves fill exactly one, so the label that follows the pair lines up
  // with the labels above and below it
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

  inline Pane pane(const std::string &label, const std::vector<Field> &fields)
  {
    Pane p;
    p.label = label;
    p.fields = fields;
    return p;
  }

} // namespace Dialog

#endif
