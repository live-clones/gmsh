// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The colour map editor, counterpart of colorbarWindow. The FLTK one draws the
// colour bar by hand with the drawing primitives of the toolkit; here it is
// drawn with an ImDrawList, and the parameters go through the View options, so
// that they are saved and scripted like everything else.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <string>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "drawContext.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "ColorTable.h"
#endif

#if defined(HAVE_POST)

namespace {

  // the predefined colour maps of ColorTable_Recompute(), in order
  const char *const _colormapNames[] = {
    "All black",   "vis5d",        "Jet",         "Lucie",
    "Rainbow",     "emc2000",      "Incandescent", "Hot",
    "Pink",        "Grayscale",    "French flag", "HSV",
    "Spectrum",    "Bone",         "Spring",      "Summer",
    "Autumn",      "Winter",       "Cool",        "Copper",
    "Magma",       "Inferno",      "Plasma",      "Viridis",
    nullptr};

  bool _viewNumber(int view, const char *name, const char *label,
                   float width = 180.f)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "View", view, name, v, false)) return false;
    ImGui::SetNextItemWidth(width);
    bool changed = ImGui::InputDouble(label, &v, 0., 0., "%g",
                                      ImGuiInputTextFlags_EnterReturnsTrue);
    if(changed) NumberOption(GMSH_SET | GMSH_GUI, "View", view, name, v, false);
    return changed;
  }

  bool _viewSlider(int view, const char *name, const char *label, double a,
                   double b)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "View", view, name, v, false)) return false;
    ImGui::SetNextItemWidth(180.f);
    bool changed =
      ImGui::SliderScalar(label, ImGuiDataType_Double, &v, &a, &b, "%.3g");
    if(changed) NumberOption(GMSH_SET | GMSH_GUI, "View", view, name, v, false);
    return changed;
  }

  bool _viewCheck(int view, const char *name, const char *label)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, "View", view, name, v, false)) return false;
    bool b = (v != 0.);
    if(!ImGui::Checkbox(label, &b)) return false;
    v = b ? 1. : 0.;
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, name, v, false);
    return true;
  }

} // namespace

#endif

