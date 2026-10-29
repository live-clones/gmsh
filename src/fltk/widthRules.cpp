// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <FL/Fl_Scroll.H>
#include "widthRules.h"

// all the children of a group side by side on one line, e.g. the fields of a
// vector, and not stacked like the panes of tabs
static bool isRow(Fl_Group *g)
{
  if(g->children() < 2) return false;
  std::vector<Fl_Widget *> w(g->array(), g->array() + g->children());
  std::sort(w.begin(), w.end(),
            [](Fl_Widget *a, Fl_Widget *b) { return a->x() < b->x(); });
  for(std::size_t i = 1; i < w.size(); i++)
    if(w[i]->y() != w[0]->y() || w[i]->x() < w[i - 1]->x() + w[i - 1]->w())
      return false;
  return true;
}

void widthRules::_record(Fl_Widget *w, int mid, int right, int rule, int parent)
{
  item it;
  it.widget = w;
  it.x = w->x();
  it.w = w->w();
  it.parent = parent;
  if(rule != Stretch)
    it.rule = rule;
  else if(it.x >= mid)
    it.rule = Shift;
  else if(it.x + it.w >= right - 1)
    it.rule = Stretch;
  else
    it.rule = Stay;
  _items.push_back(it);
  Fl_Group *g = w->as_group();
  if(!g) return;
  int index = _items.size() - 1;
  int childRule = (it.rule == Stretch && isRow(g)) ? Share : it.rule;
  // a scroll places its own scrollbars
  Fl_Scroll *s = dynamic_cast<Fl_Scroll *>(g);
  for(int i = 0; i < g->children(); i++) {
    Fl_Widget *c = g->child(i);
    if(s && (c == &s->scrollbar || c == &s->hscrollbar)) continue;
    _record(c, mid, right, childRule, index);
  }
}

void widthRules::record(Fl_Group *g, int mid, int right)
{
  for(int i = 0; i < g->children(); i++)
    _record(g->child(i), mid, right, Stretch, -1);
}

void widthRules::apply(int extra) const
{
  if(extra < 0) extra = 0;
  for(const item &it : _items) {
    Fl_Widget *w = it.widget;
    int x = it.x, ww = it.w;
    if(it.rule == Shift)
      x += extra;
    else if(it.rule == Stretch)
      ww += extra;
    else if(it.rule == Share) {
      // a share of the row, which its parent, placed before, has stretched
      const item &p = _items[it.parent];
      Fl_Widget *pw = p.widget;
      double scale = (double)pw->w() / p.w;
      x = pw->x() + (int)((it.x - p.x) * scale);
      ww = pw->x() + (int)((it.x + it.w - p.x) * scale) - x;
    }
    Fl_Group *g = w->as_group();
    if(g && !dynamic_cast<Fl_Scroll *>(g)) {
      // its children are placed by their own items
      g->Fl_Widget::resize(x, w->y(), ww, w->h());
      g->init_sizes();
    }
    else // a scroll only moves its children, which their items place after
      w->resize(x, w->y(), ww, w->h());
  }
}
