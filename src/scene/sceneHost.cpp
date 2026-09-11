// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include "sceneHost.h"

namespace Scene {

  namespace {
    Host &_held()
    {
      static Host held;
      return held;
    }
  } // namespace

  void setHost(const Host &host) { _held() = host; }
  const Host &host() { return _held(); }

} // namespace Scene

#endif
