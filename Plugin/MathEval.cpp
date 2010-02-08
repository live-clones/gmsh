// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "MathEval.h"
#include "mathEvaluator.h"
#include "OctreePost.h"

StringXNumber MathEvalOptions_Number[] = {
  {GMSH_FULLRC, "TimeStep", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "ExternalView", NULL, -1.},
  {GMSH_FULLRC, "ExternalTimeStep", NULL, -1.}
};

StringXString MathEvalOptions_String[] = {
  {GMSH_FULLRC, "Expression0", NULL, "Sqrt(v0^2+v1^2+v2^2)"},
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
  GMSH_Plugin *GMSH_RegisterMathEvalPlugin()
  {
    return new GMSH_MathEvalPlugin();
  }
}

std::string GMSH_MathEvalPlugin::getHelp() const
{
  return "Plugin(MathEval) creates a new view using\n"
         "data from `iView'. If only `Expression0' is\n"
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
         " ..., vn, which represent the n components in\n"
         "`iView', w0, w1, w2,..., wn which represent the n\n"
         "components of `ExternalView' and the symbols x,\n"
         "y and z, which represent the three spatial coordinates.\n"
         "If `TimeStep' < 0, the plugin extracts data from \n"
         "all the time steps in the view.\n"
         "If `iView' < 0, the plugin is run on the current view.\n"
         "\n"
         "Plugin(MathEval) creates one new view.\n";
}

