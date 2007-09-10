// $Id: Evaluate.cpp,v 1.30 2007-09-10 04:47:08 geuzaine Exp $
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

#include "Plugin.h"
#include "Evaluate.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

extern Context_T CTX;

StringXNumber EvaluateOptions_Number[] = {
  {GMSH_FULLRC, "Component", NULL, -1.},
  {GMSH_FULLRC, "TimeStep", NULL, -1.},
  {GMSH_FULLRC, "ExternalView", NULL, -1.},
  {GMSH_FULLRC, "ExternalTimeStep", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString EvaluateOptions_String[] = {
  {GMSH_FULLRC, "Expression", NULL, "v0*Sin(x)"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterEvaluatePlugin()
  {
    return new GMSH_EvaluatePlugin();
  }
}


GMSH_EvaluatePlugin::GMSH_EvaluatePlugin()
{
  ;
}

void GMSH_EvaluatePlugin::getName(char *name) const
{
  strcpy(name, "Evaluate");
}

void GMSH_EvaluatePlugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "C. Geuzaine");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Evaluate) sets the `Component'-th\n"
	 "component of the `TimeStep'-th time step in the\n"
	 "view `iView' to the expression `Expression'.\n"
	 "`Expression' can contain:\n"
	 "\n"
	 "- the usual mathematical functions (Log, Sqrt,\n"
	 "Sin, Cos, Fabs, ...) and operators (+, -, *, /, ^);\n"
	 "\n"
	 "- the symbols x, y and z, to retrieve the\n"
	 "coordinates of the current node;\n"
	 "\n"
	 "- the symbols Time and TimeStep, to retrieve the\n"
	 "current time and time step values;\n"
	 "\n"
	 "- the symbol v, to retrieve the `Component'-th\n"
	 "component of the field in `iView' at the\n"
	 "`TimeStep'-th time step;\n"
	 "\n"
	 "- the symbols v0, v1, v2, ..., v8, to retrieve each\n"
	 "component of the field in `iView' at the\n"
	 "`TimeStep'-th time step;\n"
	 "\n"
	 "- the symbol w, to retrieve the `Component'-th\n"
	 "component of the field in `ExternalView' at the\n"
	 "`ExternalTimeStep'-th time step. If `ExternalView'\n"
	 "and `iView' are based on different spatial grids,\n"
	 "or if their data types are different, `ExternalView'\n"
	 "is interpolated onto `iView';\n"
	 "\n"
	 "- the symbols w0, w1, w2, ..., w8, to retrieve each\n"
	 "component of the field in `ExternalView' at the\n"
	 "`ExternalTimeStep'-th time step.\n"
	 "\n"
	 "If `TimeStep' < 0, the plugin automatically loops\n"
	 "over all the time steps in `iView' and evaluates\n"
	 "`Expression' for each one. If `ExternalTimeStep'\n"
	 "< 0, the plugin uses `TimeStep' instead. If\n"
	 "`Component' < 0, the plugin automatically loops\n"
	 "over all the components in the view and\n"
	 "evaluates `Expression' for each one. If `iView'\n"
	 "< 0, the plugin is run on the current view. If\n"
	 "`ExternalView' < 0, the plugin uses `iView'\n"
	 "instead.\n"
	 "\n"
	 "Plugin(Evaluate) is executed in-place.\n");
}

