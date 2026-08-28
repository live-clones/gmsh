// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The three windows of the Help menu: what the keyboard and the mouse do, what
// the options are worth right now, and what this build is. They are the
// counterpart of src/fltk/helpWindow.cpp and of src/imgui/helpPanel.cpp, and
// like every other dialog they are described once here and built by both
// interfaces.
//
// Nothing in them is written twice: the shortcuts come from GetShortcutsUsage()
// and GetMouseUsage(), which is also what -help prints, and the listing from
// PrintOptions(), so neither can drift from what Gmsh really does. The Dear
// ImGui panel this replaces had its own copy of the shortcut tables, and it had
// already drifted.

#include "GmshConfig.h"

#include <algorithm>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include "GuiDialogs.h"
#include "GuiDeclare.h"
#include "GuiActions.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "drawContext.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

namespace {

  // How many lines a description is worth when it is set beside its key and
  // allowed to run on: the column it is in is about that many characters wide,
  // and a line that says nothing still takes one.
  int _wrapped(const std::string &text, int columns)
  {
    int rows = ((int)text.size() + columns - 1) / columns;
    return rows > 0 ? rows : 1;
  }

  // How wide the two columns of these tables are, in multiples of the font
  // size, and about how many characters of the second one fit on a line. The
  // second is what says how many lines a description is worth, and it is
  // deliberately mean: a line too many leaves a gap, a line too few writes the
  // next row over this one.
  const double _keysEm = 13.;
  const double _saysEm = 30.;
  const int _columns = 56;

  // one line of a table: what one presses on the left, what it does on the
  // right, running on over as many lines as it needs
  void _row(Dialog::Pane &pane, const std::string &keys,
            const std::string &what)
  {
    Dialog::Field key = Dialog::says([keys]() { return keys; });
    key.packed = true;
    key.widthEm = _keysEm;
    pane.fields.push_back(key);
    Dialog::Field says = Dialog::says([what]() { return what; });
    says.sameRow = true;
    says.wraps = true;
    says.widthEm = _saysEm;
    says.rows = _wrapped(what, _columns);
    pane.fields.push_back(says);
  }

  // --- the listing of the current options

  // What the listing shows and what one has picked in it. It is not rebuilt at
  // every frame: PrintOptions() writes out every option there is, and the Dear
  // ImGui panel draws itself afresh sixty times a second.
  struct listingState {
    std::vector<std::string> lines; // as they are shown
    std::vector<std::string> types; // "number", "string", "color" or nothing
    // What is picked, by the name of the option rather than by the place of
    // its line: changing a value has the listing read again, and the line it
    // was on is not the line it is on now.
    std::set<std::string> picked;
    std::string last; // the option whose value is offered below the listing
    bool modifiedOnly = false;
    bool withHelp = false;
    std::string filter;
    bool stale = true;
  };

  listingState &_listing()
  {
    static listingState state;
    return state;
  }

  void _wanted() { _listing().stale = true; }

  // what names a line: what it says before the value, which is the option
  std::string _key(const std::string &line)
  {
    std::string::size_type is = line.find(" =");
    return (is == std::string::npos) ? line : line.substr(0, is);
  }

  // Read the options again. PrintOptions() ends every line with a null byte
  // and the kind of the option after it, which is what says whether a line can
  // be edited and how.
  void _readOptions()
  {
    listingState &state = _listing();
    state.stale = false;
    state.lines.clear();
    state.types.clear();

    std::vector<std::string> all;
    PrintOptions(0, GMSH_FULLRC, state.modifiedOnly ? 1 : 0,
                 state.withHelp ? 1 : 0, nullptr, &all);
#if defined(HAVE_PARSER)
    PrintParserSymbols(state.withHelp ? 1 : 0, all);
#endif

    std::string filter = state.filter;
    std::transform(filter.begin(), filter.end(), filter.begin(), ::tolower);
    for(auto &line : all) {
      std::string::size_type sep = line.rfind('\0');
      std::string type;
      if(sep != std::string::npos) {
        std::string tail = line.substr(sep + 1);
        if(tail == "number" || tail == "string" || tail == "color")
          type = tail;
        line = line.substr(0, sep);
      }
      // a line longer than that is a wall of text, and the window this
      // replaces cuts it there too
      if(line.size() > 256) line.resize(256);
      if(filter.size()) {
        try {
          if(!std::regex_search(line,
                                std::regex(filter, std::regex_constants::icase)))
            continue;
        } catch(...) {
          // an unfinished regular expression is one being typed: show
          // everything rather than nothing
        }
      }
      state.lines.push_back(line);
      state.types.push_back(type);
    }
  }

