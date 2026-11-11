// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef OPTION_PAGES_H
#define OPTION_PAGES_H

#include <string>
#include <vector>

// The option window as a table: pages (the tabs), their sections, and the
// rows of each section, each row one or several fields bound to an option by
// its name. The interfaces lay the rows out and bind the fields: the FLTK
// interface in optionWindow.cpp, the web page in options.mjs (which shows the
// fields of the options it has, and no custom row).
//
// A row holds one field (a check button across the row, or a field with its
// label to its right) or several: check buttons in columns, or fields sharing
// the width of one by their weights, the label of each to its right; a field
// flagged FieldColumn2 goes to the second column, after the label of the first
// one. What a table cannot say (a matrix of inputs, the colour buttons, a
// button) is a custom row, built by the interface by its name: alone in its
// row it takes the rows it needs, beside other fields it takes its share of
// the width (weight > 0) or places itself (weight 0).
//
// To add an option to the window: a field in a row of its section here,
// nothing else (its choices and range come from DefaultOptions.h, its key from
// the item of its name in Actions.cpp).

enum optionFieldKind {
  FieldCheck, // a check button (an option that is 0 or 1)
  FieldNumber, // a number
  FieldChoice, // one of the values of the option (see OptionChoices)
  FieldText, // a string
  FieldHeading, // a line and a title in the section (option is the title)
  FieldCustom // a row the interface builds itself (option is its name)
};

enum optionFieldFlag {
  FieldOnRelease = 1 << 0, // a number set when the field is left, not typed
  FieldFloat = 1 << 1, // a number shown as set (1e-6), whatever the step
  FieldColumn2 = 1 << 2, // in the second column, after the first label
  FieldColumn2Half = 1 << 3, // in the second column, half its width
  FieldStepper = 1 << 4 // a number with - and + buttons, its label after them
};

struct optionField {
  optionFieldKind kind;
  std::string option; // "Geometry.Points", or the title or name (see above)
  std::string label; // "" for none
  int weight; // its share of the width when several fields share a row
  int flags; // optionFieldFlag bits
};

// a row of fields, and the builders of its fields
typedef std::vector<optionField> optionRow;
optionField check(const std::string &option, const std::string &label,
                  int weight = 1, int flags = 0);
optionField number(const std::string &option, const std::string &label,
                   int weight = 1, int flags = 0);
optionField choice(const std::string &option, const std::string &label,
                   int weight = 1, int flags = 0);
optionField text(const std::string &option, const std::string &label,
                 int weight = 1, int flags = 0);
optionField heading(const std::string &title);
optionField custom(const std::string &name, int weight = 0);
// a share of a row left empty
optionField space(int weight = 1);

struct optionSection {
  std::string name;
  bool open; // the section shown unfolded when its page is first shown
  std::vector<optionRow> rows; // an empty row leaves a row blank
};

struct optionPage {
  std::string name;
  std::vector<optionSection> sections;
};

// The pages: "General", "Geometry", "Mesh", "Solver", "Post-processing" and
// "View" (the options of a view)
const std::vector<optionPage> &OptionPages();
const optionPage *GetOptionPage(const std::string &name);

#endif
