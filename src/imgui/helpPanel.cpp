// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// The three help windows of the "Help" menu, which are three separate windows
// in the FLTK interface too: the keyboard and mouse reference, the listing of
// the current options and of the parser symbols, and the "About" box. The
// listing comes from PrintOptions(), so it can never get out of date.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstring>
#include <string>
#include <vector>

#include "imgui.h"

#include "appWindow.h"
#include "Gui.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "GuiActions.h"
#include "GmshGlobal.h"
#include "CommandLine.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

namespace {

  struct shortcut {
    const char *keys;
    const char *what;
  };

  const shortcut _mouse[] = {
    {"Move", "highlight the entity under the cursor"},
    {"Left button", "rotate"},
    {"Ctrl + Left button", "start a rubber zoom"},
    {"Middle button", "zoom"},
    {"Shift + Left button", "zoom"},
    {"Right button", "pan (and reset the view on a click)"},
    {"Wheel", "zoom"},
    {"Double click", "run the double-click command of the entity"},
    {nullptr, nullptr}};

  const shortcut _keyboard[] = {
    {"0", "reload the geometry script"},
    {"9 or Ctrl + 0", "reload the whole project"},
    {"1 or F1", "mesh in 1D"},
    {"2 or F2", "mesh in 2D"},
    {"3 or F3", "mesh in 3D"},
    {"Ctrl + N", "new file"},
    {"Ctrl + O", "open a file"},
    {"Ctrl + Shift + O", "merge a file"},
    {"Ctrl + Shift + R", "reopen the second most recent file"},
    {"Ctrl + R", "rename the model file"},
    {"Ctrl + Shift + S", "save the mesh"},
    {"Ctrl + J", "save the options next to the model"},
    {"Ctrl + Shift + J", "save the options as the default ones"},
    {"Ctrl + E", "export"},
    {"Ctrl + Q", "quit"},
    {"Ctrl + T", "run the solver"},
    {"Ctrl + Shift + N", "options"},
    {"Ctrl + Shift + U", "plugins"},
    {"Ctrl + Shift + V", "visibility"},
    {"Ctrl + Shift + C", "clipping"},
    {"Ctrl + Shift + M", "manipulator"},
    {"Ctrl + I", "statistics"},
    {"Ctrl + L", "show or hide the message console"},
    {"Ctrl + M", "minimize the window"},
    {"Ctrl + F", "enter or leave full screen"},
    {"Ctrl + D", "attach or detach the module panel"},
    {"Ctrl + H", "this window"},
    {"Ctrl + Shift + H", "the current options and workspace"},
    {"m", "show or hide the message console"},
    {"w", "merge the files matching the watch pattern"},
    {"Left, Right", "step through the time steps"},
    {"Up, Down", "step through the views"},
    {"Home", "rewind the animation"},
    {nullptr, nullptr}};

  const shortcut _selection[] = {
    {"e", "end the selection"},
    {"u", "undo the last selection"},
    {"i or -", "invert the selection"},
    {"q or Escape", "abort the selection"},
    {nullptr, nullptr}};

  void _table(const char *title, const shortcut *rows)
  {
    ImGui::SeparatorText(title);
    if(!ImGui::BeginTable(title, 2,
                          ImGuiTableFlags_SizingStretchProp |
                            ImGuiTableFlags_RowBg))
      return;
    for(int i = 0; rows[i].keys; i++) {
      ImGui::TableNextRow();
      ImGui::TableNextColumn();
      ImGui::TextUnformatted(rows[i].keys);
      ImGui::TableNextColumn();
      ImGui::TextUnformatted(rows[i].what);
    }
    ImGui::EndTable();
  }

} // namespace