  // The option a line of the listing is about: its category, which of them
  // when there are several of a kind, and its name. Empty when the line is not
  // an option at all -- a parser symbol, a heading.
  bool _optionOf(const std::string &key, std::string &category, int &index,
                 std::string &name, std::string &type)
  {
    listingState &state = _listing();
    if(key.empty()) return false;
    int line = -1;
    for(std::size_t i = 0; i < state.lines.size(); i++)
      if(_key(state.lines[i]) == key) {
        line = (int)i;
        break;
      }
    if(line < 0) return false;
    type = state.types[line];
    if(type.empty()) return false;
    const std::string &text = state.lines[line];
    std::string::size_type dot = text.find_first_of('.');
    if(dot == std::string::npos) return false;
    category = text.substr(0, dot);
    std::string::size_type space = text.find_first_of(' ', dot);
    if(space == std::string::npos) return false;
    name = text.substr(dot + 1, space - dot - 1);
    // a colour is written "General.Color.Background", and it is the last part
    // that names it
    if(type == "color") {
      if(name.size() > 6)
        name = name.substr(6);
      else
        return false;
    }
    // and the category carries which one it is: "View[0]"
    index = 0;
    std::string::size_type open = category.find('[');
    std::string::size_type close = category.find(']');
    if(open != std::string::npos && close != std::string::npos) {
      index = atoi(category.substr(open + 1, close - open - 1).c_str());
      category = category.substr(0, open);
    }
    return name.size() > 0;
  }

  // the lines one has picked, as one would paste them
  void _copyPicked()
  {
    std::string all;
    for(const auto &line : _listing().lines)
      if(_listing().picked.count(_key(line))) all += line + "\n";
    Gui::copyText(all);
  }

} // namespace

namespace Dialog {

  Panel shortcuts()
  {
    Panel p;
    p.title = "Keyboard and Mouse Usage";
    // one long page, as the window this replaces is
    p.tabbed = false;
    p.leastRows = 18;

    {
      Pane keyboard;
      keyboard.label = "Keyboard Shortcuts";
      keyboard.scrolling = true;
      for(const auto &row : GetShortcutsUsage())
        _row(keyboard, row.first, row.second);
      keyboard.separatorAfter = true;
      p.panes.push_back(keyboard);
    }

    {
      Pane mouse;
      mouse.label = "Mouse Actions";
      mouse.scrolling = true;
      for(const auto &row : GetMouseUsage())
        _row(mouse, row.first, row.second);
      // what the window this replaces says under that table
      const char *const notes[] = {
        "For a 2 button mouse, Middle button = Shift+Left button.",
        "For a 1 button mouse, Middle button = Shift+Left button, "
        "Right button = Alt+Left button.",
        nullptr};
      for(int i = 0; notes[i]; i++) {
        std::string what = notes[i];
        Field says_ = says([what]() { return what; });
        says_.wraps = true;
        says_.rows = _wrapped(what, _columns + (int)_keysEm * 2);
        mouse.fields.push_back(says_);
      }
      mouse.separatorAfter = true;
      p.panes.push_back(mouse);
    }

    {
      Pane usage;
      usage.label = "Command Line Switches";
      usage.scrolling = true;
      for(const auto &row : GetUsage()) {
        if(row.first.empty()) continue;
        if(row.second.empty()) {
          // a heading of its own, between two groups of switches
          std::string title = row.first;
          Field head = names([title]() { return title; });
          head.rule = true;
          usage.fields.push_back(head);
          continue;
        }
        _row(usage, row.first, row.second);
      }
      p.panes.push_back(usage);
    }

    return p;
  }

