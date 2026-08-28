// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_DIALOGS_H
#define GMSH_GUI_DIALOGS_H

#include <functional>
#include <string>
#include <vector>

#include "GmshConfig.h"
#include "ColorTable.h"

// The dialogs of the graphical user interface, declared once and built by both
// interfaces, in the same spirit as the menus of GuiMenus.h. This one describes
// forms rather than menus: a dialog is a set of panes, a pane a list of
// labelled fields.
//
// The important difference with the menus is that the description *owns the
// values*. A field says where its value lives, both interfaces bind their
// widget to that same variable, and nothing has to be read back afterwards --
// which is what the interactive actions of GuiActionsGeo.cpp want, since they
// read their parameters again at every application.

namespace Dialog {

  enum FieldKind {
    Text, // an expression, evaluated by geometryEvaluate() when it is used
    Integer,
    Number, // a plain double, for the ones that are really an option
    Check,
    Choice, // one of a list, kept as the text of the choice
    Label, // not a value at all: a line the dialog says, recomputed as it shows
    Output, // the same, but with a label, for a value one reads and cannot edit
    Action, // not a value either: a button in the flow of the fields
    // A colour, shown as a swatch one clicks to change, its name beside it.
    // The option window this reproduces fills a whole button with the colour
    // and writes the name inside it; the swatch was preferred and is a
    // deliberate departure.
    Color,
    // A direction, given by dragging a point over a disc: the option window
    // has one for the light, and there is no arrangement of ordinary fields
    // that says the same thing. It is drawn `rows` lines tall and hangs over
    // what follows it rather than making its own line that tall, which is
    // where the window this reproduces puts it.
    Direction,
    // The colour map of a view: the wedge, the four channels drawn over it,
    // and the keys and clicks that change them. It is a widget of its own in
    // the window this reproduces, and there is no describing it as fields.
    ColorMap,
    // A hierarchy one folds and unfolds, each line of which may be picked:
    // the visibility panel shows the model that way, entity under entity.
    Tree,
    // A button that drops a list of things to do rather than of things to
    // be: the size-field window offers every kind of field it can make, and
    // every view a field may be drawn on, that way. The list is made when the
    // button is opened, and picking a line runs it.
    Menu,
    List, // what has been picked so far, which one may correct
    Spacer // nothing at all: it eats what is left of the line, and never less
           // than widthEm, so that it still separates in a window that fits
           // its contents exactly
  };

  // One line of a Tree: how deep it is in the hierarchy, what it says, and
  // whether it stands for something one can pick -- the headings of a tree do
  // not, they are only there to gather what is under them.
  struct TreeLine {
    int depth;
    std::string label;
    bool pickable;
    TreeLine(int d = 0, const std::string &l = "", bool p = true)
      : depth(d), label(l), pickable(p)
    {
    }
  };

