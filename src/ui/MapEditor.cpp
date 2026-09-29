// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <cmath>
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

  MapEditor::Answer MapEditor::press(const ColourMap &map, int entry,
                                     int value, int button, unsigned mods,
                                     bool onWedge)
  {
    _help = false;
    if(map.empty()) return Redraw;
    if(onWedge) {
      _marking = true;
      _marker = std::max(0, std::min(map.size() - 1, entry));
      return Redraw;
    }
    if(mods & ModCommand)
      _channel = 3;
    else if(button == 0 && !(mods & (ModShift | ModAlt)))
      _channel = 0;
    else if(button == 1 || (button == 0 && (mods & ModShift)))
      _channel = 1;
    else
      _channel = 2;
    _from = entry;
    return drag(map, entry, value);
  }

  MapEditor::Answer MapEditor::drag(const ColourMap &map, int entry, int value)
  {
    if(map.empty()) return NotMine;
    int size = map.size();
    entry = std::max(0, std::min(size - 1, entry));
    if(_marking) {
      _marker = entry;
      return Redraw;
    }
    if(_from < 0) return NotMine;
    value = std::max(0, std::min(255, value));
    bool hsv = map.hsv && map.hsv();
    for(int i = std::min(_from, entry); i <= std::max(_from, entry); i++)
      setMapChannel(map, i, _channel, value, hsv);
    _from = entry;
    return Changed;
  }

  std::string MapEditor::markerText(const ColourMap &map, int entry)
  {
    if(map.empty() || !map.about) return "";
    std::string name;
    double least = 0., most = 0.;
    map.about(name, least, most);
    int size = map.size();
    double v = size > 1 ? least + (most - least) * entry / (double)(size - 1) :
                          least;
    char s[64];
    snprintf(s, sizeof(s), "%g", v);
    return s;
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

  namespace {
    // the rows of the picture: the values last, the marker above them, the
    // wedge above it, the curves in all that is left
    void _rows(double height, double line, double &wedge, double &marker,
               double &values)
    {
      // the margins are fractions of a line, whatever the line is: 5 pixels
      // below a line of 17, as master has it, or less than a cell
      values = height - .3 * line - line;
      marker = values - line;
      wedge = marker - line;
    }
  } // namespace

  MapEditor::Picture MapEditor::picture(const ColourMap &map, double width,
                                        double height, double line) const
  {
    Picture p;
    _rows(height, line, p.wedge, p.marker, p.values);
    int size = map.empty() ? 0 : map.size();
    if(size < 2 || width < 1. || p.wedge < .25 * line) return p;
    bool hsv = map.hsv && map.hsv();
    auto xOf = [&](int i) { return width * i / (double)(size - 1); };
    auto yOf = [&](int v) { return p.wedge * (1. - v / 255.); };
    // the wedge, a box a unit wide
    for(int x = 0; x < (int)width; x++) {
      int i = entryAt(map, x, width);
      Colour c = map.colour(i);
      c.a = 255;
      p.boxes.push_back({(double)x, p.wedge, 1., line, c});
    }
    // the curves: red, green and blue, or hue, saturation and value, then
    // alpha in the colour of the text
    const Colour inks[3] = {Colour(255, 0, 0), Colour(0, 255, 0),
                            Colour(0, 0, 255)};
    for(int channel = 0; channel < 4; channel++)
      for(int i = 1; i < size; i++)
        p.segments.push_back({xOf(i - 1), yOf(mapChannel(map, i - 1, channel, hsv)),
                              xOf(i), yOf(mapChannel(map, i, channel, hsv)),
                              channel < 3 ? inks[channel] : Colour(),
                              channel == 3});
    // the marker under the wedge
    double mx = xOf(_marker), my = p.marker, a = line * .3;
    p.segments.push_back({mx, my, mx, my + line * .7, Colour(), true});
    p.segments.push_back({mx, my, mx - a, my + a * 1.6, Colour(), true});
    p.segments.push_back({mx, my, mx + a, my + a * 1.6, Colour(), true});
    // the help or the title, the value under the marker, the largest one
    if(_help) {
      const auto &keys = helpLines();
      double scale = std::min(
        .85, (p.wedge - .7 * line) / ((double)keys.size() + 1.) / line);
      double step = line * scale * 1.06;
      for(std::size_t k = 0; k < keys.size(); k++) {
        p.texts.push_back({.35 * line, .35 * line + k * step, keys[k].first,
                           scale, false});
        p.texts.push_back({12. * step, .35 * line + k * step, keys[k].second,
                           scale, false});
      }
    }
    else
      p.texts.push_back({.35 * line, .25 * line, title(map), 1., false});
    p.texts.push_back({.6 * line, p.values, markerText(map, _marker), 1., false});
    std::string name;
    double least = 0., most = 0.;
    if(map.about) map.about(name, least, most);
    char s[64];
    snprintf(s, sizeof(s), "%g", most);
    p.texts.push_back({width - .6 * line, p.values, s, 1., true});
    return p;
  }

  void MapEditor::at(const ColourMap &map, double x, double y, double width,
                     double height, double line, int &entry, int &value,
                     bool &onWedge)
  {
    double wedge, marker, values;
    _rows(height, line, wedge, marker, values);
    entry = entryAt(map, x, width);
    value = valueAt(y, wedge);
    onWedge = y >= wedge;
  }

  std::vector<unsigned char> MapEditor::raster(const Picture &p, int width,
                                               int height, Colour background,
                                               Colour ink)
  {
    std::vector<unsigned char> rgba((std::size_t)std::max(0, width) *
                                      std::max(0, height) * 4);
    auto put = [&](int x, int y, const Colour &c) {
      if(x < 0 || y < 0 || x >= width || y >= height) return;
      unsigned char *d = &rgba[((std::size_t)y * width + x) * 4];
      d[0] = c.r;
      d[1] = c.g;
      d[2] = c.b;
      d[3] = 255;
    };
    for(int y = 0; y < height; y++)
      for(int x = 0; x < width; x++) put(x, y, background);
    for(const auto &b : p.boxes)
      for(int y = (int)b.y; y < (int)(b.y + b.h); y++)
        for(int x = (int)b.x; x < (int)(b.x + b.w); x++) put(x, y, b.colour);
    for(const auto &s : p.segments) {
      const Colour &c = s.ink ? ink : s.colour;
      double dx = s.x1 - s.x0, dy = s.y1 - s.y0;
      int n = (int)std::ceil(std::max(std::fabs(dx), std::fabs(dy))) + 1;
      for(int k = 0; k <= n; k++)
        put((int)(s.x0 + dx * k / n), (int)(s.y0 + dy * k / n), c);
    }
    return rgba;
  }

} // namespace Ui
