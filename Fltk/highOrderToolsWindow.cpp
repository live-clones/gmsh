// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <string.h>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GmshConfig.h"
#include "FlGui.h"
#include "drawContext.h"
#include "highOrderToolsWindow.h"
#include "paletteWindow.h"
#include "contextWindow.h"
#include "graphicWindow.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "PViewData.h"
#include "GeoStringInterface.h"
#include "Options.h"
#include "Context.h"
#include "HighOrder.h"
#include "OptHomRun.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif


static void change_completeness_cb(Fl_Widget *w, void *data){

  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  bool onlyVisible = (bool)o->butt[1]->value(); 
  if (!o->complete){
    SetHighOrderComplete (GModel::current(), onlyVisible);
    o->complete = 1;
  }
  else if (o->complete){
    SetHighOrderInComplete (GModel::current(), onlyVisible);
    o->complete = 0;
  }
  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
}

static void highordertools_runp_cb(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  
  int order = (int)o->value[0]->value();
  bool linear = !(bool)o->butt[2]->value(); 
  bool incomplete = (bool)o->butt[0]->value(); 
  bool onlyVisible = (bool)o->butt[1]->value(); 

  if (order == 1)
    SetOrder1(GModel::current());
  else
    SetOrderN(GModel::current(), order, linear, incomplete, onlyVisible);

  distanceFromMeshToGeometry_t dist;
  computeDistanceFromMeshToGeometry (GModel::current(), dist);
  for (std::map<GEntity*, double> ::iterator it = dist.d2.begin(); it !=dist.d2.end();++it){
    printf ("GEntity %d of dim %d : dist %12.5E\n",it->first->tag(),it->first->dim(),it->second);
  }


  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
 
}

static void chooseopti_cb(Fl_Widget *w, void *data){
  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  int elastic = o->choice[2]->value(); 
  
  if (elastic == 1){
    o->choice[0]->deactivate(); 
    o->choice[1]->deactivate(); 
    for (int i=3;i<=6;i++)
      o->value[i]->deactivate(); 
    //   o->push[1]->deactivate();
  }
  else {
    o->push[0]->activate();
    o->choice[0]->activate(); 
    o->choice[1]->activate(); 
    for (int i=3;i<=6;i++)
      o->value[i]->activate(); 
    //    o->push[1]->activate();
  }
  
}

static void highordertools_runelas_cb(Fl_Widget *w, void *data)
{
  highOrderToolsWindow *o = FlGui::instance()->highordertools;
  
  bool elastic = o->choice[2]->value() == 1; 
  double threshold_min = o->value[1]->value(); 
  bool onlyVisible = (bool)o->butt[1]->value(); 
  int nbLayers = (int) o->value[2]->value(); 
  double threshold_max = o->value[8]->value(); 

  if(elastic)ElasticAnalogy(GModel::current(), threshold_min, onlyVisible);
  else  {
    OptHomParameters p;
    p.nbLayers = nbLayers; 
    p.BARRIER_MIN = threshold_min;
    p.BARRIER_MAX = threshold_max;
    p.onlyVisible = onlyVisible;
    p.dim  = GModel::current()->getDim();//o->meshOrder;
    p.itMax = (int) o->value[3]->value(); 
    p.weightFixed =  o->value[5]->value(); 
    p.weightFree =  o->value[6]->value(); 
    p.DistanceFactor =  o->value[7]->value(); 
    p.method =  o->CAD ? (int)o->choice[0]->value() : 2; 
    p.filter =  (int)o->choice[1]->value(); 
    HighOrderMeshOptimizer (GModel::current(),p);
    printf("CPU TIME = %4f seconds\n",p.CPU);
  }


  CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  drawContext::global()->draw();
 
}


