// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "GuiDialogs.h"
#include "drawContext.h"
#include "fileDialogs.h"
#include "Context.h"
#include "GModel.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Options.h"
#include "OpenFile.h"
#include "OS.h"
#include "onelabGroup.h"
#include "viewButton.h"
#include "menuFltk.h"
#include "GuiMenus.h"
#include "GuiActions.h"

#if defined(HAVE_MESH)
#include "Field.h"
#endif

static void view_toggle_cb(Fl_Widget *w, void *data)
{
  int num = (intptr_t)data;
  viewButton *but = FlGui::instance()->onelab->getViewButton(num);
  if(but) {
    if(Fl::event_state(FL_SHIFT)) {
      for(std::size_t i = 0; i < PView::list.size(); i++) {
        if((int)i != num)
          opt_view_visible(i, GMSH_SET | GMSH_GUI, 0);
        else
          opt_view_visible(i, GMSH_SET | GMSH_GUI, 1);
      }
    }
    else
      opt_view_visible(num, GMSH_SET, but->value());
    drawContext::global()->draw();
  }
}

viewButton::viewButton(int x, int y, int w, int h, int num, Fl_Color col)
  : Fl_Group(x, y, w, h)
{
  int popw = FL_NORMAL_SIZE + 2;

  PView *view = PView::list[num];
  PViewData *data = view->getData();
  PViewOptions *opt = view->getOptions();

  _toggle = new Fl_Check_Button(x, y, w - popw, h);
  _toggle->box(FL_FLAT_BOX);
  _toggle->color(col);
  _toggle->callback(view_toggle_cb, (void *)(intptr_t)num);
  _toggle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _toggle->value(opt->visible);
  char tmp[256];
  sprintf(tmp, "[%d] %s", num, data->getName().c_str());
  _toggle->copy_label(tmp);
  strcpy(_tooltip, data->getFileName().c_str());
  _toggle->tooltip(_tooltip);

  _butt = new Fl_Button(x + w - popw, y, popw, h, "@>");
  _butt->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _butt->tooltip("Show view options (Shift+w)");
  _butt->box(FL_FLAT_BOX);
  _butt->color(col);
  _butt->selection_color(col);
  // What it drops is described once in src/common/GuiMenus.cpp, and the FLTK
  // popup is built from it: the twenty-six entries used to be written out
  // here, and the Dear ImGui tree offered three of them.
  _popup = new popupButtonFltk(x + w - popw, y, popw, h);
  _popup->box(FL_NO_BOX);
  _popup->key = "view";
  _popup->what = [num]() { return Menu::viewActions(num); };
  end(); // close the group
  resizable(_toggle);
}
