// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstring>
#include <regex>

#include "imgui.h"

#include "messageConsole.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "OS.h"

messageConsole::messageConsole()
  : _maxLines(50000), _autoScroll(true), _scrollToBottom(false)
{
  _filter[0] = '\0';
}

void messageConsole::add(const std::string &msg, int level)
{
  _lines.push_back(line(msg, level));
  while(_lines.size() > _maxLines) _lines.pop_front();
  if(_autoScroll) _scrollToBottom = true;
}

void messageConsole::clear()
{
  _lines.clear();
}

void messageConsole::save(const std::string &fileName)
{
  FILE *fp = Fopen(fileName.c_str(), "w");
  if(!fp) {
    Msg::Error("Unable to open file '%s'", fileName.c_str());
    return;
  }
  for(auto &l : _lines) fprintf(fp, "%s\n", l.text.c_str());
  fclose(fp);
  Msg::StatusBar(true, "Wrote '%s'", fileName.c_str());
}

static ImVec4 _colorForLevel(int level)
{
  // these follow the colors of the FLTK message browser
  switch(level) {
  case Gui::MessageError: return ImVec4(0.90f, 0.30f, 0.30f, 1.f);
  case Gui::MessageWarning: return ImVec4(0.95f, 0.75f, 0.25f, 1.f);
  case Gui::MessageDirect: return ImVec4(0.45f, 0.65f, 1.00f, 1.f);
  default: return ImGui::GetStyleColorVec4(ImGuiCol_Text);
  }
}

void messageConsole::draw()
{
  if(ImGui::Button("Clear")) clear();
  ImGui::SameLine();
  if(ImGui::Button("Copy")) {
    std::string all;
    for(auto &l : _lines) { all += l.text; all += "\n"; }
    ImGui::SetClipboardText(all.c_str());
  }
  ImGui::SameLine();
  ImGui::Checkbox("Auto-scroll", &_autoScroll);
  ImGui::SameLine();
  ImGui::SetNextItemWidth(-1.f);
  ImGui::InputTextWithHint("##filter", "Filter (regular expression)", _filter,
                           sizeof(_filter));
  ImGui::Separator();

  // an invalid regular expression should not throw out of the frame
  bool useFilter = (_filter[0] != '\0');
  std::regex re;
  if(useFilter) {
    try {
      re = std::regex(_filter, std::regex::icase);
    } catch(...) {
      useFilter = false;
    }
  }

  if(ImGui::BeginChild("##messages", ImVec2(0, 0), ImGuiChildFlags_None,
                       ImGuiWindowFlags_HorizontalScrollbar)) {
    ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(4, 1));
    for(auto &l : _lines) {
      if(useFilter && !std::regex_search(l.text, re)) continue;
      ImGui::PushStyleColor(ImGuiCol_Text, _colorForLevel(l.level));
      ImGui::TextUnformatted(l.text.c_str());
      ImGui::PopStyleColor();
    }
    ImGui::PopStyleVar();
    if(_scrollToBottom) {
      ImGui::SetScrollHereY(1.f);
      _scrollToBottom = false;
    }
  }
  ImGui::EndChild();
}

#endif
