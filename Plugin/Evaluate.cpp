// $Id: Evaluate.cpp,v 1.5 2004-05-13 15:54:56 geuzaine Exp $
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
         "Plugin(Evaluate) sets the values associated\n"
         "with the `TimeStep'-th time step in the scalar\n"
	 "view `iView' to the expression `Expression'. In\n"
	 "addition to the usual mathematical functions\n"
	 "(Exp, Log, Sqrt, Sin, Cos, Fabs, etc.) and\n"
	 "operators (+, -, *, /, ^), `Expression' can\n"
	 "contain the symbols x, y, z and v, which\n"
	 "represent the three spatial coordinates and the\n"
	 "value of the field, respectively. If `iView' < 0,\n"
	 "the plugin is run on the current view.\n"
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

static void evaluateList(Post_View * v, List_T * list, int nbElm,
			 int nbNod, int timeStep, char *expression)
{
#if !defined(HAVE_MATH_EVAL)

  Msg(GERROR, "MathEval is not compiled in this version of Gmsh");

#else

  double *x, *y, *z, *val;
  int nb, i, j;

  if(!nbElm)
    return;

  v->Changed = 1;

  if(timeStep < 0 || timeStep > v->NbTimeStep - 1){
    Msg(WARNING, "Invalid TimeStep (%d) in View[%d]: choosing TimeStep 0",
	timeStep, v->Index);
    timeStep = 0;
  }

  void *f = evaluator_create(expression);

  if(!f){
    Msg(GERROR, "Invalid expression '%s'", expression);
    return;
  }

  double min = VAL_INF;
  double max = -VAL_INF;

  nb = List_Nbr(list) / nbElm;
  for(i = 0; i < List_Nbr(list); i += nb) {
    x = (double *)List_Pointer_Fast(list, i);
    y = (double *)List_Pointer_Fast(list, i + nbNod);
    z = (double *)List_Pointer_Fast(list, i + 2 * nbNod);
    val = (double *)List_Pointer_Fast(list, i + 3 * nbNod);
    for(j = 0; j < nbNod; j++) {

      double xx = x[j];
      double yy = y[j];
      double zz = z[j];
      double vv = val[nbNod * timeStep + j];

      char *names[] = { "x", "y" , "z", "v" };
      double values[] = { xx , yy, zz, vv };
      double res = evaluator_evaluate(f, sizeof(names)/sizeof(names[0]), names, values);

      val[nbNod * timeStep + j] = res;
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

static void evaluate(Post_View * v, int timeStep, char *expression)
{
  evaluateList(v, v->SP, v->NbSP, 1, timeStep, expression);
  evaluateList(v, v->SL, v->NbSL, 2, timeStep, expression);
  evaluateList(v, v->ST, v->NbST, 3, timeStep, expression);
  evaluateList(v, v->SQ, v->NbSQ, 4, timeStep, expression);
  evaluateList(v, v->SS, v->NbSS, 4, timeStep, expression);
  evaluateList(v, v->SH, v->NbSH, 8, timeStep, expression);
  evaluateList(v, v->SI, v->NbSI, 6, timeStep, expression);
  evaluateList(v, v->SY, v->NbSY, 5, timeStep, expression);
}

Post_View *GMSH_EvaluatePlugin::execute(Post_View * v)
{
  Post_View *vv;

  int timeStep = (int)EvaluateOptions_Number[0].def;
  int iView = (int)EvaluateOptions_Number[1].def;
  char *expr = EvaluateOptions_String[0].def;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  evaluate(vv, timeStep, expr);
  return vv;
}