void appWindow::_drawHelpPanel()
{
  if(_showHelpBasic) {
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_FirstUseEver);
    if(ImGui::Begin("Keyboard and Mouse Usage", &_showHelpBasic)) {
      _table("Mouse", _mouse);
      _table("Keyboard", _keyboard);
      _table("While selecting entities", _selection);
    }
    ImGui::End();
  }

  if(_showHelpOptions) {
    ImGui::SetNextWindowSize(ImVec2(620, 620), ImGuiCond_FirstUseEver);
    if(ImGui::Begin("Current Options and Workspace", &_showHelpOptions)) {
      static char filter[128] = "";
      static bool onlyModified = false;
      static bool withHelp = false;
      static std::vector<std::string> lines;
      static bool first = true;

      bool refresh = first;
      first = false;
      if(ImGui::Button("Refresh")) refresh = true;
      ImGui::SameLine();
      if(ImGui::Checkbox("Only the modified ones", &onlyModified))
        refresh = true;
      ImGui::SameLine();
      if(ImGui::Checkbox("Show the help", &withHelp)) refresh = true;
      ImGui::SetNextItemWidth(-1.f);
      ImGui::InputTextWithHint("##filter", "Filter", filter, sizeof(filter));

      if(refresh) {
        lines.clear();
        PrintOptions(0, GMSH_FULLRC, onlyModified ? 1 : 0, withHelp ? 1 : 0,
                     nullptr, &lines);
#if defined(HAVE_PARSER)
        PrintParserSymbols(withHelp ? 1 : 0, lines);
#endif
      }

      ImGui::Separator();
      if(ImGui::BeginChild("##listing", ImVec2(0, 0), ImGuiChildFlags_None,
                           ImGuiWindowFlags_HorizontalScrollbar)) {
        std::string f(filter);
        for(auto &c : f) c = (char)tolower((unsigned char)c);
        for(auto &l : lines) {
          // PrintOptions() appends the kind of the option after a null byte
          std::string text = l.substr(0, l.find('\0'));
          if(f.size()) {
            std::string t = text;
            for(auto &c : t) c = (char)tolower((unsigned char)c);
            if(t.find(f) == std::string::npos) continue;
          }
          ImGui::TextUnformatted(text.c_str());
        }
      }
      ImGui::EndChild();
    }
    ImGui::End();
  }
}

void appWindow::_drawAboutPanel()
{
  if(!_showAbout) return;

  ImGui::SetNextWindowSize(ImVec2(560, 460), ImGuiCond_FirstUseEver);
  if(!ImGui::Begin("About Gmsh", &_showAbout)) {
    ImGui::End();
    return;
  }

  ImGui::TextUnformatted("Gmsh");
  ImGui::Text("version %s", GetGmshVersion());
  ImGui::Spacing();
  ImGui::TextUnformatted("Copyright (C) 1997-2026");
  ImGui::TextUnformatted("Christophe Geuzaine and Jean-Francois Remacle");
  ImGui::Spacing();
  if(ImGui::SmallButton("Credits"))
    postAction([]() { openURL("https://gmsh.info/CREDITS.txt"); });
  ImGui::SameLine();
  if(ImGui::SmallButton("Licensing information"))
    postAction([]() { openURL("https://gmsh.info/LICENSE.txt"); });
  ImGui::SameLine();
  if(ImGui::SmallButton("Issue tracker")) {
    postAction(
      []() { openURL("https://gitlab.onelab.info/gmsh/gmsh/issues"); });
  }
  ImGui::Spacing();
  ImGui::Separator();
  if(ImGui::BeginChild("##build", ImVec2(0, -ImGui::GetFrameHeightWithSpacing()),
                       ImGuiChildFlags_None,
                       ImGuiWindowFlags_HorizontalScrollbar)) {
    ImGui::Text("Build OS: %s", GetGmshBuildOS());
    ImGui::Text("Build date: %s", GetGmshBuildDate());
    ImGui::Text("Build host: %s", GetGmshBuildHost());
    ImGui::TextUnformatted("Build options:");
    ImGui::Indent();
    ImGui::TextWrapped("%s", GetGmshBuildOptions());
    ImGui::Unindent();
    ImGui::Text("GUI toolkit: %s", Gui::toolkitVersion().c_str());
    ImGui::Text("Packaged by: %s", GetGmshPackager());
  }
  ImGui::EndChild();
  if(ImGui::Button("Visit https://gmsh.info"))
    postAction([]() { openURL("https://gmsh.info"); });

  ImGui::End();
}

#endif
