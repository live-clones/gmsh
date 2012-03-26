// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include "FlGui.h"
#include "drawContext.h"
#include "statisticsWindow.h"
#include "paletteWindow.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "Generator.h"
#include "Context.h"
#include "OS.h"
#include "Field.h"

void statistics_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->stats->show();
}

static void statistics_update_cb(Fl_Widget *w, void *data)
{
  FlGui::instance()->stats->compute(true);
}

static void statistics_histogram_cb(Fl_Widget *w, void *data)
{
  std::string name((const char*)data);

  std::vector<double> x, y;

  if(name == "Gamma2D"){
    for(int i = 0; i < 100; i++){
      x.push_back((double)i / 99);
      y.push_back(FlGui::instance()->stats->quality[0][i]);
    }
    new PView("Gamma", "# Elements", x, y);
  }
  else if(name == "Eta2D"){
    for(int i = 0; i < 100; i++){
      x.push_back((double)i / 99);
      y.push_back(FlGui::instance()->stats->quality[1][i]);
    }
    new PView("Eta", "# Elements", x, y);
  }
  else if(name == "Rho2D"){
    for(int i = 0; i < 100; i++){
      x.push_back((double)i / 99);
      y.push_back(FlGui::instance()->stats->quality[2][i]);
    }
    new PView("Rho", "# Elements", x, y);
  }
  else if(name == "Disto2D"){
    for(int i = 0; i < 100; i++){
      x.push_back((double)i / 99);
      y.push_back(FlGui::instance()->stats->quality[3][i]);
    }
    new PView("Disto", "# Elements", x, y);
  }
  else{

    std::vector<GEntity*> entities_;
    GModel::current()->getEntities(entities_);
    std::map<int, std::vector<double> > d;
    for(unsigned int i = 0; i < entities_.size(); i++){
      if(entities_[i]->dim() < 2) continue;
      for(unsigned int j = 0; j < entities_[i]->getNumMeshElements(); j++){
	MElement *e = entities_[i]->getMeshElement(j);
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

  FlGui::instance()->updateViews();
  drawContext::global()->draw();
}

statisticsWindow::statisticsWindow(int deltaFontSize)
{
  FL_NORMAL_SIZE -= deltaFontSize;

  int num = 0;
  int width = 26 * FL_NORMAL_SIZE;
  int height = 5 * WB + 18 * BH;

  win = new paletteWindow
    (width, height, CTX::instance()->nonModalWindows ? true : false, "Statistics");
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

  for(int i = 0; i < num; i++) {
    value[i]->align(FL_ALIGN_RIGHT);
    value[i]->value(0);
  }

  {
    memUsage = new Fl_Box(WB, height - BH - WB, width / 2, BH, "");
    memUsage->align(FL_ALIGN_INSIDE);

    Fl_Return_Button *o = new Fl_Return_Button
      (width - BB - WB, height - BH - WB, BB, BH, "Update");
    o->callback(statistics_update_cb);
  }

  win->position(CTX::instance()->statPosition[0], CTX::instance()->statPosition[1]);
  win->end();

  FL_NORMAL_SIZE += deltaFontSize;
}

void statisticsWindow::compute(bool elementQuality)
{
#if 0
  {
    // MINIMUM ANGLES
    double minAngle = 120.0;
    double meanAngle = 0.0;
    int count = 0;
    std::vector<GEntity*> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->dim() < 2) continue;
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	MElement *e = entities[i]->getMeshElement(j);
	double angle = e->angleShapeMeasure();
	minAngle = std::min(minAngle, angle);
	meanAngle += angle;
	count++;
      }
    }
    meanAngle  = meanAngle / count;
    printf("Angles = min=%g av=%g \n", minAngle, meanAngle);
  }

  {
    // MESH DEGREE VERTICES
    std::vector<GEntity*> entities;
    std::set<MEdge, Less_Edge> edges;
    GModel::current()->getEntities(entities);
    std::map<MVertex*, int > vert2Deg;
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->dim() < 2 ) continue;
      //      if(entities[i]->tag() < 100) continue;
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	MElement *e =  entities[i]->getMeshElement(j);
	for(unsigned int k = 0; k < e->getNumEdges(); k++){
	  edges.insert(e->getEdge(k));
	}
	for(unsigned int k = 0; k < e->getNumVertices(); k++){
	  MVertex *v = e->getVertex(k);
	  if (v->onWhat()->dim() < 2) continue;
	  std::map<MVertex*, int >::iterator it = vert2Deg.find(v);
	  if (it == vert2Deg.end()) {
	    vert2Deg.insert(std::make_pair(v,1));
	  }
	  else{
	    int nbE = it->second+1;
	    it->second = nbE;
	  }
	}
      }
    }
    int dMin = 10;
    int dMax = 0;
    int d4 = 0;
    int nbElems = vert2Deg.size();
    std::map<MVertex*, int >::const_iterator itmap = vert2Deg.begin();
    for(; itmap !=vert2Deg.end(); itmap++){
      MVertex *v = itmap->first;
      int nbE =  itmap->second;
      dMin = std::min(nbE, dMin);
      dMax = std::max(nbE, dMax);
      if (nbE == 4) d4 += 1;
    }
    if (nbElems > 0)
      printf("Stats degree vertices: dMin=%d , dMax=%d, d4=%g \n",
	     dMin, dMax, (double)d4/nbElems);
    FieldManager *fields = GModel::current()->getFields();
    Field *f = fields->get(fields->background_field);
    int nbEdges = edges.size();
    printf("nb edges =%d \n", nbEdges);
    if(system("rm qualEdges.txt"));
    FILE *fp = fopen("qualEdges.txt", "w");
    std::vector<int> qualE;
    int nbS = 50;
    qualE.resize(nbS);
    if(fields.getBackgroundField() > 0){
      std::set<MEdge, Less_Edge>::iterator it = edges.begin();
      double sum = 0;
      for (; it !=edges.end();++it){
	MVertex *v0 = it->getVertex(0);
	MVertex *v1 = it->getVertex(1);
	double l = sqrt((v0->x()-v1->x())*(v0->x()-v1->x())+
			(v0->y()-v1->y())*(v0->y()-v1->y())+
			(v0->z()-v1->z())*(v0->z()-v1->z()));
	double lf =  (*f)(0.5*(v0->x()+v1->x()), 0.5*(v0->y()+v1->y()),
			  0.5*(v0->z()+v1->z()),v0->onWhat());
	double el = l/lf;
	int index = (int) ceil(el*nbS*0.5);
	qualE[index]+= 1;
	double e = (l>lf) ? lf/l : l/lf;
	sum += e - 1.0;
      }
      double tau = exp ((1./edges.size()) * sum);
      printf("N edges = %d tau = %g\n",(int)edges.size(),tau);

      double ibegin = 2./(2*nbS);
      double inext = 2./nbS;
      for (int i= 0; i< qualE.size(); i++){
	fprintf(fp, "0 0 0 0 %g 0 0 %g \n", ibegin+i*inext , (double)qualE[i]/nbEdges);
      }

    }
    fclose(fp);
  }
  {
    std::vector<GEntity*> entities;
    std::set<MEdge, Less_Edge> edges;
    GModel::current()->getEntities(entities);
    std::map<MVertex*, int > vert2Deg;
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->dim() < 2 ) continue;
      if(entities[i]->tag() != 10) continue;
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
	MElement *e =  entities[i]->getMeshElement(j);
	for(unsigned int k = 0; k < e->getNumEdges(); k++){
	  edges.insert(e->getEdge(k));
	}
	for(unsigned int k = 0; k < e->getNumVertices(); k++){
	  MVertex *v = e->getVertex(k);
	  if (v->onWhat()->dim() < 2) continue;
	  std::map<MVertex*, int >::iterator it = vert2Deg.find(v);
	  if (it == vert2Deg.end()){
	    vert2Deg.insert(std::make_pair(v,1));
	  }
	  else{
	    int nbE = it->second+1;
	    it->second = nbE;
	  }
	}
      }
    }
    int dMin = 10;
    int dMax = 0;
    int d4 = 0;
    int nbElems = vert2Deg.size();
    std::map<MVertex*, int >::const_iterator itmap = vert2Deg.begin();
    for(; itmap !=vert2Deg.end(); itmap++){
      MVertex *v = itmap->first;
      int nbE =  itmap->second;
      dMin = std::min(nbE, dMin);
      dMax = std::max(nbE, dMax);
      if (nbE == 4) d4 += 1;
    }
    if (nbElems > 0) printf("Stats degree vertices: dMin=%d , dMax=%d, d4=%g \n",
			    dMin, dMax, (double)d4/nbElems);
    FieldManager *fields = GModel::current()->getFields();
    Field *f = fields->get(fields.getBackgroundField());
    int nbEdges = edges.size();
    if(system("rm qualEdges.txt"));
    FILE *fp = fopen("qualEdges.txt", "w");
    std::vector<int> qualE;
    int nbS = 50;
    qualE.resize(nbS);
    if(fields.getBackgroundField() > 0){
      std::set<MEdge, Less_Edge>::iterator it = edges.begin();
      double sum = 0;
      for (; it !=edges.end();++it){
	MVertex *v0 = it->getVertex(0);
	MVertex *v1 = it->getVertex(1);
	double l = sqrt((v0->x()-v1->x())*(v0->x()-v1->x())+
			(v0->y()-v1->y())*(v0->y()-v1->y())+
			(v0->z()-v1->z())*(v0->z()-v1->z()));
	double lf =  (*f)(0.5*(v0->x()+v1->x()), 0.5*(v0->y()+v1->y()),
			  0.5*(v0->z()+v1->z()),v0->onWhat());
	double el = l/lf;
	int index = (int) ceil(el*nbS*0.5);
	qualE[index]+= 1;
	double e = (l>lf) ? lf/l : l/lf;
	sum += e - 1.0;
      }
      double tau = exp ((1./edges.size()) * sum);
      double ibegin = 2./(2*nbS);
      double inext = 2./nbS;
      for (int i= 0; i< qualE.size(); i++){
	fprintf(fp, "0 0 0 0 %g 0 0 %g \n", ibegin+i*inext , (double)qualE[i]/nbEdges);
      }
    }
    fclose(fp);
  }
#endif

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

  static char mem[256];
  long m = GetMemoryUsage();
  if(m){
    sprintf(mem, "Memory usage: %gMb", GetMemoryUsage()/1024./1024.);
    memUsage->label(mem);
  }
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
