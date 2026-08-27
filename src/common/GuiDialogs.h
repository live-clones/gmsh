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
    List, // what has been picked so far, which one may correct
    Spacer // nothing at all: it eats what is left of the line, and never less
           // than widthEm, so that it still separates in a window that fits
           // its contents exactly
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
    // how many lines a List takes
    int rows;
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
    // A check that folds a part of the dialog away rather than holding a
    // setting: it is drawn as a disclosure toggle, with an arrow saying which
    // way it goes.
    bool disclosure;
    // Integer and Number: what the value may be, and what one step of the
    // arrows is worth. maximum greater than minimum means it is bounded.
    double minimum, maximum, step;
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
        flag(nullptr), optionIndex(0), list(nullptr), rows(5), multiple(false),
        disclosure(false), minimum(0.),
        maximum(0.), step(0.), sameRow(false), packed(false), widthEm(0.),
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
    // the button at the bottom of the pane, when it has one
    std::string buttonLabel;
    std::function<void()> button;
    // What to do when the user picks this pane, as opposed to the dialog being
    // told to show it. Picking the tab of a tool has to change the tool, the
    // same as picking it in the tree does.
    std::function<void()> chosen;
    Pane() : separatorAfter(false) {}
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
    // fields shown below the panes, whichever one is selected
    std::vector<Field> footer;
    // buttons at the very bottom, for the panels that act rather than only hold
    std::vector<Button> buttons;
    // The buttons share the last line of the footer instead of taking one of
    // their own: "Memory usage: ..." and Update sit on one line in the window
    // the statistics panel replaces. Only for a footer short enough to leave
    // them the room, which the panel that asks for it knows and the builders
    // do not.
    bool buttonsInFooter;
    Panel() : tabbed(true), buttonsInFooter(false) {}
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
  // the six planes that cut what is drawn
  Panel clipping();

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
