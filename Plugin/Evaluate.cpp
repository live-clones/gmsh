// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "Evaluate.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

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

void GMSH_EvaluatePlugin::getName(char *name) const
{
  strcpy(name, "Evaluate");
}

void GMSH_EvaluatePlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
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

void GMSH_EvaluatePlugin::evaluate(PView *v1, List_T *list1, int nbElm1,
                                   PView *v2, List_T *list2, int nbElm2,
                                   int nbNod, int nbComp, int comp, 
                                   int timeStep1, int timeStep2,
                                   const char *expression)
{
#if !defined(HAVE_MATH_EVAL)

  Msg::Error("MathEval is not compiled in this version of Gmsh");

#else

  if(!nbElm1)
    return;

  void *f = evaluator_create((char*)expression);

  if(!f){
    Msg::Error("Invalid expression '%s'", expression);
    return;
  }

  if((nbElm1 != nbElm2) && !_octree){
    Msg::Info("External view based on different grid: interpolating...");
    _octree = new OctreePost(v2);
  }

  v1->setChanged(true);

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
      
      double time = v1->getData()->getTime(timeStep1);
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
#endif
}

PView *GMSH_EvaluatePlugin::execute(PView *v)
{
  int comp = (int)EvaluateOptions_Number[0].def;
  int timeStep = (int)EvaluateOptions_Number[1].def;
  int externalView = (int)EvaluateOptions_Number[2].def;
  int externalTimeStep = (int)EvaluateOptions_Number[3].def;
  int iView = (int)EvaluateOptions_Number[4].def;
  const char *expr = EvaluateOptions_String[0].def.c_str();

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewDataList *data1 = getDataList(v1);
  if(!data1) return v;

  if(timeStep > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
        timeStep, v1->getIndex());
    timeStep = 0;
  }

  PView *v2 = v1;

  if(externalView >= 0){
    if(externalView < (int)PView::list.size())
      v2 = PView::list[externalView];
    else
      Msg::Error("View[%d] does not exist: using self", externalView);
  }

  PViewDataList *data2 = getDataList(v2);
  if(!data2) return v;

  if(externalTimeStep < 0 && data2->getNumTimeSteps() != data1->getNumTimeSteps()){
    Msg::Error("Number of time steps don't match: using step 0");
    externalTimeStep = 0;
  }
  else if(externalTimeStep > data2->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
        externalTimeStep, v2->getIndex());
    externalTimeStep = 0;
  }

  _octree = 0;

  for(int tt = 0; tt < data1->getNumTimeSteps(); tt++){
    if(timeStep < 0 || timeStep == tt){

      int t2;
      if(externalTimeStep < 0)
        t2 = tt;
      else
        t2 = externalTimeStep;

      evaluate(v1, data1->SP, data1->NbSP, 
               v2, data2->SP, data2->NbSP, 1, 1, 0, tt, t2, expr);
      evaluate(v1, data1->SL, data1->NbSL, 
               v2, data2->SL, data2->NbSL, 2, 1, 0, tt, t2, expr);
      evaluate(v1, data1->ST, data1->NbST, 
               v2, data2->ST, data2->NbST, 3, 1, 0, tt, t2, expr);
      evaluate(v1, data1->SQ, data1->NbSQ,
               v2, data2->SQ, data2->NbSQ, 4, 1, 0, tt, t2, expr);      
      evaluate(v1, data1->SS, data1->NbSS, 
               v2, data2->SS, data2->NbSS, 4, 1, 0, tt, t2, expr);
      evaluate(v1, data1->SH, data1->NbSH,
               v2, data2->SH, data2->NbSH, 8, 1, 0, tt, t2, expr);      
      evaluate(v1, data1->SI, data1->NbSI, 
               v2, data2->SI, data2->NbSI, 6, 1, 0, tt, t2, expr);
      evaluate(v1, data1->SY, data1->NbSY, 
               v2, data2->SY, data2->NbSY, 5, 1, 0, tt, t2, expr);

      for(int cc = 0; cc < 3; cc++){
        if(comp < 0 || comp == cc){
          evaluate(v1, data1->VP, data1->NbVP, 
                   v2, data2->VP, data2->NbVP, 1, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VL, data1->NbVL,
                   v2, data2->VL, data2->NbVL, 2, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VT, data1->NbVT,
                   v2, data2->VT, data2->NbVT, 3, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VQ, data1->NbVQ,
                   v2, data2->VQ, data2->NbVQ, 4, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VS, data1->NbVS,
                   v2, data2->VS, data2->NbVS, 4, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VH, data1->NbVH,
                   v2, data2->VH, data2->NbVH, 8, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VI, data1->NbVI,
                   v2, data2->VI, data2->NbVI, 6, 3, cc, tt, t2, expr);
          evaluate(v1, data1->VY, data1->NbVY,
                   v2, data2->VY, data2->NbVY, 5, 3, cc, tt, t2, expr);
        }
      }

      for(int cc = 0; cc < 9; cc++){
        if(comp < 0 || comp == cc){
          evaluate(v1, data1->TP, data1->NbTP,
                   v2, data2->TP, data2->NbTP, 1, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TL, data1->NbTL,
                   v2, data2->TL, data2->NbTL, 2, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TT, data1->NbTT,
                   v2, data2->TT, data2->NbTT, 3, 9, cc, tt, t2, expr);      
          evaluate(v1, data1->TQ, data1->NbTQ,
                   v2, data2->TQ, data2->NbTQ, 4, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TS, data1->NbTS,
                   v2, data2->TS, data2->NbTS, 4, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TH, data1->NbTH,
                   v2, data2->TH, data2->NbTH, 8, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TI, data1->NbTI,
                   v2, data2->TI, data2->NbTI, 6, 9, cc, tt, t2, expr);
          evaluate(v1, data1->TY, data1->NbTY,
                   v2, data2->TY, data2->NbTY, 5, 9, cc, tt, t2, expr);
        }
      }
    }
  }

  if(_octree) delete _octree;

  data1->finalize();

  return v1;
}
