// $Id: Evaluate.cpp,v 1.7 2004-05-16 20:04:43 geuzaine Exp $
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
  {GMSH_FULLRC, "TimeStep", NULL, 0.},
  {GMSH_FULLRC, "Component", NULL, 0.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString EvaluateOptions_String[] = {
  {GMSH_FULLRC, "Expression", NULL, "0.01*(Fabs(Sin(30*y)*Fabs(Cos(30*x)))+0.3)"}
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
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Evaluate) sets the `Component'-th\n"
	 "component of the `TimeStep'-th time step\n"
	 "in the view `iView' to the expression\n"
	 "`Expression'. In addition to the usual\n"
	 "mathematical functions (Exp, Log, Sqrt, Sin,\n"
	 "Cos, Fabs, etc.) and operators (+, -, *, /, ^),\n"
	 "`Expression' can contain the symbols x, y, z\n"
	 "and v, which represent the three spatial\n"
	 "coordinates and the value of the field,\n"
	 "respectively. If `iView' < 0, the plugin is run\n"
	 "on the current view.\n"
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

static void evaluate(Post_View * v, List_T * list, int nbElm,
		     int nbNod, int nbComp, int comp, int timeStep,
		     char *expression)
{
#if !defined(HAVE_MATH_EVAL)

  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");

#else

  if(!nbElm)
    return;

  if(timeStep < 0 || timeStep > v->NbTimeStep - 1){
    Msg(GERROR, "Invalid TimeStep (%d) in View[%d]", timeStep, v->Index);
    return;
  }
  
  if(comp < 0 || comp > nbComp - 1){
    Msg(GERROR, "Invalid Component (%d) in View[%d]", comp, v->Index);
    return;
  }

  void *f = evaluator_create(expression);

  if(!f){
    Msg(GERROR, "Invalid expression '%s'", expression);
    return;
  }

  v->Changed = 1;

  double min = VAL_INF;
  double max = -VAL_INF;

  int nb = List_Nbr(list) / nbElm;
  for(int i = 0; i < List_Nbr(list); i += nb) {
    double *x = (double *)List_Pointer_Fast(list, i);
    double *y = (double *)List_Pointer_Fast(list, i + nbNod);
    double *z = (double *)List_Pointer_Fast(list, i + 2 * nbNod);
    for(int j = 0; j < nbNod; j++) {
      double *val = (double *)List_Pointer_Fast(list, 
						i + 3 * nbNod + 
						nbNod * nbComp * timeStep + nbComp * j);
      double xx = x[j];
      double yy = y[j];
      double zz = z[j];
      double vv = val[comp];

      char *names[] = { "x", "y" , "z", "v" };
      double values[] = { xx , yy, zz, vv };
      double res = evaluator_evaluate(f, sizeof(names)/sizeof(names[0]), names, values);

      val[comp] = res;

      if(nbComp == 3)
	res = sqrt(DSQR(val[0]) + DSQR(val[1]) + DSQR(val[2]));
      else if(nbComp == 9)
	res = ComputeVonMises(val);
      if(res < min) min = res;
      if(res > max) max = res;
    }
  }

  evaluator_destroy(f);
  
  v->TimeStepMin[timeStep] = min;
  v->TimeStepMax[timeStep] = max;
  v->Min = v->TimeStepMin[0];
  v->Max = v->TimeStepMax[0];
  for(int i = 1; i < v->NbTimeStep; i++){
    if(v->TimeStepMin[i] < v->Min) v->Min = v->TimeStepMin[i];
    if(v->TimeStepMax[i] > v->Max) v->Max = v->TimeStepMax[i];
  }

#endif
}

Post_View *GMSH_EvaluatePlugin::execute(Post_View * v)
{
  int timeStep = (int)EvaluateOptions_Number[0].def;
  int comp = (int)EvaluateOptions_Number[1].def;
  int iView = (int)EvaluateOptions_Number[2].def;
  char *expr = EvaluateOptions_String[0].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);

  evaluate(v1, v1->SP, v1->NbSP, 1, 1, comp, timeStep, expr);
  evaluate(v1, v1->VP, v1->NbVP, 1, 3, comp, timeStep, expr);
  evaluate(v1, v1->TP, v1->NbTP, 1, 9, comp, timeStep, expr);

  evaluate(v1, v1->SL, v1->NbSL, 2, 1, comp, timeStep, expr);
  evaluate(v1, v1->VL, v1->NbVL, 2, 3, comp, timeStep, expr);
  evaluate(v1, v1->TL, v1->NbTL, 2, 9, comp, timeStep, expr);

  evaluate(v1, v1->ST, v1->NbST, 3, 1, comp, timeStep, expr);
  evaluate(v1, v1->VT, v1->NbVT, 3, 3, comp, timeStep, expr);
  evaluate(v1, v1->TT, v1->NbTT, 3, 9, comp, timeStep, expr);

  evaluate(v1, v1->SQ, v1->NbSQ, 4, 1, comp, timeStep, expr);
  evaluate(v1, v1->VQ, v1->NbVQ, 4, 3, comp, timeStep, expr);
  evaluate(v1, v1->TQ, v1->NbTQ, 4, 9, comp, timeStep, expr);

  evaluate(v1, v1->SS, v1->NbSS, 4, 1, comp, timeStep, expr);
  evaluate(v1, v1->VS, v1->NbVS, 4, 3, comp, timeStep, expr);
  evaluate(v1, v1->TS, v1->NbTS, 4, 9, comp, timeStep, expr);

  evaluate(v1, v1->SH, v1->NbSH, 8, 1, comp, timeStep, expr);
  evaluate(v1, v1->VH, v1->NbVH, 8, 3, comp, timeStep, expr);
  evaluate(v1, v1->TH, v1->NbTH, 8, 9, comp, timeStep, expr);

  evaluate(v1, v1->SI, v1->NbSI, 6, 1, comp, timeStep, expr);
  evaluate(v1, v1->VI, v1->NbVI, 6, 3, comp, timeStep, expr);
  evaluate(v1, v1->TI, v1->NbTI, 6, 9, comp, timeStep, expr);

  evaluate(v1, v1->SY, v1->NbSY, 5, 1, comp, timeStep, expr);
  evaluate(v1, v1->VY, v1->NbVY, 5, 3, comp, timeStep, expr);
  evaluate(v1, v1->TY, v1->NbTY, 5, 9, comp, timeStep, expr);

  return v1;
}

