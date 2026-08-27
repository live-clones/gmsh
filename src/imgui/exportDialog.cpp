// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The per-format export options, the counterpart of the twenty dialogs of
// fileDialogs.cpp. Only the formats that have options worth setting get one;
// for the others the file is written straight away. As everywhere else, the
// widgets read and write the real Gmsh options, so what the dialog shows is
// what a script would set.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstring>
#include <string>

#include "imgui.h"
#include <GLFW/glfw3.h>

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "Options.h"

namespace {

  enum optionKind { OptCheck, OptNumber, OptCombo };

  struct exportOption {
    optionKind kind;
    const char *category;
    const char *name;
    const char *label;
    const char *const *choices; // OptCombo, indexed by the value
    const double *values; // OptCombo, when the values are not 0, 1, 2, ...
  };

#define XCHECK(cat, name, label) {OptCheck, cat, name, label, nullptr, nullptr}
#define XNUMBER(cat, name, label) {OptNumber, cat, name, label, nullptr, nullptr}
#define XCOMBO(cat, name, label, ch, v) {OptCombo, cat, name, label, ch, v}
#define XEND {OptCheck, nullptr, nullptr, nullptr, nullptr, nullptr}

  const char *const _mshVersions[] = {"Version 2.2 (ASCII or binary)",
                                      "Version 4.1 (ASCII or binary)",
                                      "Version 1 (ASCII, obsolete)", nullptr};
  const double _mshVersionValues[] = {2.2, 4.1, 1.0};

  const char *const _epsQualities[] = {"Raster image",
                                       "Vector, simple sort",
                                       "Vector, accurate sort (BSP)",
                                       "Vector, unsorted", nullptr};

  const exportOption _mshOptions[] = {
    XCOMBO("Mesh", "MshFileVersion", "Version", _mshVersions, _mshVersionValues),
    XCHECK("Mesh", "Binary", "Write in binary"),
    XCHECK("Mesh", "SaveAll", "Save all the elements (ignore the physical groups)"),
    XCHECK("Mesh", "SaveParametric", "Save the parametric coordinates"),
    XCHECK("Mesh", "SaveTopology", "Save the topology of the model"),
    XEND};

  const exportOption _stlOptions[] = {
    XCHECK("Mesh", "Binary", "Write in binary"),
    XCHECK("Mesh", "SaveAll", "Save all the elements (ignore the physical groups)"),
    XCHECK("Mesh", "StlOneSolidPerSurface", "One solid per surface"),
    XCHECK("Mesh", "StlRemoveDuplicateTriangles", "Remove the duplicate triangles"),
    XEND};

  const exportOption _meshOptions[] = {
    XCHECK("Mesh", "SaveAll", "Save all the elements (ignore the physical groups)"),
    XCHECK("Mesh", "SaveGroupsOfNodes", "Save the groups of nodes"),
    XCHECK("Mesh", "SaveGroupsOfElements", "Save the groups of elements"),
    XNUMBER("Mesh", "ScalingFactor", "Scaling applied to the coordinates"),
    XEND};

  const exportOption _bdfOptions[] = {
    XCHECK("Mesh", "SaveAll", "Save all the elements (ignore the physical groups)"),
    XNUMBER("Mesh", "BdfFieldFormat", "Field format (0: free, 1: small, 2: large)"),
    XNUMBER("Mesh", "ScalingFactor", "Scaling applied to the coordinates"),
    XEND};

  const exportOption _cgnsOptions[] = {
    XCHECK("Mesh", "SaveAll", "Save all the elements (ignore the physical groups)"),
    XCHECK("Mesh", "CgnsExportStructured", "Export a structured grid"),
    XCHECK("Mesh", "CgnsExportCPEX0045", "Use the CPEX0045 high order convention"),
    XEND};

  const exportOption _posOptions[] = {
    XCHECK("PostProcessing", "Binary", "Write in binary"),
    XCHECK("PostProcessing", "SaveMesh", "Save the mesh"),
    XCHECK("PostProcessing", "SaveInterpolationMatrices",
           "Save the interpolation matrices"),
    XEND};

  const exportOption _bitmapOptions[] = {
    XNUMBER("Print", "Width", "Width in pixels (-1 for the size of the window)"),
    XNUMBER("Print", "Height", "Height in pixels (-1 for the size of the window)"),
    XCHECK("Print", "Background", "Print the background"),
    XCHECK("Print", "CompositeWindows", "Composite all the graphic windows"),
    XEND};

  const exportOption _jpegOptions[] = {
    XNUMBER("Print", "Width", "Width in pixels (-1 for the size of the window)"),
    XNUMBER("Print", "Height", "Height in pixels (-1 for the size of the window)"),
    XCHECK("Print", "Background", "Print the background"),
    XCHECK("Print", "CompositeWindows", "Composite all the graphic windows"),
    XNUMBER("Print", "JpegQuality", "Quality (1-100)"),
    XEND};

  const exportOption _vectorOptions[] = {
    XCOMBO("Print", "EpsQuality", "Output", _epsQualities, nullptr),
    XCHECK("Print", "Text", "Print the text"),
    XCHECK("Print", "Background", "Print the background"),
    XCHECK("Print", "EpsOcclusionCulling", "Cull the occluded primitives"),
    XCHECK("Print", "EpsBestRoot", "Optimize the BSP tree"),
    XCHECK("Print", "EpsCompress", "Compress the output"),
    XEND};

