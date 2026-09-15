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

// The 3D scene: what draws the model, and what one picks in it.
//
// It is not part of the toolkit contract of src/ui/Backend.h: every one
// of these speaks Gmsh -- picking answers with model entities, the capture
// with a pixel buffer -- and it is implemented once per interface.
//
// There is more than one scene, and which one runs is decided when the
// interface comes up, beside which interface: each says it is there under
// the name of the interface it belongs to, and the one offered as "*"
// serves any interface that has no scene of its own. When none is there at
// all, these answer with nothing, so that the scene is never what stops an
// interface from linking.

class drawContext;
class PixelBuffer;
class GVertex;
class GEdge;
class GFace;
class GRegion;
class MElement;
class PView;

// What a scene answers, filled in by whichever one it is. GuiSceneOps.h
// says what is in it; there is nothing to write here but the shape.
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
