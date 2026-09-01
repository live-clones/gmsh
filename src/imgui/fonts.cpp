// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// Finding a font for the interface.
//
// Dear ImGui embeds a single bitmap font, which is crisp at its native size but
// blurry as soon as the display scale is not 1 -- and it is 1.8 on a typical
// desktop today. Gmsh therefore looks for a real TrueType font on the system
// and loads that instead, falling back on the embedded one when it finds
// nothing. Set GMSH_GUI_FONT to a .ttf file to choose explicitly.
//
// This also fixes the text drawn in the 3D scene, which is rendered from the
// same atlas by drawContextGL.

#include "GmshConfig.h"

#if defined(HAVE_IMGUI)

#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <string>
#include <system_error>
#include <vector>

#include "imgui.h"

#include "appWindow.h"
#include "toolkit.h"
#include "OS.h"

namespace {

  // the usual places, in the order we prefer them
  const char *const _fontFiles[] = {
#if defined(__APPLE__)
    "/System/Library/Fonts/SFNSDisplay.ttf",
    "/System/Library/Fonts/Helvetica.ttc",
    "/Library/Fonts/Arial.ttf",
#elif defined(WIN32) || defined(_WIN32)
    "C:\\Windows\\Fonts\\segoeui.ttf",
    "C:\\Windows\\Fonts\\arial.ttf",
    "C:\\Windows\\Fonts\\tahoma.ttf",
#else
    "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
    "/usr/share/fonts/dejavu/DejaVuSans.ttf",
    "/usr/share/fonts/TTF/DejaVuSans.ttf",
    "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
    "/usr/share/fonts/liberation-sans/LiberationSans-Regular.ttf",
    "/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf",
    "/usr/share/fonts/noto/NotoSans-Regular.ttf",
#endif
    nullptr};

  // the families to look for when scanning a directory, in the order we prefer
  // them; this is what finds the fonts on the distributions that do not use the
  // paths above (NixOS, Guix, a font installed in the home directory, ...)
  const char *const _fontNames[] = {"DejaVuSans.ttf",
                                    "LiberationSans-Regular.ttf",
                                    "NotoSans-Regular.ttf",
                                    "FreeSans.ttf",
                                    "Arial.ttf",
                                    nullptr};

  // Read the <dir> entries of a fontconfig configuration file. This is how the
  // font directories are found on the distributions that do not use the usual
  // paths (NixOS and Guix put every font under /nix/store or /gnu/store and
  // only list them here), without having to link against fontconfig.
  void _readFontconfigDirs(const std::string &file,
                           std::vector<std::string> &dirs)
  {
    FILE *fp = Fopen(file.c_str(), "rb");
    if(!fp) return;
    std::string content;
    char buffer[4096];
    std::size_t n;
    while((n = fread(buffer, 1, sizeof(buffer), fp)) > 0)
      content.append(buffer, n);
    fclose(fp);

    std::size_t pos = 0;
    while((pos = content.find("<dir", pos)) != std::string::npos) {
      std::size_t open = content.find('>', pos);
      if(open == std::string::npos) break;
      std::size_t close = content.find("</dir>", open);
      if(close == std::string::npos) break;
      std::string dir = content.substr(open + 1, close - open - 1);
      // trim
      while(dir.size() && isspace((unsigned char)dir.front())) dir.erase(0, 1);
      while(dir.size() && isspace((unsigned char)dir.back())) dir.pop_back();
      if(dir.size() && dir[0] == '~') {
        if(const char *home = getenv("HOME")) dir = std::string(home) + dir.substr(1);
      }
      if(dir.size() && dir[0] == '/') dirs.push_back(dir);
      pos = close + 6;
    }
  }

  void _fontDirectories(std::vector<std::string> &dirs)
  {
    if(const char *home = getenv("HOME")) {
      dirs.push_back(std::string(home) + "/.local/share/fonts");
      dirs.push_back(std::string(home) + "/.nix-profile/share/fonts");
      dirs.push_back(std::string(home) + "/.fonts");
    }
    // NixOS and friends put everything behind the current system profile
    dirs.push_back("/run/current-system/sw/share/fonts");
    dirs.push_back("/usr/local/share/fonts");
    dirs.push_back("/usr/share/fonts");
    if(const char *xdg = getenv("XDG_DATA_DIRS")) {
      std::string s(xdg);
      std::size_t start = 0;
      while(start < s.size()) {
        std::size_t sep = s.find(':', start);
        if(sep == std::string::npos) sep = s.size();
        std::string d = s.substr(start, sep - start);
        if(d.size()) dirs.push_back(d + "/fonts");
        start = sep + 1;
      }
    }

    // whatever fontconfig knows about
    _readFontconfigDirs("/etc/fonts/fonts.conf", dirs);
    std::error_code ec;
    for(const auto &entry :
        std::filesystem::directory_iterator("/etc/fonts/conf.d", ec)) {
      if(entry.path().extension() == ".conf")
        _readFontconfigDirs(entry.path().string(), dirs);
    }
  }

  // look for one of the preferred families under the font directories; the
  // search is depth-limited, so that a big font tree does not cost anything
  // noticeable at startup
  std::string _searchFontDirectories()
  {
    std::vector<std::string> dirs;
    _fontDirectories(dirs);

    for(int wanted = 0; _fontNames[wanted]; wanted++) {
      for(auto &dir : dirs) {
        std::error_code ec;
        if(!std::filesystem::is_directory(dir, ec) || ec) continue;
        auto opts = std::filesystem::directory_options::skip_permission_denied;
        std::filesystem::recursive_directory_iterator it(dir, opts, ec), end;
        if(ec) continue;
        for(; it != end; it.increment(ec)) {
          if(ec) break;
          if(it.depth() > 3) {
            it.disable_recursion_pending();
            continue;
          }
          std::error_code ec2;
          if(it->is_directory(ec2)) continue;
          if(it->path().filename().string() == _fontNames[wanted])
            return it->path().string();
        }
      }
    }
    return "";
  }

  std::string _findFont()
  {
    if(const char *env = getenv("GMSH_GUI_FONT")) {
      if(!StatFile(env)) return env;
      Toolkit::report(Toolkit::Warning, "GMSH_GUI_FONT='%s' does not exist: ignoring it", env);
    }
    for(int i = 0; _fontFiles[i]; i++)
      if(!StatFile(_fontFiles[i])) return _fontFiles[i];
    return _searchFontDirectories();
  }

} // namespace

void appWindow::_loadFont()
{
  ImGuiIO &io = ImGui::GetIO();

  std::string file = _findFont();
  if(file.size()) {
    // the size is only a starting point: since 1.92 Dear ImGui rasterizes the
    // glyphs at whatever size they are drawn, so the display scale is applied
    // through style.FontScaleDpi instead
    ImFont *font = io.Fonts->AddFontFromFileTTF(file.c_str(), 16.f);
    if(font) {
      io.FontDefault = font;
      // reported by the constructor, once the console can receive messages
      _fontFile = file;
      return;
    }
    Toolkit::report(Toolkit::Warning, "Could not load the font '%s'", file.c_str());
  }

  io.Fonts->AddFontDefault();
  _fontFile.clear();
}

#endif
