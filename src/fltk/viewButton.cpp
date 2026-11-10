// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include <cstdint>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "drawContext.h"
#include "fileDialogs.h"
#include "Context.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Options.h"
#include "OS.h"
#include "onelabGroup.h"
#include "fltkActions.h"
#include "viewButton.h"
#include "graphicWindow.h"
#include "Actions.h"

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

void saveView(int index)
{
  static const char *formats =
    "Gmsh Parsed\t*.pos\nGmsh MSH\t*.msh\n"
    "Gmsh Legacy ASCII\t*.pos\nGmsh Legacy Binary\t*.pos\n"
    "MED\t*.rmed\nSTL Surface\t*.stl\nGeneric TXT\t*.txt\n"
    "VTK XML Unstructured Grid\t*.vtu\n";

  PView *view = PView::list[index];
test:
  if(fileChooser(FILE_CHOOSER_CREATE, "Export", formats,
                 view->getData()->getFileName().c_str())) {
    std::string name = fileChooserGetName(1);
    bool confirmOverwrite = CTX::instance()->confirmOverwrite;
#if defined(__APPLE__)
    // handled directly by the native macOS file chooser
    if(CTX::instance()->nativeFileChooser) confirmOverwrite = false;
#endif
    if(confirmOverwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", nullptr, name.c_str()))
          goto test;
    }
    // (in the order of the formats above)
    const int format[] = {PView::POS_PARSED, PView::MSH, PView::POS_ASCII,
                          PView::POS_BINARY, PView::MED, PView::STL,
                          PView::TXT,        PView::VTU};
    int f = fileChooserGetFilter();
    view->write(name, (f >= 0 && f < 8) ? format[f] : PView::POS_PARSED);
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
  std::string label = "[" + std::to_string(num) + "] " + data->getName();
  _toggle->copy_label(label.c_str());
  _toggle->copy_tooltip(data->getFileName().c_str());

  _butt = new Fl_Button(x + w - popw, y, popw, h, "@>");
  _butt->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  _butt->tooltip("Show view options (Shift+w)");
  _butt->box(FL_FLAT_BOX);
  _butt->color(col);
  _butt->selection_color(col);
  _popup = new Fl_Menu_Button(x + w - popw, y, popw, h);
  _popup->type(Fl_Menu_Button::POPUP123);

  // (see Actions.cpp)
  addMenuItems(_popup, GetActionMenu("View"), num);

  end(); // close the group
  resizable(_toggle);
}
