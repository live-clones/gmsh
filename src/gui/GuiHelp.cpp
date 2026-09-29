// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the three windows of the Help menu; the shortcuts come from
// GetShortcutsUsage() and GetMouseUsage(), the listing from PrintOptions()

#include "GmshConfig.h"

#include <algorithm>
#include <regex>
#include <set>
#include <string>
#include <vector>

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

using namespace Ui;
using namespace Declare;

namespace {

  // a key and what it does, the second as many lines as it takes
  const double _keysEm = 13.;
  const double _saysEm = 30.;

  Item _row(const std::string &keys, const std::string &what)
  {
    return hbox({label(keys).sized(_keysEm),
                 prose([what]() { return paragraphs(what); }).sized(_saysEm)});
  }

  // what it says before the value
  std::string _key(const std::string &line)
  {
    std::string::size_type is = line.find(" =");
    return (is == std::string::npos) ? line : line.substr(0, is);
  }

} // namespace

Form GuiShortcuts::build()
{
  std::vector<Item> keyboard, mouse, usage;
  for(const auto &row : GetShortcutsUsage())
    keyboard.push_back(_row(row.first, row.second));
  for(const auto &row : GetMouseUsage())
    mouse.push_back(_row(row.first, row.second));
  const char *const notes[] = {
    "For a 2 button mouse, Middle button = Shift+Left button.",
    "For a 1 button mouse, Middle button = Shift+Left button, "
    "Right button = Alt+Left button."};
  for(const char *what : notes) {
    std::string said = what;
    mouse.push_back(
      prose([said]() { return paragraphs(said); }).sized(_keysEm + _saysEm));
  }
  for(const auto &row : GetUsage()) {
    if(row.first.empty()) continue;
    if(row.second.empty()) {
      usage.push_back(rule());
      usage.push_back(heading(row.first));
      continue;
    }
    usage.push_back(_row(row.first, row.second));
  }
  Form f = {"shortcuts", "Keyboard and Mouse Usage",
            vbox({heading("Keyboard Shortcuts"), vbox(keyboard), rule(),
                  heading("Mouse Actions"), vbox(mouse), rule(),
                  heading("Command Line Switches"), vbox(usage)})
              .scrolls()};
  f.leastRows = 18;
  return f;
}

// PrintOptions() ends every line with a null byte and the kind of the option,
// which says whether the line can be edited
void GuiCurrentOptions::read()
{
  stale = false;
  lines.clear();
  types.clear();

  std::vector<std::string> all;
  PrintOptions(0, GMSH_FULLRC, modifiedOnly ? 1 : 0, withHelp ? 1 : 0, nullptr,
               &all);
#if defined(HAVE_PARSER)
  PrintParserSymbols(withHelp ? 1 : 0, all);
#endif

  // compiled once for all the lines, case-insensitive; an unfinished regular
  // expression is one being typed, and keeps everything
  std::regex pattern;
  bool valid = !filter.empty();
  if(valid) {
    try {
      pattern = std::regex(filter, std::regex_constants::icase);
    } catch(...) {
      valid = false;
    }
  }
  for(auto &line : all) {
    std::string::size_type sep = line.rfind('\0');
    std::string type;
    if(sep != std::string::npos) {
      std::string tail = line.substr(sep + 1);
      if(tail == "number" || tail == "string" || tail == "color") type = tail;
      line = line.substr(0, sep);
    }
    // a line longer than that is a wall of text
    if(line.size() > 256) line.resize(256);
    if(valid && !std::regex_search(line, pattern)) continue;
    lines.push_back(line);
    types.push_back(type);
  }
}

// empty when the line is not an option: a parser symbol, a heading
bool GuiCurrentOptions::optionOf(const std::string &key, std::string &category,
                                 int &index, std::string &name,
                                 std::string &type)
{
  if(key.empty()) return false;
  int line = -1;
  for(std::size_t i = 0; i < lines.size(); i++)
    if(_key(lines[i]) == key) {
      line = (int)i;
      break;
    }
  if(line < 0) return false;
  type = types[line];
  if(type.empty()) return false;
  const std::string &text = lines[line];
  std::string::size_type dot = text.find_first_of('.');
  if(dot == std::string::npos) return false;
  category = text.substr(0, dot);
  std::string::size_type space = text.find_first_of(' ', dot);
  if(space == std::string::npos) return false;
  name = text.substr(dot + 1, space - dot - 1);
  // "General.Color.Background": the last part names it
  if(type == "color") {
    if(name.size() > 6)
      name = name.substr(6);
    else
      return false;
  }
  index = 0;
  std::string::size_type open = category.find('[');
  std::string::size_type close = category.find(']');
  if(open != std::string::npos && close != std::string::npos) {
    index = atoi(category.substr(open + 1, close - open - 1).c_str());
    category = category.substr(0, open);
  }
  return name.size() > 0;
}

