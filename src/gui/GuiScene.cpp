// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_GUI)

#include <map>

#include "Gui.h"

// handed on to whichever scene was chosen, answered with nothing when none was


  namespace {

    std::map<std::string, GuiSceneOps> &_offered()
    {
      static std::map<std::string, GuiSceneOps> it;
      return it;
    }

    GuiSceneOps &_ops()
    {
      static GuiSceneOps it;
      return it;
    }

  } // namespace

  void Gui::offerScene(const char *interface, const GuiSceneOps &ops)
  {
    if(interface) _offered()[interface] = ops;
  }

  void Gui::useScene(const std::string &interface)
  {
    // the one of this interface, or the one serving any, or nothing
    auto it = _offered().find(interface);
    if(it == _offered().end()) it = _offered().find("*");
    _ops() = (it != _offered().end()) ? it->second : GuiSceneOps();
  }


#define GUI_SCENE_FORWARD(name, args, call)                                    \
  void Gui::name args                                                          \
  {                                                                            \
    if(_ops().name) _ops().name call;                                          \
  }
  GUI_SCENE_VOID(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD

#define GUI_SCENE_FORWARD(ret, name, args, call, none)                         \
  ret Gui::name args { return _ops().name ? _ops().name call : (none); }
  GUI_SCENE_VALUE(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD

#define GUI_SCENE_FORWARD(type, name)                                          \
  const std::vector<type> &Gui::name()                                         \
  {                                                                            \
    static const std::vector<type> none;                                       \
    return _ops().name ? _ops().name() : none;                                 \
  }
  GUI_SCENE_LIST(GUI_SCENE_FORWARD)
#undef GUI_SCENE_FORWARD


#endif
