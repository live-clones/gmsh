// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "clippingWindow.h"
#include "paletteWindow.h"
#include "GmshDefines.h"
#include "PView.h"
#include "PViewOptions.h"
#include "Context.h"

void clip_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->clipping->show();
}

static void clip_num_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->clipping->resetBrowser();
}

static void clip_update_cb(Fl_Widget *w, void *data)
{
  if(FlGui::instance()->clipping->group[0]->visible()){ // plane tab
    int idx = FlGui::instance()->clipping->choice->value();
    CTX::instance()->geom.clip &= ~(1 << idx);
    CTX::instance()->mesh.clip &= ~(1 << idx);
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->clip &= ~(1 << idx);
    for(int i = 0; i < FlGui::instance()->clipping->browser->size(); i++){
      if(FlGui::instance()->clipping->browser->selected(i + 1)){
        if(i == 0)
          CTX::instance()->geom.clip |= (1 << idx);
        else if(i == 1)
          CTX::instance()->mesh.clip |= (1 << idx);
        else if(i - 2 < (int)PView::list.size())
          PView::list[i - 2]->getOptions()->clip |= (1 << idx);
      }
    }
    for(int j = 0; j < 4; j++)
      CTX::instance()->clipPlane[idx][j] = FlGui::instance()->clipping->plane[j]->value();
    FlGui::instance()->clipping->fillBoxValuesFromPlaneValues();
  }
  else{ // box tab
    CTX::instance()->geom.clip = 0;
    CTX::instance()->mesh.clip = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->clip = 0;
    for(int i = 0; i < FlGui::instance()->clipping->browser->size(); i++){
      if(FlGui::instance()->clipping->browser->selected(i + 1)){
        for(int idx = 0; idx < 6; idx++){
          if(i == 0)
            CTX::instance()->geom.clip |= (1 << idx);
          else if(i == 1)
            CTX::instance()->mesh.clip |= (1 << idx);
          else if(i - 2 < (int)PView::list.size())
            PView::list[i - 2]->getOptions()->clip |= (1 << idx);
        }
      }
    }
    double c[3] = {FlGui::instance()->clipping->box[0]->value(),
                   FlGui::instance()->clipping->box[1]->value(),
                   FlGui::instance()->clipping->box[2]->value()};
    double d[3] = {FlGui::instance()->clipping->box[3]->value(),
                   FlGui::instance()->clipping->box[4]->value(),
                   FlGui::instance()->clipping->box[5]->value()};
    // left
    CTX::instance()->clipPlane[0][0] = 1.; 
    CTX::instance()->clipPlane[0][1] = 0.;
    CTX::instance()->clipPlane[0][2] = 0.;
    CTX::instance()->clipPlane[0][3] = -c[0] + d[0] / 2.;
    // top
    CTX::instance()->clipPlane[1][0] = 0.; 
    CTX::instance()->clipPlane[1][1] = 1.; 
    CTX::instance()->clipPlane[1][2] = 0.;
    CTX::instance()->clipPlane[1][3] = -c[1] + d[1] / 2.;
    // near
    CTX::instance()->clipPlane[2][0] = 0.; 
    CTX::instance()->clipPlane[2][1] = 0.; 
    CTX::instance()->clipPlane[2][2] = 1.;
    CTX::instance()->clipPlane[2][3] = -c[2] + d[2] / 2.;
    // right
    CTX::instance()->clipPlane[3][0] = -1.; 
    CTX::instance()->clipPlane[3][1] = 0.; 
    CTX::instance()->clipPlane[3][2] = 0.;
    CTX::instance()->clipPlane[3][3] = c[0] + d[0] / 2.;
    // bottom
    CTX::instance()->clipPlane[4][0] = 0.; 
    CTX::instance()->clipPlane[4][1] = -1.; 
    CTX::instance()->clipPlane[4][2] = 0.;
    CTX::instance()->clipPlane[4][3] = c[1] + d[1] / 2.;
    // far
    CTX::instance()->clipPlane[5][0] = 0.; 
    CTX::instance()->clipPlane[5][1] = 0.; 
    CTX::instance()->clipPlane[5][2] = -1.;
    CTX::instance()->clipPlane[5][3] = c[2] + d[2] / 2.;

    int idx = FlGui::instance()->clipping->choice->value();
    for(int j = 0; j < 4; j++)
      FlGui::instance()->clipping->plane[j]->value(CTX::instance()->clipPlane[idx][j]);
  }
  
  if(CTX::instance()->clipWholeElements || 
     CTX::instance()->clipWholeElements != 
     FlGui::instance()->clipping->butt[0]->value()){
    for(int clip = 0; clip < 6; clip++){
      if(CTX::instance()->mesh.clip)
        CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
      for(unsigned int index = 0; index < PView::list.size(); index++)
        if(PView::list[index]->getOptions()->clip)
          PView::list[index]->setChanged(true);
    }
  }
  
  CTX::instance()->clipWholeElements = 
    FlGui::instance()->clipping->butt[0]->value();
  CTX::instance()->clipOnlyDrawIntersectingVolume = 
    FlGui::instance()->clipping->butt[1]->value();
  CTX::instance()->clipOnlyVolume = 
    FlGui::instance()->clipping->butt[2]->value();
  
  int old = CTX::instance()->drawBBox;
  CTX::instance()->drawBBox = 1;
  if(CTX::instance()->fastRedraw)
    CTX::instance()->post.draw = CTX::instance()->mesh.draw = 0;
  drawContext::global()->draw();
  CTX::instance()->drawBBox = old;
  CTX::instance()->post.draw = CTX::instance()->mesh.draw = 1;
}

