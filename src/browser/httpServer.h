// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BROWSER_HTTP_SERVER_H
#define BROWSER_HTTP_SERVER_H

#include "GmshConfig.h"

#if defined(HAVE_BROWSER)

#include <functional>
#include <string>

// The smallest HTTP server that will do.
//
// No thread and no WebSocket: the chrome owns the loop, so the socket is
// looked at from it, and the page asks again rather than being told. A poll is
// a poor way to drive an interface and it is deliberate -- what this is for is
// finding out whether the descriptions survive a process boundary, and a
// question and an answer is enough to find that out. Something meant to be
// used rather than tried would push.

namespace Browser {

  // what a request asks: the path, and the body of a POST
  struct Ask {
    std::string path;
    std::string body;
  };

  // Start listening. Returns the port, or 0 if it could not.
  int listen(int wanted);
  void stop();

  // Answer whatever has arrived, and nothing more: it returns as soon as
  // there is nothing left to read, so the loop it is called from keeps
  // turning. `answer` is given a request, fills in what it is sending, and
  // returns the body.
  void serve(const std::function<std::string(const Ask &, std::string &type)>
               &answer);

} // namespace Browser

#endif

#endif
