// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_FORM_H
#define UI_FORM_H

#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "Menu.h"

// A form: a set of panes, a pane a list of labelled fields. Field is the
// atom it shares with Tree.h.
//
// The description owns the values: a field says where its value lives, every
// interface binds its widget to that same place, and nothing is read back.
//
// The layout is said here and worked out once, by the solver of Layout.h.
// Thirteen notions say all of it, and the list is closed:
//
//   1. a line; a field that joins the line before it (sameRow)
//   2. a run of fields packed against each other (packed); the spacer that
//      closes one (Spacer)
//   3. a width declared in em (widthEm) or as a share of one field
//      (widthShare)
//   4. two consecutive shares make one split cell, measuring exactly what
//      one field would
//   5. a pane laid out on N equal columns (Pane::columns)
//   6. a label written before the field rather than after (labelBefore)
//   7. a field that takes the height left over (rows == 0, on List,
//      Hierarchy and ColorMap)
//   8. a field drawn over the lines that follow it (Direction)
//   9. a field several rows tall (rows, wraps)
//  10. the column down the side and its width (Form::side, sideEm)
//  11. header, footer, row of buttons, the button of a pane, buttonApart
//  12. the sections of a pane, and panes gathered into families (Pane::group)
//  13. scrolling and a floor (Pane::scrolling, Form::leastRows)
//
// Refused: text that reflows freely (what wraps is worth a fixed number of
// rows), a width in percent of the parent, a pane inside a pane at any depth,
// constraints that travel up and down at once, cascade or inheritance. An
// interface that comes out a few pixels wrong has wrong metrics, not a
// missing notion.

namespace Ui {

  struct Tree; // Tree.h is written in terms of a Field

  // Four bytes rather than a packed number: the packing depends on the
  // endianness of the machine.
  struct Colour {
    unsigned char r, g, b, a;
    Colour(unsigned char red = 0, unsigned char green = 0,
           unsigned char blue = 0, unsigned char alpha = 255)
      : r(red), g(green), b(blue), a(alpha)
    {
    }
  };

  // hue, saturation and value, each from 0 to 255
  void toHsv(const Colour &c, int &h, int &s, int &v);
  Colour fromHsv(int h, int s, int v, unsigned char alpha);

  // The colour map of a post-processing view: the wedge, the four channels
  // drawn over it, the entries one paints on, and the parameters it is
  // computed from. The parameters are named rather than being members, each
  // with its keys and bounds, so that the colour model stays the host's: an
  // interface offers them all without knowing what any of them means.
  struct ColourMap {
    // what it is of, and the range of the values it stands for
    std::function<void(std::string &name, double &least, double &most)> about;
    // the entries, which are its resolution, and what each of them is worth
    std::function<int()> size;
    std::function<Colour(int i)> colour;
    std::function<void(int i, const Colour &c)> setColour;

    // the ready made maps, numbered from zero, and which one it is on
    std::function<int()> numPresets;
    std::function<int()> preset;
    std::function<void(int preset)> choosePreset;

    struct Parameter {
      std::string name;
      // what raises it and what lowers it; a parameter that is on or off has
      // only `up`, which flips it
      Shortcut up, down;
      // Where it stops. most greater than least bounds it; equal leaves it
      // free, as the curvature and the offset are.
      double least, most, step;
      // It runs round rather than stopping, and this is what is added or
      // taken off when it goes past an end -- not necessarily the distance
      // between the two ends.
      bool wraps;
      double period;
      // it is on or off rather than a quantity
      bool toggle;
      Parameter()
        : least(0.), most(0.), step(0.), wraps(false), period(0.),
          toggle(false)
      {
      }
    };
    std::function<std::vector<Parameter>()> parameters;
    std::function<double(const std::string &name)> parameter;
    // and what setting one does, which is to put the entries back in step
    std::function<void(const std::string &name, double value)> setParameter;
    // raise or lower one by its step, inside its bounds or running round
    void adjust(const Parameter &p, bool up) const;

    // the four channels as hue, saturation and value rather than red, green
    // and blue: it changes what is drawn, not only what the map is worth
    std::function<bool()> hsv;
    std::function<void(bool)> setHsv;

    // the whole map, to and from wherever the host keeps one aside
    std::function<void()> copy, paste;

    bool empty() const { return !size; }
  };

