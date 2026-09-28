// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

// the embedded bitmap font is blurry as soon as the display scale is not 1: a
// TrueType font of the system is looked for; GMSH_GUI_FONT names one

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
    // the font the page asks for, and FLTK gets through fontconfig
    "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
    "/usr/share/fonts/liberation-sans/LiberationSans-Regular.ttf",
    "/usr/share/fonts/liberation/LiberationSans-Regular.ttf",
    "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
    "/usr/share/fonts/dejavu/DejaVuSans.ttf",
    "/usr/share/fonts/TTF/DejaVuSans.ttf",
    "/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf",
    "/usr/share/fonts/noto/NotoSans-Regular.ttf",
#endif
    nullptr};

  // for the distributions that do not use the paths above
  const char *const _fontNames[] = {"LiberationSans-Regular.ttf",
                                    "DejaVuSans.ttf",
                                    "NotoSans-Regular.ttf",
                                    "FreeSans.ttf",
                                    "Arial.ttf",
                                    nullptr};

  // the <dir> entries of a fontconfig file: NixOS and Guix only list their
  // fonts there
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

    _readFontconfigDirs("/etc/fonts/fonts.conf", dirs);
    std::error_code ec;
    for(const auto &entry :
        std::filesystem::directory_iterator("/etc/fonts/conf.d", ec)) {
      if(entry.path().extension() == ".conf")
        _readFontconfigDirs(entry.path().string(), dirs);
    }
  }

  // depth-limited, so that a big font tree costs nothing at startup
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

  // Dear ImGui sizes a font by its line, from the ascender to the descender;
  // FLTK and the page by its em. The line over the em, read off the hhea and
  // head tables of the file; 1 when they cannot be read.
  float _lineOverEm(const std::string &file)
  {
    FILE *fp = Fopen(file.c_str(), "rb");
    if(!fp) return 1.f;
    std::vector<unsigned char> b;
    unsigned char chunk[4096];
    std::size_t n;
    while((n = fread(chunk, 1, sizeof(chunk), fp)) > 0 && b.size() < (1u << 16))
      b.insert(b.end(), chunk, chunk + n);
    fclose(fp);
    auto u16 = [&](std::size_t at) {
      return at + 1 < b.size() ? (b[at] << 8) | b[at + 1] : 0;
    };
    auto u32 = [&](std::size_t at) {
      return ((std::size_t)u16(at) << 16) | (std::size_t)u16(at + 2);
    };
    std::size_t head = 0, hhea = 0;
    for(std::size_t t = 0, count = u16(4); t < count; t++) {
      std::size_t entry = 12 + 16 * t;
      if(entry + 16 > b.size()) break;
      if(!memcmp(&b[entry], "head", 4)) head = u32(entry + 8);
      if(!memcmp(&b[entry], "hhea", 4)) hhea = u32(entry + 8);
    }
    int em = u16(head + 18);
    int ascender = (short)u16(hhea + 4), descender = (short)u16(hhea + 6);
    if(!head || !hhea || em <= 0 || ascender <= descender) return 1.f;
    return (float)(ascender - descender) / (float)em;
  }

  ImFont *_bold = nullptr, *_italic = nullptr, *_fixed = nullptr;

  // the face of fixed width of the same family, where there is one:
  // LiberationSans-Regular beside LiberationMono-Regular, DejaVuSans beside
  // DejaVuSansMono
  std::string _fixedBeside(const std::string &file)
  {
    std::size_t at = file.find("Sans-");
    if(at != std::string::npos)
      return file.substr(0, at) + "Mono-" + file.substr(at + 5);
    at = file.find("Sans.");
    if(at != std::string::npos)
      return file.substr(0, at) + "SansMono." + file.substr(at + 5);
    return "";
  }

} // namespace

ImFont *imguiBoldFont() { return _bold; }
ImFont *imguiItalicFont() { return _italic; }
ImFont *imguiFixedFont() { return _fixed; }

void appWindow::_loadFont()
{
  ImGuiIO &io = ImGui::GetIO();

  std::string file = _findFont();
  if(file.size()) {
    // since 1.92 Dear ImGui rasterizes at whatever size is drawn: the display
    // scale goes through style.FontScaleDpi
    ImFont *font = io.Fonts->AddFontFromFileTTF(file.c_str(), 16.f);
    if(font) {
      io.FontDefault = font;
      _fontFile = file;
      _fontLine = _lineOverEm(file);
      // the headings are bold, some words of prose slanted: the files beside
      // it, where there are
      std::size_t at = file.find("Regular");
      if(at != std::string::npos) {
        std::string bold = file, italic = file;
        bold.replace(at, 7, "Bold");
        italic.replace(at, 7, "Italic");
        if(!StatFile(bold))
          _bold = io.Fonts->AddFontFromFileTTF(bold.c_str(), 16.f);
        if(!StatFile(italic))
          _italic = io.Fonts->AddFontFromFileTTF(italic.c_str(), 16.f);
      }
      std::string fixed = _fixedBeside(file);
      if(fixed.size() && !StatFile(fixed))
        _fixed = io.Fonts->AddFontFromFileTTF(fixed.c_str(), 16.f);
      return;
    }
    Toolkit::report(Toolkit::Warning, "Could not load the font '%s'", file.c_str());
  }

  io.Fonts->AddFontDefault();
  _fontFile.clear();
}

#endif
