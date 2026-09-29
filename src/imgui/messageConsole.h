// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESSAGE_CONSOLE_H
#define MESSAGE_CONSOLE_H

#include "GmshConfig.h"

#include <deque>
#include <string>
#include <vector>

// the message console, with a regular expression filter

class messageConsole {
private:
  struct line {
    std::string text;
    int level;
    line(const std::string &t, int l) : text(t), level(l) {}
  };
  std::deque<line> _lines;
  std::size_t _maxLines;
  char _filter[256];
  bool _autoScroll;
  bool _scrollToBottom;

public:
  messageConsole();
  void add(const std::string &msg, int level);
  void clear();
  // writing it to a file is the caller's
  void lines(std::vector<std::string> &out) const;
  std::size_t size() const { return _lines.size(); }
  void draw();
};

#endif
