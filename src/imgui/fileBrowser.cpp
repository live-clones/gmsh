// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#include <algorithm>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <filesystem>
#include <system_error>

#include "imgui.h"

#include "fileBrowser.h"

namespace fs = std::filesystem;

fileBrowser::fileBrowser()
  : _mode(Open), _selected(-1), _active(false), _done(false), _accepted(false),
    _needRescan(true), _hidden(false)
{
  _where[0] = '\0';
  _fileName[0] = '\0';
  _filter[0] = '\0';
}

void fileBrowser::begin(Mode mode, const std::string &title,
                        const std::vector<format> &formats,
                        const std::string &initialName)
{
  _mode = mode;
  _title = title;
  _active = true;
  _done = false;
  _accepted = false;
  _needRescan = true;
  _selected = -1;
  _message.clear();

  _formats = formats;
  _chosen = 0;
  std::string filter = _formats.empty() ? std::string() : _formats[0].pattern;
  strncpy(_filter, filter.c_str(), sizeof(_filter) - 1);
  _filter[sizeof(_filter) - 1] = '\0';

  // the directory of the given name, or where the process is
  std::string name = initialName;
  std::error_code ec;
  fs::path p(name);
  fs::path dir = p.has_parent_path() ? p.parent_path() : fs::current_path(ec);
  if(ec || dir.empty()) dir = ".";
  _directory = fs::absolute(dir, ec).lexically_normal().string();
  if(ec) _directory = dir.string();

  std::string base = p.filename().string();
  strncpy(_fileName, base.c_str(), sizeof(_fileName) - 1);
  _fileName[sizeof(_fileName) - 1] = '\0';
}

std::string fileBrowser::result() const
{
  if(!_fileName[0]) return "";
  std::error_code ec;
  fs::path p(_fileName);
  if(p.is_absolute()) return p.lexically_normal().string();
  return (fs::path(_directory) / p).lexically_normal().string();
}

static bool _matches(const std::string &name, const char *filter)
{
  if(!filter || !filter[0]) return true;
  std::size_t dot = name.find_last_of('.');
  std::size_t slash = name.find_last_of("/\\");
  std::string ext = (dot != std::string::npos &&
                     (slash == std::string::npos || dot > slash)) ?
                      name.substr(dot) :
                      std::string();
  std::string f(filter);
  std::size_t pos = 0;
  while(pos < f.size()) {
    std::size_t end = f.find(' ', pos);
    if(end == std::string::npos) end = f.size();
    std::string pat = f.substr(pos, end - pos);
    pos = end + 1;
    if(pat.empty()) continue;
    if(pat == "*" || pat == "*.*") return true;
    if(pat.size() > 1 && pat[0] == '*') {
      std::string want = pat.substr(1); // ".geo"
      if(want.size() == ext.size() &&
         std::equal(want.begin(), want.end(), ext.begin(),
                    [](char a, char b) { return tolower(a) == tolower(b); }))
        return true;
    }
  }
  return false;
}

void fileBrowser::_rescan()
{
  _entries.clear();
  _selected = -1;
  std::error_code ec;
  std::vector<entry> dirs, files;
  for(fs::directory_iterator it(_directory, ec), end; it != end;
      it.increment(ec)) {
    if(ec) break;
    std::error_code ec2;
    std::string name = it->path().filename().string();
    if(name.empty() || (name[0] == '.' && !_hidden)) continue;
    if(it->is_directory(ec2))
      dirs.push_back(entry(name, true));
    else if(_matches(name, _filter))
      files.push_back(entry(name, false));
  }
  auto byName = [](const entry &a, const entry &b) { return a.name < b.name; };
  std::sort(dirs.begin(), dirs.end(), byName);
  std::sort(files.begin(), files.end(), byName);
  _entries.insert(_entries.end(), dirs.begin(), dirs.end());
  _entries.insert(_entries.end(), files.begin(), files.end());
  strncpy(_where, _directory.c_str(), sizeof(_where) - 1);
  _where[sizeof(_where) - 1] = '\0';
  _needRescan = false;
}

