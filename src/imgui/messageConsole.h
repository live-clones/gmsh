// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESSAGE_CONSOLE_H
#define MESSAGE_CONSOLE_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <deque>
#include <string>

// The message console, i.e. the Dear ImGui counterpart of messageBrowser: the
// lines that Msg::Info(), Msg::Warning() etc. send to the GUI, with a regular
// expression filter and the usual copy/save/clear actions.

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
  void save(const std::string &fileName);
  std::size_t size() const { return _lines.size(); }
  // draw the contents of the console; the caller owns the Dear ImGui window
  void draw();
};

#endif

#endif
