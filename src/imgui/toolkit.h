// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_TOOLKIT_H
#define IMGUI_TOOLKIT_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <functional>
#include <string>

// what the interface needs of whoever drives it, so that src/imgui includes
// nothing of the application

namespace Toolkit {

  enum Level { Debug = 0, Info, Warning, Error };

  // set once; until then nothing is said
  void reportTo(const std::function<void(int level, const std::string &text)>
                  &sink);
  void quitWith(const std::function<void()> &what);

  void report(int level, const char *format, ...);
  void quit();

  void claimThread();
  // the mesher calls in from its worker threads: what comes from elsewhere is
  // dropped
  bool onThread();

} // namespace Toolkit

#endif

#endif
