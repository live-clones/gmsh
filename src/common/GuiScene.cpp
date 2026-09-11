// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <map>

#include "GuiScene.h"

// Which 3D scene, and what happens when there is none.
//
// There is one of these per interface, and they are all compiled in: the FLTK
// windows, the Dear ImGui panes, a window of its own for a chrome that draws
// nothing. Which one runs is decided when the interface comes up -- beside
// which chrome -- so what the rest of Gmsh calls cannot be any of them. It is
// this, which hands the call on to whichever was chosen.
//
// And when none was, it answers. That is not a courtesy: it is what lets an
// interface be tried before anyone has written it a scene, which is how the
// page in a browser came to exist at all. Nothing is drawn, nothing is picked,
// and nothing crashes.

namespace Gui {

  namespace {

    // Filled before main() by whichever scenes were built, so it has to exist
    // the first time it is used and not a moment later.
    std::map<std::string, SceneOps> &_offered()
    {
      static std::map<std::string, SceneOps> it;
      return it;
    }

    SceneOps &_ops()
    {
      static SceneOps it;
      return it;
    }

  } // namespace

  void offerScene(const char *chrome, const SceneOps &ops)
  {
    if(chrome) _offered()[chrome] = ops;
  }

  void useScene(const std::string &chrome)
  {
    // the one that belongs to this chrome, or the one that serves any chrome
    // having none of its own, or nothing at all
    auto it = _offered().find(chrome);
    if(it == _offered().end()) it = _offered().find("*");
    _ops() = (it != _offered().end()) ? it->second : SceneOps();
  }

  // and now the functions GuiScene.h promises, each handing on to whatever
  // was chosen, each answering for itself when nothing was

#define GUI_SCENE_FORWARD(name, args, call)                                    \
  void name args                                                               \
  {                                                                            \
    if(_ops().name) _ops().name call;                                          \
  }
  GUI_SCENE_VOID(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD

#define GUI_SCENE_FORWARD(ret, name, args, call, none)                         \
  ret name args { return _ops().name ? _ops().name call : (none); }
  GUI_SCENE_VALUE(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD

#define GUI_SCENE_FORWARD(type, name)                                          \
  const std::vector<type> &name()                                              \
  {                                                                            \
    static const std::vector<type> none;                                       \
    return _ops().name ? _ops().name() : none;                                 \
  }
  GUI_SCENE_LIST(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD

} // namespace Gui

#endif
