// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "clippingWindow.h"
#include "shortcutWindow.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

clippingWindow::clippingWindow(int fontsize) 
  : _fontsize(fontsize)
{
  static Fl_Menu_Item plane_number[] = {
    {"Plane 0", 0, 0},
    {"Plane 1", 0, 0},
    {"Plane 2", 0, 0},
    {"Plane 3", 0, 0},
    {"Plane 4", 0, 0},
    {"Plane 5", 0, 0},
    {0}
  };

  int width = 26 * _fontsize;
  int height = 10 * BH + 5 * WB;
  int L = 7 * _fontsize;

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Clipping");
  win->box(GMSH_WINDOW_BOX);

  browser = new Fl_Multi_Browser(WB, WB, L - WB, height - BH - 3 * WB);
  browser->callback(clip_update_cb);

  Fl_Tabs *o = new Fl_Tabs
    (L + WB, WB, width - L - 2 * WB, height - 3 * WB - 4 * BH);
  {
    group[0] = new Fl_Group
      (L + WB, WB + BH, width - L - 2 * WB, height - 3 * WB - 5 * BH, "Planes");

    int BW = width - L - 4 * WB - 4 * _fontsize;

    choice = new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, BW, BH);
    choice->menu(plane_number);
    choice->callback(clip_num_cb);

    Fl_Button *invert = new Fl_Button
      (L + 2 * WB, 2 * WB + 2 * BH, _fontsize, 4 * BH, "-");
    invert->callback(clip_invert_cb);
    invert->tooltip("Invert orientation");
    
    value[0] = new Fl_Value_Input
      (L + 2 * WB + _fontsize, 2 * WB + 2 * BH, BW - _fontsize, BH, "A");
    value[1] = new Fl_Value_Input
      (L + 2 * WB + _fontsize, 2 * WB + 3 * BH, BW - _fontsize, BH, "B");
    value[2] = new Fl_Value_Input
      (L + 2 * WB + _fontsize, 2 * WB + 4 * BH, BW - _fontsize, BH, "C");
    value[3] = new Fl_Value_Input
      (L + 2 * WB + _fontsize, 2 * WB + 5 * BH, BW - _fontsize, BH, "D");
    for(int i = 0; i < 4; i++){
      value[i]->align(FL_ALIGN_RIGHT);
      value[i]->callback(clip_update_cb);
    }

    group[0]->end();
  }
  {
    group[1] = new Fl_Group
      (L + WB, WB + BH, width - L - 2 * WB, height - 3 * WB - 5 * BH, "Box");
    group[1]->hide();

    int w2 = (width - L - 4 * WB) / 2;
    int BW = w2 - 2 * _fontsize;
    value[4] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Cx");
    value[5] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Cy");
    value[6] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Cz");
    value[7] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 1 * BH, BW, BH, "Wx");
    value[8] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 2 * BH, BW, BH, "Wy");
    value[9] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 3 * BH, BW, BH, "Wz");
    for(int i = 4; i < 10; i++){
      value[i]->align(FL_ALIGN_RIGHT);
      value[i]->callback(clip_update_cb);
    }

    group[1]->end();
  }
  o->callback(clip_reset_cb);
  o->end();

  butt[0] = new Fl_Check_Button
    (L + WB, 3 * WB + 6 * BH, width - L - 2 * WB, BH, "Keep whole elements");
  butt[1] = new Fl_Check_Button
    (L + WB, 3 * WB + 7 * BH, width - L - 2 * WB, BH, "Only draw intersecting volume layer");
  butt[2] = new Fl_Check_Button
    (L + WB, 3 * WB + 8 * BH, width - L - 2 * WB, BH, "Cut only volume elements");
  for(int i = 0; i < 3; i++){
    butt[i]->type(FL_TOGGLE_BUTTON);
    butt[i]->callback(clip_update_cb);
  }

  resetBrowser();

  {
    Fl_Return_Button *o = new Fl_Return_Button
      (width - 3 * BB - 3 * WB, height - BH - WB, BB, BH, "Redraw");
    o->callback(redraw_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Reset");
    o->callback(clip_reset_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void *)win);
  }

  win->position(CTX.clip_position[0], CTX.clip_position[1]);
  win->end();
}

void clippingWindow::resetBrowser()
{
  char str[128];
  browser->clear();
  browser->add("Geometry");
  browser->add("Mesh");
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    sprintf(str, "View [%d]", i);
    browser->add(str);
  }
  int idx = choice->value();
  browser->deselect();
  for(int i = 0; i < browser->size(); i++){
    if((i == 0 && CTX.geom.clip & (1 << idx)) ||
       (i == 1 && CTX.mesh.clip & (1 << idx)) ||
       (i - 2 < PView::list.size() && 
        PView::list[i - 2]->getOptions()->Clip & (1 << idx)))
      browser->select(i + 1);
  }
  for(int i = 0; i < 4; i++)
    value[i]->value(CTX.clip_plane[idx][i]);
  for(int i = 4; i < 7; i++)
    value[i]->value(0.);
  for(int i = 7; i < 10; i++)
    value[i]->value(1.);

  for(int i = 0; i < 3; i++) {
    value[i]->step(0.01);
    value[i]->minimum(-1.0);
    value[i]->maximum(1.0);
  }
  double val1 = 0;
  for(int i = 0; i < 3; i++)
    val1 = std::max(val1, std::max(fabs(CTX.min[i]), fabs(CTX.max[i])));
  val1 *= 1.5;
  for(int i = 3; i < 10; i++){
    value[i]->step(val1/200.);
    value[i]->minimum(-val1);
    value[i]->maximum(val1);
  }
}

void clippingWindow::show()
{
  resetBrowser();
  win->show();
}
