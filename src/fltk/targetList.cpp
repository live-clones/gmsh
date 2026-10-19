// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <FL/fl_draw.H>
#include "FlGui.h"
#include "targetList.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"

targetList::targetList(int x, int y, int w, int rowHeight,
                       const std::vector<const char *> &buttons,
                       Fl_Callback *cb)
  : Fl_Group(x, y, w, 4 * rowHeight), _rowHeight(rowHeight)
{
  browser = new Fl_Multi_Browser(x, y, w, 3 * rowHeight);
  browser->has_scrollbar(Fl_Browser_::VERTICAL);
  browser->tooltip("Ctrl+click or Shift+click to choose several at once");
  count = new Fl_Box(x, y, w, rowHeight);
  count->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
  for(const char *b : buttons) {
    Fl_Button *o = new Fl_Button(x, y, rowHeight, rowHeight, b);
    o->callback(cb, (void *)b);
    _buttons.push_back(o);
  }
  end();
  resize(x, y, w, 4 * rowHeight);
}

int targetList::heightFor(int n) const
{
  fl_font(browser->textfont(), browser->textsize());
  int lines = std::max(2, std::min(6, n));
  return lines * (fl_height() + 2) + 4 + WB + _rowHeight;
}

std::string targetList::viewName(int i)
{
  return "[" + std::to_string(i) + "] " + PView::list[i]->getData()->getName();
}

void targetList::selectViews(const std::string &which, int first, int keep)
{
  for(int i = 0; i < browser->size(); i++) {
    int v = i - first;
    bool visible = v < 0 || (v < (int)PView::list.size() &&
                             PView::list[v]->getOptions()->visible);
    bool on = (which == "All") || (which == "Visible" && visible) ||
              (keep >= 0 && v == keep);
    browser->select(i + 1, on ? 1 : 0);
  }
}

int targetList::selectedCount() const
{
  int n = 0;
  for(int i = 1; i <= browser->size(); i++)
    if(browser->selected(i)) n++;
  return n;
}

void targetList::resize(int x, int y, int w, int h)
{
  // the browser takes what the line of buttons leaves
  Fl_Widget::resize(x, y, w, h);
  int bh = _rowHeight, bw = 5 * (bh - 1) / 2, n = _buttons.size();
  int hb = std::max(bh, h - WB - bh);
  browser->resize(x, y, w, hb);
  count->resize(x, y + hb + WB, w - n * bw, bh);
  for(int i = 0; i < n; i++)
    _buttons[i]->resize(x + w - (n - i) * bw, y + hb + WB, bw, bh);
}
