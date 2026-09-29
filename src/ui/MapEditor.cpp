// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cstdio>

#include "MapEditor.h"

namespace Ui {

  MapEditor::Answer MapEditor::key(const ColourMap &map, int key,
                                   unsigned mods)
  {
    if(map.empty()) return NotMine;
    bool command = (mods & ModCommand) != 0;
    // the digits, the digits with Command and the first seven function keys,
    // in that order
    int presets = map.numPresets ? map.numPresets() : 0, preset = -1;
    if(key >= '0' && key <= '9') preset = (key - '0') + (command ? 10 : 0);
    if(key >= KeyF1 && key < KeyF1 + 7) preset = 20 + key - KeyF1;
    if(preset >= 0 && preset < presets) {
      map.choosePreset(preset);
      return Changed;
    }
    if(key == 'H' && !command) {
      _help = !_help;
      return Redraw;
    }
    if(key == 'M' && !command && map.setHsv) {
      map.setHsv(!(map.hsv && map.hsv()));
      return Redraw;
    }
    if(key == 'R' && !command) {
      if(map.preset) map.choosePreset(map.preset());
      return Changed;
    }
    if(key == 'C' && command) {
      if(map.copy) map.copy();
      return Redraw;
    }
    if(key == 'V' && command) {
      if(map.paste) map.paste();
      return Changed;
    }
    if(map.parameters) {
      for(const auto &p : map.parameters()) {
        if(!p.up.empty() && p.up.matches(key, mods)) {
          map.adjust(p, true);
          return Changed;
        }
        if(!p.down.empty() && p.down.matches(key, mods)) {
          map.adjust(p, false);
          return Changed;
        }
      }
    }
    return NotMine;
  }

  void MapEditor::press(const ColourMap &map, int entry, int value, int button,
                        unsigned mods)
  {
    _help = false;
    if(mods & ModCommand)
      _channel = 3;
    else if(button == 0 && !(mods & (ModShift | ModAlt)))
      _channel = 0;
    else if(button == 1 || (button == 0 && (mods & ModShift)))
      _channel = 1;
    else
      _channel = 2;
    _from = entry;
    drag(map, entry, value);
  }

  void MapEditor::drag(const ColourMap &map, int entry, int value)
  {
    if(map.empty() || _from < 0) return;
    int size = map.size();
    entry = std::max(0, std::min(size - 1, entry));
    value = std::max(0, std::min(255, value));
    bool hsv = map.hsv && map.hsv();
    for(int i = std::min(_from, entry); i <= std::max(_from, entry); i++)
      setMapChannel(map, i, _channel, value, hsv);
    _from = entry;
  }

  std::string MapEditor::title(const ColourMap &map)
  {
    char s[128];
    snprintf(s, sizeof(s), "Colormap %d (%s) - Press h for help",
             map.preset ? map.preset() : 0,
             (map.hsv && map.hsv()) ? "HSV" : "RGB");
    return s;
  }

  const std::vector<std::pair<std::string, std::string>> &MapEditor::helpLines()
  {
    static const std::vector<std::pair<std::string, std::string>> lines = {
      {"0-9, Ctrl+0-9, F1-F7", "Select predefined colormap"},
      {"mouse1", "Draw red or hue channel"},
      {"mouse2, Shift+mouse1", "Draw green or saturation channel"},
      {"mouse3, Alt+mouse1", "Draw blue or value channel"},
      {"Ctrl+mouse1", "Draw alpha channel"},
      {"Ctrl+c, Ctrl+v, r", "Copy, paste or reset colormap"},
      {"m", "Toggle RGB/HSV mode"},
      {"left, right", "Translate abscissa"},
      {"Ctrl+left, Ctrl+right", "Rotate abscissa"},
      {"i, Ctrl+i", "Invert abscissa or ordinate"},
      {"up, down", "Modify color channel curvature"},
      {"a, Ctrl+a", "Modify alpha coefficient"},
      {"p, Ctrl+p", "Modify alpha channel power law"},
      {"b, Ctrl+b", "Modify gamma correction"},
      {"h", "Show this help message"}};
    return lines;
  }

  int MapEditor::entryAt(const ColourMap &map, double x, double width)
  {
    int size = map.empty() ? 0 : map.size();
    if(size < 1 || width <= 0.) return 0;
    return std::max(0, std::min(size - 1, (int)(x * size / width)));
  }

  int MapEditor::valueAt(double y, double height)
  {
    if(height <= 0.) return 0;
    return std::max(0, std::min(255, (int)((height - y) * 255. / height)));
  }

} // namespace Ui
