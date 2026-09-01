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

// What the 3D scene needs of whoever is holding it.
//
// Drawing the model with OpenGL and picking in it is not a widget toolkit's
// business, and this directory does none of it; but a scene does have to ask
// for another frame, and it does have to know how big a pixel is. Nine things,
// all of them the holder's, so that the same scene can be held by an interface
// that draws it inside a pane of its own -- which is what the Dear ImGui one
// does -- or by a window that holds nothing else, which is what a chrome
// running somewhere else pairs with.
//
// It is the same shape as Ui::Backend::Host, and for the same reason: a piece
// meant to be reused says what it needs rather than reaching for it.

namespace Scene {

  struct Host {
    // another frame is wanted
    std::function<void()> redraw;
    // process the pending events; rateLimited asks to do nothing when a check
    // was made less than one refresh period ago
    std::function<void(bool rateLimited)> check;
    // wait for events and process them; seconds < 0 waits indefinitely
    std::function<void(double seconds, bool force)> wait;
    // draw the view that last had the pointer, and nothing else
    std::function<void()> drawCurrent;
    // how many device pixels one of the interface's own make
    std::function<float()> uiScale;
    // how many views there are, which decides whether one may be closed
    std::function<int()> numViews;
    // say something next to the pointer, over the view: what is being picked,
    // put where the user is already looking
    std::function<void(const std::string &text)> tooltip;
    // The view the pointer was last in, which is the one the rest of Gmsh
    // means by "the current one". Whoever holds the views keeps it, since a
    // click on one of them is what changes it.
    std::function<sceneView *()> current;
    std::function<void(sceneView *view)> setCurrent;
  };

  void setHost(const Host &host);
  const Host &host();

} // namespace Scene

#endif

#endif
