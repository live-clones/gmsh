// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The surface reclassification panel, the counterpart of classificationEditor.
// What it runs lives in GuiActions.cpp and is shared with the FLTK interface;
// the parameters that Gmsh exposes as options are read and written through the
// option functions, the few that it does not are kept here.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <string>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "GuiActions.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "drawContext.h"

namespace {

  bool _meshNumber(const char *name, const char *label, float width = 160.f)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "Mesh", 0, name, v, false)) return false;
    ImGui::SetNextItemWidth(width);
    bool changed = ImGui::InputDouble(label, &v, 0., 0., "%g",
                                      ImGuiInputTextFlags_EnterReturnsTrue);
    if(changed) NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, name, v, false);
    return changed;
  }

  bool _meshCheck(const char *name, const char *label)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "Mesh", 0, name, v, false)) return false;
    bool b = (v != 0.);
    if(!ImGui::Checkbox(label, &b)) return false;
    v = b ? 1. : 0.;
    NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, name, v, false);
    return true;
  }

  // a combo over a Mesh option whose values start at 1
  bool _meshCombo(const char *name, const char *label,
                  const char *const *choices)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "Mesh", 0, name, v, false)) return false;
    int n = 0;
    while(choices[n]) n++;
    int index = (int)v - 1;
    ImGui::SetNextItemWidth(220.f);
    bool changed = false;
    if(ImGui::BeginCombo(label,
                         (index >= 0 && index < n) ? choices[index] : "?")) {
      for(int k = 0; k < n; k++)
        if(ImGui::Selectable(choices[k], k == index)) {
          double nv = k + 1;
          NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, name, nv, false);
          changed = true;
        }
      ImGui::EndCombo();
    }
    return changed;
  }

  const char *const _hoAlgorithms[] = {"Optimization", "Elastic analogy",
                                       "Fast curving",
                                       "Boundary layer curving (experimental)",
                                       nullptr};
  const char *const _hoStrategies[] = {"Disjoint strong",
                                       "Adaptive one-by-one", "Disjoint weak",
                                       nullptr};
  const char *const _metisAlgorithms[] = {"Recursive", "K-way", nullptr};
  const char *const _metisMatching[] = {"Random", "Sorted heavy-edge", nullptr};
  const char *const _metisRefinement[] = {"FM-based cut", "Greedy",
                                          "Two-sided node FM",
                                          "One-sided node FM", nullptr};

} // namespace

// ------------------------------------------------------------ high order


// -------------------------------------------------------- reclassification

void appWindow::_drawClassifyPanel()
{
  if(!_showClassify) return;

  ImGui::SetNextWindowSize(ImVec2(460, 300), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Reclassify the surfaces", &_showClassify)) {
    ImGui::End();
    return;
  }

  static double angle = 40.;
  static bool ensureParametrizable = false;

  ImGui::TextWrapped("Split the discrete surfaces along the edges whose "
                     "dihedral angle exceeds the threshold, so that a curved "
                     "geometry can be built on top of a triangulation.");
  ImGui::Spacing();
  ImGui::SetNextItemWidth(160.f);
  ImGui::InputDouble("Angle threshold (degrees)", &angle, 0., 0., "%g");
  ImGui::Checkbox("Make the surfaces parametrizable", &ensureParametrizable);
  if(ImGui::BeginItemTooltip()) {
    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 30.f);
    ImGui::TextUnformatted("Cut the surfaces further so that each of them can "
                           "be parametrized, and build the geometry of the "
                           "discrete entities");
    ImGui::PopTextWrapPos();
    ImGui::EndTooltip();
  }

  ImGui::Separator();
  if(ImGui::Button("Reclassify")) {
    double a = angle;
    bool p = ensureParametrizable;
    postAction([a, p]() { meshClassifySurfaces(a, p); });
  }
  ImGui::SameLine();
  if(ImGui::Button("Show only the lines")) {
    postAction([]() {
      double one = 1., zero = 0.;
      NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, "Lines", one, false);
      NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, "SurfaceFaces", zero, false);
      NumberOption(GMSH_SET | GMSH_GUI, "Mesh", 0, "SurfaceEdges", zero, false);
      drawContext::global()->draw();
    });
  }

  ImGui::End();
}

#endif
