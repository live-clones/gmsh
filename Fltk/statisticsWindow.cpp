// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "GUI.h"
#include "Draw.h"
#include "statisticsWindow.h"
#include "shortcutWindow.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "Generator.h"
#include "Context.h"

extern Context_T CTX;

void statistics_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->stats->show();
}

static void statistics_update_cb(Fl_Widget *w, void *data)
{
  GUI::instance()->stats->compute(true);
}

static void statistics_histogram_cb(Fl_Widget *w, void *data)
{
  std::string name((const char*)data);

  std::vector<double> x, y;

  if(name == "Gamma2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[0][i]);
    new PView("Gamma", "# Elements", x, y);
  }
  else if(name == "Eta2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[1][i]);
    new PView("Eta", "# Elements", x, y);
  }
  else if(name == "Rho2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[2][i]);
    new PView("Rho", "# Elements", x, y);
  }
  else if(name == "Disto2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[3][i]);
    new PView("Disto", "# Elements", x, y);
  }
  else{
    std::vector<GEntity*> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->dim() < 2) continue;
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(name == "Gamma3D")
          d[e->getNum()].push_back(e->gammaShapeMeasure());
        else if(name == "Eta3D")
          d[e->getNum()].push_back(e->etaShapeMeasure());
        else if(name == "Rho3D")
          d[e->getNum()].push_back(e->rhoShapeMeasure());
        else
          d[e->getNum()].push_back(e->distoShapeMeasure());
      }
    }
    name.resize(name.size() - 2);
    new PView(name, "ElementData", GModel::current(), d);
  }

  GUI::instance()->updateViews();
  Draw();
}

statisticsWindow::statisticsWindow()
{
  int i, num = 0;
  int width = 26 * FL_NORMAL_SIZE;
  int height = 5 * WB + 18 * BH;

  win = new dialogWindow(width, height, CTX.non_modal_windows, "Statistics");
  win->box(GMSH_WINDOW_BOX);
  {
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width - 2 * WB, height - 3 * WB - BH);
    {
      group[0] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Geometry");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 1 * BH, IW, BH, "Points");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 2 * BH, IW, BH, "Lines");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 3 * BH, IW, BH, "Surfaces");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 4 * BH, IW, BH, "Volumes");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 5 * BH, IW, BH, "Physical groups");
      group[0]->end();
    }
    {
      group[1] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Mesh");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 1 * BH, IW, BH, "Nodes on Lines");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 2 * BH, IW, BH, "Nodes on surfaces");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 3 * BH, IW, BH, "Nodes in volumes");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 4 * BH, IW, BH, "Triangles");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadrangles");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 6 * BH, IW, BH, "Tetrahedra");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 7 * BH, IW, BH, "Hexahedra");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 8 * BH, IW, BH, "Prisms");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 9 * BH, IW, BH, "Pyramids");

      value[num++] = new Fl_Output(2 * WB, 2 * WB + 10 * BH, IW, BH, "Time for 1D mesh");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 11 * BH, IW, BH, "Time for 2D mesh");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 12 * BH, IW, BH, "Time for 3D mesh");

      value[num] = new Fl_Output(2 * WB, 2 * WB + 13 * BH, IW, BH, "Gamma"); 
      value[num]->tooltip("~ inscribed_radius / circumscribed_radius"); num++;
      value[num] = new Fl_Output(2 * WB, 2 * WB + 14 * BH, IW, BH, "Eta");
      value[num]->tooltip("~ volume^(2/3) / sum_edge_length^2"); num++;
      value[num] = new Fl_Output(2 * WB, 2 * WB + 15 * BH, IW, BH, "Rho");
      value[num]->tooltip("~ min_edge_length / max_edge_length"); num++;
      value[num] = new Fl_Output(2 * WB, 2 * WB + 16 * BH, IW, BH, "Disto");
      value[num]->tooltip("~ min (J0/J, J/J0)"); num++;

      for(int i = 0; i < 4; i++){
        int ww = 3 * FL_NORMAL_SIZE;
        new Fl_Box
          (FL_NO_BOX, width - 3 * ww - 2 * WB, 2 * WB + (13 + i) * BH, ww, BH, "Plot:");
        butt[2 * i] = new Fl_Button
          (width - 2 * ww - 2 * WB, 2 * WB + (13 + i) * BH, ww, BH, "2D");
        butt[2 * i + 1] = new Fl_Button
          (width - ww - 2 * WB, 2 * WB + (13 + i) * BH, ww, BH, "3D");
      }
      butt[0]->callback(statistics_histogram_cb, (void *)"Gamma2D");
      butt[1]->callback(statistics_histogram_cb, (void *)"Gamma3D");
      butt[2]->callback(statistics_histogram_cb, (void *)"Eta2D");
      butt[3]->callback(statistics_histogram_cb, (void *)"Eta3D");
      butt[4]->callback(statistics_histogram_cb, (void *)"Rho2D");
      butt[5]->callback(statistics_histogram_cb, (void *)"Rho3D");
      butt[6]->callback(statistics_histogram_cb, (void *)"Disto2D");
      butt[7]->callback(statistics_histogram_cb, (void *)"Disto3D");

      group[1]->end();
    }
    {
      group[2] = new Fl_Group
        (WB, WB + BH, width - 2 * WB, height - 3 * WB - 2 * BH, "Post-processing");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 1 * BH, IW, BH, "Views");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 2 * BH, IW, BH, "Points");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 3 * BH, IW, BH, "Lines");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 4 * BH, IW, BH, "Triangles");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 5 * BH, IW, BH, "Quadrangles");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 6 * BH, IW, BH, "Tetrahedra");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 7 * BH, IW, BH, "Hexahedra");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 8 * BH, IW, BH, "Prisms");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 9 * BH, IW, BH, "Pyramids");
      value[num++] = new Fl_Output(2 * WB, 2 * WB + 10 * BH, IW, BH, "Strings");
      group[2]->end();
    }
    o->end();
  }

  for(i = 0; i < num; i++) {
    value[i]->align(FL_ALIGN_RIGHT);
    value[i]->value(0);
  }

  {
    Fl_Return_Button *o = new Fl_Return_Button
      (width - 2 * BB - 2 * WB, height - BH - WB, BB, BH, "Update");
    o->callback(statistics_update_cb);
  }
  {
    Fl_Button *o = new Fl_Button(width - BB - WB, height - BH - WB, BB, BH, "Cancel");
    o->callback(hide_cb, (void *)win);
  }
  
  win->position(CTX.stat_position[0], CTX.stat_position[1]);
  win->end();
}

