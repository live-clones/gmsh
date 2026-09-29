// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef UI_MAP_EDITOR_H
#define UI_MAP_EDITOR_H

#include <string>
#include <utility>
#include <vector>

#include "Form.h"

namespace Ui {

  // What editing a colour map (Field::map) is, whatever draws it: the keys,
  // the help, the title, which channel a button draws and which entries a
  // drag paints. An interface draws the curves and the wedge, turns its
  // events into entries and intensities, and keeps one of these per map.
  class MapEditor {
  public:
    // what a key did: nothing (the interface passes it on), what is shown
    // changed (the help, the mode), or the colours did (the field is told)
    enum Answer { NotMine = 0, Redraw, Changed };
    Answer key(const ColourMap &map, int key, unsigned mods);

    // a button down on an entry (0 to size - 1) at an intensity (0 to
    // 255); button 0 is the left one, 1 the middle one, 2 the right one.
    // Left draws red or hue, middle or Shift+left green or saturation,
    // right or Alt+left blue or value, any with Command alpha
    void press(const ColourMap &map, int entry, int value, int button,
               unsigned mods);
    // the entries between the last one and this one take the intensity
    void drag(const ColourMap &map, int entry, int value);
    void release() { _from = -1; }
    bool drawing() const { return _from >= 0; }

    bool help() const { return _help; }
    void setHelp(bool on) { _help = on; }
    // "Colormap 2 (RGB) - Press h for help"
    static std::string title(const ColourMap &map);
    // what the keys and the buttons do, a line each
    static const std::vector<std::pair<std::string, std::string>> &helpLines();

    // the entry under x, in a wedge from 0 to width; the intensity at y, in a
    // drawing of the curves from 0 (the top) to height
    static int entryAt(const ColourMap &map, double x, double width);
    static int valueAt(double y, double height);

  private:
    bool _help = false;
    int _from = -1, _channel = 0;
  };

} // namespace Ui

#endif
