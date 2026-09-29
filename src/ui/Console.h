// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <cstddef>
#include <deque>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "Form.h"

// The console under the scene, as FLTK had it: the lines the messages said,
// and over them a bar -- a regular expression that filters what is shown, a
// button that saves the messages, one that clears them, a switch that keeps
// the last line in view. What it keeps and what it lets through is here; each
// interface draws the bar and the lines.

namespace Ui {

  class Console {
  public:
    struct Line {
      std::string text;
      // Backend::Level: what the interface colours the line with
      int level;
    };

    // --- what the bar says, the same in every interface
    static const char *filterGlyph() { return "search"; }
    static const char *filterTip()
    {
      return "Filter messages using regular expression";
    }
    static const char *saveLabel() { return "Save"; }
    static const char *saveTip() { return "Save messages to file"; }
    static const char *clearLabel() { return "Clear"; }
    static const char *clearTip() { return "Clear messages"; }
    static const char *autoScrollLabel() { return "Autoscroll messages"; }

    // at most `most` lines, the oldest forgotten first; 0 for no end
    explicit Console(std::size_t most = 0);

    // false when the filter does not let it through: the interface has
    // nothing to add to what it shows
    bool add(const std::string &text, int level);
    void clear();

    // case is ignored; an expression that does not parse lets nothing
    // through, as FLTK had it; empty lets everything. False when it is the
    // one there was
    bool setFilter(const std::string &expression);
    const std::string &filter() const { return _filter; }
    bool passes(const std::string &text) const;

    const std::deque<Line> &lines() const { return _lines; }
    // those the filter lets through, in order
    std::vector<const Line *> shown() const;
    // the text of every line, filtered or not: what is saved
    std::vector<std::string> texts() const;

    bool autoScroll() const { return _autoScroll; }
    void setAutoScroll(bool on) { _autoScroll = on; }

    // the bar as fields, for an interface that makes its widgets from them:
    // the filter (after the picture filterGlyph()), Save, Clear, Autoscroll,
    // bound to this console, which must outlive them; `changed` runs once
    // what is shown changed (the filter, the lines cleared, the switch)
    std::vector<Field> bar(const std::function<void()> &save,
                           const std::function<void()> &changed);

  private:
    std::deque<Line> _lines;
    std::size_t _most;
    std::string _filter;
    struct compiled;
    std::shared_ptr<compiled> _compiled;
    bool _autoScroll;
  };

} // namespace Ui

#endif