highOrderToolsWindow::highOrderToolsWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  static int cols[5] = {2 * WB, BB, BB, 2 * BB, 0};
  int width = cols[0] + cols[1] + cols[2] + cols[3] + 6 * WB;
  int height = 23 * BH;

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "High Order Tools");
  win->box(GMSH_WINDOW_BOX);

  //  Fl_Tabs *o = new Fl_Tabs
  //    (WB, WB, width - 2 * WB, height - 3 * WB - BH);
  //  {
  //    Fl_Group *g = new Fl_Group
  //      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Check Validity");    
  //    g->end();
  //    Fl_Group::current()->resizable(g);
  //  }
  {
    //    Fl_Group *g = new Fl_Group
    //      (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Generate High Order Mesh");

    //    int y = 3 * WB + BH;
    int y = WB;
    int x = 2*WB;

    output[0] = new Fl_Output
      (x,y, IW, BH, "CAD MODEL");
    output[0]->align(FL_ALIGN_RIGHT);
    output[0]->value("AVAILABLE");

    y += BH;

    butt[1] = new Fl_Check_Button
      (x,y, IW, BH, "Apply to visible entities only");
    butt[1]->type(FL_TOGGLE_BUTTON);
    butt[1]->value(1);

    {
      y += BH / 2;
      Fl_Box* b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
      b->box(FL_ENGRAVED_FRAME);
      b->labeltype(FL_NO_LABEL);
    }

    {
      y += BH;
      Fl_Box *b = new Fl_Box
	(x, y, width, BH, "Generate high order nodes");
      b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    }

    y += BH;

    value[0] = new Fl_Value_Input
      (x,y, IW, BH, "Polynomial Order");
    value[0]->minimum(1);
    value[0]->maximum(10);
    value[0]->step(1);
    value[0]->align(FL_ALIGN_RIGHT);
    value[0]->value(meshOrder);

    y += BH;

    butt[0] = new Fl_Check_Button
      (x,y, IW, BH, "Use Incomplete Elements");
    butt[0]->type(FL_TOGGLE_BUTTON);
    butt[0]->value(!complete);
    butt[0]->callback(change_completeness_cb);

    y += BH;


    butt[2] = new Fl_Check_Button
      (x,y, IW, BH, "Generate curvilinear elements");
    butt[2]->type(FL_TOGGLE_BUTTON);
    butt[2]->value(1);

    push[0] = new Fl_Button
      (x+1.9*IW, y, (int)(1.2*BB), BH, "Apply");
    push[0]->callback(highordertools_runp_cb);


  //   g->end();
  //   Fl_Group::current()->resizable(g);
  // }
  // {
  //   Fl_Group *g = new Fl_Group
  //     (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Optimize");


    {
      y += BH / 2;
      Fl_Box* b = new Fl_Box(x, y + BH - WB, width - 4 * WB, 2);
      b->box(FL_ENGRAVED_FRAME);
      b->labeltype(FL_NO_LABEL);
    }

    {
      y += BH;
      Fl_Box *b = new Fl_Box
	(x, y, width, BH, "Optimization");
      b->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
    }
    {
      y += BH;
      
      value[1] = new Fl_Value_Input
	(x,y, IW/2.0, BH);
      value[1]->minimum(0);
      value[1]->maximum(1);
      value[1]->step(.01);
      value[1]->align(FL_ALIGN_RIGHT);
      value[1]->value(0.1);

      value[8] = new Fl_Value_Input
	(x+IW/2.0,y, IW/2.0, BH, "Jacobian Range");
      value[8]->minimum(1);
      value[8]->maximum(10);
      value[8]->step(.01);
      value[8]->align(FL_ALIGN_RIGHT);
      value[8]->value(2);
      
      y += 1.2*BH;
      value[2] = new Fl_Value_Input
	(x,y, IW, BH, "Number of Layers");
      value[2]->minimum(1);
      value[2]->maximum(20);
      value[2]->step(1);
      value[2]->align(FL_ALIGN_RIGHT);
      value[2]->value(6);

      y += 1.2*BH;
      value[7] = new Fl_Value_Input
	(x,y, IW, BH, "Distance Factor");
      value[7]->minimum(1);
      value[7]->maximum(20000);
      value[7]->step(1);
      value[7]->align(FL_ALIGN_RIGHT);
      value[7]->value(12);

    }
    {

      static Fl_Menu_Item menu_method[] = {
        {"Optimization", 0, 0, 0},
        {"ElasticAnalogy", 0, 0, 0},
        {0}
      };

      y += BH;
      choice[2] = new Fl_Choice
        (x,y, IW, BH, "Algorithm");
      choice[2]->align(FL_ALIGN_RIGHT);
      choice[2]->menu(menu_method);
      choice[2]->callback(chooseopti_cb);      
    }
    {
      static Fl_Menu_Item menu_objf[] = {
        {"CAD + FIXBND", 0, 0, 0},
        {"CAD + FREEBND", 0, 0, 0},
        {"MESH ONLY", 0, 0, 0},
        {0}
      };

      
      static Fl_Menu_Item menu_strategy[] = {
        {"GLOBAL", 0, 0, 0},
        {"BLOBS ", 0, 0, 0},
        {0}
      };
      
      y += BH;
      choice[0] = new Fl_Choice
        (x,y, IW, BH, "Objective Function");
      choice[0]->menu(menu_objf);
      choice[0]->align(FL_ALIGN_RIGHT);
      

      y += BH;
      choice[1] = new Fl_Choice
        (x,y, IW, BH, "Strategy");
      choice[1]->menu(menu_strategy);
      choice[1]->align(FL_ALIGN_RIGHT);
      

      y += 1.2*BH;
      value[5] = new Fl_Value_Input
	(x,y, IW, BH, "W fixed");
      value[5]->align(FL_ALIGN_RIGHT);
      value[5]->value(1.e+5);

      value[6] = new Fl_Value_Input
	(x+IW*1.5,y, IW, BH, "W free");
      value[6]->align(FL_ALIGN_RIGHT);
      value[6]->value(1.e+2);

      y += 1.2*BH;
      value[3] = new Fl_Value_Input
	(x,y, IW, BH, "Maximum nb. of Iterations");
      value[3]->minimum(1);
      value[3]->maximum(10000);
      value[3]->step(10);
      value[3]->align(FL_ALIGN_RIGHT);
      value[3]->value(300);


      y += 1.2*BH;
      value[4] = new Fl_Value_Input
	(x,y, IW, BH, "Tolerance");
      value[4]->minimum(1.e-12);
      value[4]->maximum(0.1);
      value[4]->step(1.e-5);
      value[4]->align(FL_ALIGN_RIGHT);
      value[4]->value(1.e-4);
      
      push[1] = new Fl_Button
	(x+1.9*IW, y, (int)(1.2*BB), BH, "Apply");
      push[1]->callback(highordertools_runelas_cb);      

    }
    
    y += 1.5*BH;
    messages = new Fl_Browser
            (x,y, width-2*x, height - y - 2*WB);
    messages->box(FL_THIN_DOWN_BOX);
    messages->textfont(FL_COURIER);
    messages->textsize(FL_NORMAL_SIZE - 1);
    messages->type(FL_MULTI_BROWSER);
    //    messages->callback(message_browser_cb, this);
  }

  //  win->resizable(o);
  win->position(CTX::instance()->hotPosition[0], CTX::instance()->hotPosition[1]);
  win->end();
  FL_NORMAL_SIZE += deltaFontSize;
}

void highOrderToolsWindow::show(bool redrawOnly)
{
  getMeshInfoForHighOrder (GModel::current(),meshOrder,complete, CAD); 

  if(win->shown() && redrawOnly)
    win->redraw();
  else {
    value[0]->value(meshOrder);
    butt[0]->value(!complete);
    if (CAD)output[0]->value("AVAILABLE");
    else {
      output[0]->value("NOT AVAILABLE");
      choice[0]->value(2); 
    }
    win->show();
  }
}
void highordertools_cb(Fl_Widget *w, void *data)
{
  // get the visibility info from the model, and update the browser
  // accordingly
  const char *str = (const char*)data;
  if(str && !strcmp(str, "redraw_only"))
    FlGui::instance()->highordertools->show(true);
  else
    FlGui::instance()->highordertools->show(false);
}
