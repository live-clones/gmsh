// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// What is left of the tool panels of the Dear ImGui interface. Like the option
// editor they read and write through the option functions rather than keeping
// any state of their own.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "OS.h"
#include "drawContext.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

namespace {

  // a numeric field bound to a General option, with its help as a tooltip
  bool _number(const char *category, const char *name, const char *label,
               float width = 160.f)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, category, 0, name, v, false)) return false;
    ImGui::SetNextItemWidth(width);
    bool changed = ImGui::InputDouble(label, &v, 0., 0., "%g",
                                      ImGuiInputTextFlags_EnterReturnsTrue);
    if(changed) NumberOption(GMSH_SET | GMSH_GUI, category, 0, name, v, false);
    return changed;
  }

  bool _check(const char *category, const char *name, const char *label)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, category, 0, name, v, false)) return false;
    bool b = (v != 0.);
    if(!ImGui::Checkbox(label, &b)) return false;
    v = b ? 1. : 0.;
    NumberOption(GMSH_SET | GMSH_GUI, category, 0, name, v, false);
    return true;
  }

} // namespace

// --------------------------------------------------------------- statistics


// -------------------------------------------------------------- manipulator


// ----------------------------------------------------------------- clipping


#endif
