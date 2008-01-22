// $Id: CutParametric.cpp,v 1.23 2008-01-22 20:44:36 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include "OctreePost.h"
#include "CutParametric.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

StringXNumber CutParametricOptions_Number[] = {
  {GMSH_FULLRC, "MinU", GMSH_CutParametricPlugin::callbackMinU, 0.},
  {GMSH_FULLRC, "MaxU", GMSH_CutParametricPlugin::callbackMaxU, 2*3.1416},
  {GMSH_FULLRC, "nPointsU", GMSH_CutParametricPlugin::callbackN, 360.},
  {GMSH_FULLRC, "ConnectPoints", GMSH_CutParametricPlugin::callbackConnect, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString CutParametricOptions_String[] = {
  {GMSH_FULLRC, "X", GMSH_CutParametricPlugin::callbackX, "0 + 1 * Cos(u)"},
  {GMSH_FULLRC, "Y", GMSH_CutParametricPlugin::callbackY, "0 + 1 * Sin(u)"},
  {GMSH_FULLRC, "Z", GMSH_CutParametricPlugin::callbackZ, "0"},
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutParametricPlugin()
  {
    return new GMSH_CutParametricPlugin();
  }
}


GMSH_CutParametricPlugin::GMSH_CutParametricPlugin()
{
  ;
}

static double getU(int i)
{
  double minU = CutParametricOptions_Number[0].def;
  double maxU = CutParametricOptions_Number[1].def;
  int nbU = (int)CutParametricOptions_Number[2].def;
  
  if(nbU == 1)
    return minU;
  else
    return minU + (double)(i)/(double)(nbU-1) * (maxU - minU);
}

int GMSH_CutParametricPlugin::recompute = 1;
std::vector<double> GMSH_CutParametricPlugin::x;
std::vector<double> GMSH_CutParametricPlugin::y;
std::vector<double> GMSH_CutParametricPlugin::z;

int GMSH_CutParametricPlugin::fillXYZ()
{
#if !defined(HAVE_MATH_EVAL)
  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
  return 0;
#else
  char *exprx = CutParametricOptions_String[0].def;
  char *expry = CutParametricOptions_String[1].def;
  char *exprz = CutParametricOptions_String[2].def;
  int nbU = (int)CutParametricOptions_Number[2].def;

  x.resize(nbU);
  y.resize(nbU);
  z.resize(nbU);
  void *fx = evaluator_create(exprx);
  if(!fx){
    Msg(GERROR, "Invalid expression '%s'", exprx);
    return 0;
  }
  void *fy = evaluator_create(expry);
  if(!fy){
    evaluator_destroy(fx);
    Msg(GERROR, "Invalid expression '%s'", expry);
    return 0;
  }
  void *fz = evaluator_create(exprz);
  if(!fz){
    Msg(GERROR, "Invalid expression '%s'", exprz);
    evaluator_destroy(fx);
    evaluator_destroy(fy);
    return 0;
  }
  for(int i = 0; i < nbU; ++i){
    char *names[] = { "u" };
    double values[] = { getU(i) };
    x[i] = evaluator_evaluate(fx, sizeof(names)/sizeof(names[0]), names, values);
    y[i] = evaluator_evaluate(fy, sizeof(names)/sizeof(names[0]), names, values);
    z[i] = evaluator_evaluate(fz, sizeof(names)/sizeof(names[0]), names, values);
  }
  return 1;
#endif
}

void GMSH_CutParametricPlugin::draw()
{
#if defined(HAVE_FLTK)
  if(recompute){
    fillXYZ();
    recompute = 0;
  }
  glColor4ubv((GLubyte *) & CTX.color.fg);
  if(CutParametricOptions_Number[3].def && x.size() > 1){
    glBegin(GL_LINES);
    for(unsigned int i = 1; i < x.size(); ++i){
      glVertex3d(x[i-1], y[i-1], z[i-1]);
      glVertex3d(x[i], y[i], z[i]);
    }
    glEnd();
  }
  else{
    for(unsigned int i = 0; i < x.size(); ++i)
      Draw_Sphere(CTX.point_size, x[i], y[i], z[i], 1);
  }
#endif
}

double GMSH_CutParametricPlugin::callback(int num, int action, double value, double *opt,
					  double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  recompute = 1;
  DrawPlugin(draw);
#endif
  return 0.;
}

char *GMSH_CutParametricPlugin::callbackStr(int num, int action, char *value, char **opt)
{
  *opt = value;
#if defined(HAVE_FLTK)
  recompute = 1;
  DrawPlugin(draw);
#endif
  return NULL;
}

double GMSH_CutParametricPlugin::callbackMinU(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[0].def,
		  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackMaxU(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[1].def,
		  0.01, 0., 10.);
}

double GMSH_CutParametricPlugin::callbackN(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[2].def,
		  1, 1, 1000);
}

double GMSH_CutParametricPlugin::callbackConnect(int num, int action, double value)
{
  return callback(num, action, value, &CutParametricOptions_Number[3].def,
		  1, 0, 1);
}

char *GMSH_CutParametricPlugin::callbackX(int num, int action, char *value)
{
  return callbackStr(num, action, value, &CutParametricOptions_String[0].def);
}

char *GMSH_CutParametricPlugin::callbackY(int num, int action, char *value)
{
  return callbackStr(num, action, value, &CutParametricOptions_String[1].def);
}

char *GMSH_CutParametricPlugin::callbackZ(int num, int action, char *value)
{
  return callbackStr(num, action, value, &CutParametricOptions_String[2].def);
}

void GMSH_CutParametricPlugin::getName(char *name) const
{
  strcpy(name, "Cut Parametric");
}

void GMSH_CutParametricPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutParametric) cuts the view `iView' with\n"
	 "the parametric function (`X'(u), `Y'(u), `Z'(u)),\n"
	 "using `nPointsU' values of the parameter u in\n"
	 "[`MinU', `MaxU']. If `ConnectPoints' is set, the\n"
	 "plugin creates line elements; otherwise, the\n"
	 "plugin generates points. If `iView' < 0, the plugin\n"
	 "is run on the current view.\n"
	 "\n"
	 "Plugin(CutParametric) creates one new view.\n");
}