static void clip_invert_cb(Fl_Widget *w, void *data)
{
  for(int i = 0; i < 4; i++)
    FlGui::instance()->clipping->plane[i]->value
      (-FlGui::instance()->clipping->plane[i]->value());
  clip_update_cb(NULL, NULL);
}

static void clip_reset_cb(Fl_Widget *w, void *data)
{
  CTX::instance()->geom.clip = 0;
  CTX::instance()->mesh.clip = 0;
  for(unsigned int index = 0; index < PView::list.size(); index++)
    PView::list[index]->getOptions()->clip = 0;

  // Warning: for consistency these reset values should match the
  // default values for the associated options
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 4; j++)
      CTX::instance()->clipPlane[0][0] = 0.;
  CTX::instance()->clipPlane[0][0] = 1.;
  CTX::instance()->clipPlane[1][1] = 1.;
  CTX::instance()->clipPlane[2][2] = 1.;
  CTX::instance()->clipPlane[3][0] = -1.;
  CTX::instance()->clipPlane[4][1] = -1.;
  CTX::instance()->clipPlane[5][2] = -1.;
  CTX::instance()->clipPlane[3][3] = 1.;
  CTX::instance()->clipPlane[4][3] = 1.;
  CTX::instance()->clipPlane[5][3] = 1.;

  if(CTX::instance()->clipWholeElements){
    CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    for(unsigned int index = 0; index < PView::list.size(); index++)
      PView::list[index]->setChanged(true);
  }

  FlGui::instance()->clipping->resetBrowser();
  drawContext::global()->draw();
}