int GMSH_EvaluatePlugin::getNbOptions() const
{
  return sizeof(EvaluateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_EvaluatePlugin::getOption(int iopt)
{
  return &EvaluateOptions_Number[iopt];
}

int GMSH_EvaluatePlugin::getNbOptionsStr() const
{
  return sizeof(EvaluateOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_EvaluatePlugin::getOptionStr(int iopt)
{
  return &EvaluateOptions_String[iopt];
}

void GMSH_EvaluatePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Evaluate failed...");
}

void GMSH_EvaluatePlugin::evaluate(Post_View *v1, List_T *list1, int nbElm1,
				   Post_View *v2, List_T *list2, int nbElm2,
				   int nbNod, int nbComp, int comp, 
				   int timeStep1, int timeStep2,
				   char *expression)
{
#if !defined(HAVE_MATH_EVAL)

  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");

#else

  if(!nbElm1)
    return;

  Msg(FATAL, "XXXXXXXXXXXXXXXXXXXXXX");
  return;

  /*
  void *f = evaluator_create(expression);

  if(!f){
    Msg(GERROR, "Invalid expression '%s'", expression);
    return;
  }

  if((nbElm1 != nbElm2) && !_octree){
    Msg(INFO, "External view based on different grid: interpolating...");
    _octree = new OctreePost(v2);
  }

  v1->Changed = 1;

  int nb = List_Nbr(list1) / nbElm1;
  int nb2 = nbElm2 ? List_Nbr(list2) / nbElm2 : 0;
  for(int i = 0, i2 = 0; i < List_Nbr(list1); i += nb, i2 += nb2) {
    double *x = (double *)List_Pointer_Fast(list1, i);
    double *y = (double *)List_Pointer_Fast(list1, i + nbNod);
    double *z = (double *)List_Pointer_Fast(list1, i + 2 * nbNod);
    for(int j = 0; j < nbNod; j++) {
      // store data from the main view into v
      double v[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
      double *val1 = (double *)List_Pointer_Fast(list1, 
						 i + 3 * nbNod + 
						 nbNod * nbComp * timeStep1 + nbComp * j);
      for(int k = 0; k < nbComp; k++) v[k] = val1[k];

      // store data from the external view into w
      double w[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
      double *val2;
      if(_octree){
	double tmp[9];
	val2 = tmp;
	if(_octree->searchScalar(x[j], y[j], z[j], val2, timeStep2)){
	  w[0] = val2[0];
	}
	else if(_octree->searchVector(x[j], y[j], z[j], val2, timeStep2)){
	  for(int k = 0; k < 3; k++) w[k] = val2[k];
	}
	else if(_octree->searchTensor(x[j], y[j], z[j], val2, timeStep2)){
	  for(int k = 0; k < 9; k++) w[k] = val2[k];
	}
      }
      else{
	val2 = (double *)List_Pointer_Fast(list2, 
					   i2 + 3 * nbNod + 
					   nbNod * nbComp * timeStep2 + nbComp * j);
	for(int k = 0; k < nbComp; k++) w[k] = val2[k];
      }
      
      double time = *(double*)List_Pointer(v1->Time, timeStep1);
      double tstep = timeStep1; 
      char *names[] = { "x", "y", "z", "Time", "TimeStep",
			"v", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8",
			"w", "w0", "w1", "w2", "w3", "w4", "w5", "w6", "w7", "w8" };
      double values[] = { x[j], y[j], z[j], time, tstep,
			  v[comp], v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
			  w[comp], w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8] };
      val1[comp] = evaluator_evaluate(f, sizeof(names)/sizeof(names[0]), names, values);
    }
  }

  evaluator_destroy(f);

  */
#endif
}

Post_View *GMSH_EvaluatePlugin::execute(Post_View * v)
{
  int comp = (int)EvaluateOptions_Number[0].def;
  int timeStep = (int)EvaluateOptions_Number[1].def;
  int externalView = (int)EvaluateOptions_Number[2].def;
  int externalTimeStep = (int)EvaluateOptions_Number[3].def;
  int iView = (int)EvaluateOptions_Number[4].def;
  char *expr = EvaluateOptions_String[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  if(timeStep > v1->NbTimeStep - 1){
    Msg(GERROR, "Invalid time step (%d) in View[%d]: using step 0 instead",
	timeStep, v1->Index);
    timeStep = 0;
  }

  Post_View *v2 = v1;

  if(externalView >= 0){
    if(!List_Pointer_Test(CTX.post.list, externalView))
      Msg(GERROR, "View[%d] does not exist: using self", externalView);
    else
      v2 = *(Post_View **)List_Pointer(CTX.post.list, externalView);
  }

  if(externalTimeStep < 0 && v2->NbTimeStep != v1->NbTimeStep){
    Msg(GERROR, "Number of time steps don't match: using step 0");
    externalTimeStep = 0;
  }
  else if(externalTimeStep > v2->NbTimeStep-1){
    Msg(GERROR, "Invalid time step (%d) in View[%d]: using step 0 instead",
	externalTimeStep, v2->Num);
    externalTimeStep = 0;
  }

  _octree = NULL;

  for(int tt = 0; tt < v1->NbTimeStep; tt++){
    if(timeStep < 0 || timeStep == tt){

      int t2;
      if(externalTimeStep < 0)
	t2 = tt;
      else
	t2 = externalTimeStep;

      evaluate(v1, v1->SP, v1->NbSP, v2, v2->SP, v2->NbSP, 1, 1, 0, tt, t2, expr);
      evaluate(v1, v1->SL, v1->NbSL, v2, v2->SL, v2->NbSL, 2, 1, 0, tt, t2, expr);
      evaluate(v1, v1->ST, v1->NbST, v2, v2->ST, v2->NbST, 3, 1, 0, tt, t2, expr);
      evaluate(v1, v1->SQ, v1->NbSQ, v2, v2->SQ, v2->NbSQ, 4, 1, 0, tt, t2, expr);      
      evaluate(v1, v1->SS, v1->NbSS, v2, v2->SS, v2->NbSS, 4, 1, 0, tt, t2, expr);
      evaluate(v1, v1->SH, v1->NbSH, v2, v2->SH, v2->NbSH, 8, 1, 0, tt, t2, expr);      
      evaluate(v1, v1->SI, v1->NbSI, v2, v2->SI, v2->NbSI, 6, 1, 0, tt, t2, expr);
      evaluate(v1, v1->SY, v1->NbSY, v2, v2->SY, v2->NbSY, 5, 1, 0, tt, t2, expr);

      for(int cc = 0; cc < 3; cc++){
	if(comp < 0 || comp == cc){
	  evaluate(v1, v1->VP, v1->NbVP, v2, v2->VP, v2->NbVP, 1, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VL, v1->NbVL, v2, v2->VL, v2->NbVL, 2, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VT, v1->NbVT, v2, v2->VT, v2->NbVT, 3, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VQ, v1->NbVQ, v2, v2->VQ, v2->NbVQ, 4, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VS, v1->NbVS, v2, v2->VS, v2->NbVS, 4, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VH, v1->NbVH, v2, v2->VH, v2->NbVH, 8, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VI, v1->NbVI, v2, v2->VI, v2->NbVI, 6, 3, cc, tt, t2, expr);
	  evaluate(v1, v1->VY, v1->NbVY, v2, v2->VY, v2->NbVY, 5, 3, cc, tt, t2, expr);
	}
      }

      for(int cc = 0; cc < 9; cc++){
	if(comp < 0 || comp == cc){
	  evaluate(v1, v1->TP, v1->NbTP, v2, v2->TP, v2->NbTP, 1, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TL, v1->NbTL, v2, v2->TL, v2->NbTL, 2, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TT, v1->NbTT, v2, v2->TT, v2->NbTT, 3, 9, cc, tt, t2, expr);      
	  evaluate(v1, v1->TQ, v1->NbTQ, v2, v2->TQ, v2->NbTQ, 4, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TS, v1->NbTS, v2, v2->TS, v2->NbTS, 4, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TH, v1->NbTH, v2, v2->TH, v2->NbTH, 8, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TI, v1->NbTI, v2, v2->TI, v2->NbTI, 6, 9, cc, tt, t2, expr);
	  evaluate(v1, v1->TY, v1->NbTY, v2, v2->TY, v2->NbTY, 5, 9, cc, tt, t2, expr);
	}
      }
    }
  }

  if(_octree) delete _octree;

  // recompute min/max, etc.:
  v1->Min = VAL_INF;
  v1->Max = -VAL_INF;
  EndView(v1, 0, v1->FileName, v1->Name);

  return v1;
}