void statisticsWindow::compute(bool elementQuality)
{
  int num = 0;
  static double s[50];
  static char label[50][256];

  if(elementQuality)
    GetStatistics(s, quality);
  else
    GetStatistics(s);

  // geom
  sprintf(label[num], "%g", s[0]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[1]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[2]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[3]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[45]); value[num]->value(label[num]); num++;

  // mesh
  sprintf(label[num], "%g", s[4]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[5]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[6]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[7]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[8]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[9]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[10]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[11]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[12]); value[num]->value(label[num]); num++;

  sprintf(label[num], "%g", s[13]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[14]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[15]); value[num]->value(label[num]); num++;

  if(!elementQuality){
    for(int i = 0; i < 8; i += 2) butt[i]->deactivate();
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "Press Update");
    value[num]->deactivate();
    value[num]->value(label[num]); num++;
  }
  else{
    for(int i = 0; i < 8; i += 2) butt[i]->activate();
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[17], s[18], s[19]);
    value[num]->activate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[20], s[21], s[22]);
    value[num]->activate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[23], s[24], s[25]);
    value[num]->activate();
    value[num]->value(label[num]); num++;
    sprintf(label[num], "%.4g (%.4g->%.4g)", s[46], s[47], s[48]);
    value[num]->activate();
    value[num]->value(label[num]); num++;
  }

  // post
  sprintf(label[num], "%g", s[26]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[27]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[28]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[29]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[30]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[31]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[32]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[33]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[34]); value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[35]); value[num]->value(label[num]); num++;
}

void statisticsWindow::show()
{
  if(!win->shown()) 
    compute(false);

  for(int i = 0; i < 3; i++)
    group[i]->hide();
  
  if(GModel::current()->getMeshStatus(true) > 0)
    group[1]->show();
  else if(PView::list.size())
    group[2]->show();
  else
    group[0]->show();

  win->show();
}