  struct Field {
    FieldKind kind;
    std::string label;
    std::string tooltip;
    // where the value lives; exactly one of these is set, following kind, and
    // Choice uses text
    std::string *text;
    int *integer;
    double *number;
    bool *flag;
    unsigned int *colour;
    // Or a pair of functions, for what is reached neither by a variable nor by
    // name: a few options of the option window are accessors with a side
    // effect and no entry in the option table.
    std::function<double()> readNumber;
    std::function<void(double)> writeNumber;
    // the same for a value that reads and writes as words: readText below says
    // what it holds, and this is what changing it does
    std::function<void(const std::string &)> writeText;
    // ColorMap: the table it edits, and what it says over it -- the name of
    // the view and the range of its values. Null when there is nothing to
    // show.
    std::function<GmshColorTable *(std::string &name, double &least,
                                   double &most)>
      colourMap;
    // Direction: the three components, read and written together. They are
    // three options here rather than one, and what the field holds is the
    // direction they make.
    std::function<void(double &x, double &y, double &z)> readVector;
    std::function<void(double x, double y, double z)> writeVector;
    // Instead of a variable, the field can edit a Gmsh option, addressed the
    // way the option file does. The interfaces never see the difference: they
    // go through the accessors below.
    std::string optionCategory, optionName;
    int optionIndex;
    // Choice: the fixed list, and what each choice stands for when the field
    // is bound to an integer rather than to its own text
    std::vector<std::string> choices;
    std::vector<int> values;
    // A list that depends on the model instead. It fills the labels, and the
    // values when the field is bound to an integer. On a Text field it offers
    // what one may want to type, as the Fl_Input_Choice of the FLTK dialog
    // does.
    std::function<void(std::vector<std::string> &labels,
                       std::vector<int> &values)>
      dynamicChoices;
    // List: what it shows, how to name one entry, and what to do to drop one.
    // Without removeItem it is only read.
    const std::vector<int> *list;
    std::function<std::string(int index)> itemLabel;
    std::function<void(int index)> removeItem;
    // how many lines a List takes, or zero for as many as there is room for
    int rows;
    // The widths of the columns of a List, in multiples of the font size, when
    // its lines are tab-separated columns rather than plain text: the entities
    // of the visibility panel are a type, a number and a name. Empty for a
    // list of plain lines.
    std::vector<double> columnsEm;
    // Tree: its lines, in the order they are drawn, deepest last. Which of
    // them are picked is asked and set through chosen() and choose(), by the
    // place of the line in that list, as for a List.
    std::function<void(std::vector<TreeLine> &lines)> treeLines;
    // List: which entries are chosen and how to change that. Without them the
    // list is only read; `multiple` says whether more than one may be chosen.
    std::function<bool(int index)> chosen;
    std::function<void(int index, bool on)> choose;
    bool multiple;
    // Label: what the line says. It is also what a field of any other kind
    // shows when it has one, which is how a value that is computed rather than
    // stored gets displayed.
    std::function<std::string()> readText;
    // called once the value has changed, for the fields that drive something
    // else -- a preview, or another field
    std::function<void()> changed;
    // false greys the field out
    std::function<bool()> enabled;
    // false leaves it out altogether: a field that only makes sense sometimes
    // is not there rather than dead, which is what the windows this replaces
    // do with the Redraw button of the option window
    std::function<bool()> visible;
    // The field is to be looked at twice: what it does cannot be taken back.
    // Both interfaces draw such a field the way they warn -- in red, as it
    // happens -- and the description says the weight rather than the colour,
    // which is the interface's to choose.
    bool alert;
    // A line that names what is under it rather than saying something about
    // it: the windows this replaces write the name of the plugin, and of the
    // size field, in bold over their row of tabs.
    bool heading;
    // The line runs on over several lines rather than being cut off: the help
    // of a plugin is a paragraph, not a label. It is worth `rows` lines.
    bool wraps;
    // A rule across the pane at the top of this line, as the window this
    // reproduces draws between two groups of options inside one tab. It is
    // not a line of its own: the text of the field is written under it.
    bool rule;
    // A check that folds a part of the dialog away rather than holding a
    // setting: it is drawn as a disclosure toggle, with an arrow saying which
    // way it goes.
    bool disclosure;
    // Integer and Number: what the value may be, and what one step of the
    // arrows is worth. maximum greater than minimum means it is bounded.
    double minimum, maximum, step;
    // The label comes before the field rather than after it. Every window of
    // Gmsh writes it after, except the one that hides entities by number,
    // where the name of what is being hidden reads better in front of it.
    bool labelBefore;
    // Put this field on the same line as the one before it. That is most of
    // the layout the description carries: the windows it replaces are two or
    // three columns wide in places, and stacking everything in one column
    // loses the grouping they express.
    bool sameRow;
    // Take the width the field needs rather than an equal share of the line.
    // Packed fields follow one another from where they stand; a Spacer between
    // two runs of them is what pushes the second to the right. A row of values
    // with a couple of buttons after them is not four equal columns.
    bool packed;
    // How wide the field itself should be, in multiples of the font size, when
    // its natural width is not what is wanted. Three little numbers side by
    // side are not three of anything else.
    double widthEm;
    // How wide the field should be as a fraction of one ordinary field, gaps
    // included: two halves take exactly the room one would, so whatever
    // follows them stays in line with the rows above and below. An absolute
    // width cannot say that -- a field is ten times the font size in FLTK and
    // whatever the panel works out in Dear ImGui.
    double widthShare;
    Field()
      : kind(Text), text(nullptr), integer(nullptr), number(nullptr),
        flag(nullptr), colour(nullptr), optionIndex(0), list(nullptr),
        rows(5), multiple(false), alert(false), heading(false), wraps(false),
        rule(false), disclosure(false), minimum(0.), maximum(0.), step(0.),
        labelBefore(false), sameRow(false), packed(false), widthEm(0.),
        widthShare(0.)
    {
    }

