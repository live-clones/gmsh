// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_FORM_H
#define UI_FORM_H

#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "Menu.h"

// A form is a tree of boxes, tabs and fields; Field is the atom it shares
// with Tree.h. The description owns the values: a field says where its value
// lives, every interface binds its widget to that place, and nothing is read
// back.
//
// What the tree looks like is defined by its translation into flex and grid,
// the CSS the page writes as it is; the other toolkits get the same from
// Layout.h, a small flex/grid engine. In em; the widgets' own sizes are the
// toolkit's.
//
//   vbox                 flex column
//   hbox                 flex row, gap between the cells; hbox(…, 0.) no gap
//   a field in a line    a cell: flex row [widget][buttons after][name],
//                        flex 0 1 auto -- its content, no wider
//   a box in a line      flex 1 0 auto: what is left of the line; its
//                        content on a line with a gap()
//   unqualified value    the widget is one field wide (10 em), or a share of
//                        one when several values share the line: two are
//                        two halves
//   sized(em)            the widget that wide; share(x) x of one field
//   tight()              flex 0 0 auto: the cell is its content, packed
//                        against its neighbours; on a line with a gap() every
//                        cell is
//   gap()                flex 1 1 2em: eats what is left of the line; down
//                        a column flex 1 1 0, what is left of its height
//   fills(), scrolls()   flex 1 1 0 down the column, overflow scrolls; in a
//                        line, such a cell is a column: flex 0 0 auto, as
//                        wide as its widest line, running the height of the
//                        line, its buttons as wide as it; leastRows is its
//                        least height, in lines of widgets with their room
//   labeled(…, before)   the name before the widget, at the end of its room;
//                        the names of the lines of a box are one column, as
//                        wide as the widest
//   tall(n) on a button  align-self stretch: as tall as the column beside it
//   grid                 grid, repeat(n, max-content), the last cell of a
//                        row running to the end
//   label(…, Centre)     flex 1 1 auto: the width of its line, the text set
//                        in the middle of it (or at the end, Right)
//   rule()               a border between two lines
//   heading()            a line of bold text
//   tabs                 a row of tabs, the panes stacked on one grid cell:
//                        the tallest gives the height
//   visibleWhen          hidden: in the tree, taking no room

namespace Ui {

  struct Tree; // Tree.h is written in terms of a Field

