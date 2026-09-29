// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(__EMSCRIPTEN__)

#include <cstdlib>
#include <emscripten.h>
#include "httpServer.h"

// The conversation of httpServer.cpp, with Gmsh compiled to WebAssembly and
// running inside the page: what the page asks with fetch() waits in a queue on
// its side (see pageChannel.js), is taken from it here when the interface
// turns, and answered through the promise the page holds; what Gmsh has to say
// goes to the event streams the page has opened. Nothing calls into Gmsh from
// outside: Gmsh comes for the questions, so an answer that makes it wait -- a
// window that must be answered -- is served from inside that wait, as it is
// over HTTP.

EM_JS_DEPS(pageChannel, "$stringToNewUTF8,$UTF8ToString,$setValue");

EM_JS(int, pageTake, (char **path, char **body), {
  const ask = globalThis.gmshPage && globalThis.gmshPage.asks.shift();
  if(!ask) return -1;
  setValue(path, stringToNewUTF8(ask.path), '*');
  setValue(body, stringToNewUTF8(ask.body), '*');
  return ask.id;
});

EM_JS(void, pageGive, (int id, const char *type, const char *data, int size), {
  globalThis.gmshPage.give(id, UTF8ToString(type),
                           HEAPU8.slice(data, data + size));
});

EM_JS(void, pageOpen, (int id), { globalThis.gmshPage.open(id); });

EM_JS(void, pagePush, (const char *name, const char *data), {
  globalThis.gmshPage.push(UTF8ToString(name), UTF8ToString(data));
});

EM_JS(int, pageListeners, (), {
  return globalThis.gmshPage ? globalThis.gmshPage.streams.length : 0;
});

namespace Browser {

  // there is no port: nobody but the page can ask
  int listen(int wanted) { return wanted > 0 ? wanted : 1; }

  void stop() {}

  bool listeners() { return pageListeners() > 0; }

  void push(const char *name, const std::string &data)
  {
    pagePush(name, data.c_str());
  }

  void serve(const std::function<std::string(const Ask &, std::string &type)>
               &answer)
  {
    while(true) {
      char *path = nullptr, *body = nullptr;
      int id = pageTake(&path, &body);
      if(id < 0) return; // nothing waiting
      Ask ask;
      ask.path = path;
      ask.body = body;
      free(path);
      free(body);
      std::string type = "application/json";
      std::string said = answer(ask, type);
      if(type == "text/event-stream") {
        pageOpen(id);
        if(said.size()) push("state", said);
      }
      else
        pageGive(id, type.c_str(), said.data(), (int)said.size());
    }
  }

} // namespace Browser

#endif