Form GuiCurrentOptions::build()
{
  if(stale) read();
  auto wanted = [this]() {
    stale = true;
    reload();
  };

  Field listing =
    chooseFrom(
      [this](std::vector<std::string> &labels, std::vector<int> &values) {
        for(std::size_t i = 0; i < lines.size(); i++) {
          labels.push_back(lines[i]);
          values.push_back((int)i);
        }
      },
      [this](int i) {
        return i >= 0 && i < (int)lines.size() && picked.count(_key(lines[i])) > 0;
      },
      [this](int i, bool on) {
        if(i < 0 || i >= (int)lines.size()) return;
        std::string key = _key(lines[i]);
        if(on) {
          picked.insert(key);
          last = key;
        }
        else
          picked.erase(key);
        rebuild();
      },
      true)
      .fills()
      .sized(40.)
      .asCode()
      .tip("Pick a line to see what its option is worth; Copy takes the "
           "picked lines");

  // bound to the option the picked line names
  std::string category, name, type;
  int index = 0;
  Item worth = label("Pick a line to change what it is worth");
  if(optionOf(last, category, index, name, type)) {
    std::string full = category +
                       (index ? "[" + std::to_string(index) + "]" : "") + "." +
                       (type == "color" ? "Color." : "") + name;
    worth = option(full, full).labeled(full, true).onChanged([wanted]() {
      drawContext::global()->draw();
      wanted();
    });
  }

  auto copy = [this]() {
    std::string all;
    for(const auto &line : lines)
      if(picked.count(_key(line))) all += line + "\n";
    Gui::instance().copyText(all);
  };

  Form f = {
    "currentOptions", "Current Options and Workspace",
    vbox({hbox({check("Only show modified", &modifiedOnly)
                  .tip("Show only values different from defaults")
                  .tight()
                  .onChanged(wanted),
                check("Show help", &withHelp)
                  .tip("Show help strings")
                  .tight()
                  .onChanged(wanted),
                text("", &filter)
                  .labeled("Filter", true)
                  .tip("Filter the list with a regular expression")
                  .onChanged(wanted)}),
          listing, worth,
          hbox({button("Copy", copy), gap(),
                button("Update", wanted).byDefault()})})};
  f.leastRows = 17;
  return f;
}

Form GuiAbout::build()
{
  Field page = prose([]() {
    std::vector<Ui::Line> lines;
    lines.push_back(titled("Gmsh"));
    lines.push_back(middled(said(std::string("version ") + GetGmshVersion())));
    lines.push_back(Ui::Line());
    lines.push_back(middled(said("Copyright (C) 1997-2026")));
    lines.push_back(
      middled(said("Christophe Geuzaine and Jean-Francois Remacle")));
    lines.push_back(Ui::Line());
    {
      Ui::Line l;
      l.centred = true;
      following(l, "Credits", []() { openURL("https://gmsh.info/CREDITS.txt"); });
      l.words.push_back(Ui::Words(" and "));
      following(l, "licensing information",
                []() { openURL("https://gmsh.info/LICENSE.txt"); });
      lines.push_back(l);
    }
    lines.push_back(Ui::Line());
    lines.push_back(middled(said("Please report all issues on")));
    {
      Ui::Line l;
      l.centred = true;
      following(l, "https://gitlab.onelab.info/gmsh/gmsh/issues", []() {
        openURL("https://gitlab.onelab.info/gmsh/gmsh/issues");
      });
      lines.push_back(l);
    }
    lines.push_back(Ui::Line());
    // what `gmsh -info` prints
    for(const auto &line : GetBuildInfo()) {
      std::string::size_type colon = line.find(':');
      if(colon == std::string::npos) continue;
      std::string name = line.substr(0, colon);
      while(name.size() && name[name.size() - 1] == ' ')
        name.resize(name.size() - 1);
      std::string value = line.substr(colon + 1);
      while(value.size() && value[0] == ' ') value = value.substr(1);
      // said above already
      if(name == "Version" || name == "Web site" || name == "Issue tracker")
        continue;
      lines.push_back(item(name, value));
    }
    lines.push_back(Ui::Line());
    {
      Ui::Line l;
      l.centred = true;
      l.words.push_back(Ui::Words("Visit "));
      following(l, "https://gmsh.info", []() { openURL("https://gmsh.info"); });
      l.words.push_back(Ui::Words(" for more information"));
      lines.push_back(l);
    }
    return lines;
  });
  return {"about", "About Gmsh", page.sized(24.).tall(30)};
}