int GMSH_MathEvalPlugin::getNbOptions() const
{
  return sizeof(MathEvalOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_MathEvalPlugin::getOption(int iopt)
{
  return &MathEvalOptions_Number[iopt];
}

int GMSH_MathEvalPlugin::getNbOptionsStr() const
{
  return sizeof(MathEvalOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_MathEvalPlugin::getOptionStr(int iopt)
{
  return &MathEvalOptions_String[iopt];
}

static std::vector<double> *incrementList(PViewDataList *data, int numComp, 
                                          int type)
{
  switch(type){
  case TYPE_PNT:
    if     (numComp == 1){ data->NbSP++; return &data->SP; }
    else if(numComp == 3){ data->NbVP++; return &data->VP; }
    else if(numComp == 9){ data->NbTP++; return &data->TP; }
    break;
  case TYPE_LIN:
    if     (numComp == 1){ data->NbSL++; return &data->SL; }
    else if(numComp == 3){ data->NbVL++; return &data->VL; }
    else if(numComp == 9){ data->NbTL++; return &data->TL; }
    break;
  case TYPE_TRI:
    if     (numComp == 1){ data->NbST++; return &data->ST; }
    else if(numComp == 3){ data->NbVT++; return &data->VT; }
    else if(numComp == 9){ data->NbTT++; return &data->TT; }
    break;
  case TYPE_QUA:
    if     (numComp == 1){ data->NbSQ++; return &data->SQ; }
    else if(numComp == 3){ data->NbVQ++; return &data->VQ; }
    else if(numComp == 9){ data->NbTQ++; return &data->TQ; }
    break;
  case TYPE_TET:
    if     (numComp == 1){ data->NbSS++; return &data->SS; }
    else if(numComp == 3){ data->NbVS++; return &data->VS; }
    else if(numComp == 9){ data->NbTS++; return &data->TS; }
    break;
  case TYPE_HEX:
    if     (numComp == 1){ data->NbSH++; return &data->SH; }
    else if(numComp == 3){ data->NbVH++; return &data->VH; }
    else if(numComp == 9){ data->NbTH++; return &data->TH; }
    break;
  case TYPE_PRI:
    if     (numComp == 1){ data->NbSI++; return &data->SI; }
    else if(numComp == 3){ data->NbVI++; return &data->VI; }
    else if(numComp == 9){ data->NbTI++; return &data->TI; }
    break;
  case TYPE_PYR:
    if     (numComp == 1){ data->NbSY++; return &data->SY; }
    else if(numComp == 3){ data->NbVY++; return &data->VY; }
    else if(numComp == 9){ data->NbTY++; return &data->TY; }
    break;
  }
  return 0;
}

PView *GMSH_MathEvalPlugin::execute(PView *view)
{
  int timeStep = (int)MathEvalOptions_Number[0].def;
  int iView = (int)MathEvalOptions_Number[1].def;
  int iExternalView = (int)MathEvalOptions_Number[2].def;
  int stepExternal = (int)MathEvalOptions_Number[3].def;
  std::vector<std::string> expr(9);
  for(int i = 0; i < 9; i++) expr[i] = MathEvalOptions_String[i].def;
  
  PView *v1 = getView(iView, view);
  if(!v1) return view;
  PViewData *data1 = v1->getData();

  if(data1->hasMultipleMeshes()){
    Msg::Error("MathEval plugin cannot be applied to multi-mesh views");
    return view;
  }
  PView *externalView = NULL;
  PViewData *dataExternal = NULL;
  OctreePost *octree = 0;

  if(iExternalView>=0){
    externalView = getView(iExternalView, view);
    if(!externalView){
      Msg::Error("MathEval plugin cannot found external view %i",iExternalView);
      return view;
    }
    dataExternal = externalView->getData();
    if(dataExternal->hasMultipleMeshes()){
      Msg::Error("MathEval plugin cannot be applied to multi-mesh views");
      return view;
    }
    if((data1->getNumEntities() != dataExternal->getNumEntities()) ||
        (data1->getNumElements() != dataExternal->getNumElements())){
      Msg::Info("External view based on different grid: interpolating...");
      octree = new OctreePost(externalView);
    }
  }

  int numComp2;
  if(expr[3].size() || expr[4].size() || expr[5].size() || 
     expr[6].size() || expr[7].size() || expr[8].size()){
    numComp2 = 9;
    for(int i = 0; i < 9; i++)
      if(expr[i].empty()) expr[i] = "0";
  }
  else if(expr[1].size() || expr[2].size()){
    numComp2 = 3;
    for(int i = 0; i < 3; i++)
      if(expr[i].empty()) expr[i] = "0";
  }
  else{
    numComp2 = 1;
  }
  expr.resize(numComp2);

  const char *names[] = 
    { "x", "y", "z", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8", "w0","w1","w2","w3","w4","w5","w6","w7","w8","w9" };
  unsigned int numVariables = sizeof(names) / sizeof(names[0]);
  std::vector<std::string> variables(numVariables);
  for(unsigned int i = 0; i < numVariables; i++) variables[i] = names[i];
  mathEvaluator f(expr, variables);
  if(expr.empty()) return view;
  std::vector<double> values(numVariables), res(numComp2);
          
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
      int type = data1->getType(0, ent, ele);
      int numComp = data1->getNumComponents(0, ent, ele);
      int numCompExternal = !dataExternal ? 9 : octree ? 9 : dataExternal->getNumComponents(stepExternal, ent, ele);
      std::vector<double> *out = incrementList(data2, numComp2, type);
      std::vector<double> w(std::max(9, numCompExternal), 0.);
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
          std::vector<double> v(std::max(9, numComp), 0.);
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, v[comp]);
          values[0] = x[nod]; values[1] = y[nod]; values[2] = z[nod];
          if(dataExternal){
            if(octree){
              if(!octree->searchScalar(x[nod], y[nod], z[nod], &w[0], stepExternal))
                if(!octree->searchVector(x[nod], y[nod], z[nod], &w[0], stepExternal))
                  octree->searchTensor(x[nod], y[nod], z[nod], &w[0], stepExternal);
            }
            else
              for(int comp = 0; comp < numCompExternal; comp++)
                dataExternal->getValue(stepExternal, ent, ele, nod, comp, w[comp]);
          }
          for(int i = 0; i < 9; i++) values[3 + i] = v[i];
          for(int i = 0; i < 9; i++) values[12 + i] = w[i];
          if(f.eval(values, res))
            for(int i = 0; i < numComp2; i++)
              out->push_back(res[i]);
        }
      }
    }
  }
  
  if(timeStep < 0){
    for(int i = 0; i < data1->getNumTimeSteps(); i++)
      data2->Time.push_back(data1->getTime(i));
  }
  else
    data2->Time.push_back(data1->getTime(timeStep));
        
  data2->setName(data1->getName() + "_MathEval");
  data2->setFileName(data1->getName() + "_MathEval.pos");
  data2->finalize();

  return v2;
}
