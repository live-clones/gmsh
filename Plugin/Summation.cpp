// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GmshDefines.h"
#include "Summation.h"
#include "OctreePost.h"
#include "GEntity.h"
#include <algorithm>

StringXNumber SummationOptions_Number[] = {
  {GMSH_FULLRC, "View 0", nullptr, -1.}, {GMSH_FULLRC, "View 1", nullptr, -1.},
  {GMSH_FULLRC, "View 2", nullptr, -1.}, {GMSH_FULLRC, "View 3", nullptr, -1.},
  {GMSH_FULLRC, "View 4", nullptr, -1.}, {GMSH_FULLRC, "View 5", nullptr, -1.},
  {GMSH_FULLRC, "View 6", nullptr, -1.}, {GMSH_FULLRC, "View 7", nullptr, -1.}};

StringXString SummationOptions_String[] = {
  {GMSH_FULLRC, "Resuling View Name", nullptr, "default"}};

extern "C" {
GMSH_Plugin *GMSH_RegisterSummationPlugin()
{
  return new GMSH_SummationPlugin();
}
}

std::string GMSH_SummationPlugin::getHelp() const
{
  return "Plugin(Summation) sums every time steps "
         "of 'Reference View' and (every) 'Other View X'"
         "and store the result in a new view.\n"
         "If 'View 0' < 0 then the current view is selected.\n"
         "If 'View 1...8' < 0 then this view is skipped.\n"
         "Views can have diffrent number of time steps\n"
         "Warning: the Plugin assume that every views share"
         "the same mesh and that meshes do not move between time steps!";
}

int GMSH_SummationPlugin::getNbOptions() const
{
  return sizeof(SummationOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_SummationPlugin::getOption(int iopt)
{
  return &SummationOptions_Number[iopt];
}

int GMSH_SummationPlugin::getNbOptionsStr() const
{
  return sizeof(SummationOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_SummationPlugin::getOptionStr(int iopt)
{
  return &SummationOptions_String[iopt];
}

PView *GMSH_SummationPlugin::execute(PView *view)
{
  int nviewmax = 8;
  std::vector<int> views_indices;
  std::vector<PView *> pviews;
  std::vector<PViewData *> pviewsdata;

  // Get view indices and PViews
  for(int i = 0; i < nviewmax; i++) {
    int iview = (int)SummationOptions_Number[i].def;
    if(i == 0 || iview > -1) {
      views_indices.push_back(iview);
      pviews.push_back(getView(iview, view));
      if(!pviews.back()) {
        Msg::Error("Summation plugin could not find view %i", iview);
        return view;
      }
      pviewsdata.push_back(getPossiblyAdaptiveData(pviews.back()));
      if(pviewsdata.back()->hasMultipleMeshes()) {
        Msg::Error("Summation plugin cannot be applied to multi-mesh views");
        return view;
      }
    }
  }
  // Number of view to sum
  int nviews = pviews.size();
  // Check if the views share the same mesh
  //(at least same number of elements and entities)
  // If a view has an empty timestep: skip it, no problem.
  for(int j = 1; j < nviews; j++) {
    if(pviewsdata[j]->getNumEntities() == 0 &&
       pviewsdata[j]->getNumElements() == 0)
      continue; // empty time step
    if((pviewsdata[0]->getNumEntities() != pviewsdata[j]->getNumEntities()) ||
       (pviewsdata[0]->getNumElements() != pviewsdata[j]->getNumElements())) {
      Msg::Error("Summation plugin: views based on different grid.");
    }
  }
  // get min/max indices of time steps
  int timeBeg = pviewsdata[0]->getFirstNonEmptyTimeStep();
  int timeEnd = pviewsdata[0]->getNumTimeSteps();
  int iref = 0; // reference view and time step to get mesh's info
  int stepref = timeBeg;
  for(int i = 1; i < nviews; i++) {
    if(timeBeg > pviewsdata[i]->getFirstNonEmptyTimeStep()) {
      timeBeg = pviewsdata[i]->getFirstNonEmptyTimeStep();
      iref = i;
      stepref = timeBeg;
    }
    timeEnd = std::max(timeEnd, pviewsdata[i]->getNumTimeSteps());
  }
  // Init result
  PView *v2 = new PView();
  PViewDataList *data2 = getDataList(v2);

  for(int ent = 0; ent < pviewsdata[iref]->getNumEntities(stepref); ent++) {
    for(int ele = 0; ele < pviewsdata[iref]->getNumElements(stepref, ent);
        ele++) {
      //      if(pviewsdata[0]->skipElement(timeBeg, ent, ele)) continue;
      int numNodes = pviewsdata[iref]->getNumNodes(stepref, ent, ele);
      int type = pviewsdata[iref]->getType(stepref, ent, ele);
      int numComp = pviewsdata[iref]->getNumComponents(stepref, ent, ele);
      int numComp2 = numComp;
      std::vector<double> *out = data2->incrementList(numComp2, type, numNodes);
      std::vector<double> v(std::max(9, numComp), 0.);
      std::vector<double> x(numNodes), y(numNodes), z(numNodes);
      for(int nod = 0; nod < numNodes; nod++)
        pviewsdata[iref]->getNode(stepref, ent, ele, nod, x[nod], y[nod],
                                  z[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(x[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(y[nod]);
      for(int nod = 0; nod < numNodes; nod++) out->push_back(z[nod]);
      for(int step = timeBeg; step < timeEnd; step++) {
        for(int nod = 0; nod < numNodes; nod++) {
          for(int comp = 0; comp < numComp; comp++) {
            v[comp] = 0;
            for(int iview = 0; iview < nviews; iview++) {
              if(!pviewsdata[iview]->hasTimeStep(step)) continue;
              double d;
              pviewsdata[iview]->getValue(step, ent, ele, nod, comp, d);
              v[comp] += d;
            }
          }
          for(int i = 0; i < numComp2; i++) out->push_back(v[i]);
        }
      }
    }
  }

  // Set time
  for(int step = timeBeg; step < timeEnd; step++) {
    int iview = 0;
    for(iview = 0; iview < nviews; iview++) {
      if(!pviewsdata[iview]->hasTimeStep(step)) continue;
      break;
    }
    data2->Time.push_back(pviewsdata[iview]->getTime(step));
  }

  std::string outputname = SummationOptions_String[0].def;
  if(outputname == "default")
    outputname = pviewsdata[0]->getName() + "_Summation";

  data2->setName(outputname);
  data2->setFileName(outputname + "_Summation.pos");
  data2->finalize();

  return v2;
}
