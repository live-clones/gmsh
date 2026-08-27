// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The visibility panel, counterpart of visibilityWindow. The list of entities
// and their visibility state come from VisibilityList, which is shared with the
// FLTK interface; this file only presents it.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstring>
#include <string>
#include <vector>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "VisibilityList.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "Context.h"
#include "GModel.h"
#include "drawContext.h"

namespace {

  // split the tab-separated line of VisibilityList into its columns
  void _columns(const std::string &line, std::string col[3])
  {
    std::size_t start = 0;
    for(int i = 0; i < 3; i++) {
      std::size_t sep = line.find('\t', start);
      if(sep == std::string::npos) sep = line.size();
      // the line starts with a tab, so skip the empty first field
      col[i] = line.substr(start, sep - start);
      if(sep >= line.size()) {
        for(int j = i + 1; j < 3; j++) col[j].clear();
        return;
      }
      start = sep + 1;
    }
  }

} // namespace

void appWindow::_drawVisibilityPanel()
{
  if(!_showVisibility) return;

  ImGui::SetNextWindowSize(ImVec2(520, 560), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Visibility", &_showVisibility)) {
    ImGui::End();
    return;
  }

  static int type = 1; // elementary entities
  static char search[256] = "";
  static bool recursive = true;
  static bool allModels = false;
  static bool dirty = true;

  const char *types[] = {"Models", "Elementary entities", "Physical groups",
                         "Mesh partitions"};
  ImGui::SetNextItemWidth(180.f);
  if(ImGui::BeginCombo("##type", types[type])) {
    for(int i = 0; i < 4; i++)
      if(ImGui::Selectable(types[i], type == i)) {
        type = i;
        dirty = true;
      }
    ImGui::EndCombo();
  }
  ImGui::SameLine();
  ImGui::SetNextItemWidth(-1.f);
  if(ImGui::InputTextWithHint("##search", "Filter (regular expression)", search,
                              sizeof(search)))
    dirty = true;

  ImGui::Checkbox("Apply recursively", &recursive);
  ImGui::SameLine();
  ImGui::Checkbox("Apply to all the models", &allModels);
  ImGui::SameLine();
  if(ImGui::Button("Refresh")) dirty = true;

  VisibilityList::VisibilityType vt;
  switch(type) {
  case 0: vt = VisibilityList::Models; break;
  case 2: vt = VisibilityList::PhysicalEntities; break;
  case 3: vt = VisibilityList::MeshPartitions; break;
  default: vt = VisibilityList::ElementaryEntities; break;
  }

  // the model can change under our feet, so rebuild whenever asked
  if(dirty) {
    VisibilityList::instance()->update(vt, search);
    dirty = false;
  }

  int n = VisibilityList::instance()->getNumEntities();
  bool changed = false;

  if(ImGui::Button("Show all")) {
    for(int i = 0; i < n; i++)
      VisibilityList::instance()->setVisibility(i, 1, recursive, allModels);
    changed = true;
  }
  ImGui::SameLine();
  if(ImGui::Button("Hide all")) {
    for(int i = 0; i < n; i++)
      VisibilityList::instance()->setVisibility(i, 0, recursive, allModels);
    changed = true;
  }
  ImGui::SameLine();
  if(ImGui::Button("Invert")) {
    for(int i = 0; i < n; i++)
      VisibilityList::instance()->setVisibility(
        i, VisibilityList::instance()->getVisibility(i) ? 0 : 1, recursive,
        allModels);
    changed = true;
  }

  ImGui::Separator();
  ImGui::Text("%d %s", n, types[type]);

  const ImGuiTableFlags flags =
    ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg |
    ImGuiTableFlags_ScrollY | ImGuiTableFlags_Sortable |
    ImGuiTableFlags_SizingStretchProp;
  if(ImGui::BeginTable("##entities", 4, flags, ImVec2(0.f, -1.f))) {
    ImGui::TableSetupScrollFreeze(0, 1);
    ImGui::TableSetupColumn("Visible", ImGuiTableColumnFlags_NoSort |
                                         ImGuiTableColumnFlags_WidthFixed,
                            60.f);
    ImGui::TableSetupColumn("Type", ImGuiTableColumnFlags_DefaultSort);
    ImGui::TableSetupColumn("Tag");
    ImGui::TableSetupColumn("Name");
    ImGui::TableHeadersRow();

    if(ImGuiTableSortSpecs *specs = ImGui::TableGetSortSpecs()) {
      if(specs->SpecsDirty && specs->SpecsCount > 0) {
        // VisibilityList sorts by type (1), tag (2) or name (3), the sign of
        // the mode giving the direction
        int mode = specs->Specs[0].ColumnIndex; // 1 = type, 2 = tag, 3 = name
        if(mode >= 1 && mode <= 3) {
          bool ascending =
            specs->Specs[0].SortDirection == ImGuiSortDirection_Ascending;
          // setSortMode() toggles the direction when given the same mode twice,
          // so drive it explicitly
          VisibilityList::instance()->setSortMode(ascending ? mode : -mode);
          if(VisibilityList::instance()->getSortMode() !=
             (ascending ? mode : -mode))
            VisibilityList::instance()->setSortMode(ascending ? mode : -mode);
          VisibilityList::instance()->update(vt, search);
          n = VisibilityList::instance()->getNumEntities();
        }
        specs->SpecsDirty = false;
      }
    }

    for(int i = 0; i < n; i++) {
      std::string col[3];
      std::string line = VisibilityList::instance()->getBrowserLine(i);
      // the line starts with a tab: drop it before splitting
      if(!line.empty() && line[0] == '\t') line = line.substr(1);
      _columns(line, col);

      ImGui::TableNextRow();
      ImGui::TableNextColumn();
      ImGui::PushID(i);
      bool visible = VisibilityList::instance()->getVisibility(i) ? true : false;
      if(ImGui::Checkbox("##v", &visible)) {
        VisibilityList::instance()->setVisibility(i, visible ? 1 : 0, recursive,
                                                  allModels);
        changed = true;
      }
      ImGui::PopID();
      for(int c = 0; c < 3; c++) {
        ImGui::TableNextColumn();
        ImGui::TextUnformatted(col[c].c_str());
      }
    }
    ImGui::EndTable();
  }

  if(changed) {
    CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    drawContext::global()->draw();
  }

  ImGui::End();
}

#endif
