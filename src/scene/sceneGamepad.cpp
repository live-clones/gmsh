// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GL_SCENE)

#include "sceneGamepad.h"
#include "sceneView.h"
#include "Navigator.h"
#include "GamePad.h"
#include "Context.h"
#include "drawContext.h"

namespace Scene {

  namespace {

    // One navigator for the program, made when a pad is there and unmade
    // when it goes, so that it never holds a pad that has been deleted: the
    // option that enables the gamepad makes a new one each time it is turned
    // on.
    Navigator *_nautilus = nullptr;
    GamePad *_padOf = nullptr;

    void _forget()
    {
      delete _nautilus;
      _nautilus = nullptr;
      _padOf = nullptr;
    }

  } // namespace

  double gamepadPeriod()
  {
    GamePad *pad = CTX::instance()->gamepad;
    if(!pad) return 0.;
    return pad->active ? pad->frequency : 3.;
  }

  bool gamepadTurn(sceneView *view)
  {
    GamePad *pad = CTX::instance()->gamepad;
    if(!pad || !pad->active) {
      if(_nautilus) _forget();
      return false;
    }
    if(!view || !view->everDrawn()) return false;
    drawContext *ctx = view->getDrawContext();
    if(!ctx) return false;

    pad->read_event();

    if(_nautilus && _padOf != pad) _forget();
    if(!_nautilus) {
      _nautilus = new Navigator(pad->frequency, ctx);
      _padOf = pad;
    }
    else if(_nautilus->ctx != ctx)
      _nautilus->setDrawContext(ctx);

    if(!ctx->camera.on) ctx->camera.init();
    _nautilus->move();
    return true;
  }

} // namespace Scene

#endif
