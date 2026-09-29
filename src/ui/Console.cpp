// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <regex>

#include "Console.h"

namespace Ui {

  struct Console::compiled {
    std::regex expression;
    bool valid;
  };

  Console::Console(std::size_t most) : _most(most), _autoScroll(true) {}

  bool Console::add(const std::string &text, int level)
  {
    _lines.push_back(Line{text, level});
    if(_most)
      while(_lines.size() > _most) _lines.pop_front();
    return passes(text);
  }

  void Console::clear() { _lines.clear(); }

  bool Console::setFilter(const std::string &expression)
  {
    if(expression == _filter) return false;
    _filter = expression;
    _compiled.reset();
    if(_filter.empty()) return true;
    _compiled = std::make_shared<compiled>();
    try {
      _compiled->expression = std::regex(_filter, std::regex_constants::icase);
      _compiled->valid = true;
    } catch(...) {
      _compiled->valid = false;
    }
    return true;
  }

  bool Console::passes(const std::string &text) const
  {
    if(!_compiled) return true;
    if(!_compiled->valid) return false;
    try {
      return std::regex_search(text, _compiled->expression);
    } catch(...) {
      return false;
    }
  }

  std::vector<const Console::Line *> Console::shown() const
  {
    std::vector<const Line *> out;
    for(const Line &l : _lines)
      if(passes(l.text)) out.push_back(&l);
    return out;
  }

  std::vector<std::string> Console::texts() const
  {
    std::vector<std::string> out;
    for(const Line &l : _lines) out.push_back(l.text);
    return out;
  }

  std::vector<Field> Console::bar(const std::function<void()> &save,
                                  const std::function<void()> &changed)
  {
    std::vector<Field> row(4);
    Field &filter = row[0];
    filter.kind = Text;
    filter.tooltip = filterTip();
    filter.readText = [this]() { return _filter; };
    filter.writeText = [this](const std::string &t) { setFilter(t); };
    filter.changed = changed;
    filter.widthEm = 15.;
    Field &keep = row[1];
    keep.kind = Action;
    keep.label = saveLabel();
    keep.tooltip = saveTip();
    keep.changed = save;
    Field &clearing = row[2];
    clearing.kind = Action;
    clearing.label = clearLabel();
    clearing.tooltip = clearTip();
    clearing.changed = [this, changed]() {
      clear();
      if(changed) changed();
    };
    Field &follow = row[3];
    follow.kind = Check;
    follow.label = autoScrollLabel();
    follow.readNumber = [this]() { return _autoScroll ? 1. : 0.; };
    follow.writeNumber = [this](double v) { _autoScroll = v != 0.; };
    follow.changed = changed;
    return row;
  }

} // namespace Ui
