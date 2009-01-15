// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "Draw.h"
#include "clippingWindow.h"
#include "paletteWindow.h"
#include "GmshDefines.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Context.h"

extern Context_T CTX;

void clip_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->clipping->show();
}

static void clip_num_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->clipping->resetBrowser();
}

static void clip_update_cb(Fl_Widget *w, void *data)
{
  if(GUI::instance()->clipping->group[0]->visible()){ // clipping planes
    int idx = GUI::instance()->clipping->choice->value();
    CTX.geom.clip &= ~(1 << idx);
    CTX.mesh.clip &= ~(1 << idx);
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->Clip &= ~(1 << idx);
    for(int i = 0; i < GUI::instance()->clipping->browser->size(); i++){
      if(GUI::instance()->clipping->browser->selected(i + 1)){
        if(i == 0)
          CTX.geom.clip |= (1 << idx);
        else if(i == 1)
          CTX.mesh.clip |= (1 << idx);
        else if(i - 2 < (int)PView::list.size())
          PView::list[i - 2]->getOptions()->Clip |= (1 << idx);
      }
    }
    for(int i = 0; i < 4; i++)
      CTX.clip_plane[idx][i] = GUI::instance()->clipping->value[i]->value();
  }
  else{ // clipping box
    CTX.geom.clip = 0;
    CTX.mesh.clip = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->Clip = 0;
    for(int i = 0; i < GUI::instance()->clipping->browser->size(); i++){
      if(GUI::instance()->clipping->browser->selected(i + 1)){
        for(int idx = 0; idx < 6; idx++){
          if(i == 0)
            CTX.geom.clip |= (1 << idx);
          else if(i == 1)
            CTX.mesh.clip |= (1 << idx);
          else if(i - 2 < (int)PView::list.size())
            PView::list[i - 2]->getOptions()->Clip |= (1 << idx);
        }
      }
    }
    double c[3] = {GUI::instance()->clipping->value[4]->value(),
                   GUI::instance()->clipping->value[5]->value(),
                   GUI::instance()->clipping->value[6]->value()};
    double d[3] = {GUI::instance()->clipping->value[7]->value(),
                   GUI::instance()->clipping->value[8]->value(),
                   GUI::instance()->clipping->value[9]->value()};
    // left
    CTX.clip_plane[0][0] = 1.;  CTX.clip_plane[0][1] = 0.;  CTX.clip_plane[0][2] = 0.;
    CTX.clip_plane[0][3] = -(c[0] - d[0] / 2.);
    // right
    CTX.clip_plane[1][0] = -1.; CTX.clip_plane[1][1] = 0.; CTX.clip_plane[1][2] = 0.;
    CTX.clip_plane[1][3] = (c[0] + d[0] / 2.);
    // top
    CTX.clip_plane[2][0] = 0.; CTX.clip_plane[2][1] = 1.; CTX.clip_plane[2][2] = 0.;
    CTX.clip_plane[2][3] = -(c[1] - d[1] / 2.);
    // bottom
    CTX.clip_plane[3][0] = 0.; CTX.clip_plane[3][1] = -1.; CTX.clip_plane[3][2] = 0.;
    CTX.clip_plane[3][3] = (c[1] + d[1] / 2.);
    // near
    CTX.clip_plane[4][0] = 0.; CTX.clip_plane[4][1] = 0.; CTX.clip_plane[4][2] = 1.;
    CTX.clip_plane[4][3] = -(c[2] - d[2] / 2.);
    // far
    CTX.clip_plane[5][0] = 0.; CTX.clip_plane[5][1] = 0.; CTX.clip_plane[5][2] = -1.;
    CTX.clip_plane[5][3] = (c[2] + d[2] / 2.);
  }

  if(CTX.clip_whole_elements || 
     CTX.clip_whole_elements != GUI::instance()->clipping->butt[0]->value()){
    for(int clip = 0; clip < 6; clip++){
      if(CTX.mesh.clip)
	CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
      for(unsigned int index = 0; index < PView::list.size(); index++)
	if(PView::list[index]->getOptions()->Clip)
	  PView::list[index]->setChanged(true);
    }
  }
  
  CTX.clip_whole_elements = GUI::instance()->clipping->butt[0]->value();
  CTX.clip_only_draw_intersecting_volume = GUI::instance()->clipping->butt[1]->value();
  CTX.clip_only_volume = GUI::instance()->clipping->butt[2]->value();
  
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.draw_bbox = old;
  CTX.post.draw = CTX.mesh.draw = 1;
}