static void clip_redraw_cb(Fl_Widget *w, void *data)
{
  // force update to make sure to set all planes active/inactive
  // correctly when switching between the plane et box tabs
  clip_update_cb(NULL, NULL);
  drawContext::global()->draw();
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
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Clipping");
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
    
    plane[0] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 2 * BH, BW - FL_NORMAL_SIZE, BH, "A");
    plane[1] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 3 * BH, BW - FL_NORMAL_SIZE, BH, "B");
    plane[2] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 4 * BH, BW - FL_NORMAL_SIZE, BH, "C");
    plane[3] = new Fl_Value_Input
      (L + 2 * WB + FL_NORMAL_SIZE, 2 * WB + 5 * BH, BW - FL_NORMAL_SIZE, BH, "D");
    for(int j = 0; j < 4; j++){
      plane[j]->align(FL_ALIGN_RIGHT);
      plane[j]->callback(clip_update_cb);
    }

    group[0]->end();
  }
  {
    group[1] = new Fl_Group
      (L + WB, WB + BH, width - L - 2 * WB, height - 3 * WB - 5 * BH, "Box");
    group[1]->hide();

    int w2 = (width - L - 4 * WB) / 2;
    int BW = w2 - 2 * FL_NORMAL_SIZE;
    box[0] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 1 * BH, BW, BH, "Cx");
    box[1] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 2 * BH, BW, BH, "Cy");
    box[2] = new Fl_Value_Input(L + 2 * WB, 2 * WB + 3 * BH, BW, BH, "Cz");
    box[3] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 1 * BH, BW, BH, "Wx");
    box[4] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 2 * BH, BW, BH, "Wy");
    box[5] = new Fl_Value_Input(L + 2 * WB + w2, 2 * WB + 3 * BH, BW, BH, "Wz");
    for(int i = 0; i < 6; i++){
      box[i]->align(FL_ALIGN_RIGHT);
      box[i]->callback(clip_update_cb);
    }

    group[1]->end();
  }
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
    o->callback(clip_redraw_cb);
  }
  {
    Fl_Button *o = new Fl_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Reset");
    o->callback(clip_reset_cb);
  }

  win->position(CTX::instance()->clipPosition[0], CTX::instance()->clipPosition[1]);
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
    if((i == 0 && CTX::instance()->geom.clip & (1 << idx)) ||
       (i == 1 && CTX::instance()->mesh.clip & (1 << idx)) ||
       (i > 1 && i - 2 < (int)PView::list.size() && 
        PView::list[i - 2]->getOptions()->clip & (1 << idx)))
      browser->select(i + 1);
  }

  for(int j = 0; j < 4; j++)
    plane[j]->value(CTX::instance()->clipPlane[idx][j]);

  for(int j = 0; j < 3; j++) {
    plane[j]->step(0.01);
    plane[j]->minimum(-1.0);
    plane[j]->maximum(1.0);
  }
  double val1 = 0;
  for(int i = 0; i < 3; i++)
    val1 = std::max(val1, std::max(fabs(CTX::instance()->min[i]), 
                                   fabs(CTX::instance()->max[i])));
  val1 *= 1.5;

  plane[3]->step(val1 / 200.);
  plane[3]->minimum(-val1);
  plane[3]->maximum(val1);

  fillBoxValuesFromPlaneValues();
  
  for(int i = 0; i < 6; i++){
    box[i]->step(val1 / 200.);
    box[i]->minimum(-val1);
    box[i]->maximum(val1);
  }
}
  
void clippingWindow::fillBoxValuesFromPlaneValues()
{
  double c[3] = {(-CTX::instance()->clipPlane[0][3] + CTX::instance()->clipPlane[3][3]) / 2.,
                 (-CTX::instance()->clipPlane[1][3] + CTX::instance()->clipPlane[4][3]) / 2.,
                 (-CTX::instance()->clipPlane[2][3] + CTX::instance()->clipPlane[5][3]) / 2.};
  double d[3] = {CTX::instance()->clipPlane[0][3] + CTX::instance()->clipPlane[3][3],
                 CTX::instance()->clipPlane[1][3] + CTX::instance()->clipPlane[4][3],
                 CTX::instance()->clipPlane[2][3] + CTX::instance()->clipPlane[5][3]};
  box[0]->value(c[0]);
  box[1]->value(c[1]);
  box[2]->value(c[2]);
  box[3]->value(d[0]);
  box[4]->value(d[1]);
  box[5]->value(d[2]);
}

void clippingWindow::show()
{
  resetBrowser();
  win->show();
}
