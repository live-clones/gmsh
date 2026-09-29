// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BROWSER_HTTP_SERVER_H
#define BROWSER_HTTP_SERVER_H

#include "GmshConfig.h"

#include <functional>
#include <string>

// the smallest HTTP server that will do, with no thread: the interface owns the
// loop. The page is told rather than polled, through an event stream it holds
// open; what it does goes up as a plain POST

namespace Browser {

  struct Ask {
    std::string path;
    std::string body;
    // the Origin header: a plain POST of a form goes out to another origin
    // without asking permission, so any page could drive this one
    std::string origin;
  };

  // the port, or 0
  int listen(int wanted);
  void stop();

  // returns as soon as nothing is left to read; answering with "text/event-
  // stream" hands the connection over: written to afterwards with push(), the
  // body sent as the first event
  void serve(const std::function<std::string(const Ask &, std::string &type)>
               &answer);

  // to every page listening; a page that has gone away is dropped
  void push(const char *name, const std::string &data);
  bool listeners();

} // namespace Browser

#endif
