// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef REBUILD_LOOP_H
#define REBUILD_LOOP_H

#include <functional>

// A list of widgets made again (the ONELAB tree, the context window), which
// may be asked for again while it is being made (hiding an edited input runs
// its callback, which may ask for it): run(make) calls make() until nobody
// asked meanwhile, the requests made during a run waiting for its end. make()
// returns false when the object that owns this is gone (the GUI closed), and
// run() then returns without touching it.
class rebuildLoop {
private:
  bool _running = false, _again = false;

public:
  void run(const std::function<bool()> &make)
  {
    if(_running) {
      _again = true;
      return;
    }
    _running = true;
    // not running any more however a run ends (e.g. by an exception), unless
    // the owner is gone
    struct ended {
      rebuildLoop *loop;
      bool alive;
      ~ended()
      {
        if(alive) loop->_running = false;
      }
    } done{this, true};
    do {
      _running = true; // (again, if made() was called)
      _again = false;
      if(!make()) {
        done.alive = false;
        return;
      }
    } while(_again);
  }
  // the list is made: a request from now on (by events processed before
  // make() returns) is run at once
  void made() { _running = false; }
};

#endif
