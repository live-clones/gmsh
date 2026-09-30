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
// button that saves the messages, one that clears them, one that copies what
// is shown, a switch that keeps the last line in view. What it keeps and what it lets through is here; each
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
    static const char *copyLabel() { return "Copy"; }
    static const char *copyTip()
    {
      return "Copy the messages shown to the clipboard";
    }
    static const char *autoScrollLabel() { return "Autoscroll messages"; }

    // at most `most` lines, the oldest forgotten first; 0 for no end
    explicit Console(std::size_t most = 50000);

    // false when the filter does not let it through: the interface has
    // nothing to add to what it shows
    bool add(const std::string &text, int level);
    void clear();

    // case is ignored; empty, or an expression that does not parse, lets
    // everything through -- the field says the second, see filterValid().
    // False when it is the one there was
    bool setFilter(const std::string &expression);
    const std::string &filter() const { return _filter; }
    // false while the expression does not parse: the field is drawn red
    bool filterValid() const;
    bool passes(const std::string &text) const;

    const std::deque<Line> &lines() const { return _lines; }
    // those the filter lets through, in order
    std::vector<const Line *> shown() const;
    std::size_t shownCount() const { return _shown.size(); }
    const Line &shownAt(std::size_t k) const;
    // changes whenever the lines shown are not those before and the new
    // ones after them: cleared, filtered again, the oldest shown forgotten
    unsigned generation() const { return _generation; }
    // the text of every line, filtered or not: what is saved
    std::vector<std::string> texts() const;
    // the lines shown, one after the other: what Copy puts on the clipboard
    std::string shownText() const;

    bool autoScroll() const { return _autoScroll; }
    void setAutoScroll(bool on) { _autoScroll = on; }

    // the bar as fields, for an interface that makes its widgets from them:
    // the filter (after the picture filterGlyph(), alert when it does not
    // parse), Save, Clear, Copy, Autoscroll, bound to this console, which
    // must outlive them; `changed` runs once what is shown changed (the
    // filter, the lines cleared, the switch); `copy` puts text on the
    // clipboard
    std::vector<Field> bar(const std::function<void()> &save,
                           const std::function<void(const std::string &)> &copy,
                           const std::function<void()> &changed);

  private:
    std::deque<Line> _lines;
    std::size_t _most;
    // the lines shown, by the number of each since the start: those of the
    // lines forgotten go before _dropped
    std::deque<std::size_t> _shown;
    std::size_t _dropped;
    unsigned _generation;
    void _reshow();
    std::string _filter;
    struct compiled;
    std::shared_ptr<compiled> _compiled;
    bool _autoScroll;
  };

} // namespace Ui

#endif