void appWindow::_drawColormapPanel()
{
  if(!_showColormap) return;

  ImGui::SetNextWindowSize(ImVec2(460, 470), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Colour map", &_showColormap)) {
    ImGui::End();
    return;
  }

#if defined(HAVE_POST)
  int numViews = (int)PView::list.size();
  if(!numViews) {
    ImGui::TextDisabled("No post-processing view loaded");
    ImGui::End();
    return;
  }

  static int view = 0;
  static int selected = -1;
  if(view >= numViews) view = 0;

  ImGui::SetNextItemWidth(240.f);
  char preview[128];
  snprintf(preview, sizeof(preview), "[%d] %s", view,
           PView::list[view]->getData()->getName().c_str());
  if(ImGui::BeginCombo("View", preview)) {
    for(int i = 0; i < numViews; i++) {
      char label[128];
      snprintf(label, sizeof(label), "[%d] %s", i,
               PView::list[i]->getData()->getName().c_str());
      if(ImGui::Selectable(label, view == i)) view = i;
    }
    ImGui::EndCombo();
  }

  GmshColorTable *ct = GetColorTable(view);
  if(!ct) {
    ImGui::TextDisabled("This view has no colour map");
    ImGui::End();
    return;
  }

  bool changed = false;

  // --- the colour bar itself, one quad per entry
  ImGui::SeparatorText("Colour map");
  {
    ImVec2 p = ImGui::GetCursorScreenPos();
    float width = ImGui::GetContentRegionAvail().x;
    float height = 48.f * ImGui::GetStyle().FontScaleDpi;
    if(height < 32.f) height = 32.f;
    ImDrawList *dl = ImGui::GetWindowDrawList();
    int n = ct->size;
    if(n < 2) n = 2;
    float dx = width / (float)n;
    for(int i = 0; i < n; i++) {
      unsigned int c = ct->table[i];
      ImU32 col = IM_COL32(CTX::instance()->unpackRed(c),
                           CTX::instance()->unpackGreen(c),
                           CTX::instance()->unpackBlue(c), 255);
      dl->AddRectFilled(ImVec2(p.x + i * dx, p.y),
                        ImVec2(p.x + (i + 1) * dx + 1.f, p.y + height), col);
    }
    dl->AddRect(p, ImVec2(p.x + width, p.y + height),
                ImGui::GetColorU32(ImGuiCol_Border));
    ImGui::InvisibleButton("##colorbar", ImVec2(width, height));
    if(ImGui::IsItemHovered() || ImGui::IsItemActive()) {
      float x = ImGui::GetIO().MousePos.x - p.x;
      int i = (int)(x / dx);
      if(i < 0) i = 0;
      if(i >= n) i = n - 1;
      if(ImGui::IsItemActive()) selected = i;
      unsigned int c = ct->table[i];
      ImGui::SetTooltip("Index %d / %d\nR %d  G %d  B %d  A %d", i, n - 1,
                        CTX::instance()->unpackRed(c),
                        CTX::instance()->unpackGreen(c),
                        CTX::instance()->unpackBlue(c),
                        CTX::instance()->unpackAlpha(c));
    }
  }

  // --- editing one entry by hand
  if(selected >= 0 && selected < ct->size) {
    unsigned int c = ct->table[selected];
    float col[4] = {CTX::instance()->unpackRed(c) / 255.f,
                    CTX::instance()->unpackGreen(c) / 255.f,
                    CTX::instance()->unpackBlue(c) / 255.f,
                    CTX::instance()->unpackAlpha(c) / 255.f};
    ImGui::SetNextItemWidth(180.f);
    char label[64];
    snprintf(label, sizeof(label), "Colour of index %d", selected);
    if(ImGui::ColorEdit4(label, col, ImGuiColorEditFlags_AlphaPreviewHalf)) {
      ct->table[selected] = CTX::instance()->packColor(
        (int)(col[0] * 255.f + 0.5f), (int)(col[1] * 255.f + 0.5f),
        (int)(col[2] * 255.f + 0.5f), (int)(col[3] * 255.f + 0.5f));
      PView::list[view]->setChanged(true);
      changed = true;
    }
    ImGui::SameLine();
    if(ImGui::SmallButton("Deselect")) selected = -1;
  }
  else {
    ImGui::TextDisabled("Click the bar to pick an entry and edit its colour");
  }

  // --- the parameters, which are all View options
  ImGui::SeparatorText("Predefined");
  {
    double v = 0.;
    NumberOption(GMSH_GET, "View", view, "ColormapNumber", v, false);
    int index = (int)v;
    int n = 0;
    while(_colormapNames[n]) n++;
    const char *name = (index >= 0 && index < n) ? _colormapNames[index] : "?";
    ImGui::SetNextItemWidth(240.f);
    if(ImGui::BeginCombo("Colour map", name)) {
      for(int i = 0; i < n; i++)
        if(ImGui::Selectable(_colormapNames[i], i == index)) {
          double nv = i;
          NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapNumber", nv,
                       false);
          changed = true;
        }
      ImGui::EndCombo();
    }
  }

  ImGui::SeparatorText("Transformation");
  changed |= _viewCheck(view, "ColormapInvert", "Invert");
  ImGui::SameLine();
  changed |= _viewCheck(view, "ColormapSwap", "Swap");
  changed |= _viewSlider(view, "ColormapRotation", "Rotation", -255., 255.);
  changed |= _viewSlider(view, "ColormapCurvature", "Curvature", -5., 5.);
  changed |= _viewSlider(view, "ColormapBias", "Bias", -1., 1.);
  changed |= _viewSlider(view, "ColormapAlpha", "Alpha", 0., 1.);
  changed |= _viewSlider(view, "ColormapAlphaPower", "Alpha power", 0., 2.);
  changed |= _viewNumber(view, "ColormapBeta", "Beta");

  ImGui::Separator();
  if(ImGui::Button("Copy")) {
    ColorTable_Copy(ct);
  }
  ImGui::SameLine();
  if(ImGui::Button("Paste")) {
    ColorTable_Paste(ct);
    PView::list[view]->setChanged(true);
    changed = true;
  }
  ImGui::SameLine();
  if(ImGui::Button("Reset")) {
    double zero = 0., one = 1.;
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapInvert", zero,
                 false);
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapSwap", zero, false);
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapRotation", zero,
                 false);
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapCurvature", zero,
                 false);
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapBias", zero, false);
    NumberOption(GMSH_SET | GMSH_GUI, "View", view, "ColormapAlpha", one, false);
    changed = true;
  }

  if(changed) drawContext::global()->draw();
#else
  ImGui::TextDisabled("Gmsh was compiled without post-processing support");
#endif

  ImGui::End();
}

#endif
