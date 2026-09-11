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

// The little services the interface needs of whoever is driving it, and which
// have nothing to do with Gmsh: somewhere to say what happened, a way to ask
// to be shut down, and the answer to "am I the thread that draws?".
//
// They exist so that the rest of src/imgui/ has nothing to include from the
// application. What the interface reports is that GLFW would not start, that a
// font is missing, that a window cannot be split -- facts about the toolkit,
// which the application decides what to do with.

namespace Toolkit {

  // how bad it is; the sink decides what to do about it
  enum Level { Debug = 0, Info, Warning, Error };

  // Where what the interface says goes. Set once by whoever brings it up;
  // until then nothing is said, which is what a toolkit with no application
  // behind it should do.
  void reportTo(const std::function<void(int level, const std::string &text)>
                  &sink);
  // and what to do when the interface is asked to quit
  void quitWith(const std::function<void()> &what);

  // say something, printf style
  void report(int level, const char *format, ...);
  // ask to be shut down
  void quit();

  // Remember that this is the thread the interface lives on. Called once, as
  // the interface comes up.
  void claimThread();
  // Is this that thread? The mesher calls into the interface from its worker
  // threads, and neither toolkit is re-entrant; what comes from elsewhere is
  // dropped rather than drawn.
  bool onThread();

} // namespace Toolkit

#endif

#endif