  // A word, or a few of them, written as part of a line of prose: whether it
  // is set apart, and what following it does if it is worth following.
  struct Words {
    std::string text;
    bool italic;
    // if it is a word one may follow -- an address, a document
    std::function<void()> follow;
    Words(const std::string &said = std::string(), bool slanted = false)
      : text(said), italic(slanted)
    {
    }
  };

  // One line of prose: what is written on it, and how it is set. It holds no
  // value and names no widget.
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
    // a colour, shown as a swatch one clicks to change, its name beside it
    Color,
    // A direction, given by dragging a point over a disc. It is drawn `rows`
    // lines tall and hangs over what follows it rather than making its own
    // line that tall.
    Direction,
    // the colour map of a view: the wedge, the four channels drawn over it,
    // and the keys and clicks that change them
    ColorMap,
    // a hierarchy one folds and unfolds, each line of which may be picked
    Hierarchy,
    // a button that drops a list of things to do: the list is made when the
    // button is opened, and picking a line runs it
    Menu,
    List, // what has been picked so far, which one may correct
    // a page of written text; nothing on it is a value
    Prose,
    Spacer // nothing at all: it eats what is left of the line, and never less
           // than widthEm, so that it still separates in a window that fits
           // its contents exactly
  };

  // A button: at the bottom of a form, or hung after a field.
  struct Button {
    std::string label;
    // a picture, for the interfaces that have one; the others fall back on
    // the label
    std::string glyph;
    std::string tooltip;
    std::function<void()> action;
    // it drops a menu instead of acting
    std::function<std::vector<MenuItem>()> menu;
    // its state, for the ones that hold one: a level rather than a flag, zero
    // is off
    std::function<int()> on;
    // the one the dialog is there for, drawn as the button Return would press
    bool isDefault = false;
    // set apart from the rest, at the far left: for a button that undoes
    // rather than does
    bool apart = false;
    // false greys it out
    std::function<bool()> enabled;
  };

  struct Field {
    FieldKind kind = Text;
    std::string label;
    std::string tooltip;
    // Where the value lives, as a pair of functions following kind. A field
    // that says in words what it shows while writing a number sets readText
    // and writeNumber; Label sets readText alone.
    std::function<double()> readNumber;
    std::function<void(double)> writeNumber;
    std::function<std::string()> readText;
    std::function<void(const std::string &)> writeText;
    std::function<Colour()> readColour;
    std::function<void(Colour)> writeColour;
    // Direction: the three components, read and written together
    std::function<void(double &x, double &y, double &z)> readVector;
    std::function<void(double x, double y, double z)> writeVector;
    // ColorMap: what it edits. Empty when there is nothing to show.
    ColourMap map;
    // Choice: the fixed list, and what each choice stands for when the field
    // is bound to an integer rather than to its own text
    std::vector<std::string> choices;
    std::vector<int> values;
    // A list that depends on the model instead. It fills the labels, and the
    // values when the field is bound to an integer. On a Text field it offers
    // what one may want to type.
    std::function<void(std::vector<std::string> &labels,
                       std::vector<int> &values)>
      dynamicChoices;
    // List: what it shows, how to name one entry, and what to do to drop one.
    // Without removeItem it is only read.
    const std::vector<int> *list = nullptr;
    std::function<std::string(int index)> itemLabel;
    std::function<void(int index)> removeItem;
    // how many lines a List takes, or zero for as many as there is room for
    int rows = 5;
    // the widths of the columns of a List, in multiples of the font size,
    // when its lines are tab-separated columns; empty for plain lines
    std::vector<double> columnsEm;
    // Hierarchy: the tree it shows, by pointer since a tree is made of fields
    std::shared_ptr<Tree> hierarchy;
    // List: which entries are chosen and how to change that. Without them the
    // list is only read; `multiple` says whether more than one may be chosen.
    std::function<bool(int index)> chosen;
    std::function<void(int index, bool on)> choose;
    bool multiple = false;
    // Prose: the page, worked out as the window shows
    std::function<std::vector<Line>()> prose;
    // called once the value has changed
    std::function<void()> changed;
    // false greys the field out
    std::function<bool()> enabled;
    // false leaves it out altogether rather than greyed
    std::function<bool()> visible;
    // what it does cannot be taken back: drawn the way the interface warns
    bool alert = false;
    // a line that names what is under it, drawn as a heading
    bool heading = false;
    // the text runs on over `rows` lines rather than being cut off
    bool wraps = false;
    // a rule across the pane at the top of this line, the field under it
    bool rule = false;
    // a check that folds a part of the dialog away, drawn as a disclosure
    // toggle
    bool disclosure = false;
    // Integer and Number: what the value may be, and what one step of the
    // arrows is worth. maximum greater than minimum means it is bounded.
    double minimum = 0., maximum = 0., step = 0.;
    // a value one may also drag along a scale; says nothing without bounds
    bool slider = false;
    // the label comes before the field rather than after it
    bool labelBefore = false;
    // on the same line as the field before it
    bool sameRow = false;
    // Take the width the field needs rather than an equal share of the line.
    // Packed fields follow one another; a Spacer between two runs of them
    // pushes the second to the right.
    bool packed = false;
    // how wide the field itself should be, in multiples of the font size
    double widthEm = 0.;
    // The value is taken when the user has finished with the field -- left
    // it, or pressed Return -- rather than at every letter typed: for a value
    // that may run a solver when it changes.
    bool commitsWhenDone = false;
    // little controls after the field, each a button that may drop a menu
    // and may be on
    std::vector<Button> trailing;
    // How wide the field should be as a fraction of one ordinary field, gaps
    // included: two halves take exactly the room one would, so whatever
    // follows them stays in line with the rows above and below.
    double widthShare = 0.;
    // the same, worth zero or nothing on a field bound to nothing
    double getNumber() const;
    void setNumber(double v);
    std::string getText() const;
    void setText(const std::string &v);
    bool getFlag() const;
    void setFlag(bool v);
    Colour getColour() const;
    void setColour(Colour v);
    // the three components of a Direction, as a unit vector
    void getVector(double &x, double &y, double &z) const;
    void setVector(double x, double y, double z);
  };

  struct Pane {
    std::string label;
    // the outer tab this one belongs to, when a dialog has too many panes to
    // show across one row
    std::string group;
    // a rule under the pane
    bool separatorAfter = false;
    // false hides the whole pane, which is how a dialog folds its advanced
    // part away
    std::function<bool()> visible;
    std::vector<Field> fields;
    // panes shown one under another inside this one, each with its label as
    // a heading and its own visible(); the fields above them come first
    std::vector<Pane> sections;
    // the fields of a long pane scroll rather than making the window as tall
    // as they are
    bool scrolling = false;
    // The pane is laid out on that many columns of equal width, the same for
    // every row, so that the columns of two rows line up. Zero shares the
    // line instead.
    int columns = 0;
    // fields on the line of that button, to its left, outside whatever
    // scrolls above them
    std::vector<Field> beside;
    // the button at the bottom of the pane, when it has one
    std::string buttonLabel;
    std::function<void()> button;
    // at the far left of that line rather than at the right: same idea as
    // Button::apart
    bool buttonApart = false;
    // what to do when the user picks this pane, as opposed to the dialog
    // being told to show it
    std::function<void()> chosen;
  };

  struct Form {
    // what the interface keeps its own state of one under, from one run to
    // the next; unique among the forms of the application
    std::string id;
    std::string title;
    // one pane at a time under tabs, or all of them one under another as
    // titled sections
    bool tabbed = true;
    std::vector<Pane> panes;
    // fields shown in a column down the left of the panes, whichever one is
    // selected
    std::vector<Field> side;
    // how wide that column is, in multiples of the font size; zero for the
    // usual width, which is enough for one list of names
    double sideEm = 0.;
    // fields shown above the panes, whichever one is selected, across the
    // whole width
    std::vector<Field> header;
    // fields shown below the panes, whichever one is selected
    std::vector<Field> footer;
    // buttons at the very bottom, for the panels that act rather than only hold
    std::vector<Button> buttons;
    // how often the dialog is to be refreshed on its own, in seconds, for
    // one that watches something; zero for the others
    double refreshEvery = 0.;
    // the buttons share the last line of the footer instead of taking one
    // of their own; only for a footer short enough to leave them the room
    bool buttonsInFooter = false;
    // what to undo when the dialog is closed, for the ones that leave
    // something behind
    std::function<void()> closed;
    // the least a pane is worth, in lines, so that the window sits still
    // whichever pane is showing; zero lets the panes decide
    int leastRows = 0;
  };

} // namespace Ui

#endif