    // Read and write the value, whatever it is bound to. This is what the two
    // interfaces use, so that neither has to know about the option system.
    double getNumber() const;
    void setNumber(double v);
    std::string getText() const;
    void setText(const std::string &v);
    bool getFlag() const;
    void setFlag(bool v);
    // packed the way Gmsh packs a colour, see CTX::packColor()
    unsigned int getColour() const;
    void setColour(unsigned int v);
    // the three components of a Direction, as a unit vector
    void getVector(double &x, double &y, double &z) const;
    void setVector(double x, double y, double z);
  };

  struct Pane {
    std::string label;
    // The outer tab this one belongs to, when a dialog has too many panes to
    // show across one row. Empty for the dialogs that have few enough, which
    // then keep a single row of tabs.
    std::string group;
    // draw a rule under the pane, as the windows this replaces do between their
    // groups
    bool separatorAfter;
    // false hides the whole pane, which is how a dialog folds its advanced
    // part away
    std::function<bool()> visible;
    std::vector<Field> fields;
    // Panes shown one under another inside this one, each with its label as a
    // heading and its own visible(). A tab of the option window is a column of
    // titled sections, which is the one place where a pane is not flat; the
    // fields above them, if any, come first.
    std::vector<Pane> sections;
    // the fields of a long pane scroll rather than making the window as tall
    // as they are
    bool scrolling;
    // The pane is laid out on that many columns of equal width, the same for
    // every one of its rows: a field starts at the left of its column and
    // takes the width it needs, its label running on as far as it must. It is
    // how the option window is drawn, and the difference with sharing a line
    // is that the columns of two rows line up. Zero shares the line instead.
    int columns;
    // Fields on the line of that button, to its left, outside whatever
    // scrolls above them: the window this reproduces puts "Set as background
    // field" beside Apply, and Record beside Run.
    std::vector<Field> beside;
    // the button at the bottom of the pane, when it has one
    std::string buttonLabel;
    std::function<void()> button;
    // What to do when the user picks this pane, as opposed to the dialog being
    // told to show it. Picking the tab of a tool has to change the tool, the
    // same as picking it in the tree does.
    std::function<void()> chosen;
    Pane() : separatorAfter(false), scrolling(false), columns(0) {}
  };

  struct Button {
    std::string label;
    std::function<void()> action;
    // the one the dialog is there for, drawn as the button Return would press
    bool isDefault;
    // set apart from the rest, at the far left. The buttons of a dialog are
    // gathered at its right; "Defaults", which undoes rather than does, stands
    // away from them in the windows this replaces
    bool apart;
    Button() : isDefault(false), apart(false) {}
  };