int GMSH_CutParametricPlugin::getNbOptions() const
{
  return sizeof(CutParametricOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutParametricPlugin::getOption(int iopt)
{
  return &CutParametricOptions_Number[iopt];
}

int GMSH_CutParametricPlugin::getNbOptionsStr() const
{
  return sizeof(CutParametricOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_CutParametricPlugin::getOptionStr(int iopt)
{
  return &CutParametricOptions_String[iopt];
}

void GMSH_CutParametricPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutParametric failed...");
}

static void addInView(int connect, int i, int nbcomp, int nbtime,
		      double x0, double y0, double z0, double *res0,
		      double x, double y, double z, double *res,
		      List_T *P, int *nP, List_T *L, int *nL)
{
  if(connect){
    if(i){
      List_Add(L, &x0); List_Add(L, &x);
      List_Add(L, &y0); List_Add(L, &y);
      List_Add(L, &z0); List_Add(L, &z);
      for(int k = 0; k < nbtime; ++k){
	for(int l = 0; l < nbcomp; ++l)
	  List_Add(L, &res0[nbcomp*k+l]); 
	for(int l = 0; l < nbcomp; ++l)
	  List_Add(L, &res[nbcomp*k+l]);
      }
      (*nL)++;
    }
  }
  else{
    List_Add(P, &x);
    List_Add(P, &y);
    List_Add(P, &z);
    for(int k = 0; k < nbtime; ++k)
      for(int l = 0; l < nbcomp; ++l)
	List_Add(P, &res[nbcomp*k+l]);
    (*nP)++;
  }
}

PView *GMSH_CutParametricPlugin::execute(PView *v)
{
  int iView = (int)CutParametricOptions_Number[4].def;

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(!fillXYZ())
    return v;

  int nbU = (int)CutParametricOptions_Number[2].def;
  int connect = (int)CutParametricOptions_Number[3].def;
  if(nbU < 2) connect = 0;

  OctreePost o(v1);

  PView *v2 = new PView(true);

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  double *res0 = new double[9 * data1->getNumTimeSteps()];
  double *res1 = new double[9 * data1->getNumTimeSteps()];
  double x0 = 0., y0 = 0., z0 = 0., x1 = 0., y1 = 0., z1 = 0.;

  for(int k = 0; k < 9 * data1->getNumTimeSteps(); ++k) res0[k] = res1[k] = 0.;

  for(int i = 0; i < nbU; ++i){
    if(i && connect){
      x0 = x1;
      y0 = y1;
      z0 = z1;
      for(int k = 0; k < 9 * data1->getNumTimeSteps(); ++k) res0[k] = res1[k];
    }

    x1 = x[i];
    y1 = y[i];
    z1 = z[i];

    if(data1->NbST || data1->NbSQ || data1->NbSS || 
       data1->NbSH || data1->NbSI || data1->NbSY){
      o.searchScalar(x1, y1, z1, res1);
      addInView(connect, i, 1, data1->getNumTimeSteps(), 
		x0, y0, z0, res0, x1, y1, z1, res1,
		data2->SP, &data2->NbSP, data2->SL, &data2->NbSL);
    }
    if(data1->NbVT || data1->NbVQ || data1->NbVS || 
       data1->NbVH || data1->NbVI || data1->NbVY){
      o.searchVector(x1, y1, z1, res1);
      addInView(connect, i, 3, data1->getNumTimeSteps(), 
		x0, y0, z0, res0, x1, y1, z1, res1,
		data2->VP, &data2->NbVP, data2->VL, &data2->NbVL);
    }
    if(data1->NbTT || data1->NbTQ || data1->NbTS ||
       data1->NbTH || data1->NbTI || data1->NbTY){
      o.searchTensor(x1, y1, z1, res1);
      addInView(connect, i, 9, data1->getNumTimeSteps(),
		x0, y0, z0, res0, x1, y1, z1, res1,
		data2->TP, &data2->NbTP, data2->TL, &data2->NbTL);
    }
  }
    
  delete [] res0;
  delete [] res1;

  data2->setName(data1->getName() + "_CutParametric");
  data2->setFileName(data1->getName() + "_CutParametric.pos");
  data2->finalize();

  return v2;
}
