// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
  {GMSH_FULLRC, "View", NULL, -1.},
  {GMSH_FULLRC, "OtherTimeStep", NULL, -1.},
  {GMSH_FULLRC, "OtherView", NULL, -1.}
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
  return "Plugin(MathEval) creates a new view using "
    "data from the time step `TimeStep' in the view "
    "`View'.\n\n"
    "If only `Expression0' is given (and `Expression1', "
    "..., `Expression8' are all empty), the plugin "
    "creates a scalar view. If `Expression0', `Expression1' "
    "and/or `Expression2' are given (and `Expression3', "
    "..., `Expression8' are all empty) the plugin creates "
    "a vector view. Otherwise the plugin creates a tensor "
    "view.\n\n"
    "In addition to the usual mathematical functions "
    "(Exp, Log, Sqrt, Sin, Cos, Fabs, etc.) and operators "
    "(+, -, *, /, ^), all expressions can contain:\n\n"
    "- the symbols v0, v1, v2, ..., vn, which represent "
    "the n components in `View';\n\n"
    "- the symbols w0, w1, w2, ..., wn, which represent "
    "the n components of `OtherView', at time step "
    "`OtherTimeStep';\n\n"
    "- the symbols x, y and z, which represent the three "
    "spatial coordinates.\n\n"
    "If `TimeStep' < 0, the plugin extracts data from all "
    "the time steps in the view.\n\n"
    "If `View' < 0, the plugin is run on the current view.\n\n"
    "Plugin(MathEval) creates one new view.";
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

PView *GMSH_MathEvalPlugin::execute(PView *view)
{
  int timeStep = (int)MathEvalOptions_Number[0].def;
  int iView = (int)MathEvalOptions_Number[1].def;
  int otherTimeStep = (int)MathEvalOptions_Number[2].def;
  int iOtherView = (int)MathEvalOptions_Number[3].def;
  std::vector<std::string> expr(9);
  for(int i = 0; i < 9; i++) expr[i] = MathEvalOptions_String[i].def;
  
  PView *v1 = getView(iView, view);
  if(!v1) return view;
  PViewData *data1 = getPossiblyAdaptiveData(v1);

  if(data1->hasMultipleMeshes()){
    Msg::Error("MathEval plugin cannot be applied to multi-mesh views");
    return view;
  }

  PView *otherView = v1;
  if(iOtherView >= 0){
    otherView = getView(iOtherView, view);
    if(!otherView){
      Msg::Error("MathEval plugin could not find other view %i", iOtherView);
      return view;
    }
  }

  PViewData *otherData = getPossiblyAdaptiveData(otherView);
  if(otherData->hasMultipleMeshes()){
    Msg::Error("MathEval plugin cannot be applied to multi-mesh views");
    return view;
  }

  OctreePost *octree = 0;
  if((data1->getNumEntities() != otherData->getNumEntities()) ||
     (data1->getNumElements() != otherData->getNumElements())){
    Msg::Info("Other view based on different grid: interpolating...");
    octree = new OctreePost(otherView);
  }

  if(otherTimeStep < 0 && otherData->getNumTimeSteps() != data1->getNumTimeSteps()){
    Msg::Error("Number of time steps don't match: using step 0");
    otherTimeStep = 0;
  }
  else if(otherTimeStep > otherData->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
               otherTimeStep, otherView->getIndex());
    otherTimeStep = 0;
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
    { "x", "y", "z", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8",
      "w0", "w1", "w2", "w3", "w4", "w5", "w6", "w7", "w8", "w9" };
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

  int firstNonEmptyStep =  data1->getFirstNonEmptyTimeStep();
  int timeBeg = (timeStep < 0) ? firstNonEmptyStep : timeStep;
  int timeEnd = (timeStep < 0) ? -timeStep : timeStep + 1;
  for(int ent = 0; ent < data1->getNumEntities(timeBeg); ent++){
    for(int ele = 0; ele < data1->getNumElements(timeBeg, ent); ele++){
      if(data1->skipElement(timeBeg, ent, ele)) continue;
      int numNodes = data1->getNumNodes(timeBeg, ent, ele);
      int type = data1->getType(timeBeg, ent, ele);
      int numComp = data1->getNumComponents(timeBeg, ent, ele);
      int otherNumComp = (!otherData || octree) ? 9 :
        otherData->getNumComponents(timeBeg, ent, ele);
      std::vector<double> *out = data2->incrementList(numComp2, type);
      std::vector<double> w(std::max(9, otherNumComp), 0.);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        data1->getNode(timeBeg, ent, ele, nod, x[nod], y[nod], z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]); 
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]); 
      for(int step = timeBeg; step < timeEnd; step++){
	if(!data1->hasTimeStep(step)) continue;
        int step2 = (otherTimeStep < 0) ? step : otherTimeStep;
        for(int nod = 0; nod < numNodes; nod++){
          std::vector<double> v(std::max(9, numComp), 0.);
          for(int comp = 0; comp < numComp; comp++)
            data1->getValue(step, ent, ele, nod, comp, v[comp]);
          values[0] = x[nod]; values[1] = y[nod]; values[2] = z[nod];
          if(otherData){
            if(octree){
              if(!octree->searchScalar(x[nod], y[nod], z[nod], &w[0], step2))
                if(!octree->searchVector(x[nod], y[nod], z[nod], &w[0], step2))
                  octree->searchTensor(x[nod], y[nod], z[nod], &w[0], step2);
            }
            else
              for(int comp = 0; comp < otherNumComp; comp++)
                otherData->getValue(step2, ent, ele, nod, comp, w[comp]);
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
    for(int i = firstNonEmptyStep; i < data1->getNumTimeSteps(); i++) {
      if(!data1->hasTimeStep(i)) continue;
      data2->Time.push_back(data1->getTime(i));
    }
  }
  else
    data2->Time.push_back(data1->getTime(timeStep));
        
  data2->setName(data1->getName() + "_MathEval");
  data2->setFileName(data1->getName() + "_MathEval.pos");
  data2->finalize();

  return v2;
}
