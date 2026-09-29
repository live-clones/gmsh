// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef COLORBAR_WINDOWH
#define COLORBAR_WINDOWH

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include "Form.h"
#include "MapEditor.h"

class colorbarWindow : public Fl_Window {
private:
  int font_height;
  const char *label;
  double minval, maxval; // min and max data values
  int wedge_y; // top coord of color wedge
  // the keys, the help, the marker and the stroke being drawn, and what the
  // editor looks like, as every interface has them
  Ui::MapEditor _edit;
  // what it edits, described rather than handed over: see Ui::ColourMap
  Ui::ColourMap _map;
  bool *viewchanged; // pointer to changed bit in view
  Fl_Color color_bg;
  // the entry, the intensity and the part of the picture under x, y
  void _at(int x, int y, int &entry, int &value, bool &onWedge);

public:
  colorbarWindow(int x, int y, int w, int h, const char *l = nullptr);
  void draw();
  int handle(int);
  void update(const char *name, double min, double max,
              const Ui::ColourMap &map,
              bool *changed);
};

#endif