  struct Panel {
    std::string title;
    // When the panes are tabbed, one is shown at a time and each may carry a
    // button of its own. When they are not, they follow one another as titled
    // sections, which is how the windows that are one long form are laid out.
    bool tabbed;
    std::vector<Pane> panes;
    // Fields shown in a column down the left of the panes, whichever one is
    // selected. It is where a list that says what the panes act upon goes: the
    // clipping window puts what each plane cuts there.
    std::vector<Field> side;
    // how wide that column is, in multiples of the font size; zero for the
    // usual width, which is enough for one list of names
    double sideEm;
    // Fields shown above the panes, whichever one is selected, and across the
    // whole width: what the panes are about rather than what they hold. The
    // plugin and size-field windows write the name of the plugin, or of the
    // field, over the row of tabs that way.
    std::vector<Field> header;
    // fields shown below the panes, whichever one is selected
    std::vector<Field> footer;
    // buttons at the very bottom, for the panels that act rather than only hold
    std::vector<Button> buttons;
    // How often the dialog is to be built again from the values it shows,
    // in seconds: a dialog that watches something -- the gamepad, whose
    // buttons light up as they are pressed -- rather than only holding
    // settings. Zero for the ones that change only when one changes them.
    double refreshEvery;
    // The buttons share the last line of the footer instead of taking one of
    // their own: "Memory usage: ..." and Update sit on one line in the window
    // the statistics panel replaces. Only for a footer short enough to leave
    // them the room, which the panel that asks for it knows and the builders
    // do not.
    bool buttonsInFooter;
    // The least a pane is worth, in lines: a window whose height follows
    // whichever pane is showing is one that will not sit still, and the
    // option window this reproduces is twelve lines tall whatever category it
    // is on. Zero lets the panes decide.
    int leastRows;
    Panel()
      : tabbed(true), sideEm(0.), refreshEvery(0.), buttonsInFooter(false),
        leastRows(0)
    {
    }
  };

  // which dialog: the numbering Gui::showDialog() uses
  enum {
    Elementary = 0,
    Physical,
    Transform,
    Mesh,
    Partition,
    HighOrder,
    Manipulator,
    Statistics,
    Clipping,
    Options,
    Gamepad,
    Visibility,
    Plugins,
    Fields,
    Classify,
    Shortcuts,
    CurrentOptions,
    About,
    NumDialogs
  };

  // The four context dialogs, the counterparts of src/fltk/contextWindow.cpp.
  Panel elementaryContext();
  Panel physicalContext();
  Panel transformContext();
  Panel meshContext();
  // the mesh partitioner, which is all options
  Panel partition();
  // the high order tools, two sections one under the other
  Panel highOrder();
  // the rotation, translation and scale of the view
  Panel manipulator();
  // what the model is made of, and how good the mesh is
  Panel statistics();
  // every option there is, laid out by hand in GuiOptions.cpp
  Panel options();
  // which category it is showing, so that a menu can open it on the one it is
  // about rather than on whichever was last looked at
  int &optionsCategory();
  // and which post-processing view its View options are editing
  int &optionsView();
  // Show it on a view: the one given, or the one it is already on when that
  // is -1. The categories before the views are not for anyone else to count.
  // `pane` names the tab to open it on -- "Map" for the colour map of a view
  // -- and shows whichever was last looked at when it is empty.
  void showOptionsForView(int view, const std::string &pane = "");
  // the six planes that cut what is drawn
  Panel clipping();
  // what of the model is drawn: the list of entities, by number, by picking,
  // and per graphic window
  Panel visibility();
  // the plugins, what each of them takes, and what it is run on
  Panel plugins();
  // the mesh size fields, what each of them takes, and which is the background
  Panel fields();
  // turning a triangulation into a model: what to detect the edges on, which
  // of them to keep, and the reclassification itself
  Panel classify();
  // show it, with the lines drawn: it is what one is about to work on
  void startClassify();
  // what the keyboard and the mouse do, and what the command line takes
  Panel shortcuts();
  // what every option is worth right now, and what one may change it to
  Panel currentOptions();
  // what this Gmsh is
  Panel about();
  // show that window with a view picked, as the button of a view does
  void showPluginsForView(int view);
  // what the gamepad is doing and what each of its buttons and axes is for
  Panel gamepad();

  // the one of the given index
  Panel panel(int dialog);

  // The pane each dialog shows, shared so that the description and both
  // interfaces agree on it without anyone having to be told.
  int &currentPane(int dialog);
  // the transform dialog offers the mesh extrusion fields only when the action
  // that opened it extrudes
  bool &extrudeMode();
  // the physical dialog names the kind of entity and says whether the group is
  // being added to or removed from
  std::string &physicalType();
  bool &physicalRemove();

  // Show one of them on the given pane. This is what the modules tree calls;
  // the interface only has to raise the window, through Gui::showDialog().
  void show(int dialog, int pane);
  void showTransform(int pane, bool extrude);
  void showPhysical(const std::string &type, bool remove);

} // namespace Dialog

#endif
