// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef WIDTH_RULES_H
#define WIDTH_RULES_H

#include <vector>
#include <FL/Fl_Group.H>

// Lets the widgets of a dialog laid out at a fixed width follow a wider
// window: a widget that starts in the left half and ends at the right margin
// stretches, one that starts in the right half moves with the right margin,
// and the others stay where they are; the children of a group that moves or
// stays do the same, those of a group on one row that stretches share its
// width. A scroll is followed into, apart from its scrollbars. Only x and w
// change.
class widthRules {
private:
  enum { Stay, Shift, Stretch, Share };
  struct item {
    Fl_Widget *widget;
    int x, w, rule, parent;
  };
  std::vector<item> _items;
  void _record(Fl_Widget *w, int mid, int right, int rule, int parent);

public:
  // records the descendants of g as they are placed now; mid is the x where
  // the right half starts and right the x of the right margin
  void record(Fl_Group *g, int mid, int right);
  // places them for a width larger by extra pixels than when recorded
  void apply(int extra) const;
  bool empty() const { return _items.empty(); }
};

#endif