  // four bytes rather than a packed number: the packing depends on the
  // endianness
  struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char red = 0, unsigned char green = 0,
           unsigned char blue = 0, unsigned char alpha = 255)
      : r(red), g(green), b(blue), a(alpha)
    {
    }
  };

  void toHsv(const Colour &c, int &h, int &s, int &v);
  Colour fromHsv(int h, int s, int v, unsigned char alpha);

  // the parameters are named rather than members, so that the colour model
  // stays the host's: an interface offers them all without knowing what any
  // means
  struct ColourMap {
    std::function<void(std::string &name, double &least, double &most)> about;
    std::function<int()> size;
    std::function<Colour(int i)> colour;
    std::function<void(int i, const Colour &c)> setColour;

    std::function<int()> numPresets;
    std::function<int()> preset;
    std::function<void(int preset)> choosePreset;

    struct Parameter {
      std::string name;
      // a parameter that is on or off has only `up`, which flips it
      Shortcut up, down;
      // most greater than least bounds it; equal leaves it free
      double least, most, step;
      // runs round: what is added or taken off past an end, not necessarily the
      // distance between the ends
      bool wraps;
      double period;
      bool toggle;
      Parameter()
        : least(0.), most(0.), step(0.), wraps(false), period(0.),
          toggle(false)
      {
      }
    };
    std::function<std::vector<Parameter>()> parameters;
    std::function<double(const std::string &name)> parameter;
    // setting one puts the entries back in step
    std::function<void(const std::string &name, double value)> setParameter;
    void adjust(const Parameter &p, bool up) const;

    // as hue, saturation and value: changes what is drawn, not what the map is
    // worth
    std::function<bool()> hsv;
    std::function<void(bool)> setHsv;

    std::function<void()> copy, paste;

    bool empty() const { return !size; }
  };

  // a few words of a line of prose
  struct Words {
    std::string text;
    bool italic;
    std::function<void()> follow;
    Words(const std::string &said = std::string(), bool slanted = false)
      : text(said), italic(slanted)
    {
    }
  };

  // a line of prose holds no value and names no widget
  struct Line {
    std::vector<Words> words;
    bool centred; // written in the middle of the column
    bool bullet; // an item of a list, indented under a dot
    bool heading; // the name of what one is reading, larger and bold
    Line() : centred(false), bullet(false), heading(false) {}
  };

  enum FieldKind {
    Text, // an expression, evaluated by geometryEvaluate() when it is used
    Integer,
    Number, // a plain double, for the ones that are really an option
    Check,
    Choice, // one of a list, kept as the text of the choice
    Label, // not a value at all: a line the dialog says, recomputed as it shows
    Output, // the same, but with a label, for a value one reads and cannot edit
    Action, // not a value either: a button in the flow of the fields
    Color,
    // a disc drawn `rows` lines tall, hanging over what follows it
    Direction,
    ColorMap,
    Hierarchy,
    // the list is made when the button is opened
    Menu,
    List, // what has been picked so far, which one may correct
    Prose,
    Spacer // nothing at all: it eats what is left of the line, and never
           // less than widthEm, so that it still separates in a window that
           // fits its contents exactly
  };

  enum Align { Left, Centre, Right };

  struct Button {
    std::string label;
    // the name of a picture of Glyph.h, shown instead of the label
    std::string glyph;
    std::string tooltip;
    std::function<void()> action;
    std::function<std::vector<MenuItem>()> menu;
    // a level rather than a flag: zero is off
    std::function<int()> on;
    std::function<bool()> enabled;
  };

  struct Field {
    FieldKind kind = Text;
    std::string label;
    std::string tooltip;
    // a field that says in words what it shows while writing a number sets
    // readText and writeNumber; Label sets readText alone
    std::function<double()> readNumber;
    std::function<void(double)> writeNumber;
    std::function<std::string()> readText;
    std::function<void(const std::string &)> writeText;
    std::function<Colour()> readColour;
    std::function<void(Colour)> writeColour;
    std::function<void(double &x, double &y, double &z)> readVector;
    std::function<void(double x, double y, double z)> writeVector;
    // the option it edits, whose name the host is told when it changes
    std::string option;
    ColourMap map;
    // what each choice stands for when the field is bound to an integer
    std::vector<std::string> choices;
    std::vector<int> values;
    // a list that depends on the model; on a Text field, what one may want to
    // type
    std::function<void(std::vector<std::string> &labels,
                       std::vector<int> &values)>
      dynamicChoices;
    // without removeItem the list is only read
    const std::vector<int> *list = nullptr;
    std::function<std::string(int index)> itemLabel;
    std::function<void(int index)> removeItem;
    // zero for as many lines as there is room for
    int rows = 5;
    // in em, when the lines are tab-separated columns
    std::vector<double> columnsEm;
    // the lines are code: a face of fixed width, a size smaller
    bool isCode = false;
    // by pointer: a tree is made of fields
    std::shared_ptr<Tree> hierarchy;
    // without these the list is only read
    std::function<bool(int index)> chosen;
    std::function<void(int index, bool on)> choose;
    bool multiple = false;
    std::function<std::vector<Line>()> prose;
    std::function<void()> changed;
    // when set, called instead of changed for the change that ends the
    // choosing of a number -- Enter, the field left, a drag let go -- and on
    // Enter even with the value as it was: what is redone at every step of a
    // drag can be kept for the value chosen
    std::function<void()> done;
    std::function<bool()> enabled;
    // left out rather than greyed
    std::function<bool()> visible;
    // drawn the way the interface warns
    bool alert = false;
    bool isDefault = false;
    bool heading = false;
    Align align = Left;
    // runs on over `rows` lines
    bool wraps = false;
    // drawn as a disclosure toggle
    bool disclosure = false;
    // maximum greater than minimum means bounded
    double minimum = 0., maximum = 0., step = 0.;
    // says nothing without bounds
    bool slider = false;
    bool labelBefore = false;
    // tight(): its content, packed against its neighbours
    bool packed = false;
    // over the lines that follow, which start past it
    bool hangs = false;
    double widthEm = 0.;
    // taken when the user has finished with the field, not at every letter
    bool commitsWhenDone = false;
    // each may drop a menu and may be on
    std::vector<Button> trailing;
    // a fraction of one ordinary field, gaps included: two halves take exactly
    // the room one would
    double widthShare = 0.;
    // --- qualifiers; what they do is defined at the top of the file
    Field &labeled(const std::string &text, bool before = false)
    {
      label = text;
      labelBefore = before;
      return *this;
    }
    Field &tip(const std::string &text)
    {
      tooltip = text;
      return *this;
    }
    Field &onChanged(std::function<void()> what)
    {
      changed = what;
      return *this;
    }
    Field &onDone(std::function<void()> what)
    {
      done = what;
      return *this;
    }
    // so that a lambda is never taken for a flag
    template <class F, class = decltype(std::declval<F>()())>
    Field &enabledWhen(F when)
    {
      enabled = when;
      return *this;
    }
    Field &enabledWhen(const bool &flag)
    {
      enabled = [&flag]() { return flag; };
      return *this;
    }
    Field &enabledWhen(bool &&) = delete;
    template <class F, class = decltype(std::declval<F>()())>
    Field &visibleWhen(F when)
    {
      visible = when;
      return *this;
    }
    Field &visibleWhen(const bool &flag)
    {
      visible = [&flag]() { return flag; };
      return *this;
    }
    Field &visibleWhen(bool &&) = delete;
    Field &within(double lo, double hi, double stepBy = 0.)
    {
      minimum = lo;
      maximum = hi;
      step = stepBy;
      return *this;
    }
    Field &slid()
    {
      slider = true;
      return *this;
    }
    Field &sized(double em)
    {
      widthEm = em;
      return *this;
    }
    Field &share(double part)
    {
      widthShare = part;
      return *this;
    }
    Field &tight()
    {
      packed = true;
      return *this;
    }
    // a label that tall wraps its text; a button that tall stands beside
    // the lines that follow
    Field &tall(int lines)
    {
      rows = lines;
      hangs = kind == Action;
      wraps = kind == Label;
      return *this;
    }
    Field &columns(const std::vector<double> &em)
    {
      columnsEm = em;
      return *this;
    }
    Field &asCode()
    {
      isCode = true;
      return *this;
    }
    Field &fills()
    {
      rows = 0;
      return *this;
    }
    Field &whenDone()
    {
      commitsWhenDone = true;
      return *this;
    }
    Field &warns()
    {
      alert = true;
      return *this;
    }
    Field &offering(std::function<void(std::vector<std::string> &labels,
                                       std::vector<int> &values)>
                      what)
    {
      dynamicChoices = what;
      return *this;
    }
    Field &byDefault()
    {
      isDefault = true;
      return *this;
    }

    double getNumber() const;
    void setNumber(double v);
    std::string getText() const;
    void setText(const std::string &v);
    bool getFlag() const;
    void setFlag(bool v);
    Colour getColour() const;
    void setColour(Colour v);
    void getVector(double &x, double &y, double &z) const;
    void setVector(double x, double y, double z);
  };

  // a box stacks its items down or across; tabs show one at a time; a cell is
  // as wide as the field says, an equal part of the line otherwise
  struct Box;
  struct Tabs;
  struct Item {
    enum Kind { Nothing, AField, ABox, ATabs, ARule, AHeading };
    Kind kind = Nothing;
    Field field;
    std::shared_ptr<Box> box;
    std::shared_ptr<Tabs> tabs;
    std::string text; // Heading
    Item() {}
    Item(const Field &f) : kind(AField), field(f) {}
    Item(const Box &b);
    Item(const Tabs &t);
  };

  struct Box {
    std::vector<Item> items;
    enum Direction { Down, Across };
    Direction direction = Down;
    // across: in em; below zero the ordinary gap, zero none
    double padding = -1.;
    // down: the rows of a table, each column as wide as its widest cell
    bool grid = false;
    std::function<bool()> visible;
    bool scrolling = false;

    template <class F, class = decltype(std::declval<F>()())>
    Box &visibleWhen(F when)
    {
      visible = when;
      return *this;
    }
    Box &visibleWhen(const bool &flag)
    {
      visible = [&flag]() { return flag; };
      return *this;
    }
    Box &visibleWhen(bool &&) = delete;
    Box &scrolls()
    {
      scrolling = true;
      return *this;
    }
  };

  struct Tabs {
    std::vector<std::pair<std::string, Item>> tabs;
    std::function<void(const std::string &)> chosen;
  };

  inline Item::Item(const Box &b) : kind(ABox), box(std::make_shared<Box>(b)) {}
  inline Item::Item(const Tabs &t) : kind(ATabs), tabs(std::make_shared<Tabs>(t))
  {
  }

  struct Form {
    // unique among the forms of the application
    std::string id;
    std::string title;
    Item content;
    // in seconds, for a dialog that watches something
    double refreshEvery = 0.;
    // for the dialogs that leave something behind
    std::function<void()> closed;
    // the least of what fills what is left, in lines: a pane of tabs, a
    // list with no rows, a box that scrolls; so that the window sits still
    // whichever pane is showing
    int leastRows = 0;
  };

  // --- what the interfaces that keep widgets ask of a description

  // whether it is to be shown now: a field or a box whose visibleWhen says
  // so, anything else that is something
  bool shown(const Item &it);
  // what makes the widgets of a form be built again when it changes: the
  // fields, their kinds and buttons, the boxes, tabs, headings and rules.
  // shownOnly: what is hidden is not built at all (the interfaces made of
  // boxes), so that showing it changes the shape; placing interfaces give
  // it no room instead, and keep its widgets
  std::string signature(const Form &form, bool shownOnly = false);
  // the same for a row of buttons, whose labels and states they show
  std::string signature(const std::vector<Button> &buttons);
  // what is folded away now, as a word: a placing interface places the form
  // again only when this changes
  std::string folding(const Form &form);

  // --- the value of a field, as every interface shows and reads it

  // the entries of a choice, a menu or a list, and the values they stand for
  // (none: they are their places, or their texts)
  void choices(const Field &f, std::vector<std::string> &labels,
               std::vector<int> &values);
  // within the bounds, and whole for an Integer
  double bounded(const Field &f, double v);
  // the decimals of a step: 0.25 has 2, 5 has none; at most 10
  int decimals(double step);
  // with the decimals of the step (none, or 0: as "%g"), unless the value is
  // off the grid of the step (1e-6 on a step of 1e-4): then as it is. An
  // interface passes the step of the field when values are dragged
  // (Backend::Settings::inputScrolling), none otherwise
  std::string numberText(double v, double step);
  // what was typed, if it is a number
  bool readNumber(const std::string &said, double &v);
  // a channel of the colour i of a map: 0, 1, 2 red, green, blue, or hue,
  // saturation, value; 3 alpha; all from 0 to 255
  int mapChannel(const ColourMap &map, int i, int channel, bool hsv);
  void setMapChannel(const ColourMap &map, int i, int channel, int value,
                     bool hsv);

} // namespace Ui

#endif