  const exportOption _texOptions[] = {
    XNUMBER("Print", "TexWidthInMm", "Width of the output (mm)"),
    XCHECK("Print", "TexForceFontSize", "Force the font size"),
    XCHECK("Print", "TexAsEquation", "Print as an equation"),
    XEND};

  const exportOption *_optionsForFormat(int format)
  {
    switch(format) {
    case FORMAT_MSH: return _mshOptions;
    case FORMAT_STL: return _stlOptions;
    case FORMAT_BDF: return _bdfOptions;
    case FORMAT_CGNS: return _cgnsOptions;
    case FORMAT_POS: return _posOptions;
    case FORMAT_JPEG: return _jpegOptions;
    case FORMAT_PNG:
    case FORMAT_GIF:
    case FORMAT_PPM:
    case FORMAT_YUV: return _bitmapOptions;
    case FORMAT_PS:
    case FORMAT_EPS:
    case FORMAT_PDF:
    case FORMAT_SVG: return _vectorOptions;
    case FORMAT_TEX: return _texOptions;
    case FORMAT_UNV:
    case FORMAT_INP:
    case FORMAT_KEY:
    case FORMAT_RAD:
    case FORMAT_DIFF:
    case FORMAT_MED:
    case FORMAT_VTK:
    case FORMAT_SU2:
    case FORMAT_NEU:
    case FORMAT_MESH:
    case FORMAT_P3D:
    case FORMAT_IR3:
    case FORMAT_CELUM:
    case FORMAT_MATLAB:
    case FORMAT_TOCHNOG: return _meshOptions;
    default: return nullptr;
    }
  }

  bool _drawOption(const exportOption &o)
  {
    double v = 0.;
    if(!NumberOption(GMSH_GET, o.category, 0, o.name, v, false)) {
      // not available in this build
      return false;
    }
    bool changed = false;
    ImGui::PushID(o.name);
    if(o.kind == OptCheck) {
      bool b = (v != 0.);
      if(ImGui::Checkbox(o.label, &b)) {
        v = b ? 1. : 0.;
        changed = true;
      }
    }
    else if(o.kind == OptCombo) {
      int n = 0;
      while(o.choices[n]) n++;
      int index = -1;
      for(int k = 0; k < n; k++)
        if(o.values ? (o.values[k] == v) : ((double)k == v)) index = k;
      ImGui::SetNextItemWidth(280.f);
      if(ImGui::BeginCombo(o.label,
                           (index >= 0) ? o.choices[index] : "?")) {
        for(int k = 0; k < n; k++)
          if(ImGui::Selectable(o.choices[k], k == index)) {
            v = o.values ? o.values[k] : (double)k;
            changed = true;
          }
        ImGui::EndCombo();
      }
    }
    else {
      ImGui::SetNextItemWidth(160.f);
      if(ImGui::InputDouble(o.label, &v, 0., 0., "%g",
                            ImGuiInputTextFlags_EnterReturnsTrue))
        changed = true;
    }
    if(changed)
      NumberOption(GMSH_SET | GMSH_GUI, o.category, 0, o.name, v, false);
    ImGui::PopID();
    return changed;
  }

} // namespace

bool appWindow::exportOptionsDialog(int format, const std::string &fileName)
{
  const exportOption *options = _optionsForFormat(format);
  if(!options) return true; // nothing to ask

  if(_inFrame) {
    Msg::Debug("Ignoring export dialog requested from within a frame");
    return true;
  }

  _exportFormat = format;
  _exportFileName = fileName;
  _exportDone = false;
  _exportAccepted = false;
  _exportActive = true;

  _modalDepth++;
  while(!_exportDone && _instance && _window &&
        !glfwWindowShouldClose(_window)) {
    glfwWaitEventsTimeout(0.05);
    frame();
  }
  _modalDepth--;
  _exportActive = false;
  return _exportAccepted;
}

void appWindow::_drawExportDialog()
{
  if(!_exportActive) return;

  const exportOption *options = _optionsForFormat(_exportFormat);
  if(!options) {
    _exportDone = true;
    _exportAccepted = true;
    return;
  }

  const char *id = "##gmshExportOptions";
  if(!ImGui::IsPopupOpen(id)) ImGui::OpenPopup(id);

  ImVec2 centre = ImGui::GetMainViewport()->GetCenter();
  ImGui::SetNextWindowPos(centre, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
  if(ImGui::BeginPopupModal(id, nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
    ImGui::Text("Writing '%s'", _exportFileName.c_str());
    ImGui::Separator();
    for(int i = 0; options[i].name; i++) _drawOption(options[i]);
    ImGui::Separator();
    if(ImGui::Button("Save", ImVec2(90, 0))) {
      _exportAccepted = true;
      _exportDone = true;
    }
    ImGui::SameLine();
    if(ImGui::Button("Cancel", ImVec2(90, 0)) ||
       ImGui::IsKeyPressed(ImGuiKey_Escape)) {
      _exportAccepted = false;
      _exportDone = true;
    }
    if(_exportDone) ImGui::CloseCurrentPopup();
    ImGui::EndPopup();
  }
}

#endif
