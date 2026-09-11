// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <algorithm>
#include <cstring>
#include <filesystem>
#include <system_error>

#include "imgui.h"

#include "fileBrowser.h"

namespace fs = std::filesystem;

// Where the "Home" button goes. Told to the browser once rather than asked of
// anyone: a file browser is a file browser.
static std::string _home = ".";

void fileBrowser::setHome(const std::string &directory)
{
  if(directory.size()) _home = directory;
}

fileBrowser::fileBrowser()
  : _mode(Open), _selected(-1), _active(false), _done(false), _accepted(false),
    _needRescan(true)
{
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

  // start in the directory of the given name, or where the process is: what
  // file is meant is the caller's to say
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

// does the name match one of the space-separated patterns of the filter?
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
    if(name.empty() || name[0] == '.') continue;
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
  _needRescan = false;
}

void fileBrowser::draw()
{
  if(!_active) return;
  if(_needRescan) _rescan();

  const char *id = "##gmshFileBrowser";
  if(!ImGui::IsPopupOpen(id)) ImGui::OpenPopup(id);

  ImVec2 center = ImGui::GetMainViewport()->GetCenter();
  ImGui::SetNextWindowPos(center, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));
  ImGui::SetNextWindowSize(ImVec2(700, 480), ImGuiCond_Appearing);
  if(!ImGui::BeginPopupModal(id, nullptr, ImGuiWindowFlags_NoSavedSettings))
    return;

  ImGui::TextUnformatted(_title.c_str());
  ImGui::Separator();

  // path bar: one button per component, so that any parent is one click away
  {
    std::error_code ec;
    fs::path p(_directory);
    std::vector<fs::path> parts;
    for(fs::path cur = p; !cur.empty(); cur = cur.parent_path()) {
      parts.push_back(cur);
      if(cur == cur.root_path()) break;
    }
    std::reverse(parts.begin(), parts.end());
    for(std::size_t i = 0; i < parts.size(); i++) {
      std::string label = parts[i].filename().string();
      if(label.empty()) label = parts[i].string(); // root
      ImGui::PushID((int)i);
      if(ImGui::SmallButton(label.c_str())) {
        _directory = parts[i].string();
        _needRescan = true;
      }
      ImGui::PopID();
      if(i + 1 < parts.size()) ImGui::SameLine(0.f, 2.f);
    }
    ImGui::SameLine();
    if(ImGui::SmallButton("Home")) {
      _directory = _home;
      _needRescan = true;
    }
  }

  ImGui::Separator();

  float footer = ImGui::GetFrameHeightWithSpacing() * 2.f + 8.f;
  if(ImGui::BeginChild("##list", ImVec2(0, -footer), ImGuiChildFlags_Borders)) {
    if(ImGui::Selectable("..", false, ImGuiSelectableFlags_AllowDoubleClick)) {
      if(ImGui::IsMouseDoubleClicked(ImGuiMouseButton_Left)) {
        std::error_code ec;
        fs::path parent = fs::path(_directory).parent_path();
        if(!parent.empty()) {
          _directory = parent.string();
          _needRescan = true;
        }
      }
    }
    for(int i = 0; i < (int)_entries.size(); i++) {
      const entry &e = _entries[i];
      std::string label = e.isDir ? ("[" + e.name + "]") : e.name;
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

  ImGui::SetNextItemWidth(-160.f);
  if(ImGui::InputText("##name", _fileName, sizeof(_fileName),
                      ImGuiInputTextFlags_EnterReturnsTrue)) {
    _done = true;
    _accepted = true;
  }
  ImGui::SameLine();
  if(ImGui::Button(_mode == Save ? "Save" : "Open", ImVec2(70, 0))) {
    _done = true;
    _accepted = true;
  }
  ImGui::SameLine();
  if(ImGui::Button("Cancel", ImVec2(70, 0)) ||
     ImGui::IsKeyPressed(ImGuiKey_Escape)) {
    _done = true;
    _accepted = false;
  }

  // The formats offered, when there is more than one to choose from: picking
  // one narrows what is listed, and is what the caller is told was meant.
  if(_formats.size() > 1) {
    std::string say = _formats[_chosen].name.size() ?
                        _formats[_chosen].name : _formats[_chosen].pattern;
    ImGui::SetNextItemWidth(220.f);
    if(ImGui::BeginCombo("Format", say.c_str())) {
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
    ImGui::SameLine();
  }
  else if(_filter[0]) {
    ImGui::TextDisabled("Filter: %s", _filter);
    ImGui::SameLine();
  }
  if(_message.size()) ImGui::TextUnformatted(_message.c_str());

  // an accepted directory name just enters it
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

#endif
