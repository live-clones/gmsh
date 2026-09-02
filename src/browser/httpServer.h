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
// No thread: the chrome owns the loop, so the socket is looked at from it and
// nothing is ever touched from two places at once.
//
// The page is told rather than asked to ask. It opens one connection that is
// never answered and never closed -- an event stream, which is what a browser
// gives you for nothing through EventSource -- and Gmsh writes a line into it
// whenever there is something new. Everything the page does still goes up as
// a plain POST, so nothing here has to decode frames the way a WebSocket
// would.

namespace Browser {

  // what a request asks: the path, the body of a POST, and the page it came
  // from if it said so
  struct Ask {
    std::string path;
    std::string body;
    // The Origin header, empty when there is none. A page in a browser sends
    // it whenever it asks something of another origin than its own, and a
    // plain POST of a form goes out without asking permission first: without
    // looking at this, any page anyone visits could drive this one.
    std::string origin;
  };

  // Start listening. Returns the port, or 0 if it could not.
  int listen(int wanted);
  void stop();

  // Answer whatever has arrived, and nothing more: it returns as soon as
  // there is nothing left to read, so the loop it is called from keeps
  // turning. `answer` is given a request, fills in what it is sending, and
  // returns the body.
  //
  // Answering with the type "text/event-stream" hands the connection over
  // instead of closing it: what is written to it afterwards is written with
  // push(), and the body that was returned is sent as the first event.
  void serve(const std::function<std::string(const Ask &, std::string &type)>
               &answer);

  // Say something to every page listening. `name` is which kind of news it is
  // and `data` one line of it; a page that has gone away is dropped.
  void push(const char *name, const std::string &data);
  // whether anyone is listening at all: there is nothing to work out when
  // nobody is
  bool listeners();

} // namespace Browser

#endif

#endif
