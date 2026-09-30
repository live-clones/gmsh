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

  Console::Console(std::size_t most)
    : _most(most), _dropped(0), _generation(0), _autoScroll(true)
  {
  }

  bool Console::add(const std::string &text, int level)
  {
    _lines.push_back(Line{text, level});
    bool through = passes(text);
    if(through) _shown.push_back(_dropped + _lines.size() - 1);
    if(_most)
      while(_lines.size() > _most) {
        // what is shown moves up when the oldest shown goes
        if(_shown.size() && _shown.front() == _dropped) {
          _shown.pop_front();
          _generation++;
        }
        _lines.pop_front();
        _dropped++;
      }
    return through;
  }

  void Console::clear()
  {
    _dropped += _lines.size();
    _lines.clear();
    _shown.clear();
    _generation++;
  }

  void Console::_reshow()
  {
    _shown.clear();
    for(std::size_t i = 0; i < _lines.size(); i++)
      if(passes(_lines[i].text)) _shown.push_back(_dropped + i);
    _generation++;
  }

  bool Console::setFilter(const std::string &expression)
  {
    if(expression == _filter) return false;
    _filter = expression;
    _compiled.reset();
    if(_filter.empty()) {
      _reshow();
      return true;
    }
    _compiled = std::make_shared<compiled>();
    try {
      _compiled->expression = std::regex(_filter, std::regex_constants::icase);
      _compiled->valid = true;
    } catch(...) {
      _compiled->valid = false;
    }
    _reshow();
    return true;
  }

  bool Console::filterValid() const { return !_compiled || _compiled->valid; }

  bool Console::passes(const std::string &text) const
  {
    if(!_compiled || !_compiled->valid) return true;
    try {
      return std::regex_search(text, _compiled->expression);
    } catch(...) {
      return false;
    }
  }

  std::vector<const Console::Line *> Console::shown() const
  {
    std::vector<const Line *> out;
    for(std::size_t k : _shown) out.push_back(&_lines[k - _dropped]);
    return out;
  }

  const Console::Line &Console::shownAt(std::size_t k) const
  {
    return _lines[_shown[k] - _dropped];
  }

  std::vector<std::string> Console::texts() const
  {
    std::vector<std::string> out;
    for(const Line &l : _lines) out.push_back(l.text);
    return out;
  }

  std::string Console::shownText() const
  {
    std::string out;
    for(std::size_t k : _shown) out += _lines[k - _dropped].text + "\n";
    return out;
  }

  std::vector<Field> Console::bar(
    const std::function<void()> &save,
    const std::function<void(const std::string &)> &copy,
    const std::function<void()> &changed)
  {
    std::vector<Field> row(5);
    Field &filter = row[0];
    filter.kind = Text;
    filter.tooltip = filterTip();
    filter.readText = [this]() { return _filter; };
    filter.writeText = [this](const std::string &t) { setFilter(t); };
    filter.changed = changed;
    filter.widthEm = 15.;
    filter.alert = !filterValid();
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
    Field &copying = row[3];
    copying.kind = Action;
    copying.label = copyLabel();
    copying.tooltip = copyTip();
    copying.changed = [this, copy]() {
      if(copy) copy(shownText());
    };
    Field &follow = row[4];
    follow.kind = Check;
    follow.label = autoScrollLabel();
    follow.readNumber = [this]() { return _autoScroll ? 1. : 0.; };
    follow.writeNumber = [this](double v) { _autoScroll = v != 0.; };
    follow.changed = changed;
    return row;
  }

} // namespace Ui
