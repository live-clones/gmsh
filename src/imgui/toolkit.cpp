// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdarg>
#include <cstdio>
#include <thread>

#include "toolkit.h"

namespace Toolkit {

  namespace {
    std::function<void(int, const std::string &)> _sink;
    std::function<void()> _quit;
    std::thread::id _thread;
    bool _claimed = false;
  } // namespace

  void reportTo(const std::function<void(int, const std::string &)> &sink)
  {
    _sink = sink;
  }

  void quitWith(const std::function<void()> &what) { _quit = what; }

  void report(int level, const char *format, ...)
  {
    if(!_sink) return;
    char text[2048];
    va_list args;
    va_start(args, format);
    vsnprintf(text, sizeof(text), format, args);
    va_end(args);
    _sink(level, text);
  }

  void quit()
  {
    if(_quit) _quit();
  }

  void claimThread()
  {
    _thread = std::this_thread::get_id();
    _claimed = true;
  }

  bool onThread()
  {
    // before anyone has claimed it, everything is on it: there is no interface
    // to be re-entered
    return !_claimed || std::this_thread::get_id() == _thread;
  }

} // namespace Toolkit

#endif