static void clip_invert_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < 4; i++)
    GUI::instance()->clipping->value[i]->value
      (-GUI::instance()->clipping->value[i]->value());
  clip_update_cb(NULL, NULL);
}

static void clip_reset_cb(Fl_Widget *w, void *data)
{
  CTX.geom.clip = 0;
  CTX.mesh.clip = 0;
  for(unsigned int index = 0; index < PView::list.size(); index++)
    PView::list[index]->getOptions()->Clip = 0;

  for(int i = 0; i < 6; i++){
    CTX.clip_plane[i][0] = 1.;
    for(int j = 1; j < 4; j++)
      CTX.clip_plane[i][j] = 0.;
  }

  if(CTX.clip_whole_elements){
    CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    for(unsigned int index = 0; index < PView::list.size(); index++)
      PView::list[index]->setChanged(true);
  }

  GUI::instance()->clipping->resetBrowser();
  Draw();
}

clippingWindow::clippingWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  static Fl_Menu_Item plane_number[] = {
    {"Plane 0", 0, 0},
    {"Plane 1", 0, 0},
    {"Plane 2", 0, 0},
    {"Plane 3", 0, 0},
    {"Plane 4", 0, 0},
    {"Plane 5", 0, 0},
    {0}
  };

  int width = 26 * FL_NORMAL_SIZE;
  int height = 10 * BH + 5 * WB;
  int L = 7 * FL_NORMAL_SIZE;

  win = new paletteWindow
    (width, height, CTX.non_modal_windows ? true : false, "Clipping");
  win->box(GMSH_WINDOW_BOX);

  browser = new Fl_Multi_Browser(WB, WB, L - WB, height - BH - 3 * WB);
  browser->callback(clip_update_cb);

  Fl_Tabs *o = new Fl_Tabs
    (L + WB, WB, width - L - 2 * WB, height - 3 * WB - 4 * BH);
  {
    group[0] = new Fl_Group
      (L + WB, WB + BH, width - L - 2 * WB, height - 3 * WB - 5 * BH, "Planes");

    int BW = width - L - 4 * WB - 4 * FL_NORMAL_SIZE;

    choice = new Fl_Choice(L + 2 * WB, 2 * WB + 1 * BH, BW, BH);
    choice->menu(plane_number);
    choice->callback(clip_num_cb);

    Fl_Button *invert = new Fl_Button
      (L + 2 * WB, 2 * WB + 2 * BH, FL_NORMAL_SIZE, 4 * BH, "-");
    invert->callback(clip_invert_cb);
    invert->tooltip("Invert orientation");
    
    value[0] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 2 * BH, BW - FL_NORMAL_SIZE, BH, "A");
    value[1] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 3 * BH, BW - FL_NORMAL_SIZE, BH, "B");
    value[2] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 4 * BH, BW - FL_NORMAL_SIZE, BH, "C");
    value[3] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 5 * BH, BW - FL_NORMAL_SIZE, BH, "D");
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
    int BW = w2 - 2 * FL_NORMAL_SIZE;
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
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Redraw");
    o->callback(redraw_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Reset");
    o->callback(clip_reset_cb);
  }

  win->position(CTX.clip_position[0], CTX.clip_position[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
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
       (i > 1 && i - 2 < (int)PView::list.size() && 
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
