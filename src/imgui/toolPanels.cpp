// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The plugin and the mesh size field panels, counterparts of pluginWindow and
// fieldWindow. Both describe themselves: a plugin exposes its options through
// GMSH_Plugin::getOption()/getOptionStr(), and a field through its map of
// FieldOption, so these panels are generic and pick up new plugins and new
// field types without any change.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdio>
#include <cstring>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "imgui.h"
#include "imgui_stdlib.h"

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "GModel.h"
#include "drawContext.h"

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#include "Plugin.h"
#endif

#if defined(HAVE_MESH)
#include "Field.h"
#endif

// ------------------------------------------------------------------ plugins

void appWindow::_drawPluginPanel()
{
  if(!_showPlugins) return;

  ImGui::SetNextWindowSize(ImVec2(520, 560), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Plugins", &_showPlugins)) {
    ImGui::End();
    return;
  }

#if defined(HAVE_PLUGINS)
  static char filter[128] = "";
  static std::string current;
  static std::map<std::string, std::string> edits;

  ImGui::SetNextItemWidth(-1.f);
  ImGui::InputTextWithHint("##filter", "Filter the plugins", filter,
                           sizeof(filter));

  float listHeight = ImGui::GetContentRegionAvail().y * 0.35f;
  if(ImGui::BeginChild("##list", ImVec2(0.f, listHeight),
                       ImGuiChildFlags_Borders)) {
    for(auto it = PluginManager::instance()->begin();
        it != PluginManager::instance()->end(); it++) {
      const std::string &name = it->first;
      if(filter[0]) {
        std::string a = name, b = filter;
        for(auto &c : a) c = (char)tolower((unsigned char)c);
        for(auto &c : b) c = (char)tolower((unsigned char)c);
        if(a.find(b) == std::string::npos) continue;
      }
      if(ImGui::Selectable(name.c_str(), current == name)) current = name;
      if(ImGui::IsItemHovered() && it->second) {
        std::string help = it->second->getShortHelp();
        if(help.size()) ImGui::SetTooltip("%s", help.c_str());
      }
    }
  }
  ImGui::EndChild();

  GMSH_Plugin *p = nullptr;
  for(auto it = PluginManager::instance()->begin();
      it != PluginManager::instance()->end(); it++)
    if(it->first == current) p = it->second;

  if(!p) {
    ImGui::TextDisabled("Select a plugin to see its options");
    ImGui::End();
    return;
  }

  ImGui::SeparatorText(current.c_str());
  if(ImGui::TreeNode("Help")) {
    ImGui::PushTextWrapPos(0.f);
    ImGui::TextUnformatted(p->getHelp().c_str());
    ImGui::PopTextWrapPos();
    ImGui::TreePop();
  }

  if(ImGui::BeginChild("##options", ImVec2(0.f, -ImGui::GetFrameHeightWithSpacing()))) {
    for(int i = 0; i < p->getNbOptions(); i++) {
      StringXNumber *o = p->getOption(i);
      if(!o) continue;
      double v = o->def;
      ImGui::PushID(i);
      ImGui::SetNextItemWidth(180.f);
      if(ImGui::InputDouble(o->str, &v, 0., 0., "%g",
                            ImGuiInputTextFlags_EnterReturnsTrue))
        o->def = v;
      if(o->help && ImGui::BeginItemTooltip()) {
        ImGui::TextUnformatted(o->help);
        ImGui::EndTooltip();
      }
      ImGui::PopID();
    }
    for(int i = 0; i < p->getNbOptionsStr(); i++) {
      StringXString *o = p->getOptionStr(i);
      if(!o) continue;
      std::string key = current + "/" + o->str;
      auto it = edits.find(key);
      if(it == edits.end())
        it = edits.insert(std::make_pair(key, o->def)).first;
      ImGui::PushID(1000 + i);
      ImGui::SetNextItemWidth(240.f);
      ImGui::InputText(o->str, &it->second);
      if(ImGui::IsItemDeactivatedAfterEdit()) o->def = it->second;
      if(o->help && ImGui::BeginItemTooltip()) {
        ImGui::TextUnformatted(o->help);
        ImGui::EndTooltip();
      }
      ImGui::PopID();
    }
  }
  ImGui::EndChild();

  if(ImGui::Button("Run")) {
    GMSH_Plugin *plugin = p;
    postAction([plugin]() {
      try {
        plugin->run();
      } catch(...) {
        Msg::Error("Plugin '%s' failed", plugin->getName().c_str());
      }
      Gui::updateViews(true, true);
      drawContext::global()->draw();
    });
  }
#else
  ImGui::TextDisabled("Gmsh was compiled without plugin support");
#endif

  ImGui::End();
}

// ------------------------------------------------------------- size fields