  Panel currentOptions()
  {
    Panel p;
    p.title = "Current Options and Workspace";
    p.tabbed = false;
    p.leastRows = 18;

    if(_listing().stale) _readOptions();

    Pane all;
    // what of them is shown, and which of them
    {
      Field diff = check("Only show modified", &_listing().modifiedOnly);
      diff.tooltip = "Show only values different from defaults";
      diff.packed = true;
      diff.changed = _wanted;
      all.fields.push_back(diff);

      Field help = check("Show help", &_listing().withHelp);
      help.tooltip = "Show help strings";
      help.packed = true;
      help.sameRow = true;
      help.changed = _wanted;
      all.fields.push_back(help);

      Field find = text("Filter", &_listing().filter);
      find.tooltip = "Filter the list with a regular expression";
      find.sameRow = true;
      find.labelBefore = true;
      find.changed = _wanted;
      all.fields.push_back(find);
    }

    // the listing itself, filling what is left of the window
    {
      Field listing = chooseFrom(
        [](std::vector<std::string> &labels, std::vector<int> &values) {
          for(std::size_t i = 0; i < _listing().lines.size(); i++) {
            labels.push_back(_listing().lines[i]);
            values.push_back((int)i);
          }
        },
        [](int i) {
          return i >= 0 && i < (int)_listing().lines.size() &&
                 _listing().picked.count(_key(_listing().lines[i])) > 0;
        },
        [](int i, bool on) {
          if(i < 0 || i >= (int)_listing().lines.size()) return;
          std::string key = _key(_listing().lines[i]);
          if(on) {
            _listing().picked.insert(key);
            _listing().last = key;
          }
          else
            _listing().picked.erase(key);
        },
        true);
      listing.rows = 0;
      listing.widthEm = 40.;
      listing.tooltip = "Pick a line to see what its option is worth; "
                        "Copy takes the picked lines";
      all.fields.push_back(listing);
    }
    p.panes.push_back(all);

    // What the picked line is worth, where one can change it. The window this
    // replaces opens a little window of its own on a double click; here the
    // value is simply there, bound to the option the line names, which is the
    // same thing one field earlier.
    {
      std::string category, name, type;
      int index = 0;
      if(_optionOf(_listing().last, category, index, name, type)) {
        Field value;
        value.kind = type == "color"  ? Color :
                     type == "string" ? Text :
                                        Number;
        value.label = category + (index ? "[" + std::to_string(index) + "]" : "") +
                      "." + (type == "color" ? "Color." : "") + name;
        value.labelBefore = true;
        value.optionCategory = category;
        value.optionIndex = index;
        value.optionName = type == "color" ? "Color." + name : name;
        value.changed = []() {
          drawContext::global()->draw();
          _wanted();
        };
        p.footer.push_back(value);
      }
      else {
        p.footer.push_back(says([]() {
          return std::string("Pick a line to change what it is worth");
        }));
      }
    }

    Button copy;
    copy.label = "Copy";
    copy.action = _copyPicked;
    copy.apart = true;
    p.buttons.push_back(copy);

    Button update;
    update.label = "Update";
    update.isDefault = true;
    update.action = _wanted;
    p.buttons.push_back(update);

    return p;
  }

  Panel about()
  {
    Panel p;
    p.title = "About Gmsh";
    p.tabbed = false;
    // as tall as the window this replaces, which is what it takes to say all
    // of this without scrolling
    p.leastRows = 21;

    Pane what;
    what.scrolling = true;

    what.fields.push_back(names([]() { return std::string("Gmsh"); }));
    what.fields.push_back(says([]() {
      return std::string("version ") + GetGmshVersion();
    }));
    what.fields.push_back(says([]() {
      return std::string("Copyright (C) 1997-2026 Christophe Geuzaine and "
                         "Jean-Francois Remacle");
    }));

    {
      Field credits = does("Credits", []() {
        openURL("https://gmsh.info/CREDITS.txt");
      });
      credits.packed = true;
      what.fields.push_back(credits);
      Field licence = does("Licensing information", []() {
        openURL("https://gmsh.info/LICENSE.txt");
      });
      licence.packed = true;
      licence.sameRow = true;
      what.fields.push_back(licence);
      Field issues = does("Issue tracker", []() {
        openURL("https://gitlab.onelab.info/gmsh/gmsh/issues");
      });
      issues.packed = true;
      issues.sameRow = true;
      what.fields.push_back(issues);
    }

    // What this build is: exactly what `gmsh -info` prints, which is where the
    // versions of PETSc, OCC and MED are already worked out. The window this
    // replaces had its own copy of those tests.
    {
      bool first = true;
      for(const auto &line : GetBuildInfo()) {
        std::string::size_type colon = line.find(':');
        if(colon == std::string::npos) continue;
        std::string name = line.substr(0, colon);
        while(name.size() && name[name.size() - 1] == ' ')
          name.resize(name.size() - 1);
        std::string value = line.substr(colon + 1);
        while(value.size() && value[0] == ' ') value = value.substr(1);
        // the version is written over these, and the two addresses are the
        // buttons above
        if(name == "Version" || name == "Web site" || name == "Issue tracker")
          continue;
        // a rule between what Gmsh is and what this build of it is, on a
        // line of its own: over a line of text it would be drawn through it
        if(first) {
          Field rule = says([]() { return std::string(); });
          rule.rule = true;
          what.fields.push_back(rule);
          first = false;
        }
        _row(what, name, value);
      }
    }

    Field visit = does("Visit https://gmsh.info", []() {
      openURL("https://gmsh.info");
    });
    visit.packed = true;
    what.fields.push_back(visit);

    p.panes.push_back(what);
    return p;
  }

} // namespace Dialog
