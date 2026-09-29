// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SCENE_GAMEPAD_H
#define SCENE_GAMEPAD_H

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

class sceneView;

// the gamepad flying the camera: a pad is read, and read again; whoever holds
// the scene only says when

namespace Scene {

  // in seconds: the rate of the pad, three seconds while the option is on and
  // no pad is, zero when off
  double gamepadPeriod();

  // true when the view has to be drawn again; nothing before the view has drawn
  // once
  bool gamepadTurn(sceneView *view);

} // namespace Scene

#endif

#endif