void fileBrowser::draw()
{
  if(!_active) return;
  if(_needRescan) _rescan();

  // as the page draws it: the title in the title bar, the window the colour
  // of the dialogs, the directory typed, the list, the name, the format, the
  // buttons
  const char *id = "###gmshFileBrowser";
  if(!ImGui::IsPopupOpen(id)) ImGui::OpenPopup(id);
  const ImGuiStyle &style = ImGui::GetStyle();
  const float em = ImGui::GetFontSize();
  ImVec2 center = ImGui::GetMainViewport()->GetCenter();
  ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
  ImGui::SetNextWindowSize(ImVec2(32.f * em, 26.f * em), ImGuiCond_Appearing);
  ImGui::PushStyleColor(ImGuiCol_PopupBg, style.Colors[ImGuiCol_WindowBg]);
  bool shown = ImGui::BeginPopupModal((_title + id).c_str(), nullptr,
                                      ImGuiWindowFlags_NoSavedSettings);
  ImGui::PopStyleColor();
  if(!shown) return;

  float go = ImGui::CalcTextSize("Go").x + 2.f * style.FramePadding.x;
  ImGui::SetNextItemWidth(-(go + style.ItemSpacing.x));
  bool moved = ImGui::InputText("##where", _where, sizeof(_where),
                                ImGuiInputTextFlags_EnterReturnsTrue);
  ImGui::SameLine();
  if(ImGui::Button("Go") || moved) {
    std::error_code ec;
    if(fs::is_directory(_where, ec) && !ec) {
      _directory = fs::absolute(_where, ec).lexically_normal().string();
      _needRescan = true;
    }
  }

  float line = ImGui::GetFrameHeightWithSpacing();
  float below = line * (_formats.size() > 1 ? 4.f : 3.f);
  ImGui::PushStyleColor(ImGuiCol_ChildBg, style.Colors[ImGuiCol_FrameBg]);
  bool listed =
    ImGui::BeginChild("##list", ImVec2(0, -below), ImGuiChildFlags_Borders);
  ImGui::PopStyleColor();
  if(listed) {
    if(ImGui::Selectable("..", false, ImGuiSelectableFlags_AllowDoubleClick) &&
       ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
      fs::path parent = fs::path(_directory).parent_path();
      if(!parent.empty()) {
        _directory = parent.string();
        _needRescan = true;
      }
    }
    for(int i = 0; i < (int)_entries.size(); i++) {
      const entry &e = _entries[i];
      std::string label = e.isDir ? e.name + "/" : e.name;
      if(ImGui::Selectable(label.c_str(), _selected == i,
                           ImGuiSelectableFlags_AllowDoubleClick)) {
        _selected = i;
        if(!e.isDir) {
          strncpy(_fileName, e.name.c_str(), sizeof(_fileName) - 1);
          _fileName[sizeof(_fileName) - 1] = '\0';
        }
        if(ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
          if(e.isDir) {
            _directory = (fs::path(_directory) / e.name).string();
            _needRescan = true;
          }
          else {
            _done = true;
            _accepted = true;
          }
        }
      }
    }
  }
  ImGui::EndChild();

  // a check box as small as those of the dialogs
  ImGui::PushStyleVar(
    ImGuiStyleVar_FramePadding,
    ImVec2(style.FramePadding.x, std::floor(style.FramePadding.y / 3.f)));
  if(ImGui::Checkbox("Show hidden files", &_hidden)) _needRescan = true;
  ImGui::PopStyleVar();

  // the names of the two lines before them, lined up
  float named =
    ImGui::GetCursorPosX() +
    std::max(ImGui::CalcTextSize("File").x, ImGui::CalcTextSize("Format").x) +
    style.ItemSpacing.x;
  ImGui::AlignTextToFramePadding();
  ImGui::TextUnformatted("File");
  ImGui::SameLine(named);
  ImGui::SetNextItemWidth(-FLT_MIN);
  if(ImGui::InputText("##name", _fileName, sizeof(_fileName),
                      ImGuiInputTextFlags_EnterReturnsTrue)) {
    _done = true;
    _accepted = true;
  }

  // picking a format narrows what is listed, and is what the caller is told was
  // meant
  if(_formats.size() > 1) {
    std::string say = _formats[_chosen].name.size() ?
                        _formats[_chosen].name : _formats[_chosen].pattern;
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted("Format");
    ImGui::SameLine(named);
    ImGui::SetNextItemWidth(-FLT_MIN);
    if(ImGui::BeginCombo("##format", say.c_str())) {
      for(std::size_t i = 0; i < _formats.size(); i++) {
        std::string one = _formats[i].name.size() ? _formats[i].name :
                                                    _formats[i].pattern;
        if(ImGui::Selectable(one.c_str(), (int)i == _chosen)) {
          _chosen = (int)i;
          strncpy(_filter, _formats[i].pattern.c_str(), sizeof(_filter) - 1);
          _filter[sizeof(_filter) - 1] = '\0';
          _needRescan = true;
        }
      }
      ImGui::EndCombo();
    }
  }

  // Cancel, then the one Return presses, framed as in the dialogs, at the
  // right end
  float button = 6.f * em;
  if(_message.size()) {
    ImGui::AlignTextToFramePadding();
    ImGui::TextUnformatted(_message.c_str());
    ImGui::SameLine();
  }
  ImGui::SetCursorPosX(ImGui::GetWindowContentRegionMax().x - 2.f * button -
                       style.ItemSpacing.x);
  if(ImGui::Button("Cancel", ImVec2(button, 0)) ||
     ImGui::IsKeyPressed(ImGuiKey_Escape)) {
    _done = true;
    _accepted = false;
  }
  ImGui::SameLine();
  ImGui::PushStyleColor(ImGuiCol_Border, style.Colors[ImGuiCol_ButtonActive]);
  if(ImGui::Button(_mode == Save ? "Save" : "Open", ImVec2(button, 0))) {
    _done = true;
    _accepted = true;
  }
  ImGui::PopStyleColor();

  if(_done && _accepted) {
    std::error_code ec;
    std::string full = result();
    if(!full.empty() && fs::is_directory(full, ec) && !ec) {
      _directory = full;
      _fileName[0] = '\0';
      _needRescan = true;
      _done = false;
      _accepted = false;
    }
  }

  if(_done) ImGui::CloseCurrentPopup();
  ImGui::EndPopup();
}
