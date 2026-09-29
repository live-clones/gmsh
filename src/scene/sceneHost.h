// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_HOST_H
#define SCENE_HOST_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include <functional>
#include <string>

class sceneView;
class drawContextGlobal;

// what the scene needs of whoever holds it, an interface drawing it in a pane
// or a window holding nothing else; the same shape as Ui::Backend::Host

namespace Scene {

  // the hand is what "this can be clicked" comes out as: every toolkit has one
  enum Cursor { Ordinary = 0, Picking };

  struct Host {
    std::function<void()> redraw;
    // rateLimited: nothing when a check was made less than a refresh period ago
    std::function<void(bool rateLimited)> check;
    // seconds < 0 waits indefinitely
    std::function<void(double seconds, bool force)> wait;
    std::function<void()> drawCurrent;
    std::function<float()> uiScale;
    // decides whether one may be closed
    std::function<int()> numViews;
    // said both ways round every time, so that a holder keeping the cursor it
    // was given needs no rule for taking it off
    std::function<void(Cursor kind)> cursor;
    // the view the pointer was last in: whoever holds the views keeps it
    std::function<sceneView *()> current;
    std::function<void(sceneView *view)> setCurrent;
    // when the holder can draw one view alone
    std::function<void(sceneView *view)> redrawView;
    // on the interface's thread, once that many seconds have gone by
    std::function<void(double seconds, std::function<void()> what)> later;
    // held anywhere: the view, or an option dragged in a dialog, is changing
    std::function<bool()> buttonDown;
    // any value that tells one context from another, for what is kept per
    // context
    std::function<void *()> context;
    std::function<void(sceneView *view)> makeCurrent;
    // for a picture of another size than the view, when the text engine in
    // use cannot draw one: an engine that can, used meanwhile (none: the one
    // in use can)
    std::function<drawContextGlobal *()> printFonts;
    // the height of the screen in its pixels and the scale of the desktop, for
    // the size of the text of the scene (none: GLFW's primary monitor)
    std::function<void(int &height, float &scale)> screen;
  };

  void setHost(const Host &host);
  const Host &host();

  // for a holder whose loop has no timers: given as Host::later, run with
  // fireTimers() at each turn, waited on no longer than nextTimer() says (below
  // zero: nothing pending)
  void later(double seconds, std::function<void()> what);
  void fireTimers();
  double nextTimer();

} // namespace Scene

#endif

#endif
