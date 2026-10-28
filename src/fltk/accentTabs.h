// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ACCENT_TABS_H
#define ACCENT_TABS_H

#include <cstdlib>
#include <FL/Fl_Tabs.H>
#include <FL/fl_draw.H>
#include "gmshScheme.h"
#include "paletteWindow.h"

// The tabs of the tools: under the gmsh theme the tab chosen carries a bar in
// the selection colour along its top, as the editors mark it, the tabs of
// FLTK telling it by its frame alone; a tab of a floating tool dragged off
// the row takes the tool to the dock
class accentTabs : public Fl_Tabs {
  Fl_Widget *_pushedTab; // the tab the button went down on
protected:
  void draw_tab(int x1, int x2, int W, int H, Fl_Widget *o, int flags, int what)
  {
    Fl_Tabs::draw_tab(x1, x2, W, H, o, flags, what);
    // the last argument says which side of the chosen tab this one is on,
    // not whether it is chosen: that is the child shown
    if(o != value() || !gmshScheme()) return;
    // from the light left line of the frame of the tab to its dark right
    // one, the tabs drawn shifted by the offset of a scrolled row
    fl_color(gmshAccent());
    fl_rectf(x1 + tab_offset + 1, y() + 1, W - 2, 2);
  }

public:
  accentTabs(int x, int y, int w, int h, const char *l = nullptr)
    : Fl_Tabs(x, y, w, h, l), _pushedTab(nullptr)
  {
  }
  virtual int handle(int event)
  {
    switch(event) {
    case FL_PUSH: _pushedTab = which(Fl::event_x(), Fl::event_y()); break;
    case FL_DRAG:
      if(_pushedTab) {
        // off the row, at the top or the bottom, by more than its height
        int th = abs(tab_height()),
            top = tab_height() >= 0 ? y() : y() + h() - th;
        if(Fl::event_y() < top - th || Fl::event_y() >= top + 2 * th) {
          _pushedTab = nullptr;
          push(nullptr);
          if(paletteWindow *pw = dynamic_cast<paletteWindow *>(window()))
            pw->dragToDock();
          return 1;
        }
      }
      break;
    case FL_RELEASE: _pushedTab = nullptr; break;
    }
    return Fl_Tabs::handle(event);
  }
};

#endif
