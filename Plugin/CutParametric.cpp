// $Id: CutParametric.cpp,v 1.11 2005-03-02 07:49:41 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "OctreePost.h"
#include "CutParametric.h"
#include "List.h"
#include "Context.h"
#include <math.h>

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

StringXNumber CutParametricOptions_Number[] = {
  {GMSH_FULLRC, "MinU", NULL, 0.},
  {GMSH_FULLRC, "MaxU", NULL, 2*M_PI},
  {GMSH_FULLRC, "nPointsU", NULL, 360.},
  //{GMSH_FULLRC, "MinV", NULL, 0.},
  //{GMSH_FULLRC, "MaxV", NULL, 1.},
  //{GMSH_FULLRC, "nPointsV", NULL, 0.},
  //{GMSH_FULLRC, "MinW", NULL, 0.},
  //{GMSH_FULLRC, "MaxW", NULL, 1.},
  //{GMSH_FULLRC, "nPointsW", NULL, 0.},
  {GMSH_FULLRC, "ConnectPoints", NULL, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString CutParametricOptions_String[] = {
  {GMSH_FULLRC, "X", NULL, "0 + 1 * Cos(u)"},
  {GMSH_FULLRC, "Y", NULL, "0 + 1 * Sin(u)"},
  {GMSH_FULLRC, "Z", NULL, "0"},
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

void GMSH_CutParametricPlugin::getName(char *name) const
{
  strcpy(name, "Cut Parametric");
}

void GMSH_CutParametricPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuzaine@acm.caltech.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutParametric) cuts the scalar view `iView'\n"
	 "with the parametric function (`X'(u), `Y'(u), `Z'(u)),\n"
	 "using `nPointsU' values of the parameter u in\n"
	 "[`MinU', `MaxU']. If `ConnectPoints' is set, the\n"
	 "plugin creates scalar line elements; otherwise,\n"
	 "the plugin generates scalar points. If `iView' < 0,\n"
	 "the plugin is run on the current view.\n"
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

Post_View *GMSH_CutParametricPlugin::execute(Post_View * v)
{
  int iView = (int)CutParametricOptions_Number[4].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

#if !defined(HAVE_MATH_EVAL)

  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");
  return v;

#else

  double minU = CutParametricOptions_Number[0].def;
  double maxU = CutParametricOptions_Number[1].def;
  int nbU = (int)CutParametricOptions_Number[2].def;
  int connect = (int)CutParametricOptions_Number[3].def;
  if(nbU < 2) connect = 0;

  char *exprx = CutParametricOptions_String[0].def;
  char *expry = CutParametricOptions_String[1].def;
  char *exprz = CutParametricOptions_String[2].def;

  void *fx = evaluator_create(exprx);
  if(!fx){
    Msg(GERROR, "Invalid expression '%s'", exprx);
    return v;
  }

  void *fy = evaluator_create(expry);
  if(!fy){
    evaluator_destroy(fx);
    Msg(GERROR, "Invalid expression '%s'", expry);
    return v;
  }

  void *fz = evaluator_create(exprz);
  if(!fz){
    evaluator_destroy(fx);
    evaluator_destroy(fy);
    Msg(GERROR, "Invalid expression '%s'", exprz);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);
  OctreePost o(v1);

  Post_View *v2 = BeginView(1);
  double *res0 = new double[9*v1->NbTimeStep];
  double *res = new double[9*v1->NbTimeStep];
  double x = 0., y = 0., z = 0., x0 = 0., y0 = 0., z0 = 0.;

  for(int k = 0; k < 9*v1->NbTimeStep; ++k) res0[k] = res[k] = 0.;

  for(int i = 0; i < nbU; ++i){
    if(i && connect){
      x0 = x;
      y0 = y;
      z0 = z;
      for(int k = 0; k < 9*v1->NbTimeStep; ++k) res0[k] = res[k];
    }

    double u;
    if(nbU == 1 || maxU == minU)
      u = minU;
    else
      u = minU + (double)(i)/(double)(nbU-1) * (maxU - minU);
    char *names[] = { "u" };
    double values[] = { u };
    x = evaluator_evaluate(fx, sizeof(names)/sizeof(names[0]), names, values);
    y = evaluator_evaluate(fy, sizeof(names)/sizeof(names[0]), names, values);
    z = evaluator_evaluate(fz, sizeof(names)/sizeof(names[0]), names, values);

    if(v->NbST || v->NbSQ || v->NbSS || v->NbSH || v->NbSI || v->NbSY){
      o.searchScalar(x, y, z, res);
      addInView(connect, i, 1, v1->NbTimeStep, x0, y0, z0, res0, x, y, z, res,
		v2->SP, &v2->NbSP, v2->SL, &v2->NbSL);
    }
    if(v->NbVT || v->NbVQ || v->NbVS || v->NbVH || v->NbVI || v->NbVY){
      double size;
      o.searchVector(x, y, z, res, &size);
      addInView(connect, i, 3, v1->NbTimeStep, x0, y0, z0, res0, x, y, z, res,
		v2->VP, &v2->NbVP, v2->VL, &v2->NbVL);
    }
    if(v->NbTT || v->NbTQ || v->NbTS || v->NbTH || v->NbTI || v->NbTY){
      o.searchTensor(x, y, z, res);
      addInView(connect, i, 9, v1->NbTimeStep, x0, y0, z0, res0, x, y, z, res,
		v2->TP, &v2->NbTP, v2->TL, &v2->NbTL);
    }
  }

  char name[1024], filename[1024];
  sprintf(name, "%s_CutParametric", v1->Name);
  sprintf(filename, "%s_CutParametric.pos", v1->Name);
  EndView(v2, 1, filename, name);

  evaluator_destroy(fx);
  evaluator_destroy(fy);
  evaluator_destroy(fz);
  delete [] res0;
  delete [] res;

  return v2;

#endif
}