void appWindow::_drawFieldPanel()
{
  if(!_showFields) return;

  ImGui::SetNextWindowSize(ImVec2(540, 560), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("Mesh size fields", &_showFields)) {
    ImGui::End();
    return;
  }

#if defined(HAVE_MESH)
  FieldManager *fields = GModel::current()->getFields();
  static int current = -1;
  static std::map<std::string, std::string> edits;
  bool changed = false;

  // --- create a new field of the chosen type
  static std::string newType;
  ImGui::SetNextItemWidth(200.f);
  if(ImGui::BeginCombo("##type", newType.size() ? newType.c_str() :
                                                  "New field of type...")) {
    for(auto &kv : fields->mapTypeName)
      if(ImGui::Selectable(kv.first.c_str(), newType == kv.first))
        newType = kv.first;
    ImGui::EndCombo();
  }
  ImGui::SameLine();
  ImGui::BeginDisabled(newType.empty());
  if(ImGui::Button("Add")) {
    int id = fields->newId();
    fields->newField(id, newType);
    current = id;
    changed = true;
  }
  ImGui::EndDisabled();

  ImGui::Separator();

  // --- the list of existing fields
  float listHeight = ImGui::GetContentRegionAvail().y * 0.3f;
  if(ImGui::BeginChild("##fields", ImVec2(0.f, listHeight),
                       ImGuiChildFlags_Borders)) {
    for(auto &kv : *fields) {
      Field *f = kv.second;
      if(!f) continue;
      char label[256];
      snprintf(label, sizeof(label), "[%d] %s%s", kv.first, f->getName(),
               (fields->getBackgroundField() == kv.first) ? "  (background)" :
                                                            "");
      if(ImGui::Selectable(label, current == kv.first)) current = kv.first;
    }
  }
  ImGui::EndChild();

  Field *f = (current >= 0) ? fields->get(current) : nullptr;
  if(!f) {
    ImGui::TextDisabled("Select a field to see its options");
    ImGui::End();
    return;
  }

  ImGui::SeparatorText(f->getName());
  if(f->getDescription().size() && ImGui::TreeNode("Help")) {
    ImGui::PushTextWrapPos(0.f);
    ImGui::TextUnformatted(f->getDescription().c_str());
    ImGui::PopTextWrapPos();
    ImGui::TreePop();
  }

  if(ImGui::BeginChild("##fieldoptions",
                       ImVec2(0.f, -ImGui::GetFrameHeightWithSpacing()))) {
    for(auto &kv : f->options) {
      FieldOption *o = kv.second;
      if(!o || o->isDeprecated()) continue;
      ImGui::PushID(kv.first.c_str());
      switch(o->getType()) {
      case FIELD_OPTION_BOOL: {
        bool b = (o->numericalValue() != 0.);
        if(ImGui::Checkbox(kv.first.c_str(), &b)) {
          o->numericalValue(b ? 1. : 0.);
          changed = true;
        }
        break;
      }
      case FIELD_OPTION_INT:
      case FIELD_OPTION_DOUBLE: {
        double v = o->numericalValue();
        ImGui::SetNextItemWidth(180.f);
        if(ImGui::InputDouble(kv.first.c_str(), &v, 0., 0., "%g",
                              ImGuiInputTextFlags_EnterReturnsTrue)) {
          o->numericalValue(v);
          changed = true;
        }
        break;
      }
      default: {
        // strings, paths and lists are all edited as text, using the textual
        // representation the field itself provides
        std::string key = std::to_string(current) + "/" + kv.first;
        std::string current_text;
        o->getTextRepresentation(current_text);
        auto it = edits.find(key);
        if(it == edits.end())
          it = edits.insert(std::make_pair(key, current_text)).first;
        ImGui::SetNextItemWidth(240.f);
        ImGui::InputText(kv.first.c_str(), &it->second);
        if(ImGui::IsItemDeactivatedAfterEdit()) {
          if(o->getType() == FIELD_OPTION_STRING ||
             o->getType() == FIELD_OPTION_PATH) {
            o->string(it->second);
          }
          else {
            // a list of numbers, separated by commas or spaces
            std::string t = it->second;
            for(auto &c : t)
              if(c == ',' || c == '{' || c == '}') c = ' ';
            std::istringstream in(t);
            if(o->getType() == FIELD_OPTION_LIST) {
              std::list<int> l;
              int v;
              while(in >> v) l.push_back(v);
              o->list(l);
            }
            else {
              std::list<double> l;
              double v;
              while(in >> v) l.push_back(v);
              o->listdouble(l);
            }
          }
          changed = true;
        }
        else if(!ImGui::IsItemActive() && it->second != current_text) {
          it->second = current_text;
        }
        break;
      }
      }
      if(o->getDescription().size() && ImGui::BeginItemTooltip()) {
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 30.f);
        ImGui::TextUnformatted(o->getDescription().c_str());
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
      }
      ImGui::PopID();
    }
  }
  ImGui::EndChild();

  if(ImGui::Button("Set as background field")) {
    fields->setBackgroundFieldId(current);
    changed = true;
  }
  ImGui::SameLine();
  if(ImGui::Button("Delete")) {
    int id = current;
    current = -1;
    fields->deleteField(id);
    changed = true;
  }

  if(changed) {
    Gui::updateFields();
    drawContext::global()->draw();
  }
#else
  ImGui::TextDisabled("Gmsh was compiled without mesh support");
#endif

  ImGui::End();
}

#endif
