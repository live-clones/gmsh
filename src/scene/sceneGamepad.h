// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_GAMEPAD_H
#define SCENE_GAMEPAD_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

class sceneView;

// The gamepad, flying the camera of a view.
//
// There is no event to wait for: a pad is read, and read again. What it says
// then moves the camera, which is what Navigator does and which speaks Gmsh
// through and through -- hence its place beside the scene rather than in an
// interface. What is left to whoever holds the scene is only *when* to ask: a
// toolkit that sleeps between events asks on a timer, an interface that draws
// a frame at a time asks once per frame.

namespace Scene {

  // How often a holder is to ask, in seconds: the rate the pad reports once
  // one is plugged in, three seconds while the option is on and nothing is,
  // and zero when the option is off -- then there is nothing to ask.
  double gamepadPeriod();

  // One turn: read what the pad says and move the camera of the view by it.
  // Returns true when the view has to be drawn again. Nothing moves before
  // the view has drawn once, since there is no picture to move around until
  // then; and nothing at all happens when no pad is enabled, so that asking
  // every frame costs a test.
  bool gamepadTurn(sceneView *view);

} // namespace Scene

#endif

#endif
