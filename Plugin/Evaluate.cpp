// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "Evaluate.h"
#include "OctreePost.h"

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

PView *GMSH_EvaluatePlugin::execute(PView *v)
{
  int component = (int)EvaluateOptions_Number[0].def;
  int timeStep = (int)EvaluateOptions_Number[1].def;
  int externalView = (int)EvaluateOptions_Number[2].def;
  int externalTimeStep = (int)EvaluateOptions_Number[3].def;
  int iView = (int)EvaluateOptions_Number[4].def;
  const char *expr = EvaluateOptions_String[0].def.c_str();

  PView *v1 = getView(iView, v);
  if(!v1) return v;

  PViewData *data1 = v1->getData();

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

  PViewData *data2 = v2->getData();

  if(externalTimeStep < 0 && data2->getNumTimeSteps() != data1->getNumTimeSteps()){
    Msg::Error("Number of time steps don't match: using step 0");
    externalTimeStep = 0;
  }
  else if(externalTimeStep > data2->getNumTimeSteps() - 1){
    Msg::Error("Invalid time step (%d) in View[%d]: using step 0 instead",
               externalTimeStep, v2->getIndex());
    externalTimeStep = 0;
  }

  v1->setChanged(true);

  OctreePost *octree = 0;
  if((data1->getNumEntities() != data2->getNumEntities()) ||
     (data1->getNumElements() != data2->getNumElements())){
    Msg::Info("External view based on different grid: interpolating...");
    octree = new OctreePost(v2);
  }
  
#if defined(HAVE_MATH_EVAL)
  void *f = evaluator_create((char*)expr);
  if(!f){
    Msg::Error("Invalid expression '%s'", expr);
    return v;
  }

  for(int step = 0; step < data1->getNumTimeSteps(); step++){
    if(timeStep >= 0 && timeStep != step) continue;

    double time = data1->getTime(step);
    int step2 = (externalTimeStep < 0) ? step : externalTimeStep;

    // tag all the nodes with "0" (the default tag)
    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
	for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++)
	  data1->tagNode(step, ent, ele, nod, 0);
      }
    }

    for(int ent = 0; ent < data1->getNumEntities(step); ent++){
      for(int ele = 0; ele < data1->getNumElements(step, ent); ele++){
	if(data1->skipElement(step, ent, ele)) continue;
        for(int nod = 0; nod < data1->getNumNodes(step, ent, ele); nod++){
          double x, y, z;
          int tag = data1->getNode(step, ent, ele, nod, x, y, z);
          if(tag) continue; // node has already been modified

          double v[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
	  for(int comp = 0; comp < data1->getNumComponents(step, ent, ele); comp++)
	    data1->getValue(step, ent, ele, nod, comp, v[comp]);

          double w[9] = {0., 0., 0., 0., 0., 0., 0., 0., 0.};
          if(octree){
            if(!octree->searchScalar(x, y, z, w, step2))
              if(!octree->searchVector(x, y, z, w, step2))
                octree->searchTensor(x, y, z, w, step2);
          }
          else
            for(int comp = 0; comp < data2->getNumComponents(step2, ent, ele); comp++)
              data2->getValue(step2, ent, ele, nod, comp, w[comp]);
          
	  for(int comp = 0; comp < data1->getNumComponents(step, ent, ele); comp++){
            if(component >= 0 && component != comp) continue;
            char *names[] = 
              {"x", "y", "z", "Time", "TimeStep",
               "v", "v0", "v1", "v2", "v3", "v4", "v5", "v6", "v7", "v8",
               "w", "w0", "w1", "w2", "w3", "w4", "w5", "w6", "w7", "w8"};
            double values[] = 
              {x, y, z, time, step,
               v[comp], v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
               w[comp], w[0], w[1], w[2], w[3], w[4], w[5], w[6], w[7], w[8]};
            double res = evaluator_evaluate
              (f, sizeof(names)/sizeof(names[0]), names, values);
            data1->setValue(step, ent, ele, nod, comp, res);
            data1->tagNode(step, ent, ele, nod, 1);
          }
        }
      }
    }
  }
  evaluator_destroy(f);
#else
  Msg::Error("MathEval is not compiled in this version of Gmsh");
#endif

  if(octree) delete octree;

  data1->finalize();

  return v1;
}
