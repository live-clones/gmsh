// $Id: CutParametric.cpp,v 1.4 2004-06-24 16:02:21 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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
  {GMSH_FULLRC, "minU", NULL, 0.},
  {GMSH_FULLRC, "maxU", NULL, 2*M_PI},
  {GMSH_FULLRC, "nPointsU", NULL, 360.},
  //{GMSH_FULLRC, "minV", NULL, 0.},
  //{GMSH_FULLRC, "maxV", NULL, 1.},
  //{GMSH_FULLRC, "nPointsV", NULL, 0.},
  //{GMSH_FULLRC, "minW", NULL, 0.},
  //{GMSH_FULLRC, "maxW", NULL, 1.},
  //{GMSH_FULLRC, "nPointsW", NULL, 0.},
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
  strcpy(name, "Cut parametric");
}

void GMSH_CutParametricPlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuzaine@acm.caltech.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutParametric) cuts a triangle/tetrahedron\n"
	 "scalar view `iView' with the parametric function\n"
	 "(`X'(u), `Y'(u), `Z'(u)), using `nPointsU' values of\n"
	 "the parameter u in [`minU', `maxU']. If `iView' < 0,\n"
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

Post_View *GMSH_CutParametricPlugin::execute(Post_View * v)
{
  int iView = (int)CutParametricOptions_Number[3].def;

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

  Post_View *v2 = BeginView(1);
  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);
  OctreePost o(v1);
  double *res = new double[9*v1->NbTimeStep];

  for(int i = 0; i < nbU; ++i){
    double u = minU + (double)(i)/(double)(nbU-1) * (maxU - minU);
    char *names[] = { "u" };
    double values[] = { u };
    double x = evaluator_evaluate(fx, sizeof(names)/sizeof(names[0]), names, values);
    double y = evaluator_evaluate(fy, sizeof(names)/sizeof(names[0]), names, values);
    double z = evaluator_evaluate(fz, sizeof(names)/sizeof(names[0]), names, values);
    o.searchScalar(x, y, z, res);
    List_Add(v2->SP, &x);
    List_Add(v2->SP, &y);
    List_Add(v2->SP, &z);
    for(int k = 0; k < v1->NbTimeStep; ++k)
      List_Add(v2->SP, &res[k]);	      
    v2->NbSP++;
  }

  char name[1024], filename[1024];
  sprintf(name, "%s_CutParametric", v1->Name);
  sprintf(filename, "%s_CutParametric.pos", v1->Name);
  EndView(v2, 1, filename, name);

  evaluator_destroy(fx);
  evaluator_destroy(fy);
  evaluator_destroy(fz);
  delete [] res;

  return v2;

#endif
}
