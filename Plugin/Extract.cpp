// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "Extract.h"

#if defined(HAVE_MATH_EVAL)
#include "matheval.h"
#endif

StringXNumber ExtractOptions_Number[] = {
  {GMSH_FULLRC, "TimeStep", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString ExtractOptions_String[] = {
#if defined(HAVE_MATH_EVAL)
  {GMSH_FULLRC, "Expression0", NULL, "Sqrt(v0^2+v1^2+v2^2)"},
#else
  {GMSH_FULLRC, "Expression0", NULL, "v0"},
#endif
  {GMSH_FULLRC, "Expression1", NULL, ""},
  {GMSH_FULLRC, "Expression2", NULL, ""},
  {GMSH_FULLRC, "Expression3", NULL, ""},
  {GMSH_FULLRC, "Expression4", NULL, ""},
  {GMSH_FULLRC, "Expression5", NULL, ""},
  {GMSH_FULLRC, "Expression6", NULL, ""},
  {GMSH_FULLRC, "Expression7", NULL, ""},
  {GMSH_FULLRC, "Expression8", NULL, ""}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterExtractPlugin()
  {
    return new GMSH_ExtractPlugin();
  }
}

void GMSH_ExtractPlugin::getName(char *name) const
{
  strcpy(name, "Extract");
}

void GMSH_ExtractPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine, J.-F. Remacle");
  strcpy(copyright, "C. Geuzaine, J.-F. Remacle");
  strcpy(help_text,
         "Plugin(Extract) extracts a combination of\n"
         "components from the `TimeStep'th time step\n"
         "in the view `iView'. If only `Expression0' is\n"
         "given (and `Expression1', ..., `Expression8' are\n"
         "all empty), the plugin creates a scalar view.\n"
         "If `Expression0', `Expression1' and/or\n"
         "`Expression2' are given (and `Expression3',\n"
         "..., `Expression8' are all empty) the plugin\n"
         "creates a vector view. Otherwise the plugin\n"
         "creates a tensor view. In addition to the usual\n"
         "mathematical functions (Exp, Log, Sqrt, Sin, Cos,\n"
         "Fabs, etc.) and operators (+, -, *, /, ^), all\n"
         "expressions can contain the symbols v0, v1, v2,\n"
         " ..., vn, which represent the n components of the\n"
         "field, and the symbols x, y and z, which represent\n"
         "the three spatial coordinates. If `TimeStep' < 0,\n"
         "the plugin extracts data from all the time steps\n"
         "in the view. If `iView' < 0, the plugin is run on\n"
         "the current view.\n"
         "\n"
         "Plugin(Extract) creates one new view.\n");
}

int GMSH_ExtractPlugin::getNbOptions() const
{
  return sizeof(ExtractOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_ExtractPlugin::getOption(int iopt)
{
  return &ExtractOptions_Number[iopt];
}

int GMSH_ExtractPlugin::getNbOptionsStr() const
{
  return sizeof(ExtractOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_ExtractPlugin::getOptionStr(int iopt)
{
  return &ExtractOptions_String[iopt];
}

void GMSH_ExtractPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Extract failed...");
}

static std::vector<double> *incrementList(PViewDataList *data2, int numComp2, 
                                          int numEdges)
{
  switch(numEdges){
  case 0:
    if     (numComp2 == 1){ data2->NbSP++; return &data2->SP; }
    else if(numComp2 == 3){ data2->NbVP++; return &data2->VP; }
    else if(numComp2 == 9){ data2->NbTP++; return &data2->TP; }
    break;
  case 1:
    if     (numComp2 == 1){ data2->NbSL++; return &data2->SL; }
    else if(numComp2 == 3){ data2->NbVL++; return &data2->VL; }
    else if(numComp2 == 9){ data2->NbTL++; return &data2->TL; }
    break;
  case 3: 
    if     (numComp2 == 1){ data2->NbST++; return &data2->ST; }
    else if(numComp2 == 3){ data2->NbVT++; return &data2->VT; }
    else if(numComp2 == 9){ data2->NbTT++; return &data2->TT; }
    break;
  case 4: 
    if     (numComp2 == 1){ data2->NbSQ++; return &data2->SQ; }
    else if(numComp2 == 3){ data2->NbVQ++; return &data2->VQ; }
    else if(numComp2 == 9){ data2->NbTQ++; return &data2->TQ; }
    break;
  case 6:
    if     (numComp2 == 1){ data2->NbSS++; return &data2->SS; }
    else if(numComp2 == 3){ data2->NbVS++; return &data2->VS; }
    else if(numComp2 == 9){ data2->NbTS++; return &data2->TS; }
    break;
  case 12: 
    if     (numComp2 == 1){ data2->NbSH++; return &data2->SH; }
    else if(numComp2 == 3){ data2->NbVH++; return &data2->VH; }
    else if(numComp2 == 9){ data2->NbTH++; return &data2->TH; }
    break;
  case 9: 
    if     (numComp2 == 1){ data2->NbSI++; return &data2->SI; }
    else if(numComp2 == 3){ data2->NbVI++; return &data2->VI; }
    else if(numComp2 == 9){ data2->NbTI++; return &data2->TI; }
    break;
  case 8:
    if     (numComp2 == 1){ data2->NbSY++; return &data2->SY; }
    else if(numComp2 == 3){ data2->NbVY++; return &data2->VY; }
    else if(numComp2 == 9){ data2->NbTY++; return &data2->TY; }
    break;
  }
  return 0;
}

PView *GMSH_ExtractPlugin::execute(PView *v)
{
  int timeStep = (int)ExtractOptions_Number[0].def;
  int iView = (int)ExtractOptions_Number[1].def;
  const char *expr[9] = { ExtractOptions_String[0].def.c_str(), 
                          ExtractOptions_String[1].def.c_str(),
                          ExtractOptions_String[2].def.c_str(),
                          ExtractOptions_String[3].def.c_str(),
                          ExtractOptions_String[4].def.c_str(),
                          ExtractOptions_String[5].def.c_str(),
                          ExtractOptions_String[6].def.c_str(),
                          ExtractOptions_String[7].def.c_str(),
                          ExtractOptions_String[8].def.c_str() };

  PView *v1 = getView(iView, v);
  if(!v1) return v;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()){
    Msg::Error("Extract plugin cannot be applied to multi-mesh views");
    return v;
  }

  int numComp2;
  if(strlen(expr[3]) || strlen(expr[4]) || strlen(expr[5]) || 
     strlen(expr[6]) || strlen(expr[7]) || strlen(expr[8])){
    numComp2 = 9;
    for(int i = 0; i < 9; i++)
      if(!strlen(expr[i])) expr[i] = "0";
  }
  else if(strlen(expr[1]) || strlen(expr[2])){
    numComp2 = 3;
    for(int i = 0; i < 3; i++)
      if(!strlen(expr[i])) expr[i] = "0";
  }
  else{
    numComp2 = 1;
  }

  // if we have MathEval, we can evaluate arbitrary expressions;
  // otherwise, we only allow to extract single components
#if defined(HAVE_MATH_EVAL)
  void *f[9] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
  for(int i = 0; i < numComp2; i++){
    f[i] = evaluator_create((char*)expr[i]);
    if(!f[i]){
      Msg::Error("Invalid expression '%s'", expr[i]);
      for(int j = 0; j < i; j++)
        if(f[j]) evaluator_destroy(f[j]);
      return v;
    }
  }
#else
  int comp2[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  for(int i = 0; i < numComp2; i++){
    if     (!strcmp(expr[i], "v0")) comp2[i] = 0;
    else if(!strcmp(expr[i], "v1")) comp2[i] = 1;
    else if(!strcmp(expr[i], "v2")) comp2[i] = 2;
    else if(!strcmp(expr[i], "v3")) comp2[i] = 3;
    else if(!strcmp(expr[i], "v4")) comp2[i] = 4;
    else if(!strcmp(expr[i], "v5")) comp2[i] = 5;
    else if(!strcmp(expr[i], "v6")) comp2[i] = 6;
    else if(!strcmp(expr[i], "v7")) comp2[i] = 7;
    else if(!strcmp(expr[i], "v8")) comp2[i] = 8;
    else{
      Msg::Error("Invalid expression '%s'", expr[i]);
      return v;
    }
  }
#endif

  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  if(timeStep < 0){
    timeStep = - data1->getNumTimeSteps();
  }
  else if(timeStep > data1->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using all steps instead",
               timeStep, v1->getIndex());
    timeStep = - data1->getNumTimeSteps();
  }

  for(int ent = 0; ent < data1->getNumEntities(0); ent++){
    for(int ele = 0; ele < data1->getNumElements(0, ent); ele++){
      if(data1->skipElement(0, ent, ele)) continue;
      int numNodes = data1->getNumNodes(0, ent, ele);
      int numEdges = data1->getNumEdges(0, ent, ele);
      int numComp = data1->getNumComponents(0, ent, ele);
      std::vector<double> *out = incrementList(data2, numComp2, numEdges);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(0, ent, ele, nod, x[nod], y[nod], z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]); 
      int timeBeg = (timeStep < 0) ? 0 : timeStep;
      int timeEnd = (timeStep < 0) ? -timeStep : timeStep + 1;
      for(int step = timeBeg; step < timeEnd; step++){
        for(int nod = 0; nod < numNodes; nod++){
          double v[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
          for(int comp = 0; comp < numComp; comp++)
	    data1->getValue(step, ent, ele, nod, comp, v[comp]);
          for(int comp = 0; comp < numComp2; comp++){
#if defined(HAVE_MATH_EVAL)
            char *names[] = { "x", "y", "z", "v0", "v1", "v2", 
                              "v3", "v4", "v5", "v6", "v7", "v8" };
            double values[] = { x[nod], y[nod], z[nod], v[0], v[1], v[2], 
                                v[3], v[4], v[5], v[6], v[7], v[8] };
            double res = evaluator_evaluate(f[comp], sizeof(names) / sizeof(names[0]),
                                            names, values);
#else
            double res = v[comp2[comp]];
#endif
            out->push_back(res);
          }
        }
      }
    }
  }
  
#if defined(HAVE_MATH_EVAL)
  for(int i = 0; i < numComp2; i++)
    evaluator_destroy(f[i]);
#endif

  if(timeStep < 0){
    for(int i = 0; i < data1->getNumTimeSteps(); i++)
      data2->Time.push_back(data1->getTime(i));
  }
  else
    data2->Time.push_back(data1->getTime(timeStep));
        
  data2->setName(data1->getName() + "_Extract");
  data2->setFileName(data1->getName() + "_Extract.pos");
  data2->finalize();

  return v2;
}
