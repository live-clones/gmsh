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
    // Over the curves, left draws red or hue, middle or Shift+left green or
    // saturation, right or Alt+left blue or value, any with Command alpha;
    // on the wedge (onWedge), any moves the marker. Redraw or Changed
    Answer press(const ColourMap &map, int entry, int value, int button,
                 unsigned mods, bool onWedge = false);
    // the entries between the last one and this one take the intensity, or
    // the marker follows
    Answer drag(const ColourMap &map, int entry, int value);
    void release()
    {
      _from = -1;
      _marking = false;
    }
    bool drawing() const { return _from >= 0 || _marking; }

    // the entry the marker is on, and the value of the map there
    int marker() const { return _marker; }
    static std::string markerText(const ColourMap &map, int entry);

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

    // --- what the editor looks like, in the units the interface draws in, y
    // down, as master has it: the curves over the wedge, the marker under
    // it, the values on the last line
    struct Picture {
      struct Segment {
        double x0, y0, x1, y1;
        Colour colour;
        // in the colour of the text of the interface rather than `colour`
        bool ink;
      };
      struct Box {
        double x, y, w, h;
        Colour colour;
      };
      struct Text {
        // the top left corner of the line, or its top right one
        double x, y;
        std::string text;
        // of the font of the interface
        double scale;
        bool right;
      };
      std::vector<Box> boxes;
      std::vector<Segment> segments;
      std::vector<Text> texts;
      // where the wedge, the marker and the values start
      double wedge = 0., marker = 0., values = 0.;
    };
    // `line` is the height of a line of text
    Picture picture(const ColourMap &map, double width, double height,
                    double line) const;
    // the point x, y of the same picture: the entry under it, the intensity
    // it stands for, and whether it is on the wedge or below it
    static void at(const ColourMap &map, double x, double y, double width,
                   double height, double line, int &entry, int &value,
                   bool &onWedge);
    // the boxes and segments of a picture as pixels, the texts left out:
    // rows from the top, 4 bytes a pixel
    static std::vector<unsigned char> raster(const Picture &p, int width,
                                             int height, Colour background,
                                             Colour ink);

  private:
    bool _help = false, _marking = false;
    int _from = -1, _channel = 0, _marker = 0;
  };

} // namespace Ui

#endif
