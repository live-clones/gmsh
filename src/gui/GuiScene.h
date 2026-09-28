// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_GUI_SCENE_H
#define GMSH_GUI_SCENE_H

#include <string>
#include <vector>

#include "GmshConfig.h"
#include "GuiSceneOps.h"
#include "SPoint2.h"

// The 3D scene, not part of the toolkit contract of src/ui/Backend.h: every
// one of these speaks Gmsh, and is implemented once per interface. Each
// scene offers itself under the name of its interface, "*" serving any
// interface without one; with none at all, these answer with nothing.

class drawContext;
class PixelBuffer;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// filled in by whichever scene it is; GuiSceneOps.h says what is in it
struct GuiSceneOps {
#define GUI_SCENE_AS_MEMBER(name, args, call) void (*name) args = nullptr;
  GUI_SCENE_VOID(GUI_SCENE_AS_MEMBER)
#undef GUI_SCENE_AS_MEMBER
#define GUI_SCENE_AS_MEMBER(ret, name, args, call, none) ret(*name) args = nullptr;
  GUI_SCENE_VALUE(GUI_SCENE_AS_MEMBER)
#undef GUI_SCENE_AS_MEMBER
#define GUI_SCENE_AS_MEMBER(type, name)                                        \
  const std::vector<type> &(*name)() = nullptr;
  GUI_SCENE_LIST(GUI_SCENE_AS_MEMBER)
#undef GUI_SCENE_AS_MEMBER
};

#endif
